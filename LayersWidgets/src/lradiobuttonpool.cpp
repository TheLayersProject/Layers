#include <LayersWidgets/lradiobuttonpool.h>

#include <LayersWidgets/lradiobutton.h>

using Layers::LRadioButtonPool;

LRadioButtonPool::LRadioButtonPool(QList<LRadioButton*> radio_buttons) :
	m_radio_buttons{ radio_buttons }
{
	set_active(m_radio_buttons.first());

	for (LRadioButton* radio_button : m_radio_buttons)
		connect(radio_button, &LRadioButton::clicked, [this, radio_button]
			{ set_active(radio_button); });
}

void LRadioButtonPool::set_active(LRadioButton* button)
{
	if (m_radio_buttons.contains(button) && m_active_button != button)
	{
		if (m_active_button)
			m_active_button->set_state("Inactive");

		m_active_button = button;
		m_active_button->set_state("Active");
	}
}
