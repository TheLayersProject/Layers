#include "MainWindowTitlebar.h"

using Layers::Button;
using Layers::Tab;
using Layers::TabBar;
using Layers::MainWindowTitlebar;

MainWindowTitlebar::MainWindowTitlebar(QWidget* parent) :
	Widget(parent)
{
	setFixedHeight(40);

	set_name("titlebar");
	set_proper_name("Titlebar");
	set_icon(new Graphic(":/svgs/titlebar_icon.svg", QSize(20, 20)));
	m_fill->set_disabled();

	m_menu_tab_bar->set_name("menu_tab_bar");
	m_menu_tab_bar->set_proper_name("Menu Tab Bar");

	m_settings_button->set_name("settings_button");
	m_settings_button->set_proper_name("Settings Button");

	m_minimize_button->set_name("minimize_button");
	m_minimize_button->set_proper_name("Minimize Button");

	m_maximize_button->set_name("maximize_button");
	m_maximize_button->set_proper_name("Maximize Button");

	m_exit_button->set_name("exit_button");
	m_exit_button->set_proper_name("Exit Button");

	setup_layout();
}

TabBar* MainWindowTitlebar::menu_tab_bar() const
{
	return m_menu_tab_bar;
}

Button* MainWindowTitlebar::settings_button() const
{
	return m_settings_button;
}

Button* MainWindowTitlebar::minimize_button() const
{
	return m_minimize_button;
}

Button* MainWindowTitlebar::maximize_button() const
{
	return m_maximize_button;
}

Button* MainWindowTitlebar::exit_button() const
{
	return m_exit_button;
}

void MainWindowTitlebar::setup_layout()
{
	// Main Layout
	main_layout->setContentsMargins(0, 0, 0, 0);
	main_layout->setSpacing(0);
	main_layout->addWidget(m_menu_tab_bar);
	main_layout->addStretch();
	main_layout->addWidget(m_settings_button);
	main_layout->addWidget(m_minimize_button);
	main_layout->addWidget(m_maximize_button);
	main_layout->addWidget(m_exit_button);

	setLayout(main_layout);
}
