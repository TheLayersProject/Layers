#include <Layers/lfillcontrol.h>

#include <QMouseEvent>

#include <Layers/lapplication.h>
#include <Layers/lfilldialog.h>

using Layers::LFillControl;

LFillControl::LFillControl(QWidget* parent) :
	LWidget(parent)
{
	init_attributes();

	installEventFilter(this);
	setFixedSize(40, 40);
	set_name("Fill Control");
}

LFillControl::~LFillControl()
{
	delete m_fill;
}

void LFillControl::set_attribute(LAttribute* attribute)
{
	m_fill->set_link_attribute(attribute);
}

bool LFillControl::eventFilter(QObject* object, QEvent* event)
{
	if (object == this)
	{
		if (event->type() == QEvent::MouseButtonPress ||
			event->type() == QEvent::MouseButtonDblClick)
		{
			QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

			if (mouse_event->button() & Qt::LeftButton)
			{
				LFillDialog fill_dialog;
				fill_dialog.apply_theme(
					activeTheme()->find_item(fill_dialog.path()));
				fill_dialog.move(mapToGlobal(QPoint(0, 0)));
				fill_dialog.set_attribute(m_fill);
				fill_dialog.exec();
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
