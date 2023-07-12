#ifndef LTHEMEABLETREEITEM_H
#define LTHEMEABLETREEITEM_H

#include <QVariant>
#include <QList>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LThemeableTreeItem
{
public:
    LThemeableTreeItem(
        LThemeable* themeable, LThemeableTreeItem* parent = nullptr);

    void append_child(LThemeableTreeItem* child);

    LThemeableTreeItem* child(int number);

    int child_count() const;

    QVariant data() const;

    LThemeableTreeItem* parent();

    int child_number() const;

private:
    QList<LThemeableTreeItem*> m_child_items;
    LThemeableTreeItem* m_parent{ nullptr };
    LThemeable* m_themeable;
};
LAYERS_NAMESPACE_END

#endif // LTHEMEABLETREEITEM_H
