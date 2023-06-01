#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVBoxLayout>

#include "Application.h"
#include "Widget.h"

namespace Layers
{
	class Menu;
	class SettingsMenu;
	class ThemeEditor;
	class MainWindowTitlebar;

	/*!
		A MainWindow is a Widget that provides a main application window.
	*/
	class MainWindow : public Widget
	{
		Q_OBJECT

	public:
		MainWindow(bool preview = false, QWidget* parent = nullptr);

		void center_dialog(QDialog* dialog);

		virtual Themeable* clone() override;

		void edit_themeable(Themeable* themeable);

		void set_central_widget(Widget* central_widget);

		void update_theme_dependencies();

	public slots:
		void close_menu(int index);
		void new_theme_clicked();
		void menu_changed(int old_index, int new_index);
		void open_widget(
			Widget* widget, const QString& name, Graphic* graphic = nullptr);

	protected:
		bool nativeEvent(
			const QByteArray& eventType, void* message, qintptr* result) override;

	private:
		void init_attributes();
		void init_layout();
		void init_themes_widget_connections();
		void init_titlebar_connections();

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		QList<QWidget*> m_opened_widgets;

		MainWindowTitlebar* m_titlebar;

		Widget* m_separator{ new Widget };

		Widget* m_central_widget{ nullptr };

		// Menus
		SettingsMenu* m_settings_menu;
		ThemeEditor* m_theme_editor;
	};
}

#endif // MAINWINDOW_H
