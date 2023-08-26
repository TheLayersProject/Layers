#ifndef LMAINWINDOW_H
#define LMAINWINDOW_H

#include <QVBoxLayout>

#include "layers_global.h"
#include "layers_exports.h"

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

	## Central Widgets

	Central widgets are widgets that appear underneath the window's titlebar
	and take up a majority of the window's visible space. Multiple central
	widgets can be opened at a time, but only one visible, so there is a
	corresponding tab in the titlebar for each open central widget to give the
	user a way to switch between them.

	To open a central widget, use the open_central_widget() function. For
	example:

	~~~~~~~~~~~~~{.c}
	open_central_widget(new LayersDemo,
		LGraphic(":/images/layers.imgseq", QSize(35, 35)));
	~~~~~~~~~~~~~

	The example above shows how the LayersDemo central widget is set in
	the *Layers Demo* application.

	## Titlebar

	The main window contains a titlebar with an LTabBar for swapping between
	central widgets and LButton widgets for window management.
	
	There is a special titlebar button called the *settings button*, labeled
	with a gear icon, that opens a LSettingsMenu as a central widget.

	## Closing the Application

	The user can close the application by clicking on the *exit button* in the
	window's titlebar, or by closing all of the central widget tabs.
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
		Opens *central_widget* and associates it with a tab in the window's
		titlebar.
	*/
	void open_central_widget(QWidget* central_widget);

	/*!
		Opens *central_widget* and associates it with a tab in the window's
		titlebar.

		The *tab_icon_graphic* is the graphic given to the tab's icon.
	*/
	void open_central_widget(
		QWidget* central_widget, const LGraphic& tab_icon_graphic);

	/*!
		Updates the main window.

		This function overrides LThemeable::update() to adjust the window's
		layout according to the border thickness and margins.
	*/
	virtual void update() override;

protected:
	virtual bool nativeEvent(
		const QByteArray& eventType, void* message, qintptr* result) override;

private slots:
	void new_theme_clicked();

private:
	void init_attributes();
	void init_layout();
	void init_titlebar_connections();

	void _open_central_widget(QWidget* central_widget);

	void set_active_central_widget(QWidget* central_widget);

	QVBoxLayout* m_main_layout{ new QVBoxLayout };

	LMainWindowTitlebar* m_titlebar;

	LWidget* m_separator{ new LWidget };

	QList<QWidget*> m_central_widgets;
};
LAYERS_NAMESPACE_END

#endif // LMAINWINDOW_H
