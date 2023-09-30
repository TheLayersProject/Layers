#ifndef LTHEMECOMBOBOXITEMMODEL_H
#define LTHEMECOMBOBOXITEMMODEL_H

#include <QAbstractListModel>

#include "layers_global.h"
#include "layers_exports.h"

#include "ltheme.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeComboBoxItemModel : public QAbstractListModel
{
	Q_OBJECT

public:
	LThemeComboBoxItemModel(QObject* parent = nullptr);

	void append(LTheme* theme);

	void clear();

	virtual QVariant data(const QModelIndex& index, int role) const override;

	virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;

private:
	QList<LTheme*> m_themes{ QList<LTheme*>() };
};
LAYERS_NAMESPACE_END

#endif // LTHEMECOMBOBOXITEMMODEL_H  
