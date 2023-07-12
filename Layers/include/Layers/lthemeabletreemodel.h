#ifndef LTHEMEABLETREEMODEL_H
#define LTHEMEABLETREEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeabletreeitem.h"

LAYERS_NAMESPACE_BEGIN
class LThemeableTreeItem;

class LThemeableTreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    LThemeableTreeModel(LThemeable* root_themeable, QObject* parent = nullptr);

    QVariant data(const QModelIndex& index, int role) const override;

    QModelIndex index(int row, int column,
        const QModelIndex& parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

private:
    LThemeableTreeItem* init_item(
        LThemeable* themeable, LThemeableTreeItem* parent = nullptr);

    LThemeableTreeItem* get_item(const QModelIndex& index) const;

    LThemeableTreeItem* m_root_item;
};
LAYERS_NAMESPACE_END

#endif // LTHEMEABLETREEMODEL_H
