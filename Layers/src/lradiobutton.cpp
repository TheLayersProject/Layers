#include "Layers/lradiobutton.h"

#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>

using Layers::LRadioButton;
using Layers::LStatePool;

LRadioButton::LRadioButton(QWidget* parent) : QWidget(parent)
{
	add_state_pool(m_status_states);
	init_attributes();
	installEventFilter(this);
	setFixedSize(40, 40);

	m_status_states->set_state("Inactive");
}

LStatePool* LRadioButton::status_states() const
{
	return m_status_states;
}

bool LRadioButton::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress)
		if (static_cast<QMouseEvent*>(event)->button() & Qt::LeftButton)
			emit clicked();

	return false;
}

void LRadioButton::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	QStringList s = states();

	int border_thickness = m_border_thickness->as<int>(s);
	qreal margin = m_margin->as<qreal>(s);

	qreal radius_h = (width() / 2) - margin;
	qreal radius_v = (height() / 2) - margin;

	// Fill
	QPainterPath fill_path;
	fill_path.addEllipse(rect().center(),
		radius_h - border_thickness, radius_v - border_thickness);

	painter.fillPath(fill_path, m_fill->as<QColor>(s));

	// Border
	QPainterPath border_path;
	border_path.addEllipse(rect().center(),
		radius_h, radius_v);
	border_path = border_path - fill_path;

	if (border_thickness)
		painter.fillPath(border_path, m_border_fill->as<QColor>(s));

	// Active Dot
	if (s.contains("Active"))
	{
		QPainterPath active_dot_path;
		active_dot_path.addEllipse(rect().center(),
			radius_h * 0.385, radius_v * 0.385);

		painter.fillPath(active_dot_path, m_active_dot_fill->as<QColor>(s));
	}
}

void LRadioButton::init_attributes()
{
	m_border_thickness->add_override("Active", 0.0);

	m_fill->add_override("Active", QColor(Qt::lightGray));

	for (LAttribute* attr : attributes())
		establish_update_connection(attr);
}
