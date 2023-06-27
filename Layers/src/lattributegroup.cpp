#include <Layers/lattributegroup.h>

#include <QJsonObject>

using Layers::LAttribute;
using Layers::LAttributeGroup;
using Layers::LAttributeMap;
using Layers::LBorderAttributes;
using Layers::LCornerRadiiAttributes;
using Layers::LMarginsAttributes;

LAttributeGroup::LAttributeGroup(const QString& name) :
	m_name{ name },
	QObject() { }

LAttributeGroup::LAttributeGroup(const LAttributeGroup& attribute_group) :
	m_name{ attribute_group.m_name },
	QObject()
{
	for (const QString& key : attribute_group.m_attrs.keys())
		m_attrs[key] = new LAttribute(*attribute_group.m_attrs[key]);
}

LAttributeGroup::~LAttributeGroup()
{
	for (LAttribute* attr : m_attrs)
		delete attr;

	m_attrs.clear();
}

LAttributeMap& LAttributeGroup::attributes()
{
	return m_attrs;
}

LAttributeMap::iterator LAttributeGroup::begin()
{
	return m_attrs.begin();
}

bool LAttributeGroup::contains(LAttribute* attr) const
{
	for (LAttribute* group_attr : m_attrs)
		if (group_attr == attr)
			return true;

	return false;
}

void LAttributeGroup::copy(const LAttributeGroup& attribute_group)
{
	for (const QString& key : m_attrs.keys())
		m_attrs[key]->copy(*attribute_group.m_attrs[key]);
}

LAttributeMap::iterator LAttributeGroup::end()
{
	return m_attrs.end();
}

QStringList LAttributeGroup::keys() const
{
	return m_attrs.keys();
}

QString LAttributeGroup::name()
{
	return m_name;
}

LAttribute*& LAttributeGroup::operator[](const QString& key)
{
	return m_attrs[key];
}

QJsonObject LAttributeGroup::to_json_object()
{
	QJsonObject json_object;

	for (const QString& key : m_attrs.keys())
		json_object.insert(key, m_attrs[key]->to_json_object());

	return json_object;
}

LBorderAttributes::LBorderAttributes(const QString& name) :
	LAttributeGroup(name)
{
	m_attrs =
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
	m_attrs =
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
	m_attrs =
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