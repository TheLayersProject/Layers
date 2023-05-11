#ifndef ATTRIBUTEGROUP_H
#define ATTRIBUTEGROUP_H

#include "Attribute.h"

namespace Layers
{
	/*!
		An AttributeGroup is an implementaion of AbstractAttribute that creates
		a container for a group of Attribute objects.

		The attributes are stored in a QMap of QString-Attribute* pairs where
		the QString matches the name of the associated attribute.
	*/
	class AttributeGroup : public AbstractAttribute
	{
		Q_OBJECT

	public:
		/*!
			Constructs an empty AttributeGroup.
		*/
		AttributeGroup(const QString& name, bool disabled = false);

		/*!
			Constructs a copy of *attribute_group*.
		*/
		AttributeGroup(const AttributeGroup& attribute_group);

		~AttributeGroup();

		/*!
			Returns a reference to the map of attributes contained in the
			group.
		*/
		QMap<QString, Attribute*>& attributes();

		/*!
			Returns an iterator pointing to the first attribute in the group.
		*/
		QMap<QString, Attribute*>::iterator begin();

		/*!
			Copies the valuation of the attributes in *attribute_group* to the
			attributes in this group.
		*/
		void copy(const AttributeGroup& attribute_group);

		/*!
			Returns an iterator pointing to the imaginary item after the last
			attribute in the group.
		*/
		QMap<QString, Attribute*>::iterator end();

		/*!
			Entangles the attributes in this group with the attributes in
			*attribute_group*.
		*/
		void entangle_with(AttributeGroup& attribute_group);

		/*!
			Returns true if any of the attributes in this group are
			multi-valued. Otherwise, returns false.
		*/
		virtual bool is_multi_valued() const override;

		/*!
			Sets the active state of all the attributes in this group.
		*/
		virtual void set_state(const QString& state) override;

		/*!
			Returns attribute group represented as a QJsonObject.
		*/
		QJsonObject to_json_object();

	protected:
		QMap<QString, Attribute*> m_attributes;
	};

	class BorderAttributes : public AttributeGroup
	{
		Q_OBJECT

	public:
		BorderAttributes(const QString& name = "border");

		Attribute* fill() const;

		Attribute* thickness() const;

	private:
		Attribute* m_fill{ new Attribute(
			"fill",
			QColor(Qt::gray)
			) };

		Attribute* m_thickness{ new Attribute(
			"thickness",
			QVariant::fromValue(0.0)
			) };
	};

	class CornerRadiiAttributes : public AttributeGroup
	{
		Q_OBJECT

	public:
		CornerRadiiAttributes(const QString& name = "corner_radii");

		Attribute* bottom_left() const;

		Attribute* bottom_right() const;

		Attribute* top_left() const;

		Attribute* top_right() const;

	private:
		Attribute* m_bottom_left{ new Attribute(
			"bottom_left",
			QVariant::fromValue(0.0)
			) };

		Attribute* m_bottom_right{ new Attribute(
			"bottom_right",
			QVariant::fromValue(0.0)
			) };

		Attribute* m_top_left{ new Attribute(
			"top_left",
			QVariant::fromValue(0.0)
			) };

		Attribute* m_top_right{ new Attribute(
			"top_right",
			QVariant::fromValue(0.0)
			) };
	};

	class MarginsAttributes : public AttributeGroup
	{
		Q_OBJECT

	public:
		MarginsAttributes(const QString& name = "margins");

		Attribute* bottom() const;

		Attribute* left() const;

		Attribute* right() const;

		Attribute* top() const;

	private:
		Attribute* m_bottom{ new Attribute(
			"bottom",
			QVariant::fromValue(0.0)
			) };

		Attribute* m_left{ new Attribute(
			"left",
			QVariant::fromValue(0.0)
			) };

		Attribute* m_right{ new Attribute(
			"right",
			QVariant::fromValue(0.0)
			) };

		Attribute* m_top{ new Attribute(
			"top",
			QVariant::fromValue(0.0)
			) };
	};
}

#endif // ATTRIBUTEGROUP_H