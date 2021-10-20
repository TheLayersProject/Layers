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

	dlg.setCurrentColor(m_attribute_set.attribute_value("background_color")->value<QColor>());

	if (dlg.exec())
	{
		set_stateless_attribute_value("background_color", dlg.currentColor());

		emit color_changed();

		share_attributes();
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
