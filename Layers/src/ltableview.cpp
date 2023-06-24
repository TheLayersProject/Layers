#include <Layers/ltableview.h>

#include <QPainter>

#include <Layers/lheaderview.h>
#include <Layers/lgridlineitemdelegate.h>

using Layers::LBorderAttributes;
using Layers::LGridlineItemDelegate;
using Layers::LSvgRenderer;
using Layers::LTableView;
using Layers::LThemeable;

LTableView::LTableView(QWidget* parent) : QTableView(parent)
{
	init_attributes();
	update_stylesheet();

	//setItemDelegate(new LGridlineItemDelegate);

	setHorizontalHeader(new LHeaderView(Qt::Horizontal));

	horizontalHeader()->setStretchLastSection(true);
	horizontalHeader()->setMinimumHeight(40);
	setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	setShowGrid(false);
	verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	verticalHeader()->setDefaultSectionSize(48);
	verticalHeader()->hide();
}

QList<LThemeable*> LTableView::child_themeables(Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables = LThemeable::child_themeables(options);

	if (LThemeable* child_themeable_item_delegate = dynamic_cast<LThemeable*>(itemDelegate()))
	{
		child_themeables.append(child_themeable_item_delegate);

		if (options == Qt::FindChildrenRecursively)
		{
			QList<QObject*> delegate_child_objects = itemDelegate()->findChildren<QObject*>(options);

			for (QObject* delegate_child_object : delegate_child_objects)
				if (LThemeable* child_themeable = dynamic_cast<LThemeable*>(delegate_child_object))
					child_themeables.append(child_themeable);
		}
	}

	return child_themeables;
}

void LTableView::setItemDelegate(QAbstractItemDelegate* item_delegate)
{
	if (LGridlineItemDelegate* themeable_item_delegate =
		dynamic_cast<LGridlineItemDelegate*>(item_delegate))
	{
		connect(themeable_item_delegate, &LGridlineItemDelegate::changed,
			[this] { update(); });
	}
	
	QTableView::setItemDelegate(item_delegate);
}

void LTableView::init_attributes()
{
	m_attr_data.attr_groups.insert({
		{ "border", m_border },
		{ "corner_radii", m_corner_radii }
		});

	m_attr_data.ungrouped_attrs.insert({
		{ "fill", m_fill },
		{ "item_fill", m_item_fill },
		{ "text_color", m_text_color }
		});

	connect(m_border->fill(), &LAttribute::changed, [this] { update_stylesheet(); });
	connect(m_border->thickness(), &LAttribute::changed, [this] { update_stylesheet(); });
	connect(m_corner_radii->top_left(), &LAttribute::changed, [this] { update_stylesheet(); });
	connect(m_corner_radii->top_right(), &LAttribute::changed, [this] { update_stylesheet(); });
	connect(m_corner_radii->bottom_left(), &LAttribute::changed, [this] { update_stylesheet(); });
	connect(m_corner_radii->bottom_right(), &LAttribute::changed, [this] { update_stylesheet(); });
	connect(m_fill, &LAttribute::changed, [this] { update_stylesheet(); });
	connect(m_item_fill, &LAttribute::changed, [this] { update_stylesheet(); });
	connect(m_text_color, &LAttribute::changed, [this] { update_stylesheet(); });

	m_border->thickness()->set_value(3.0);
	m_corner_radii->top_left()->set_value(5.0);
	m_corner_radii->top_right()->set_value(5.0);
	m_corner_radii->bottom_left()->set_value(5.0);
	m_corner_radii->bottom_right()->set_value(5.0);
}

void LTableView::update_stylesheet()
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

	stylesheet.append(
		"QTableView {"
		"background: " + m_fill->as<QColor>().name() + ";"
		"}");

	stylesheet.append(
		"QTableView::item {"
		"background: " + m_item_fill->as<QColor>().name() + ";"
		"}");

	setStyleSheet(stylesheet);

	update();
}

void LTableView::update_height()
{
	int visible_row_count = model()->rowCount() < m_visible_row_limit ?
		model()->rowCount() : m_visible_row_limit;

	int new_height = m_border->thickness()->as<int>() * 2;

	new_height += horizontalHeader()->height();

	for (auto i = visible_row_count; i--;)
		new_height += verticalHeader()->sectionSize(i);

	setMaximumHeight(new_height);
}
