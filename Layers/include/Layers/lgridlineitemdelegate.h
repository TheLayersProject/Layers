#ifndef LGRIDLINEITEMDELEGATE_H
#define LGRIDLINEITEMDELEGATE_H

#include <QStyledItemDelegate>

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lthemeable.h>

LAYERS_NAMESPACE_BEGIN
/*!
	An LGridlineItemDelegate is a QStyledItemDelegate and a LThemeable that
	provides a customizable gridline.
*/
class LAYERS_EXPORT LGridlineItemDelegate : public QStyledItemDelegate, public LThemeable
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

	// TODO: Create a destructor; free the attributes

	/*!
		Returns a pointer to the grid fill attribute of this themeable.
	*/
	LAttribute* grid_fill() const;

	/*!
		Returns a pointer to the grid thickness attribute of this themeable.
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
		new LAttribute("grid.fill", QColor("#808080"), this) };

	LAttribute* m_grid_thickness{
		new LAttribute("grid.thickness", 3.0, this) };
};
LAYERS_NAMESPACE_END

#endif // LGRIDLINEITEMDELEGATE_H  
