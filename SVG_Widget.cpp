#include "Layers.h"

using Layers::SVG_Widget;

SVG_Widget::SVG_Widget(QString file_path, QWidget* parent) : QSvgWidget(parent)
{
	QFile file(file_path);

	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&file);
		m_svg_str = in.readAll();
		file.close();
	}

	build_svg_elements_list();

	init_attributes(); // Necessary to call after m_svg_elements has been initialized

	load(m_svg_str.toUtf8());
}

SVG_Widget::SVG_Widget(const SVG_Widget& svg_w)
{
	m_svg_str = svg_w.m_svg_str;
	m_svg_elements = svg_w.m_svg_elements;

	init_attributes(); // Necessary to call after m_svg_elements has been initialized

	load(m_svg_str.toUtf8());
}

void SVG_Widget::init_attributes()
{
	add_attribute("use_common_color", true);
	add_attribute("use_common_hover_color", true);

	add_attribute("common_color", QColor(Qt::black));
	add_attribute("common_hover_color", QColor(Qt::darkGray));

	// Build attributes from elements
	for (int i = 0; i < m_svg_elements.size(); i++)
	{
		if (m_svg_elements[i].startsWith("<path") && m_svg_elements[i].contains("id="))
		{
			QString l_element_id = element_id(m_svg_elements[i]);

			if (!m_attributes.contains("#" + l_element_id + "/color"))
			{
				// Get ID's Default Fill Color
				int color_start_index = m_svg_elements[i].indexOf("fill=") + 6;
				int color_end_index = m_svg_elements[i].indexOf("\"", color_start_index);
				int color_length = color_end_index - color_start_index;

				QString color = m_svg_elements[i].mid(color_start_index, color_length);

				add_attribute("#" + l_element_id + "/color", QColor(color));
				add_attribute("#" + l_element_id + "/hover_color", QColor(color));
			}
		}
	}
}

void SVG_Widget::init_attribute_widgets()
{
	if (m_customize_panel)
	{
		Color_Attribute_Widget* common_color_caw = new Color_Attribute_Widget("Common Color", m_attributes["common_color"], true);
		Color_Attribute_Widget* common_hover_color_caw = new Color_Attribute_Widget("Common Hover Color", m_attributes["common_hover_color"], true);

		m_customize_panel->add_attribute_widget(common_color_caw);
		m_customize_panel->add_attribute_widget(common_hover_color_caw);

		// Add attribute widget references

		m_attribute_widgets["common_color_caw"] = common_color_caw;
		m_attribute_widgets["common_hover_color_caw"] = common_hover_color_caw;
	}
}

void SVG_Widget::issue_update()
{
	update();
}

void SVG_Widget::rebuild_svg_str()
{
	QString new_svg_str = "";

	for (QString tag : m_svg_elements)
	{
		new_svg_str += tag;
	}

	m_svg_str = new_svg_str;
}

void SVG_Widget::set_hovering(bool cond)
{
	m_hovering = cond;

	update_theme_dependencies();
}

void SVG_Widget::update_theme_dependencies()
{
	for (int i = 0; i < m_svg_elements.size(); i++)
	{
		if (m_svg_elements[i].startsWith("<path") && m_svg_elements[i].contains("id="))
		{
			if (m_hovering)
			{
				if (attributes()["use_common_hover_color"].value().value<bool>() && attributes().contains("common_hover_color"))
				{
					m_svg_elements[i].replace(m_svg_elements[i].indexOf("fill=") + 6, 7, attributes()["common_hover_color"].value().value<QColor>().name());
				}
				else if (attributes().contains("#" + element_id(m_svg_elements[i]) + "/hover_color"))
				{
					m_svg_elements[i].replace(m_svg_elements[i].indexOf("fill=") + 6, 7, attributes()["#" + element_id(m_svg_elements[i]) + "/hover_color"].value().value<QColor>().name());
				}
			}
			else
			{
				if (attributes()["use_common_color"].value().value<bool>() && attributes().contains("common_color"))
				{
					m_svg_elements[i].replace(m_svg_elements[i].indexOf("fill=") + 6, 7, attributes()["common_color"].value().value<QColor>().name());
				}
				else if (attributes().contains("#" + element_id(m_svg_elements[i]) + "/color"))
				{
					m_svg_elements[i].replace(m_svg_elements[i].indexOf("fill=") + 6, 7, attributes()["#" + element_id(m_svg_elements[i]) + "/color"].value().value<QColor>().name());
				}
			}
		}
	}

	rebuild_svg_str();

	load(m_svg_str.toUtf8());
}

void SVG_Widget::build_svg_elements_list()
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

QString SVG_Widget::element_id(const QString& element)
{
	int id_start_index = element.indexOf("id=") + 4;
	int id_end_index = element.indexOf("\"", id_start_index);
	int id_length = id_end_index - id_start_index;

	return element.mid(id_start_index, id_length);
}
