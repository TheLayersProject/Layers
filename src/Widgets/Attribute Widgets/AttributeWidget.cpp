#include "../../../include/AttributeWidgets.h"

using Layers::AttributeWidget;

AttributeWidget::AttributeWidget(QWidget* parent) : Widget(parent)
{
	init_attributes();

	set_name("attribute_widget");
}

void AttributeWidget::set_current_editting_state(const QString& state)
{
}

void AttributeWidget::init_attributes()
{
	a_fill.set_value(QColor("#1A000000")); // Black with 10% opacity
	a_corner_radius_tl.set_value(10);
	a_corner_radius_tr.set_value(10);
	a_corner_radius_bl.set_value(10);
	a_corner_radius_br.set_value(10);
}
