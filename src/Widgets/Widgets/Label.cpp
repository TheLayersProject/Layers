#include "Label.h"

#include "Graphic.h"

#include <QPainter>

using Layers::Attribute;
using Layers::NewGraphic;
using Layers::Label;
using Layers::Themeable;

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

Label::Label(const NewGraphic& graphic, QWidget* parent) :
	m_graphic{ new NewGraphic(graphic) }
{
	init();

	if (m_graphic->svg_renderer())
	{
		connect(m_graphic->svg_renderer(), &QSvgRenderer::repaintNeeded,
			[this] { update(); });
	}
	else
	{
		connect(&m_timer, &QTimer::timeout, [this] {
			m_timer.start(17);
			update();
			});

		m_timer.start(17);
	}

	setMinimumSize(m_graphic->size());
}

Label::~Label()
{
	delete m_fill;
	delete m_text_color;

	m_fill = nullptr;
	m_text_color = nullptr;
}

QList<Themeable*> Label::child_themeables(Qt::FindChildOptions options)
{
	QList<Themeable*> child_themeables;

	if (m_graphic && m_graphic->svg_renderer())
		child_themeables.append(m_graphic->svg_renderer());

	return child_themeables;
}

Attribute* Label::fill() const
{
	return m_fill;
}

NewGraphic* Label::graphic() const
{
	return m_graphic;
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

void Label::paintEvent(QPaintEvent* event)
{
	if (m_graphic)
	{
		QPainter painter = QPainter(this);

		QSize graphic_size = m_graphic->size();

		int x = 0;
		int y = 0;

		Qt::Alignment a = alignment();

		if (a & Qt::AlignHCenter)
			x = (width() / 2) - (graphic_size.width() / 2);
		else if (a & Qt::AlignRight)
			x = width() - graphic_size.width();

		if (a & Qt::AlignVCenter)
			y = (height() / 2) - (graphic_size.height() / 2);
		else if (a & Qt::AlignBottom)
			y = height() - graphic_size.height();

		if (m_graphic->svg_renderer())
		{
			m_graphic->svg_renderer()->render(&painter,
				QRectF(QPoint(x, y), graphic_size));
		}
		else if (m_graphic->image())
		{
			painter.drawImage(x, y, *m_graphic->image());
		}
		else if (ImageSequence* imgseq = m_graphic->image_sequence())
		{
			painter.drawImage(x, y, (*imgseq)[m_frame++]);
				
			if (m_frame == imgseq->size())
				m_frame = 0;
		}
	}
	else
		QLabel::paintEvent(event);
}

void Label::update_stylesheet()
{
	QString stylesheet = "QLabel {";

	if (!m_fill->disabled())
		stylesheet += "background: " + m_fill->as<QColor>().name() + ";";

	if (!m_graphic)
		stylesheet += "color: " + m_text_color->as<QColor>().name() + ";";

	stylesheet += "}";

	setStyleSheet(stylesheet);
	update();
}

void Label::init()
{
	init_attributes();

	if (!m_graphic)
		set_icon(new Graphic(":/svgs/label_icon.svg", QSize(17, 6)));

	update_stylesheet();
}

void Label::init_attributes()
{
	m_attributes.insert("fill", m_fill);

	if (!m_graphic)
		m_attributes.insert("text_color", m_text_color);

	for (AbstractAttribute* attribute : m_attributes)
		connect(attribute, &AbstractAttribute::changed,
			this, &Label::update_stylesheet);
}
