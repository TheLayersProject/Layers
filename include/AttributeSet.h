#ifndef ATTRIBUTESET_H
#define ATTRIBUTESET_H

#include <QDataStream>

#include "Attribute.h"

namespace Layers
{
	class AttributeSet
	{
	public:
		void add_attribute(Attribute* attribute);

		Attribute* attribute(const QString& attribute_name);

		QVariant* attribute_value(const QString& attribute_name);

		QMap<QString, Attribute*>& attributes();

		bool contains(const QString& attribute_name);

		void copy_values_from(AttributeSet& other_attribute_set);

		void remove_attribute(const QString& attribute_name);

		bool replace_with_proxy(const QString& attribute_name, Attribute* proxy_attribute);

		void replace_all_with(AttributeSet& other_attribute_set);

		void set_state(const QString& state);

		QList<QString> states() const;

		friend QDataStream& operator <<(QDataStream& stream, const AttributeSet& as)
		{
			stream << as.m_attributes.count();

			for (Attribute* attr : as.m_attributes)
				stream << *attr;

			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, AttributeSet& as)
		{
			qsizetype attr_count;

			stream >> attr_count;

			for (int i = 0; i < attr_count; i++)
			{
				Attribute* attr = new Attribute("");

				stream >> *attr;

				as.m_attributes.insert(attr->name(), attr);
			}

			return stream;
		}

	private:
		QMap<QString, Attribute*> m_attributes{ QMap<QString, Attribute*>() };
	};
}

#endif // ATTRIBUTESET_H
