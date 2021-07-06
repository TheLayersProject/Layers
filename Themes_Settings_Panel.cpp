#include "Layers.h"

using Layers::Button;
using Layers::Combobox;
using Layers::Themes_Settings_Panel;

Themes_Settings_Panel::Themes_Settings_Panel(QWidget* parent) : Widget(parent)
{
	init_child_themeable_reference_list();
	init_attributes();

	set_icon(new Graphic_Widget(":/svgs/panel_icon.svg", QSize(20, 20)));
	set_name("themes_settings_panel");
	set_proper_name("Themes Panel");

	m_theme_label->set_name("theme_label");
	m_theme_label->set_proper_name("\"Theme\" Label");
	m_theme_label->set_font_size(15);

	m_theme_combobox->set_icon(new Graphic_Widget(":/svgs/combobox_icon.svg", QSize(21, 18)));
	m_theme_combobox->set_name("theme_combobox");
	m_theme_combobox->set_proper_name("Theme Combobox");
	m_theme_combobox->set_font_size(15);

	m_new_theme_button->set_name("new_theme_button");
	m_new_theme_button->set_proper_name("New Theme Button");

	m_customize_theme_button->set_name("customize_theme_button");
	m_customize_theme_button->set_proper_name("Customize Theme Button");

	m_delete_theme_button->set_name("delete_theme_button");
	m_delete_theme_button->set_proper_name("Delete Theme Button");

	m_theme_info_button->set_name("theme_info_button");
	m_theme_info_button->set_proper_name("Theme Info Button");
	m_theme_info_button->disable_graphic_hover_color();

	m_separator_1->setFixedSize(1, 30);

	m_separator_2->setFixedSize(1, 30);

	m_spacer_1->setFixedWidth(12);
	m_spacer_1->set_attribute_value("Default", "background_disabled", true);

	m_spacer_2->setFixedWidth(12);
	m_spacer_2->set_attribute_value("Default", "background_disabled", true);

	m_control_separator->set_name("separator");
	m_control_separator->set_proper_name("Separators");
	m_control_separator->setFixedSize(1, 30);
	m_control_separator->share_all_attributes_with(m_separator_1);
	m_control_separator->share_all_attributes_with(m_separator_2);
	m_control_separator->set_ACW_primary("border_awc", false);
	m_control_separator->set_ACW_primary("hover_background_caw", false);
	m_control_separator->set_ACW_primary("outline_caw", false);
	m_control_separator->set_ACW_primary("corner_color_caw", false);
	m_control_separator->set_ACW_primary("corner_radii_awc", false);

	setup_layout();
}

void Themes_Settings_Panel::init_attributes()
{
	set_attribute_value("Default", "background_disabled", true);
}

void Themes_Settings_Panel::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_theme_label);
	add_child_themeable_reference(m_theme_combobox);
	add_child_themeable_reference(m_new_theme_button);
	add_child_themeable_reference(m_customize_theme_button);
	add_child_themeable_reference(m_delete_theme_button);
	add_child_themeable_reference(m_theme_info_button);
	add_child_themeable_reference(m_control_separator);
}

Button* Themes_Settings_Panel::customize_theme_button() const
{
	return m_customize_theme_button;
}

Button* Themes_Settings_Panel::new_theme_button() const
{
	return m_new_theme_button;
}

Combobox* Themes_Settings_Panel::theme_combobox() const
{
	return m_theme_combobox;
}

void Themes_Settings_Panel::show_custom_theme_buttons(bool cond)
{
	if (cond)
	{
		m_customize_theme_button->show();
		m_delete_theme_button->show();
		m_separator_2->show();
		m_spacer_1->show();
		m_spacer_2->show();
	}
	else
	{
		m_customize_theme_button->hide();
		m_delete_theme_button->hide();
		m_separator_2->hide();
		m_spacer_1->hide();
		m_spacer_2->hide();
	}
}

void Themes_Settings_Panel::init_attribute_widgets()
{
	Widget::init_attribute_widgets();

	m_attribute_widgets["border_awc"]->set_primary(false);
	m_attribute_widgets["hover_background_caw"]->set_primary(false);
	m_attribute_widgets["outline_caw"]->set_primary(false);
	m_attribute_widgets["corner_color_caw"]->set_primary(false);
	m_attribute_widgets["corner_radii_awc"]->set_primary(false);
}

void Themes_Settings_Panel::setup_layout()
{
	QHBoxLayout* theme_buttons_hbox = new QHBoxLayout;

	theme_buttons_hbox->setContentsMargins(0, 5, 0, 0);
	theme_buttons_hbox->setSpacing(0);
	theme_buttons_hbox->addWidget(m_new_theme_button);
	theme_buttons_hbox->addSpacing(12);
	theme_buttons_hbox->addWidget(m_separator_1);
	theme_buttons_hbox->addSpacing(12);
	theme_buttons_hbox->addWidget(m_customize_theme_button);
	theme_buttons_hbox->addWidget(m_delete_theme_button);
	theme_buttons_hbox->addWidget(m_spacer_1);
	theme_buttons_hbox->addWidget(m_separator_2);
	theme_buttons_hbox->addWidget(m_spacer_2);
	theme_buttons_hbox->addWidget(m_theme_info_button);
	theme_buttons_hbox->addStretch();

	Vertical_Layout* main_layout = new Vertical_Layout;

	main_layout->setContentsMargins(32, 32, 0, 0);
	main_layout->addWidget(m_theme_label);
	main_layout->addWidget(m_theme_combobox);
	main_layout->addLayout(theme_buttons_hbox);
	main_layout->addStretch();

	setLayout(main_layout);
}
