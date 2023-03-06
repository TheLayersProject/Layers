#include "../../include/Application.h"
#include "../../include/build_themes.h"
#include "../../include/CustomizePanel.h"
#include "../../include/Downloader.h"
#include "../../include/GitHubRepo.h"
#include "../../include/theme_loading.h"
#include "../../include/Themeable.h"
#include "../../include/UpdateDialog.h"
#include "../../include/Version.h"
#include "../../include/WidgetButtonGroup.h"
#include "../../include/Window.h"

#include <QFontDatabase>
#include <QGradientStops>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QProcess>

using Layers::Application;
using Layers::ColorDialog;
using Layers::CreateNewThemeDialog;
using Layers::CustomizePanel;
using Layers::GradientDialog;
using Layers::Theme;
using Layers::Themeable;
using Layers::ThemeCompatibilityCautionDialog;
using Layers::Window;

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
	m_app_dir{ QDir(app_path(name)) },
	m_app_themes_dir{ QDir(app_themes_path(name)) },
	m_settings{ QSettings(name, name) },
	m_downloader{ new Downloader(this) },
	QApplication(argc, argv)
{
	Q_INIT_RESOURCE(image_sequences);
	Q_INIT_RESOURCE(roboto_font);
	Q_INIT_RESOURCE(svgs);
	Q_INIT_RESOURCE(theme_light);
	Q_INIT_RESOURCE(theme_dark);

	qRegisterMetaType<QGradientStops>("QGradientStops");

	setAttribute(Qt::AA_EnableHighDpiScaling);
	set_proper_name("App");

	if (m_version)
	{
		QFile setup_file(m_app_dir.filePath(m_name + "-" + m_version->toString() + "-setup.exe"));

		if (setup_file.exists()) setup_file.remove();
	}

	QStringList name_parts = m_name.split(' ', Qt::SkipEmptyParts);
	for (int i = 0; i < name_parts.size(); i++)
		name_parts[i].replace(0, 1, name_parts[i][0].toLower());

	m_name_underscored = name_parts.join("_");

	init_directories();
	init_fonts();
	init_themes();
	init_latest_version_tag();

	m_create_new_theme_dialog = new CreateNewThemeDialog;

	m_color_dialog = new ColorDialog;

	m_gradient_dialog = new GradientDialog;

	m_theme_compatibility_caution_dialog =
		new ThemeCompatibilityCautionDialog;

	m_update_dialog = new UpdateDialog("", "");

	add_child_themeable_pointer(*m_create_new_theme_dialog);
	add_child_themeable_pointer(*m_color_dialog);
	add_child_themeable_pointer(*m_gradient_dialog);
	add_child_themeable_pointer(*m_theme_compatibility_caution_dialog);
	add_child_themeable_pointer(*m_update_dialog);
}

Application::~Application()
{
	if (m_github_repo)
	{
		delete m_github_repo;
		m_github_repo = nullptr;
	}

	if (m_latest_version)
	{
		delete m_latest_version;
		m_latest_version = nullptr;
	}

	if (m_version)
	{
		delete m_version;
		m_version = nullptr;
	}

	for (Theme* theme : m_themes)
	{
		delete theme;
		theme = nullptr;
	}
	m_themes.clear();

	delete m_create_new_theme_dialog;
	delete m_color_dialog;
	delete m_gradient_dialog;
	delete m_theme_compatibility_caution_dialog;
	delete m_update_dialog;

	m_create_new_theme_dialog = nullptr;
	m_color_dialog = nullptr;
	m_gradient_dialog = nullptr;
	m_theme_compatibility_caution_dialog = nullptr;
	m_update_dialog = nullptr;
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
	if (m_current_theme != &theme)
	{
		m_current_theme = &theme;

		for (Themeable* themeable : m_child_themeables)
			themeable->apply_theme(theme);

		m_settings.setValue("themes/active_theme", theme.name());

		emit current_theme_changed();
	}
}

QList<Themeable*> Application::child_themeables(Qt::FindChildOptions options)
{
	return m_child_themeables;
}

void Application::create_theme(const QString& new_theme_name, const QString& copy_theme_name)
{
	m_themes[new_theme_name] = new Theme(new_theme_name);

	Theme* new_theme = m_themes[new_theme_name];

	new_theme->copy(*m_themes[copy_theme_name]);

	save_theme(*m_themes[new_theme_name]);
}

CreateNewThemeDialog* Application::create_new_theme_dialog() const
{
	return m_create_new_theme_dialog;
}

ColorDialog* Application::color_dialog() const
{
	return m_color_dialog;
}

Theme* Application::current_theme() const
{
	return m_current_theme;
}

CustomizePanel* Application::customize_panel()
{
	CustomizePanel* customize_panel = new CustomizePanel(this, false);

	QList<WidgetButton*> dialog_widget_buttons = QList<WidgetButton*>();
	QList<WidgetButton*> window_widget_buttons = QList<WidgetButton*>();

	for (Themeable* child_themeable : child_themeables())
	{
		// Check if themeable has a proper name to determine that it is customizable
		if (child_themeable->proper_name()) // TODO: Consider a Themeable::is_customizable() function so this is clearer
		{
			WidgetButton* widget_button;

			if (child_themeable->icon())
				widget_button = new WidgetButton(new Graphic(*child_themeable->icon()), *child_themeable->proper_name());
			else
				widget_button = new WidgetButton(*child_themeable->proper_name());

			QObject::connect(widget_button, &WidgetButton::clicked, [child_themeable] {
				Themeable* cloned_themeable = child_themeable->clone();

				if (QWidget* cloned_widget = dynamic_cast<QWidget*>(cloned_themeable))
				{
					static_cast<Window*>(QApplication::activeWindow()
						)->customize_menu()->set_preview_widget(cloned_widget);

					static_cast<Window*>(QApplication::activeWindow()
						)->customize_menu()->open_customize_panel(
							new CustomizePanel(cloned_themeable));
				}
			});

			if (dynamic_cast<Dialog*>(child_themeable))
				dialog_widget_buttons.append(widget_button);

			else if (dynamic_cast<Window*>(child_themeable))
				window_widget_buttons.append(widget_button);
		}
	}

	customize_panel->add_widget_button_group(new WidgetButtonGroup("Dialogs", dialog_widget_buttons));

	if (window_widget_buttons.size() == 1)
		customize_panel->add_widget_button(window_widget_buttons.first());

	return customize_panel;
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
		return *m_latest_version != m_version->toString();
	else
		return false;
}

bool Application::update_on_request()
{
	UpdateDialog* update_dialog = new UpdateDialog(m_version->toString(), *m_latest_version);

	update_dialog->assign_tag_prefixes();
	if (m_current_theme) update_dialog->apply_theme(*m_current_theme);
	update_dialog->show();

	if (update_dialog->exec())
	{
		QUrl repo_releases_json_download_url(m_github_api_repos_url_base + "/" + m_github_repo->toString() + "/releases");

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
					QUrl latest_version_download_url = QUrl(release_asset.toObject()["browser_download_url"].toString());

					if (!QFile::exists(latest_version_download_url.fileName()))
					{
						QNetworkReply* update_download = m_downloader->download(latest_version_download_url, m_app_dir);

						QEventLoop loop;
						connect(update_download, SIGNAL(finished()), &loop, SLOT(quit()));
						loop.exec();
					}

					QStringList args = { "/SILENT" };

					QProcess update_process;
					update_process.startDetached(m_app_dir.filePath(latest_version_download_url.fileName()), args);

					return true;
				}
			}
		}
	}

	return false;
}

void Application::rename_theme(const QString& old_name, const QString& new_name)
{
	if (m_themes.contains(old_name))
	{
		QDir T1_themes_dir(m_layers_themes_dir.filePath("T1\\"));

		QDir old_theme_dir(T1_themes_dir.absoluteFilePath(m_themes[old_name]->identifier() + "\\"));

		old_theme_dir.removeRecursively();

		m_themes.insert(new_name, m_themes.take(old_name));

		m_themes[new_name]->set_name(new_name);

		apply_theme(*m_themes[new_name]);
		save_theme(*m_themes[new_name]);
	}
}

Theme* Application::load_theme(const QString& file_name)
{
	qDebug() << "Loading" << file_name;

	return load_theme_1(file_name, app_identifier());
}

Window* Application::main_window() const
{
	// TODO: Below is temporary and will not work right if the application supports multiple windows.
	for (Themeable* themeable : m_child_themeables)
		if (themeable->name() && *themeable->name() == "window")
			return static_cast<Window*>(themeable);

	return nullptr;
}

QString& Application::name()
{
	return m_name;
}

void Application::reapply_theme()
{
	for (Themeable* themeable : m_child_themeables)
		themeable->apply_theme(*m_current_theme);
}

void Application::save_theme(Theme& theme)
{
	QDir T1_themes_dir(m_layers_themes_dir.filePath("T1\\"));

	QDir theme_dir(T1_themes_dir.absoluteFilePath(theme.identifier() + "\\"));

	if (!theme_dir.exists())
		theme_dir.mkdir(theme_dir.absolutePath());

	QFile layers_theme_file(theme_dir.absoluteFilePath("layers.json"));

	if (!layers_theme_file.open(QIODevice::WriteOnly))
	{
		qDebug() << "Could not create theme file";
		return;
	}

	layers_theme_file.write(theme.to_json_document(ThemeDataType::Layers).toJson());
	layers_theme_file.close();

	//if (app_identifier() != "layers_demo_f97aae7f-2076-4918-93ce-19321584f675")
	//{
	QFile app_theme_file(theme_dir.absoluteFilePath(app_identifier() + ".json"));

	if (!app_theme_file.open(QIODevice::WriteOnly))
	{
		qDebug() << "Could not create theme file";
		return;
	}

	app_theme_file.write(theme.to_json_document(ThemeDataType::Application).toJson());
	app_theme_file.close();
	//}
}

QSettings& Application::settings()
{
	return m_settings;
}

Theme* Application::theme(const QString& theme_name)
{
	if (m_themes.contains(theme_name))
		return m_themes[theme_name];

	return nullptr;
}

ThemeCompatibilityCautionDialog* Application::theme_compatibility_caution_dialog() const
{
	return m_theme_compatibility_caution_dialog;
}

void Application::init_directories()
{
	if (!m_layers_dir.exists())
	{
		m_layers_dir.mkdir(m_layers_dir.absolutePath());
		m_layers_themes_dir.mkdir(m_layers_themes_dir.absolutePath());
	}

	if (!m_app_dir.exists())
	{
		m_app_dir.mkdir(m_app_dir.absolutePath());
		m_app_themes_dir.mkdir(m_app_themes_dir.absolutePath());

		//m_layers_dir(deprecated_layers_path());

		// If the deprecated Layers path exists, move the theme files into the new themes directory and delete the deprecated directory
		//if (deprecated_layers_dir.exists())
		//{
		//	QDir deprecated_themes_dir(deprecated_layers_themes_path());

		//	for (const QString& file_name : deprecated_themes_dir.entryList(QDir::Files))
		//		QDir().rename(deprecated_themes_dir.absoluteFilePath(file_name), m_app_themes_dir.absoluteFilePath(file_name));

		//	deprecated_layers_dir.removeRecursively();
		//}
	}
}

void Application::init_fonts()
{
	QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Black.ttf");
	QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-BlackItalic.ttf");
	QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Bold.ttf");
	QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-BoldItalic.ttf");
	QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Italic.ttf");
	QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Light.ttf");
	QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-LightItalic.ttf");
	QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Medium.ttf");
	QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-MediumItalic.ttf");
	QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Regular.ttf");
	QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-Thin.ttf");
	QFontDatabase::addApplicationFont(":/fonts/Roboto/Roboto-ThinItalic.ttf");

	QFont font("Roboto", 12, QFont::Normal);

	font.setStyleStrategy(QFont::PreferAntialias);

	setFont(font);
}

void Application::init_themes()
{
	/* TODO: Might need to handle case where theme files labeled "dark" or "light"
	   appear in the custom themes directory. */

	// Load prebuilt theme files
	m_themes.insert("Dark", load_theme(":/themes/Dark"));
	m_themes.insert("Light", load_theme(":/themes/Light"));

	QDir T1_themes_dir(m_layers_themes_dir.filePath("T1\\"));

	for (const QString& file_name : T1_themes_dir.entryList(QDir::NoDotAndDotDot|QDir::AllEntries))
	{
		QString theme_dir_path = T1_themes_dir.absoluteFilePath(file_name);

		//if (QFile(
		//		QDir(theme_dir_path).filePath(app_identifier() + ".json")
		//	).exists())
		//{
		Theme* loaded_theme = load_theme(theme_dir_path);

		m_themes.insert(loaded_theme->name(), loaded_theme);
		//}
	}

	QString active_theme_name =
		m_settings.value("themes/active_theme").value<QString>();

	if (m_themes.contains(active_theme_name))
		apply_theme(*m_themes[active_theme_name]);
	else
		apply_theme(*m_themes["Light"]);
}

void Application::init_latest_version_tag()
{
	if (m_github_repo)
	{
		QUrl repo_tags_json_download_url(m_github_api_repos_url_base + "/" + m_github_repo->toString() + "/tags");

		QNetworkReply* repo_tags_json_download = m_downloader->download(repo_tags_json_download_url);

		QEventLoop loop;
		connect(repo_tags_json_download, &QNetworkReply::finished, &loop, &QEventLoop::quit);
		loop.exec();

		if (repo_tags_json_download->error() == QNetworkReply::NoError)
		{
			QJsonDocument json_doc = QJsonDocument::fromJson(repo_tags_json_download->readAll());

			m_latest_version = new QString(json_doc.array().first().toObject()["name"].toString());
		}
	}
}
