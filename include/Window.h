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

		void center_dialog(QDialog* dialog);

		virtual Themeable* clone() override;

		void edit_themeable(Themeable* themeable);

		void set_main_menu(Menu* main_menu);

		void update_theme_dependencies();

	public slots:
		void new_theme_clicked();
		void open_menu(Menu* menu);

	protected:
		bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;

	private:
		void init_attributes();
		void init_layout();
		void init_themes_widget_connections();
		void init_titlebar_connections();

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		Titlebar* m_titlebar;

		Widget* m_separator{ new Widget };

		// Menus
		Menu* m_app_menu{ nullptr };
		SettingsMenu* m_settings_menu;
		ThemeEditor* m_theme_editor;
	};
}

#endif // WINDOW_H
