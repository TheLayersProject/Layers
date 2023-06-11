#ifndef LTHEMECOMBOBOXITEMMODEL_H
#define LTHEMECOMBOBOXITEMMODEL_H

#include <QAbstractListModel>

#include "layerswidgetsexports.h"

#include <LayersCore/ltheme.h>

namespace Layers
{
	class LAYERS_WIDGETS_EXPORT LThemeComboBoxItemModel : public QAbstractListModel
	{
		Q_OBJECT

	public:
		LThemeComboBoxItemModel(QObject* parent = nullptr);

		void append(LTheme* value);
		//void append(const ThemeLineageData& value);

		void clear();

		virtual QVariant data(const QModelIndex& index, int role) const override;

		virtual int rowCount(const QModelIndex& index) const override;

	private:
		QList<LTheme*> m_data{ QList<LTheme*>() };
	};
}

#endif // LTHEMECOMBOBOXITEMMODEL_H  
