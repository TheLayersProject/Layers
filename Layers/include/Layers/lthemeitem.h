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

	QStringList attribute_group_names() const;

	LAttributeMap attributes(const QString& type_name = "");

	LThemeItem* child(int index) const;

	int child_count() const;

	QMap<QString, LThemeItem*>& children();

	LThemeItem* find_item(const QString& path);

	LThemeItem* find_item(QStringList name_list);

	int index() const;

	bool is_overridable() const;

	QString name() const;

	LThemeItem* parent() const;

	QString path() const;

	QJsonObject to_json_object() const;

private:
	LThemeItem* m_parent{ nullptr };
	QMap<QString, LThemeItem*> m_children;

	QString m_name;
	LAttributeMap m_attributes;
	QString m_file_name;
	bool m_is_overridable{ false };
};
LAYERS_NAMESPACE_END

#endif // LTHEMEITEM_H
