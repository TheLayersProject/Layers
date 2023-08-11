#ifndef LATTRIBUTEMAPMODEL_H
#define LATTRIBUTEMAPMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include "layers_global.h"
#include "layers_exports.h"

#include "lattributemapitem.h"

LAYERS_NAMESPACE_BEGIN
class LAttributeMapModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    LAttributeMapModel(QObject* parent = nullptr);

    ~LAttributeMapModel();

    QVariant data(const QModelIndex& index, int role) const override;

    QModelIndex index(int row, int column,
        const QModelIndex& parent = QModelIndex()) const override;

    QModelIndex parent(const QModelIndex& index) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    void init_root_item(
        LAttributeMap attributes, const QStringList& filter_paths);

private:
    LAttributeMapItem* init_item(
        LAttribute* attribute, const QStringList& filter_paths,
        LAttributeMapItem* parent = nullptr);

    LAttributeMapItem* get_item(const QModelIndex& index) const;

    LAttributeMapItem* m_root_item{ nullptr };
};
LAYERS_NAMESPACE_END

#endif // LATTRIBUTEMAPMODEL_H
