#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QPainter>

#include "Attribute.h"
#include "Themeable.h"

namespace Layers
{
	/*!
		A Label is a QLabel and a Themeable that is used to display text.
	*/
	class Label : public QLabel, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs an empty label.
		*/
		Label(QWidget* parent = nullptr);

		/*!
			Constructs a label that displays *text*.
		*/
		Label(const QString& text, QWidget* parent = 0);

		~Label();

		/*!
			Returns a pointer to the fill attribute of the label.
		*/
		Attribute* fill() const;

		/*!
			Returns a pointer to the outline color attribute of the label.
		*/
		Attribute* outline_color() const;

		/*!
			Returns a pointer to the top-padding attribute of the label.
		*/
		Attribute* padding_top() const;

		/*!
			Sets the *font* of the label.
		*/
		void setFont(const QFont& font);

		/*!
			Enables or disables word-wrapping functionality of the label
			depending on the value of *on*.
		*/
		void setWordWrap(bool on);

		/*!
			Sets the available width of the label to *available_width*.
		*/
		void set_available_width(int available_width);

		/*!
			Sets the *size* of the label's font.
		*/
		void set_font_size(int size);

		/*!
			Sets the hovering state of the label depending on the value
			specified by *condition*.
		*/
		void set_hovering(bool condition = true);

		/*!
			Sets the label's padding values individually.
		*/
		void set_padding(double left, double top, double right, double bottom);

		/*!
			Enables or disables resizing of the label depending on the value
			specified by *disable*.
		*/
		void set_resize_disabled(bool disable = true);

		/*!
			Returns a pointer to the text color attribute of the label.
		*/
		Attribute* text_color() const;

		/*!
			Returns a pointer to the text hover color attribute of the label.
		*/
		Attribute* text_hover_color() const;

	public slots:
		void setText(const QString& text);

	protected:
		void paintEvent(QPaintEvent* event);

	private:
		void build_wrapped_lines();

		void init_attributes();

		void resize();

		QList<QString> m_wrapped_lines;

		QPainter painter;

		bool m_hovering{ false };
		bool m_resize_disabled{ false };
		bool m_wrapping{ false };

		int m_available_width{ 16777215 };

		int m_padding_left{ 0 };
		//int m_padding_top{ 0 };
		int m_padding_right{ 0 };
		int m_padding_bottom{ 0 };

		Attribute* m_fill{
			new Attribute("fill", QColor(Qt::white), true) };

		Attribute* m_outline_color{
			new Attribute("outline_color", QColor(Qt::gray), true) };

		Attribute* m_padding_top{
			new Attribute("top_padding", QVariant::fromValue(0.0)) };

		Attribute* m_text_color{
			new Attribute("text_color", QColor(Qt::black)) };

		Attribute* m_text_hover_color{
			new Attribute("text_hover_color", QColor(Qt::black), true) };
	};
}

#endif // LABEL_H
