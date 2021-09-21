#include "Layers.h"

using Layers::Graphic_Widget;
using Layers::SVG_Widget;

Graphic_Widget::Graphic_Widget(const QDir& img_seq_dir, QSize size, QWidget* parent) :
	m_image_sequence_label{ new Image_Sequence_Label(img_seq_dir, size, this) }, Widget(parent)
{
	setFixedSize(size);

	set_stateless_attribute_value("background_disabled", true);
}

Graphic_Widget::Graphic_Widget(const QString& filepath, QSize size, QWidget* parent) :
	Widget(parent)
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
		m_svg_widget = new SVG_Widget(filepath, this);
		m_svg_widget->set_name("svg");
		m_svg_widget->set_proper_name("SVG");
		m_svg_widget->setFixedSize(size);

		add_child_themeable_reference(m_svg_widget);

		//filter_attribute("background_color");
		//filter_attribute("border_color");
		//filter_attribute("border_gradient_stops");
		//filter_attribute("border_thickness");
		//filter_attribute("corner_radius");
		//filter_attribute("border_gradient_disabled");
	}

	setFixedSize(size);

	set_stateless_attribute_value("background_disabled", true);
}

Graphic_Widget::Graphic_Widget(const QImage& image, QWidget* parent) :
	Widget(parent)
{
	m_bitmap_label = new QLabel(this);
	m_bitmap_label->setPixmap(QPixmap::fromImage(image));
	m_bitmap_label->setFixedSize(image.size());

	setFixedSize(image.size());

	set_stateless_attribute_value("background_disabled", true);
}

Graphic_Widget::Graphic_Widget(const Graphic_Widget& gw) : Widget()
{
	if (gw.m_image_sequence_label)
	{
		m_image_sequence_label = new Image_Sequence_Label(*gw.m_image_sequence_label);
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
		m_svg_widget = new SVG_Widget(*gw.m_svg_widget);
		m_svg_widget->set_name("svg");
		m_svg_widget->set_proper_name("SVG");
		m_svg_widget->setParent(this);
		m_svg_widget->setFixedSize(gw.m_svg_widget->size());

		add_child_themeable_reference(m_svg_widget);

		//filter_attribute("background_color");
		//filter_attribute("border_color");
		//filter_attribute("border_gradient_stops");
		//filter_attribute("border_thickness");
		//filter_attribute("corner_radius");
		//filter_attribute("border_gradient_disabled");
	}

	setFixedSize(gw.size());

	set_stateless_attribute_value("background_disabled", true);
}

void Graphic_Widget::convert_attribute_to_stateful(const QString& attribute_name, QMap<QString, QVariant> state_value_map)
{
	if (m_svg_widget) m_svg_widget->convert_attribute_to_stateful(attribute_name, state_value_map);
}

void Graphic_Widget::set_hovering(bool cond)
{
	if (m_svg_widget) m_svg_widget->set_hovering(cond);
}

void Graphic_Widget::set_icon(Graphic_Widget* icon)
{
	Themeable::set_icon(icon);

	if (m_svg_widget) m_svg_widget->set_icon(new Graphic_Widget(*icon));
}

void Graphic_Widget::set_size(QSize size)
{
	if (m_bitmap_label) m_bitmap_label->setFixedSize(size);
	if (m_svg_widget) m_svg_widget->setFixedSize(size);
	if (m_image_sequence_label) m_image_sequence_label->setFixedSize(size);

	setFixedSize(size);
}

SVG_Widget* Graphic_Widget::svg() const
{
	return m_svg_widget;
}

void Graphic_Widget::init_attribute_widgets()
{
	Widget::init_attribute_widgets();

	m_attribute_widgets["border_awc"]->set_primary(false);
	m_attribute_widgets["hover_background_caw"]->set_primary(false);
	m_attribute_widgets["outline_caw"]->set_primary(false);
	m_attribute_widgets["corner_color_caw"]->set_primary(false);
	m_attribute_widgets["corner_radii_attribute_widget"]->set_primary(false);
}
