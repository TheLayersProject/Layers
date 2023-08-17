#include <Layers/lheaderview.h>

#include <QPainter>

using Layers::LHeaderView;

LHeaderView::LHeaderView(Qt::Orientation orientation, QWidget* parent) :
	QHeaderView(orientation, parent)
{
	update();

	if (orientation == Qt::Horizontal)
		set_name("Horizontal Header");
	else
		set_name("Vertical Header");
}

void LHeaderView::update()
{
	setStyleSheet(
		"QHeaderView {"
		"background: " + m_fill->as<QColor>().name() + ";"
		"border-top-left-radius: "
			+ m_corner_radii_top_left->as<QString>() + "px;"
		"border-top-right-radius: "
			+ m_corner_radii_top_right->as<QString>() + "px;"
		"border-bottom-left-radius: "
			+ m_corner_radii_bottom_left->as<QString>() + "px;"
		"border-bottom-right-radius: "
			+ m_corner_radii_bottom_right->as<QString>() + "px;"
		"color: " + m_text_color->as<QColor>().name() + ";"
		"}"

		"QHeaderView::section {"
		"background: transparent;"
		"}"
	);

	QWidget::update();
}
