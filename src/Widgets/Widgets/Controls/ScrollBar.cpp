#include "ScrollBar.h"

using Layers::Attribute;
using Layers::CornerRadiiAttributes;
using Layers::ScrollBar;

ScrollBar::ScrollBar(QWidget* parent) : QScrollBar(parent)
{
	init_attributes();

	set_name("scrollbar");
	set_proper_name("ScrollBar");

	update_theme_dependencies();

	//if (orientation() == Qt::Vertical)
	//	setFixedWidth(45);
	//else if (orientation() == Qt::Horizontal)
	//	setFixedHeight(45);
}

ScrollBar::~ScrollBar()
{
	delete m_background_color;
	delete m_handle_color;
	delete m_corner_radii;
	delete m_handle_corner_radii;

	m_background_color = nullptr;
	m_handle_color = nullptr;
	m_corner_radii = nullptr;
	m_handle_corner_radii = nullptr;
}

void ScrollBar::update_theme_dependencies()
{
	setStyleSheet(build_stylesheet());
}

Attribute* ScrollBar::background_color() const
{
	return m_background_color;
}

Attribute* ScrollBar::handle_color() const
{
	return m_handle_color;
}

CornerRadiiAttributes* ScrollBar::corner_radii() const
{
	return m_corner_radii;
}

CornerRadiiAttributes* ScrollBar::handle_corner_radii() const
{
	return m_handle_corner_radii;
}

QString ScrollBar::build_stylesheet()
{
	return
		/* VERTICAL */
		"QScrollBar:vertical {"
		//"border-left: 1px solid black;"
		"background: " + m_background_color->as<QColor>().name() + ";"
		"width: 45px;"
		"border-top-left-radius: " + corner_radii()->top_left()->as<QString>() + "px;"
		"border-top-right-radius: " + corner_radii()->top_right()->as<QString>() + "px;"
		"border-bottom-left-radius: " + corner_radii()->bottom_left()->as<QString>() + "px;"
		"border-bottom-right-radius: " + corner_radii()->bottom_right()->as<QString>() + "px;"
		"margin: 0px 0px 0px 0px;"
		"}"

		"QScrollBar::handle:vertical {"
		"background: " + m_handle_color->as<QColor>().name() + ";"
		"min-height: 26px;"
		"border-top-left-radius: " + handle_corner_radii()->top_left()->as<QString>() + "px;"
		"border-top-right-radius: " + handle_corner_radii()->top_right()->as<QString>() + "px;"
		"border-bottom-left-radius: " + handle_corner_radii()->bottom_left()->as<QString>() + "px;"
		"border-bottom-right-radius: " + handle_corner_radii()->bottom_right()->as<QString>() + "px;"
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
		"border-top-left-radius: " + corner_radii()->top_left()->as<QString>() + "px;"
		"border-top-right-radius: " + corner_radii()->top_right()->as<QString>() + "px;"
		"border-bottom-left-radius: " + corner_radii()->bottom_left()->as<QString>() + "px;"
		"border-bottom-right-radius: " + corner_radii()->bottom_right()->as<QString>() + "px;"
		"margin: 0px 0px 0px 0px;"
		"}"

		"QScrollBar::handle:horizontal {"
		"background: " + m_handle_color->as<QColor>().name() + ";"
		"min-width: 26px;"
		"border-top-left-radius: " + handle_corner_radii()->top_left()->as<QString>() + "px;"
		"border-top-right-radius: " + handle_corner_radii()->top_right()->as<QString>() + "px;"
		"border-bottom-left-radius: " + handle_corner_radii()->bottom_left()->as<QString>() + "px;"
		"border-bottom-right-radius: " + handle_corner_radii()->bottom_right()->as<QString>() + "px;"
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
		"}";
}

void ScrollBar::init_attributes()
{
	m_corner_radii->bottom_right()->set_value(10.0);

	m_handle_corner_radii->top_left()->set_value(5.0);
	m_handle_corner_radii->top_right()->set_value(5.0);
	m_handle_corner_radii->bottom_left()->set_value(5.0);
	m_handle_corner_radii->bottom_right()->set_value(5.0);

	m_entities.insert({
		{ "background_color", m_background_color },
		{ "corner_radii", m_corner_radii },
		{ "handle_corner_radii", m_handle_corner_radii },
		{ "handle_color", m_handle_color }
		});

	connect(m_background_color, &Entity::value_changed, [this] { update_theme_dependencies(); });
	connect(m_corner_radii, &Entity::value_changed, [this] { update_theme_dependencies(); });
	connect(m_corner_radii->top_left(), &Entity::value_changed, [this] { update_theme_dependencies(); });
	connect(m_corner_radii->top_right(), &Entity::value_changed, [this] { update_theme_dependencies(); });
	connect(m_corner_radii->bottom_left(), &Entity::value_changed, [this] { update_theme_dependencies(); });
	connect(m_corner_radii->bottom_right(), &Entity::value_changed, [this] { update_theme_dependencies(); });
	connect(m_handle_corner_radii, &Entity::value_changed, [this] { update_theme_dependencies(); });
	connect(m_handle_corner_radii->top_left(), &Entity::value_changed, [this] { update_theme_dependencies(); });
	connect(m_handle_corner_radii->top_right(), &Entity::value_changed, [this] { update_theme_dependencies(); });
	connect(m_handle_corner_radii->bottom_left(), &Entity::value_changed, [this] { update_theme_dependencies(); });
	connect(m_handle_corner_radii->bottom_right(), &Entity::value_changed, [this] { update_theme_dependencies(); });
	connect(m_handle_color, &Entity::value_changed, [this] { update_theme_dependencies(); });
}
