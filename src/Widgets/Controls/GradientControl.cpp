#include "../../../include/GradientControl.h"
#include "../../../include/GradientSelectionDialog.h"
#include "../../../include/Window.h"

#include <QApplication>
#include <QMouseEvent>
#include <QPainterPath>

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

	add_attribute("corner_radius", 5);
	add_attribute("outer_border_color", QColor("#2c2c2c"));
	add_attribute("inner_border_color", QColor("#d6d6d6"));

    set_attribute_value("background_gradient_stops", QVariant::fromValue(background_gradient_stops));
}

void GradientControl::set_attribute(Attribute* attribute)
{
	m_attribute = attribute;

	if (m_attribute)
	{
		bool attr_is_stateful = !m_attribute->states().isEmpty();

		if (attr_is_stateful)
		{
			m_attribute_states = m_attribute->states();

			m_current_editting_state = m_attribute_states.first();
		}

		connect(m_attribute, &Attribute::value_changed, [this, attr_is_stateful]
			{
				if (!attr_is_stateful)
					set_attribute_value("background_gradient_stops", m_attribute->value());
				else
					set_attribute_value("background_gradient_stops", *m_attribute->value(m_current_editting_state));
			});
	}
}

void GradientControl::set_current_editting_state(const QString& state)
{
	if (m_attribute_states.contains(state) && m_current_editting_state != state)
	{
		m_current_editting_state = state;

		set_attribute_value("background_gradient_stops", *m_attribute->value(m_current_editting_state));
	}
}

bool GradientControl::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			GradientSelectionDialog* gsd;

			bool attr_is_stateful = !m_attribute->states().isEmpty();

			if (attr_is_stateful)
				gsd = new GradientSelectionDialog(m_attribute_set.attribute("background_gradient_stops")->value().value<QGradientStops>());

			else
				gsd = new GradientSelectionDialog(m_attribute_set.attribute("background_gradient_stops")->value(m_current_editting_state)->value<QGradientStops>());

			if (m_current_theme) gsd->apply_theme(*m_current_theme);

			static_cast<Window*>(QApplication::activeWindow())->center_dialog(gsd);

			if (gsd->exec())
			{
				if (attr_is_stateful)
					m_attribute->set_value(QVariant::fromValue(gsd->gradient_stops()));

				else
					m_attribute->set_value(m_current_editting_state, QVariant::fromValue(gsd->gradient_stops()));

				emit gradient_changed();
			}

			delete gsd;
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