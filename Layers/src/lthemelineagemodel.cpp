#include <Layers/lthemelineagemodel.h>

using Layers::LThemeLineageModel;

LThemeLineageModel::LThemeLineageModel(QObject* parent) :
	QAbstractTableModel(parent) {}

void LThemeLineageModel::append(const LThemeLineageData& lineage_data)
{
	beginInsertRows({}, m_lineage_data.count(), m_lineage_data.count());
	m_lineage_data.append(lineage_data);
	endInsertRows();
}

void LThemeLineageModel::clear()
{
	if (!m_lineage_data.isEmpty())
	{
		beginResetModel();
		m_lineage_data.clear();
		endResetModel();
	}
}

int LThemeLineageModel::columnCount(const QModelIndex& index) const
{
	return 2;
}

QVariant LThemeLineageModel::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		const QString& theme_name = m_lineage_data[index.row()].name;
		const QString& theme_uuid = m_lineage_data[index.row()].uuid;

		switch (index.column()) {
		case 0:
			if (!theme_uuid.isEmpty())
				return theme_name + " (" + theme_uuid + ")";
			else
				return theme_name;
		default:
			return {};
		}
	}
	else if (role == Qt::DecorationRole)
	{
		const bool& theme_has_app_implementation_available =
			m_lineage_data[index.row()].has_app_implementation_available;

		switch (index.column()) {
		case 1:
			return theme_has_app_implementation_available;
		default:
			return {};
		}
	}
	else
		return {};
}

QVariant LThemeLineageModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation != Qt::Horizontal || role != Qt::DisplayRole)
		return {};

	switch (section) {
	case 0:
		return "Theme";
	case 1:
		return "Compatible";
	default:
		return {};
	}
}

int LThemeLineageModel::rowCount(const QModelIndex& index) const
{
	if (!index.isValid())
		return m_lineage_data.count();
	else
		return 0;
}
