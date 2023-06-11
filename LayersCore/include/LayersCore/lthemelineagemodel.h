#ifndef LTHEMELINEAGEMODEL_H
#define LTHEMELINEAGEMODEL_H

#include <QAbstractTableModel>

#include "layerscoreexports.h"

#include "ltheme.h"

namespace Layers
{
	class LAYERS_CORE_EXPORT LThemeLineageModel : public QAbstractTableModel
	{
		Q_OBJECT

	public:
		LThemeLineageModel(QObject* parent = nullptr);

		void append(const LThemeLineageData& lineage_data);

		void clear();

		virtual int columnCount(const QModelIndex& index) const override;

		virtual QVariant data(
			const QModelIndex& index, int role) const override;

		virtual QVariant headerData(
			int section, Qt::Orientation orientation, int role) const override;

		virtual int rowCount(const QModelIndex& index) const override;

	private:
		QList<LThemeLineageData> m_lineage_data{ QList<LThemeLineageData>() };
	};
}

#endif // LTHEMELINEAGEMODEL_H  
