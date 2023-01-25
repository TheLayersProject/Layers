#include "../../../include/AttributeGroup.h"

using Layers::Attribute;
using Layers::AttributeGroup;
using Layers::BorderAttributes;
using Layers::CornerRadiiAttributes;
using Layers::MarginsAttributes;

AttributeGroup::AttributeGroup(const QString& name, const QMap<QString, Attribute*>& attributes, bool disabled) :
	m_attributes { attributes }, AttributeType(name, disabled) { }

AttributeGroup::AttributeGroup() :
	m_attributes{ QMap<QString, Attribute*>() }, AttributeType("", false) { }

AttributeGroup::AttributeGroup(const AttributeGroup& ag) : AttributeType(ag.m_name, ag.m_disabled)
{
	m_disabled = ag.m_disabled;

	for (const QString& attr_key : ag.m_attributes.keys())
		m_attributes[attr_key] = new Attribute(*ag.m_attributes[attr_key]);
}

QMap<QString, Attribute*>& AttributeGroup::attributes()
{
	return m_attributes;
}

QMap<QString, Attribute*>::iterator AttributeGroup::begin()
{
	return m_attributes.begin();
}

void AttributeGroup::copy(const AttributeGroup& ag)
{
	for (const QString& attr_key : m_attributes.keys())
		m_attributes[attr_key]->copy(*ag.m_attributes[attr_key]);

	m_disabled = ag.m_disabled;
}

QMap<QString, Attribute*>::iterator AttributeGroup::end()
{
	return m_attributes.end();
}

void AttributeGroup::get_data_from(AttributeGroup& attr_group)
{
	for (const QString& attr_key : m_attributes.keys())
		m_attributes[attr_key]->get_data_from(*attr_group.m_attributes[attr_key]);
}

bool AttributeGroup::is_stateful() const
{
	for (Attribute* attribute : m_attributes)
		if (attribute->is_stateful())
			return true;

	return false;
}

void AttributeGroup::set_state(const QString& state)
{
	for (Attribute* attr : m_attributes)
		attr->set_state(state);
}

void AttributeGroup::setup_widget_update_connection(QWidget* widget)
{
	connect(this, &AttributeType::value_changed, [widget] { widget->update(); });

	for (Attribute* attr : m_attributes)
		attr->setup_widget_update_connection(widget);
}

QJsonObject AttributeGroup::to_json_object()
{
	QJsonObject json_object;

	if (m_disabled)
		json_object.insert("disabled", m_disabled);

	for (const QString& attr_key : m_attributes.keys())
		json_object.insert(attr_key, m_attributes[attr_key]->to_json_object());

	return json_object;
}

BorderAttributes::BorderAttributes(const QString& name) :
	AttributeGroup(name,
		QMap<QString, Attribute*>({
			{ "fill", &fill },
			{ "thickness", &thickness }
		})
	)
{

}

CornerRadiiAttributes::CornerRadiiAttributes(const QString& name) :
	AttributeGroup(name,
		QMap<QString, Attribute*>({
			{ "bottom_left", &bottom_left },
			{ "bottom_right", &bottom_right },
			{ "top_left", &top_left },
			{ "top_right", &top_right }
			})
	)
{
}

MarginsAttributes::MarginsAttributes(const QString& name) :
	AttributeGroup(name,
		QMap<QString, Attribute*>({
			{ "bottom", &bottom },
			{ "left", &left },
			{ "right", &right },
			{ "top", &top }
			})
	)
{
}
