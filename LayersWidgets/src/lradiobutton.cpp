#include "LayersWidgets/lradiobutton.h"

#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>

using Layers::LRadioButton;

LRadioButton::LRadioButton(QWidget* parent) : QWidget(parent)
{
	init_attributes();
	installEventFilter(this);
	setFixedSize(40, 40);
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

	int border_thickness = m_border->thickness()->as<int>();
	qreal margin = m_margin->as<qreal>();

	qreal radius_h = (width() / 2) - margin;
	qreal radius_v = (height() / 2) - margin;

	// Fill
	QPainterPath fill_path;
	fill_path.addEllipse(rect().center(),
		radius_h - border_thickness, radius_v - border_thickness);

	painter.fillPath(fill_path, m_fill->as<QColor>());

	// Border
	QPainterPath border_path;
	border_path.addEllipse(rect().center(),
		radius_h, radius_v);
	border_path = border_path - fill_path;

	if (border_thickness)
		painter.fillPath(border_path, m_border->fill()->as<QColor>());

	// Active Dot
	if (m_state == "Active")
	{
		QPainterPath active_dot_path;
		active_dot_path.addEllipse(rect().center(),
			radius_h * 0.385, radius_v * 0.385);

		painter.fillPath(active_dot_path, m_active_dot_fill->as<QColor>());
	}
}

void LRadioButton::init_attributes()
{
	m_attributes.insert({
		{ "active_dot_fill", m_active_dot_fill },
		{ "border", m_border },
		{ "fill", m_fill }
		});

	for (LAbstractAttribute* abstract_attribute : m_attributes)
		establish_update_connection(abstract_attribute);

	m_border->thickness()->init_variant_map({
		{ "Active", 0 },
		{ "Inactive", 3 }
		});

	set_state("Inactive");

	// TEMP
	m_active_dot_fill->set_value(QColor("#001122"));
	m_border->fill()->set_value(QColor("#0077b2"));
	m_fill->set_value(QColor("#112942"), "Inactive");
	m_fill->set_value(QColor("#00aaff"), "Active");
}
