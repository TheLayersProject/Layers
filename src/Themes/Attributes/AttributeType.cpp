#include "../../../include/Attribute.h"

using Layers::AttributeType;

AttributeType::AttributeType(const QString& name, bool disabled) :
	m_name{ name }, m_disabled{ disabled } {}

QString AttributeType::capitalized_name()
{
	QString name = m_name;

	QStringList name_parts = name.split('_', Qt::SkipEmptyParts);
	for (int i = 0; i < name_parts.size(); i++)
		name_parts[i].replace(0, 1, name_parts[i][0].toUpper());

	return name_parts.join(" ");
}

bool AttributeType::disabled() const
{
	return m_disabled;
}

QString AttributeType::name() { return m_name; }

void AttributeType::set_disabled(bool disabled)
{
	m_disabled = disabled;

	emit value_changed();
}
