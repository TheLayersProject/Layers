#include <Layers/lthemeabletreemodel.h>

using Layers::LThemeableTreeItem;
using Layers::LThemeableTreeModel;

LThemeableTreeModel::LThemeableTreeModel(
	LThemeable* root_themeable, QObject* parent
) : QAbstractItemModel(parent)
{
	m_root_item = new LThemeableTreeItem(nullptr);

	m_root_item->append_child(init_item(root_themeable, m_root_item));
}

QVariant LThemeableTreeModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (role == Qt::DisplayRole)
		return *get_item(index)->data().value<LThemeable*>()->name();

	if (role == Qt::EditRole)
		return get_item(index)->data();

	return QVariant();
}

QModelIndex LThemeableTreeModel::index(
	int row, int column, const QModelIndex& parent) const
{
	if (parent.isValid() && parent.column() != 0)
		return QModelIndex();

	LThemeableTreeItem* parent_item = get_item(parent);
	if (!parent_item)
		return QModelIndex();

	LThemeableTreeItem* child_item = parent_item->child(row);
	if (child_item)
		return createIndex(row, column, child_item);

	return QModelIndex();
}

QModelIndex LThemeableTreeModel::parent(const QModelIndex& index) const
{
	if (!index.isValid())
		return QModelIndex();

	LThemeableTreeItem* child_item = get_item(index);
	LThemeableTreeItem* parent_item = child_item ? child_item->parent() : nullptr;

	if (parent_item == m_root_item || !parent_item)
		return QModelIndex();

	return createIndex(parent_item->child_number(), 0, parent_item);
}

int LThemeableTreeModel::rowCount(const QModelIndex& parent) const
{
	if (parent.isValid() && parent.column() > 0)
		return 0;

	const LThemeableTreeItem* parent_item = get_item(parent);

	return parent_item ? parent_item->child_count() : 0;
}

int LThemeableTreeModel::columnCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return 1;
}

LThemeableTreeItem* LThemeableTreeModel::init_item(
	LThemeable* themeable, LThemeableTreeItem* parent)
{
	LThemeableTreeItem* item = new LThemeableTreeItem(themeable, parent);

	for (LThemeable* child_t : themeable->child_themeables())
		if (child_t->name())
			item->append_child(init_item(child_t, item));

	return item;
}

LThemeableTreeItem* LThemeableTreeModel::get_item(const QModelIndex& index) const
{
	if (index.isValid())
		if (LThemeableTreeItem* item =
			static_cast<LThemeableTreeItem*>(index.internalPointer()))
		{
			return item;
		}

	return m_root_item;
}
