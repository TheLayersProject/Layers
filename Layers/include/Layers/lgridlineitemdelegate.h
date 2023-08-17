#ifndef LGRIDLINEITEMDELEGATE_H
#define LGRIDLINEITEMDELEGATE_H

#include <QStyledItemDelegate>

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lthemeable.h>

LAYERS_NAMESPACE_BEGIN
/*!
	![LGridlineItemDelegate Example](gridline_item_delegate.png)
	
	An LGridlineItemDelegate is a QStyledItemDelegate and an LThemeable that
	provides a customizable gridline.

	The example above is from an LTableView using a gridline item delegate.
*/
class LAYERS_EXPORT LGridlineItemDelegate :
	public QStyledItemDelegate, public LThemeable
{
	Q_OBJECT

signals:
	/*!
		This signal is emitted when any of the item delegate's attributes are
		changed.
	*/
	void changed();

public:
	/*!
		Constructs a gridline item delegate.
	*/
	LGridlineItemDelegate(QObject* parent = nullptr);

	/*!
		Returns a pointer to the delegate's grid-fill attribute.
	*/
	LAttribute* grid_fill() const;

	/*!
		Returns a pointer to the delegate's grid-thickness attribute.
	*/
	LAttribute* grid_thickness() const;

	/*!
		Renders the delegate using the given *painter* and style *option* for
		the item specified by *index*.
	*/
	virtual void paint(QPainter* painter,
		const QStyleOptionViewItem& option,
		const QModelIndex& index) const override;

	using QStyledItemDelegate::sizeHint;
	using QStyledItemDelegate::createEditor;
	using QStyledItemDelegate::setEditorData;
	using QStyledItemDelegate::setModelData;
	using QStyledItemDelegate::updateEditorGeometry;

private:
	LAttribute* m_grid_fill{
		new LAttribute("Grid.Fill", QColor("#808080"), this) };

	LAttribute* m_grid_thickness{
		new LAttribute("Grid.Thickness", 3.0, this) };
};
LAYERS_NAMESPACE_END

#endif // LGRIDLINEITEMDELEGATE_H  
