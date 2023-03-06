#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QHeaderView>
#include <QTableView>
#include <QStyledItemDelegate>

#include "SvgRenderer.h"
#include "Themeable.h"

namespace Layers
{
	class TableView : public QTableView, public Themeable
	{
		Q_OBJECT

	public:
		TableView(QWidget* parent = nullptr);
		// TODO: Create a destructor; free the attributes

		void setItemDelegate(QAbstractItemDelegate* item_delegate);

		void update_height();

	protected:
		void init_attributes();

		void update_stylesheet();

	private:
		BorderAttributes* m_border{ new BorderAttributes };

		CornerRadiiAttributes* m_corner_radii{ new CornerRadiiAttributes };

		Attribute* m_fill{ new Attribute(
			"fill",
			QColor(Qt::white)
			) };

		Attribute* m_item_fill{ new Attribute(
			"item_fill",
			QColor(Qt::white)
			) };

		QAbstractItemDelegate* m_table_delegate{ nullptr };

		Attribute* m_text_color{ new Attribute(
			"text_color",
			QColor(Qt::black)
			) };

		int m_visible_row_limit{ 3 };
	};
}

#endif // TABLEVIEW_H  
