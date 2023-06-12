#ifndef LTHEMECOMBOBOXITEMDELEGATE_H
#define LTHEMECOMBOBOXITEMDELEGATE_H

#include <LayersCore/layers_global.h>
#include "layerswidgets_exports.h"

#include "lcomboboxitemdelegate.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_WIDGETS_EXPORT LThemeComboBoxItemDelegate : public LComboBoxItemDelegate
{
	Q_OBJECT

public:
	virtual bool editorEvent(QEvent* event,
		QAbstractItemModel* model,
		const QStyleOptionViewItem& option,
		const QModelIndex& index);

	virtual void paint(QPainter* painter,
		const QStyleOptionViewItem& option,
		const QModelIndex& index) const override;

private:
	QImage m_caution_image{ QImage(":/images/caution.png") };
};
LAYERS_NAMESPACE_END

#endif // LTHEMECOMBOBOXITEMDELEGATE_H
