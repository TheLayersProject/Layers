#ifndef LTHEMEMODEL_H
#define LTHEMEMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include "layers_global.h"
#include "layers_exports.h"

#include "ltheme.h"

LAYERS_NAMESPACE_BEGIN
class LThemeItem;

class LThemeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    LThemeModel(QObject* parent = nullptr);

    QVariant data(const QModelIndex& index, int role) const override;

    QModelIndex index(int row, int column,
        const QModelIndex& parent = QModelIndex()) const override;

    QModelIndex parent(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    void set_theme(LTheme* theme);

private:
    //LThemeItem* init_item(
    //    LThemeable* themeable, LThemeItem* parent = nullptr);

    LThemeItem* get_item(const QModelIndex& index) const;

    LTheme* m_theme{ nullptr };
};
LAYERS_NAMESPACE_END

#endif // LTHEMEMODEL_H
