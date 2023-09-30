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

class LAYERS_EXPORT LMainWindow : public LWidget
{
	Q_OBJECT

public:
	LMainWindow(QWidget* parent = nullptr);

	void open_central_widget(QWidget* central_widget);

	void open_central_widget(
		QWidget* central_widget, const LGraphic& tab_icon_graphic);

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
