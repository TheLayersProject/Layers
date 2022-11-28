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

	m_attribute_widget->a_fill.set_disabled();

	m_tl_line_editor->set_default_value("0");
	m_tl_line_editor->set_font_size(13);
	m_tl_line_editor->set_name("line_editor");
	m_tl_line_editor->set_proper_name("TL Line Editor");
	m_tl_line_editor->set_text("0");
	m_tl_line_editor->set_validator(new QIntValidator(0, 30));

	m_tr_line_editor->set_default_value("0");
	m_tr_line_editor->set_font_size(13);
	m_tr_line_editor->set_name("line_editor");
	m_tr_line_editor->set_proper_name("TR Line Editor");
	m_tr_line_editor->set_text("0");
	m_tr_line_editor->set_validator(new QIntValidator(0, 30));

	m_bl_line_editor->set_default_value("0");
	m_bl_line_editor->set_font_size(13);
	m_bl_line_editor->set_name("line_editor");
	m_bl_line_editor->set_proper_name("BL Line Editor");
	m_bl_line_editor->set_text("0");
	m_bl_line_editor->set_validator(new QIntValidator(0, 30));

	m_br_line_editor->set_default_value("0");
	m_br_line_editor->set_font_size(13);
	m_br_line_editor->set_name("line_editor");
	m_br_line_editor->set_proper_name("BR Line Editor");
	m_br_line_editor->set_text("0");
	m_br_line_editor->set_validator(new QIntValidator(0, 30));

	m_tl_slider->set_name("mini_slider");
	m_tr_slider->set_name("mini_slider");
	m_bl_slider->set_name("mini_slider");
	m_br_slider->set_name("mini_slider");
	m_tl_slider->set_proper_name("TL Slider");
	m_tr_slider->set_proper_name("TR Slider");
	m_bl_slider->set_proper_name("BL Slider");
	m_br_slider->set_proper_name("BR Slider");

	m_example_widget->setFixedSize(50, 50);
	m_example_widget->set_name("example_widget");
	m_example_widget->set_proper_name("Example Widget");

	// Set sliders' to control themeable's corner radii attributes
	//if (corner_radii_ag->attributes().contains("corner_radius_tl"))
	//	m_tl_slider->a_value.get_variant_from(*corner_radii_ag->attributes()["corner_radius_tl"]);
	//if (corner_radii_ag->attributes().contains("corner_radius_tr"))
	//	m_tr_slider->a_value.get_variant_from(*corner_radii_ag->attributes()["corner_radius_tr"]);
	//if (corner_radii_ag->attributes().contains("corner_radius_bl"))
	//	m_bl_slider->a_value.get_variant_from(*corner_radii_ag->attributes()["corner_radius_bl"]);
	//if (corner_radii_ag->attributes().contains("corner_radius_br"))
	//	m_br_slider->a_value.get_variant_from(*corner_radii_ag->attributes()["corner_radius_br"]);

	if (corner_radii_ag->attributes().contains("corner_radius_tl"))
	{
		m_tl_slider->a_value.get_variant_from(*corner_radii_ag->attributes()["corner_radius_tl"]);
		m_tl_slider->update_theme_dependencies();
	}
	if (corner_radii_ag->attributes().contains("corner_radius_tr"))
	{
		m_tr_slider->a_value.get_variant_from(*corner_radii_ag->attributes()["corner_radius_tr"]);
		m_tr_slider->update_theme_dependencies();
	}
	if (corner_radii_ag->attributes().contains("corner_radius_bl"))
	{
		m_bl_slider->a_value.get_variant_from(*corner_radii_ag->attributes()["corner_radius_bl"]);
		m_bl_slider->update_theme_dependencies();
	}
	if (corner_radii_ag->attributes().contains("corner_radius_br"))
	{
		m_br_slider->a_value.get_variant_from(*corner_radii_ag->attributes()["corner_radius_br"]);
		m_br_slider->update_theme_dependencies();
	}

	// Replace line editors' a_text attributes with sliders' a_value attributes
	m_tl_line_editor->a_text.get_variant_from(m_tl_slider->a_value);
	m_tr_line_editor->a_text.get_variant_from(m_tr_slider->a_value);
	m_bl_line_editor->a_text.get_variant_from(m_bl_slider->a_value);
	m_br_line_editor->a_text.get_variant_from(m_br_slider->a_value);

	//connect(m_tl_line_editor, &LineEditor::update_theme_dependencies, [this]
	//	{
	//		m_tl_line_editor->update_theme_dependencies();
	//	});

	m_tl_line_editor->update_theme_dependencies();
	m_tr_line_editor->update_theme_dependencies();
	m_bl_line_editor->update_theme_dependencies();
	m_br_line_editor->update_theme_dependencies();

	// Replace example widget's corner radii attributes with sliders' 'value' attributes
	m_example_widget->a_corner_radius_tl.get_variant_from(m_tl_slider->a_value);
	m_example_widget->a_corner_radius_tr.get_variant_from(m_tr_slider->a_value);
	m_example_widget->a_corner_radius_bl.get_variant_from(m_bl_slider->a_value);
	m_example_widget->a_corner_radius_br.get_variant_from(m_br_slider->a_value);
	m_example_widget->attributes().remove("corner_radius_tl");
	m_example_widget->attributes().remove("corner_radius_tr");
	m_example_widget->attributes().remove("corner_radius_bl");
	m_example_widget->attributes().remove("corner_radius_br");

	setup_layout();
}

MiniSlider* CornerRadiiAW::tl_slider() const { return m_tl_slider; }

MiniSlider* CornerRadiiAW::tr_slider() const { return m_tr_slider; }

MiniSlider* CornerRadiiAW::bl_slider() const { return m_bl_slider; }

MiniSlider* CornerRadiiAW::br_slider() const { return m_br_slider; }

void CornerRadiiAW::set_current_editting_state(const QString& state)
{
	m_tl_slider->set_current_editting_state(state);
	m_tr_slider->set_current_editting_state(state);
	m_bl_slider->set_current_editting_state(state);
	m_br_slider->set_current_editting_state(state);

	m_example_widget->a_corner_radius_tl.set_state(state);
	m_example_widget->a_corner_radius_tr.set_state(state);
	m_example_widget->a_corner_radius_bl.set_state(state);
	m_example_widget->a_corner_radius_br.set_state(state);

	m_tl_line_editor->set_current_editting_state(state);
	m_tr_line_editor->set_current_editting_state(state);
	m_bl_line_editor->set_current_editting_state(state);
	m_br_line_editor->set_current_editting_state(state);
}

void CornerRadiiAW::init_child_themeable_reference_list()
{
	//store_child_themeable_pointer(m_attribute_widget);
	store_child_themeable_pointer(m_tl_line_editor);
	store_child_themeable_pointer(m_tr_line_editor);
	store_child_themeable_pointer(m_bl_line_editor);
	store_child_themeable_pointer(m_br_line_editor);
	store_child_themeable_pointer(m_tl_slider);
	store_child_themeable_pointer(m_tr_slider);
	store_child_themeable_pointer(m_bl_slider);
	store_child_themeable_pointer(m_br_slider);
	store_child_themeable_pointer(m_example_widget);
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
