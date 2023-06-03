#include "NewGraphic.h"

using Layers::ImageSequence;
using Layers::NewGraphic;
using Layers::SvgRenderer;

NewGraphic::NewGraphic(const QString& file_path, QSize size, QWidget* parent)
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

NewGraphic::NewGraphic(const QImage& image, QWidget* parent) :
	m_image{ new QImage(image) }
{
	m_size = m_image->size();
}

NewGraphic::NewGraphic(const NewGraphic& graphic)
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

NewGraphic::~NewGraphic()
{
	if (m_svg_renderer)
	{
		delete m_svg_renderer;
		//QObject::disconnect(m_repaint_connection);
	}
	else if (m_image)
		delete m_image;
	else if (m_image_sequence)
		delete m_image_sequence;
}

QImage* NewGraphic::image() const
{
	return m_image;
}

ImageSequence* NewGraphic::image_sequence() const
{
	return m_image_sequence;
}

//QList<Themeable*> Graphic::child_themeables(Qt::FindChildOptions options)
//{
//	QList<Themeable*> child_themeables;
//
//	if (m_svg)
//		child_themeables.append(m_svg);
//
//	return child_themeables;
//}

QSize NewGraphic::size() const
{
	return m_size;
}

SvgRenderer* NewGraphic::svg_renderer() const
{
	return m_svg_renderer;
}
