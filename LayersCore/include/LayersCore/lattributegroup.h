#ifndef LATTRIBUTEGROUP_H
#define LATTRIBUTEGROUP_H

#include "layerscoreexports.h"

#include "lattribute.h"

namespace Layers
{
	/*!
		An LAttributeGroup is an implementation of LAbstractAttribute that creates
		a container for a group of LAttribute objects.

		The attributes are stored in a QMap of QString-LAttribute* pairs where
		the QString matches the name of the associated attribute.
	*/
	class LAYERS_CORE_EXPORT LAttributeGroup : public LAbstractAttribute
	{
		Q_OBJECT

	public:
		/*!
			Constructs an empty attribute group.
		*/
		LAttributeGroup(const QString& name, bool disabled = false);

		/*!
			Constructs a copy of *attribute_group*.
		*/
		LAttributeGroup(const LAttributeGroup& attribute_group);

		~LAttributeGroup();

		/*!
			Returns a reference to the map of attributes contained in the
			group.
		*/
		QMap<QString, LAttribute*>& attributes();

		/*!
			Returns an iterator pointing to the first attribute in the group.
		*/
		QMap<QString, LAttribute*>::iterator begin();

		/*!
			Copies the valuation of the attributes in *attribute_group* to the
			attributes in this group.
		*/
		void copy(const LAttributeGroup& attribute_group);

		/*!
			Returns an iterator pointing to the imaginary item after the last
			attribute in the group.
		*/
		QMap<QString, LAttribute*>::iterator end();

		/*!
			Entangles the attributes in this group with the attributes in
			*attribute_group*.
		*/
		void entangle_with(LAttributeGroup& attribute_group);

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
		QMap<QString, LAttribute*> m_attributes;
	};

	class LAYERS_CORE_EXPORT LBorderAttributes : public LAttributeGroup
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

	class LAYERS_CORE_EXPORT LCornerRadiiAttributes : public LAttributeGroup
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

	class LAYERS_CORE_EXPORT LMarginsAttributes : public LAttributeGroup
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
}

#endif // LATTRIBUTEGROUP_H