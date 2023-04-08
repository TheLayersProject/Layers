#include "SvgRenderer.h"

#include <QFile>

using Layers::Attribute;
using Layers::SvgRenderer;

SvgRenderer::SvgRenderer(const QString& file_path, QObject* parent) : QSvgRenderer(parent)
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

SvgRenderer::SvgRenderer(const SvgRenderer& sr)
{
	m_svg_str = sr.m_svg_str;

	for (const QString& svg_element : sr.m_svg_elements)
		m_svg_elements.append(svg_element);

	load(m_svg_str.toUtf8());
}

Attribute* SvgRenderer::common_color() const
{
	return m_common_color;
}

void SvgRenderer::rebuild_svg_str()
{
	QString new_svg_str = "";

	for (const QString& tag : m_svg_elements)
	{
		new_svg_str += tag;
	}

	m_svg_str = new_svg_str;
}

void SvgRenderer::update()
{
	for (int i = 0; i < m_svg_elements.size(); i++)
	{
		if (m_svg_elements[i].startsWith("<path") && m_svg_elements[i].contains("id="))
		{
			m_svg_elements[i].replace(m_svg_elements[i].indexOf("fill=") + 6, 7, m_common_color->as<QColor>().name());
		}
	}

	rebuild_svg_str();

	load(m_svg_str.toUtf8());
}

void SvgRenderer::init_attributes()
{
	m_attributes.insert({
		{ "common_color", m_common_color },
		//{ "use_common_color", &a_use_common_color }
		});

	connect(m_common_color, &AbstractAttribute::value_changed, [this] { update(); });
	//connect(&a_use_common_color, &AbstractAttribute::value_changed, [this] { update(); });
}

void SvgRenderer::init_svg_elements_list()
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
