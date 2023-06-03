#include "Graphic.h"

using Layers::Graphic;
using Layers::ImageSequence;
using Layers::SvgRenderer;

Graphic::Graphic(const QString& file_path, QSize size, QWidget* parent)
{
	if (file_path.endsWith(".png") || file_path.endsWith(".jpg") ||
		file_path.endsWith(".jpeg") || file_path.endsWith(".bmp") ||
		file_path.endsWith(".gif"))
	{
		m_image = new QImage(file_path);
	}
	else if (file_path.endsWith(".svg"))
	{
		m_svg_renderer = new SvgRenderer(file_path);
		m_svg_renderer->set_name("Svg");
	}
	else if (file_path.endsWith(".imgseq"))
	{
		m_image_sequence = new ImageSequence(QFile(file_path));
	}

	if (size.isValid())
		m_size = size;
	else if (m_svg_renderer)
		m_size = m_svg_renderer->defaultSize();
	else if (m_image)
		m_size = m_image->size();
	else if (m_image_sequence)
		m_size = (*m_image_sequence)[0].size();
}

Graphic::Graphic(const QImage& image, QWidget* parent) :
	m_image{ new QImage(image) }
{
	m_size = m_image->size();
}

Graphic::Graphic(const Graphic& graphic)
{
	if (graphic.m_svg_renderer)
	{
		m_svg_renderer = new SvgRenderer(*graphic.m_svg_renderer);
		m_svg_renderer->set_name("Svg");
	}
	else if (graphic.m_image)
	{
		m_image = new QImage(*graphic.m_image);
	}
	else if (graphic.m_image_sequence)
	{
		m_image_sequence = new ImageSequence(*graphic.m_image_sequence);
	}

	m_size = graphic.m_size;
}

Graphic::~Graphic()
{
	if (m_svg_renderer)
		delete m_svg_renderer;
	else if (m_image)
		delete m_image;
	else if (m_image_sequence)
		delete m_image_sequence;
}

QImage* Graphic::image() const
{
	return m_image;
}

ImageSequence* Graphic::image_sequence() const
{
	return m_image_sequence;
}

QSize Graphic::size() const
{
	return m_size;
}

SvgRenderer* Graphic::svg_renderer() const
{
	return m_svg_renderer;
}
