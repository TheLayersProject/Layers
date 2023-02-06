#include "../../../include/Attribute.h"
#include "../../../include/Graphic.h"
#include "../../../include/Theme.h"
#include "../../../include/Themeable.h"

using Layers::Attribute;
using Layers::Entity;
using Layers::Graphic;
using Layers::Theme;
using Layers::Themeable;

Themeable::~Themeable()
{
	if (m_name) delete m_name;
	if (m_proper_name) delete m_proper_name;

	m_name = nullptr;
	m_proper_name = nullptr;
}

void Themeable::apply_theme(Theme& theme)
{
	if (!m_name) qDebug() << "Unable to apply theme.  You must apply a name to the widget first.";
	else
	{
		QList<Themeable*> children = child_themeables(Qt::FindChildrenRecursively);

		if (!children.isEmpty())
		{
			for (Themeable* child_themeable : children)
			{
				if (child_themeable->m_name && child_themeable->m_tag_prefixes_assigned)
				{
					qDebug() << child_themeable->tag();

					if (theme.contains_attributes_for_tag(child_themeable->tag()))
					{
						QMap<QString, Entity*>& theme_attrs = theme[child_themeable->tag()];

						for (Entity* entity : child_themeable->m_entities)
						{
							if (theme_attrs.contains(entity->name()))
							{
								if (Attribute* attr = dynamic_cast<Attribute*>(entity))
									attr->copy(*dynamic_cast<Attribute*>(theme_attrs[attr->name()]));
								else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(entity))
									attr_group->copy(*dynamic_cast<AttributeGroup*>(theme_attrs[attr_group->name()]));
							}
						}
					}
				}
			}
		}

		if (theme.contains_attributes_for_tag(tag()))
		{
			QMap<QString, Entity*>& theme_attrs = theme[tag()];

			for (Entity* entity : m_entities)
			{
				if (theme_attrs.contains(entity->name()))
				{
					if (Attribute* attr = dynamic_cast<Attribute*>(entity))
						attr->copy(*dynamic_cast<Attribute*>(theme_attrs[attr->name()]));
					else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(entity))
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
		if (!prefixes.isEmpty())
			m_tag_prefixes.append(prefixes);

		prefixes.append(*m_name);

		for (Themeable* child_themeable : child_themeables())
			child_themeable->assign_tag_prefixes(prefixes);

		m_tag_prefixes_assigned = true;
	}
}

QList<Themeable*> Themeable::child_themeables(Qt::FindChildOptions options)
{
	QList<Themeable*> child_themeables = QList<Themeable*>();

	if (QWidget* widget = dynamic_cast<QWidget*>(this))
	{
		/*
			NOTE: Qt 6.3 adds an overload for QObject::findChildren() that
			lets the caller pass only a Qt::FindChildOptions argument.
		*/
		QList<QWidget*> child_widgets = widget->findChildren<QWidget*>(QString(), options);

		if (!child_widgets.isEmpty())
		{
			for (QWidget* child_widget : child_widgets)
				if (Themeable* child_themeable = dynamic_cast<Themeable*>(child_widget))
					child_themeables.append(child_themeable);
		}
	}

	return child_themeables;
}

void Themeable::copy_attribute_values_to(Theme* theme)
{
	theme->copy_attribute_values_of(this);

	for (Themeable* child_themeable : child_themeables(Qt::FindChildrenRecursively))
		theme->copy_attribute_values_of(child_themeable);
		//child_themeable->copy_attribute_values_to(theme);
}

QMap<QString, Entity*>& Themeable::entities()
{
	return m_entities;
}

Graphic* Themeable::icon() const
{
	return m_icon;
}

bool Themeable::is_stateful() const
{
	for (Entity* entity : m_entities)
	{
		if (Attribute* attr = dynamic_cast<Attribute*>(entity))
		{
			if (attr->is_stateful())
				return true;
		}
		else if (AttributeGroup* attr_group = dynamic_cast<AttributeGroup*>(entity))
			if (attr_group->is_stateful())
				return true;

	}

	return false;
}

QString* Themeable::name() const
{
	return m_name;
}

QString* Themeable::proper_name() const
{
	return m_proper_name;
}

void Themeable::set_functionality_disabled(bool disabled)
{
	m_functionality_disabled = disabled;
}

void Themeable::set_icon(Graphic* icon)
{
	if (m_icon) m_icon->deleteLater();

	m_icon = icon;
}

void Themeable::set_is_app_themeable(bool is_app_themeable)
{
	m_is_app_themeable = is_app_themeable;

	for (Themeable* child_themeable : child_themeables(Qt::FindChildrenRecursively))
		child_themeable->m_is_app_themeable = is_app_themeable;
		//m_child_themeable->set_is_app_themeable(is_app_themeable);
}

void Themeable::set_name(const QString& name)
{
	if (m_name) delete m_name;

	m_name = new QString(name);
}

void Themeable::set_proper_name(const QString& proper_name)
{
	if (m_proper_name) delete m_proper_name;

	m_proper_name = new QString(proper_name);
}

void Themeable::set_state(const QString& state)
{
	if (m_state != state)
	{
		m_state = state;

		for (Entity* entity : m_entities)
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

	for (Entity* entity : m_entities)
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
		if (!m_is_app_themeable)
			m_tag += "layers/";

		for (QString prefix : m_tag_prefixes)
		{
			m_tag += prefix + "/";
		}

		if (m_name)
			m_tag += *m_name;
	}

	return m_tag;
}
