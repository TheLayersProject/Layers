#include "Graphic.h"

#include <QPainter>
#include <QVBoxLayout>

using Layers::Attribute;
using Layers::Graphic;

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
		init_attributes();

		m_svg = new SvgRenderer(file_path);

		// Init image
		m_image = new QImage(file_path);
		m_image->fill(qRgba(0, 0, 0, 0));

		// Render SVG to image
		QPainter image_painter(m_image);
		m_svg->render(&image_painter, QRectF(QPoint(), size));

		m_common_color->entangle_with(*m_svg->common_color());

		// Connections
		connect(m_svg->common_color(), &AbstractAttribute::value_changed, [this] {
			m_image->fill(qRgba(0, 0, 0, 0));
			QPainter image_painter(m_image);
			m_svg->render(&image_painter, QRectF(QPoint(), this->size()));
			update();
			});
	}
	else if (file_path.endsWith(".imgseq"))
	{
		m_image_sequence = new ImageSequence(QFile(file_path));

		connect(&m_timer, &QTimer::timeout, [this] {
			if (m_frame == m_image_sequence->size()) m_frame = 0;

			m_timer.start(16.6675);

			update();
			});

		m_timer.start(16.6675);
	}

	if (size.isValid())
		setMaximumSize(size);
	else if (m_image)
		setMaximumSize(m_image->size());
	else if (m_image_sequence)
		setMaximumSize((*m_image_sequence)[0].size());
}

Graphic::Graphic(const Graphic& g)
{
	if (g.m_svg)
	{
		m_svg = new SvgRenderer(*g.m_svg);
	}
	else if (g.m_image)
	{
		m_image = new QImage(*g.m_image);
	}
	else if (g.m_image_sequence)
	{
		m_image_sequence = new ImageSequence(*g.m_image_sequence);

		connect(&m_timer, &QTimer::timeout, [this] {
			if (m_frame == m_image_sequence->size()) m_frame = 0;

			m_timer.start(16.6675);

			update();
			});

		m_timer.start(16.6675);
	}

	setMaximumSize(g.maximumSize());
}

Attribute* Graphic::common_color() const
{
	return m_common_color;
}

void Graphic::paintEvent(QPaintEvent* event)
{
	QPainter painter = QPainter(this);

	if (m_image)
		painter.drawImage(0, 0, *m_image);
	else if (m_image_sequence)
		painter.drawImage(0, 0, (*m_image_sequence)[m_frame++]);
}

void Graphic::init_attributes()
{
	m_attributes.insert({
		{ "common_color", m_common_color }
		});

	for (AbstractAttribute* entity : m_attributes)
		establish_update_connection(entity);
}
