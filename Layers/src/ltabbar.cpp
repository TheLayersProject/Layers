/*
 * Copyright (C) 2023 The Layers Project
 *
 * This file is part of Layers.
 *
 * Layers is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Layers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Layers. If not, see <https://www.gnu.org/licenses/>.
 */

#include <Layers/ltabbar.h>

#include <QEvent>
#include <QResizeEvent>

using Layers::LTab;
using Layers::LTabBar;

LTabBar::LTabBar(QWidget* parent) : LWidget(parent)
{
	init_layout();
}

void LTabBar::add_tab(const LGraphic& icon, const QString& text)
{
	_add_tab(new LTab(icon, text));
}

void LTabBar::add_tab(const QString& text)
{
	_add_tab(new LTab(text));
}

int LTabBar::current_index() const
{
	return m_current_index;
}

void LTabBar::set_current_index(int index)
{
	if (index != m_current_index)
	{
		int old_index = m_current_index;
		m_current_index = index;
		emit index_changed(old_index, index);

		if (old_index != -1)
			m_tabs[old_index]->status_states()->set_state("Inactive");

		if (index != -1)
			m_tabs[index]->status_states()->set_state("Active");
	}
}

QList<LTab*> LTabBar::tabs() const
{
	return m_tabs;
}

void LTabBar::_add_tab(LTab* tab)
{
	tab->setObjectName("Tabs");

	if (current_theme_item())
		tab->apply_theme_item(
			current_theme_item()->find_item(tab->objectName().toStdString()));

	m_tabs.append(tab);
	m_tab_layout->addWidget(tab);

	connect(tab, &LTab::clicked, [this, tab]
		{ set_current_index(m_tabs.indexOf(tab)); });

	connect(tab, &LTab::closed, [this, tab]
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


void LTabBar::init_layout()
{
	m_tab_layout->setContentsMargins(0, 0, 0, 0);
	m_tab_layout->setSpacing(0);

	setLayout(m_tab_layout);
}
