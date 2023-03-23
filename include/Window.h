#ifndef WINDOW_H
#define WINDOW_H

#include <QVBoxLayout>

#include "Application.h"
#include "Widget.h"

namespace Layers
{
	class Menu;
	class SettingsMenu;
	class ThemeEditor;
	class Titlebar;

	class Window : public Widget
	{
		Q_OBJECT

	public:
		Window(bool preview = false, QWidget* parent = nullptr);

		Menu* app_menu() const;

		void center_dialog(QDialog* dialog);

		virtual Themeable* clone() override;

		void open_themeable_customization_widget(
			WidgetEditor* themeable_customization_widget);

		void set_main_menu(Menu* main_menu);

		void set_theme_customization_menu_preview_widget(
			QWidget* widget);

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

		Titlebar* m_titlebar;

		Menu* m_app_menu{ nullptr };

		SettingsMenu* m_settings_menu;

		ThemeEditor* m_theme_customization_menu;

		Widget* m_main_widget{ nullptr };

		Widget* m_separator{ new Widget };
	};
}

#endif // WINDOW_H
