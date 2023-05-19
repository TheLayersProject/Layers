#ifndef COMBOBOXITEMDELEGATE_H
#define COMBOBOXITEMDELEGATE_H

#include <QPainterPath>
#include <QStyledItemDelegate>

#include "Themeable.h"

namespace Layers
{
	/*!
		A ComboBoxItemDelegate is a QStyledItemDelegate and a Themeable that
		serves as a basic item delegate for ComboBox.
	*/
	class ComboBoxItemDelegate : public QStyledItemDelegate, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs a combo box item delegate.
		*/
		ComboBoxItemDelegate(QObject* parent = nullptr);

		// TODO: Create a destructor; free the attributes

		/*!
			Returns a QPainterPath that represents the item's background.
		*/
		QPainterPath background_path(
			const QStyleOptionViewItem& option,
			const QModelIndex& index) const;

		/*!
			Renders the delegate using the given *painter* and style *option*
			for the item specified by *index*.
		*/
		virtual void paint(QPainter* painter,
			const QStyleOptionViewItem& option,
			const QModelIndex& index) const override;

		/*!
			Informs the item delegate that the combo box popup widget is
			displayed above or below the combo box.
		*/
		void set_is_above_control(bool condition = true);

	protected:
		Attribute* m_corner_radius{
			new Attribute("corner_radius", Variant(10.0)) };

		Attribute* m_fill{
			new Attribute("fill", VariantMap({
				{ "Selected", QColor(Qt::green) },
				{ "Unselected", QColor(Qt::white) }
			})) };

		Attribute* m_text_color{
			new Attribute("text_color", QColor(Qt::black)) };

	private:
		void init_attributes();

		bool m_is_above_control{ false };
	};
}

#endif // COMBOBOXITEMDELEGATE_H  
