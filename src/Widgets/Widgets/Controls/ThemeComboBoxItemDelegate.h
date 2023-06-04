#ifndef THEMECOMBOBOXITEMDELEGATE_H
#define THEMECOMBOBOXITEMDELEGATE_H

#include "ComboBoxItemDelegate.h"
#include "SvgRenderer.h"

namespace Layers
{
	class ThemeComboBoxItemDelegate : public ComboBoxItemDelegate
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

#endif // THEMECOMBOBOXITEMDELEGATE_H
