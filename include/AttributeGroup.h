#ifndef ATTRIBUTEGROUP_H
#define ATTRIBUTEGROUP_H

#include "Attribute.h"

namespace Layers
{
	/*!
		Implements a container used to define a group of Attributes.

		The Attributes are stored in a QMap of QString-Attribute* pairs where the QString matches
		the name of the associated Attribute.

		A group of Attributes is stateful if a single Attribute in the group is stateful.
	*/
	class AttributeGroup : public AttributeType
	{
		Q_OBJECT

	public:
		AttributeGroup();
		AttributeGroup(const QString& name, const QMap<QString, Attribute*>& attributes, bool disabled = false);
		AttributeGroup(const AttributeGroup& ag);

		/*!
			Returns a reference to the map of Attributes contained in the group.

			@returns Reference to map of Attributes
		*/
		QMap<QString, Attribute*>& attributes();

		/*!
			Copies the supplied AttributeGroup

			@param ag - AttributeGroup to copy
		*/
		void copy(const AttributeGroup& ag);

		/*!
			Calls Attribute::get_data_from() on all group Attributes, passing the corresponding
			Attributes of attr_group matched by the Attribute names.

			@param attr_group - Group of Attributes to obtain Data pointers of
		*/
		void get_data_from(AttributeGroup& attr_group);

		/*!
			Returns true if stateful, otherwise, returns false.

			This function calls Attribute::is_stateful() on all the Attributes in the group. If any
			of them are stateful, the group is considered stateful as well.

			@returns True if stateful, false otherwise
		*/
		virtual bool is_stateful() const override;

		/*!
			Sets the active state of all the Attributes in the group.

			@param state - QString representing new active state
		*/
		virtual void set_state(const QString& state) override;

		/*!
			Returns AttributeGroup converted to a QJsonObject.

			@returns QJsonObject pertaining to the AttributeGroup
		*/
		QJsonObject to_json_object();

	private:
		QMap<QString, Attribute*> m_attributes;
	};

	class BorderAttributes : public AttributeGroup
	{
		Q_OBJECT

	public:
		BorderAttributes(const QString& name = "border");

		Attribute fill{ Attribute(
			"fill",
			QColor(Qt::gray)
			) };

		Attribute thickness{ Attribute(
			"thickness",
			QVariant::fromValue(0.0)
			) };
	};

	class CornerRadiiAttributes : public AttributeGroup
	{
		Q_OBJECT

	public:
		CornerRadiiAttributes(const QString& name = "corner_radii");

		Attribute bottom_left{ Attribute(
			"bottom_left",
			QVariant::fromValue(0.0)
			) };

		Attribute bottom_right{ Attribute(
			"bottom_right",
			QVariant::fromValue(0.0)
			) };

		Attribute top_left{ Attribute(
			"top_left",
			QVariant::fromValue(0.0)
			) };

		Attribute top_right{ Attribute(
			"top_right",
			QVariant::fromValue(0.0)
			) };
	};

	class MarginsAttributes : public AttributeGroup
	{
		Q_OBJECT

	public:
		MarginsAttributes(const QString& name = "margins");

		Attribute left{ Attribute(
			"left",
			QVariant::fromValue(0.0)
			) };

		Attribute top{ Attribute(
			"top",
			QVariant::fromValue(0.0)
			) };

		Attribute right{ Attribute(
			"right",
			QVariant::fromValue(0.0)
			) };

		Attribute bottom{ Attribute(
			"bottom",
			QVariant::fromValue(0.0)
			) };
	};
}

#endif // ATTRIBUTEGROUP_H