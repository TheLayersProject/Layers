#ifndef WINDOW_H
#define WINDOW_H

#include "CreateNewThemeDialog.h"
#include "CustomizeMenu.h"
#include "SettingsMenu.h"
#include "Titlebar.h"

namespace Layers
{
	class Window : public Widget
	{
		Q_OBJECT

	public:
		Window(bool preview = false, QWidget* parent = nullptr);

		void add_menu(Menu* menu);

		Menu* app_menu() const;

		void apply_theme(Theme& theme);

		void assign_tag_prefixes();

		//template<typename T>
		//void build_main_widget();

		void center_dialog(QDialog* dialog);

		CustomizeMenu* customize_menu() const;

		void finalize();

		void link_theme_name(const QString& name);

		void set_main_widget(Widget* main_widget);

		void set_window_icon(const Graphic& icon_graphic);

		void set_window_title(const QString& title);

		SettingsMenu* settings_menu() const;

		Titlebar* titlebar() const;

		void update_theme_dependencies();

	public slots:
		void customize_clicked();
		void exit_clicked();
		void maximize_clicked();
		void minimize_clicked();
		void new_theme_clicked();
		void open_menu(Menu* menu);
		void settings_clicked();

	protected:
		void init_attribute_widgets();

		void init_child_themeable_reference_list();

		bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;

		void paintEvent(QPaintEvent* event) override;

	private:
		void setup_layout();

		bool m_maximized{ false };
		bool m_preview{ false };

		CreateNewThemeDialog* m_create_new_theme_dialog{ new CreateNewThemeDialog };

		QVBoxLayout* m_app_menu_layout{ new QVBoxLayout };
		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		QList<Menu*> m_menus;
		QList<Menu*> m_menu_stack;

		Titlebar* m_titlebar{ new Titlebar };

		// TODO: Make Menu constructor that does not require an icon
		Menu* m_app_menu{ new Menu("App", new Graphic(":/svgs/settings_animated.svg", QSize(24, 24))) };

		SettingsMenu* m_settings_menu{ new SettingsMenu };

		CustomizeMenu* m_customize_menu{ new CustomizeMenu };

		Widget* m_main_widget{ nullptr };
	};
}

#endif // WINDOW_H
