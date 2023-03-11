#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QDir>
#include <QSettings>
#include <QUuid>

#include "ColorDialog.h"
#include "CreateNewThemeDialog.h"
#include "directories.h"
#include "GradientDialog.h"
#include "Theme.h"
#include "Themeable.h"
#include "ThemeCompatibilityCautionDialog.h"
#include "UpdateDialog.h"

namespace Layers
{
	class CustomizePanel;
	class Downloader;
	class GitHubRepo;
	class Version;
	class Window;

	class Application : public QApplication, public Themeable
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

		~Application();

		QString app_identifier();

		/*!
			Applies a theme across the entire application.

			@param theme to apply
		*/
		void apply_theme(Theme& theme);

		virtual QList<Themeable*> child_themeables(
			Qt::FindChildOptions options = Qt::FindDirectChildrenOnly) override;

		CreateNewThemeDialog* create_new_theme_dialog() const;

		ColorDialog* color_dialog() const;

		/*!
			Returns a pointer to the current theme applied to the application.

			@returns pointer to current application theme
		*/
		Theme* current_theme() const;

		CustomizePanel* customize_panel();

		GradientDialog* gradient_dialog() const;

		/*!
			Returns a pointer to a QFile of the application icon.

			If no icon was supplied during initialization, nullptr is returned.

			@returns pointer to QFile of app icon, nullptr if none exists
		*/
		QFile* icon_file();

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
		void add_child_themeable_pointer(Themeable& themeable);

		/*!
			Returns a pointer to the application theme with the provided name.

			@param theme_name - Name of the theme to be returned
			@returns pointer to theme
		*/
		Theme* theme(const QString& theme_name);

		ThemeCompatibilityCautionDialog* theme_compatibility_caution_dialog() const;

		/*!
			Returns a reference to a QMap containing the application's themes.

			The QMap pairs QStrings to Themes, where the QString is the name of the associated theme.

			@returns QMap reference to the app's themes
		*/
		QMap<QString, Theme*>& themes();

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

		//QDir m_layers_dir{ QDir(layers_path()) };

		//QDir m_layers_themes_dir{ QDir(themes_path()) };

		QList<Themeable*> m_child_themeables;

		CreateNewThemeDialog* m_create_new_theme_dialog;

		ColorDialog* m_color_dialog;

		GradientDialog* m_gradient_dialog;

		ThemeCompatibilityCautionDialog* m_theme_compatibility_caution_dialog;

		UpdateDialog* m_update_dialog;

		Theme* m_current_theme{ nullptr };

		Downloader* m_downloader{ nullptr };

		QString m_github_api_repos_url_base{ "https://api.github.com/repos" };

		GitHubRepo* m_github_repo{ nullptr };

		QFile* m_icon_file{ nullptr };

		QString* m_latest_version{ nullptr };

		QString m_name;

		QString m_name_underscored;

		QSettings m_settings;

		QMap<QString, Theme*> m_themes;

		QUuid m_uuid;

		Version* m_version{ nullptr };
	};
}

#define layersApp (static_cast<Layers::Application*>(qApp))

#endif // APPLICATION_H
