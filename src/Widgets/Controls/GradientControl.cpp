#include "../../../include/GradientControl.h"
#include "../../../include/GradientSelectionDialog.h"
#include "../../../include/Window.h"

//#include <QApplication>
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

    a_fill.set_value(QVariant::fromValue(QGradientStops({ { 0.0, Qt::white },{ 1.0, Qt::black } })));
}

void GradientControl::set_attribute(Attribute* attribute)
{
	m_attribute = attribute;

	connect(m_attribute, &Attribute::value_changed, [this]
		{
			a_fill.copy_values_from(*m_attribute);
		});
}

bool GradientControl::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			GradientSelectionDialog* gsd;

			gsd = new GradientSelectionDialog(a_fill.value<QGradientStops>());

			if (m_current_theme) gsd->apply_theme(*m_current_theme);

			//static_cast<Window*>(QApplication::activeWindow())->center_dialog(gsd);

			if (gsd->exec())
			{
				m_attribute->set_value(QVariant::fromValue(gsd->gradient_stops()));

				emit gradient_changed();
			}

			delete gsd;
		}
	}

	return false;
}
