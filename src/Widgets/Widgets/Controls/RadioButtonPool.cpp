#include "RadioButtonPool.h"

#include "RadioButton.h"

using Layers::RadioButtonPool;

RadioButtonPool::RadioButtonPool(QList<RadioButton*> radio_buttons) :
	m_radio_buttons{ radio_buttons }
{
	set_active(m_radio_buttons.first());

	for (RadioButton* radio_button : m_radio_buttons)
		connect(radio_button, &RadioButton::clicked, [this, radio_button]
			{ set_active(radio_button); });
}

void RadioButtonPool::set_active(RadioButton* button)
{
	if (m_radio_buttons.contains(button) && m_active_button != button)
	{
		if (m_active_button)
			m_active_button->set_state("Inactive");

		m_active_button = button;
		m_active_button->set_state("Active");
	}
}
