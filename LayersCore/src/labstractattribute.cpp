#include <LayersCore/labstractattribute.h>

using Layers::LAbstractAttribute;

LAbstractAttribute::LAbstractAttribute(const QString& name, bool disabled) :
	m_name{ name }, m_disabled{ disabled } {}

QString LAbstractAttribute::capitalized_name()
{
	QString name = m_name;

	QStringList name_parts = name.split('_', Qt::SkipEmptyParts);
	for (int i = 0; i < name_parts.size(); i++)
		name_parts[i].replace(0, 1, name_parts[i][0].toUpper());

	return name_parts.join(" ");
}

bool LAbstractAttribute::disabled() const
{
	return m_disabled;
}

QString LAbstractAttribute::name()
{
	return m_name;
}

void LAbstractAttribute::set_disabled(bool disabled)
{
	m_disabled = disabled;

	emit changed();
}
