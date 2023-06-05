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
		/*!
			Constructs a main window.
		*/
		MainWindow(bool preview = false, QWidget* parent = nullptr);

		/*!
			Moves *dialog* to the center of the window.
		*/
		void center_dialog(QDialog* dialog);

		/*!
			Constructs a new MainWindow and returns it as a pointer to a
			Themeable.

			The returned main window is intended to be used as a preview widget
			in the ThemeEditor.
		*/
		virtual Themeable* clone() override;

		/*!
			Sets *themeable* as the themeable being edited by the ThemeEditor.
		*/
		void edit_themeable(Themeable* themeable);

		/*!
			Sets *central_widget* to be the main window's central widget. 
		*/
		void set_central_widget(Widget* central_widget);

	public slots:
		/*!
			Closes the widget specified by *index*.
		*/
		void close_widget(int index);

		/*!
			Opens the specified *widget*.

			The *name* and *icon* parameters are used to create the tab that
			corresponds to the widget.
		*/
		void open_widget(
			Widget* widget, const QString& name, Graphic* icon = nullptr);

	protected:
		bool nativeEvent(
			const QByteArray& eventType, void* message, qintptr* result
		) override;

	private slots:
		void new_theme_clicked();

		void open_widget_changed(int old_index, int new_index);

	private:
		void init_attributes();
		void init_layout();
		void init_themes_widget_connections();
		void init_titlebar_connections();

		void update_theme_dependencies();

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
