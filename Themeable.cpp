#include "Layers.h"

using Layers::Attribute;
using Layers::Attribute_Widget;
using Layers::Customize_Panel;
using Layers::Customize_Panel;
using Layers::Graphic_Widget;
using Layers::Attribute_Sharing_Combo;
using Layers::Themeable;
using Layers::Theme;

Themeable::~Themeable()
{
	if (m_name) delete m_name;
	if (m_app_name) delete m_app_name;
	if (m_proper_name) delete m_proper_name;

	m_name = nullptr;
	m_app_name = nullptr;
	m_proper_name = nullptr;

	while (!attribute_sharing_combos.isEmpty())
	{
		delete attribute_sharing_combos.takeLast();
	}
}

void Themeable::add_attribute(const QString& attribute_name, QVariant value)
{
	if (!m_attributes.contains(attribute_name))
	{
		m_attributes[attribute_name] = Attribute(attribute_name, value);
		m_attributes[attribute_name].set_parent_themeable(this);
	}
}

Customize_Panel* Themeable::customize_panel() const
{
	return m_customize_panel;
}

Customize_Panel* Themeable::init_customize_panel()
{
	m_customize_panel = new Customize_Panel(this);

	init_attribute_widgets();

	m_customize_panel->update_attribute_widget_background_colors();
	
	return m_customize_panel;
}

Graphic_Widget* Themeable::icon() const
{
	return m_icon;
}

void Themeable::init_child_themeable_reference_list()
{
}

void Themeable::initialize_and_acquire_panels(QList<Customize_Panel*>& list)
{
	for (Themeable* child_themeable : m_child_themeable_references)
	{
		if (child_themeable->proper_name()) child_themeable->initialize_and_acquire_panels(list); // TODO: Consider a Themeable::is_customizable() function so this is clearer
	}

	list.append(init_customize_panel());
}

bool Themeable::is_stateful() const
{
	return m_is_stateful;
}

void Themeable::make_attribute_stateful(const QString& attribute_name, QMap<QString, QVariant> state_value_map)
{
	m_is_stateful = true;

	if (m_attributes.contains(attribute_name))
	{
		m_attributes[attribute_name].make_stateful(state_value_map);
	}
}

void Themeable::apply_theme(Theme& theme)
{
	if (m_current_theme != &theme) m_current_theme = &theme;

	if (!m_name) qDebug() << "Unable to apply theme.  You must apply a name to the widget first.";
	else
	{
		if (theme.contains(theme_tag()))
		{
			for (const QString& attribute_name : m_attributes.keys())
				if (theme[theme_tag()].contains(attribute_name))
					m_attributes[attribute_name].apply_theme_attribute(theme[theme_tag()][attribute_name]);

			share_attributes();
			update_theme_dependencies();
		}

		for (Themeable* child_themeable : m_child_themeable_references)
			child_themeable->apply_theme(theme);
	}
}

void Themeable::reapply_theme()
{
	if (m_current_theme) apply_theme(*m_current_theme);
}

void Themeable::add_child_themeable_reference(Themeable* child_themeable)
{
	// TODO: Consider a version of this function that can also name the child themeable
	m_child_themeable_references.append(child_themeable);

	if (m_tag_prefixes_assigned)
	{
		if (*m_name == "window") child_themeable->assign_tag_prefixes(m_tag_prefixes, "");
		else child_themeable->assign_tag_prefixes(m_tag_prefixes, *m_name);
	}
}

void Themeable::remove_child_themeable_reference(Themeable* child_themeable)
{
	m_child_themeable_references.removeOne(child_themeable);

	child_themeable->unassign_prefixes();
}

void Themeable::set_ACW_primary(const QString& ACW_name, bool is_primary)
{
	if (m_attribute_widgets.contains(ACW_name))
		m_attribute_widgets[ACW_name]->set_primary(is_primary);
	else
		m_ACW_pre_init_primary_values[ACW_name] = is_primary;
}

void Themeable::set_attribute_value(const QString& attribute_name, QVariant value, bool update)
{
	if (m_attributes.contains(attribute_name))
	{
		if (m_attributes[attribute_name].is_stateful())
		{
			qDebug() << "ERROR: Failed to set attribute value. Attribute is stateful; use set_attribute_value() that requires a state.";
		}
		else
		{
			m_attributes[attribute_name].set_value(value);

			if (update) issue_update();
		}
	}
}

void Themeable::assign_tag_prefixes(QList<QString> parent_prefixes, const QString& parent_name)
{
	if (parent_name != "")
	{
		m_tag_prefixes.append(parent_prefixes);
		m_tag_prefixes.append(parent_name);
	}

	for (Themeable* child_themeable : m_child_themeable_references)
	{
		child_themeable->assign_tag_prefixes(m_tag_prefixes, *m_name);
	}

	m_tag_prefixes_assigned = true;
}

void Themeable::unassign_prefixes()
{
	m_tag_prefixes.clear();

	m_tag_prefixes_assigned = false;

	for (Themeable* child_themeable : m_child_themeable_references)
	{
		child_themeable->unassign_prefixes();
	}
}

QMap<QString, Attribute>& Themeable::attributes()
{
	return m_attributes;
}

QMap<QString, Attribute_Widget*>& Themeable::attribute_widgets()
{
	return m_attribute_widgets;
}

QList<Themeable*>& Themeable::child_themeable_references()
{
	return m_child_themeable_references;
}

void Themeable::replace_all_attributes_in_theme(Theme* theme)
{
	if (theme->contains(theme_tag()))
	{
		theme->replace_attributes(this);

		for (Themeable* child_themeable : m_child_themeable_references)
			child_themeable->replace_all_attributes_in_theme(theme);
	}
}

Theme* Themeable::current_theme()
{
	return m_current_theme;
}

void Themeable::filter_attribute(const QString& attribute)
{
	// TODO: Consider how filtration needs to work
	m_filtered_attributes.append(attribute);
}

void Themeable::unfilter_attribute(const QString& attribute)
{
	m_filtered_attributes.removeOne(attribute);
}

void Themeable::set_attribute_value(const QString& state, const QString& attribute, QVariant value, bool update)
{
	if (m_attributes.contains(attribute) && m_attributes[attribute].contains_state(state))
	{
		m_attributes[attribute].set_value(state, value);

		if (update) issue_update();
	}
}

void Themeable::set_icon(Graphic_Widget* icon)
{
	if (m_icon) m_icon->deleteLater();

	m_icon = icon;
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

		for (Attribute& attribute : m_attributes)
			if (attribute.is_stateful()) attribute.set_state(state);

		for (Themeable* child_themeable : m_child_themeable_references)
			child_themeable->set_state(state);

		update_theme_dependencies();

		issue_update();
	}
}

//Attribute_Sharing_Combo* Themeable::share_attribute_with_themeable(
//	const QString& from_state, const QString& from_attribute,
//	Themeable* to_themeable, QString to_state, QString to_attribute,
//	bool obtain_attribute)
//{
//	if (to_state == "") to_state = from_state;
//	if (to_attribute == "") to_attribute = from_attribute;
//
//	Attribute_Sharing_Combo* attribute_sharing_combo = new Attribute_Sharing_Combo(
//		m_attributes[from_attribute], to_themeable->attributes()[to_attribute], from_state, to_state);
//
//	attribute_sharing_combos.append(attribute_sharing_combo);
//
//	if (obtain_attribute)
//	{
//		attribute_sharing_combo->obtain_attribute(false);
//	}
//	else attribute_sharing_combo->share_attribute();
//
//	return attribute_sharing_combo;
//}

Attribute_Sharing_Combo* Themeable::share_attribute_with_themeable(
	Attribute& from_attribute, Attribute& to_attribute,
	QString from_state, QString to_state,
	bool obtain_attribute)
{
	Attribute_Sharing_Combo* attribute_sharing_combo = new Attribute_Sharing_Combo(
		from_attribute, to_attribute, from_state, to_state);

	attribute_sharing_combos.append(attribute_sharing_combo);

	if (obtain_attribute)
	{
		attribute_sharing_combo->obtain_attribute(false);
	}
	else attribute_sharing_combo->share_attribute();

	return attribute_sharing_combo;
}

//void Themeable::unshare_attribute_with_themeable(
//	const QString& from_state, const QString& from_attribute,
//	Themeable* to_themeable, QString to_state, QString to_attribute)
//{
//	// TODO: Consider making a version of this that only requires a reference to the attribute_sharing_combo
//
//	if (to_state == "") to_state = from_state;
//	if (to_attribute == "") to_attribute = from_attribute;
//
//	for (int i = 0; i < attribute_sharing_combos.size(); i++)
//	{
//		if (attribute_sharing_combos.at(i)->to_themeable() == to_themeable &&
//			attribute_sharing_combos.at(i)->from_attribute_name() == from_attribute &&
//			attribute_sharing_combos.at(i)->from_state() == from_state &&
//			attribute_sharing_combos.at(i)->to_state() == to_state)
//		{
//			delete attribute_sharing_combos.takeAt(i);
//		}
//	}
//}

void Themeable::unshare_attribute_with_themeable(
	Attribute& from_attribute, Attribute& to_attribute,
	QString from_state, QString to_state)
{
	for (int i = 0; i < attribute_sharing_combos.size(); i++)
	{
		if (attribute_sharing_combos.at(i)->from_state() == from_state &&
			&attribute_sharing_combos.at(i)->from_attribute() == &from_attribute &&
			attribute_sharing_combos.at(i)->to_state() == to_state &&
			&attribute_sharing_combos.at(i)->to_attribute() == &to_attribute)
		{
			delete attribute_sharing_combos.takeAt(i);
		}
	}
}

QString* Layers::Themeable::proper_name() const
{
	return m_proper_name;
}

QString& Themeable::theme_tag()
{
	if (m_theme_tag == "")
	{
		if (m_app_name)
		{
			m_theme_tag += "app/" + *m_app_name + "/";
		}
		else
		{
			m_theme_tag += "layers/";
		}

		for (QString supplemental_prefix : m_tag_prefixes)
		{
			m_theme_tag += supplemental_prefix + "/";
		}

		m_theme_tag += m_name;
	}

	return m_theme_tag;
}

QList<QString> Themeable::states() const
{
	QList<QString> states = QList<QString>();

	for (const Attribute& attribute : m_attributes)
		for (const QString& state : attribute.states())
			if (!states.contains(state)) states.append(state);

	return states;
}

Attribute_Sharing_Combo* Themeable::take_attribute_sharing_combo(const QString& from_state, const QString& from_attribute, Themeable* to_themeable, const QString& to_state, const QString& to_attribute)
{
	for (int i = 0; i < attribute_sharing_combos.size(); i++)
	{
		if (attribute_sharing_combos.at(i)->from_themeable() == this &&
			attribute_sharing_combos.at(i)->from_state() == from_state &&
			attribute_sharing_combos.at(i)->from_attribute_name() == from_attribute &&
			attribute_sharing_combos.at(i)->to_themeable() == to_themeable &&
			attribute_sharing_combos.at(i)->to_state() == to_state &&
			attribute_sharing_combos.at(i)->to_attribute_name() == to_attribute)
		{
			return attribute_sharing_combos.takeAt(i);
		}
	}

	return nullptr;
}

void Themeable::update_theme_dependencies()
{
}

void Themeable::init_attributes()
{
}

void Themeable::init_attribute_widgets()
{
}

void Themeable::share_attributes()
{
	if (!m_shared_attributes)
	{
		m_shared_attributes = true;

		for (Attribute_Sharing_Combo* attribute_sharing_combo : attribute_sharing_combos)
		{
			attribute_sharing_combo->share_attribute();
		}

		m_shared_attributes = false;
	}
}

QString Themeable::state() const
{
	return m_state;
}
