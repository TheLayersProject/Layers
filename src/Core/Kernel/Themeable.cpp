#include "Themeable.h"

#include <QWidget>

#include "Attribute.h"
#include "Graphic.h"
#include "Theme.h"

using Layers::AbstractAttribute;
using Layers::Attribute;
using Layers::Graphic;
using Layers::Theme;
using Layers::Themeable;

Themeable::~Themeable()
{
	if (m_name)
		delete m_name;

	if (m_icon)
		delete m_icon;
}

void Themeable::apply_theme(Theme& theme)
{
	if (!m_name)
		qDebug() << "Unable to apply theme. "
			"You must apply a name to the widget first.";
	else
	{
		for (Themeable* child_themeable : child_themeables())
			if (child_themeable->m_name && child_themeable->m_tag_prefixes_assigned)
				child_themeable->apply_theme(theme);

		if (theme.contains_attributes_for_tag(tag()))
		{
			AttributeMap& theme_attrs = theme[tag()];

			for (AbstractAttribute* abstract_attr : m_attributes)
			{
				if (theme_attrs.contains(abstract_attr->name()))
				{
					if (Attribute* attr = dynamic_cast<Attribute*>(abstract_attr))
						attr->copy(*dynamic_cast<Attribute*>(theme_attrs[attr->name()]));
					else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(abstract_attr))
						attr_group->copy(*dynamic_cast<AttributeGroup*>(theme_attrs[attr_group->name()]));
				}
			}
		}
	}
}

void Themeable::assign_tag_prefixes(QStringList prefixes)
{
	if (m_name)
	{
		m_tag_prefixes.append(prefixes);
		m_tag_prefixes_assigned = true;

		prefixes.append(*m_name);

		for (Themeable* child_themeable : child_themeables())
			child_themeable->assign_tag_prefixes(prefixes);
	}
}

QMap<QString, AbstractAttribute*>& Themeable::attributes()
{
	return m_attributes;
}

QList<Themeable*> Themeable::child_themeables(Qt::FindChildOptions options)
{
	QList<Themeable*> child_themeables = QList<Themeable*>();

	if (QObject* object = dynamic_cast<QObject*>(this))
	{
		QList<QObject*> child_objects =
			object->findChildren<QObject*>(Qt::FindDirectChildrenOnly);

		for (QObject* child_object : child_objects)
		{
			if (Themeable* child_themeable = dynamic_cast<Themeable*>(child_object))
			{
				child_themeables.append(child_themeable);

				if (options == Qt::FindChildrenRecursively)
					child_themeables.append(child_themeable->child_themeables(options));
			}
		}
	}

	return child_themeables;
}

Themeable* Themeable::clone()
{
	return new Themeable;
}

void Themeable::copy_attribute_values_to(Theme* theme)
{
	if (m_tag_prefixes_assigned)
	{
		theme->copy_attribute_values_of(this);

		for (Themeable* child_themeable : child_themeables(Qt::FindChildrenRecursively))
			if (child_themeable->m_tag_prefixes_assigned)
				theme->copy_attribute_values_of(child_themeable);
	}
}

void Themeable::establish_update_connection(
	AbstractAttribute* abstract_attribute)
{
	if (QWidget* widget = dynamic_cast<QWidget*>(this))
	{
		if (Attribute* attr = dynamic_cast<Attribute*>(abstract_attribute))
		{
			widget->connect(attr, &Attribute::changed, [widget]
				{ widget->update(); });
		}
		else if (AttributeGroup* attr_group =
			dynamic_cast<AttributeGroup*>(abstract_attribute))
		{
			widget->connect(attr_group, &AttributeGroup::changed, [widget]
				{ widget->update(); });

			for (Attribute* attr : attr_group->attributes())
				widget->connect(attr, &Attribute::changed, [widget]
					{ widget->update(); });
		}
	}
}

Graphic* Themeable::icon() const
{
	return m_icon;
}

bool Themeable::is_app_themeable() const
{
	return m_is_app_themeable;
}

bool Themeable::is_multi_valued() const
{
	for (AbstractAttribute* entity : m_attributes)
	{
		if (Attribute* attr = dynamic_cast<Attribute*>(entity))
		{
			if (attr->is_multi_valued())
				return true;
		}
		else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(entity))
			if (attr_group->is_multi_valued())
				return true;

	}

	return false;
}

QString* Themeable::name() const
{
	return m_name;
}

void Themeable::set_functionality_disabled(bool disabled)
{
	m_functionality_disabled = disabled;

	for (Themeable* child_themeable : child_themeables())
		child_themeable->set_functionality_disabled(disabled);
}

void Themeable::set_icon(const Graphic& icon)
{
	if (m_icon)
		delete m_icon;

	m_icon = new Graphic(icon);
}

void Themeable::set_is_app_themeable(bool is_app_themeable)
{
	m_is_app_themeable = is_app_themeable;

	for (Themeable* child_themeable : child_themeables(Qt::FindChildrenRecursively))
		child_themeable->m_is_app_themeable = is_app_themeable;
}

void Themeable::set_name(const QString& name)
{
	if (m_name)
		delete m_name;

	m_name = new QString(name);
}

void Themeable::set_state(const QString& state)
{
	if (m_state != state)
	{
		m_state = state;

		for (AbstractAttribute* entity : m_attributes)
		{
			if (Attribute* attr = dynamic_cast<Attribute*>(entity))
				attr->set_state(state);
			else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(entity))
				attr_group->set_state(state);
		}

		for (Themeable* child_themeable : child_themeables())
			child_themeable->set_state(state);
	}
}

QString Themeable::state() const
{
	return m_state;
}

QStringList Themeable::states() const
{
	QStringList states;

	for (AbstractAttribute* entity : m_attributes)
	{
		if (Attribute* attr = dynamic_cast<Attribute*>(entity))
		{
			for (const QString& state : attr->states())
				if (!states.contains(state))
					states.append(state);
		}
		else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(entity))
		{
			for (Attribute* attr : attr_group->attributes())
				for (const QString& state : attr->states())
					if (!states.contains(state))
						states.append(state);
		}
	}

	return states;
}

QString& Themeable::tag()
{
	if (m_tag == "")
	{
		for (QString prefix : m_tag_prefixes)
		{
			m_tag += prefix + "/";
		}

		if (m_name)
			m_tag += *m_name;
	}

	return m_tag;
}

QStringList Themeable::tag_prefixes() const
{
	return m_tag_prefixes;
}
