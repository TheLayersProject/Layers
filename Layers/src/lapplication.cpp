/*
 * Copyright (C) 2023 The Layers Project
 *
 * This file is part of Layers.
 *
 * Layers is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Layers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Layers. If not, see <https://www.gnu.org/licenses/>.
 */

#include <Layers/lapplication.h>

#include <QDirIterator>
#include <QFontDatabase>
#include <QGradientStops>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QProcess>
#include <QWidget>

#include <Layers/ldownloader.h>
#include <Layers/lgithubrepo.h>

using Layers::LApplication;
using Layers::LAttribute;
using Layers::LTheme;
using Layers::LThemeable;
using Layers::LMainWindow;

LTheme* Layers::activeTheme()
{
	if (layersApp)
		return layersApp->active_theme();
	else
		return nullptr;
}

LApplication::LApplication(
	int& argc, char** argv,
	const QString& name,
	const QUuid& uuid,
	LGitHubRepo* github_repo) :
	m_name{ name },
	m_uuid{ uuid },
	m_github_repo{ github_repo },
	m_settings{ QSettings(name, name) },
	m_downloader{ new LDownloader(this) },
	QApplication(argc, argv)
{
	Q_INIT_RESOURCE(roboto_font);
	Q_INIT_RESOURCE(images);
	Q_INIT_RESOURCE(theme_light);
	Q_INIT_RESOURCE(theme_dark);

	qRegisterMetaType<QGradientStops>("QGradientStops");

	init_directories();
	init_fonts();
	init_latest_version();
	setAttribute(Qt::AA_EnableHighDpiScaling);
	setEffectEnabled(Qt::UI_AnimateCombo, false);
	setObjectName("App");

	QStringList name_parts = m_name.split(' ', Qt::SkipEmptyParts);
	for (int i = 0; i < name_parts.size(); i++)
		name_parts[i].replace(0, 1, name_parts[i][0].toLower());
	m_name_underscored = name_parts.join("_");

	init_themes();
}

LApplication::~LApplication()
{
	if (m_github_repo)
		delete m_github_repo;

	for (LTheme* theme : m_themes)
		delete theme;

	m_themes.clear();
}

QString LApplication::app_identifier()
{
	return m_name_underscored + "_" + m_uuid.toString(QUuid::WithoutBraces);
}

void LApplication::apply_theme(LTheme* theme)
{
	if (m_active_theme != theme)
	{
		LTheme* previous_active_theme = m_active_theme;

		m_active_theme = theme;

		if (!m_active_theme->has_implementation(app_identifier()))
		{
			// Iterate backwards through the lineage to determine last CAT.
			for (int i = m_active_theme->lineage().size() - 1; i >= 0; i--)
			{
				QString theme_id = m_active_theme->lineage()[i];

				QString theme_name = (theme_id.contains("_")) ?
					theme_id.left(theme_id.lastIndexOf("_")) : theme_id;

				if (LTheme* theme = layersApp->theme(theme_id))
					if (theme->has_implementation(app_identifier()))
					{
						QString app_file_name =
							layersApp->app_identifier() + ".json";

						QFile last_CAT_app_file(
							theme->dir().filePath(app_file_name));
						
						if (last_CAT_app_file.exists())
						{
							last_CAT_app_file.copy(
								m_active_theme->dir().filePath(app_file_name)
							);

							QFile::setPermissions(
								m_active_theme->dir().filePath(app_file_name),
								QFileDevice::WriteUser);

							break;
						}
					}
			}
		}

		m_active_theme->load(app_identifier());

		_clear_theme();

		apply_theme_item(theme->find_item(path()));

		m_settings.setValue("themes/active_theme", theme->id());

		emit active_theme_changed();

		if (previous_active_theme)
			previous_active_theme->clear();
	}
}

QList<LThemeable*> LApplication::child_themeables(Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables;

	for (QWidget* tl_widget : topLevelWidgets())
		if (LThemeable* tl_themeable = dynamic_cast<LThemeable*>(tl_widget))
			child_themeables.append(tl_themeable);

	return child_themeables;
}

LTheme* LApplication::active_theme()
{
	return m_active_theme;
}

void LApplication::add_theme(LTheme* theme)
{
	m_themes[theme->id()] = theme;

	emit theme_added(theme);
}

QFile* LApplication::icon_file()
{
	return m_icon_file;
}

QString LApplication::latest_version()
{
	return m_latest_version;
}

QMap<QString, LTheme*> LApplication::themes()
{
	return m_themes;
}

bool LApplication::update_available()
{
	if (!m_latest_version.isEmpty() && !version().isEmpty())
		return m_latest_version != version();
	else
		return false;
}

QString LApplication::version()
{
	return applicationVersion();
}

void LApplication::download_and_install_update()
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
			}
		}
	}
}

void LApplication::rename_theme(const QString& theme_id, const QString& new_name)
{
	if (m_themes.contains(theme_id))
	{
		LTheme* theme = m_themes[theme_id];
		QDir old_theme_dir = theme->dir();

		theme->set_name(new_name);

		old_theme_dir.rename(
			old_theme_dir.absoluteFilePath("."),
			latest_T_version_path() + theme->id() + "\\");

		// TEMP
		//theme->set_dir();

		//old_theme_dir.removeRecursively();

		//m_themes.insert(new_name, m_themes.take(old_name));

		//m_themes[new_name]->set_name(new_name);

		//apply_theme(*m_themes[new_name]);
		//save_theme(*m_themes[new_name]);
	}
}

QString LApplication::name()
{
	return m_name;
}

LAttribute* LApplication::primary() const
{
	return m_primary;
}

void LApplication::reapply_theme()
{
	apply_theme(m_active_theme);
}

void LApplication::set_version(const QString& version)
{
	setApplicationVersion(version);
}

QSettings& LApplication::settings()
{
	return m_settings;
}

LTheme* LApplication::theme(const QString& theme_id)
{
	if (m_themes.contains(theme_id))
		return m_themes[theme_id];

	return nullptr;
}

void LApplication::_clear_theme()
{
	if (current_theme_item())
		apply_theme_item(nullptr);
}

void LApplication::init_directories()
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

void LApplication::init_fonts()
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

void LApplication::init_themes()
{
	/* TODO: Might need to handle case where theme files labeled "dark" or "light"
	   appear in the custom themes directory. */

	// Load prebuilt theme files
	m_themes["Dark"] = new LTheme(QDir(":/themes/Dark"));
	m_themes["Light"] = new LTheme(QDir(":/themes/Light"));

	QDir latest_T_version_dir = latest_T_version_path();

	for (const QString& dir_name : latest_T_version_dir.entryList(QDir::NoDotAndDotDot|QDir::Dirs))
	{
		LTheme* loaded_theme = new LTheme(QDir(latest_T_version_dir.absoluteFilePath(dir_name)));

		m_themes[loaded_theme->id()] = loaded_theme;
	}

	QString active_theme_id =
		m_settings.value("themes/active_theme").value<QString>();

	if (m_themes.contains(active_theme_id))
		apply_theme(m_themes[active_theme_id]);
	else
		apply_theme(m_themes["Dark"]);
}

void LApplication::init_latest_version()
{
	if (m_github_repo)
	{
		QUrl url(m_github_api_repos_url_base + "/" + m_github_repo->to_string() + "/tags");

		QNetworkReply* download = m_downloader->download(url);

		QEventLoop loop;
		connect(download, &QNetworkReply::finished, &loop, &QEventLoop::quit);
		loop.exec();

		if (download->error() == QNetworkReply::NoError)
		{
			QJsonDocument json_doc =
				QJsonDocument::fromJson(download->readAll());

			if (!json_doc.array().isEmpty())
				m_latest_version =
				json_doc.array().first().toObject()["name"].toString();
		}
	}
}
