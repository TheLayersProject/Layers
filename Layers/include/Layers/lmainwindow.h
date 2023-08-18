#ifndef LMAINWINDOW_H
#define LMAINWINDOW_H

#include <QVBoxLayout>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeeditordialog.h"
#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class Menu;
class LSettingsMenu;
class LMainWindowTitlebar;

/*!
	![LMainWindow Example](main_window.png)
	
	An LMainWindow is a LWidget that provides a main window interface
	for *Layers* applications.

	The image above shows how the main window appears in the *Layers Demo*
	application.

	## Titlebar

	The main window contains a titlebar with an LTabBar for navigating between
	the window's central widgets and LButton widgets for window management.
	There is also a special titlebar button called the *settings button*,
	labeled with a gear icon, that opens the window's LSettingsMenu central
	widget.

	## Central Widgets

	Central widgets are widgets that appear underneath the window's titlebar.
	The active central widget takes up a majority of the window's available
	space.

	To set a central widget, use the set_central_widget() function. For
	example:

	~~~~~~~~~~~~~{.c}
	set_central_widget(new LayersDemo);
	~~~~~~~~~~~~~

	The example above shows how the central widget is set in the *Layers Demo*
	application.

	## Exiting the Application

	Exiting the main window exits the whole application.
*/
class LAYERS_EXPORT LMainWindow : public LWidget
{
	Q_OBJECT

public:
	/*!
		Constructs a main window.
	*/
	LMainWindow(QWidget* parent = nullptr);

	/*!
		Moves *dialog* to the center of the window.
	*/
	void center_dialog(QDialog* dialog);

	/*!
		Sets *central_widget* to be the main window's central widget. 
	*/
	void set_central_widget(LWidget* central_widget);

	virtual void update() override;

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
		LWidget* widget, const QString& name, LGraphic* icon = nullptr);

protected:
	virtual bool nativeEvent(
		const QByteArray& eventType, void* message, qintptr* result) override;

private slots:
	void new_theme_clicked();

	void open_widget_changed(int old_index, int new_index);

private:
	void init_attributes();
	void init_layout();
	void init_themes_widget_connections();
	void init_titlebar_connections();

	QVBoxLayout* m_main_layout{ new QVBoxLayout };

	QList<QWidget*> m_opened_widgets;

	LMainWindowTitlebar* m_titlebar;

	LWidget* m_separator{ new LWidget };

	LWidget* m_central_widget{ nullptr };

	LSettingsMenu* m_settings_menu;

	LThemeEditorDialog* m_theme_editor_dialog{ new LThemeEditorDialog };
};
LAYERS_NAMESPACE_END

#endif // LMAINWINDOW_H
