#include <Layers/lfillcontrol.h>

#include <QMouseEvent>

#include <Layers/lfilldialog.h>

using Layers::LFillControl;

LFillControl::LFillControl(QWidget* parent) :
	m_control_dialog{ new LFillDialog(this) },
	m_dialog{ new LFillDialog },
	LWidget(parent)
{
	init_attributes();

	installEventFilter(this);
	setFixedSize(40, 40);
	set_name("Fill Control");

	m_control_dialog->hide();

	m_dialog->entangle_with(m_control_dialog);
}

LFillControl::~LFillControl()
{
	// TODO: Maybe the dialog should just be generated when it is needed
	delete m_control_dialog;
	delete m_dialog;
}

void LFillControl::set_attribute(LAttribute* attribute)
{
	fill()->establish_link(*attribute);

	m_dialog->set_attribute(attribute);
}

bool LFillControl::eventFilter(QObject* object, QEvent* event)
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

void LFillControl::init_attributes()
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
}
