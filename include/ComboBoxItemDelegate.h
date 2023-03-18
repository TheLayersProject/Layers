#ifndef COMBOBOXDELEGATE_H
#define COMBOBOXDELEGATE_H

#include <QPainterPath>
#include <QStyledItemDelegate>

#include "Themeable.h"

namespace Layers
{
	class ComboBoxItemDelegate : public QStyledItemDelegate, public Themeable
	{
		Q_OBJECT

	public:
		ComboBoxItemDelegate(QObject* parent = nullptr);
		// TODO: Create a destructor; free the attributes

		QPainterPath background_path(
			const QStyleOptionViewItem& option,
			const QModelIndex& index) const;

		virtual void paint(QPainter* painter,
			const QStyleOptionViewItem& option,
			const QModelIndex& index) const override;

		void set_is_above_control(bool condition = true);

	protected:
		Attribute* m_corner_radius{ new Attribute(
			"corner_radius",
			Variant(10.0)
			) };

		Attribute* m_fill{ new Attribute(
			"fill", VariantMap({
				{ "Selected", QColor(Qt::green) },
				{ "Unselected", QColor(Qt::white) }
				})
			) };

		Attribute* m_text_color{ new Attribute(
			"text_color",
			QColor(Qt::black)
			) };

	private:
		void init_attributes();

		bool m_is_above_control{ false };
	};
}

#endif // COMBOBOXDELEGATE_H  
