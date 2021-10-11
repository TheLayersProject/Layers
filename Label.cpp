#include "Layers.h"

using Layers::Label;

Label::Label(QWidget* parent) : QLabel(parent)
{
	init_attributes();

	set_icon(new Graphic(":/svgs/label_icon.svg", QSize(17, 6)) );
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

		Color_Attribute_Widget* hover_color_caw = new Color_Attribute_Widget("Hover Color", m_attribute_set.attribute("color_hover"), true);

		m_customize_panel->add_attribute_widget(color_caw);
		m_customize_panel->add_attribute_widget(hover_color_caw);
	}
}

void Label::issue_update()
{
	update();
}

void Label::resize()
{
	QFontMetrics font_metrics(font());

	int unwrapped_width = m_padding_left + font_metrics.horizontalAdvance(text()) + 2 + m_padding_right;
	int unwrapped_height = m_padding_top + font_metrics.height() + m_padding_bottom;

	if (unwrapped_width > m_available_width && wordWrap())
	{
		m_wrapping = true;

		QLabel::setFixedWidth(m_available_width);

		build_wrapped_lines();

		int wrapped_height = m_padding_top + font_metrics.height() * m_wrapped_lines.count() + m_padding_bottom;

		QLabel::setFixedHeight(wrapped_height);
	}
	else
	{
		m_wrapping = false;

		QLabel::setFixedSize(unwrapped_width, unwrapped_height);
	}
}

void Label::build_wrapped_lines()
{
	m_wrapped_lines.clear();

	QFontMetrics font_metrics(font());

	QList<QString> lines = text().split("\n");

	for (QString& line : lines)
	{
		int line_width = font_metrics.horizontalAdvance(line) + 2;

		if (line_width > width())
		{
			while (line != "")
			{
				QString sub_line = line;

				QList<QString> sub_line_words = sub_line.split(" ");

				while (font_metrics.horizontalAdvance(sub_line) + 2 > width() && !sub_line_words.isEmpty())
				{
					sub_line = sub_line.left(sub_line.count() - sub_line_words.takeLast().count() - 1);
				}

				m_wrapped_lines.append(sub_line);

				line.remove(0, sub_line.count() + 1);
			}
		}
		else m_wrapped_lines.append(line);
	}
}

void Label::setFont(const QFont& f)
{
	QLabel::setFont(f);

	if (!m_resize_disabled) resize();
}

void Label::setMaximumWidth(int maxw)
{
	QLabel::setMaximumWidth(maxw);

	if (!m_resize_disabled) resize();
}

void Label::setWordWrap(bool on)
{
	QLabel::setWordWrap(on);

	if (!m_resize_disabled) resize();
}

void Label::set_available_width(int available_width)
{
	m_available_width = available_width;

	if (!m_resize_disabled) resize();
}

void Label::set_font_size(int size)
{
	QFont f = font();

	f.setPointSize(size);

	setFont(f);

	if (!m_resize_disabled) resize();
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

	if (!m_resize_disabled) resize();
}

void Label::set_resize_disabled(bool disable)
{
	m_resize_disabled = disable;
}

int Label::width_unwrapped()
{
	QFontMetrics font_metrics(font());

	return m_padding_left + font_metrics.horizontalAdvance(text()) + 2 + m_padding_right;
}

void Label::setText(const QString& text)
{
	QLabel::setText(text);

	if (!m_resize_disabled) resize();
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
	painter.setFont(label_font);
	painter.setPen(pen);

	if (!m_attribute_set.attribute_value("background_disabled")->value<bool>()) painter.fillRect(QRect(0, 0, width(), height()), fill_brush);

	if (wordWrap() && m_wrapping)
	{
		QFontMetrics font_metrics(font());

		for (int i = 0; i < m_wrapped_lines.count(); i++)
		{
			path.addText(m_padding_left, m_padding_top + label_font.pointSizeF() + (font_metrics.height() * i), label_font, m_wrapped_lines[i]);
		}
	}
	else
		path.addText(m_padding_left, m_padding_top + label_font.pointSizeF(), label_font, text());

	if (!m_attribute_set.attribute_value("outline_disabled")->value<bool>()) painter.strokePath(path, pen);

	painter.fillPath(path, text_brush);
	painter.end();
}
