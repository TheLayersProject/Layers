#include "Label.h"

#include "Graphic.h"

#include <QPainterPath>

using Layers::Attribute;
using Layers::Label;

Label::Label(QWidget* parent) :
	QLabel(parent)
{
	init();
}

Label::Label(const QString& text, QWidget* parent) :
	QLabel(text, parent)
{
	init();
}

Label::~Label()
{
	delete m_fill;
	delete m_text_color;

	m_fill = nullptr;
	m_text_color = nullptr;
}

Attribute* Label::fill() const
{
	return m_fill;
}

Attribute* Label::text_color() const
{
	return m_text_color;
}

void Label::set_font_size(int size)
{
	QFont f = font();

	f.setPointSize(size);

	setFont(f);
}

//void Label::paintEvent(QPaintEvent* event)
//{
//}

void Label::update_stylesheet()
{
	QString stylesheet = "QLabel {";

	if (!m_fill->disabled())
		stylesheet += "background: " + m_fill->as<QColor>().name() + ";";

	if (m_contains_text)
		stylesheet += "color: " + m_text_color->as<QColor>().name() + ";";

	stylesheet += "}";

	setStyleSheet(stylesheet);
	update();
}

void Label::init()
{
	init_attributes();

	if (m_contains_text)
		set_icon(new Graphic(":/svgs/label_icon.svg", QSize(17, 6)));

	update_stylesheet();
}

void Label::init_attributes()
{
	m_attributes.insert("fill", m_fill);

	if (m_contains_text)
		m_attributes.insert("text_color", m_text_color);

	for (AbstractAttribute* attribute : m_attributes)
		connect(attribute, &AbstractAttribute::changed,
			this, &Label::update_stylesheet);
}
