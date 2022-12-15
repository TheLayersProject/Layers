#include "../../../include/AttributeWidgets.h"

using Layers::Attribute;
using Layers::FillAW;
using Layers::FillControl;
using Layers::Theme;

FillAW::FillAW(Attribute* attribute, QWidget* parent) :
	m_attribute_label{ new Label(attribute->capitalized_name()) },
	AttributeWidget(attribute, parent)
{
	init_child_themeable_reference_list();

	// Setup Attribute Label
	m_attribute_label->set_name("label");
	m_attribute_label->set_proper_name("Label");
	m_attribute_label->set_font_size(14);
	m_attribute_label->set_padding(0, 7, 0, 0);

	// Setup Left Stretch
	//m_left_stretch->a_fill.set_disabled();
	//m_left_stretch->hide();

	// Setup Right Stretch
	m_right_stretch->a_fill.set_disabled();

	connect(m_disabled_toggle, &ToggleSwitch::toggled_event, [this] {
		 if (m_disabled_toggle->toggled())
		 {
		 	m_fill_control->show();

		 	m_attribute_type->set_disabled(false);
		 }
		 else
		 {
		 	m_fill_control->hide();

		 	m_attribute_type->set_disabled();

			emit widget_disabled();
		 }
	});

	if (!attribute->disabled())
		m_disabled_toggle->toggle(false);
	else
		/* TODO: Emit a signal when an attribute widget is disabled so that children,
		   like this, can handle hiding their controls */
		m_fill_control->hide();

	// Setup Control
	m_fill_control->set_attribute(attribute);

	// Setup Layout
	QHBoxLayout* hbox = new QHBoxLayout;
	hbox->setContentsMargins(8, 0, 8, 0);
	hbox->setSpacing(0);
	//hbox->addWidget(m_left_stretch);
	hbox->addWidget(m_disabled_toggle);
	hbox->addWidget(m_toggle_label_separator);
	//hbox->addSpacing(16);
	hbox->addWidget(m_attribute_label);
	//hbox->addSpacing(6);
	hbox->addWidget(m_fill_control);
	hbox->addWidget(m_right_stretch);
	setLayout(hbox);
}

FillControl* FillAW::fill_control() const
{
	return m_fill_control;
}

//void FillAW::set_centered(bool centered)
//{
//	if (m_centered != centered)
//	{
//		m_centered = centered;
//
//		if (m_centered) m_left_stretch->show();
//		else m_left_stretch->hide();
//	}
//}

void FillAW::set_current_editting_state(const QString& state)
{
	m_fill_control->set_current_editting_state(state);
}

void FillAW::init_child_themeable_reference_list()
{
	store_child_themeable_pointer(m_attribute_label);
	store_child_themeable_pointer(m_disabled_toggle);
	store_child_themeable_pointer(m_fill_control);
}
