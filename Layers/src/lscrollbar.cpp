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
	setStyleSheet(
		/* VERTICAL */
		"QScrollBar:vertical {"
		//"border-left: 1px solid black;"
		"background: " + m_background_color->as<QColor>().name() + ";"
		"width: 45px;"
		"border-top-left-radius: " + m_corner_radii_top_left->as<QString>() + "px;"
		"border-top-right-radius: " + m_corner_radii_top_right->as<QString>() + "px;"
		"border-bottom-left-radius: " + m_corner_radii_bottom_left->as<QString>() + "px;"
		"border-bottom-right-radius: " + m_corner_radii_bottom_right->as<QString>() + "px;"
		"margin: 0px 0px 0px 0px;"
		"}"

		"QScrollBar::handle:vertical {"
		"background: " + m_handle_color->as<QColor>().name() + ";"
		"min-height: 26px;"
		"border-top-left-radius: " + m_handle_corner_radii_top_left->as<QString>() + "px;"
		"border-top-right-radius: " + m_handle_corner_radii_top_right->as<QString>() + "px;"
		"border-bottom-left-radius: " + m_handle_corner_radii_bottom_left->as<QString>() + "px;"
		"border-bottom-right-radius: " + m_handle_corner_radii_bottom_right->as<QString>() + "px;"
		"margin: 10px 10px 10px 10px;"
		"}"

		"QScrollBar::add-line:vertical {"
		"border: none;"
		"background: none;"
		"}"

		"QScrollBar::sub-line:vertical {"
		"height: 0px;"
		"width: 0px;"
		"border: none;"
		"background: none;"
		"}"

		"QScrollBar:up-arrow:vertical, QScrollBar::down-arrow:vertical {"
		"border: none;"
		"background: none;"
		"color: none;"
		"}"

		"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
		"background: none;"
		"}"

		/* HORIZONTAL */
		"QScrollBar:horizontal {"
		//"border-top: 1px solid black;"
		"background: " + m_background_color->as<QColor>().name() + ";"
		"height: 45px;"
		"border-top-left-radius: " + m_corner_radii_top_left->as<QString>() + "px;"
		"border-top-right-radius: " + m_corner_radii_top_right->as<QString>() + "px;"
		"border-bottom-left-radius: " + m_corner_radii_bottom_left->as<QString>() + "px;"
		"border-bottom-right-radius: " + m_corner_radii_bottom_right->as<QString>() + "px;"
		"margin: 0px 0px 0px 0px;"
		"}"

		"QScrollBar::handle:horizontal {"
		"background: " + m_handle_color->as<QColor>().name() + ";"
		"min-width: 26px;"
		"border-top-left-radius: " + m_handle_corner_radii_top_left->as<QString>() + "px;"
		"border-top-right-radius: " + m_handle_corner_radii_top_right->as<QString>() + "px;"
		"border-bottom-left-radius: " + m_handle_corner_radii_bottom_left->as<QString>() + "px;"
		"border-bottom-right-radius: " + m_handle_corner_radii_bottom_right->as<QString>() + "px;"
		"margin: 10px 10px 10px 10px;"
		"}"

		"QScrollBar::add-line:horizontal {"
		"border: none;"
		"background: none;"
		"}"

		"QScrollBar::sub-line:horizontal {"
		"height: 0px;"
		"width: 0px;"
		"border: none;"
		"background: none;"
		"}"

		"QScrollBar:up-arrow:horizontal, QScrollBar::down-arrow:horizontal {"
		"border: none;"
		"background: none;"
		"color: none;"
		"}"

		"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {"
		"background: none;"
		"}");
}
