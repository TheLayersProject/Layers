#include "GradientControl.h"

#include "Application.h"
#include "Window.h"

#include "Widgets/Dialogs/GradientDialog.h"

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
	// Remove control attribute
	m_attributes.remove("fill");

	m_border->fill()->set_value(QColor("#D6D6D6"));
	m_border->thickness()->set_value(2.0);
	m_corner_radii->top_left()->set_value(5.0);
	m_corner_radii->top_right()->set_value(5.0);
	m_corner_radii->bottom_left()->set_value(5.0);
	m_corner_radii->bottom_right()->set_value(5.0);
	m_margins->left()->set_value(10.0);
	m_margins->top()->set_value(10.0);
	m_margins->right()->set_value(10.0);
	m_margins->bottom()->set_value(10.0);

    m_fill->set_value(QVariant::fromValue(QGradientStops({ { 0.0, Qt::white },{ 1.0, Qt::black } })));
}

void GradientControl::set_current_editting_state(const QString& state)
{
	fill()->set_state(state);
}

bool GradientControl::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			//GradientDialog* gsd =
			//	new GradientDialog(fill()->as<QGradientStops>());

			//gsd->entangle_with(
			//	layersApp->main_window()->control_gradient_dialog());

			GradientDialog* gradient_dialog = layersApp->gradient_dialog();

			gradient_dialog->set_gradient_stops(fill()->as<QGradientStops>());
			

			//static_cast<Window*>(QApplication::activeWindow())->center_dialog(gsd);

			if (gradient_dialog->exec())
			{
				fill()->set_value(QVariant::fromValue(gradient_dialog->gradient_stops()));

				emit gradient_changed();
			}

			gradient_dialog->hide();

			//delete gsd;
		}
	}

	return false;
}
