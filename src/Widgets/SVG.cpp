#include "../../include/AttributeWidgets.h"
#include "../../include/CustomizePanel.h"
#include "../../include/SVG.h"

#include <QFile>

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

	if (m_svg_str.contains("BLOCK_THEMING"))
		m_theming_blocked = true;

	build_svg_elements_list();

	init_size();

	if (!m_theming_blocked)
		init_attributes(); // Necessary to call after m_svg_elements has been initialized

	load(m_svg_str.toUtf8());
}

SVG::SVG(const SVG& svg)
{
	m_svg_str = svg.m_svg_str;
	m_svg_elements = svg.m_svg_elements;

	m_theming_blocked = svg.m_theming_blocked;

	setFixedSize(svg.size());

	if (!m_theming_blocked)
	{
		init_attributes(); // Necessary to call after m_svg_elements has been initialized

		a_common_color.copy_value_from(svg.a_common_color);
		a_common_hover_color.copy_value_from(svg.a_common_hover_color);
		a_use_common_color.copy_value_from(svg.a_use_common_color);
		a_use_common_hover_color.copy_value_from(svg.a_use_common_hover_color);
	}

	load(m_svg_str.toUtf8());
}

void SVG::apply_theme_attributes(QMap<QString, AttributeType*>& theme_attrs)
{
	a_common_color.copy_value_from(*dynamic_cast<Attribute*>(theme_attrs["common_color"]));
	a_common_hover_color.copy_value_from(*dynamic_cast<Attribute*>(theme_attrs["common_hover_color"]));
	a_use_common_color.copy_value_from(*dynamic_cast<Attribute*>(theme_attrs["use_common_color"]));
	a_use_common_hover_color.copy_value_from(*dynamic_cast<Attribute*>(theme_attrs["use_common_hover_color"]));
}

void SVG::init_attributes()
{
	m_attributes.insert({
		{ "common_color", &a_common_color },
		{ "common_hover_color", &a_common_hover_color },
		{ "use_common_color", &a_use_common_color },
		{ "use_common_hover_color", &a_use_common_hover_color }
		});

	connect(&a_common_color, &AttributeType::value_changed, [this] { update(); });
	connect(&a_common_hover_color, &AttributeType::value_changed, [this] { update(); });
	connect(&a_use_common_color, &AttributeType::value_changed, [this] { update(); });
	connect(&a_use_common_hover_color, &AttributeType::value_changed, [this] { update(); });

	m_attribute_layout.append(&a_common_color);
	m_attribute_layout.append(&a_common_hover_color);
	//m_attribute_layout.append(&a_use_common_color);
	//m_attribute_layout.append(&a_use_common_hover_color);
}

void SVG::rebuild_svg_str()
{
	QString new_svg_str = "";

	for (const QString& tag : m_svg_elements)
	{
		new_svg_str += tag;
	}

	m_svg_str = new_svg_str;
}

void SVG::set_hovering(bool cond)
{
	m_hovering = cond;

	update();
}

void SVG::set_state(const QString& state)
{
	Themeable::set_state(state);

	update();
}

void SVG::update()
{
	if (!m_theming_blocked)
	{
		for (int i = 0; i < m_svg_elements.size(); i++)
		{
			if (m_svg_elements[i].startsWith("<path") && m_svg_elements[i].contains("id="))
			{
				if (m_hovering)
				{
					if (a_use_common_hover_color.as<bool>())
					{
						m_svg_elements[i].replace(m_svg_elements[i].indexOf("fill=") + 6, 7, a_common_hover_color.as<QColor>().name());
					}
				}
				else
				{
					if (a_use_common_color.as<bool>())
					{
						m_svg_elements[i].replace(m_svg_elements[i].indexOf("fill=") + 6, 7, a_common_color.as<QColor>().name());
					}
				}
			}
		}

		rebuild_svg_str();

		load(m_svg_str.toUtf8());

		//QSvgWidget::update();
	}
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
