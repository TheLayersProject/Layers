#include "../../include/AttributeWidgets.h"
#include "../../include/Graphic.h"

using Layers::Graphic;
using Layers::SVG;

Graphic::Graphic(const ImageSequence& image_sequence, QSize size, QWidget* parent) :
	m_image_sequence_label{ new ImageSequenceLabel(image_sequence, size) }, Widget(parent)
{
	m_fill->set_disabled();
	init_layout();
	init_max_size();
}

Graphic::Graphic(const QString& filepath, QSize size, QWidget* parent) :
	Widget(parent)
{
	if (filepath.endsWith(".png") || filepath.endsWith(".jpg") ||
		filepath.endsWith(".jpeg") || filepath.endsWith(".bmp") ||
		filepath.endsWith(".gif"))
	{
		m_bitmap_label = new QLabel;
		m_bitmap_label->setPixmap(QPixmap(filepath));
		m_bitmap_label->setFixedSize(size);
	}
	else if (filepath.endsWith(".svg"))
	{
		m_svg_widget = new SVG(filepath);
		m_svg_widget->set_name("svg");
		m_svg_widget->set_proper_name("SVG");
		m_svg_widget->setFixedSize(size);
	}

	m_fill->set_disabled();
	init_layout();
	init_max_size();
}

Graphic::Graphic(const QString& filepath, QWidget* parent) : Widget(parent)
{
	if (filepath.endsWith(".png") || filepath.endsWith(".jpg") ||
		filepath.endsWith(".jpeg") || filepath.endsWith(".bmp") ||
		filepath.endsWith(".gif"))
	{
		QPixmap pixmap(filepath);

		m_bitmap_label = new QLabel;
		m_bitmap_label->setPixmap(pixmap);
		m_bitmap_label->setFixedSize(pixmap.size());
		setFixedSize(pixmap.size());
	}
	else if (filepath.endsWith(".svg"))
	{
		m_svg_widget = new SVG(filepath);
		m_svg_widget->set_name("svg");
		m_svg_widget->set_proper_name("SVG");
	}

	m_fill->set_disabled();
	init_layout();
	init_max_size();
}

Graphic::Graphic(const QImage& image, QWidget* parent) :
	Widget(parent)
{
	m_bitmap_label = new QLabel;
	m_bitmap_label->setPixmap(QPixmap::fromImage(image));
	m_bitmap_label->setFixedSize(image.size());

	m_fill->set_disabled();
	init_layout();
	init_max_size();
}

Graphic::Graphic(const Graphic& gw) : Widget()
{
	if (gw.m_image_sequence_label)
	{
		m_image_sequence_label = new ImageSequenceLabel(*gw.m_image_sequence_label);
		m_image_sequence_label->setFixedSize(gw.m_image_sequence_label->size());
	}
	else if (gw.m_bitmap_label)
	{
		m_bitmap_label = new QLabel;
		m_bitmap_label->setPixmap(QPixmap(gw.m_bitmap_label->pixmap()));
		m_bitmap_label->setFixedSize(gw.m_bitmap_label->size());

	}
	else if (gw.m_svg_widget)
	{
		m_svg_widget = new SVG(*gw.m_svg_widget);
		m_svg_widget->set_name("svg");
		m_svg_widget->set_proper_name("SVG");
		m_svg_widget->setFixedSize(gw.m_svg_widget->size());
	}

	m_fill->set_disabled();
	init_layout();
	init_max_size();
}

Graphic::~Graphic()
{
	if (m_bitmap_label)
		m_bitmap_label->deleteLater();

	else if (m_svg_widget)
		m_svg_widget->deleteLater();

	else if (m_image_sequence_label)
		m_image_sequence_label->deleteLater();
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
		m_bitmap_label->setPixmap(pixmap);
}

SVG* Graphic::svg() const
{
	return m_svg_widget;
}

void Graphic::init_layout()
{
	QVBoxLayout* main_layout = new QVBoxLayout;

	if (m_bitmap_label)
	{
		main_layout->addWidget(m_bitmap_label);
		main_layout->setAlignment(m_bitmap_label, Qt::AlignHCenter);
	}
	else if (m_svg_widget)
	{
		main_layout->addWidget(m_svg_widget);
		main_layout->setAlignment(m_svg_widget, Qt::AlignHCenter);
	}
	else if (m_image_sequence_label)
	{
		main_layout->addWidget(m_image_sequence_label);
		main_layout->setAlignment(m_image_sequence_label, Qt::AlignHCenter);
	}

	main_layout->setContentsMargins(0, 0, 0, 0);
	main_layout->setSpacing(0);

	setLayout(main_layout);
}

void Graphic::init_max_size()
{
	QSize new_size;

	if (m_bitmap_label)
		new_size = m_bitmap_label->size();
	else if (m_svg_widget)
		new_size = m_svg_widget->size();
	else if (m_image_sequence_label)
		new_size = m_image_sequence_label->size();

	setMaximumSize(new_size);
}
