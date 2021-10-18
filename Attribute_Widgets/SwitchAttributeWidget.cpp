#include "../Layers.h"

using Layers::StatelessAttribute;
using Layers::SwitchAttributeWidget;
using Layers::Theme;

SwitchAttributeWidget::SwitchAttributeWidget(
	const QString& first_label_text, AttributeWidget* first_attribute_widget,
	const QString& second_label_text, AttributeWidget* second_attribute_widget,
	StatelessAttribute* control_attribute, bool is_primary, QWidget* parent) :
	m_labeled_toggle_switch{ new ToggleSwitch(first_label_text, second_label_text) },
	m_first_attribute_widget{ first_attribute_widget }, m_second_attribute_widget{ second_attribute_widget },
	m_control_attribute{ control_attribute }, AttributeWidget(is_primary, parent)
{
	setFixedHeight(45 + first_attribute_widget->height());

	m_labeled_toggle_switch->set_name("labeled_toggle");

	QHBoxLayout* hbox = new QHBoxLayout;

	hbox->setContentsMargins(0, 0, 0, 0);
	hbox->setSpacing(0);
	hbox->addStretch();
	hbox->addWidget(m_labeled_toggle_switch);
	hbox->addStretch();

	QVBoxLayout* vbox = new QVBoxLayout;

	vbox->setContentsMargins(8, 0, 8, 0);
	vbox->setSpacing(0);
	vbox->addLayout(hbox);
	vbox->addWidget(first_attribute_widget);
	vbox->addWidget(second_attribute_widget);

	add_child_themeable_reference(m_labeled_toggle_switch);
	setLayout(vbox);

	connect(m_labeled_toggle_switch, &ToggleSwitch::toggled_event, [this] {
		if (m_labeled_toggle_switch->toggled())
		{
			setFixedHeight(45 + m_second_attribute_widget->height());

			m_first_attribute_widget->hide();
			m_second_attribute_widget->show();

			m_control_attribute->set_value(false);
			m_control_attribute->parent_themeable()->share_attributes();
			m_control_attribute->parent_themeable()->issue_update();
		}
		else
		{
			setFixedHeight(45 + m_first_attribute_widget->height());

			m_first_attribute_widget->show();
			m_second_attribute_widget->hide();

			m_control_attribute->set_value(true);
			m_control_attribute->parent_themeable()->share_attributes();
			m_control_attribute->parent_themeable()->issue_update();
		}
	});

	if (!m_control_attribute->value().value<bool>())
	{
		setFixedHeight(45 + m_second_attribute_widget->height());

		m_first_attribute_widget->hide();

		m_control_attribute->set_value(false);
		m_control_attribute->parent_themeable()->share_attributes();
		m_control_attribute->parent_themeable()->issue_update();
	}
	else
	{
		setFixedHeight(45 + m_first_attribute_widget->height());

		m_second_attribute_widget->hide();

		m_control_attribute->set_value(true);
		m_control_attribute->parent_themeable()->share_attributes();
		m_control_attribute->parent_themeable()->issue_update();
	}
}

void SwitchAttributeWidget::apply_theme(Theme& theme)
{
	if (m_control_attribute->value().value<bool>() && m_labeled_toggle_switch->toggled())
		m_labeled_toggle_switch->toggle();
	else if (!m_control_attribute->value().value<bool>() && !m_labeled_toggle_switch->toggled())
		m_labeled_toggle_switch->toggle();

	Themeable::apply_theme(theme);
}

void SwitchAttributeWidget::enable_secondary_background_color(bool cond)
{
	AttributeWidget::enable_secondary_background_color(cond);

	m_first_attribute_widget->enable_secondary_background_color(cond);
	m_second_attribute_widget->enable_secondary_background_color(cond);
}
