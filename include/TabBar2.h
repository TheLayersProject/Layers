#ifndef TABBAR2_H
#define TABBAR2_H

#include <QHBoxLayout>

#include "Tab.h"
#include "Widget.h"

namespace Layers
{
	class TabBar2 : public Widget
	{
		Q_OBJECT

	public:
		TabBar2(QWidget* parent = nullptr);

		void add_tab(Menu* menu);

		bool is(QWidget* widget);

		QList<Tab*> tabs();

		void select_tab(Tab* selected_tab);

	protected:
		void init_attributes();

		void resizeEvent(QResizeEvent* event);

	private:
		void setup_layout();

		Tab* m_control_tab{ new Tab(this) };

		//Widget* m_background_widget{ new Widget(this) };
		Widget* m_foreground_widget{ new Widget(this) };

		QHBoxLayout* m_tab_layout{ new QHBoxLayout };
	};
}

#endif // TABBAR2_H
