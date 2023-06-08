#ifndef TABBAR_H
#define TABBAR_H

#include <QHBoxLayout>

#include "Tab.h"
#include "Widget.h"

namespace Layers
{
	/*!
		A TabBar is a Widget that lets the user switch between different
		widgets that are represented by a set of tabs.
	*/
	class TabBar : public Widget
	{
		Q_OBJECT

	signals:
		/*!
			This signal is emitted when the current index changes.
		*/
		void index_changed(int old_index, int new_index);

		/*!
			This signal is emitted when a tab is closed.
		*/
		void tab_closed(int index);

	public:
		/*!
			Constructs a tab bar.
		*/
		TabBar(QWidget* parent = nullptr);

		/*!
			Creates a tab labeled with an *icon* and *text*.
		*/
		void add_tab(const Graphic& icon, const QString& text);

		/*!
			Creates a tab labeled with *text*.
		*/
		void add_tab(const QString& text);

		/*!
			Returns the current index of the tab bar.
		*/
		int current_index() const;

		/*!
			Sets the current index of the tab bar.
		*/
		void set_current_index(int index);

		/*!
			Returns a list of pointers to the tabs of the tab bar.
		*/
		QList<Tab*> tabs() const;

	protected:
		void init_attributes();
		void init_layout();

		void _add_tab(Tab* tab);

		Tab* m_control_tab{ new Tab(Graphic(":/images/exit.svg"), "", this)};

		int m_current_index{ -1 };

		QList<Tab*> m_tabs;

		QHBoxLayout* m_tab_layout{ new QHBoxLayout };
	};
}

#endif // TABBAR_H
