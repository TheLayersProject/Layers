#include "TabBar2.h"

#include <QEvent>
#include <QResizeEvent>

using Layers::Tab;
using Layers::TabBar2;

TabBar2::TabBar2(QWidget* parent) : Widget(parent)
{
	init_attributes();

	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	m_control_tab->hide();

	setup_layout();
}

void TabBar2::add_tab(Menu* menu)
{
	Tab* tab = new Tab(menu);

	tab->entangle_with(m_control_tab);

	connect(tab, &Tab::clicked, [this, tab] {
		if (!tab->menu()->isVisible())
		{
			select_tab(tab);
		}
	});

	connect(tab, &Tab::exit_pressed, [this, tab] {		
		if (tab->menu()->isVisible())
		{
			QList<Tab*> tab_list = tabs();

			tab_list.removeOne(tab);

			if (!tab_list.isEmpty())
				select_tab(tab_list.last());
		}

		tab->deleteLater();
	});

	m_tab_layout->insertWidget(m_tab_layout->count() - 1, tab);
}

bool TabBar2::is(QWidget* widget)
{
	if (this == widget || m_foreground_widget == widget)
		return true;

	return false;
}

QList<Tab*> TabBar2::tabs()
{
	QList<Tab*> tabs_list;

	tabs_list = findChildren<Tab*>();

	tabs_list.removeOne(m_control_tab);

	return tabs_list;
}

void TabBar2::select_tab(Tab* selecting_tab)
{
	selecting_tab->fill()->set_state("Active");
	selecting_tab->menu()->show();

	for (Tab* tab : tabs())
		if (tab != selecting_tab)
		{
			tab->fill()->set_state("Inactive");
			tab->menu()->hide();
		}
}

void TabBar2::init_attributes()
{
	m_fill->set_disabled();

	m_foreground_widget->fill()->set_disabled();
}

void TabBar2::resizeEvent(QResizeEvent* event)
{
	m_foreground_widget->setFixedSize(size());
	//m_foreground_widget->setFixedSize(size());
}

void TabBar2::setup_layout()
{
	m_tab_layout->addStretch();
	m_tab_layout->setContentsMargins(0, 0, 0, 0);
	m_tab_layout->setSpacing(0);

	m_foreground_widget->setLayout(m_tab_layout);
}
