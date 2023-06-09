#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QHeaderView>
#include <QTableView>
#include <QStyledItemDelegate>

#include "SvgRenderer.h"
#include "Themeable.h"

namespace Layers
{
	/*!
		A TableView is a QTableView and a Themeable that displays items from a
		model in the form of a table.
	*/
	class TableView : public QTableView, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs a table view.
		*/
		TableView(QWidget* parent = nullptr);

		// TODO: Create a destructor; free the attributes

		virtual QList<Themeable*> child_themeables(
			Qt::FindChildOptions options = Qt::FindDirectChildrenOnly) override;

		/*!
			Sets the item delegate of the table view.
		*/
		void setItemDelegate(QAbstractItemDelegate* item_delegate);

		/*!
			Updates the height of the table view.
		*/
		void update_height();

	private:
		void init_attributes();

		void update_stylesheet();

		BorderAttributes* m_border{ new BorderAttributes };

		CornerRadiiAttributes* m_corner_radii{ new CornerRadiiAttributes };

		Attribute* m_fill{
			new Attribute("fill", QColor(Qt::white)) };

		Attribute* m_item_fill{
			new Attribute("item_fill", QColor(Qt::white)) };

		QAbstractItemDelegate* m_table_delegate{ nullptr };

		Attribute* m_text_color{
			new Attribute("text_color", QColor(Qt::black)) };

		int m_visible_row_limit{ 3 };
	};
}

#endif // TABLEVIEW_H
