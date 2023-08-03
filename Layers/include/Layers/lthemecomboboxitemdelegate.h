#ifndef LTHEMECOMBOBOXITEMDELEGATE_H
#define LTHEMECOMBOBOXITEMDELEGATE_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lcomboboxitemdelegate.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeComboBoxItemDelegate : public LComboBoxItemDelegate
{
	Q_OBJECT

signals:
	void mouse_moved(QPoint cursor_pos);

public:
	virtual bool editorEvent(QEvent* event,
		QAbstractItemModel* model,
		const QStyleOptionViewItem& option,
		const QModelIndex& index) override;

	virtual void paint(QPainter* painter,
		const QStyleOptionViewItem& option,
		const QModelIndex& index) const override;

private:
	QImage m_caution_image{ QImage(":/images/caution.png") };
};
LAYERS_NAMESPACE_END

#endif // LTHEMECOMBOBOXITEMDELEGATE_H
