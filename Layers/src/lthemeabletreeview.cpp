#include <Layers/lthemeabletreeview.h>

#include <QEvent>
#include <QPainter>

#include <Layers/lthemeabletreemodel.h>

using Layers::LThemeable;
using Layers::LThemeableTreeView;

LThemeableTreeView::LThemeableTreeView(QWidget* parent) :
	QTreeView(parent)
{
	setHeaderHidden(true);
	setHorizontalScrollBar(m_horizontal_scrollbar);
	setVerticalScrollBar(m_vertical_scrollbar);

	m_horizontal_scrollbar->set_name("Horizontal ScrollBar");

	m_vertical_scrollbar->set_name("Vertical ScrollBar");
	
	update();
}

QList<LThemeable*> LThemeableTreeView::child_themeables(Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables = LThemeable::child_themeables(options);

	child_themeables.append(m_horizontal_scrollbar);
	child_themeables.append(m_vertical_scrollbar);

	return child_themeables;
}

void LThemeableTreeView::set_root_themeable(LThemeable* root_themeable)
{
	setModel(new LThemeableTreeModel(root_themeable));
}

void LThemeableTreeView::update()
{
	QString stylesheet =
		"QAbstractItemView {"
		"background: " + m_fill->as<QColor>().name() + ";"
		"border: none;"
		"}"

		"QAbstractItemView::item {"
		"height: 40px;"
		"color: " + m_text_color->as<QColor>().name() + ";"
		"}";

	setStyleSheet(
		stylesheet
	);

	QWidget::update();
}

void LThemeableTreeView::selectionChanged(
	const QItemSelection& selected,
	const QItemSelection& deselected)
{
	QModelIndexList indexes = selected.indexes();

	if (!indexes.isEmpty())
		emit selection_changed(
			indexes.first().data(Qt::EditRole).value<LThemeable*>());
}
