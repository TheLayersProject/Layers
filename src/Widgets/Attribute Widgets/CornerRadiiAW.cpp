#include "../../../include/AttributeWidgets.h"

#include <QIntValidator>

using Layers::CornerRadiiAW;
using Layers::MiniSlider;
using Layers::Theme;

CornerRadiiAW::CornerRadiiAW(AttributeGroup* corner_radii_ag, QWidget* parent) :
	m_attribute_widget{ new AttributeWidget }, AWGroup("Corner Radii", parent)
{
	init_child_themeable_reference_list();

	add_attribute_widget(m_attribute_widget);

	m_attribute_widget->setFixedSize(260, 177);
	m_attribute_widget->a_fill.set_disabled();

	m_tl_line_editor->set_default_value("0");
	m_tl_line_editor->set_font_size(13);
	m_tl_line_editor->set_name("line_editor");
	m_tl_line_editor->set_text("0");
	m_tl_line_editor->set_validator(new QIntValidator(0, 30));

	m_tr_line_editor->set_default_value("0");
	m_tr_line_editor->set_font_size(13);
	m_tr_line_editor->set_name("line_editor");
	m_tr_line_editor->set_text("0");
	m_tr_line_editor->set_validator(new QIntValidator(0, 30));

	m_bl_line_editor->set_default_value("0");
	m_bl_line_editor->set_font_size(13);
	m_bl_line_editor->set_name("line_editor");
	m_bl_line_editor->set_text("0");
	m_bl_line_editor->set_validator(new QIntValidator(0, 30));

	m_br_line_editor->set_default_value("0");
	m_br_line_editor->set_font_size(13);
	m_br_line_editor->set_name("line_editor");
	m_br_line_editor->set_text("0");
	m_br_line_editor->set_validator(new QIntValidator(0, 30));

	m_tl_slider->set_name("mini_slider");
	m_tr_slider->set_name("mini_slider");
	m_bl_slider->set_name("mini_slider");
	m_br_slider->set_name("mini_slider");

	m_example_widget->setFixedSize(50, 50);
	m_example_widget->set_name("example_widget");

	// Set sliders' to control themeable's corner radii attributes
	if (corner_radii_ag->attributes().contains("corner_radius_tl"))
		m_tl_slider->a_value.get_values_from(*corner_radii_ag->attributes()["corner_radius_tl"]);
	if (corner_radii_ag->attributes().contains("corner_radius_tr"))
		m_tr_slider->a_value.get_values_from(*corner_radii_ag->attributes()["corner_radius_tr"]);
	if (corner_radii_ag->attributes().contains("corner_radius_bl"))
		m_bl_slider->a_value.get_values_from(*corner_radii_ag->attributes()["corner_radius_bl"]);
	if (corner_radii_ag->attributes().contains("corner_radius_br"))
		m_br_slider->a_value.get_values_from(*corner_radii_ag->attributes()["corner_radius_br"]);

	// Replace line editors' a_text attributes with sliders' a_value attributes
	m_tl_line_editor->a_text.get_values_from(m_tl_slider->a_value);
	m_tr_line_editor->a_text.get_values_from(m_tr_slider->a_value);
	m_bl_line_editor->a_text.get_values_from(m_bl_slider->a_value);
	m_br_line_editor->a_text.get_values_from(m_br_slider->a_value);

	m_tl_line_editor->reconnect_text_attribute();
	m_tr_line_editor->reconnect_text_attribute();
	m_bl_line_editor->reconnect_text_attribute();
	m_br_line_editor->reconnect_text_attribute();

	// Replace example widget's corner radii attributes with sliders' 'value' attributes
	m_example_widget->a_corner_radius_tl.get_values_from(m_tl_slider->a_value);
	m_example_widget->a_corner_radius_tr.get_values_from(m_tr_slider->a_value);
	m_example_widget->a_corner_radius_bl.get_values_from(m_bl_slider->a_value);
	m_example_widget->a_corner_radius_br.get_values_from(m_br_slider->a_value);

	setup_layout();
}

void CornerRadiiAW::replace_all_attributes_with(CornerRadiiAW* corner_radii_aw)
{
	AWGroup::replace_all_attributes_with(corner_radii_aw);

	if (m_example_widget) m_example_widget->replace_all_attributes_with(corner_radii_aw->m_example_widget);
	if (m_tl_line_editor) m_tl_line_editor->replace_all_attributes_with(corner_radii_aw->m_tl_line_editor);
	if (m_tr_line_editor) m_tr_line_editor->replace_all_attributes_with(corner_radii_aw->m_tr_line_editor);
	if (m_bl_line_editor) m_bl_line_editor->replace_all_attributes_with(corner_radii_aw->m_bl_line_editor);
	if (m_br_line_editor) m_br_line_editor->replace_all_attributes_with(corner_radii_aw->m_br_line_editor);
	if (m_tl_slider) m_tl_slider->replace_all_attributes_with(corner_radii_aw->m_tl_slider);
	if (m_tr_slider) m_tr_slider->replace_all_attributes_with(corner_radii_aw->m_tr_slider);
	if (m_bl_slider) m_bl_slider->replace_all_attributes_with(corner_radii_aw->m_bl_slider);
	if (m_br_slider) m_br_slider->replace_all_attributes_with(corner_radii_aw->m_br_slider);
}

MiniSlider* CornerRadiiAW::tl_slider() const { return m_tl_slider; }

MiniSlider* CornerRadiiAW::tr_slider() const { return m_tr_slider; }

MiniSlider* CornerRadiiAW::bl_slider() const { return m_bl_slider; }

MiniSlider* CornerRadiiAW::br_slider() const { return m_br_slider; }

void CornerRadiiAW::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_attribute_widget);
	add_child_themeable_reference(m_tl_line_editor);
	add_child_themeable_reference(m_tr_line_editor);
	add_child_themeable_reference(m_bl_line_editor);
	add_child_themeable_reference(m_br_line_editor);
	add_child_themeable_reference(m_tl_slider);
	add_child_themeable_reference(m_tr_slider);
	add_child_themeable_reference(m_bl_slider);
	add_child_themeable_reference(m_br_slider);
	add_child_themeable_reference(m_example_widget);
}

void CornerRadiiAW::setup_layout()
{
	QHBoxLayout* top_controls_hbox = new QHBoxLayout;
	QHBoxLayout* bottom_controls_hbox = new QHBoxLayout;

	top_controls_hbox->setContentsMargins(0, 0, 0, 0);
	top_controls_hbox->addWidget(m_tl_line_editor);
	top_controls_hbox->addWidget(m_tl_slider);
	top_controls_hbox->addStretch();
	top_controls_hbox->addWidget(m_tr_slider);
	top_controls_hbox->addWidget(m_tr_line_editor);

	bottom_controls_hbox->setContentsMargins(0, 0, 0, 0);
	bottom_controls_hbox->addWidget(m_bl_line_editor);
	bottom_controls_hbox->addWidget(m_bl_slider);
	bottom_controls_hbox->addStretch();
	bottom_controls_hbox->addWidget(m_br_slider);
	bottom_controls_hbox->addWidget(m_br_line_editor);

	m_main_layout->setContentsMargins(0, 0, 0, 0);
	m_main_layout->addLayout(top_controls_hbox);
	m_main_layout->addWidget(m_example_widget);
	m_main_layout->addLayout(bottom_controls_hbox);
	m_main_layout->setAlignment(m_example_widget, Qt::AlignHCenter);

	m_attribute_widget->setLayout(m_main_layout);
}
