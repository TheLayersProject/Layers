#include <Layers/lthemeable.h>

#include <QWidget>

#include <Layers/lattribute.h>
#include <Layers/lgraphic.h>
#include <Layers/ltheme.h>

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

void LThemeable::add_state_pool(LStatePool* state_pool, bool include_children)
{
	m_state_pools.append(state_pool);

	state_pool->connect(state_pool, &LStatePool::changed, [this]
		{
			for (LAttribute* attr : attributes())
				attr->changed();
		});

	for (LThemeable* child_themeable : child_themeables())
		child_themeable->add_state_pool(state_pool, include_children);
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

			for (LAttribute* attr : attributes())
				if (theme_attrs.contains(attr->name()))
					attr->copy(*theme_attrs[attr->name()]);
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

LAttribute* LThemeable::attribute(const QString& link)
{
	QStringList link_parts = link.split('.');

	QString search_tag = link_parts.takeFirst();
	QString attr_id = link_parts.join(".");

	return attribute(search_tag, attr_id);
}

LAttribute* LThemeable::attribute(const QString& search_tag, const QString& attr_id)
{
	//if (tag() == search_tag)
	//{
	//	QStringList attr_parts = attr_id.split('.');

	//	if (attr_parts.size() > 1)
	//	{
	//		for (LAttributeGroup* attr_group : m_attr_data.attr_groups)
	//		{
	//			if (attr_group->name() == attr_parts[0])
	//			{
	//				for (LAttribute* group_attr : (*attr_group))
	//					if (group_attr->name() == attr_parts[1])
	//						return group_attr;
	//			}
	//		}
	//	}
	//	else
	//	{
	//		for (LAttribute* attr : m_attr_data.ungrouped_attrs)
	//			if (attr->name() == attr_parts[0])
	//				return attr;
	//	}

	//	// TODO: Add support for override attributes
	//}
	//else
	//{
	//	for (LThemeable* child_themeable : child_themeables())
	//	{
	//		if (search_tag.contains(child_themeable->tag()))
	//			return child_themeable->attribute(search_tag, attr_id);
	//	}
	//}

	return nullptr;
}

QList<LAttribute*> LThemeable::attributes()
{
	QList<LAttribute*> attributes;

	if (QObject* object = dynamic_cast<QObject*>(this))
	{
		QList<QObject*> child_objects =
			object->findChildren<QObject*>(Qt::FindDirectChildrenOnly);

		for (QObject* child_object : child_objects)
			if (LAttribute* attr = dynamic_cast<LAttribute*>(child_object))
				attributes.append(attr);
	}

	return attributes;
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

LGraphic* LThemeable::icon() const
{
	return m_icon;
}

bool LThemeable::is_app_themeable() const
{
	return m_is_app_themeable;
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

QStringList LThemeable::states() const
{
	QStringList states;

	for (LStatePool* state_pool : m_state_pools)
		states.append(state_pool->state());

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

void LThemeable::update()
{
	if (QWidget* widget = dynamic_cast<QWidget*>(this))
		widget->update();
}
