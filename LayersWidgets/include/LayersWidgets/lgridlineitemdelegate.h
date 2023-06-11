#ifndef LGRIDLINEITEMDELEGATE_H
#define LGRIDLINEITEMDELEGATE_H

#include <QStyledItemDelegate>

#include "layerswidgetsexports.h"

#include <LayersCore/lthemeable.h>

namespace Layers
{
	/*!
		A LGridlineItemDelegate is a QStyledItemDelegate and a LThemeable that
		provides a customizable gridline.
	*/
	class LAYERS_WIDGETS_EXPORT LGridlineItemDelegate : public QStyledItemDelegate, public LThemeable
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
		LGridlineItemDelegate(QObject* parent = nullptr);

		// TODO: Create a destructor; free the attributes

		/*!
			Returns a pointer to the grid attributes of this item delegate.
		*/
		LBorderAttributes* grid() const;

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

		LBorderAttributes* m_grid{ new LBorderAttributes("grid") };
	};
}

#endif // LGRIDLINEITEMDELEGATE_H  
