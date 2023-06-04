#include "Application.h"

#include "Downloader.h"
#include "GitHubRepo.h"
#include "Version.h"
#include "MainWindow.h"

#include "Widgets/Dialogs/CreateThemeDialog.h"
#include "Widgets/Dialogs/ColorDialog.h"
#include "Widgets/Dialogs/GradientDialog.h"
#include "Widgets/Dialogs/ThemeCompatibilityCautionDialog.h"
#include "Widgets/Dialogs/UpdateDialog.h"
#include "Widgets/Widgets/Menus/ThemeEditor/WidgetEditor.h"

#include <QDirIterator>
#include <QFontDatabase>
#include <QGradientStops>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QProcess>

using Layers::Application;
using Layers::ColorDialog;
using Layers::CreateThemeDialog;
using Layers::WidgetEditor;
using Layers::GradientDialog;
using Layers::Theme;
using Layers::Themeable;
using Layers::ThemeCompatibilityCautionDialog;
using Layers::MainWindow;

Application::Application(
	int& argc, char** argv,
	const QString& name,
	const QUuid& uuid,
	QFile* icon_file,
	Version* version,
	GitHubRepo* github_repo) :
	m_name{ name },
	m_uuid{ uuid },
	m_icon_file{ icon_file },
	m_version{ version },
	m_github_repo{ github_repo },
	m_settings{ QSettings(name, name) },
	m_downloader{ new Downloader(this) },
	QApplication(argc, argv)
{
	Q_INIT_RESOURCE(image_sequences);
	Q_INIT_RESOURCE(roboto_font);
	Q_INIT_RESOURCE(images);
	Q_INIT_RESOURCE(theme_light);
	Q_INIT_RESOURCE(theme_dark);

	qRegisterMetaType<QGradientStops>("QGradientStops");

	setAttribute(Qt::AA_EnableHighDpiScaling);
	setEffectEnabled(Qt::UI_AnimateCombo, false);
	set_name("App");

	QStringList name_parts = m_name.split(' ', Qt::SkipEmptyParts);
	for (int i = 0; i < name_parts.size(); i++)
		name_parts[i].replace(0, 1, name_parts[i][0].toLower());

	m_name_underscored = name_parts.join("_");

	init_directories();
	init_fonts();
	init_themes();
	init_latest_version_tag();

	m_create_theme_dialog = new CreateThemeDialog;

	m_color_dialog = new ColorDialog;

	m_gradient_dialog = new GradientDialog;

	m_theme_compatibility_caution_dialog =
		new ThemeCompatibilityCautionDialog;

	m_update_dialog = new UpdateDialog("", "");

	add_child_themeable_pointer(*m_create_theme_dialog);
	add_child_themeable_pointer(*m_color_dialog);
	add_child_themeable_pointer(*m_gradient_dialog);
	add_child_themeable_pointer(*m_theme_compatibility_caution_dialog);
	add_child_themeable_pointer(*m_update_dialog);
}

Application::~Application()
{
	if (m_github_repo)
		delete m_github_repo;

	if (m_latest_version)
		delete m_latest_version;

	if (m_version)
		delete m_version;

	for (Theme* theme : m_themes)
		delete theme;

	m_themes.clear();

	delete m_create_theme_dialog;
	delete m_color_dialog;
	delete m_gradient_dialog;
	delete m_theme_compatibility_caution_dialog;
	delete m_update_dialog;
}

QString Application::app_identifier()
{
	return m_name_underscored + "_" + m_uuid.toString(QUuid::WithoutBraces);
}

void Application::add_child_themeable_pointer(Themeable& themeable)
{
	m_child_themeables.append(&themeable);
}

void Application::apply_theme(Theme& theme)
{
	if (m_active_theme != &theme)
	{
		if (m_active_theme)
			m_active_theme->clear();

		m_active_theme = &theme;

		if (!m_active_theme->has_app_implementation())
		{
			// Iterate backwards through the lineage to determine last CAT.
			for (int i = m_active_theme->lineage().size() - 1; i >= 0; i--)
			{
				QString theme_id = m_active_theme->lineage()[i];

				QString theme_name = (theme_id.contains("_")) ?
					theme_id.left(theme_id.lastIndexOf("_")) : theme_id;

				if (Theme* theme = layersApp->theme(theme_name))
					if (theme->has_app_implementation())
					{
						QString app_file_name =
							layersApp->app_identifier() + ".json";

						QFile last_CAT_app_file(
							theme->dir().filePath(app_file_name));
						
						if (last_CAT_app_file.exists())
							last_CAT_app_file.copy(
								m_active_theme->dir().filePath(app_file_name)
							);
					}
			}
		}

		m_active_theme->load();

		for (Themeable* themeable : m_child_themeables)
			themeable->apply_theme(theme);

		m_settings.setValue("themes/active_theme", theme.id());

		emit active_theme_changed();
	}
}

QList<Themeable*> Application::child_themeables(Qt::FindChildOptions options)
{
	return m_child_themeables;
}

CreateThemeDialog* Application::create_theme_dialog() const
{
	return m_create_theme_dialog;
}

ColorDialog* Application::color_dialog() const
{
	return m_color_dialog;
}

Theme* Application::active_theme() const
{
	return m_active_theme;
}

GradientDialog* Application::gradient_dialog() const
{
	return m_gradient_dialog;
}

QFile* Application::icon_file()
{
	return m_icon_file;
}

QMap<QString, Theme*>& Application::themes()
{
	return m_themes;
}

bool Application::update_available()
{
	if (m_latest_version && m_version)
		return *m_latest_version != m_version->to_string();
	else
		return false;
}

bool Application::update_on_request()
{
	UpdateDialog* update_dialog = new UpdateDialog(m_version->to_string(), *m_latest_version);

	if (m_active_theme)
		update_dialog->apply_theme(*m_active_theme);

	update_dialog->show();

	if (update_dialog->exec())
	{
		QUrl repo_releases_json_download_url(m_github_api_repos_url_base + "/" + m_github_repo->to_string() + "/releases");

		QNetworkReply* repo_releases_json_download = m_downloader->download(repo_releases_json_download_url);

		QEventLoop loop;
		connect(repo_releases_json_download, &QNetworkReply::finished, &loop, &QEventLoop::quit);
		loop.exec();

		if (repo_releases_json_download->error() == QNetworkReply::NoError)
		{
			QJsonArray repo_releases_json_array = QJsonDocument::fromJson(repo_releases_json_download->readAll()).array();

			QJsonArray release_assets_array = repo_releases_json_array.first().toObject()["assets"].toArray();

			for (QJsonValueRef release_asset : release_assets_array)
			{
				QString release_asset_name = release_asset.toObject()["name"].toString();

				if (release_asset_name.endsWith(".exe") || release_asset_name.endsWith(".msi"))
				{
					QDir temp_dir = local_app_data_path() + "Temp\\";

					QUrl latest_version_download_url = QUrl(release_asset.toObject()["browser_download_url"].toString());

					if (!QFile::exists(latest_version_download_url.fileName()))
					{
						QNetworkReply* update_download = m_downloader->download(latest_version_download_url, temp_dir);

						QEventLoop loop;
						connect(update_download, SIGNAL(finished()), &loop, SLOT(quit()));
						loop.exec();
					}

					QStringList args = { "/SILENT" };

					QProcess update_process;
					update_process.startDetached(temp_dir.filePath(latest_version_download_url.fileName()), args);

					return true;
				}
			}
		}
	}

	return false;
}

void Application::rename_theme(const QString& theme_id, const QString& new_name)
{
	if (m_themes.contains(theme_id))
	{
		Theme* theme = m_themes[theme_id];

		QDir old_theme_dir = theme->dir();

		old_theme_dir.rename(
			old_theme_dir.absoluteFilePath("."),
			latest_T_version_path() + new_name + theme->uuid()->toString(QUuid::WithoutBraces) + "\\");

		theme->set_name(new_name);

		//old_theme_dir.removeRecursively();

		//m_themes.insert(new_name, m_themes.take(old_name));

		//m_themes[new_name]->set_name(new_name);

		//apply_theme(*m_themes[new_name]);
		//save_theme(*m_themes[new_name]);
	}
}

QString Application::name()
{
	return m_name;
}

void Application::reapply_theme()
{
	for (Themeable* themeable : m_child_themeables)
		themeable->apply_theme(*m_active_theme);
}

void Application::save_theme(Theme& theme)
{
	QDir theme_dir = latest_T_version_path() + theme.id() + "\\";

	if (!theme_dir.exists())
		theme_dir.mkdir(".");

	QFile theme_layers_file(theme_dir.absoluteFilePath("layers.json"));

	if (!theme_layers_file.open(QIODevice::WriteOnly))
	{
		qDebug() << "Could not write theme layers file";
		return;
	}

	theme_layers_file.write(theme.to_json_document(ThemeDataType::Layers).toJson());
	theme_layers_file.close();

	QFile app_theme_file(theme_dir.absoluteFilePath(app_identifier() + ".json"));

	if (!app_theme_file.open(QIODevice::WriteOnly))
	{
		qDebug() << "Could not create theme app-implementation file";
		return;
	}

	app_theme_file.write(theme.to_json_document(ThemeDataType::Application).toJson());
	app_theme_file.close();
}

QSettings& Application::settings()
{
	return m_settings;
}

Theme* Application::theme(const QString& theme_id)
{
	if (m_themes.contains(theme_id))
		return m_themes[theme_id];

	return nullptr;
}

ThemeCompatibilityCautionDialog* Application::theme_compatibility_caution_dialog() const
{
	return m_theme_compatibility_caution_dialog;
}

void Application::init_directories()
{
	QDir app_dir = app_path(m_name);
	QDir layers_dir = layers_path();
	QDir themes_dir = themes_path();
	QDir latest_T_version_dir = latest_T_version_path();

	if (!app_dir.exists())
		app_dir.mkdir(".");

	if (!layers_dir.exists())
		layers_dir.mkdir(".");

	if (!themes_dir.exists())
		themes_dir.mkdir(".");

	if (!latest_T_version_dir.exists())
		latest_T_version_dir.mkdir(".");
}

void Application::init_fonts()
{
	QDirIterator fonts_iterator(
		":/fonts",
		{ "*.ttf", "*.otf" },
		QDir::Files, QDirIterator::Subdirectories);

	while (fonts_iterator.hasNext())
		QFontDatabase::addApplicationFont(fonts_iterator.next());

	QFont font("Roboto", 12, QFont::Normal);
	font.setStyleStrategy(QFont::PreferAntialias);
	setFont(font);
}

void Application::init_themes()
{
	/* TODO: Might need to handle case where theme files labeled "dark" or "light"
	   appear in the custom themes directory. */

	// Load prebuilt theme files
	m_themes["Dark"] = new Theme(QDir(":/themes/Dark"));
	m_themes["Light"] = new Theme(QDir(":/themes/Light"));

	QDir latest_T_version_dir = latest_T_version_path();

	for (const QString& dir_name : latest_T_version_dir.entryList(QDir::NoDotAndDotDot|QDir::Dirs))
	{
		Theme* loaded_theme = new Theme(QDir(latest_T_version_dir.absoluteFilePath(dir_name)));

		m_themes[loaded_theme->id()] = loaded_theme;
	}

	QString active_theme_id =
		m_settings.value("themes/active_theme").value<QString>();

	if (m_themes.contains(active_theme_id))
		apply_theme(*m_themes[active_theme_id]);
	else
		apply_theme(*m_themes["Light"]);
}

void Application::init_latest_version_tag()
{
	if (m_github_repo)
	{
		QUrl repo_tags_json_download_url(m_github_api_repos_url_base + "/" + m_github_repo->to_string() + "/tags");

		QNetworkReply* repo_tags_json_download = m_downloader->download(repo_tags_json_download_url);

		QEventLoop loop;
		connect(repo_tags_json_download, &QNetworkReply::finished, &loop, &QEventLoop::quit);
		loop.exec();

		if (repo_tags_json_download->error() == QNetworkReply::NoError)
		{
			QJsonDocument json_doc = QJsonDocument::fromJson(repo_tags_json_download->readAll());

			if (!json_doc.array().isEmpty())
				m_latest_version = new QString(json_doc.array().first().toObject()["name"].toString());
		}
	}
}
