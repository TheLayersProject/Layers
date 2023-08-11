#include <Layers/lthememodel.h>

using Layers::LThemeItem;
using Layers::LThemeModel;

LThemeModel::LThemeModel(QObject* parent) :
	QAbstractItemModel(parent)
{
}

QVariant LThemeModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();

	else if (role == Qt::DisplayRole)
		return get_item(index)->name();

	else if (role == Qt::UserRole)
		return QVariant::fromValue(get_item(index));

	return QVariant();
}

QModelIndex LThemeModel::index(
	int row, int column, const QModelIndex& parent) const
{
	if (parent.isValid() && parent.column() != 0)
		return QModelIndex();

	LThemeItem* parent_item = get_item(parent);
	if (!parent_item)
		return QModelIndex();

	LThemeItem* child_item = parent_item->child(row);
	if (child_item)
		return createIndex(row, column, child_item);

	return QModelIndex();
}

QModelIndex LThemeModel::parent(const QModelIndex& index) const
{
	if (!index.isValid())
		return QModelIndex();

	LThemeItem* child_item = get_item(index);
	LThemeItem* parent_item = child_item ? child_item->parent() : nullptr;

	if (parent_item == m_theme->root_item() || !parent_item)
		return QModelIndex();

	return createIndex(parent_item->child_number(), 0, parent_item);
}

int LThemeModel::rowCount(const QModelIndex& parent) const
{
	if (parent.isValid() && parent.column() > 0)
		return 0;

	const LThemeItem* parent_item = get_item(parent);

	return parent_item ?
		parent_item->child_count() : 0;
}

int LThemeModel::columnCount(const QModelIndex& parent) const
{
	Q_UNUSED(parent);
	return 1;
}

void LThemeModel::set_theme(LTheme* theme)
{
	beginResetModel();
	m_theme = theme;
	endResetModel();
}

LThemeItem* LThemeModel::get_item(const QModelIndex& index) const
{
	if (index.isValid())
		if (LThemeItem* item =
			static_cast<LThemeItem*>(index.internalPointer()))
		{
			return item;
		}

	if (m_theme)
		return m_theme->root_item();

	return nullptr;
}
