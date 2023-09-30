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

    virtual int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    virtual QVariant data(const QModelIndex& index, int role) const override;

    virtual QModelIndex index(int row, int column,
        const QModelIndex& parent = QModelIndex()) const override;

    virtual QModelIndex parent(const QModelIndex& index) const override;

    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    void set_theme(LTheme* theme);

private:
    LThemeItem* get_item(const QModelIndex& index) const;

    LTheme* m_theme{ nullptr };
};
LAYERS_NAMESPACE_END

#endif // LTHEMEMODEL_H
