#include "TabBar.h"

#include <QEvent>
#include <QResizeEvent>

using Layers::Tab;
using Layers::TabBar;

TabBar::TabBar(QWidget* parent) : Widget(parent)
{
	init_attributes();
	init_layout();

	m_control_tab->hide();
	m_control_tab->set_icon(Graphic(":/svgs/mll_icon.svg", QSize(20, 6)));
	m_control_tab->set_name("Tabs");
}

void TabBar::add_tab(const Graphic& icon, const QString& text)
{
	_add_tab(new Tab(icon, text));
}

void TabBar::add_tab(const QString& text)
{
	_add_tab(new Tab(text));
}

int TabBar::current_index() const
{
	return m_current_index;
}

void TabBar::set_current_index(int index)
{
	if (index != m_current_index)
	{
		int old_index = m_current_index;
		m_current_index = index;
		emit index_changed(old_index, index);

		if (old_index != -1)
			m_tabs[old_index]->fill()->set_state("Inactive");

		m_tabs[index]->fill()->set_state("Active");
	}
}

QList<Tab*> TabBar::tabs() const
{
	return m_tabs;
}

void TabBar::init_attributes()
{
	m_fill->set_disabled();
}

void TabBar::init_layout()
{
	m_tab_layout->setContentsMargins(0, 0, 0, 0);
	m_tab_layout->setSpacing(0);

	setLayout(m_tab_layout);
}

void TabBar::_add_tab(Tab* tab)
{
	tab->entangle_with(m_control_tab);

	m_tabs.append(tab);
	m_tab_layout->addWidget(tab);

	connect(tab, &Tab::clicked, [this, tab]
		{ set_current_index(m_tabs.indexOf(tab)); });

	connect(tab, &Tab::closed, [this, tab]
		{
			int remove_index = m_tabs.indexOf(tab);

			if (m_current_index == remove_index)
			{
				if (remove_index < m_tabs.count() - 1)
					set_current_index(remove_index + 1);
				else
					set_current_index(remove_index - 1);
			}

			m_tabs.takeAt(remove_index)->deleteLater();

			if (m_current_index > remove_index)
				m_current_index--;

			emit tab_closed(remove_index);
		});
}
