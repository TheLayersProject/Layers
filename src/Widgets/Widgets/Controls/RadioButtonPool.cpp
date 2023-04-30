#include "RadioButtonPool.h"

#include "RadioButton.h"

using Layers::RadioButtonPool;

RadioButtonPool::RadioButtonPool(QList<RadioButton*> radio_buttons) :
	m_radio_buttons{ radio_buttons }
{
	for (RadioButton* radio_button : radio_buttons)
		connect(radio_button, &RadioButton::clicked, [this, radio_button]
			{
				if (m_active_radio_button)
					m_active_radio_button->set_state("Inactive");

				m_active_radio_button = radio_button;
				m_active_radio_button->set_state("Active");
			});
}
