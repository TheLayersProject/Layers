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

	if (m_stateless_attribute)
		dlg.setCurrentColor(m_stateless_attribute->value().value<QColor>());

	else if (m_stateful_attribute)
		dlg.setCurrentColor(m_stateful_attribute->value(m_current_editting_state)->value<QColor>());

	else
		dlg.setCurrentColor(m_attribute_set.attribute_value("background_color")->value<QColor>());

	if (dlg.exec())
	{
		if (m_stateless_attribute)
			m_stateless_attribute->set_value(dlg.currentColor());

		else if (m_stateful_attribute)
			m_stateful_attribute->set_value(m_current_editting_state, dlg.currentColor());

		else
			set_stateless_attribute_value("background_color", dlg.currentColor());

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
	set_stateless_attribute_value("background_color", QColor(Qt::white));
	add_stateless_attribute("corner_radius", 5);
	add_stateless_attribute("outer_border_color", QColor("#2c2c2c"));
	add_stateless_attribute("inner_border_color", QColor("#d6d6d6"));
}

void ColorControl::set_attribute(Attribute* attribute)
{
	m_stateful_attribute = dynamic_cast<StatefulAttribute*>(attribute);
	m_stateless_attribute = dynamic_cast<StatelessAttribute*>(attribute);

	if (m_stateless_attribute)
	{
		connect(m_stateless_attribute, &Attribute::value_changed, [this]
			{
				set_stateless_attribute_value("background_color", m_stateless_attribute->value());
			});
	}
	else if (m_stateful_attribute)
	{
		m_attribute_states = m_stateful_attribute->states();

		m_current_editting_state = m_attribute_states.first();

		connect(m_stateful_attribute, &Attribute::value_changed, [this]
			{
				set_stateless_attribute_value("background_color", *m_stateful_attribute->value(m_current_editting_state));
			});
	}
}

void ColorControl::set_current_editting_state(const QString& state)
{
	if (m_attribute_states.contains(state) && m_current_editting_state != state)
	{
		m_current_editting_state = state;

		set_stateless_attribute_value("background_color", *m_stateful_attribute->value(m_current_editting_state));
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

void ColorControl::paintEvent(QPaintEvent* event)
{
    QPainterPath outer_border_path;
    QPainterPath inner_border_path;
    QPainterPath background_path;

    outer_border_path.addRoundedRect(QRectF(10, 10, 25, 25), m_attribute_set.attribute_value("corner_radius")->value<int>(), m_attribute_set.attribute_value("corner_radius")->value<int>());
    inner_border_path.addRoundedRect(QRectF(11, 11, 25 - 2, 25 - 2), m_attribute_set.attribute_value("corner_radius")->value<int>() - 1, m_attribute_set.attribute_value("corner_radius")->value<int>() - 1);
    background_path.addRoundedRect(QRectF(12, 12, 25 - 4, 25 - 4), m_attribute_set.attribute_value("corner_radius")->value<int>() - 1.5, m_attribute_set.attribute_value("corner_radius")->value<int>() - 1.5);

    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillPath(outer_border_path, m_attribute_set.attribute_value("outer_border_color")->value<QColor>());
    painter.fillPath(inner_border_path, m_attribute_set.attribute_value("inner_border_color")->value<QColor>());
    painter.fillPath(background_path, m_attribute_set.attribute_value("background_color")->value<QColor>());
    painter.end();
}
