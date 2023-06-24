#ifndef LMAINWINDOWTITLEBAR_H
#define LMAINWINDOWTITLEBAR_H

#include <Layers/layers_global.h>

#include <Layers/ltabbar.h>

LAYERS_NAMESPACE_BEGIN
class LMainWindowTitlebar : public LWidget
{
	Q_OBJECT

public:
	LMainWindowTitlebar(QWidget* parent = nullptr);

	LTabBar* menu_tab_bar() const;

	LButton* settings_button() const;
	LButton* minimize_button() const;
	LButton* maximize_button() const;
	LButton* exit_button() const;

protected:
	void init_layout();

private:
	QHBoxLayout* main_layout = new QHBoxLayout;

	LButton* m_settings_button{
		new LButton(LGraphic(":/images/settings.svg", QSize(20, 20))) };

	LButton* m_minimize_button{
		new LButton(LGraphic(":/images/minimize.svg", QSize(20, 20))) };

	LButton* m_maximize_button{
		new LButton(LGraphic(":/images/maximize.svg", QSize(20, 20))) };

	LButton* m_exit_button{
		new LButton(LGraphic(":/images/exit.svg", QSize(20, 20))) };

	LTabBar* m_menu_tab_bar{ new LTabBar };
};
LAYERS_NAMESPACE_END

#endif // LMAINWINDOWTITLEBAR_H
