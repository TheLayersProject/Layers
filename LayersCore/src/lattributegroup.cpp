#include <LayersCore/lattributegroup.h>

using Layers::LAttribute;
using Layers::LAttributeGroup;
using Layers::LBorderAttributes;
using Layers::LCornerRadiiAttributes;
using Layers::LMarginsAttributes;

LAttributeGroup::LAttributeGroup(const QString& name, bool disabled) :
	LAbstractAttribute(name, disabled) { }

LAttributeGroup::LAttributeGroup(const LAttributeGroup& attribute_group) :
	LAbstractAttribute(attribute_group.m_name, attribute_group.m_disabled)
{
	m_disabled = attribute_group.m_disabled;

	for (const QString& attr_key : attribute_group.m_attributes.keys())
		m_attributes[attr_key] =
			new LAttribute(*attribute_group.m_attributes[attr_key]);
}

LAttributeGroup::~LAttributeGroup()
{
	for (LAttribute* attr : m_attributes)
		delete attr;

	m_attributes.clear();
}

QMap<QString, LAttribute*>& LAttributeGroup::attributes()
{
	return m_attributes;
}

QMap<QString, LAttribute*>::iterator LAttributeGroup::begin()
{
	return m_attributes.begin();
}

void LAttributeGroup::copy(const LAttributeGroup& attribute_group)
{
	for (const QString& key : m_attributes.keys())
		m_attributes[key]->copy(
			*attribute_group.m_attributes[key]);

	m_disabled = attribute_group.m_disabled;
}

QMap<QString, LAttribute*>::iterator LAttributeGroup::end()
{
	return m_attributes.end();
}

void LAttributeGroup::entangle_with(LAttributeGroup& attribute_group)
{
	for (const QString& attr_key : m_attributes.keys())
		m_attributes[attr_key]->entangle_with(
			*attribute_group.m_attributes[attr_key]);
}

bool LAttributeGroup::is_multi_valued() const
{
	for (LAttribute* attribute : m_attributes)
		if (attribute->is_multi_valued())
			return true;

	return false;
}

void LAttributeGroup::set_state(const QString& state)
{
	for (LAttribute* attr : m_attributes)
		attr->set_state(state);
}

QJsonObject LAttributeGroup::to_json_object()
{
	QJsonObject json_object;

	if (m_disabled)
		json_object.insert("disabled", m_disabled);

	for (const QString& key : m_attributes.keys())
		json_object.insert(key, m_attributes[key]->to_json_object());

	return json_object;
}

LBorderAttributes::LBorderAttributes(const QString& name) :
	LAttributeGroup(name)
{
	m_attributes =
		QMap<QString, LAttribute*>({
			{ "fill", m_fill },
			{ "thickness", m_thickness }
		});
}

LAttribute* LBorderAttributes::fill() const
{
	return m_fill;
}

LAttribute* LBorderAttributes::thickness() const
{
	return m_thickness;
}

LCornerRadiiAttributes::LCornerRadiiAttributes(const QString& name) :
	LAttributeGroup(name)
{
	m_attributes =
		QMap<QString, LAttribute*>({
			{ "bottom_left", m_bottom_left },
			{ "bottom_right", m_bottom_right },
			{ "top_left", m_top_left },
			{ "top_right", m_top_right }
		});
}

LAttribute* LCornerRadiiAttributes::bottom_left() const
{
	return m_bottom_left;
}

LAttribute* LCornerRadiiAttributes::bottom_right() const
{
	return m_bottom_right;
}

LAttribute* LCornerRadiiAttributes::top_left() const
{
	return m_top_left;
}

LAttribute* LCornerRadiiAttributes::top_right() const
{
	return m_top_right;
}

LMarginsAttributes::LMarginsAttributes(const QString& name) :
	LAttributeGroup(name)
{
	m_attributes =
		QMap<QString, LAttribute*>({
			{ "bottom", m_bottom },
			{ "left", m_left },
			{ "right", m_right },
			{ "top", m_top }
		});
}

LAttribute* LMarginsAttributes::bottom() const
{
	return m_bottom;
}

LAttribute* LMarginsAttributes::left() const
{
	return m_left;
}

LAttribute* LMarginsAttributes::right() const
{
	return m_right;
}

LAttribute* LMarginsAttributes::top() const
{
	return m_top;
}