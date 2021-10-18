#include "Layers.h"

using Layers::GradientControl;

GradientControl::GradientControl(QWidget* parent) : Widget(parent)
{
	init_attributes();

	installEventFilter(this);
	setFixedSize(45, 45);
}

void GradientControl::init_attributes()
{
    QGradientStops background_gradient_stops = { { 0.0, Qt::white },{ 1.0, Qt::black } };

	add_stateless_attribute("corner_radius", 5);
	add_stateless_attribute("outer_border_color", QColor("#2c2c2c"));
	add_stateless_attribute("inner_border_color", QColor("#d6d6d6"));

    set_stateless_attribute_value("background_gradient_stops", QVariant::fromValue(background_gradient_stops));
}

bool GradientControl::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			GradientSelectionBox gsb(m_attribute_set.attribute_value("background_gradient_stops")->value<QGradientStops>());

			if (m_current_theme) gsb.apply_theme(*m_current_theme);

			static_cast<Window*>(QApplication::activeWindow())->center_dialog(&gsb);

			if (gsb.exec())
			{
				set_stateless_attribute_value("background_gradient_stops", QVariant::fromValue(gsb.gradient_stops()));

				emit gradient_changed();

				// Update widgets that is control shares its background with
				share_attributes();
			}
		}
	}

	return false;
}

void GradientControl::paintEvent(QPaintEvent* event)
{
	QPainterPath outer_border_path;
	QPainterPath inner_border_path;
	QPainterPath background_path;
	QLinearGradient background_gradient;

	outer_border_path.addRoundedRect(QRectF(10, 10, 25, 25), m_attribute_set.attribute_value("corner_radius")->value<int>(), m_attribute_set.attribute_value("corner_radius")->value<int>());
	inner_border_path.addRoundedRect(QRectF(11, 11, 25 - 2, 25 - 2), m_attribute_set.attribute_value("corner_radius")->value<int>() - 1, m_attribute_set.attribute_value("corner_radius")->value<int>() - 1);
	background_path.addRoundedRect(QRectF(12, 12, 25 - 4, 25 - 4), m_attribute_set.attribute_value("corner_radius")->value<int>() - 1.5, m_attribute_set.attribute_value("corner_radius")->value<int>() - 1.5);

	background_gradient.setStart(12, 12);
	background_gradient.setFinalStop(33, 12);
	background_gradient.setStops(m_attribute_set.attribute_value("background_gradient_stops")->value<QGradientStops>());

	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.fillPath(outer_border_path, m_attribute_set.attribute_value("outer_border_color")->value<QColor>());
	painter.fillPath(inner_border_path, m_attribute_set.attribute_value("inner_border_color")->value<QColor>());
	painter.fillPath(background_path, background_gradient);
	painter.end();
}