#ifndef GRIDLINEITEMDELEGATE_H
#define GRIDLINEITEMDELEGATE_H

#include <QStyledItemDelegate>

#include "Themeable.h"

namespace Layers
{
	class GridlineItemDelegate : public QStyledItemDelegate, public Themeable
	{
		Q_OBJECT

	signals:
		void changed();

	public:
		GridlineItemDelegate(QObject* parent = nullptr);

		//using QStyledItemDelegate::QStyledItemDelegate;
		// TODO: Create a destructor; free the attributes

		BorderAttributes* grid() const;

		virtual void paint(QPainter* painter,
			const QStyleOptionViewItem& option,
			const QModelIndex& index) const override;

		using QStyledItemDelegate::sizeHint;
		using QStyledItemDelegate::createEditor;
		using QStyledItemDelegate::setEditorData;
		using QStyledItemDelegate::setModelData;
		using QStyledItemDelegate::updateEditorGeometry;

	private:
		void init_attributes();

		BorderAttributes* m_grid{ new BorderAttributes("grid") };
	};
}

#endif // GRIDLINEITEMDELEGATE_H  
