#include "../../../include/ColorControl.h"

#include <QColorDialog>
#include <QMouseEvent>
#include <QPainterPath>

using Layers::ColorControl;

ColorControl::ColorControl(QWidget* parent) : Widget(parent)
{
	init_attributes();

    setFixedSize(45, 45);
	installEventFilter(this);
}

ColorControl::~ColorControl()
{
	disconnect(attribute_connection);
}

void ColorControl::click()
{
	QColorDialog dlg;

	dlg.setCurrentColor(a_fill.as<QColor>());

	if (dlg.exec())
	{
		if (a_fill.is_stateful())
			a_fill.set_value(a_fill.state(), dlg.currentColor());
		else
			a_fill.set_value(dlg.currentColor());

		emit color_changed();
	}

	open_on_release = false;
}

void ColorControl::disable_clicking(bool cond)
{
	clicking_disabled = cond;
}

void ColorControl::init_attributes()
{
	a_border_fill.set_value(QColor("#D6D6D6"));
	a_border_thickness.set_value(2);
	a_corner_radius_tl.set_value(5);
	a_corner_radius_tr.set_value(5);
	a_corner_radius_bl.set_value(5);
	a_corner_radius_br.set_value(5);
	a_margin_left.set_value(10);
	a_margin_top.set_value(10);
	a_margin_right.set_value(10);
	a_margin_bottom.set_value(10);
	a_outline_color.set_disabled(false);
}

void ColorControl::set_current_editting_state(const QString& state)
{
	a_fill.set_state(state);
}

bool ColorControl::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			open_on_release = true;
		}
	}
	else if (event->type() == QEvent::MouseButtonRelease && open_on_release && !clicking_disabled)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			click();
		}
	}
	else if (open_on_release && event->type() == QEvent::MouseMove)
	{
		open_on_release = false;
	}

    return false;
}
