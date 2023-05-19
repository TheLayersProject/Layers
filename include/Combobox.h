#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QComboBox>
#include <QPainterPath>

#include "Themeable.h"

namespace Layers
{
	/*!
		A ComboBox is a QComboBox and a Themeable that provides the user with a
		way to select an option from a list of options.
	*/
	class ComboBox : public QComboBox, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs a ComboBox.
		*/
		ComboBox(QWidget* parent = nullptr);

		~ComboBox();

		/*!
			Returns a list of child themeables.

			This function overrides Themeable::child_themeables() to include
			the item delegate of the combo box and any children it might have.
		*/
		virtual QList<Themeable*> child_themeables(
			Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
		) override;

		/*!
			Sets both the minimum and maximum heights of the widget to *h*
			without changing the widths.
		*/
		void setFixedHeight(int h);

		/*!
			Sets both the minimum and maximum sizes of the widget to *s*,
			thereby preventing it from ever growing or shrinking.
		*/
		void setFixedSize(const QSize& s);

		/*!
			Sets the width of the widget to *w* and the height to *h*.
		*/
		void setFixedSize(int w, int h);

		/*!
			Sets both the minimum and maximum width of the widget to *w*
			without changing the heights.
		*/
		void setFixedWidth(int w);

		/*!
			Displays the list of items in the combobox.

			This function overrides QComboBox::showPopup() to inform the item
			delegate about whether the popup is being displayed above or below
			the combo box, if the item delegate is a ComboBoxItemDelegate type.
		*/
		virtual void showPopup() override;

	protected:
		/*!
			Returns a QPainterPath that represents the combo box's background.
		*/
		QPainterPath background_path() const;

		virtual bool eventFilter(QObject* object, QEvent* event) override;

		virtual void paintEvent(QPaintEvent* event) override;

		BorderAttributes* m_border{ new BorderAttributes };

		Attribute* m_corner_radius{
			new Attribute("corner_radius", Variant(10.0)) };

		Attribute* m_fill{
			new Attribute("fill", QColor(Qt::white)) };

		Attribute* m_text_color{
			new Attribute("text_color", QColor(Qt::black)) };

	private:
		void init_attributes();

		void update_stylesheet();
	};
}

#endif // COMBOBOX_H
