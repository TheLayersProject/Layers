#include <Layers/lsvgrenderer.h>

#include <QFile>

using Layers::LAttribute;
using Layers::LSvgRenderer;

LSvgRenderer::LSvgRenderer(const QString& file_path, QObject* parent) :
	QSvgRenderer(parent)
{
	init_attributes();

	QFile file(file_path);

	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&file);
		m_svg_str = in.readAll();
		file.close();
	}

	init_svg_elements_list();

	load(m_svg_str.toUtf8());
}

LSvgRenderer::LSvgRenderer(const LSvgRenderer& svg_renderer)
{
	init_attributes();

	m_svg_str = svg_renderer.m_svg_str;

	for (const QString& svg_element : svg_renderer.m_svg_elements)
		m_svg_elements.append(svg_element);

	load(m_svg_str.toUtf8());
}

LSvgRenderer::~LSvgRenderer()
{
	delete m_common_color;
}

LAttribute* LSvgRenderer::common_color() const
{
	return m_common_color;
}

void LSvgRenderer::rebuild_svg_str()
{
	QString new_svg_str = "";

	for (const QString& tag : m_svg_elements)
	{
		new_svg_str += tag;
	}

	m_svg_str = new_svg_str;
}

void LSvgRenderer::update()
{
	for (int i = 0; i < m_svg_elements.size(); i++)
	{
		if (m_svg_elements[i].startsWith("<path") &&
			m_svg_elements[i].contains("id="))
		{
			QString common_color_name = m_common_color->as<QColor>(states()).name();

			m_svg_elements[i].replace(
				m_svg_elements[i].indexOf("fill=") + 6, 7,
				common_color_name);
		}
	}

	rebuild_svg_str();

	load(m_svg_str.toUtf8());
}

void LSvgRenderer::init_attributes()
{
	connect(m_common_color, &LAttribute::changed, [this] {
		update();
		emit repaintNeeded();
		});
}

void LSvgRenderer::init_svg_elements_list()
{
	QString temp_svg_str = QString(m_svg_str);

	while (temp_svg_str.contains("<"))
	{
		int tag_open_index = temp_svg_str.indexOf("<");
		int tag_close_index = temp_svg_str.indexOf(">");
		int tag_size = tag_close_index - tag_open_index + 1;

		m_svg_elements.append(temp_svg_str.mid(tag_open_index, tag_size));

		temp_svg_str.remove(tag_open_index, tag_size);
	}
}
