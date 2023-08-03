#ifndef LTHEMEITEM_H
#define LTHEMEITEM_H

#include <QVariant>
#include <QList>

#include "layers_global.h"
#include "layers_exports.h"

#include "lattribute.h"

LAYERS_NAMESPACE_BEGIN
class LThemeItem : public QObject
{
    Q_OBJECT

public:
    LThemeItem(
        const QString& name,
        const LAttributeMap& attributes,
        bool is_overridable,
        const QString& file_name,
        LThemeItem* parent = nullptr);

    void append_child(LThemeItem* child);

    QStringList attribute_group_names();

    LAttributeMap& attributes();

    LThemeItem* child(int number);

    int child_count() const;

    QMap<QString, LThemeItem*>& child_items();

    QString file_name() const;

    LThemeItem* find_item(QStringList name_list);

    bool is_overridable() const;

    QString name() const;

    LThemeItem* parent();

    QString path();

    int child_number() const;

    QJsonObject to_json_object();

private:
    QMap<QString, LThemeItem*> m_child_items;
    LThemeItem* m_parent{ nullptr };
    QString m_name;
    QString m_file_name;
    LAttributeMap m_attributes;
    bool m_is_overridable{ false };
};
LAYERS_NAMESPACE_END

#endif // LTHEMEITEM_H
