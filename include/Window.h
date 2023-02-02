#ifndef WINDOW_H
#define WINDOW_H

#include "Application.h"
#include "ColorDialog.h"
#include "CreateNewThemeDialog.h"
#include "CustomizeMenu.h"
#include "GradientDialog.h"
#include "SettingsMenu.h"
#include "Titlebar.h"
#include "UpdateDialog.h"

namespace Layers
{
	class Window : public Widget
	{
		Q_OBJECT

	public:
		Window(bool preview = false, QWidget* parent = nullptr);

		void add_menu(Menu* menu);

		Menu* app_menu() const;

		void assign_tag_prefixes();

		template<typename T>
		void build_main_widget();

		void center_dialog(QDialog* dialog);

		ColorDialog* control_color_dialog() const;

		GradientDialog* control_gradient_dialog() const;

		CustomizeMenu* customize_menu() const;

		void finalize();

		void link_theme_name(const QString& name);

		void set_main_widget(Widget* main_widget);

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
		bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;

		void paintEvent(QPaintEvent* event) override;

	private:
		void setup_layout();

		bool m_maximized{ false };
		bool m_preview{ false };

		CreateNewThemeDialog* m_create_new_theme_dialog{ new CreateNewThemeDialog };

		ColorDialog* m_control_color_dialog{ new ColorDialog(this) };

		GradientDialog* m_control_gradient_dialog{ new GradientDialog(QGradientStops(), this) };

		UpdateDialog* m_control_update_dialog{ new UpdateDialog("", "", this) };

		QVBoxLayout* m_app_menu_layout{ new QVBoxLayout };
		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		QList<Menu*> m_menus;
		QList<Menu*> m_menu_stack;

		Titlebar* m_titlebar{ new Titlebar };

		Menu* m_app_menu{ nullptr };

		SettingsMenu* m_settings_menu{ new SettingsMenu };

		CustomizeMenu* m_customize_menu{ new CustomizeMenu };

		Widget* m_main_widget{ nullptr };

		Widget* m_tab_menu_separator{ new Widget };
	};

	template<typename T>
	inline void Window::build_main_widget()
	{
		m_main_widget = new T;

		//m_main_widget->set_icon(new Graphic(layersApp->icon_file()->fileName()));
		m_main_widget->set_is_app_themeable(true);
		m_main_widget->apply_theme(*layersApp->current_theme());

		add_child_themeable_pointer(m_main_widget);

		m_app_menu_layout->addWidget(m_main_widget);

		if (m_customize_menu->preview_widget())
		{
			Window* preview_window = dynamic_cast<Window*>(m_customize_menu->preview_widget());

			if (preview_window)
				preview_window->build_main_widget<T>();
		}
	}
}

#endif // WINDOW_H
