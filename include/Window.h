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

		void center_dialog(QDialog* dialog);

		virtual Themeable* clone() override;

		CustomizeMenu* customize_menu() const;

		void set_main_menu(Menu* main_menu);

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

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		Titlebar* m_titlebar{ new Titlebar };

		Menu* m_app_menu{ nullptr };

		SettingsMenu* m_settings_menu{ new SettingsMenu };

		CustomizeMenu* m_customize_menu{ new CustomizeMenu };

		Widget* m_main_widget{ nullptr };

		Widget* m_separator{ new Widget };
	};
}

#endif // WINDOW_H
