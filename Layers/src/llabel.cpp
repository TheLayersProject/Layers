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
	m_graphic{ new LGraphic(graphic) }
{
	init();

	if (m_graphic->svg_renderer())
	{
		m_repaint_connection =
			connect(m_graphic->svg_renderer(), &LSvgRenderer::repaintNeeded,
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

LLabel::~LLabel()
{
	disconnect(m_repaint_connection);

	delete m_fill;
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
			painter.drawImage(x, y, (*imgseq)[m_frame++]);
				
			if (m_frame == imgseq->size())
				m_frame = 0;
		}
	}
	else
		QLabel::paintEvent(event);
}

void LLabel::update_stylesheet()
{
	QStringList s = states();

	QString stylesheet = "QLabel {";

	// TEMP:
	//stylesheet += "background: " + m_fill->as<QColor>(s).name() + ";";
	stylesheet += "background: transparent;";

	if (!m_graphic)
		stylesheet += "color: " + m_text_color->as<QColor>(s).name() + ";";

	stylesheet += "}";

	setStyleSheet(stylesheet);
	update();
}

void LLabel::init()
{
	init_attributes();

	if (!m_graphic)
		set_icon(LGraphic(":/images/label_icon.svg", QSize(17, 6)));

	update_stylesheet();
}

void LLabel::init_attributes()
{
	m_attr_data.ungrouped_attrs.insert("fill", m_fill);

	if (!m_graphic)
		m_attr_data.ungrouped_attrs.insert("text_color", m_text_color);

	for (LAttribute* attr : m_attr_data.ungrouped_attrs)
		connect(attr, &LAttribute::changed,
			this, &LLabel::update_stylesheet);
}
