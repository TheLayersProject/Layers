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

		Menu* app_menu() const;

		void assign_tag_prefixes();

		template<typename T>
		void build_main_widget();

		void center_dialog(QDialog* dialog);

		ColorDialog* control_color_dialog() const;

		GradientDialog* control_gradient_dialog() const;

		CustomizeMenu* customize_menu() const;

		void link_theme_name(const QString& name);

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

		CreateNewThemeDialog* m_control_create_new_theme_dialog{ new CreateNewThemeDialog(this)};

		ColorDialog* m_control_color_dialog{ new ColorDialog(this) };

		GradientDialog* m_control_gradient_dialog{ new GradientDialog(QGradientStops(), this) };

		UpdateDialog* m_control_update_dialog{ new UpdateDialog("", "", this) };

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

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
		m_app_menu = new T;

		m_titlebar->menu_tab_bar()->add_tab(m_app_menu);
		m_titlebar->menu_tab_bar()->tabs().last()->exit_button()->hide();
		m_titlebar->menu_tab_bar()->tabs().last()->text_label()->set_font_size(12);
		m_titlebar->menu_tab_bar()->tabs().last()->text_label()->set_padding(0, 8, 8, 0);
		m_titlebar->menu_tab_bar()->tabs().last()->set_state("Selected");

		m_app_menu->set_is_app_themeable(true);
		m_app_menu->apply_theme(*layersApp->current_theme());

		m_main_layout->addWidget(m_app_menu);

		if (m_customize_menu->preview_widget())
		{
			Window* preview_window = dynamic_cast<Window*>(m_customize_menu->preview_widget());

			if (preview_window)
				preview_window->build_main_widget<T>();
		}
	}
}

#endif // WINDOW_H
