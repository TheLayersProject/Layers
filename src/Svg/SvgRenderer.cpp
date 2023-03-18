#include "SvgRenderer.h"

#include <QFile>

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

	//if (m_svg_str.contains("BLOCK_THEMING"))
	//	m_theming_blocked = true;

	init_svg_elements_list();

	//init_size();

	//if (!m_theming_blocked)
	//	// Call init_attributes() AFTER m_svg_elements has been initialized
	//	init_attributes();

	load(m_svg_str.toUtf8());
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
	//if (!m_theming_blocked)
	//{
	for (int i = 0; i < m_svg_elements.size(); i++)
	{
		if (m_svg_elements[i].startsWith("<path") && m_svg_elements[i].contains("id="))
		{
			//if (m_hovering)
			//{
			//	if (a_use_common_hover_color.as<bool>())
			//	{
			//		m_svg_elements[i].replace(m_svg_elements[i].indexOf("fill=") + 6, 7, a_common_hover_color.as<QColor>().name());
			//	}
			//}
			//else
			//{
			if (a_use_common_color.as<bool>())
			{
				m_svg_elements[i].replace(m_svg_elements[i].indexOf("fill=") + 6, 7, a_common_color.as<QColor>().name());
			}
			//}
		}
	}

	rebuild_svg_str();

	load(m_svg_str.toUtf8());
	//}
}

void SvgRenderer::init_attributes()
{
	m_entities.insert({
		{ "common_color", &a_common_color },
		//{ "common_hover_color", &a_common_hover_color },
		{ "use_common_color", &a_use_common_color }
		//{ "use_common_hover_color", &a_use_common_hover_color }
		});

	//for (Entity* entity : m_entities)
	//	entity->setup_widget_update_connection(this);

	connect(&a_common_color, &Entity::value_changed, [this] { update(); });
	//connect(&a_common_hover_color, &Entity::value_changed, [this] { update(); });
	connect(&a_use_common_color, &Entity::value_changed, [this] { update(); });
	//connect(&a_use_common_hover_color, &Entity::value_changed, [this] { update(); });
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
