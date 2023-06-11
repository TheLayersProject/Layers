#include <LayersWidgets/lcolorcontrol.h>

#include <QMouseEvent>

#include <LayersWidgets/lapplication.h>
#include <LayersWidgets/lcolordialog.h>

using Layers::LColorControl;

LColorControl::LColorControl(QWidget* parent) : LWidget(parent)
{
	init_attributes();

    setFixedSize(40, 40);
	installEventFilter(this);
}

LColorControl::~LColorControl()
{
	disconnect(attribute_connection);
}

void LColorControl::click()
{
	LColorDialog* color_dialog = layersApp->color_dialog();

	color_dialog->color()->set_value(fill()->as<QColor>());

	if (color_dialog->exec())
	{
		fill()->set_value(color_dialog->color()->as<QColor>());

		emit color_changed();
	}

	color_dialog->hide();

	open_on_release = false;
}

void LColorControl::disable_clicking(bool cond)
{
	clicking_disabled = cond;
}

void LColorControl::set_current_editing_state(const QString& state)
{
	m_fill->set_state(state);
}

bool LColorControl::eventFilter(QObject* object, QEvent* event)
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

void LColorControl::init_attributes()
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