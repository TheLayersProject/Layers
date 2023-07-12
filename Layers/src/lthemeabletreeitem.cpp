#include <Layers/lthemeabletreeitem.h>

using Layers::LThemeableTreeItem;

LThemeableTreeItem::LThemeableTreeItem(
	LThemeable* themeable, LThemeableTreeItem* parent) :
	m_themeable{ themeable }, m_parent{ parent } {}

void LThemeableTreeItem::append_child(LThemeableTreeItem* child)
{
	m_child_items.append(child);
}

LThemeableTreeItem* LThemeableTreeItem::child(int number)
{
	if (number < 0 || number >= m_child_items.size())
		return nullptr;
	return m_child_items.at(number);
}

int LThemeableTreeItem::child_count() const
{
	return m_child_items.count();
}

QVariant LThemeableTreeItem::data() const
{
	return QVariant::fromValue(m_themeable);
}

LThemeableTreeItem* LThemeableTreeItem::parent()
{
	return m_parent;
}

int LThemeableTreeItem::child_number() const
{
	if (m_parent)
		return m_parent->m_child_items.indexOf(
			const_cast<LThemeableTreeItem*>(this));

	return 0;
}
