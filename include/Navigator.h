#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <QIntValidator>

#include "Button.h"
#include "Graphic.h"

namespace Layers
{
	class Navigator : public QWidget, public Themeable
	{
		Q_OBJECT

	public:
		Navigator(QWidget* parent = nullptr);
		//~Navigator();

		Button* create_text_button(const QString& text);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private:
		void adjust_collapsed_widget();

		int calculated_topbar_content_width();

		void collapse_text_buttons();

		int content_width(bool include_collapse_button);

		Graphic* create_arrow_graphic();

		void expand_text_buttons();

		void init_layout();

		QList<Graphic*> m_arrow_graphics;

		Widget* m_collapse_menu{ new Widget };

		Button* m_collapse_menu_button{ new Button(new Graphic(":/svgs/ellipsis.svg", QSize(32, 8)), true) };

		QVBoxLayout* m_collapse_menu_layout{ new QVBoxLayout };

		QList<Button*> m_collapsed_text_buttons;

		Graphic* m_control_arrow_graphic{ new Graphic(":/svgs/collapse_arrow_right.svg", QSize(8, 12)) };

		Button* m_control_text_button{ new Button("") };

		QHBoxLayout* m_main_layout{ new QHBoxLayout };

		QList<Button*> m_text_button_stack;

		QList<Button*> m_topbar_text_buttons;
	};
}

#endif // NAVIGATOR_H
