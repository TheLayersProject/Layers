#include "SettingsMenu.h"

#include "SettingsTab.h"
#include "ThemesWidget.h"

#include <QMouseEvent>

using Layers::Graphic;
using Layers::SettingsMenu;
using Layers::ThemesWidget;

SettingsMenu::SettingsMenu(QWidget* parent) :
	m_themes_widget{ new ThemesWidget },
	Widget(parent)
{
	init_layout();
	setMouseTracking(true);
	set_icon(Graphic(":/svgs/settings_animated.svg", QSize(24, 24)));
	set_name("Settings Menu");

	//m_themes_settings_panel->hide();
	m_themes_widget->setMouseTracking(true);
	
	// Add Themes Settings Tab
	add_settings_tab(Graphic(":/svgs/themes_icon.svg", QSize(25, 25)), "Themes");
	m_settings_tabs.last()->set_name("Themes Settings Tab");
	//connect(m_settings_tabs.last(), &SettingsTab::clicked, [this] { m_app_preferences_settings_panel->hide(); m_themes_settings_panel->show(); });

	m_settings_tabs.first()->set_state("Selected");

	m_sidebar->setFixedWidth(recommended_minimum_tab_width());
	m_sidebar->setMouseTracking(true);
	m_sidebar->set_icon(Graphic(":/svgs/sidebar_icon.svg", QSize(20, 20)));
	m_sidebar->set_name("Sidebar");
	m_sidebar->fill()->set_value(QColor(Qt::lightGray));
}

void SettingsMenu::add_settings_tab(const Graphic& icon, const QString& label_text)
{
	SettingsTab* settings_tab = new SettingsTab(icon, label_text);

	for (SettingsTab* st : m_settings_tabs)
	{
		connect(st, &SettingsTab::clicked, [settings_tab] {
			settings_tab->set_state("Unselected");
			settings_tab->update();
			});
		connect(settings_tab, &SettingsTab::clicked, [st] {
			st->set_state("Unselected");
			st->update();
			});
	}

	m_settings_tabs.append(settings_tab);

	int active_tab_index = m_settings_tabs.indexOf(settings_tab);

	m_sidebar_layout->insertWidget(m_sidebar_layout->count() - 1, settings_tab);
}

int SettingsMenu::largest_tab_index() const
{
	int tab_index = -1;

	for (SettingsTab* st : m_settings_tabs)
	{
		int tab_rec_min_width = st->recommended_minimum_width();
		if (tab_rec_min_width > tab_index)
		{
			tab_index = m_settings_tabs.indexOf(st);
		}
	}

	return tab_index;
}

int SettingsMenu::recommended_minimum_tab_width() const
{
	int tab_width = 0;

	for (SettingsTab* st : m_settings_tabs)
	{
		int tab_rec_min_width = st->recommended_minimum_width();
		if (tab_rec_min_width > tab_width)
		{
			tab_width = tab_rec_min_width;
		}
	}

	return tab_width;
}

ThemesWidget* SettingsMenu::themes_widget() const
{
	return m_themes_widget;
}

void SettingsMenu::init_layout()
{
	// Sidebar

	m_sidebar_layout->setContentsMargins(0, 0, 0, 0);
	m_sidebar_layout->setSpacing(0);
	m_sidebar_layout->addStretch();

	m_sidebar->setLayout(m_sidebar_layout);

	// Main Layout

	QHBoxLayout* main_layout = new QHBoxLayout;

	main_layout->setContentsMargins(0, 0, 0, 0);
	main_layout->setSpacing(0);
	main_layout->addWidget(m_sidebar);
	main_layout->addWidget(m_themes_widget);

	setLayout(main_layout);
}
