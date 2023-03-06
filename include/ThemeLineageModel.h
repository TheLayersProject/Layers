#ifndef THEMELINEAGEMODEL_H
#define THEMELINEAGEMODEL_H

#include <QAbstractTableModel>

#include "Theme.h"

namespace Layers
{
	class ThemeLineageModel : public QAbstractTableModel
	{
		Q_OBJECT

	public:
		ThemeLineageModel(QObject* parent = nullptr);

		void append(const ThemeLineageData& lineage_data);

		void clear();

		virtual int columnCount(const QModelIndex& index) const override;

		virtual QVariant data(const QModelIndex& index, int role) const override;

		virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

		virtual int rowCount(const QModelIndex& index) const override;

	private:
		QList<ThemeLineageData> m_lineage_data{ QList<ThemeLineageData>() };

		//QList<Theme*> m_themes{ QList<Theme*>() };
	};
}

#endif // THEMELINEAGEMODEL_H  
