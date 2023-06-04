#include "AttributeGroup.h"

using Layers::Attribute;
using Layers::AttributeGroup;
using Layers::BorderAttributes;
using Layers::CornerRadiiAttributes;
using Layers::MarginsAttributes;

AttributeGroup::AttributeGroup(const QString& name, bool disabled) :
	AbstractAttribute(name, disabled) { }

AttributeGroup::AttributeGroup(const AttributeGroup& attribute_group) :
	AbstractAttribute(attribute_group.m_name, attribute_group.m_disabled)
{
	m_disabled = attribute_group.m_disabled;

	for (const QString& attr_key : attribute_group.m_attributes.keys())
		m_attributes[attr_key] =
			new Attribute(*attribute_group.m_attributes[attr_key]);
}

AttributeGroup::~AttributeGroup()
{
	for (Attribute* attr : m_attributes)
		delete attr;

	m_attributes.clear();
}

QMap<QString, Attribute*>& AttributeGroup::attributes()
{
	return m_attributes;
}

QMap<QString, Attribute*>::iterator AttributeGroup::begin()
{
	return m_attributes.begin();
}

void AttributeGroup::copy(const AttributeGroup& attribute_group)
{
	for (const QString& key : m_attributes.keys())
		m_attributes[key]->copy(
			*attribute_group.m_attributes[key]);

	m_disabled = attribute_group.m_disabled;
}

QMap<QString, Attribute*>::iterator AttributeGroup::end()
{
	return m_attributes.end();
}

void AttributeGroup::entangle_with(AttributeGroup& attribute_group)
{
	for (const QString& attr_key : m_attributes.keys())
		m_attributes[attr_key]->entangle_with(
			*attribute_group.m_attributes[attr_key]);
}

bool AttributeGroup::is_multi_valued() const
{
	for (Attribute* attribute : m_attributes)
		if (attribute->is_multi_valued())
			return true;

	return false;
}

void AttributeGroup::set_state(const QString& state)
{
	for (Attribute* attr : m_attributes)
		attr->set_state(state);
}

QJsonObject AttributeGroup::to_json_object()
{
	QJsonObject json_object;

	if (m_disabled)
		json_object.insert("disabled", m_disabled);

	for (const QString& key : m_attributes.keys())
		json_object.insert(key, m_attributes[key]->to_json_object());

	return json_object;
}

BorderAttributes::BorderAttributes(const QString& name) :
	AttributeGroup(name)
{
	m_attributes =
		QMap<QString, Attribute*>({
			{ "fill", m_fill },
			{ "thickness", m_thickness }
		});
}

Attribute* BorderAttributes::fill() const
{
	return m_fill;
}

Attribute* BorderAttributes::thickness() const
{
	return m_thickness;
}

CornerRadiiAttributes::CornerRadiiAttributes(const QString& name) :
	AttributeGroup(name)
{
	m_attributes =
		QMap<QString, Attribute*>({
			{ "bottom_left", m_bottom_left },
			{ "bottom_right", m_bottom_right },
			{ "top_left", m_top_left },
			{ "top_right", m_top_right }
		});
}

Attribute* CornerRadiiAttributes::bottom_left() const
{
	return m_bottom_left;
}

Attribute* CornerRadiiAttributes::bottom_right() const
{
	return m_bottom_right;
}

Attribute* CornerRadiiAttributes::top_left() const
{
	return m_top_left;
}

Attribute* CornerRadiiAttributes::top_right() const
{
	return m_top_right;
}

MarginsAttributes::MarginsAttributes(const QString& name) :
	AttributeGroup(name)
{
	m_attributes =
		QMap<QString, Attribute*>({
			{ "bottom", m_bottom },
			{ "left", m_left },
			{ "right", m_right },
			{ "top", m_top }
		});
}

Attribute* MarginsAttributes::bottom() const
{
	return m_bottom;
}

Attribute* MarginsAttributes::left() const
{
	return m_left;
}

Attribute* MarginsAttributes::right() const
{
	return m_right;
}

Attribute* MarginsAttributes::top() const
{
	return m_top;
}