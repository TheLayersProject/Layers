#include "Layers.h"

using Layers::Graphic_Widget;
using Layers::Settings_Menu;
using Layers::Themes_Settings_Panel;

Settings_Menu::Settings_Menu(QWidget* parent) :
	Menu("Settings", new Graphic_Widget(":/svgs/settings_animated.svg", QSize(24, 24)), parent)
{
	init_child_themeable_reference_list();

	setMouseTracking(true);

	installEventFilter(this);

	set_icon(new Graphic_Widget(":/svgs/settings_animated.svg", QSize(20, 20)));
	set_name("settings_menu");
	set_proper_name("Settings Menu");

	m_app_preferences_settings_panel->setMouseTracking(true);

	m_themes_settings_panel->setMouseTracking(true);
	m_themes_settings_panel->hide();

	setup_layout();

	add_settings_tab(new Graphic_Widget(":/svgs/app_preferences_icon.svg", QSize(25, 25)), "App Preferences");
	m_settings_tabs.last()->set_name("app_preferences_settings_tab");
	connect(m_settings_tabs.last(), &Settings_Tab::clicked, [this] { m_app_preferences_settings_panel->show(); m_themes_settings_panel->hide(); });
	add_settings_tab(new Graphic_Widget(":/svgs/themes_icon.svg", QSize(25, 25)), "Themes");
	m_settings_tabs.last()->set_name("themes_settings_tab");
	connect(m_settings_tabs.last(), &Settings_Tab::clicked, [this] { m_app_preferences_settings_panel->hide(); m_themes_settings_panel->show(); });

	m_settings_tabs.first()->set_state("Selected");

	m_sidebar->setFixedWidth(recommended_minimum_tab_width());
}

void Settings_Menu::add_settings_tab(Graphic_Widget* icon, const QString& label_text)
{
	Settings_Tab* settings_tab = new Settings_Tab(icon, label_text);

	m_sidebar->add_child_themeable_reference(settings_tab);

	for (Settings_Tab* st : m_settings_tabs)
	{
		connect(st, &Settings_Tab::clicked, [settings_tab] { settings_tab->set_state("Unselected"); });
		connect(settings_tab, &Settings_Tab::clicked, [st] { st->set_state("Unselected"); });
	}

	m_settings_tabs.append(settings_tab);

	int active_tab_index = m_settings_tabs.indexOf(settings_tab);

	m_sidebar_layout->insertWidget(m_sidebar_layout->count() - 1, settings_tab);
}

void Settings_Menu::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_sidebar);
	add_child_themeable_reference(m_app_preferences_settings_panel);
	add_child_themeable_reference(m_themes_settings_panel);
}

int Settings_Menu::largest_tab_index() const
{
	int tab_index = -1;

	for (Settings_Tab* st : m_settings_tabs)
	{
		int tab_rec_min_width = st->recommended_minimum_width();
		if (tab_rec_min_width > tab_index)
		{
			tab_index = m_settings_tabs.indexOf(st);
		}
	}

	return tab_index;
}

int Settings_Menu::recommended_minimum_tab_width() const
{
	int tab_width = 0;

	for (Settings_Tab* st : m_settings_tabs)
	{
		int tab_rec_min_width = st->recommended_minimum_width();
		if (tab_rec_min_width > tab_width)
		{
			tab_width = tab_rec_min_width;
		}
	}

	return tab_width;
}

Themes_Settings_Panel* Settings_Menu::themes_settings_panel() const
{
	return m_themes_settings_panel;
}

bool Settings_Menu::eventFilter(QObject* object, QEvent* event)
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

			for (Settings_Tab* st : m_settings_tabs)
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

void Settings_Menu::init_attribute_widgets()
{
	Widget::init_attribute_widgets();

	m_attribute_widgets["border_awc"]->set_primary(false);
	m_attribute_widgets["hover_background_caw"]->set_primary(false);
	m_attribute_widgets["outline_caw"]->set_primary(false);
	m_attribute_widgets["corner_color_caw"]->set_primary(false);
	m_attribute_widgets["corner_radii_attribute_widget"]->set_primary(false);
}

void Settings_Menu::shrink_tabs()
{
	if (!m_shrunk)
	{
		m_shrunk = true;

		for (Settings_Tab* st : m_settings_tabs)
		{
			st->shrink();
		}
	}
}

void Settings_Menu::expand_tabs()
{
	if (m_shrunk)
	{
		m_shrunk = false;

		for (Settings_Tab* st : m_settings_tabs)
		{
			st->expand();
		}
	}
}

void Settings_Menu::setup_layout()
{
	// Sidebar

	m_sidebar_layout->setMargin(0);
	m_sidebar_layout->setSpacing(0);
	m_sidebar_layout->addStretch();

	m_sidebar->setLayout(m_sidebar_layout);

	// Main Layout

	Horizontal_Layout* main_layout = new Horizontal_Layout;

	main_layout->setMargin(0);
	main_layout->setSpacing(0);
	main_layout->addWidget(m_sidebar);
	main_layout->addWidget(m_app_preferences_settings_panel);
	main_layout->addWidget(m_themes_settings_panel);

	setLayout(main_layout);
}
