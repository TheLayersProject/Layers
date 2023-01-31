#include "../../../include/FillControl.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPainterPath>
#include <QVBoxLayout>

using Layers::FillControl;

FillControl::FillControl(QWidget* parent) : Widget(parent)
{
	init_attributes();

	installEventFilter(this);
	setFixedSize(45, 45);
	set_name("fill_control");
	set_proper_name("Fill Control");

	m_control_dialog->hide();

	m_dialog->entangle_with(m_control_dialog);
}

FillControl::~FillControl()
{
	// TODO: Maybe the dialog should just be generated when it is needed
	m_control_dialog->deleteLater();
	m_dialog->deleteLater();
}

void FillControl::init_attributes()
{
	// Remove control attribute
	m_entities.remove("fill");

	border.fill.set_value(QColor("#D6D6D6"));
	border.thickness.set_value(2.0);
	corner_radii.top_left.set_value(5.0);
	corner_radii.top_right.set_value(5.0);
	corner_radii.bottom_left.set_value(5.0);
	corner_radii.bottom_right.set_value(5.0);
	margins.left.set_value(10.0);
	margins.top.set_value(10.0);
	margins.right.set_value(10.0);
	margins.bottom.set_value(10.0);
	a_outline_color.set_disabled(false);
}

void FillControl::set_attribute(Attribute* attribute)
{
	a_fill.entangle_with(*attribute);

	m_dialog->set_attribute(attribute);
}

void FillControl::set_current_editting_state(const QString& state)
{
	a_fill.set_state(state);

	m_dialog->set_current_editting_state(state);
}

bool FillControl::eventFilter(QObject* object, QEvent* event)
{
	if (object == this)
	{
		if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)
		{
			QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

			if (mouse_event->button() & Qt::LeftButton)
			{
				m_dialog->move(mapToGlobal(QPoint(0, 0)));
				m_dialog->show();
				m_dialog->setFocus();
			}
		}
	}

	return false;
}
