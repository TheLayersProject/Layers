#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QTimer>

#include "Graphic.h"
#include "Themeable.h"

namespace Layers
{
	/*!
		A Label is a QLabel and a Themeable that is used to display text or a
		Graphic.
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

		/*!
			Constructs a label that displays *graphic*.
		*/
		Label(const Graphic& graphic, QWidget* parent = nullptr);

		~Label();

		/*!
			Returns a list of child themeables.

			This function overrides Themeable::child_themeables() to include
			a pointer to the SvgRenderer, if the label uses a graphic that has
			one.
		*/
		virtual QList<Themeable*> child_themeables(
			Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
		) override;

		/*!
			Returns a pointer to the fill attribute of the label.
		*/
		Attribute* fill() const;

		/*!
			Returns a pointer to the label's graphic.

			Returns nullptr if the label does not have a graphic.
		*/
		Graphic* graphic() const;

		/*!
			Sets the *size* of the label's font.
		*/
		void set_font_size(int size);

		/*!
			Returns the recommended size for the label.
		*/
		virtual QSize sizeHint() const override;

		/*!
			Returns a pointer to the text color attribute of the label.
		*/
		Attribute* text_color() const;

	protected:
		void paintEvent(QPaintEvent* event);

	private slots:
		void update_stylesheet();

	private:
		void init();
		void init_attributes();

		int m_frame{ 0 };

		Graphic* m_graphic{ nullptr };

		Attribute* m_fill{
			new Attribute("fill", QColor(Qt::white), true) };

		Attribute* m_text_color{
			new Attribute("text_color", QColor(Qt::black)) };

		QMetaObject::Connection m_repaint_connection;

		QTimer m_timer;
	};
}

#endif // LABEL_H
