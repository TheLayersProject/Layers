#include <Layers/lthemeabletreeview.h>

#include <QEvent>

#include <Layers/lthemeabletreemodel.h>

using Layers::LThemeableTreeView;

LThemeableTreeView::LThemeableTreeView(QWidget* parent) :
	QTreeView(parent)
{
	setHeaderHidden(true);
	setStyleSheet(
		"QAbstractItemView {"
		"background: transparent;"
		"border: none;"
		"}"

		"QAbstractItemView::item {"
		"height: 40px;"
		"}"
	);
}

void LThemeableTreeView::set_root_themeable(LThemeable* root_themeable)
{
	setModel(new LThemeableTreeModel(root_themeable));
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
