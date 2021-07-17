#include "Layers.h"

using Layers::Color_Control;

Color_Control::Color_Control(QWidget* parent) : Widget(parent)
{
	init_attributes();

    setFixedSize(45, 45);
	installEventFilter(this);
}

void Color_Control::click()
{
	QColorDialog dlg;

	dlg.setCurrentColor(attributes()["background_color"].value().value<QColor>());

	if (dlg.exec())
	{
		set_attribute_value("background_color", dlg.currentColor());

		emit color_changed();

		share_attributes();
	}

	open_on_release = false;
}

void Layers::Color_Control::disable_clicking(bool cond)
{
	clicking_disabled = cond;
}

void Color_Control::init_attributes()
{
    set_attribute_value("background_color", QColor(Qt::white));
	add_attribute("corner_radius", 5);
	add_attribute("outer_border_color", QColor("#2c2c2c"));
	add_attribute("inner_border_color", QColor("#d6d6d6"));
}

bool Color_Control::eventFilter(QObject* object, QEvent* event)
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

void Color_Control::paintEvent(QPaintEvent* event)
{
    QPainterPath outer_border_path;
    QPainterPath inner_border_path;
    QPainterPath background_path;

    outer_border_path.addRoundedRect(QRectF(10, 10, 25, 25), attributes()["corner_radius"].value().value<int>(), attributes()["corner_radius"].value().value<int>());
    inner_border_path.addRoundedRect(QRectF(11, 11, 25 - 2, 25 - 2), attributes()["corner_radius"].value().value<int>() - 1, attributes()["corner_radius"].value().value<int>() - 1);
    background_path.addRoundedRect(QRectF(12, 12, 25 - 4, 25 - 4), attributes()["corner_radius"].value().value<int>() - 1.5, attributes()["corner_radius"].value().value<int>() - 1.5);

    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillPath(outer_border_path, attributes()["outer_border_color"].value().value<QColor>());
    painter.fillPath(inner_border_path, attributes()["inner_border_color"].value().value<QColor>());
    painter.fillPath(background_path, attributes()["background_color"].value().value<QColor>());
    painter.end();
}
