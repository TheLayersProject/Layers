#ifndef LTABLEVIEW_H
#define LTABLEVIEW_H

#include <QHeaderView>
#include <QTableView>
#include <QStyledItemDelegate>

#include "layers_global.h"
#include "layers_exports.h"

#include "lsvgrenderer.h"
#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
/*!
	![LTableView Example](table_view.png)
	
	An LTableView is a QTableView and an LThemeable that displays items from a
	model in the form of a table.
*/
class LAYERS_EXPORT LTableView : public QTableView, public LThemeable
{
	Q_OBJECT

public:
	/*!
		Constructs a table view.
	*/
	LTableView(QWidget* parent = nullptr);

	/*!
		Returns a list of child themeables.

		This function overrides LThemeable::child_themeables() to include the
		table's item delegate as well as its children.
	*/
	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly) override;

	/*!
		Sets the item delegate of the table view.
	*/
	void setItemDelegate(QAbstractItemDelegate* item_delegate);

	/*!
		Updates the table view.

		This function overrides LThemeable::update() to set the table view's
		style sheet.
	*/
	virtual void update() override;

	/*!
		Updates the height of the table view.
	*/
	void update_height();

private:
	void init_attributes();

	LAttribute* m_border_fill
		{ new LAttribute("Border.Fill", QColor(Qt::gray), this) };

	LAttribute* m_border_thickness
		{ new LAttribute("Border.Thickness", 3.0, this) };

	LAttribute* m_corner_radii_bottom_left
		{ new LAttribute("Corner Radii.Bottom Left", 5.0, this) };

	LAttribute* m_corner_radii_bottom_right
		{ new LAttribute("Corner Radii.Bottom Right", 5.0, this) };

	LAttribute* m_corner_radii_top_left
		{ new LAttribute("Corner Radii.Top Left", 5.0, this) };

	LAttribute* m_corner_radii_top_right
		{ new LAttribute("Corner Radii.Top Right", 5.0, this) };

	LAttribute* m_fill
		{ new LAttribute("Fill", QColor(Qt::white), this) };

	LAttribute* m_item_fill
		{ new LAttribute("Item Fill", QColor(Qt::white), this) };

	QAbstractItemDelegate* m_table_delegate{ nullptr };

	LAttribute* m_text_color
		{ new LAttribute("Text Color", QColor(Qt::black), this) };

	int m_visible_row_limit{ 3 };
};
LAYERS_NAMESPACE_END

#endif // LTABLEVIEW_H
