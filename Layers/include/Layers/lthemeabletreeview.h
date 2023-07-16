#ifndef LTHEMEABLETREEVIEW_H
#define LTHEMEABLETREEVIEW_H

#include <QTreeView>

#include "layers_global.h"
#include "layers_exports.h"

#include "lscrollbar.h"
#include "lthemeable.h"

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

	/*!
		Returns a list of child themeables.

		This function overrides LThemeable::child_themeables() to include the
		scroll bars.
	*/
	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
	) override;

	void set_root_themeable(LThemeable* root_themeable);

	virtual void update() override;

protected:
	virtual void selectionChanged(
		const QItemSelection& selected,
		const QItemSelection& deselected) override;

private:
	LAttribute* m_fill{
		new LAttribute("Fill", QColor(Qt::white), this) };

	LAttribute* m_text_color{
		new LAttribute("Text Color", QColor(Qt::black), this) };

	LScrollBar* m_horizontal_scrollbar{ new LScrollBar };
	LScrollBar* m_vertical_scrollbar{ new LScrollBar };
};
LAYERS_NAMESPACE_END

#endif // LTHEMEABLETREEVIEW_H  
