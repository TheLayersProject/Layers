#include "../../../include/AttributeWidgets.h"

using Layers::Attribute;
using Layers::ColorAttributeWidget;
using Layers::ColorControl;
using Layers::Theme;

ColorAttributeWidget::ColorAttributeWidget(const QString& attribute_label_text, Attribute* attribute, bool is_primary, QWidget* parent) :
	m_attribute_label{ new Label(attribute_label_text) }, AttributeWidget(parent)
{
	init_child_themeable_reference_list();

	// Setup Attribute Label
	m_attribute_label->set_name("label");
	m_attribute_label->set_font_size(14);
	m_attribute_label->set_padding(0, 7, 0, 0);

	// Setup Left Stretch
	m_left_stretch->set_attribute_value("background_disabled", true);
	m_left_stretch->hide();

	// Setup Right Stretch
	m_right_stretch->set_attribute_value("background_disabled", true);

	// Setup Color Control
	m_color_control->set_attribute(attribute);

	// Setup Layout
	QHBoxLayout* hbox = new QHBoxLayout;
	hbox->setContentsMargins(8, 0, 8, 0);
	hbox->setSpacing(0);
	hbox->addWidget(m_left_stretch);
	hbox->addWidget(m_attribute_label);
	hbox->addSpacing(6);
	hbox->addWidget(m_color_control);
	hbox->addWidget(m_right_stretch);
	setLayout(hbox);
}

ColorAttributeWidget::ColorAttributeWidget(const QString& attribute_label_text, Attribute* attribute, Attribute* disabling_attribute, bool is_primary, QWidget* parent) :
	m_attribute_label{ new Label(attribute_label_text) }, m_disabling_attribute{ disabling_attribute },
	m_disabled_attribute_toggle{ new ToggleSwitch }, AttributeWidget(parent)
{
	init_child_themeable_reference_list();

	// Setup Attribute Label
	m_attribute_label->set_name("label");
	m_attribute_label->set_font_size(14);
	m_attribute_label->set_padding(0, 7, 0, 0);

	// Setup Left Stretch
	m_left_stretch->set_attribute_value("background_disabled", true);
	m_left_stretch->hide();

	// Setup Right Stretch
	m_right_stretch->set_attribute_value("background_disabled", true);

	// Setup Disabling Attribute Toggle
	m_disabled_attribute_toggle->set_name("toggle");

	connect(m_disabled_attribute_toggle, &ToggleSwitch::toggled_event, [this] {
		if (m_disabled_attribute_toggle->toggled())
		{
			m_color_control->show();

			if (m_disabling_attribute)
				m_disabling_attribute->set_value(false);
		}
		else
		{
			m_color_control->hide();

			if (m_disabling_attribute)
				m_disabling_attribute->set_value(true);
		}
	});

	if (!m_disabling_attribute->value().value<bool>())
	{
		m_disabled_attribute_toggle->toggle();
	}
	else m_color_control->hide();

	// Setup Color Control
	m_color_control->set_attribute(attribute);

	// Setup Layout
	QHBoxLayout* hbox = new QHBoxLayout;
	hbox->setContentsMargins(8, 0, 8, 0);
	hbox->setSpacing(0);
	hbox->addWidget(m_left_stretch);
	hbox->addWidget(m_attribute_label);
	hbox->addSpacing(14);
	hbox->addWidget(m_disabled_attribute_toggle);
	hbox->addSpacing(6);
	hbox->addWidget(m_color_control);
	hbox->addWidget(m_right_stretch);
	setLayout(hbox);
}

ColorControl* ColorAttributeWidget::color_control() const
{
	return m_color_control;
}

void ColorAttributeWidget::set_centered(bool centered)
{
	if (m_centered != centered)
	{
		m_centered = centered;

		if (m_centered) m_left_stretch->show();
		else m_left_stretch->hide();
	}
}

void ColorAttributeWidget::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_attribute_label);
	if (m_disabled_attribute_toggle) add_child_themeable_reference(m_disabled_attribute_toggle);
}
