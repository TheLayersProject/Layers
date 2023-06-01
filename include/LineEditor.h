#ifndef LINEEDITOR_H
#define LINEEDITOR_H

#include <QLineEdit>

#include "Widget.h"

namespace Layers
{
	/*!
		A LineEditor is a Widget that allows the user to edit a single line of
		text.
	*/
	class LineEditor : public Widget
	{
		Q_OBJECT

	signals:
		/*!
			This signal is emitted when the line editor's text is changed.
		*/
		void text_edited(const QString& text);

	public:
		/*!
			Constructs a line editor.
		*/
		LineEditor(QWidget* parent = nullptr);

		~LineEditor();

		/*!
			Returns a pointer to the left-padding attribute of the line editor.
		*/
		Attribute* left_padding() const;

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
			Sets the default value to be used in the line editor if it is left
			empty after losing focus.
		*/
		void set_default_value(const QString& default_value);

		/*!
			Sets the *size* of the label's font.
		*/
		void set_font_size(int size);

		/*!
			Sets all margin attributes with one value.
		*/
		void set_margin(int margin);

		/*!
			Sets the margin attributes individually.
		*/
		void set_margin(int left, int top, int right, int bottom);

		/*!
			Sets the line editor's text.
		*/
		void set_text(const QString& text);

		/*!
			Sets the validator to constrain values entered into the line
			editor.
		*/
		void set_validator(const QValidator* validator);

		/*!
			Returns a pointer to the text color attribute of the line editor.
		*/
		Attribute* text_color() const;

		/*!
			Returns a pointer to the text attribute of the line editor.
		*/
		Attribute* text() const;

	public slots:
		void set_current_editting_state(const QString& state);

		void update_theme_dependencies();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private:
		void init_attributes();

		Attribute* m_left_padding{ new Attribute("left_padding", QVariant::fromValue(3.0)) };
		Attribute* m_text_color{ new Attribute("text_color", QColor(Qt::black)) };
		Attribute* m_text{ new Attribute("text", QString("")) };

		QString* m_default_value{ nullptr };

		QLineEdit* m_line_edit{ new QLineEdit(this) };
	};
}

#endif // LINEEDITOR_H
