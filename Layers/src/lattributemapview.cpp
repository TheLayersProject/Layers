#include <Layers/lattributemapview.h>

using Layers::LAttributeMapView;
using Layers::LThemeable;

LAttributeMapView::LAttributeMapView(QWidget* parent) :
	QTreeView(parent)
{
	setObjectName("Attribute Map View");

	setHeaderHidden(true);
	setHorizontalScrollBar(m_horizontal_scrollbar);
	setModel(m_model);
	setVerticalScrollBar(m_vertical_scrollbar);

	m_horizontal_scrollbar->setObjectName("Horizontal ScrollBar");

	m_vertical_scrollbar->setObjectName("Vertical ScrollBar");

	update();
}

QList<LThemeable*> LAttributeMapView::child_themeables(Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables = LThemeable::child_themeables(options);

	child_themeables.append(m_horizontal_scrollbar);
	child_themeables.append(m_vertical_scrollbar);

	return child_themeables;
}

void LAttributeMapView::set_attributes(
	LAttributeMap attributes, const QStringList& filter_paths)
{
	m_model->init_root_item(attributes, filter_paths);
}

void LAttributeMapView::update()
{
	QString style_sheet =
		"QAbstractItemView {"
		"background: " + m_fill->as<QColor>().name() + ";"
		"border: none;"
		"}"

		"QAbstractItemView::item {"
		"height: 40px;"
		"color: " + m_text_color->as<QColor>().name() + ";"
		"}";

	setStyleSheet(
		style_sheet
	);

	QWidget::update();
}

void LAttributeMapView::selectionChanged(
	const QItemSelection& selected, const QItemSelection& deselected)
{
	QModelIndexList indexes = selected.indexes();

	if (!indexes.isEmpty())
		emit selection_changed(
			indexes.first().data(Qt::UserRole).value<LAttribute*>());
}
