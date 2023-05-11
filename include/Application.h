#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QDir>
#include <QSettings>
#include <QUuid>

#include "directories.h"
#include "Theme.h"
#include "Themeable.h"

namespace Layers
{
	class CreateNewThemeDialog;
	class ColorDialog;
	class Downloader;
	class GitHubRepo;
	class GradientDialog;
	class ThemeCompatibilityCautionDialog;
	class UpdateDialog;
	class Version;
	class MainWindow;

	/*!
		A Layers Application is a QApplication and a Themeable that provides
		structure and functionality for a Layers app.

		## App ID

		Layers app developers will need to manually produce a UUID for their
		application. The app name and UUID are used together to produce an
		app ID which is used by themes to specify app-implementations. The UUID
		for an application should never be changed because things may stop
		working properly if it does.

		## Theme Management

		The application manages loaded themes. The application is responsible
		for applying themes to known top-level widgets.

		## Updating

		The application includes functionality capable of updating itself when
		an update is available.

		<b>For now, this only works for applications hosted on GitHub. In the
		future, there will be an option to enable updating from file
		servers.</b>

		To enable update checking, Layers app developers will need to include
		Version and GitHubRepo objects as arguments for Application
		construction. These objects are used during initialization to retrieve
		the latest version via GitHub's API and compare it with the current
		version to determine if an update is available.

		After the application has been initialized in the *main()* function,
		the developers can include the following code:

		~~~~~~~~~~~~~{.c}
		if (app.update_available())
			if (app.update_on_request())
				return 0;
		~~~~~~~~~~~~~

		In the code above, update_available() is called to check if an update
		is available. If so, update_on_request() is called to display an
		UpdateDialog to the user which alerts them and asks if they would like
		to update the application. If they choose 'Update', then
		update_on_request() will return true and cause the *main()* function
		to end, closing the application while the update takes place. If the
		user chooses not to update, then the *main()* function will proceed.

		It is recommended to perform this sequence before initializing the
		MainWindow.
	*/
	class Application : public QApplication, public Themeable
	{
		Q_OBJECT

	signals:
		/*!
			This signal is emitted if the active theme changes.
		*/
		void active_theme_changed();

	public:
		/*!
			Constructs a Layers application.

			The *name* and *uuid* parameters are required.

			The *version* and *github_repo* parameters are only required if the
			Layers app developer decides to utilize the included updating
			functionality.
		*/
		Application(int& argc, char** argv,
			const QString& name,
			const QUuid& uuid,
			QFile* icon_file = nullptr,
			Version* version = nullptr,
			GitHubRepo* github_repo = nullptr);

		~Application();

		/*!
			Returns a pointer to the active theme.
		*/
		Theme* active_theme() const;

		/*!
			Stores a pointer to the provided themeable.

			This function should be used to make top-level widgets known to the
			application.
		*/
		void add_child_themeable_pointer(Themeable& themeable);

		/*!
			Returns a string representation of the app ID.
		*/
		QString app_identifier();

		/*!
			Applies *theme* to the known top-level widgets.
		*/
		void apply_theme(Theme& theme);

		/*!
			Returns a list of child themeables.

			This function overrides Themeable::child_themeables() to include
			the known top-level widgets.
		*/
		virtual QList<Themeable*> child_themeables(
			Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
		) override;

		/*!
			Returns a pointer to the application's CreateNewThemeDialog.
		*/
		CreateNewThemeDialog* create_new_theme_dialog() const;

		/*!
			Returns a pointer to the application's ColorDialog.
		*/
		ColorDialog* color_dialog() const;

		/*!
			Returns a pointer to the application's GradientDialog.
		*/
		GradientDialog* gradient_dialog() const;

		/*!
			Returns a pointer to a QFile of the application icon.

			If no icon was supplied during initialization, nullptr is returned.
		*/
		QFile* icon_file();

		/*!
			Returns the name of the application.
		*/
		QString name();

		/*!
			Reapplies the active theme.
		*/
		void reapply_theme();

		/*!
			Saves *theme* to the system.
		*/
		void save_theme(Theme& theme);

		/*!
			Returns the application's settings.
		*/
		QSettings& settings();

		/*!
			Returns a pointer to the theme specified by *theme_id*.
		*/
		Theme* theme(const QString& theme_id);

		/*!
			Returns a pointer to the application's
			ThemeCompatibilityCautionDialog.
		*/
		ThemeCompatibilityCautionDialog* theme_compatibility_caution_dialog()
			const;

		/*!
			Returns a reference to the QMap containing the application's
			themes.

			The QMap contains QString-Theme* pairs where the QString matches
			the name of the associated theme.
		*/
		QMap<QString, Theme*>& themes();

		/*!
			Returns true if an application update is available.
		*/
		bool update_available();

		/*!
			Prompts the user with an UpdateDialog asking if they would like to
			update the application.

			Returns true if the user decides to update. Otherwise, returns
			false.
		*/
		bool update_on_request();

	public slots:
		/*!
			Renames the theme specified by *old_name* to *new_name*.
		*/
		void rename_theme(const QString& old_name, const QString& new_name);

	private:
		void init_directories();
		void init_fonts();
		void init_themes();
		void init_latest_version_tag();

		QList<Themeable*> m_child_themeables;

		CreateNewThemeDialog* m_create_new_theme_dialog;

		ColorDialog* m_color_dialog;

		GradientDialog* m_gradient_dialog;

		ThemeCompatibilityCautionDialog* m_theme_compatibility_caution_dialog;

		UpdateDialog* m_update_dialog;

		Theme* m_active_theme{ nullptr };

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
