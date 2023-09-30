#ifndef LGRIDLINEITEMDELEGATE_H
#define LGRIDLINEITEMDELEGATE_H

#include <QStyledItemDelegate>

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lthemeable.h>

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LGridlineItemDelegate :
	public QStyledItemDelegate, public LThemeable
{
	Q_OBJECT

signals:
	void changed();

public:
	LGridlineItemDelegate(QObject* parent = nullptr);

	LAttribute* grid_fill() const;

	LAttribute* grid_thickness() const;

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
