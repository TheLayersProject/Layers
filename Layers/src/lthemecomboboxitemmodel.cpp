#include <Layers/lthemecomboboxitemmodel.h>

#include <Layers/lapplication.h>

using Layers::LTheme;
using Layers::LThemeComboBoxItemModel;

LThemeComboBoxItemModel::LThemeComboBoxItemModel(QObject* parent) :
	QAbstractListModel(parent) {}

void LThemeComboBoxItemModel::append(LTheme* theme)
{
	beginInsertRows({}, m_themes.count(), m_themes.count());
	m_themes.append(theme);
	endInsertRows();
}

void LThemeComboBoxItemModel::clear()
{
	if (!m_themes.isEmpty())
	{
		beginResetModel();
		m_themes.clear();
		endResetModel();
	}
}

QVariant LThemeComboBoxItemModel::data(const QModelIndex& index, int role) const
{
	if (!index.isValid())
		return QVariant();

	else if (role == Qt::DisplayRole)
		return m_themes[index.row()]->name();

	else if (role == Qt::UserRole)
		return QVariant::fromValue(m_themes[index.row()]);
	
	return QVariant();
}

int LThemeComboBoxItemModel::rowCount(const QModelIndex& parent) const
{
	if (!parent.isValid())
		return m_themes.count();
	else
		return 0;
}
