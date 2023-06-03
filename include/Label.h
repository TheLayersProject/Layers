#ifndef LABEL_H
#define LABEL_H

#include <QLabel>

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
		Label(const QString& text, QWidget* parent = nullptr);

		~Label();

		/*!
			Returns a pointer to the fill attribute of the label.
		*/
		Attribute* fill() const;

		/*!
			Sets the *size* of the label's font.
		*/
		void set_font_size(int size);

		/*!
			Returns a pointer to the text color attribute of the label.
		*/
		Attribute* text_color() const;

	//protected:
	//	void paintEvent(QPaintEvent* event);

	private slots:
		void update_stylesheet();

	private:
		void init();
		void init_attributes();

		bool m_contains_text{ true };

		Attribute* m_fill{
			new Attribute("fill", QColor(Qt::white), true) };

		Attribute* m_text_color{
			new Attribute("text_color", QColor(Qt::black)) };
	};
}

#endif // LABEL_H
