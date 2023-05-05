#ifndef MAINWINDOWTITLEBAR_H
#define MAINWINDOWTITLEBAR_H

#include "TabBar.h"

namespace Layers
{
	class MainWindowTitlebar : public Widget
	{
		Q_OBJECT

	public:
		MainWindowTitlebar(QWidget* parent = nullptr);

		TabBar* menu_tab_bar() const;

		Button* settings_button() const;
		Button* minimize_button() const;
		Button* maximize_button() const;
		Button* exit_button() const;

	protected:
		void setup_layout();

	private:
		QHBoxLayout* main_layout = new QHBoxLayout;

		Button* m_settings_button{
			new Button(
				new Graphic(":/svgs/settings.svg", QSize(20, 20)),
				true) };

		Button* m_minimize_button{
			new Button(
				new Graphic(":/svgs/minimize.svg", QSize(20, 20)),
				true) };

		Button* m_maximize_button{
			new Button(
				new Graphic(":/svgs/maximize.svg", QSize(20, 20)),
				true) };

		Button* m_exit_button{
			new Button(
				new Graphic(":/svgs/exit.svg", QSize(20, 20)),
				true) };

		TabBar* m_menu_tab_bar{ new TabBar };
	};
}

#endif // MAINWINDOWTITLEBAR_H
