#include "../../../include/AttributeWidgets.h"

using Layers::Attribute;
using Layers::FillAW;
using Layers::FillControl;
using Layers::Theme;

FillAW::FillAW(Attribute* attribute, QWidget* parent) :
	m_attribute_label{ new Label(attribute->name()) },
	m_disabled_toggle{ new ToggleSwitch }, AttributeWidget(parent)
{
	init_child_themeable_reference_list();

	// Setup Attribute Label
	m_attribute_label->set_name("label");
	m_attribute_label->set_font_size(14);
	m_attribute_label->set_padding(0, 7, 0, 0);

	// Setup Left Stretch
	m_left_stretch->a_fill.set_disabled();
	m_left_stretch->hide();

	// Setup Right Stretch
	m_right_stretch->a_fill.set_disabled();

	// Setup Disabling Attribute Toggle
	connect(m_disabled_toggle, &ToggleSwitch::toggled_event, [this, attribute] {
		if (m_disabled_toggle->toggled())
		{
			m_fill_control->show();

			attribute->set_disabled(false);
		}
		else
		{
			m_fill_control->hide();

			attribute->set_disabled();
		}
		});

	if (!attribute->disabled()) m_disabled_toggle->toggle();
	else m_fill_control->hide();

	// Setup Color Control
	m_fill_control->set_attribute(attribute);

	// Setup Layout
	QHBoxLayout* hbox = new QHBoxLayout;
	hbox->setContentsMargins(8, 0, 8, 0);
	hbox->setSpacing(0);
	hbox->addWidget(m_left_stretch);
	hbox->addWidget(m_attribute_label);
	hbox->addSpacing(14);
	hbox->addWidget(m_disabled_toggle);
	hbox->addSpacing(6);
	hbox->addWidget(m_fill_control);
	hbox->addWidget(m_right_stretch);
	setLayout(hbox);
}

FillControl* FillAW::fill_control() const
{
	return m_fill_control;
}

void FillAW::replace_all_attributes_with(FillAW* fill_aw)
{
	Widget::replace_all_attributes_with(fill_aw);

	if (m_attribute_label) m_attribute_label->replace_all_attributes_with(fill_aw->m_attribute_label);
	if (m_disabled_toggle) m_disabled_toggle->replace_all_attributes_with(fill_aw->m_disabled_toggle);
}

void FillAW::set_centered(bool centered)
{
	if (m_centered != centered)
	{
		m_centered = centered;

		if (m_centered) m_left_stretch->show();
		else m_left_stretch->hide();
	}
}

void FillAW::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_attribute_label);
	if (m_disabled_toggle) add_child_themeable_reference(m_disabled_toggle);
}
