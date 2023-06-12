#include <LayersCore/lgraphic.h>

using Layers::LGraphic;
using Layers::LImageSequence;
using Layers::LSvgRenderer;

LGraphic::LGraphic(const QString& file_path, QSize size, QWidget* parent)
{
	if (file_path.endsWith(".png") || file_path.endsWith(".jpg") ||
		file_path.endsWith(".jpeg") || file_path.endsWith(".bmp") ||
		file_path.endsWith(".gif"))
	{
		m_image = new QImage(file_path);
	}
	else if (file_path.endsWith(".svg"))
	{
		m_svg_renderer = new LSvgRenderer(file_path);
		m_svg_renderer->set_name("Svg");
	}
	else if (file_path.endsWith(".imgseq"))
	{
		m_image_sequence = new LImageSequence(QFile(file_path));
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

LGraphic::LGraphic(const QImage& image, QWidget* parent) :
	m_image{ new QImage(image) }
{
	m_size = m_image->size();
}

LGraphic::LGraphic(const LGraphic& graphic)
{
	if (graphic.m_svg_renderer)
	{
		m_svg_renderer = new LSvgRenderer(*graphic.m_svg_renderer);
		m_svg_renderer->set_name("Svg");
	}
	else if (graphic.m_image)
	{
		m_image = new QImage(*graphic.m_image);
	}
	else if (graphic.m_image_sequence)
	{
		m_image_sequence = new LImageSequence(*graphic.m_image_sequence);
	}

	m_size = graphic.m_size;
}

LGraphic::~LGraphic()
{
	if (m_svg_renderer)
		delete m_svg_renderer;
	else if (m_image)
		delete m_image;
	else if (m_image_sequence)
		delete m_image_sequence;
}

QImage* LGraphic::image() const
{
	return m_image;
}

LImageSequence* LGraphic::image_sequence() const
{
	return m_image_sequence;
}

QSize LGraphic::size() const
{
	return m_size;
}

LSvgRenderer* LGraphic::svg_renderer() const
{
	return m_svg_renderer;
}
