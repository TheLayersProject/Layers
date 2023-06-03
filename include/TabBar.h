#ifndef TABBAR_H
#define TABBAR_H

#include <QHBoxLayout>

#include "Tab.h"
#include "Widget.h"

namespace Layers
{
	class TabBar : public Widget
	{
		Q_OBJECT

	signals:
		void index_changed(int old_index, int new_index);
		void tab_closed(int index);

	public:
		TabBar(QWidget* parent = nullptr);

		void add_tab(const Graphic& icon, const QString& text);

		void add_tab(const QString& text);

		int current_index() const;

		void set_current_index(int index);

		QList<Tab*> tabs() const;

	protected:
		void init_attributes();
		void init_layout();

		void _add_tab(Tab* tab);

		Tab* m_control_tab{ new Tab(Graphic(":/svgs/exit.svg"), "", this)};

		int m_current_index{ -1 };

		QList<Tab*> m_tabs;

		QHBoxLayout* m_tab_layout{ new QHBoxLayout };
	};
}

#endif // TABBAR_H
