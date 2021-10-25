#ifndef ATTRIBUTESET_H
#define ATTRIBUTESET_H

#include <QDataStream>

#include "Attributes.h"

namespace Layers
{
	class AttributeSet
	{
	public:
		void add_stateless_attribute(StatelessAttribute* attribute);

		void add_stateful_attribute(StatefulAttribute* attribute);

		Attribute* attribute(const QString& attribute_name);

		QVariant* attribute_value(const QString& attribute_name);

		bool contains(const QString& attribute_name);

		bool contains_stateful_attribute(const QString& attribute_name);

		bool contains_stateless_attribute(const QString& attribute_name);

		void copy_values_from(AttributeSet& other_attribute_set);

		void remove_attribute(const QString& attribute_name);

		bool replace_with_proxy(const QString& attribute_name, Attribute* proxy_attribute);

		void replace_all_with(AttributeSet& other_attribute_set);

		void set_state(const QString& state);

		StatefulAttribute* stateful_attribute(const QString& attribute_name);

		QMap<QString, StatefulAttribute*>& stateful_attributes();

		StatelessAttribute* stateless_attribute(const QString& attribute_name);

		QMap<QString, StatelessAttribute*>& stateless_attributes();

		QList<QString> states() const;

		friend QDataStream& operator <<(QDataStream& stream, const AttributeSet& as)
		{
			stream << as.m_stateful_attributes.count();
			stream << as.m_stateless_attributes.count();

			for (StatefulAttribute* stateful_attr : as.m_stateful_attributes)
				stream << *stateful_attr;
			
			for (StatelessAttribute* stateless_attr : as.m_stateless_attributes)
				stream << *stateless_attr;

			//stream << as.m_stateful_attributes;
			//stream << as.m_stateless_attributes;

			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, AttributeSet& as)
		{
			qsizetype stateful_attr_count;
			qsizetype stateless_attr_count;

			stream >> stateful_attr_count;
			stream >> stateless_attr_count;

			for (int i = 0; i < stateful_attr_count; i++)
			{
				StatefulAttribute* stateful_attr = new StatefulAttribute;

				stream >> *stateful_attr;

				as.m_stateful_attributes.insert(stateful_attr->name(), stateful_attr);
			}

			for (int i = 0; i < stateless_attr_count; i++)
			{
				StatelessAttribute* stateless_attr = new StatelessAttribute;

				stream >> *stateless_attr;

				as.m_stateless_attributes.insert(stateless_attr->name(), stateless_attr);
			}

			//stream >> as.m_stateful_attributes;
			//stream >> as.m_stateless_attributes;

			return stream;
		}

	private:
		QMap<QString, StatefulAttribute*> m_stateful_attributes{ QMap<QString, StatefulAttribute*>() };
		QMap<QString, StatelessAttribute*> m_stateless_attributes{ QMap<QString, StatelessAttribute*>() };
	};
}

#endif // ATTRIBUTESET_H
