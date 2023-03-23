#include "Application.h"
#include "ColorControl.h"
#include "GradientControl.h"
#include "Window.h"

#include "Widgets/Dialogs/ColorDialog.h"

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

ColorControl::~ColorControl()
{
	disconnect(attribute_connection);
}

void ColorControl::click()
{
	ColorDialog* color_dialog = layersApp->color_dialog();

	//color_dialog->entangle_with(
	//	layersApp->main_window()->control_color_dialog());

	color_dialog->color()->set_value(fill()->as<QColor>());

	if (color_dialog->exec())
	{
		fill()->set_value(color_dialog->color()->as<QColor>());

		emit color_changed();
	}

	color_dialog->hide();

	open_on_release = false;
}

void ColorControl::disable_clicking(bool cond)
{
	clicking_disabled = cond;
}

void ColorControl::init_attributes()
{
	// Remove control attribute
	m_entities.remove("fill");

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
	m_outline_color->set_disabled(false);
}

void ColorControl::set_current_editting_state(const QString& state)
{
	m_fill->set_state(state);
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
