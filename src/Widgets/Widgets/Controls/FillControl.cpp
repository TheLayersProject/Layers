#include "FillControl.h"

#include "Widgets/Dialogs/FillDialog.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPainterPath>
#include <QVBoxLayout>

using Layers::FillControl;

FillControl::FillControl(QWidget* parent) :
	m_control_dialog{ new FillDialog(this) },
	m_dialog{ new FillDialog },
	Widget(parent)
{
	init_attributes();

	installEventFilter(this);
	setFixedSize(40, 40);
	set_name("Fill Control");

	m_control_dialog->hide();

	m_dialog->entangle_with(m_control_dialog);
}

FillControl::~FillControl()
{
	// TODO: Maybe the dialog should just be generated when it is needed
	delete m_control_dialog;
	delete m_dialog;

	m_control_dialog = nullptr;
	m_dialog = nullptr;
}

void FillControl::set_attribute(Attribute* attribute)
{
	fill()->entangle_with(*attribute);

	m_dialog->set_attribute(attribute);
}

void FillControl::set_current_editting_state(const QString& state)
{
	fill()->set_state(state);

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

void FillControl::init_attributes()
{
	// Remove control attribute
	m_attributes.remove("fill");

	m_border->fill()->set_value(QColor("#D6D6D6"));
	m_border->thickness()->set_value(2.0);
	m_corner_radii->top_left()->set_value(5.0);
	m_corner_radii->top_right()->set_value(5.0);
	m_corner_radii->bottom_left()->set_value(5.0);
	m_corner_radii->bottom_right()->set_value(5.0);
	m_margins->left()->set_value(8.0);
	m_margins->top()->set_value(8.0);
	m_margins->right()->set_value(8.0);
	m_margins->bottom()->set_value(8.0);
}
