#include <Layers/llabel.h>

#include <QPainter>

using Layers::LAttribute;
using Layers::LGraphic;
using Layers::LLabel;
using Layers::LThemeable;

LLabel::LLabel(QWidget* parent) :
	QLabel(parent)
{
	init();
}

LLabel::LLabel(const QString& text, QWidget* parent) :
	QLabel(text, parent)
{
	init();
}

LLabel::LLabel(const LGraphic& graphic, QWidget* parent) :
	m_graphic{ new LGraphic(graphic) },
	QLabel(parent)
{
	init();

	if (m_graphic->svg_renderer())
	{
		m_repaint_connection =
			connect(m_graphic->svg_renderer(), &LSvgRenderer::repaintNeeded,
				[this] { QWidget::update(); });
	}
	else if (m_graphic->image_sequence())
	{
		connect(&m_timer, &QTimer::timeout, [this]
			{ QWidget::update(); });

		m_timer.start(17);
	}

	setMinimumSize(m_graphic->size());
}

LLabel::~LLabel()
{
	disconnect(m_repaint_connection);

	delete m_fill;

	if (!m_text_color->parent())
		delete m_text_color;
}

QList<LThemeable*> LLabel::child_themeables(Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables;

	if (m_graphic && m_graphic->svg_renderer())
		child_themeables.append(m_graphic->svg_renderer());

	return child_themeables;
}

LAttribute* LLabel::fill() const
{
	return m_fill;
}

LGraphic* LLabel::graphic() const
{
	return m_graphic;
}

LAttribute* LLabel::text_color() const
{
	return m_text_color;
}

void LLabel::set_font_size(int size)
{
	QFont f = font();

	f.setPointSize(size);

	setFont(f);
}

void LLabel::set_font_size_f(qreal size)
{
	QFont f = font();

	f.setPointSizeF(size);

	setFont(f);
}

QSize LLabel::sizeHint() const
{
	if (m_graphic)
		return m_graphic->size();
	else
		return QLabel::sizeHint();
}

void LLabel::paintEvent(QPaintEvent* event)
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
		else if (LImageSequence* imgseq = m_graphic->image_sequence())
		{
			if (QImage* next_frame = imgseq->frame(m_frame++))
				painter.drawImage(x, y, *next_frame);
				
			if (m_frame == imgseq->size())
				m_frame = 0;
		}
	}
	else
		QLabel::paintEvent(event);
}

void LLabel::update()
{
	QStringList s = states();

	QString style_sheet = "QLabel {";

	// TEMP:
	//style_sheet += "background: " + m_fill->as<QColor>(s).name() + ";";
	style_sheet += "background: transparent;";

	if (!m_graphic)
		style_sheet += "color: " + m_text_color->as<QColor>(s).name() + ";";

	style_sheet += "}";

	setStyleSheet(style_sheet);

	QWidget::update();
}

void LLabel::init()
{
	init_attributes();

	if (!m_graphic)
		set_icon(LGraphic(":/images/label_icon.svg", QSize(17, 6)));

	update();
}

void LLabel::init_attributes()
{
	if (!m_graphic)
		m_text_color->setParent(this);
}
