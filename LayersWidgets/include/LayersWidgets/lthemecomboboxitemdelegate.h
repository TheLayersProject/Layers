#ifndef LTHEMECOMBOBOXITEMDELEGATE_H
#define LTHEMECOMBOBOXITEMDELEGATE_H

#include "layerswidgetsexports.h"

#include "lcomboboxitemdelegate.h"

namespace Layers
{
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
}

#endif // LTHEMECOMBOBOXITEMDELEGATE_H
