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

void ColorControl::click()
{
	QColorDialog dlg;

	if (m_attribute)
	{
		if (!m_attribute->values())
			dlg.setCurrentColor(m_attribute->value<QColor>());
		else
			dlg.setCurrentColor(*m_attribute->value<QColor>("m_current_editting_state"));
	}
	else
		dlg.setCurrentColor(a_fill.value<QColor>());

	if (dlg.exec())
	{
		if (m_attribute)
		{
			if (!m_attribute->values())
				m_attribute->set_value(dlg.currentColor());
			else
				m_attribute->set_value(m_current_editting_state, dlg.currentColor());
		}
		else
			a_fill.set_value(dlg.currentColor());

		emit color_changed();
	}

	open_on_release = false;
}

void Layers::ColorControl::disable_clicking(bool cond)
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

	//add_attribute("corner_radius", 5);
	//add_attribute("outer_border_color", QColor("#2c2c2c"));
	//add_attribute("inner_border_color", QColor("#d6d6d6"));
}

void ColorControl::set_attribute(Attribute* attribute)
{
	m_attribute = attribute;

	if (!m_attribute->states().isEmpty())
	{
		m_attribute_states = m_attribute->states();

		m_current_editting_state = m_attribute_states.first();
	}

	connect(m_attribute, &Attribute::value_changed, [this]
		{
			if (m_attribute->states().isEmpty())
				a_fill.set_value(m_attribute->value<QColor>());
			else
				a_fill.set_value(*m_attribute->value<QColor>(m_current_editting_state));
		});
}

void ColorControl::set_current_editting_state(const QString& state)
{
	if (m_attribute_states.contains(state) && m_current_editting_state != state)
	{
		m_current_editting_state = state;

		a_fill.set_value(*m_attribute->value<QColor>(m_current_editting_state));
	}
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

//void ColorControl::paintEvent(QPaintEvent* event)
//{
//    QPainterPath outer_border_path;
//    QPainterPath inner_border_path;
//    QPainterPath background_path;
//
//	int corner_radii = a_corner_radii.value<int>();
//
//    outer_border_path.addRoundedRect(QRectF(10, 10, 25, 25), corner_radii, corner_radii);
//    inner_border_path.addRoundedRect(QRectF(11, 11, 25 - 2, 25 - 2), corner_radii - 1, corner_radii - 1);
//    background_path.addRoundedRect(QRectF(12, 12, 25 - 4, 25 - 4), corner_radii - 1.5, corner_radii - 1.5);
//
//    painter.begin(this);
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.fillPath(outer_border_path, a_outer_border_color.value<QColor>());
//    painter.fillPath(inner_border_path, a_inner_border_color.value<QColor>());
//    painter.fillPath(background_path, a_fill.value<QColor>());
//    painter.end();
//}
