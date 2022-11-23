#ifndef WIDGET_H
#define WIDGET_H

#include <QPainter>
#include <QWidget>

#include "Attribute.h"
#include "Themeable.h"

namespace Layers
{
	/*!
		The Widget class wraps a QWidget with a Themeable to give QWidgets compatibility with the Layers theme
		system. The Layers Widget class overrides the QWidget's paintEvent() and uses the attributes provided
		by the Themeable class to handle the widget's appearance.
	*/
	class Widget : public QWidget, public Themeable
	{
		Q_OBJECT

	public:
		Widget(QWidget* parent = nullptr);

		virtual void apply_theme_attributes(
			QMap<QString, Attribute*>& theme_attrs) override;

		void replace_all_attributes_with(Widget* widget);

		/*!
			Sets all margin attributes with one value.

			@param margin
		*/
		void set_margin(int margin);

		/*!
			Sets the margin attributes individually.

			@param left margin
			@param top margin
			@param right margin
			@param bottom margin
		*/
		void set_margin(int left, int top, int right, int bottom);

		Attribute a_border_fill {Attribute(
			"Border Fill",
			QColor(Qt::gray)
			) };

		Attribute a_border_thickness {Attribute(
			"Border Thickness",
			QVariant::fromValue(0)
			) };

		Attribute a_corner_color {Attribute(
			"Corner Color",
			QColor(Qt::gray),
			true
			) };

		Attribute a_corner_radius_tl {Attribute(
			"Top-Left Corner Radius",
			QVariant::fromValue(0)
			) };

		Attribute a_corner_radius_tr {Attribute(
			"Top-Right Corner Radius",
			QVariant::fromValue(0)
			) };

		Attribute a_corner_radius_bl {Attribute(
			"Bottom-Left Corner Radius",
			QVariant::fromValue(0)
			) };

		Attribute a_corner_radius_br {Attribute(
			"Bottom-Right Corner Radius",
			QVariant::fromValue(0)
			) };

		Attribute a_fill {Attribute(
			"Fill",
			QColor(Qt::white)
			) };

		Attribute a_hover_fill {Attribute(
			"Hover Fill",
			QColor(Qt::lightGray),
			true
			) };

		Attribute a_margin_left {Attribute(
			"Left Margin",
			QVariant::fromValue(0)
			) };

		Attribute a_margin_top {Attribute(
			"Top Margin",
			QVariant::fromValue(0)
			) };

		Attribute a_margin_right {Attribute(
			"Right Margin",
			QVariant::fromValue(0)
			) };

		Attribute a_margin_bottom {Attribute(
			"Bottom Margin",
			QVariant::fromValue(0)
			) };

		Attribute a_outline_color {Attribute(
			"Outline Color",
			QColor(Qt::gray),
			true
			) };

	protected:
		/*!
			Overrides the QWidget::eventFilter() to handle widget hover coloring
		*/
		bool eventFilter(QObject* object, QEvent* event) override;

		/*!
			Initializes the widget's attributes.

			This function uses calls to set_attribute_value() to define attributes.

			Widget attributes include background color/gradient, corner radii, margins, outline color, and
			other varius numerical values, colors, and booleans.
		*/
		void init_attributes();

		/*!
			Paints the widget with values obtained from the widget's attributes.
		*/
		void paintEvent(QPaintEvent* event) override;

		AttributeGroup ag_border{ AttributeGroup("Border", {
			{ "border_fill", &a_border_fill },
			{ "border_thickness", &a_border_thickness }
			}) };

		AttributeGroup ag_corner_radii{ AttributeGroup("Corner Radii", {
			{ "corner_radius_tl", &a_corner_radius_tl },
			{ "corner_radius_tr", &a_corner_radius_tr },
			{ "corner_radius_bl", &a_corner_radius_bl },
			{ "corner_radius_br", &a_corner_radius_br }
			}) };

		AttributeGroup ag_margins{ AttributeGroup("Margins", {
			{ "margin_left", &a_margin_left },
			{ "margin_top", &a_margin_top },
			{ "margin_right", &a_margin_right },
			{ "margin_bottom", &a_margin_bottom }
			}) };

		bool m_hovering{ false };

		QPainter painter;
	};
}

#endif // WIDGET_H  
