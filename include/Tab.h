#ifndef MENULABELLAYER_H
#define MENULABELLAYER_H

#include "Button.h"
#include "Graphic.h"
#include "Label.h"
#include "Menu.h"

namespace Layers
{
	class Tab : public Widget
	{
		Q_OBJECT

	signals:
		void clicked();
		void exit_pressed();

	public:
		Tab(QWidget* parent = nullptr);
		Tab(Menu* menu, QWidget* parent = nullptr);

		Menu* menu() const;

		Button* exit_button() const;

		Label* text_label() const;

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();

		void setup_layout();

	private:
		QHBoxLayout* main_layout = new QHBoxLayout;

		Button* m_exit_button{ new Button(new Graphic(":/svgs/tab_exit.svg", QSize(16, 17))) };

		Graphic* m_tab_icon{ nullptr };

		Label* m_text_label{ nullptr };

		Menu* m_menu{ nullptr };
	};
}

#endif // MENULABELLAYER_H
