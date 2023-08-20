#include <Layers/lscrollbar.h>

using Layers::LAttribute;
using Layers::LScrollBar;

LScrollBar::LScrollBar(QWidget* parent) : QScrollBar(parent)
{
	set_name("ScrollBar");
	update();
}

LAttribute* LScrollBar::background_color() const
{
	return m_background_color;
}

LAttribute* LScrollBar::corner_radii_bottom_left() const
{
	return m_corner_radii_bottom_left;
}

LAttribute* LScrollBar::corner_radii_bottom_right() const
{
	return m_corner_radii_bottom_right;
}

LAttribute* LScrollBar::corner_radii_top_left() const
{
	return m_corner_radii_top_left;
}

LAttribute* LScrollBar::corner_radii_top_right() const
{
	return m_corner_radii_top_right;
}

LAttribute* LScrollBar::handle_color() const
{
	return m_handle_color;
}

LAttribute* LScrollBar::handle_corner_radii_bottom_left() const
{
	return m_handle_corner_radii_bottom_left;
}

LAttribute* LScrollBar::handle_corner_radii_bottom_right() const
{
	return m_handle_corner_radii_bottom_right;
}

LAttribute* LScrollBar::handle_corner_radii_top_left() const
{
	return m_handle_corner_radii_top_left;
}

LAttribute* LScrollBar::handle_corner_radii_top_right() const
{
	return m_handle_corner_radii_top_right;
}

void LScrollBar::update()
{
	QString o = (orientation() == Qt::Horizontal) ?
		"horizontal" : "vertical";

	QString style_sheet =
		"QScrollBar:" + o + " {"
		"background: " + m_background_color->as<QColor>().name() + ";"
		"border-top-left-radius: " +
			m_corner_radii_top_left->as<QString>() + "px;"
		"border-top-right-radius: " +
			m_corner_radii_top_right->as<QString>() + "px;"
		"border-bottom-left-radius: " +
			m_corner_radii_bottom_left->as<QString>() + "px;"
		"border-bottom-right-radius: " +
			m_corner_radii_bottom_right->as<QString>() + "px;"
		"margin: 0px 0px 0px 0px;";

	if (orientation() == Qt::Horizontal)
		style_sheet += "height: 40px;";
	else
		style_sheet += "width: 40px;";

	style_sheet += "}";

	style_sheet +=
		"QScrollBar::handle:" + o + " {"
		"background: " + m_handle_color->as<QColor>().name() + ";"
		"border-top-left-radius: " +
			m_handle_corner_radii_top_left->as<QString>() + "px;"
		"border-top-right-radius: " +
			m_handle_corner_radii_top_right->as<QString>() + "px;"
		"border-bottom-left-radius: " +
			m_handle_corner_radii_bottom_left->as<QString>() + "px;"
		"border-bottom-right-radius: " +
			m_handle_corner_radii_bottom_right->as<QString>() + "px;"
		"margin: 7px 7px 7px 7px;";
		
	if (orientation() == Qt::Horizontal)
		style_sheet += "min-width: 26px;";
	else
		style_sheet += "min-height: 26px;";

	style_sheet += "}";

	style_sheet +=
		"QScrollBar::add-line:" + o + " {"
		"border: none;"
		"background: none;"
		"}"
		"QScrollBar::sub-line:" + o + " {"
		"height: 0px;"
		"width: 0px;"
		"border: none;"
		"background: none;"
		"}"
		"QScrollBar:up-arrow:" + o + ", QScrollBar::down-arrow:" + o + " {"
		"border: none;"
		"background: none;"
		"color: none;"
		"}"
		"QScrollBar::add-page:" + o + ", QScrollBar::sub-page:" + o + " {"
		"background: none;"
		"}";

	setStyleSheet(style_sheet);
}
