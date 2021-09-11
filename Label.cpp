#include "Layers.h"

using Layers::Label;

Label::Label(QWidget* parent) : QLabel(parent)
{
	init_attributes();

	set_icon(new Graphic_Widget(":/svgs/label_icon.svg", QSize(17, 6)) );
}

Label::Label(const QString& text, QWidget* parent) : Label(parent)
{
	setText(text);
}

void Label::init_attributes()
{
	add_stateless_attribute("background_color", QColor(Qt::white));
	add_stateless_attribute("background_disabled", true);
	add_stateless_attribute("color", QColor(Qt::black));
	add_stateless_attribute("color_active", QColor(Qt::black));
	add_stateless_attribute("color_hover", QColor(Qt::black));
	add_stateless_attribute("outline_color", QColor(Qt::white));
	add_stateless_attribute("outline_disabled", true);
}

void Label::init_attribute_widgets()
{
	if (m_customize_panel)
	{
		Color_Attribute_Widget* color_caw = new Color_Attribute_Widget("Color", m_attribute_set.attribute("color"), true);

		m_customize_panel->add_attribute_widget(color_caw);
	}
}

void Label::issue_update()
{
	update();
}

void Label::resize()
{
	QFontMetrics font_metrics(font());

	int text_width = font_metrics.horizontalAdvance(text()) + 2;
	int text_height = font_metrics.height();

	setFixedSize(m_padding_left + text_width + m_padding_right, m_padding_top + text_height + m_padding_bottom);
}

void Label::set_font_size(int size)
{
	QFont f = font();

	f.setPointSize(size);

	setFont(f);

	resize();
}

void Label::set_hovering(bool cond)
{
	m_hovering = cond;

	update();
}

void Label::set_padding(int left, int top, int right, int bottom)
{
	m_padding_left = left;
	m_padding_top = top;
	m_padding_right = right;
	m_padding_bottom = bottom;

	resize();
}

void Label::setText(const QString& text)
{
	QLabel::setText(text);

	resize();
}

void Label::paintEvent(QPaintEvent* event)
{
	QPainterPath path;
	QPen pen;
	QFont label_font = font();
	QBrush fill_brush(m_attribute_set.attribute_value("background_color")->value<QColor>());
	QBrush text_brush;

	if (m_hovering) text_brush = QBrush(m_attribute_set.attribute_value("color_hover")->value<QColor>());
	else text_brush = QBrush(m_attribute_set.attribute_value("color")->value<QColor>());

	pen.setWidth(3);
	pen.setColor(m_attribute_set.attribute_value("outline_color")->value<QColor>());

	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setRenderHint(QPainter::TextAntialiasing);
	//painter.setRenderHint(QPainter::HighQualityAntialiasing);
	painter.setFont(label_font);
	painter.setPen(pen);

	if (!m_attribute_set.attribute_value("background_disabled")->value<bool>()) painter.fillRect(QRect(0, 0, width(), height()), fill_brush);

	if (wordWrap())
	{
		qDebug() << "Painting with word wrap!";

		QFontMetrics font_metrics(font());

		QList<QString> draw_lines;

		QList<QString> lines = text().split("\n");

		for (QString& line : lines)
		{
			qDebug() << "Line:" << line;

			int line_width = font_metrics.horizontalAdvance(line) + 2;

			qDebug() << "Line Width:" << line_width;

			if (line_width > width())
			{
				qDebug() << "\tLINE NEEDS TO BE SPLIT:";

				while (line != "")
				{
					QString sub_line = line;

					QList<QString> sub_line_words = sub_line.split(" ");

					while (font_metrics.horizontalAdvance(sub_line) + 2 > width())
					{
						sub_line = sub_line.left(sub_line.count() - sub_line_words.takeLast().count() - 1);
					}

					draw_lines.append(sub_line);

					line.remove(0, sub_line.count() + 1);
				}
			}
			else draw_lines.append(line);
		}

		for (int i = 0; i < draw_lines.count(); i++)
		{
			path.addText(m_padding_left, m_padding_top + label_font.pointSizeF() + (font_metrics.height() * i), label_font, draw_lines[i]);
		}
	}
	else
		path.addText(m_padding_left, m_padding_top + label_font.pointSizeF(), label_font, text());

	if (!m_attribute_set.attribute_value("outline_disabled")->value<bool>()) painter.strokePath(path, pen);

	painter.fillPath(path, text_brush);
	painter.end();
}
