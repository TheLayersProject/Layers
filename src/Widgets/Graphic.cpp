#include "../../include/AttributeWidgets.h"
#include "../../include/Graphic.h"

using Layers::Graphic;
using Layers::SVG;

Graphic::Graphic(const ImageSequence& image_sequence, QSize size, QWidget* parent) :
	m_image_sequence_label{ new ImageSequenceLabel(image_sequence, size, this) }, Widget(parent)
{
	setFixedSize(size);

	a_fill.set_disabled();
}

Graphic::Graphic(const QString& filepath, QSize size, QWidget* parent) :
	m_image_size{ size }, Widget(parent)
{
	if (filepath.endsWith(".png") || filepath.endsWith(".jpg") ||
		filepath.endsWith(".jpeg") || filepath.endsWith(".bmp") ||
		filepath.endsWith(".gif"))
	{
		m_bitmap_label = new QLabel(this);
		m_bitmap_label->setPixmap(QPixmap(filepath));
		m_bitmap_label->setFixedSize(size);
	}
	else if (filepath.endsWith(".svg"))
	{
		m_svg_widget = new SVG(filepath, this);
		m_svg_widget->set_name("svg");
		m_svg_widget->set_proper_name("SVG");
		m_svg_widget->setFixedSize(size);

		store_child_themeable_pointer(m_svg_widget);
	}

	setFixedSize(size);

	a_fill.set_disabled();
}

Graphic::Graphic(const QString& filepath, QWidget* parent) : Widget(parent)
{
	if (filepath.endsWith(".png") || filepath.endsWith(".jpg") ||
		filepath.endsWith(".jpeg") || filepath.endsWith(".bmp") ||
		filepath.endsWith(".gif"))
	{
		QPixmap pixmap(filepath);

		m_bitmap_label = new QLabel(this);
		m_bitmap_label->setPixmap(pixmap);
		m_bitmap_label->setFixedSize(pixmap.size());
		setFixedSize(pixmap.size());
	}
	else if (filepath.endsWith(".svg"))
	{
		m_svg_widget = new SVG(filepath, this);
		m_svg_widget->set_name("svg");
		m_svg_widget->set_proper_name("SVG");
		setFixedSize(m_svg_widget->size());
		//m_svg_widget->setFixedSize(size);

		store_child_themeable_pointer(m_svg_widget);
	}

	a_fill.set_disabled();
}

Graphic::Graphic(const QImage& image, QWidget* parent) :
	m_image_size{ image.size() }, Widget(parent)
{
	m_bitmap_label = new QLabel(this);
	m_bitmap_label->setPixmap(QPixmap::fromImage(image));
	m_bitmap_label->setFixedSize(image.size());

	setFixedSize(m_image_size);

	a_fill.set_disabled();
}

Graphic::Graphic(const Graphic& gw) : Widget()
{
	if (gw.m_image_sequence_label)
	{
		m_image_sequence_label = new ImageSequenceLabel(*gw.m_image_sequence_label);
		m_image_sequence_label->setFixedSize(gw.m_image_sequence_label->size());
		m_image_sequence_label->setParent(this);
	}
	else if (gw.m_bitmap_label)
	{
		m_bitmap_label = new QLabel(this);
		m_bitmap_label->setPixmap(QPixmap(gw.m_bitmap_label->pixmap()));
		m_bitmap_label->setFixedSize(gw.m_bitmap_label->size());

	}
	else if (gw.m_svg_widget)
	{
		m_svg_widget = new SVG(*gw.m_svg_widget);
		m_svg_widget->set_name("svg");
		m_svg_widget->set_proper_name("SVG");
		m_svg_widget->setParent(this);
		m_svg_widget->setFixedSize(gw.m_svg_widget->size());

		store_child_themeable_pointer(m_svg_widget);
	}

	m_image_size = gw.m_image_size;

	setFixedSize(gw.size());

	a_fill.set_disabled();
}

Graphic::~Graphic()
{
	if (m_bitmap_label) m_bitmap_label->deleteLater();
	if (m_svg_widget) m_svg_widget->deleteLater();
	if (m_image_sequence_label) m_image_sequence_label->deleteLater();
}

QSize Graphic::image_size()
{
	return m_image_size;
}

void Graphic::set_hovering(bool cond)
{
	if (m_svg_widget) m_svg_widget->set_hovering(cond);
}

void Graphic::set_icon(Graphic* icon)
{
	Themeable::set_icon(icon);

	if (m_svg_widget) m_svg_widget->set_icon(new Graphic(*icon));
}

void Graphic::set_pixmap(const QPixmap& pixmap)
{
	if (m_bitmap_label)
	{
		m_bitmap_label->setPixmap(pixmap);
		m_image_size = pixmap.size();
	}
}

void Graphic::set_size(QSize size)
{
	if (m_bitmap_label) m_bitmap_label->setFixedSize(size);
	if (m_svg_widget) m_svg_widget->setFixedSize(size);
	if (m_image_sequence_label) m_image_sequence_label->setFixedSize(size);

	setFixedSize(size);
}

SVG* Graphic::svg() const
{
	return m_svg_widget;
}

//void Graphic::update_theme_dependencies()
//{
//	int border_thickness = a_border_thickness.as<int>();
//
//	setFixedSize(
//		border_thickness + m_image_size.width() + border_thickness,
//		border_thickness + m_image_size.height() + border_thickness);
//
//	if (m_bitmap_label) m_bitmap_label->move(border_thickness, border_thickness);
//	if (m_svg_widget)
//	{
//		m_svg_widget->update_theme_dependencies();
//		m_svg_widget->move(border_thickness, border_thickness);
//	}
//	if (m_image_sequence_label) m_image_sequence_label->move(border_thickness, border_thickness);
//}
