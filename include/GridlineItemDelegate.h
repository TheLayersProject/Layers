#ifndef GRIDLINEITEMDELEGATE_H
#define GRIDLINEITEMDELEGATE_H

#include <QStyledItemDelegate>

#include "Themeable.h"

namespace Layers
{
	/*!
		A GridlineItemDelegate is a QStyledItemDelegate and a Themeable that
		provides a customizable gridline.
	*/
	class GridlineItemDelegate : public QStyledItemDelegate, public Themeable
	{
		Q_OBJECT

	signals:
		/*!
			This signal is emitted when any of the item delegate's attributes
			are changed.
		*/
		void changed();

	public:
		/*!
			Constructs a gridline item delegate.
		*/
		GridlineItemDelegate(QObject* parent = nullptr);

		// TODO: Create a destructor; free the attributes

		/*!
			Returns a pointer to the grid attributes of this item delegate.
		*/
		BorderAttributes* grid() const;

		/*!
			Renders the delegate using the given *painter* and style *option*
			for the item specified by *index*.
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
		void init_attributes();

		BorderAttributes* m_grid{ new BorderAttributes("grid") };
	};
}

#endif // GRIDLINEITEMDELEGATE_H  
