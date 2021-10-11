#include "Layers.h"

using Layers::SVG;

SVG::SVG(QString file_path, QWidget* parent) : QSvgWidget(parent)
{
	QFile file(file_path);

	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&file);
		m_svg_str = in.readAll();
		file.close();
	}

	build_svg_elements_list();

	init_size();

	init_attributes(); // Necessary to call after m_svg_elements has been initialized

	load(m_svg_str.toUtf8());
}

SVG::SVG(const SVG& svg)
{
	m_svg_str = svg.m_svg_str;
	m_svg_elements = svg.m_svg_elements;

	setFixedSize(svg.size());

	init_attributes(); // Necessary to call after m_svg_elements has been initialized

	load(m_svg_str.toUtf8());
}

void SVG::init_attributes()
{
	// TODO: Think this should be false by default
	add_stateless_attribute("use_common_color", false);
	add_stateless_attribute("use_common_hover_color", false);

	add_stateless_attribute("common_color", QColor(Qt::black));
	add_stateless_attribute("common_hover_color", QColor(Qt::darkGray));

	// Build attributes from elements
	for (int i = 0; i < m_svg_elements.size(); i++)
	{
		if (m_svg_elements[i].startsWith("<path") && m_svg_elements[i].contains("id="))
		{
			QString l_element_id = element_id(m_svg_elements[i]);

			if (!m_attribute_set.contains("#" + l_element_id + "/color"))
			{
				// Get ID's Default Fill Color
				int color_start_index = m_svg_elements[i].indexOf("fill=") + 6;
				int color_end_index = m_svg_elements[i].indexOf("\"", color_start_index);
				int color_length = color_end_index - color_start_index;

				QString color = m_svg_elements[i].mid(color_start_index, color_length);

				add_stateless_attribute("#" + l_element_id + "/color", QColor(color));
				add_stateless_attribute("#" + l_element_id + "/hover_color", QColor(color));
			}
		}
	}
}

void SVG::init_attribute_widgets()
{
	if (m_customize_panel)
	{
		if (m_attribute_set.attribute_value("use_common_color")->value<bool>())
		{
			Color_Attribute_Widget* common_color_caw = new Color_Attribute_Widget("Common Color", m_attribute_set.attribute("common_color"), true);
			m_customize_panel->add_attribute_widget(common_color_caw);
			m_attribute_widgets["common_color_caw"] = common_color_caw;
		}

		if (m_attribute_set.attribute_value("use_common_hover_color")->value<bool>())
		{
			Color_Attribute_Widget* common_hover_color_caw = new Color_Attribute_Widget("Common Hover Color", m_attribute_set.attribute("common_hover_color"), true);
			m_customize_panel->add_attribute_widget(common_hover_color_caw);
			m_attribute_widgets["common_hover_color_caw"] = common_hover_color_caw;
		}
	}
}

void SVG::issue_update()
{
	update();
}

void SVG::rebuild_svg_str()
{
	QString new_svg_str = "";

	for (QString tag : m_svg_elements)
	{
		new_svg_str += tag;
	}

	m_svg_str = new_svg_str;
}

void SVG::set_hovering(bool cond)
{
	m_hovering = cond;

	update_theme_dependencies();
}

void SVG::update_theme_dependencies()
{
	for (int i = 0; i < m_svg_elements.size(); i++)
	{
		if (m_svg_elements[i].startsWith("<path") && m_svg_elements[i].contains("id="))
		{
			if (m_hovering)
			{
				if (m_attribute_set.attribute_value("use_common_hover_color")->value<bool>() && m_attribute_set.contains("common_hover_color"))
				{
					m_svg_elements[i].replace(m_svg_elements[i].indexOf("fill=") + 6, 7, m_attribute_set.attribute_value("common_hover_color")->value<QColor>().name());
				}
				else if (m_attribute_set.contains("#" + element_id(m_svg_elements[i]) + "/hover_color"))
				{
					m_svg_elements[i].replace(m_svg_elements[i].indexOf("fill=") + 6, 7, m_attribute_set.attribute_value("#" + element_id(m_svg_elements[i]) + "/hover_color")->value<QColor>().name());
				}
			}
			else
			{
				if (m_attribute_set.attribute_value("use_common_color")->value<bool>() && m_attribute_set.contains("common_color"))
				{
					m_svg_elements[i].replace(m_svg_elements[i].indexOf("fill=") + 6, 7, m_attribute_set.attribute_value("common_color")->value<QColor>().name());
				}
				else if (m_attribute_set.contains("#" + element_id(m_svg_elements[i]) + "/color"))
				{
					m_svg_elements[i].replace(m_svg_elements[i].indexOf("fill=") + 6, 7, m_attribute_set.attribute_value("#" + element_id(m_svg_elements[i]) + "/color")->value<QColor>().name());
				}
			}
		}
	}

	rebuild_svg_str();

	load(m_svg_str.toUtf8());
}

void SVG::init_size()
{
	QSize initial_size(1, 1);

	QString svg_open_tag = m_svg_elements[0];

	svg_open_tag = svg_open_tag.replace("\n", "");
	svg_open_tag = svg_open_tag.replace("<", "");
	svg_open_tag = svg_open_tag.replace(">", "");

	QStringList svg_open_tag_parts = svg_open_tag.split(" ");

	svg_open_tag_parts.removeOne("svg");

	svg_open_tag_parts.removeAll("");

	for (const QString& svg_open_tag_part : svg_open_tag_parts)
	{
		if (svg_open_tag_part.contains("width"))
		{
			QString width_string = svg_open_tag_part.split("=").last();

			width_string.replace("\"", "");

			width_string.chop(2);

			initial_size.setWidth(width_string.toInt());
		}
		else if (svg_open_tag_part.contains("height"))
		{
			QString height_string = svg_open_tag_part.split("=").last();

			height_string.replace("\"", "");

			height_string.chop(2);

			initial_size.setHeight(height_string.toInt());
		}
	}

	setFixedSize(initial_size);
}

void SVG::build_svg_elements_list()
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

QString SVG::element_id(const QString& element)
{
	int id_start_index = element.indexOf("id=") + 4;
	int id_end_index = element.indexOf("\"", id_start_index);
	int id_length = id_end_index - id_start_index;

	return element.mid(id_start_index, id_length);
}
