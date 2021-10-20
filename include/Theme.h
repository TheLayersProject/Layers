#ifndef THEME_H
#define THEME_H

#include <QHash>
#include <QString>

#include "AttributeSet.h"

namespace Layers
{
	class StatefulAttribute;
	class StatelessAttribute;
	class Themeable;

	/*!
		Provides structure for Layers themes.

		Layers themes store sets of attributes associated with their themeable tags. When a theme is applied,
		themeables retrieve their attribute sets from the theme by passing along their tags.
	*/
	class Theme
	{
	public:
		Theme();
		Theme(const QString& name, bool is_custom = true);

		void add_attribute_set(const QString& themeable_tag, AttributeSet attribute_set);

		void add_stateful_attribute(
			const QString& themeable_tag,
			const QString& attribute_name,
			QMap<QString, QVariant> state_value_map);

		/*!
			Add an attribute to the theme.

			This implementation of this function adds an attribute with a single value.

			@param themeable_tag of themeable associated with attribute
		*/
		void add_stateless_attribute(
			const QString& themeable_tag,
			const QString& attribute_name,
			QVariant value);

		// Recommend calling contains_attributes_for_tag() before calling this since this function
		// does not check if it contains an attribute set for the given themeable tag.
		AttributeSet& attribute_set(const QString& themeable_tag);

		QHash<QString, AttributeSet>& attribute_sets();

		void consume(Theme&& theme);

		bool contains_attributes_for_tag(const QString& themeable_tag);

		// Only needs one version since attribute names should not exist in both stateless and stateful lists
		bool contains_attribute(const QString& themeable_tag, const QString& attribute_name);

		void copy_attribute_sets_from(Theme& theme);

		void copy_attribute_values_of(Themeable* themeable);

		bool is_custom();

		QString& name();

		void set_name(const QString& new_name);

		StatefulAttribute* stateful_attribute(const QString& themeable_tag, const QString& attribute_name);

		StatelessAttribute* stateless_attribute(const QString& themeable_tag, const QString& attribute_name);

		friend QDataStream& operator <<(QDataStream& stream, const Theme& t)
		{
			stream << t.m_attribute_sets;
			stream << t.m_is_custom;
			stream << t.m_name;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Theme& t)
		{
			stream >> t.m_attribute_sets;
			stream >> t.m_is_custom;
			stream >> t.m_name;
			return stream;
		}

	private:
		QHash<QString, AttributeSet> m_attribute_sets{ QHash<QString, AttributeSet>() };

		bool m_is_custom{ true };

		QString m_name{ "" };
	};
}

#endif // THEME_H
