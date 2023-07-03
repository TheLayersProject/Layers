#include <Layers/lcornerradiieditor.h>

#include <QIntValidator>

using Layers::LCornerRadiiEditor;
using Layers::LMiniSlider;
using Layers::LTheme;
using Layers::LThemeable;

LCornerRadiiEditor::LCornerRadiiEditor(
	const QString& name,
	LAttributeMap corner_radii,
	QWidget* parent
) :
	m_attribute_editor{ new LAttributeEditor },
	LAttributeEditorGroup(name, parent)
{
	add_attribute_editor(m_attribute_editor);
	set_name("Corner Radii Editor");

	m_attribute_editor->set_name("Editor");

	QIntValidator validator = QIntValidator(0, 30);

	for (LLineEditor* line_editor :
		QList<LLineEditor*>({
			m_tl_line_editor, m_tr_line_editor,
			m_bl_line_editor, m_br_line_editor
			}))
	{
		line_editor->set_default_value("0");
		line_editor->set_font_size(13);
		line_editor->set_text("0");
		line_editor->set_validator(&validator);
	}

	m_tl_line_editor->set_name("TL Line Editor");
	m_tr_line_editor->set_name("TR Line Editor");
	m_bl_line_editor->set_name("BL Line Editor");
	m_br_line_editor->set_name("BR Line Editor");

	m_tl_slider->set_name("TL Slider");
	m_tr_slider->set_name("TR Slider");
	m_bl_slider->set_name("BL Slider");
	m_br_slider->set_name("BR Slider");

	m_example_widget->setFixedSize(50, 50);
	m_example_widget->set_name("Example Widget");

	if (!corner_radii.isEmpty())
	{
		// Entangle sliders' value attributes with linked_corner_radii attributes
		m_tl_slider->value().establish_link(*corner_radii["corner_radii.top_left"]);
		m_tr_slider->value().establish_link(*corner_radii["corner_radii.top_right"]);
		m_bl_slider->value().establish_link(*corner_radii["corner_radii.bottom_left"]);
		m_br_slider->value().establish_link(*corner_radii["corner_radii.bottom_right"]);
	}

	// Entangle line editors' text attributes with sliders' value attributes
	m_tl_line_editor->text()->establish_link(m_tl_slider->value());
	m_tr_line_editor->text()->establish_link(m_tr_slider->value());
	m_bl_line_editor->text()->establish_link(m_bl_slider->value());
	m_br_line_editor->text()->establish_link(m_br_slider->value());

	m_tl_line_editor->update();
	m_tr_line_editor->update();
	m_bl_line_editor->update();
	m_br_line_editor->update();

	// Replace example widget's corner radii attributes with sliders' 'value' attributes
	m_example_widget->corner_radii_top_left()->establish_link(m_tl_slider->value());
	m_example_widget->corner_radii_top_right()->establish_link(m_tr_slider->value());
	m_example_widget->corner_radii_bottom_left()->establish_link(m_bl_slider->value());
	m_example_widget->corner_radii_bottom_right()->establish_link(m_br_slider->value());
	//m_example_widget->attribute_data().attr_groups.remove("corner_radii");

	for (LAttribute* attr : m_example_widget->attributes())
		if (attr->name().startsWith("corner_radii"))
			attr->setParent(nullptr);

	init_layout();
}

void LCornerRadiiEditor::init_layout()
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

	m_attribute_editor->setLayout(m_main_layout);
}
