#include <LayersCore/lthemeable.h>

#include <QWidget>

#include <LayersCore/lattribute.h>
#include <LayersCore/lgraphic.h>
#include <LayersCore/ltheme.h>

using Layers::LAbstractAttribute;
using Layers::LAttribute;
using Layers::LGraphic;
using Layers::LTheme;
using Layers::LThemeable;

LThemeable::~LThemeable()
{
	if (m_name)
		delete m_name;

	if (m_icon)
		delete m_icon;
}

void LThemeable::apply_theme(LTheme& theme)
{
	if (!m_name)
		qDebug() << "Unable to apply theme. "
			"You must apply a name to the widget first.";
	else
	{
		for (LThemeable* child_themeable : child_themeables())
			if (child_themeable->m_name && child_themeable->m_tag_prefixes_assigned)
				child_themeable->apply_theme(theme);

		if (theme.contains_attributes_for_tag(tag()))
		{
			LAttributeMap& theme_attrs = theme[tag()];

			for (LAbstractAttribute* abstract_attr : m_attributes)
			{
				if (theme_attrs.contains(abstract_attr->name()))
				{
					if (LAttribute* attr = dynamic_cast<LAttribute*>(abstract_attr))
						attr->copy(*dynamic_cast<LAttribute*>(theme_attrs[attr->name()]));
					else if (LAttributeGroup* attr_group = dynamic_cast<LAttributeGroup*>(abstract_attr))
						attr_group->copy(*dynamic_cast<LAttributeGroup*>(theme_attrs[attr_group->name()]));
				}
			}
		}
	}
}

void LThemeable::assign_tag_prefixes(QStringList prefixes)
{
	if (m_name)
	{
		m_tag_prefixes.append(prefixes);
		m_tag_prefixes_assigned = true;

		prefixes.append(*m_name);

		for (LThemeable* child_themeable : child_themeables())
			child_themeable->assign_tag_prefixes(prefixes);
	}
}

QMap<QString, LAbstractAttribute*>& LThemeable::attributes()
{
	return m_attributes;
}

QList<LThemeable*> LThemeable::child_themeables(Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables = QList<LThemeable*>();

	if (QObject* object = dynamic_cast<QObject*>(this))
	{
		QList<QObject*> child_objects =
			object->findChildren<QObject*>(Qt::FindDirectChildrenOnly);

		for (QObject* child_object : child_objects)
		{
			if (LThemeable* child_themeable = dynamic_cast<LThemeable*>(child_object))
			{
				child_themeables.append(child_themeable);

				if (options == Qt::FindChildrenRecursively)
					child_themeables.append(child_themeable->child_themeables(options));
			}
		}
	}

	return child_themeables;
}

LThemeable* LThemeable::clone()
{
	return new LThemeable;
}

void LThemeable::copy_attribute_values_to(LTheme* theme)
{
	if (m_tag_prefixes_assigned && !m_is_blocked_from_theme)
	{
		theme->copy_attribute_values_of(this);

		for (LThemeable* child_themeable : child_themeables())
			child_themeable->copy_attribute_values_to(theme);
	}
}

void LThemeable::establish_update_connection(
	LAbstractAttribute* abstract_attribute)
{
	if (QWidget* widget = dynamic_cast<QWidget*>(this))
	{
		if (LAttribute* attr = dynamic_cast<LAttribute*>(abstract_attribute))
		{
			widget->connect(attr, &LAttribute::changed, [widget]
				{ widget->update(); });
		}
		else if (LAttributeGroup* attr_group =
			dynamic_cast<LAttributeGroup*>(abstract_attribute))
		{
			widget->connect(attr_group, &LAttributeGroup::changed, [widget]
				{ widget->update(); });

			for (LAttribute* attr : attr_group->attributes())
				widget->connect(attr, &LAttribute::changed, [widget]
					{ widget->update(); });
		}
	}
}

LGraphic* LThemeable::icon() const
{
	return m_icon;
}

bool LThemeable::is_app_themeable() const
{
	return m_is_app_themeable;
}

bool LThemeable::is_multi_valued() const
{
	for (LAbstractAttribute* entity : m_attributes)
	{
		if (LAttribute* attr = dynamic_cast<LAttribute*>(entity))
		{
			if (attr->is_multi_valued())
				return true;
		}
		else if (LAttributeGroup* attr_group = dynamic_cast<LAttributeGroup*>(entity))
			if (attr_group->is_multi_valued())
				return true;

	}

	return false;
}

QString* LThemeable::name() const
{
	return m_name;
}

void LThemeable::set_functionality_disabled(bool disabled)
{
	m_functionality_disabled = disabled;

	for (LThemeable* child_themeable : child_themeables())
		child_themeable->set_functionality_disabled(disabled);
}

void LThemeable::set_icon(const LGraphic& icon)
{
	if (m_icon)
		delete m_icon;

	m_icon = new LGraphic(icon);
}

void LThemeable::set_is_app_themeable(bool is_app_themeable)
{
	m_is_app_themeable = is_app_themeable;

	for (LThemeable* child_themeable : child_themeables(Qt::FindChildrenRecursively))
		child_themeable->m_is_app_themeable = is_app_themeable;
}

void LThemeable::set_is_blocked_from_theme(bool is_blocked_from_theme)
{
	m_is_blocked_from_theme = is_blocked_from_theme;

	for (LThemeable* child_themeable : child_themeables(Qt::FindChildrenRecursively))
		child_themeable->m_is_blocked_from_theme = is_blocked_from_theme;
}

void LThemeable::set_is_preview_themeable(bool is_preview_themeable)
{
	m_is_preview_themeable = is_preview_themeable;

	for (LThemeable* child_themeable : child_themeables(Qt::FindChildrenRecursively))
		child_themeable->m_is_preview_themeable = is_preview_themeable;
}

void LThemeable::set_name(const QString& name)
{
	if (m_name)
		delete m_name;

	m_name = new QString(name);
}

void LThemeable::set_state(const QString& state)
{
	if (m_state != state)
	{
		m_state = state;

		for (LAbstractAttribute* entity : m_attributes)
		{
			if (LAttribute* attr = dynamic_cast<LAttribute*>(entity))
				attr->set_state(state);
			else if (LAttributeGroup* attr_group = dynamic_cast<LAttributeGroup*>(entity))
				attr_group->set_state(state);
		}

		for (LThemeable* child_themeable : child_themeables())
			child_themeable->set_state(state);
	}
}

QString LThemeable::state() const
{
	return m_state;
}

QStringList LThemeable::states() const
{
	QStringList states;

	for (LAbstractAttribute* entity : m_attributes)
	{
		if (LAttribute* attr = dynamic_cast<LAttribute*>(entity))
		{
			for (const QString& state : attr->states())
				if (!states.contains(state))
					states.append(state);
		}
		else if (LAttributeGroup* attr_group = dynamic_cast<LAttributeGroup*>(entity))
		{
			for (LAttribute* attr : attr_group->attributes())
				for (const QString& state : attr->states())
					if (!states.contains(state))
						states.append(state);
		}
	}

	return states;
}

QString& LThemeable::tag()
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

QStringList LThemeable::tag_prefixes() const
{
	return m_tag_prefixes;
}
