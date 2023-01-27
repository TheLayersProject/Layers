#include "../../../include/Entity.h"

using Layers::Entity;

Entity::Entity(const QString& name, bool disabled) :
	m_name{ name }, m_disabled{ disabled } {}

QString Entity::capitalized_name()
{
	QString name = m_name;

	QStringList name_parts = name.split('_', Qt::SkipEmptyParts);
	for (int i = 0; i < name_parts.size(); i++)
		name_parts[i].replace(0, 1, name_parts[i][0].toUpper());

	return name_parts.join(" ");
}

bool Entity::disabled() const
{
	return m_disabled;
}

QString Entity::name() { return m_name; }

void Entity::set_disabled(bool disabled)
{
	m_disabled = disabled;

	emit value_changed();
}
