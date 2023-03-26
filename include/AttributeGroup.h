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
	class AttributeGroup : public AbstractAttribute
	{
		Q_OBJECT

	public:
		AttributeGroup();
		AttributeGroup(const QString& name, bool disabled = false);
		//AttributeGroup(const QString& name, const QMap<QString, Attribute*>& attributes, bool disabled = false);
		AttributeGroup(const AttributeGroup& ag);
		~AttributeGroup();

		/*!
			Returns a reference to the map of Attributes contained in the group.

			@returns Reference to map of Attributes
		*/
		QMap<QString, Attribute*>& attributes();

		QMap<QString, Attribute*>::iterator begin();

		/*!
			Copies the supplied AttributeGroup

			@param ag - AttributeGroup to copy
		*/
		void copy(const AttributeGroup& ag);

		QMap<QString, Attribute*>::iterator end();

		/*!
			Calls Attribute::entangle_with() on all group Attributes, passing the corresponding
			Attributes of attr_group matched by the Attribute names.

			@param attr_group - Group of Attributes to obtain Data pointers of
		*/
		void entangle_with(AttributeGroup& attr_group);

		/*!
			Returns true if stateful, otherwise, returns false.

			This function calls Attribute::is_multi_valued() on all the Attributes in the group. If any
			of them are stateful, the group is considered stateful as well.

			@returns True if stateful, false otherwise
		*/
		virtual bool is_multi_valued() const override;

		/*!
			Sets the active state of all the Attributes in the group.

			@param state - QString representing new active state
		*/
		virtual void set_state(const QString& state) override;

		//virtual void setup_widget_update_connection(QWidget* widget) override;

		/*!
			Returns AttributeGroup converted to a QJsonObject.

			@returns QJsonObject pertaining to the AttributeGroup
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