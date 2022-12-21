#include "../../include/Application.h"
#include "../../include/build_themes.h"
#include "../../include/Downloader.h"
#include "../../include/GitHubRepo.h"
#include "../../include/theme_loading.h"
#include "../../include/Themeable.h"
#include "../../include/UpdateDialog.h"
#include "../../include/Version.h"

#include <QFontDatabase>
#include <QGradientStops>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QProcess>

using Layers::Application;
using Layers::Theme;
using Layers::Themeable;
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
	Q_INIT_RESOURCE(prebuilt_themes);
	Q_INIT_RESOURCE(roboto_font);
	Q_INIT_RESOURCE(svgs);

	qRegisterMetaType<QGradientStops>("QGradientStops");

	setAttribute(Qt::AA_EnableHighDpiScaling);

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
}

QString Application::app_identifier()
{
	return m_name_underscored + "_" + m_uuid.toString(QUuid::WithoutBraces);
}

void Application::store_child_themeable_pointer(Themeable& themeable)
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
	}
}

void Application::create_theme(const QString& new_theme_name, const QString& copy_theme_name)
{
	m_themes[new_theme_name] = Theme(new_theme_name);

	Theme& new_theme = m_themes[new_theme_name];

	new_theme.copy_from(m_themes[copy_theme_name]);

	save_theme(m_themes[new_theme_name]);
}

Theme* Layers::Application::current_theme() const
{
	return m_current_theme;
}

QFile* Application::icon_file()
{
	return m_icon_file;
}

QMap<QString, Theme>& Application::themes()
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
		m_themes.insert(new_name, m_themes.take(old_name));

		m_themes[new_name].set_name(new_name);

		apply_theme(m_themes[new_name]);

		QFile old_theme_file(m_app_themes_dir.absoluteFilePath(old_name.toLower()));

		old_theme_file.remove();

		save_theme(m_themes[new_name]);
	}
}

Theme Application::load_theme(const QString& file_name)
{
	qDebug() << "Loading" << file_name;

	Theme theme = load_theme_1(file_name, app_identifier());

	return theme;
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

	if (app_identifier() != "layers_demo_f97aae7f-2076-4918-93ce-19321584f675")
	{
		QFile app_theme_file(theme_dir.absoluteFilePath(app_identifier() + ".json"));

		if (!app_theme_file.open(QIODevice::WriteOnly))
		{
			qDebug() << "Could not create theme file";
			return;
		}

		app_theme_file.write(theme.to_json_document(ThemeDataType::Application).toJson());
		app_theme_file.close();
	}
}

QSettings& Application::settings()
{
	return m_settings;
}

Theme* Application::theme(const QString& theme_name)
{
	if (m_themes.contains(theme_name))
		return &m_themes[theme_name];

	return nullptr;
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
	QFontDatabase::addApplicationFont(":/roboto_font/Roboto/Roboto-Black.ttf");
	QFontDatabase::addApplicationFont(":/roboto_font/Roboto/Roboto-BlackItalic.ttf");
	QFontDatabase::addApplicationFont(":/roboto_font/Roboto/Roboto-Bold.ttf");
	QFontDatabase::addApplicationFont(":/roboto_font/Roboto/Roboto-BoldItalic.ttf");
	QFontDatabase::addApplicationFont(":/roboto_font/Roboto/Roboto-Italic.ttf");
	QFontDatabase::addApplicationFont(":/roboto_font/Roboto/Roboto-Light.ttf");
	QFontDatabase::addApplicationFont(":/roboto_font/Roboto/Roboto-LightItalic.ttf");
	QFontDatabase::addApplicationFont(":/roboto_font/Roboto/Roboto-Medium.ttf");
	QFontDatabase::addApplicationFont(":/roboto_font/Roboto/Roboto-MediumItalic.ttf");
	QFontDatabase::addApplicationFont(":/roboto_font/Roboto/Roboto-Regular.ttf");
	QFontDatabase::addApplicationFont(":/roboto_font/Roboto/Roboto-Thin.ttf");
	QFontDatabase::addApplicationFont(":/roboto_font/Roboto/Roboto-ThinItalic.ttf");

	QFont font("Roboto", 12, QFont::Normal);

	font.setStyleStrategy(QFont::PreferAntialias);

	setFont(font);
}

void Application::init_themes()
{
	/* TODO: Might need to handle case where theme files labeled "dark" or "light"
	   appear in the custom themes directory. */

	// Load prebuilt theme files
	//m_themes.insert("Blue", load_theme(":/themes/blue.json"));
	m_themes.insert("Dark", load_theme(":/themes/dark.json"));
	m_themes.insert("Light", load_theme(":/themes/light.json"));

	QDir T1_themes_dir(m_layers_themes_dir.filePath("T1\\"));

	for (const QString& file_name : T1_themes_dir.entryList(QDir::NoDotAndDotDot|QDir::AllEntries))
	{
		QString theme_dir_path = T1_themes_dir.absoluteFilePath(file_name);

		if (app_identifier() == "layers_demo_f97aae7f-2076-4918-93ce-19321584f675" ||
			QFile(
				QDir(theme_dir_path).filePath(app_identifier() + ".json")
			).exists())
		{
			Theme loaded_theme = load_theme(theme_dir_path);

			m_themes.insert(loaded_theme.name(), loaded_theme);
		}
	}

	if (m_themes.contains(m_settings.value("themes/active_theme").value<QString>()))
		apply_theme(m_themes[m_settings.value("themes/active_theme").value<QString>()]);
	else
		apply_theme(m_themes["Light"]);
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
