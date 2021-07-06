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
	add_attribute("Default", "background_color", QColor(Qt::white));
	add_attribute("Default", "background_disabled", true);
	add_attribute("Default", "color", QColor(Qt::black));
	add_attribute("Default", "color_active", QColor(Qt::black));
	add_attribute("Default", "color_hover", QColor(Qt::black));
	add_attribute("Default", "outline_color", QColor(Qt::white));
	add_attribute("Default", "outline_disabled", true);
}

void Label::init_attribute_widgets()
{
	if (m_customize_panel)
	{
		Color_Attribute_Widget* color_caw = new Color_Attribute_Widget("Color", m_attributes["color"], true);

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
	QBrush fill_brush(attributes()["background_color"].value().value<QColor>());
	QBrush text_brush;

	if (m_hovering) text_brush = QBrush(attributes()["color_hover"].value().value<QColor>());
	else text_brush = QBrush(attributes()["color"].value().value<QColor>());

	pen.setWidth(3);
	pen.setColor(attributes()["outline_color"].value().value<QColor>());

	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setRenderHint(QPainter::TextAntialiasing);
	painter.setRenderHint(QPainter::HighQualityAntialiasing);
	painter.setFont(label_font);
	painter.setPen(pen);

	if (!attributes()["background_disabled"].value().value<bool>()) painter.fillRect(QRect(0, 0, width(), height()), fill_brush);

	path.addText(m_padding_left, m_padding_top + label_font.pointSizeF(), label_font, text()); // Adjust the position

	if (!attributes()["outline_disabled"].value().value<bool>()) painter.strokePath(path, pen);

	painter.fillPath(path, text_brush);
	painter.end();
}
