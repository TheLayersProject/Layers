#include "../../include/TableView.h"

#include "../../include/HeaderView.h"
#include "../../include/ThemeableItemDelegate.h"

#include <QPainter>

using Layers::BorderAttributes;
using Layers::SvgRenderer;
using Layers::TableView;
using Layers::ThemeableItemDelegate;

TableView::TableView(QWidget* parent) : QTableView(parent)
{
	init_attributes();
	update_stylesheet();

	//setItemDelegate(new ThemeableItemDelegate);

	setHorizontalHeader(new HeaderView(Qt::Horizontal));

	horizontalHeader()->setStretchLastSection(true);
	horizontalHeader()->setMinimumHeight(45);
	setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	setShowGrid(false);
	verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	verticalHeader()->setDefaultSectionSize(48);
	verticalHeader()->hide();
}

void TableView::setItemDelegate(QAbstractItemDelegate* item_delegate)
{
	if (ThemeableItemDelegate* themeable_item_delegate =
		dynamic_cast<ThemeableItemDelegate*>(item_delegate))
	{
		connect(themeable_item_delegate, &ThemeableItemDelegate::changed,
			[this] { update(); });
	}
	
	QTableView::setItemDelegate(item_delegate);
}

void TableView::init_attributes()
{
	m_entities.insert({
		{ "border", m_border },
		{ "corner_radii", m_corner_radii },
		{ "fill", m_fill },
		{ "item_fill", m_item_fill },
		{ "text_color", m_text_color }
		});

	connect(m_border->fill(), &Entity::value_changed, [this] { update_stylesheet(); });
	connect(m_border->thickness(), &Entity::value_changed, [this] { update_stylesheet(); });
	connect(m_corner_radii->top_left(), &Entity::value_changed, [this] { update_stylesheet(); });
	connect(m_corner_radii->top_right(), &Entity::value_changed, [this] { update_stylesheet(); });
	connect(m_corner_radii->bottom_left(), &Entity::value_changed, [this] { update_stylesheet(); });
	connect(m_corner_radii->bottom_right(), &Entity::value_changed, [this] { update_stylesheet(); });
	connect(m_fill, &Entity::value_changed, [this] { update_stylesheet(); });
	connect(m_item_fill, &Entity::value_changed, [this] { update_stylesheet(); });
	connect(m_text_color, &Entity::value_changed, [this] { update_stylesheet(); });

	m_border->thickness()->set_value(3.0);
	m_corner_radii->top_left()->set_value(5.0);
	m_corner_radii->top_right()->set_value(5.0);
	m_corner_radii->bottom_left()->set_value(5.0);
	m_corner_radii->bottom_right()->set_value(5.0);
}

void TableView::update_stylesheet()
{
	QString stylesheet =
		"QTableView {"
		"border: " + m_border->thickness()->as<QString>() + "px solid " + m_border->fill()->as<QColor>().name() + ";"
		"border-top-left-radius: " + m_corner_radii->top_left()->as<QString>() + "px;"
		"border-top-right-radius: " + m_corner_radii->top_right()->as<QString>() + "px;"
		"border-bottom-left-radius: " + m_corner_radii->bottom_left()->as<QString>() + "px;"
		"border-bottom-right-radius: " + m_corner_radii->bottom_right()->as<QString>() + "px;"
		"color: " + m_text_color->as<QColor>().name() + ";"
		"}";

	if (!m_fill->disabled())
		stylesheet.append(
			"QTableView {"
			"background: " + m_fill->as<QColor>().name() + ";"
			"}");
	else
		stylesheet.append(
			"QTableView {"
			"background: transparent;"
			"}");

	if (!m_item_fill->disabled())
		stylesheet.append(
			"QTableView::item {"
			"background: " + m_item_fill->as<QColor>().name() + ";"
			"}");
	else
		stylesheet.append(
			"QTableView::item {"
			"background: transparent;"
			"}");

	setStyleSheet(stylesheet);

	update();
}

void TableView::update_height()
{
	int visible_row_count = model()->rowCount() < m_visible_row_limit ?
		model()->rowCount() : m_visible_row_limit;

	int new_height = m_border->thickness()->as<int>() * 2;

	new_height += horizontalHeader()->height();

	for (auto i = visible_row_count; i--;)
		new_height += verticalHeader()->sectionSize(i);

	setMaximumHeight(new_height);
}
