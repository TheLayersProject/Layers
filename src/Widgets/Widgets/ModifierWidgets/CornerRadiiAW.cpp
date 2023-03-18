#include "AttributeWidgets.h"

#include <QIntValidator>

using Layers::CornerRadiiAW;
using Layers::MiniSlider;
using Layers::Theme;

CornerRadiiAW::CornerRadiiAW(CornerRadiiAttributes* linked_corner_radii, QWidget* parent) :
	m_attribute_widget{ new AttributeWidget },
	AWGroup(linked_corner_radii, parent)
{
	add_attribute_widget(m_attribute_widget);
	set_name("corner_radii_aw_group");

	m_attribute_widget->fill()->set_disabled();
	m_attribute_widget->set_name("aw");

	QIntValidator validator = QIntValidator(0, 30);

	for (LineEditor* line_editor :
		QList<LineEditor*>({
			m_tl_line_editor, m_tr_line_editor,
			m_bl_line_editor, m_br_line_editor
			}))
	{
		line_editor->set_default_value("0");
		line_editor->set_font_size(13);
		line_editor->set_name("line_editor");
		line_editor->set_text("0");
		line_editor->set_validator(&validator);
	}

	m_tl_line_editor->set_proper_name("TL Line Editor");
	m_tr_line_editor->set_proper_name("TR Line Editor");
	m_bl_line_editor->set_proper_name("BL Line Editor");
	m_br_line_editor->set_proper_name("BR Line Editor");

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

	if (linked_corner_radii)
	{
		// Entangle sliders' value attributes with linked_corner_radii attributes
		m_tl_slider->a_value.entangle_with(*linked_corner_radii->top_left());
		m_tr_slider->a_value.entangle_with(*linked_corner_radii->top_right());
		m_bl_slider->a_value.entangle_with(*linked_corner_radii->bottom_left());
		m_br_slider->a_value.entangle_with(*linked_corner_radii->bottom_right());
	}

	// Entangle line editors' text attributes with sliders' value attributes
	m_tl_line_editor->text()->entangle_with(m_tl_slider->a_value);
	m_tr_line_editor->text()->entangle_with(m_tr_slider->a_value);
	m_bl_line_editor->text()->entangle_with(m_bl_slider->a_value);
	m_br_line_editor->text()->entangle_with(m_br_slider->a_value);

	m_tl_line_editor->update_theme_dependencies();
	m_tr_line_editor->update_theme_dependencies();
	m_bl_line_editor->update_theme_dependencies();
	m_br_line_editor->update_theme_dependencies();

	// Replace example widget's corner radii attributes with sliders' 'value' attributes
	m_example_widget->corner_radii()->top_left()->entangle_with(m_tl_slider->a_value);
	m_example_widget->corner_radii()->top_right()->entangle_with(m_tr_slider->a_value);
	m_example_widget->corner_radii()->bottom_left()->entangle_with(m_bl_slider->a_value);
	m_example_widget->corner_radii()->bottom_right()->entangle_with(m_br_slider->a_value);
	m_example_widget->entities().remove("corner_radii");

	setup_layout();
}

void CornerRadiiAW::set_current_editting_state(const QString& state)
{
	m_tl_slider->set_current_editting_state(state);
	m_tr_slider->set_current_editting_state(state);
	m_bl_slider->set_current_editting_state(state);
	m_br_slider->set_current_editting_state(state);

	m_example_widget->corner_radii()->top_left()->set_state(state);
	m_example_widget->corner_radii()->top_right()->set_state(state);
	m_example_widget->corner_radii()->bottom_left()->set_state(state);
	m_example_widget->corner_radii()->bottom_right()->set_state(state);

	m_tl_line_editor->set_current_editting_state(state);
	m_tr_line_editor->set_current_editting_state(state);
	m_bl_line_editor->set_current_editting_state(state);
	m_br_line_editor->set_current_editting_state(state);
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
