#ifndef LATTRIBUTEMAPITEM_H
#define LATTRIBUTEMAPITEM_H

#include <QVariant>
#include <QList>

#include "layers_global.h"
#include "layers_exports.h"

#include "lattribute.h"

LAYERS_NAMESPACE_BEGIN
class LAttributeMapItem : public QObject
{
    Q_OBJECT

public:
    LAttributeMapItem(LAttribute* attribute,
        LAttributeMapItem* parent = nullptr);

    void append_child(LAttributeMapItem* child);

    LAttribute* attribute() const;

    LAttributeMapItem* child(int number);

    int child_count() const;

    QMap<QString, LAttributeMapItem*>& child_attribute_items();

    LAttributeMapItem* parent();

    int index() const;

private:
    QMap<QString, LAttributeMapItem*> m_child_attr_items;
    LAttributeMapItem* m_parent{ nullptr };
    LAttribute* m_attribute{ nullptr };
};
LAYERS_NAMESPACE_END

#endif // LATTRIBUTEMAPITEM_H
