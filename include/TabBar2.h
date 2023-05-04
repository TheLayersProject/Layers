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

		Tab* add_tab(Menu* menu);

		QList<Tab*> tabs();

		void select_tab(Tab* selected_tab);

	protected:
		void init_attributes();

	private:
		void setup_layout();

		Tab* m_control_tab{ new Tab(this) };

		QHBoxLayout* m_tab_layout{ new QHBoxLayout };
	};
}

#endif // TABBAR2_H
