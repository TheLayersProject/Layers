#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QDir>
#include <QSettings>
#include <QUuid>
#include "directories.h"
#include "Theme.h"
#include "Window.h"

namespace Layers
{
	class Downloader;
	class GitHubRepo;
	class Version;

	class Application : public QApplication
	{
		Q_OBJECT

	signals:
		void current_theme_changed();

	public:
		Application(
			int& argc, char** argv,
			const QString& name,
			const QUuid& uuid,
			QFile* icon_file = nullptr,
			Version* version = nullptr,
			GitHubRepo* github_repo = nullptr);

		QString app_identifier();

		/*!
			Applies a theme across the entire application.

			@param theme to apply
		*/
		void apply_theme(Theme& theme);

		/*!
			Creates a new theme.

			@param new_theme_name - Name to give the new theme
			@param copy_theme_name - Name of the app theme to copy and use as the basis for the new theme
		*/
		void create_theme(const QString& new_theme_name, const QString& copy_theme_name);

		/*!
			Returns a pointer to the current theme applied to the application.

			@returns pointer to current application theme
		*/
		Theme* current_theme() const;

		/*!
			Returns a pointer to a QFile of the application icon.

			If no icon was supplied during initialization, nullptr is returned.

			@returns pointer to QFile of app icon, nullptr if none exists
		*/
		QFile* icon_file();

		/*!
			Loads and returns a theme from the supplied file.

			This function first attempts to load the theme as a latest version theme. If that fails,
			it will attempt to load the file under older version conditions until a successful load.
			Once the particular version is found and loaded, it is updated to the latest version.

			This function is updated with each new version of Layers.

			@param file to load theme from
			@returns theme loaded from file
		*/
		Theme load_theme(const QString& file_name);

		Window* main_window() const;

		/*!
			Returns the name of the application.

			@returns application name
		*/
		QString& name();

		/*!
			Reapplies the theme that is already set.
		*/
		void reapply_theme();

		/*!
			Saves a theme to a file.

			The file is saved to 'C:/Users/{Your username}/AppData/Local/{Application name}/Themes'.
			
			The theme name, lowercased, is used as the filename.

			@param theme to save
		*/
		void save_theme(Theme& theme);

		/*!
			Returns the application's settings.

			@returns Settings of the application
		*/
		QSettings& settings();

		/*!
			Stores a pointer to the provided themeable.

			The child themeable pointers are used to apply themes to child themeables.

			@param themeable to store a pointer to
		*/
		void store_child_themeable_pointer(Themeable& themeable);

		/*!
			Returns a pointer to the application theme with the provided name.

			@param theme_name - Name of the theme to be returned
			@returns pointer to theme
		*/
		Theme* theme(const QString& theme_name);

		/*!
			Returns a reference to a QMap containing the application's themes.

			The QMap pairs QStrings to Themes, where the QString is the name of the associated theme.

			@returns QMap reference to the app's themes
		*/
		QMap<QString, Theme>& themes();

		/*!
			Returns true if an application update is available. 

			This function compares the current version tag of the application (supplied during initialization)
			with the latest known version tag found on the application's GitHub repo (also supplied during initialization). 
			If they do not match, true is returned.

			@returns true if update is available, false otherwise
		*/
		bool update_available();

		/*!
			Prompts the user and asks if they'd like to update. Updates application if they choose to.

			@returns true if user chooses to update, false otherwise
		*/
		bool update_on_request();

	public slots:
		/*!
			Renames a theme with the provided new name.

			@param old_name - Name of the theme to rename
			@param new_name - New name to give to theme
		*/
		void rename_theme(const QString& old_name, const QString& new_name);

	private:
		void init_directories();
		void init_fonts();
		void init_themes();
		void init_latest_version_tag();

		QDir m_app_dir;

		QDir m_app_themes_dir;

		QDir m_layers_dir{ QDir(layers_path()) };

		QDir m_layers_themes_dir{ QDir(layers_themes_path()) };

		QList<Themeable*> m_child_themeables;

		Theme* m_current_theme{ nullptr };

		Downloader* m_downloader{ nullptr };

		QString m_github_api_repos_url_base{ "https://api.github.com/repos" };

		GitHubRepo* m_github_repo{ nullptr };

		QFile* m_icon_file{ nullptr };

		QString* m_latest_version{ nullptr };

		QString m_name;

		QString m_name_underscored;

		QSettings m_settings;

		QMap<QString, Theme> m_themes;

		QUuid m_uuid;

		Version* m_version{ nullptr };
	};
}

#define layersApp (static_cast<Layers::Application*>(qApp))

#endif // APPLICATION_H
