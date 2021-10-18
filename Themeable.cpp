#include "Layers.h"

using Layers::AttributeSet;
using Layers::AttributeSharingCombo;
using Layers::AttributeWidget;
using Layers::CustomizePanel;
using Layers::Graphic;
using Layers::StatefulAttribute;
using Layers::StatelessAttribute;
using Layers::Themeable;
using Layers::Theme;

Themeable::~Themeable()
{
	if (m_name) delete m_name;
	if (m_proper_name) delete m_proper_name;

	m_name = nullptr;
	m_proper_name = nullptr;

	while (!attribute_sharing_combos.isEmpty())
	{
		delete attribute_sharing_combos.takeLast();
	}
}

void Themeable::add_stateless_attribute(const QString& attribute_name, QVariant value)
{
	if (!m_attribute_set.contains(attribute_name))
	{
		m_attribute_set.add_attribute(StatelessAttribute(attribute_name, value));
		m_attribute_set.stateless_attribute(attribute_name)->set_parent_themeable(this);
	}
}

void Themeable::add_stateful_attribute(const QString& attribute_name, QMap<QString, QVariant> state_value_map)
{
	if (!m_attribute_set.contains(attribute_name))
	{
		m_attribute_set.add_attribute(StatefulAttribute(attribute_name, state_value_map));
		m_attribute_set.stateful_attribute(attribute_name)->set_parent_themeable(this);
	}
}

CustomizePanel* Themeable::customize_panel() const
{
	return m_customize_panel;
}

CustomizePanel* Themeable::init_customize_panel()
{
	m_customize_panel = new CustomizePanel(this);

	init_attribute_widgets();

	m_customize_panel->setup_layout();

	m_customize_panel->update_attribute_widget_background_colors();
	
	return m_customize_panel;
}

Graphic* Themeable::icon() const
{
	return m_icon;
}

void Themeable::init_child_themeable_reference_list()
{
}

void Themeable::initialize_and_acquire_panels(QList<CustomizePanel*>& list)
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

void Themeable::apply_theme(Theme& theme)
{
	if (m_current_theme != &theme) m_current_theme = &theme;

	if (!m_name) qDebug() << "Unable to apply theme.  You must apply a name to the widget first.";
	else
	{
		if (theme.contains_attributes_for_tag(theme_tag()))
		{
			m_attribute_set.copy_values_from(theme.attribute_set(theme_tag()));

			//m_attribute_set = theme.attribute_set(theme_tag());

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

void Themeable::set_is_app_themeable(bool is_app_themeable)
{
	m_is_app_themeable = is_app_themeable;

	for (Themeable* m_child_themeable : m_child_themeable_references)
		m_child_themeable->set_is_app_themeable(is_app_themeable);
}

void Themeable::set_functionality_disabled(bool disabled)
{
	m_functionality_disabled = disabled;
}

void Themeable::set_stateful_attribute_value(const QString& state, const QString& attribute_name, QVariant value, bool update)
{
	if (m_attribute_set.contains_stateful_attribute(attribute_name))
	{
		StatefulAttribute* stateful_attribute = m_attribute_set.stateful_attribute(attribute_name);

		if (stateful_attribute && stateful_attribute->contains_state(state))
		{
			stateful_attribute->set_value(state, value);

			if (update)
			{
				update_theme_dependencies();
				issue_update();
			}
		}
	}
}

void Themeable::set_stateless_attribute_value(const QString& attribute_name, QVariant value, bool update)
{
	if (m_attribute_set.contains_stateless_attribute(attribute_name))
	{
		m_attribute_set.stateless_attribute(attribute_name)->set_value(value);

		if (update)
		{
			update_theme_dependencies();
			issue_update();
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

AttributeSet& Layers::Themeable::attribute_set()
{
	return m_attribute_set;
}

QMap<QString, AttributeWidget*>& Themeable::attribute_widgets()
{
	return m_attribute_widgets;
}

QList<Themeable*>& Themeable::child_themeable_references()
{
	return m_child_themeable_references;
}

void Themeable::convert_attribute_to_stateful(const QString& attribute_name, QMap<QString, QVariant> state_value_map)
{
	m_is_stateful = true;

	if (m_attribute_set.contains_stateless_attribute(attribute_name))
	{
		m_attribute_set.remove_attribute(attribute_name);

		m_attribute_set.add_attribute(StatefulAttribute(attribute_name, state_value_map));
		m_attribute_set.stateful_attribute(attribute_name)->set_parent_themeable(this);
	}
	else qDebug() << "WARNING: Failed to convert attribute to stateful: '" + attribute_name + "' not found in attribute set.";
}

void Themeable::copy_attribute_values_to(Theme* theme)
{
	if (theme->contains_attributes_for_tag(theme_tag()))
	{
		theme->copy_attribute_values_of(this);

		for (Themeable* child_themeable : m_child_themeable_references)
			child_themeable->copy_attribute_values_to(theme);
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

void Themeable::set_icon(Graphic* icon)
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

		m_attribute_set.set_state(state);

		for (Themeable* child_themeable : m_child_themeable_references)
			child_themeable->set_state(state);

		update_theme_dependencies();

		issue_update();
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
		if (m_is_app_themeable)
		{
			//m_theme_tag += "app/" + *m_app_name + "/";
			m_theme_tag += "app/";
		}
		else
		{
			m_theme_tag += "layers/";
		}

		for (QString supplemental_prefix : m_tag_prefixes)
		{
			m_theme_tag += supplemental_prefix + "/";
		}

		if (m_name) m_theme_tag += *m_name;
	}

	return m_theme_tag;
}

//QMap<QString, StatefulAttribute>& Themeable::stateful_attributes()
//{
//	return m_stateful_attributes;
//}

QList<QString> Themeable::states() const
{
	return m_attribute_set.states();
}

AttributeSharingCombo* Themeable::take_attribute_sharing_combo(const QString& from_state, const QString& from_attribute, Themeable* to_themeable, const QString& to_state, const QString& to_attribute)
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

void Themeable::unshare_attribute_with_themeable(
	StatefulAttribute* from_stateful_attribute, QString from_state,
	StatefulAttribute* to_stateful_attribute, QString to_state)
{
	for (int i = 0; i < attribute_sharing_combos.size(); i++)
	{
		if (attribute_sharing_combos.at(i)->from_stateful_attribute() == from_stateful_attribute &&
			attribute_sharing_combos.at(i)->from_state() == from_state &&
			attribute_sharing_combos.at(i)->to_stateful_attribute() == to_stateful_attribute &&
			attribute_sharing_combos.at(i)->to_state() == to_state)
		{
			delete attribute_sharing_combos.takeAt(i);
		}
	}
}

void Themeable::unshare_attribute_with_themeable(
	StatelessAttribute* from_stateless_attribute,
	StatelessAttribute* to_stateless_attribute)
{
	for (int i = 0; i < attribute_sharing_combos.size(); i++)
	{
		if (attribute_sharing_combos.at(i)->from_stateless_attribute() == from_stateless_attribute &&
			attribute_sharing_combos.at(i)->to_stateless_attribute() == to_stateless_attribute)
		{
			delete attribute_sharing_combos.takeAt(i);
		}
	}
}

void Themeable::unshare_attribute_with_themeable(
	StatefulAttribute* from_stateful_attribute, QString from_state,
	StatelessAttribute* to_stateless_attribute)
{
	for (int i = 0; i < attribute_sharing_combos.size(); i++)
	{
		if (attribute_sharing_combos.at(i)->from_stateful_attribute() == from_stateful_attribute &&
			attribute_sharing_combos.at(i)->from_state() == from_state &&
			attribute_sharing_combos.at(i)->to_stateless_attribute() == to_stateless_attribute)
		{
			delete attribute_sharing_combos.takeAt(i);
		}
	}
}

void Themeable::unshare_attribute_with_themeable(
	StatelessAttribute* from_stateless_attribute,
	StatefulAttribute* to_stateful_attribute, QString to_state)
{
	for (int i = 0; i < attribute_sharing_combos.size(); i++)
	{
		if (attribute_sharing_combos.at(i)->from_stateless_attribute() == from_stateless_attribute &&
			attribute_sharing_combos.at(i)->to_stateful_attribute() == to_stateful_attribute &&
			attribute_sharing_combos.at(i)->to_state() == to_state)
		{
			delete attribute_sharing_combos.takeAt(i);
		}
	}
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

AttributeSharingCombo* Themeable::share_attribute_with_themeable(
	StatefulAttribute* from_stateful_attribute, QString from_state,
	StatefulAttribute* to_stateful_attribute, QString to_state,
	bool obtain_attribute)
{
	AttributeSharingCombo* attribute_sharing_combo = new AttributeSharingCombo(
		from_stateful_attribute, from_state, to_stateful_attribute, to_state);

	attribute_sharing_combos.append(attribute_sharing_combo);

	if (obtain_attribute)
	{
		attribute_sharing_combo->obtain_attribute(false);
	}
	else attribute_sharing_combo->share_attribute();

	return attribute_sharing_combo;
}

AttributeSharingCombo* Themeable::share_attribute_with_themeable(
	StatelessAttribute* from_stateless_attribute,
	StatelessAttribute* to_stateless_attribute,
	bool obtain_attribute)
{
	AttributeSharingCombo* attribute_sharing_combo = new AttributeSharingCombo(
		from_stateless_attribute, to_stateless_attribute);

	attribute_sharing_combos.append(attribute_sharing_combo);

	if (obtain_attribute)
	{
		attribute_sharing_combo->obtain_attribute(false);
	}
	else attribute_sharing_combo->share_attribute();

	return attribute_sharing_combo;
}

AttributeSharingCombo* Themeable::share_attribute_with_themeable(
	StatefulAttribute* from_stateful_attribute, QString from_state,
	StatelessAttribute* to_stateless_attribute,
	bool obtain_attribute)
{
	AttributeSharingCombo* attribute_sharing_combo = new AttributeSharingCombo(
		from_stateful_attribute, from_state, to_stateless_attribute);

	attribute_sharing_combos.append(attribute_sharing_combo);

	if (obtain_attribute)
	{
		attribute_sharing_combo->obtain_attribute(false);
	}
	else attribute_sharing_combo->share_attribute();

	return attribute_sharing_combo;
}

AttributeSharingCombo* Themeable::share_attribute_with_themeable(
	StatelessAttribute* from_stateless_attribute,
	StatefulAttribute* to_stateful_attribute, QString to_state,
	bool obtain_attribute)
{
	AttributeSharingCombo* attribute_sharing_combo = new AttributeSharingCombo(
		from_stateless_attribute, to_stateful_attribute, to_state);

	attribute_sharing_combos.append(attribute_sharing_combo);

	if (obtain_attribute)
	{
		attribute_sharing_combo->obtain_attribute(false);
	}
	else attribute_sharing_combo->share_attribute();

	return attribute_sharing_combo;
}

void Themeable::share_attributes()
{
	if (!m_shared_attributes)
	{
		m_shared_attributes = true;

		for (AttributeSharingCombo* attribute_sharing_combo : attribute_sharing_combos)
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
