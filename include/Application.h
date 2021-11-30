#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <QDir>
#include <QSettings>

#include "Theme.h"

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
			QFile* icon_file = nullptr,
			Version* version = nullptr,
			GitHubRepo* github_repo = nullptr);

		void add_child_themeable_reference(Themeable& themeable);

		void apply_theme(Theme& theme);

		void create_theme(const QString& new_theme_name, const QString& copy_theme_name);

		Theme* current_theme() const;

		QFile* icon_file();

		Theme load_theme(QFile& file);

		QString& name();

		void reapply_theme();

		void save_theme(Theme& theme);

		QSettings& settings();

		Theme* theme(const QString& theme_name);

		QMap<QString, Theme>& themes();

		bool update_available();

		bool update_on_request();

	public slots:
		void rename_theme(const QString& old_name, const QString& new_name);

	private:
		void copy_missing_attributes_to(Theme& theme_missing_attributes);

		void init_directories();
		void init_fonts();
		void init_themes();
		void init_latest_version_tag();

		QDir m_app_dir;

		QDir m_app_themes_dir;

		QList<Themeable*> m_child_themeable_references;

		Theme* m_current_theme{ nullptr };

		Downloader* m_downloader{ nullptr };

		QString m_github_api_repos_url_base{ "https://api.github.com/repos" };

		GitHubRepo* m_github_repo{ nullptr };

		QFile* m_icon_file{ nullptr };

		QString* m_latest_version{ nullptr };

		QString m_name;

		QSettings m_settings;

		QMap<QString, Theme> m_themes;

		Version* m_version{ nullptr };
	};
}

#define layersApp (static_cast<Layers::Application*>(qApp))

#endif // APPLICATION_H
