#include "../../include/AttributeWidgets.h"
#include "../../include/CustomizePanel.h"
#include "../../include/Label.h"

#include <QPainterPath>

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

void Label::apply_theme_attributes(QMap<QString, AttributeType*>& theme_attrs)
{
	a_fill.copy(*dynamic_cast<Attribute*>(theme_attrs["fill"]));
	a_text_hover_color.copy(*dynamic_cast<Attribute*>(theme_attrs["text_hover_color"]));
	a_outline_color.copy(*dynamic_cast<Attribute*>(theme_attrs["outline_color"]));
	a_text_color.copy(*dynamic_cast<Attribute*>(theme_attrs["text_color"]));
}

void Label::init_attributes()
{
	m_attributes.insert({
		{ "fill", &a_fill },
		{ "text_hover_color", &a_text_hover_color },
		{ "outline_color", &a_outline_color },
		{ "text_color", &a_text_color }
	});

	m_attribute_layout.append(&a_text_color);
	m_attribute_layout.append(&a_text_hover_color);
	m_attribute_layout.append(&a_outline_color);
	m_attribute_layout.append(&a_fill);

	for (AttributeType* attr_type : m_attributes)
		attr_type->setup_widget_update_connection(this);
}

void Label::resize()
{
	QFontMetrics font_metrics(font());

	int unwrapped_width = m_padding_left + font_metrics.horizontalAdvance(text()) + 2 + m_padding_right;
	int unwrapped_height = a_padding_top.as<double>() + font_metrics.height() + m_padding_bottom;

	if (unwrapped_width > m_available_width && wordWrap())
	{
		m_wrapping = true;

		QLabel::setFixedWidth(m_available_width);

		build_wrapped_lines();

		int wrapped_height = a_padding_top.as<double>() + font_metrics.height() * m_wrapped_lines.count() + m_padding_bottom;

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

void Label::set_padding(double left, double top, double right, double bottom)
{
	m_padding_left = left;
	a_padding_top.set_value(top);
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
	QBrush fill_brush(a_fill.as<QColor>());
	QBrush text_brush;

	if (m_hovering) text_brush = QBrush(a_text_hover_color.as<QColor>());
	else text_brush = QBrush(a_text_color.as<QColor>());

	pen.setWidth(3);
	pen.setColor(a_outline_color.as<QColor>());

	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setRenderHint(QPainter::TextAntialiasing);
	painter.setFont(label_font);
	painter.setPen(pen);

	if (!a_fill.disabled()) painter.fillRect(QRect(0, 0, width(), height()), fill_brush);

	if (wordWrap() && m_wrapping)
	{
		QFontMetrics font_metrics(font());

		for (int i = 0; i < m_wrapped_lines.count(); i++)
		{
			path.addText(m_padding_left, a_padding_top.as<double>() + label_font.pointSizeF() + (font_metrics.height() * i), label_font, m_wrapped_lines[i]);
		}
	}
	else
		path.addText(m_padding_left, a_padding_top.as<double>() + label_font.pointSizeF(), label_font, text());

	if (!a_outline_color.disabled()) painter.strokePath(path, pen);

	painter.fillPath(path, text_brush);
	painter.end();
}
