#ifndef ATTRIBUTESET_H
#define ATTRIBUTESET_H

#include <QDataStream>

#include "Attributes.h"

namespace Layers
{
	class AttributeSet
	{
	public:
		void add_attribute(StatelessAttribute attribute);

		void add_attribute(StatefulAttribute attribute);

		Attribute* attribute(const QString& attribute_name);

		QVariant* attribute_value(const QString& attribute_name);

		bool contains(const QString& attribute_name);

		bool contains_stateful_attribute(const QString& attribute_name);

		bool contains_stateless_attribute(const QString& attribute_name);

		void copy_values_from(AttributeSet& other_attribute_set);

		void remove_attribute(const QString& attribute_name);

		void set_state(const QString& state);

		StatefulAttribute* stateful_attribute(const QString& attribute_name);

		QMap<QString, StatefulAttribute>& stateful_attributes();

		StatelessAttribute* stateless_attribute(const QString& attribute_name);

		QMap<QString, StatelessAttribute>& stateless_attributes();

		QList<QString> states() const;

		friend QDataStream& operator <<(QDataStream& stream, const AttributeSet& as)
		{
			stream << as.m_stateful_attributes;
			stream << as.m_stateless_attributes;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, AttributeSet& as)
		{
			stream >> as.m_stateful_attributes;
			stream >> as.m_stateless_attributes;
			return stream;
		}

	private:
		QMap<QString, StatefulAttribute> m_stateful_attributes{ QMap<QString, StatefulAttribute>() };
		QMap<QString, StatelessAttribute> m_stateless_attributes{ QMap<QString, StatelessAttribute>() };
	};
}

#endif // ATTRIBUTESET_H
