#ifndef LTHEMEABLETREEVIEW_H
#define LTHEMEABLETREEVIEW_H

#include <QTreeView>

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lthemeable.h>

LAYERS_NAMESPACE_BEGIN
class LThemeableTreeItemModel;

/*!
	An LThemeableTreeView is a QAbstractItemView and a LThemeable that is
	customizable.
*/
class LAYERS_EXPORT LThemeableTreeView :
	public QTreeView, public LThemeable
{
	Q_OBJECT

signals:
	void selection_changed(LThemeable* themeable);

public:
	/*!
		Constructs a themeable tree view.
	*/
	LThemeableTreeView(QWidget* parent = nullptr);

	void set_root_themeable(LThemeable* root_themeable);

protected:
	virtual void selectionChanged(
		const QItemSelection& selected,
		const QItemSelection& deselected) override;
};
LAYERS_NAMESPACE_END

#endif // LTHEMEABLETREEVIEW_H  
