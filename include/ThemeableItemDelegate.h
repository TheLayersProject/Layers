#ifndef ITEMDELEGATEWITHCUSTOMGRID_H
#define ITEMDELEGATEWITHCUSTOMGRID_H

#include <QStyledItemDelegate>

#include "Themeable.h"

namespace Layers
{
	class ThemeableItemDelegate : public QStyledItemDelegate, public Themeable
	{
		Q_OBJECT

	signals:
		void changed();

	public:
		ThemeableItemDelegate(QObject* parent = nullptr);

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

#endif // ITEMDELEGATEWITHCUSTOMGRID_H  
