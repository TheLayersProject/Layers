#include "Layers.h"

using Layers::Button;
using Layers::Customize_Menu;
using Layers::Customize_Panel;
using Layers::Window;

Customize_Menu::Customize_Menu(QWidget* parent) :
	Menu("Customize", new Graphic_Widget(":/svgs/customize_theme.svg", QSize(24, 24)), parent)
{
	init_child_themeable_reference_list();

	installEventFilter(this);
	setMouseTracking(true);

	set_icon(new Graphic_Widget(":/svgs/customize_theme.svg", QSize(20, 20)));
	set_name("customize_menu");
	set_proper_name("Customize Menu");

	m_topbar->setFixedHeight(45);
	m_topbar->setMouseTracking(true);
	m_topbar->set_name("topbar");
	m_topbar->set_proper_name("Topbar");
	m_topbar->set_stateless_attribute_value("background_color", QColor(Qt::lightGray));
	m_topbar->set_stateless_attribute_value("corner_radius_tr", 10);
	m_topbar->set_stateless_attribute_value("corner_radius_br", 10);
	m_topbar->set_ACW_primary("border_awc", false);
	m_topbar->set_ACW_primary("hover_background_caw", false);
	m_topbar->set_ACW_primary("outline_caw", false);
	m_topbar->set_ACW_primary("corner_color_caw", false);

	m_apply_button->disable_text_hover_color();
	m_apply_button->set_margin(0, 7, 0, 7);
	m_apply_button->set_name("apply_button");
	m_apply_button->set_proper_name("Apply Button");
	m_apply_button->set_text_padding(3, 5, 0, 0);
	m_apply_button->set_ACW_primary("border_awc", false);
	m_apply_button->set_ACW_primary("outline_caw", false);
	m_apply_button->set_ACW_primary("corner_color_caw", false);

	m_sidebar->installEventFilter(this);
	m_sidebar->setFixedWidth(300);
	m_sidebar->setMouseTracking(true);
	m_sidebar->set_name("sidebar");
	m_sidebar->set_proper_name("Sidebar");
	m_sidebar->set_stateless_attribute_value("background_color", QColor(Qt::lightGray));
	m_sidebar->share_attribute_with_themeable(m_sidebar->attribute_set().stateless_attribute("background_color"), m_preview_widget->attribute_set().stateless_attribute("corner_color"));
	m_sidebar->set_ACW_primary("border_awc", false);
	m_sidebar->set_ACW_primary("hover_background_caw", false);
	m_sidebar->set_ACW_primary("outline_caw", false);
	m_sidebar->set_ACW_primary("corner_color_caw", false);
	m_sidebar->set_ACW_primary("corner_radii_awc", false);

	m_preview_widget->set_stateless_attribute_value("corner_radius_tl", 10);
	m_preview_widget->set_stateless_attribute_value("corner_color_disabled", false);

	setup_layout();
}

Button* Customize_Menu::apply_button() const
{
	return m_apply_button;
}

void Customize_Menu::init_preview_window()
{
	m_preview_window = new Window("", true);
	m_preview_window->setMinimumSize(500, 400);
	m_preview_window->setMaximumSize(800, 600);
	m_preview_window->titlebar()->exit_button()->set_disabled();
	m_preview_window->settings_menu()->themes_settings_panel()->theme_combobox()->set_disabled();

	m_preview_window->initialize_and_acquire_panels(m_customize_panels);

	for (Customize_Panel* customize_panel : m_customize_panels)
	{
		m_sidebar_layout->addWidget(customize_panel);
	}

	open_customize_panel(m_customize_panels.last());

	m_sidebar_layout->addStretch();

	m_preview_layout->addWidget(m_preview_window);
}

void Customize_Menu::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_sidebar);
	add_child_themeable_reference(m_topbar);
	m_topbar->add_child_themeable_reference(m_apply_button);
}

void Customize_Menu::open_customize_panel(Customize_Panel* customize_panel)
{
	if (m_panel_stack.contains(customize_panel))
	{
		if (m_panel_stack.last() != customize_panel)
		{
			m_panel_stack.last()->hide();

			m_preview_window->remove_child_themeable_reference(m_panel_stack.last());

			while (m_panel_stack.last() != customize_panel)
			{
				remove_child_themeable_reference(m_label_button_stack.last());
				remove_child_themeable_reference(m_arrow_graphic_stack.last());

				m_panel_stack.removeLast();
				m_label_button_stack.takeLast()->deleteLater();
				m_arrow_graphic_stack.takeLast()->deleteLater();
			}

			m_preview_window->add_child_themeable_reference(customize_panel);

			if (current_theme()) customize_panel->apply_theme(*current_theme());

			customize_panel->show();

			m_label_button_stack.last()->disable_text_hover_color();
		}
	}
	else
	{
		if (!m_panel_stack.isEmpty())
		{
			m_panel_stack.last()->hide();

			m_preview_window->remove_child_themeable_reference(m_panel_stack.last());
		}

		// Setup Button

		Button* label_button = new Button(*customize_panel->proper_name(), true);
		label_button->disable_text_hover_color();
		label_button->set_attribute_value("background_disabled", true);
		label_button->set_font_size(14);
		label_button->set_name("label_button");
		label_button->set_padding(0, label_button->top_padding(), 0, label_button->bottom_padding());
		label_button->set_text_padding(0, 4, 0, 0);

		connect(label_button, &Button::clicked, [this, customize_panel] {
			open_customize_panel(customize_panel);
			});

		if (!m_label_button_stack.isEmpty()) m_label_button_stack.last()->disable_text_hover_color(false);

		m_label_button_stack.append(label_button);

		add_child_themeable_reference(label_button);

		if (current_theme()) label_button->apply_theme(*current_theme());

		// Setup Arrow Graphic

		if (m_label_button_stack.count() > 1)
		{
			QGraphicsOpacityEffect* arrow_opacity = new QGraphicsOpacityEffect;
			arrow_opacity->setOpacity(0.5);

			Graphic_Widget* arrow_graphic = new Graphic_Widget(":/svgs/collapse_arrow_right.svg", QSize(8, 12));
			arrow_graphic->setGraphicsEffect(arrow_opacity);
			arrow_graphic->set_name("arrow_graphic");

			m_arrow_graphic_stack.append(arrow_graphic);

			add_child_themeable_reference(arrow_graphic);

			if (current_theme()) arrow_graphic->apply_theme(*current_theme());

			m_topbar_layout->insertWidget(m_topbar_layout->count() - 2, arrow_graphic);
		}

		m_topbar_layout->insertWidget(m_topbar_layout->count() - 2, label_button);

		m_preview_window->add_child_themeable_reference(customize_panel);

		if (current_theme()) customize_panel->apply_theme(*current_theme());

		customize_panel->show();

		m_panel_stack.append(customize_panel);
	}
}

Window* Customize_Menu::preview_window() const
{
	return m_preview_window;
}

bool Customize_Menu::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::Resize)
	{
		if (height() < m_sidebar->height()) m_sidebar_scroll_area->setFixedWidth(m_sidebar->width() + 17);
		else m_sidebar_scroll_area->setFixedWidth(m_sidebar->width());
	}

	if (object == this)
	{
		Widget::eventFilter(object, event);
	}

	return false;
}

void Customize_Menu::init_attribute_widgets()
{
	Widget::init_attribute_widgets();

	m_attribute_widgets["border_awc"]->set_primary(false);
	m_attribute_widgets["hover_background_caw"]->set_primary(false);
	m_attribute_widgets["outline_caw"]->set_primary(false);
	m_attribute_widgets["corner_color_caw"]->set_primary(false);
	m_attribute_widgets["corner_radii_awc"]->set_primary(false);
}

void Customize_Menu::setup_layout()
{
	// Topbar

	m_topbar_layout->setContentsMargins(8, 0, 8, 0);
	m_topbar_layout->setSpacing(10);
	m_topbar_layout->addStretch();
	m_topbar_layout->addWidget(m_apply_button);

	m_topbar->setLayout(m_topbar_layout);

	// Sidebar

	m_sidebar_layout->setMargin(0);
	m_sidebar_layout->setSpacing(0);

	m_sidebar->setLayout(m_sidebar_layout);

	m_sidebar_scroll_area->setWidget(m_sidebar);
	m_sidebar_scroll_area->setFixedWidth(m_sidebar->width());

	// Preview Widget and Layout

	m_preview_layout->setMargin(32);
	m_preview_layout->setSpacing(0);

	m_preview_widget->setLayout(m_preview_layout);
	m_preview_widget->set_stateless_attribute_value("background_disabled", true);

	m_preview_scroll_area->setWidget(m_preview_widget);

	// Main Vbox

	QVBoxLayout* main_vbox = new QVBoxLayout;

	main_vbox->setMargin(0);
	main_vbox->setSpacing(0);
	main_vbox->addWidget(m_topbar);
	main_vbox->addWidget(m_preview_scroll_area);

	// Main Layout

	m_main_layout->setMargin(0);
	m_main_layout->setSpacing(0);
	m_main_layout->addWidget(m_sidebar_scroll_area);
	m_main_layout->addLayout(main_vbox);
	//m_main_layout->addStretch();

	setLayout(m_main_layout);
}
