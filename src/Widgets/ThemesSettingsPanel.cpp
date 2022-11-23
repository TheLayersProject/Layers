#include "../../include/AttributeWidgets.h"
#include "../../include/Application.h"
#include "../../include/Layouts.h"
#include "../../include/SettingsPanels.h"

using Layers::Button;
using Layers::Combobox;
using Layers::Theme;
using Layers::ThemesSettingsPanel;

ThemesSettingsPanel::ThemesSettingsPanel(QWidget* parent) : Widget(parent)
{
	init_child_themeable_reference_list();
	init_attributes();

	set_icon(new Graphic(":/svgs/panel_icon.svg", QSize(20, 20)));
	set_name("themes_settings_panel");
	set_proper_name("Themes Panel");

	m_theme_label->set_name("theme_label");
	m_theme_label->set_proper_name("\"Theme\" Label");
	m_theme_label->set_font_size(15);

	m_theme_combobox->set_icon(new Graphic(":/svgs/combobox_icon.svg", QSize(21, 18)));
	m_theme_combobox->set_item_renaming_disabled(false);
	m_theme_combobox->set_name("theme_combobox");
	m_theme_combobox->set_proper_name("Theme Combobox");
	m_theme_combobox->set_font_size(15);

	connect(m_theme_combobox, SIGNAL(item_replaced(const QString&, const QString&)),
		layersApp, SLOT(rename_theme(const QString&, const QString&)));

	connect(m_theme_combobox, &Combobox::current_item_changed, [this] {
		layersApp->apply_theme(layersApp->themes()[m_theme_combobox->current_item()]);
	});

	m_new_theme_button->set_name("new_theme_button");
	m_new_theme_button->set_proper_name("New Theme Button");

	m_customize_theme_button->set_name("customize_theme_button");
	m_customize_theme_button->set_proper_name("Customize Theme Button");

	m_delete_theme_button->set_name("delete_theme_button");
	m_delete_theme_button->set_proper_name("Delete Theme Button");

	m_theme_info_button->set_name("theme_info_button");
	m_theme_info_button->set_proper_name("Theme Info Button");
	m_theme_info_button->disable_graphic_hover_color();

	m_separator_1->replace_all_attributes_with(m_control_separator);
	m_separator_1->setFixedSize(1, 30);

	m_separator_2->replace_all_attributes_with(m_control_separator);
	m_separator_2->setFixedSize(1, 30);

	m_spacer_1->setFixedWidth(12);

	m_spacer_2->setFixedWidth(12);

	m_control_separator->set_name("separator");
	m_control_separator->set_proper_name("Separators");
	m_control_separator->setFixedSize(1, 30);
	//m_control_separator->set_ACW_primary("border_awc", false);
	//m_control_separator->set_ACW_primary("hover_background_caw", false);
	//m_control_separator->set_ACW_primary("outline_caw", false);
	//m_control_separator->set_ACW_primary("corner_color_caw", false);
	//m_control_separator->set_ACW_primary("corner_radii_awc", false);

	setup_layout();
}

void ThemesSettingsPanel::init_attributes()
{
	a_fill.set_disabled();

	m_spacer_1->a_fill.set_disabled();

	m_spacer_2->a_fill.set_disabled();

	m_theme_info_button->graphic()->svg()->a_use_common_hover_color.set_value(false);
}

void ThemesSettingsPanel::init_child_themeable_reference_list()
{
	store_child_themeable_pointer(m_theme_label);
	store_child_themeable_pointer(m_theme_combobox);
	store_child_themeable_pointer(m_new_theme_button);
	store_child_themeable_pointer(m_customize_theme_button);
	store_child_themeable_pointer(m_delete_theme_button);
	store_child_themeable_pointer(m_theme_info_button);
	store_child_themeable_pointer(m_control_separator);
}

void ThemesSettingsPanel::apply_theme(Theme& theme)
{
	if (theme.is_custom())
		show_custom_theme_buttons();
	else
		show_custom_theme_buttons(false);

	Themeable::apply_theme(theme);
}

Button* ThemesSettingsPanel::customize_theme_button() const
{
	return m_customize_theme_button;
}

Button* ThemesSettingsPanel::new_theme_button() const
{
	return m_new_theme_button;
}

Combobox* ThemesSettingsPanel::theme_combobox() const
{
	return m_theme_combobox;
}

void ThemesSettingsPanel::show_custom_theme_buttons(bool cond)
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

void ThemesSettingsPanel::setup_layout()
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

	VerticalLayout* main_layout = new VerticalLayout;

	main_layout->setContentsMargins(32, 32, 0, 0);
	main_layout->addWidget(m_theme_label);
	main_layout->addWidget(m_theme_combobox);
	main_layout->addLayout(theme_buttons_hbox);
	main_layout->addStretch();

	setLayout(main_layout);
}
