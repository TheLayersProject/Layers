#ifndef LATTRIBUTEGROUP_H
#define LATTRIBUTEGROUP_H

#include <QColor>

#include "layers_global.h"
#include "layers_exports.h"

#include "lattribute.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LAttributeGroup is an LAbstractAttribute that creates a container for a
	group of LAttribute objects.

	The attributes are stored in a QMap of QString-LAttribute* pairs where the
	QString matches the name of the associated attribute.
*/
class LAYERS_EXPORT LAttributeGroup : public QObject
{
	Q_OBJECT

public:
	/*!
		Constructs an empty attribute group.
	*/
	LAttributeGroup(const QString& name);

	/*!
		Constructs a copy of *attribute_group*.
	*/
	LAttributeGroup(const LAttributeGroup& attribute_group);

	~LAttributeGroup();

	/*!
		Returns a reference to the map of attributes contained in the group.
	*/
	LAttributeMap& attributes();

	/*!
		Returns an iterator pointing to the first attribute in the group.
	*/
	LAttributeMap::iterator begin();

	bool contains(LAttribute* attr) const;

	/*!
		Copies the valuation of the attributes in *attribute_group* to the
		attributes in this group.
	*/
	void copy(const LAttributeGroup& attribute_group);

	/*!
		Returns an iterator pointing to the imaginary item after the last
		attribute in the group.
	*/
	LAttributeMap::iterator end();

	QStringList keys() const;

	/*!
		Returns the name of the attribute group.
	*/
	QString name();

	LAttribute*& operator[](const QString& key);

	/*!
		Returns attribute group represented as a QJsonObject.
	*/
	QJsonObject to_json_object();

protected:
	LAttributeMap m_attrs;

	QString m_name;
};

using LAttributeGroupMap = QMap<QString, LAttributeGroup*>;

class LAYERS_EXPORT LBorderAttributes : public LAttributeGroup
{
	Q_OBJECT

public:
	LBorderAttributes(const QString& name = "border");

	LAttribute* fill() const;

	LAttribute* thickness() const;

private:
	LAttribute* m_fill{ new LAttribute(
		"fill",
		QColor(Qt::gray)
		) };

	LAttribute* m_thickness{ new LAttribute(
		"thickness",
		QVariant::fromValue(0.0)
		) };
};

class LAYERS_EXPORT LCornerRadiiAttributes : public LAttributeGroup
{
	Q_OBJECT

public:
	LCornerRadiiAttributes(const QString& name = "corner_radii");

	LAttribute* bottom_left() const;

	LAttribute* bottom_right() const;

	LAttribute* top_left() const;

	LAttribute* top_right() const;

private:
	LAttribute* m_bottom_left{ new LAttribute(
		"bottom_left",
		QVariant::fromValue(0.0)
		) };

	LAttribute* m_bottom_right{ new LAttribute(
		"bottom_right",
		QVariant::fromValue(0.0)
		) };

	LAttribute* m_top_left{ new LAttribute(
		"top_left",
		QVariant::fromValue(0.0)
		) };

	LAttribute* m_top_right{ new LAttribute(
		"top_right",
		QVariant::fromValue(0.0)
		) };
};

class LAYERS_EXPORT LMarginsAttributes : public LAttributeGroup
{
	Q_OBJECT

public:
	LMarginsAttributes(const QString& name = "margins");

	LAttribute* bottom() const;

	LAttribute* left() const;

	LAttribute* right() const;

	LAttribute* top() const;

private:
	LAttribute* m_bottom{ new LAttribute(
		"bottom",
		QVariant::fromValue(0.0)
		) };

	LAttribute* m_left{ new LAttribute(
		"left",
		QVariant::fromValue(0.0)
		) };

	LAttribute* m_right{ new LAttribute(
		"right",
		QVariant::fromValue(0.0)
		) };

	LAttribute* m_top{ new LAttribute(
		"top",
		QVariant::fromValue(0.0)
		) };
};
LAYERS_NAMESPACE_END

#endif // LATTRIBUTEGROUP_H