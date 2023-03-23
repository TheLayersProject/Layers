#ifndef THEMECOMBOBOXITEMDELEGATE_H
#define THEMECOMBOBOXITEMDELEGATE_H

#include "ComboBoxItemDelegate.h"
#include "SvgRenderer.h"

namespace Layers
{
	class ThemeComboBoxItemDelegate : public ComboBoxItemDelegate
	{
		Q_OBJECT

		//signals:
		//	void changed();

	public:
		ThemeComboBoxItemDelegate(QObject* parent = nullptr);
		// TODO: Create a destructor; free the attributes

		virtual bool editorEvent(QEvent* event,
			QAbstractItemModel* model,
			const QStyleOptionViewItem& option,
			const QModelIndex& index);

		virtual void paint(QPainter* painter,
			const QStyleOptionViewItem& option,
			const QModelIndex& index) const override;

	private:
		SvgRenderer* m_caution_svg{ new SvgRenderer(":/svgs/caution.svg", this) };

		QImage m_caution_image{ QImage(18, 17, QImage::Format_ARGB32) };
	};
}

#endif // THEMECOMBOBOXITEMDELEGATE_H
