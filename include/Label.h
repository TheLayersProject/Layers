#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QPainter>

#include "Themeable.h"

namespace Layers
{
	class Label : public QLabel, public Themeable
	{
		Q_OBJECT

	public:
		Label(QWidget* parent = nullptr);
		Label(const QString& text, QWidget* parent = 0);

		void init_attribute_widgets();

		void issue_update();

		void resize();

		void build_wrapped_lines();

		void setFont(const QFont& f);

		void setMaximumWidth(int maxw);

		void setWordWrap(bool on);

		void set_available_width(int available_width);
		void set_font_size(int size);
		void set_hovering(bool cond = true);
		void set_padding(int left, int top, int right, int bottom);
		void set_resize_disabled(bool disable = true);

		int width_unwrapped();

	public slots:
		void setText(const QString& text);

	protected:
		void init_attributes();
		void paintEvent(QPaintEvent* event);

		QList<QString> m_wrapped_lines;

		QPainter painter;

		bool m_hovering{ false };
		bool m_resize_disabled{ false };
		bool m_wrapping{ false };

		int m_available_width{ 16777215 };

		int m_padding_left{ 0 };
		int m_padding_top{ 0 };
		int m_padding_right{ 0 };
		int m_padding_bottom{ 0 };
	};
}

#endif // LABEL_H
