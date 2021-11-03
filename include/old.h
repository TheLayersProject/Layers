#ifndef OLD_H
#define OLD_H

#include <QDataStream>
#include <QString>
#include <QVariant>

namespace Layers { class Themeable; }

// 2.0.0a Classes
namespace Layers
{
	class Attribute_2_0_0_a
	{
	public:
		friend QDataStream& operator >>(QDataStream& stream, Attribute_2_0_0_a& a)
		{
			stream >> a.m_name;
			stream >> a.m_state;
			stream >> a.m_values;
			return stream;
		}

		bool m_is_stateful{ false };

		QString m_name;
		QString m_state;

		QMap<QString, QVariant> m_values{ QMap<QString, QVariant>() };
	};

	class Theme_2_0_0_a
	{
	public:
		friend QDataStream& operator >>(QDataStream& stream, Theme_2_0_0_a& t)
		{
			stream >> t.name;
			stream >> t.built_in;
			stream >> t.m_data;
			return stream;
		}

		bool built_in{ false };

		QHash<QString, QMap<QString, Attribute_2_0_0_a>> m_data{ QHash<QString, QMap<QString, Attribute_2_0_0_a>>() };

		QString name;
	};
}

// 2.1.0a Classes
namespace Layers
{
	class Attribute_2_1_0_a
	{
	public:
		Attribute_2_1_0_a(const QString& name);

		QString& name();

	protected:
		QString m_name{ "" };

		Themeable* m_parent_themeable{ nullptr };
	};

	class Stateless_Attribute_2_1_0_a : public Attribute_2_1_0_a
	{
	public:
		Stateless_Attribute_2_1_0_a();
		Stateless_Attribute_2_1_0_a(const QString& name, QVariant value);

		QVariant& value();

		friend QDataStream& operator <<(QDataStream& stream, const Stateless_Attribute_2_1_0_a& a)
		{
			stream << a.m_name;
			stream << a.m_value;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Stateless_Attribute_2_1_0_a& a)
		{
			stream >> a.m_name;
			stream >> a.m_value;
			return stream;
		}

	private:
		QVariant m_value{ QVariant() };
	};

	class Stateful_Attribute_2_1_0_a : public Attribute_2_1_0_a
	{
	public:
		Stateful_Attribute_2_1_0_a();
		Stateful_Attribute_2_1_0_a(const QString& name, QMap<QString, QVariant> state_value_map);

		QMap<QString, QVariant>& values();

		friend QDataStream& operator <<(QDataStream& stream, const Stateful_Attribute_2_1_0_a& a)
		{
			stream << a.m_name;
			stream << a.m_state;
			stream << a.m_values;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Stateful_Attribute_2_1_0_a& a)
		{
			stream >> a.m_name;
			stream >> a.m_state;
			stream >> a.m_values;
			return stream;
		}

	private:
		QString m_state;

		QMap<QString, QVariant> m_values{ QMap<QString, QVariant>() };
	};

	class Attribute_Set_2_1_0_a
	{
	public:
		void add_stateless_attribute(Stateless_Attribute_2_1_0_a attribute);

		void add_stateful_attribute(Stateful_Attribute_2_1_0_a attribute);

		bool contains(const QString& attribute_name);

		QMap<QString, Stateful_Attribute_2_1_0_a>& stateful_attributes();

		QMap<QString, Stateless_Attribute_2_1_0_a>& stateless_attributes();

		friend QDataStream& operator <<(QDataStream& stream, const Attribute_Set_2_1_0_a& as)
		{
			stream << as.m_stateful_attributes;
			stream << as.m_stateless_attributes;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Attribute_Set_2_1_0_a& as)
		{
			stream >> as.m_stateful_attributes;
			stream >> as.m_stateless_attributes;
			return stream;
		}

	private:
		QMap<QString, Stateful_Attribute_2_1_0_a> m_stateful_attributes{ QMap<QString, Stateful_Attribute_2_1_0_a>() };
		QMap<QString, Stateless_Attribute_2_1_0_a> m_stateless_attributes{ QMap<QString, Stateless_Attribute_2_1_0_a>() };
	};

	class Theme_2_1_0_a
	{
	public:
		Theme_2_1_0_a();
		Theme_2_1_0_a(const QString& name, bool is_custom = true);

		void add_stateful_attribute(
			const QString& themeable_tag,
			const QString& attribute_name,
			QMap<QString, QVariant> state_value_map);

		void add_stateless_attribute(
			const QString& themeable_tag,
			const QString& attribute_name,
			QVariant value);

		QHash<QString, Attribute_Set_2_1_0_a>& attribute_sets();

		bool is_custom();

		QString& name();

		friend QDataStream& operator <<(QDataStream& stream, const Theme_2_1_0_a& t)
		{
			stream << t.m_attribute_sets;
			stream << t.m_is_custom;
			stream << t.m_name;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Theme_2_1_0_a& t)
		{
			stream >> t.m_attribute_sets;
			stream >> t.m_is_custom;
			stream >> t.m_name;
			return stream;
		}

	private:
		bool m_is_custom{ true };

		QHash<QString, Attribute_Set_2_1_0_a> m_attribute_sets{ QHash<QString, Attribute_Set_2_1_0_a>() };

		QString m_name;
	};
}

// 2.2.0a Classes
namespace Layers
{
	class Attribute_2_2_0_a
	{
	public:
		Attribute_2_2_0_a(const QString& name);

		QString& name();

		Themeable* parent_themeable() const;

		void set_parent_themeable(Themeable* parent_themeable);

		virtual QVariant& value() = 0;

	protected:
		QString m_name{ "" };

		Themeable* m_parent_themeable{ nullptr };
	};

	class Stateless_Attribute_2_2_0_a : public Attribute_2_2_0_a
	{
	public:
		Stateless_Attribute_2_2_0_a();
		Stateless_Attribute_2_2_0_a(const QString& name, QVariant value);

		void set_value(QVariant value);

		QVariant& value();

		friend QDataStream& operator <<(QDataStream& stream, const Stateless_Attribute_2_2_0_a& a)
		{
			stream << a.m_name;
			stream << a.m_value;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Stateless_Attribute_2_2_0_a& a)
		{
			stream >> a.m_name;
			stream >> a.m_value;
			return stream;
		}

	private:
		QVariant m_value{ QVariant() };
	};

	class Stateful_Attribute_2_2_0_a : public Attribute_2_2_0_a
	{
	public:
		Stateful_Attribute_2_2_0_a();
		Stateful_Attribute_2_2_0_a(const QString& name, QMap<QString, QVariant> state_value_map);

		bool contains_state(const QString& state) const;

		void set_state(const QString& state);

		void set_value(const QString& state, QVariant value);

		void set_values(const QMap<QString, QVariant>& values);

		QString state() const;

		QList<QString> states() const;

		QVariant* value(const QString& state);

		QVariant& value();

		QMap<QString, QVariant>& values();

		friend QDataStream& operator <<(QDataStream& stream, const Stateful_Attribute_2_2_0_a& a)
		{
			stream << a.m_name;
			stream << a.m_state;
			stream << a.m_values;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Stateful_Attribute_2_2_0_a& a)
		{
			stream >> a.m_name;
			stream >> a.m_state;
			stream >> a.m_values;
			return stream;
		}

	private:
		QString m_state;

		QMap<QString, QVariant> m_values{ QMap<QString, QVariant>() };
	};

	class Attribute_Set_2_2_0_a
	{
	public:
		void add_stateless_attribute(Stateless_Attribute_2_2_0_a attribute);

		void add_stateful_attribute(Stateful_Attribute_2_2_0_a attribute);

		Attribute_2_2_0_a* attribute(const QString& attribute_name);

		QVariant* attribute_value(const QString& attribute_name);

		bool contains(const QString& attribute_name);

		bool contains_stateful_attribute(const QString& attribute_name);

		bool contains_stateless_attribute(const QString& attribute_name);

		void copy_values_from(Attribute_Set_2_2_0_a& other_attribute_set);

		void remove_attribute(const QString& attribute_name);

		void set_state(const QString& state);

		Stateful_Attribute_2_2_0_a* stateful_attribute(const QString& attribute_name);

		QMap<QString, Stateful_Attribute_2_2_0_a>& stateful_attributes();

		Stateless_Attribute_2_2_0_a* stateless_attribute(const QString& attribute_name);

		QMap<QString, Stateless_Attribute_2_2_0_a>& stateless_attributes();

		QList<QString> states() const;

		friend QDataStream& operator <<(QDataStream& stream, const Attribute_Set_2_2_0_a& as)
		{
			stream << as.m_stateful_attributes;
			stream << as.m_stateless_attributes;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Attribute_Set_2_2_0_a& as)
		{
			stream >> as.m_stateful_attributes;
			stream >> as.m_stateless_attributes;
			return stream;
		}

	private:
		QMap<QString, Stateful_Attribute_2_2_0_a> m_stateful_attributes{ QMap<QString, Stateful_Attribute_2_2_0_a>() };
		QMap<QString, Stateless_Attribute_2_2_0_a> m_stateless_attributes{ QMap<QString, Stateless_Attribute_2_2_0_a>() };
	};

	class Theme_2_2_0_a
	{
	public:
		Theme_2_2_0_a();
		Theme_2_2_0_a(const QString& name, bool is_custom = true);

		void add_attribute_set(const QString& themeable_tag, Attribute_Set_2_2_0_a attribute_set);

		void add_stateful_attribute(
			const QString& themeable_tag,
			const QString& attribute_name,
			QMap<QString, QVariant> state_value_map);

		void add_stateless_attribute(
			const QString& themeable_tag,
			const QString& attribute_name,
			QVariant value);

		Attribute_Set_2_2_0_a& attribute_set(const QString& themeable_tag);

		QHash<QString, Attribute_Set_2_2_0_a>& attribute_sets();

		bool contains_attributes_for_tag(const QString& themeable_tag);

		bool contains_attribute(const QString& themeable_tag, const QString& attribute_name);

		void copy_attribute_sets_from(Theme_2_2_0_a& theme);

		bool is_custom();

		QString& name();

		void set_name(const QString& new_name);

		Stateful_Attribute_2_2_0_a* stateful_attribute(const QString& themeable_tag, const QString& attribute_name);

		Stateless_Attribute_2_2_0_a* stateless_attribute(const QString& themeable_tag, const QString& attribute_name);

		friend QDataStream& operator <<(QDataStream& stream, const Theme_2_2_0_a& t)
		{
			stream << t.m_attribute_sets;
			stream << t.m_is_custom;
			stream << t.m_name;
			return stream;
		}

		friend QDataStream& operator >>(QDataStream& stream, Theme_2_2_0_a& t)
		{
			stream >> t.m_attribute_sets;
			stream >> t.m_is_custom;
			stream >> t.m_name;
			return stream;
		}

	private:
		bool m_is_custom{ true };

		QHash<QString, Attribute_Set_2_2_0_a> m_attribute_sets{ QHash<QString, Attribute_Set_2_2_0_a>() };

		QString m_name;
	};
}

#endif // OLD_H
