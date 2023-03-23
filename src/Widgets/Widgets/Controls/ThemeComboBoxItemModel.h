#ifndef THEMECOMBOBOXITEMMODEL_H
#define THEMECOMBOBOXITEMMODEL_H

#include <QAbstractListModel>

#include "Theme.h"

namespace Layers
{
	class ThemeComboBoxItemModel : public QAbstractListModel
	{
		Q_OBJECT

	public:
		ThemeComboBoxItemModel(QObject* parent = nullptr);

		void append(Theme* value);
		//void append(const ThemeLineageData& value);

		void clear();

		virtual QVariant data(const QModelIndex& index, int role) const override;

		virtual int rowCount(const QModelIndex& index) const override;

	private:
		QList<Theme*> m_data{ QList<Theme*>() };
	};
}

#endif // THEMECOMBOBOXITEMMODEL_H  
