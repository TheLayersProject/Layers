#ifndef LTHEMECOMBOBOXITEMMODEL_H
#define LTHEMECOMBOBOXITEMMODEL_H

#include <QAbstractListModel>

#include <LayersCore/layers_global.h>
#include "layerswidgets_exports.h"

#include <LayersCore/ltheme.h>

LAYERS_NAMESPACE_BEGIN
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
LAYERS_NAMESPACE_END

#endif // LTHEMECOMBOBOXITEMMODEL_H  
