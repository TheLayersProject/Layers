#include <LayersWidgets/lthemecomboboxitemmodel.h>

#include <LayersWidgets/lapplication.h>
#include <LayersWidgets/lenums.h>

using Layers::LThemeComboBoxItemModel;

LThemeComboBoxItemModel::LThemeComboBoxItemModel(QObject* parent) :
	QAbstractListModel(parent) {}

void LThemeComboBoxItemModel::append(LTheme* value)
{
	beginInsertRows({}, m_data.count(), m_data.count());
	m_data.append(value);
	endInsertRows();
}

void LThemeComboBoxItemModel::clear()
{
	if (!m_data.isEmpty())
	{
		beginResetModel();
		m_data.clear();
		endResetModel();
	}
}

QVariant LThemeComboBoxItemModel::data(const QModelIndex& index, int role) const
{
	LTheme* index_theme = m_data[index.row()];

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
		return index_theme->has_app_implementation(layersApp->app_identifier());
	else
		return {};
}

int LThemeComboBoxItemModel::rowCount(const QModelIndex& index) const
{
	if (!index.isValid())
		return m_data.count();
	else
		return 0;
}
