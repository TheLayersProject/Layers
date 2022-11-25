#include "../../../include/Application.h"
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
	// Remove control attribute
	m_attributes.remove("fill");

	a_border_fill.set_value(QColor("#D6D6D6"));
	a_border_thickness.set_value(2.0);
	a_corner_radius_tl.set_value(5.0);
	a_corner_radius_tr.set_value(5.0);
	a_corner_radius_bl.set_value(5.0);
	a_corner_radius_br.set_value(5.0);
	a_margin_left.set_value(10.0);
	a_margin_top.set_value(10.0);
	a_margin_right.set_value(10.0);
	a_margin_bottom.set_value(10.0);
	a_outline_color.set_disabled(false);

    a_fill.set_value(QVariant::fromValue(QGradientStops({ { 0.0, Qt::white },{ 1.0, Qt::black } })));
}

void GradientControl::set_current_editting_state(const QString& state)
{
	a_fill.set_state(state);
}

bool GradientControl::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			GradientSelectionDialog* gsd;

			gsd = new GradientSelectionDialog(a_fill.as<QGradientStops>());
			gsd->assign_tag_prefixes();

			gsd->replace_all_attributes_with(
				static_cast<Window*>(
					layersApp->main_window()->customize_menu()->preview_widget()
				)->control_gradient_selection_dialog()
			);
			

			//static_cast<Window*>(QApplication::activeWindow())->center_dialog(gsd);

			if (gsd->exec())
			{
				if (a_fill.is_stateful())
					a_fill.set_value(a_fill.state(), QVariant::fromValue(gsd->gradient_stops()));
				else
					a_fill.set_value(QVariant::fromValue(gsd->gradient_stops()));

				emit gradient_changed();
			}

			delete gsd;
		}
	}

	return false;
}
