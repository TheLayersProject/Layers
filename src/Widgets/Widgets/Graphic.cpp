#include "Graphic.h"

#include <QPainter>
#include <QVBoxLayout>

using Layers::Attribute;
using Layers::Graphic;
using Layers::SvgRenderer;
using Layers::Themeable;

Graphic::Graphic(const QString& file_path, QSize size, QWidget* parent) :
	QWidget(parent)
{
	if (file_path.endsWith(".png") || file_path.endsWith(".jpg") ||
		file_path.endsWith(".jpeg") || file_path.endsWith(".bmp") ||
		file_path.endsWith(".gif"))
	{
		m_image = new QImage(file_path);
	}
	else if (file_path.endsWith(".svg"))
	{
		m_svg = new SvgRenderer(file_path);
		m_svg->set_name("svg");
		m_svg->set_proper_name("SVG");

		m_repaint_connection = connect(m_svg, &QSvgRenderer::repaintNeeded,
			[this] { update(); });
	}
	else if (file_path.endsWith(".imgseq"))
	{
		m_image_sequence = new ImageSequence(QFile(file_path));

		connect(&m_timer, &QTimer::timeout, [this] {
			m_timer.start(17);
			update();
			});

		m_timer.start(17);
	}

	if (size.isValid())
		setMaximumSize(size);
	else if (m_svg)
		setMaximumSize(m_svg->defaultSize());
	else if (m_image)
		setMaximumSize(m_image->size());
	else if (m_image_sequence)
		setMaximumSize((*m_image_sequence)[0].size());

	m_draw_size = maximumSize();
}

Graphic::Graphic(const QImage& image, QWidget* parent) :
	m_image{ new QImage(image) },
	QWidget(parent)
{
	setMaximumSize(m_image->size());

	m_draw_size = maximumSize();
}

Graphic::Graphic(const Graphic& g)
{
	if (g.m_svg)
	{
		m_svg = new SvgRenderer(*g.m_svg);
		m_svg->set_name("svg");
		m_svg->set_proper_name("SVG");

		m_repaint_connection = connect(m_svg, &QSvgRenderer::repaintNeeded,
			[this] { update(); });
	}
	else if (g.m_image)
	{
		m_image = new QImage(*g.m_image);
	}
	else if (g.m_image_sequence)
	{
		m_image_sequence = new ImageSequence(*g.m_image_sequence);

		connect(&m_timer, &QTimer::timeout, [this] {
			m_timer.start(17);
			update();
			});

		m_timer.start(17);
	}

	setMaximumSize(g.maximumSize());

	m_draw_size = maximumSize();
}

Graphic::~Graphic()
{
	if (m_svg)
	{
		delete m_svg;
		QObject::disconnect(m_repaint_connection);
	}
	else if (m_image)
		delete m_image;
	else if (m_image_sequence)
		delete m_image_sequence;
}

QList<Themeable*> Graphic::child_themeables(Qt::FindChildOptions options)
{
	QList<Themeable*> child_themeables;

	if (m_svg)
		child_themeables.append(m_svg);

	return child_themeables;
}

SvgRenderer* Graphic::svg() const
{
	return m_svg;
}

void Graphic::paintEvent(QPaintEvent* event)
{
	QPainter painter = QPainter(this);

	int centered_x = (width() / 2) - (m_draw_size.width() / 2);
	int centered_y = (height() / 2) - (m_draw_size.height() / 2);

	if (m_svg)
	{
		m_svg->render(&painter,
			QRectF(QPoint(centered_x, centered_y), m_draw_size));
	}
	else if (m_image)
	{
		painter.drawImage(centered_x, centered_y, *m_image);
	}
	else if (m_image_sequence)
	{
		painter.drawImage(centered_x, centered_y,
			(*m_image_sequence)[m_frame++]);

		if (m_frame == m_image_sequence->size()) m_frame = 0;
	}
}
