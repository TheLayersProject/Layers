#include "../../../../include/AttributeWidgets.h"
#include "../../../../include/SettingsMenu.h"

#include <QMouseEvent>

using Layers::Graphic;
using Layers::SettingsMenu;
using Layers::ThemesSettingsPanel;

SettingsMenu::SettingsMenu(QWidget* parent) :
	Menu("Settings", new Graphic(":/svgs/settings_animated.svg", QSize(24, 24)), parent)
{
	init_child_themeable_reference_list();

	setMouseTracking(true);

	installEventFilter(this);

	set_icon(new Graphic(":/svgs/settings_animated.svg", QSize(20, 20)));
	set_name("settings_menu");
	set_proper_name("Settings Menu");

	m_app_preferences_settings_panel->setMouseTracking(true);

	m_themes_settings_panel->setMouseTracking(true);
	m_themes_settings_panel->hide();

	setup_layout();

	// Add 'App Preferences' Settings Tab
	add_settings_tab(new Graphic(":/svgs/app_preferences_icon.svg", QSize(25, 25)), "App Preferences");
	m_settings_tabs.last()->set_name("app_preferences_settings_tab");
	connect(m_settings_tabs.last(), &SettingsTab::clicked, [this] { m_app_preferences_settings_panel->show(); m_themes_settings_panel->hide(); });
	
	// Add 'Themes' Settings Tab
	add_settings_tab(new Graphic(":/svgs/themes_icon.svg", QSize(25, 25)), "Themes");
	m_settings_tabs.last()->set_name("themes_settings_tab");
	connect(m_settings_tabs.last(), &SettingsTab::clicked, [this] { m_app_preferences_settings_panel->hide(); m_themes_settings_panel->show(); });

	m_settings_tabs.first()->set_state("Selected");

	m_sidebar->setFixedWidth(recommended_minimum_tab_width());
}

void SettingsMenu::add_settings_tab(Graphic* icon, const QString& label_text)
{
	SettingsTab* settings_tab = new SettingsTab(icon, label_text);

	m_sidebar->store_child_themeable_pointer(settings_tab);

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

void SettingsMenu::init_child_themeable_reference_list()
{
	store_child_themeable_pointer(m_sidebar);
	store_child_themeable_pointer(m_app_preferences_settings_panel);
	store_child_themeable_pointer(m_themes_settings_panel);
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

ThemesSettingsPanel* SettingsMenu::themes_settings_panel() const
{
	return m_themes_settings_panel;
}

bool SettingsMenu::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			if (m_hovering_over_divider)
			{
				m_dragging_sidebar = true;

				last_pos = mouse_event->globalPos();
			}
		}
	}
	else if (event->type() == QEvent::MouseButtonRelease)
	{
		m_dragging_sidebar = false;
	}
	else if (event->type() == QEvent::MouseButtonDblClick)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			QRect division_rect(m_sidebar->width() - 8, 0, 16, height());

			if (division_rect.contains(mouse_event->pos()))
			{
				int index_of_largest_tab = largest_tab_index();
				int recommended_tab_width = recommended_minimum_tab_width();

				if (m_settings_tabs.at(index_of_largest_tab)->width() == recommended_tab_width)
				{
					m_sidebar->setFixedWidth(61);
					shrink_tabs();
				}
				else
				{
					m_sidebar->setFixedWidth(recommended_tab_width);
					expand_tabs();
				}
			}
		}
	}
	else if (event->type() == QEvent::MouseMove)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		QRect division_rect(m_sidebar->width() - 8, 0, 16, height());

		if (m_dragging_sidebar)
		{
			QPoint delta = QPoint(mouse_event->globalPos() - last_pos);

			int x_change = delta.x();

			int new_width = m_sidebar->width() + x_change;

			if (new_width >= 61)
			{
				m_frozen = false;
				m_sidebar->setFixedWidth(new_width);
			}
			else if (new_width < 61) m_frozen = true;

			int largest_tab_index = -1;
			int recommended_minimum_tab_width = 0;

			for (SettingsTab* st : m_settings_tabs)
			{
				int tab_rec_min_width = st->recommended_minimum_width();
				if (tab_rec_min_width > recommended_minimum_tab_width)
				{
					largest_tab_index = m_settings_tabs.indexOf(st);
					recommended_minimum_tab_width = tab_rec_min_width;
				}
			}

			if (m_settings_tabs.at(largest_tab_index)->width() < recommended_minimum_tab_width) shrink_tabs();
			else expand_tabs();

			if (!m_frozen) last_pos = mouse_event->globalPos();
		}
		else
		{
			if (division_rect.contains(mouse_event->pos()))
			{
				m_hovering_over_divider = true;
				setCursor(Qt::SizeHorCursor);
			}
			else
			{
				m_hovering_over_divider = false;
				unsetCursor();
			}
		}
	}

	Widget::eventFilter(object, event);

	return false;
}

void SettingsMenu::shrink_tabs()
{
	if (!m_shrunk)
	{
		m_shrunk = true;

		for (SettingsTab* st : m_settings_tabs)
		{
			st->shrink();
		}
	}
}

void SettingsMenu::expand_tabs()
{
	if (m_shrunk)
	{
		m_shrunk = false;

		for (SettingsTab* st : m_settings_tabs)
		{
			st->expand();
		}
	}
}

void SettingsMenu::setup_layout()
{
	// Sidebar

	m_sidebar_layout->setContentsMargins(0, 0, 0, 0);
	m_sidebar_layout->setSpacing(0);
	m_sidebar_layout->addStretch();

	m_sidebar->setLayout(m_sidebar_layout);

	// Main Layout

	HorizontalLayout* main_layout = new HorizontalLayout;

	main_layout->setContentsMargins(0, 0, 0, 0);
	main_layout->setSpacing(0);
	main_layout->addWidget(m_sidebar);
	main_layout->addWidget(m_app_preferences_settings_panel);
	main_layout->addWidget(m_themes_settings_panel);

	setLayout(main_layout);
}
