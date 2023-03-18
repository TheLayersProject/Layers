#include "ThemeComboBoxItemModel.h"

#include "Layers.h"

using Layers::ThemeComboBoxItemModel;

ThemeComboBoxItemModel::ThemeComboBoxItemModel(QObject* parent) :
	QAbstractListModel(parent) {}

void ThemeComboBoxItemModel::append(Theme* value)
{
	beginInsertRows({}, m_data.count(), m_data.count());
	m_data.append(value);
	endInsertRows();
}

void ThemeComboBoxItemModel::clear()
{
	if (!m_data.isEmpty())
	{
		beginResetModel();
		m_data.clear();
		endResetModel();
	}
}

QVariant ThemeComboBoxItemModel::data(const QModelIndex& index, int role) const
{
	Theme* index_theme = m_data[index.row()];

	if (role == Qt::DisplayRole)
		return index_theme->name();
	else if (role == Qt::UserRole)
	{
		if (index_theme->uuid())
			return index_theme->name() + "_" +
				index_theme->uuid()->toString(QUuid::WithoutBraces);
		else
			return index_theme->name();
	}
	else if (role == Layers::UuidIfExists)
	{
		if (index_theme->uuid())
			return index_theme->uuid()->toString(QUuid::WithoutBraces);
		else
			return QString();
	}
	else if (role == Layers::AppImplementationAvailable)
		return index_theme->has_app_implementation();
	else
		return {};
}

int ThemeComboBoxItemModel::rowCount(const QModelIndex& index) const
{
	if (!index.isValid())
		return m_data.count();
	else
		return 0;
}
