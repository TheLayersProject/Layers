#include "ThemesWidget.h"

#include "Application.h"

using Layers::Button;
using Layers::ComboBox;
using Layers::Theme;
using Layers::ThemeComboBox;
using Layers::ThemesWidget;

ThemesWidget::ThemesWidget(QWidget* parent) : Widget(parent)
{
	init_attributes();

	set_icon(new Graphic(":/svgs/panel_icon.svg", QSize(20, 20)));
	set_name("themes_widget");
	set_proper_name("Themes Widget");

	m_theme_label->set_name("theme_label");
	m_theme_label->set_proper_name("\"Theme\" Label");
	m_theme_label->set_font_size(15);

	m_theme_combobox->set_icon(new Graphic(":/svgs/combobox_icon.svg", QSize(21, 18)));
	//m_theme_combobox->set_item_renaming_disabled(false);
	m_theme_combobox->set_name("theme_combobox");
	m_theme_combobox->set_proper_name("Theme Combobox");

	m_connections.append(
		connect(m_theme_combobox, SIGNAL(item_replaced(const QString&, const QString&)),
			layersApp, SLOT(rename_theme(const QString&, const QString&))
	));

	m_connections.append(
		connect(layersApp, &Application::current_theme_changed, [this] {
			handle_custom_theme_buttons_visibility();
	}));

	if (!layersApp->current_theme()->editable())
		show_custom_theme_buttons(false);

	m_new_theme_button->set_name("new_theme_button");
	m_new_theme_button->set_proper_name("New Theme Button");

	m_customize_theme_button->set_name("customize_theme_button");
	m_customize_theme_button->set_proper_name("Customize Theme Button");

	m_delete_theme_button->set_name("delete_theme_button");
	m_delete_theme_button->set_proper_name("Delete Theme Button");

	m_theme_info_button->set_name("theme_info_button");
	m_theme_info_button->set_proper_name("Theme Info Button");
	m_theme_info_button->disable_graphic_hover_color();

	m_separator_1->entangle_with(m_control_separator);
	m_separator_1->setFixedSize(1, 30);

	m_separator_2->entangle_with(m_control_separator);
	m_separator_2->setFixedSize(1, 30);

	m_spacer_1->setFixedWidth(12);

	m_spacer_2->setFixedWidth(12);

	m_control_separator->hide();
	m_control_separator->set_name("separator");
	m_control_separator->set_proper_name("Separators");
	m_control_separator->setFixedSize(1, 30);

	setup_layout();
}

ThemesWidget::~ThemesWidget()
{
	for (QMetaObject::Connection connection : m_connections)
		QObject::disconnect(connection);
}

void ThemesWidget::handle_custom_theme_buttons_visibility()
{
	if (layersApp->current_theme()->editable())
		show_custom_theme_buttons();
	else
		show_custom_theme_buttons(false);
}

void ThemesWidget::init_attributes()
{
	m_fill->set_disabled();

	m_spacer_1->fill()->set_disabled();

	m_spacer_2->fill()->set_disabled();

	//m_theme_info_button->graphic()->svg()->a_use_common_hover_color.set_value(false);
}

Button* ThemesWidget::customize_theme_button() const
{
	return m_customize_theme_button;
}

Button* ThemesWidget::new_theme_button() const
{
	return m_new_theme_button;
}

ThemeComboBox* ThemesWidget::theme_combobox() const
{
	return m_theme_combobox;
}

void ThemesWidget::show_custom_theme_buttons(bool cond)
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

void ThemesWidget::setup_layout()
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

	QVBoxLayout* main_layout = new QVBoxLayout;

	main_layout->setContentsMargins(32, 32, 0, 0);
	main_layout->addWidget(m_theme_label);
	main_layout->addWidget(m_theme_combobox);
	main_layout->addLayout(theme_buttons_hbox);
	main_layout->addStretch();

	setLayout(main_layout);

	main_layout->activate();
}
