#include "Layers.h"

using Layers::Gradient_Control;

Gradient_Control::Gradient_Control(QWidget* parent) : Widget(parent)
{
	init_attributes();

	installEventFilter(this);
	setFixedSize(45, 45);
}

void Gradient_Control::init_attributes()
{
    QGradientStops background_gradient_stops = { { 0.0, Qt::white },{ 1.0, Qt::black } };

	add_attribute("Default", "corner_radius", 5);
	add_attribute("Default", "outer_border_color", QColor("#2c2c2c"));
	add_attribute("Default", "inner_border_color", QColor("#d6d6d6"));

    set_attribute_value("Default", "background_gradient_stops", QVariant::fromValue(background_gradient_stops));
}

bool Gradient_Control::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			Gradient_Selection_Box gsb(attributes()["background_gradient_stops"].value().value<QGradientStops>());

			if (m_current_theme) gsb.apply_theme(*m_current_theme);

			static_cast<Window*>(QApplication::activeWindow())->center_dialog(&gsb);

			if (gsb.exec())
			{
				set_attribute_value("Default", "background_gradient_stops", QVariant::fromValue(gsb.gradient_stops()));

				emit gradient_changed();

				// Update widgets that is control shares its background with
				share_attributes();
			}
		}
	}

	return false;
}

void Gradient_Control::paintEvent(QPaintEvent* event)
{
	QPainterPath outer_border_path;
	QPainterPath inner_border_path;
	QPainterPath background_path;
	QLinearGradient background_gradient;

	outer_border_path.addRoundedRect(QRectF(10, 10, 25, 25), attributes()["corner_radius"].value().value<int>(), attributes()["corner_radius"].value().value<int>());
	inner_border_path.addRoundedRect(QRectF(11, 11, 25 - 2, 25 - 2), attributes()["corner_radius"].value().value<int>() - 1, attributes()["corner_radius"].value().value<int>() - 1);
	background_path.addRoundedRect(QRectF(12, 12, 25 - 4, 25 - 4), attributes()["corner_radius"].value().value<int>() - 1.5, attributes()["corner_radius"].value().value<int>() - 1.5);

	background_gradient.setStart(12, 12);
	background_gradient.setFinalStop(33, 12);
	background_gradient.setStops(attributes()["background_gradient_stops"].value().value<QGradientStops>());

	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.fillPath(outer_border_path, attributes()["outer_border_color"].value().value<QColor>());
	painter.fillPath(inner_border_path, attributes()["inner_border_color"].value().value<QColor>());
	painter.fillPath(background_path, background_gradient);
	painter.end();
}