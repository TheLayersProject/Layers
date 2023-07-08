#include <Layers/lgradientcontrol.h>

#include <QMouseEvent>

#include <Layers/lapplication.h>
#include <Layers/lgradientdialog.h>

using Layers::LGradientControl;

LGradientControl::LGradientControl(QWidget* parent) : LWidget(parent)
{
	init_attributes();

	installEventFilter(this);
	setFixedSize(40, 40);
}

LGradientControl::~LGradientControl()
{
	delete  m_fill;
}

bool LGradientControl::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			LGradientDialog* gradient_dialog = layersApp->gradient_dialog();

			gradient_dialog->set_gradient_stops(fill()->as<QGradientStops>());

			if (gradient_dialog->exec())
			{
				fill()->set_value(QVariant::fromValue(gradient_dialog->gradient_stops()));

				emit gradient_changed();
			}

			gradient_dialog->hide();
		}
	}

	return false;
}

void LGradientControl::init_attributes()
{
	// Remove control attribute
	m_fill->setParent(nullptr);

	m_border_fill->set_value(QColor("#D6D6D6"));
	m_border_thickness->set_value(2.0);
	m_corner_radii_top_left->set_value(5.0);
	m_corner_radii_top_right->set_value(5.0);
	m_corner_radii_bottom_left->set_value(5.0);
	m_corner_radii_bottom_right->set_value(5.0);
	m_margins_left->set_value(8.0);
	m_margins_top->set_value(8.0);
	m_margins_right->set_value(8.0);
	m_margins_bottom->set_value(8.0);

	m_fill->set_value(
		QVariant::fromValue(
			QGradientStops({ { 0.0, Qt::white },{ 1.0, Qt::black } })));
}
