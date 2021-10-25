#include "../../../include/AttributeWidgets.h"

#include <QIntValidator>

using Layers::CornerRadiiAttributeWidget;
using Layers::MiniSlider;
using Layers::Theme;

CornerRadiiAttributeWidget::CornerRadiiAttributeWidget(Themeable* themeable, bool is_primary, QWidget* parent) :
	m_attribute_widget{ new AttributeWidget(is_primary) }, AttributeWidgetContainer("Corner Radii", is_primary, parent)
{
	init_child_themeable_reference_list();

	//store_attribute_pointer(themeable->attribute("corner_radius_tl"));

	add_attribute_widget(m_attribute_widget);

	m_attribute_widget->setFixedSize(260, 177);
	m_attribute_widget->set_stateless_attribute_value("background_disabled", true);

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
	m_tl_slider->set_attribute(themeable->attribute("corner_radius_tl"));
	m_tr_slider->set_attribute(themeable->attribute("corner_radius_tr"));
	m_bl_slider->set_attribute(themeable->attribute("corner_radius_bl"));
	m_br_slider->set_attribute(themeable->attribute("corner_radius_br"));

	// Replace line editors' 'text' attributes with sliders' 'value' attributes
	m_tl_line_editor->replace_attribute_with_proxy("text", m_tl_slider->attribute("value"));
	m_tr_line_editor->replace_attribute_with_proxy("text", m_tr_slider->attribute("value"));
	m_bl_line_editor->replace_attribute_with_proxy("text", m_bl_slider->attribute("value"));
	m_br_line_editor->replace_attribute_with_proxy("text", m_br_slider->attribute("value"));

	m_tl_line_editor->reconnect_text_attribute();
	m_tr_line_editor->reconnect_text_attribute();
	m_bl_line_editor->reconnect_text_attribute();
	m_br_line_editor->reconnect_text_attribute();

	// Replace example widget's corner radii attributes with sliders' 'value' attributes
	m_example_widget->replace_attribute_with_proxy("corner_radius_tl", m_tl_slider->attribute("value"));
	m_example_widget->replace_attribute_with_proxy("corner_radius_tr", m_tr_slider->attribute("value"));
	m_example_widget->replace_attribute_with_proxy("corner_radius_bl", m_bl_slider->attribute("value"));
	m_example_widget->replace_attribute_with_proxy("corner_radius_br", m_br_slider->attribute("value"));

	setup_layout();
}

MiniSlider* CornerRadiiAttributeWidget::tl_slider() const { return m_tl_slider; }

MiniSlider* CornerRadiiAttributeWidget::tr_slider() const { return m_tr_slider; }

MiniSlider* CornerRadiiAttributeWidget::bl_slider() const { return m_bl_slider; }

MiniSlider* CornerRadiiAttributeWidget::br_slider() const { return m_br_slider; }

void CornerRadiiAttributeWidget::init_child_themeable_reference_list()
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

void CornerRadiiAttributeWidget::setup_layout()
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
