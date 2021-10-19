#include "../../Layers.h"

using Layers::Button;
using Layers::CustomizeMenu;
using Layers::CustomizePanel;
using Layers::Window;

CustomizeMenu::CustomizeMenu(QWidget* parent) :
	Menu("Customize", new Graphic(":/svgs/customize_theme.svg", QSize(24, 24)), parent)
{
	Widget* ccp_widget = new Widget;
	ccp_widget->set_name("widget");
	ccp_widget->set_proper_name("Widget");

	m_control_customize_panel = new CustomizePanel(ccp_widget);

	init_child_themeable_reference_list();

	installEventFilter(this);
	setMouseTracking(true);

	set_icon(new Graphic(":/svgs/customize_theme.svg", QSize(20, 20)));
	set_name("customize_menu");
	set_proper_name("Customize Menu");

	connect(m_collapsed_button, &Button::clicked, [this] {
		if (!m_collapsed_widget->isVisible())
		{
			QPoint mapped_from_global = m_collapsed_button->mapToGlobal(QPoint(0, 0));
			QPoint move_point = QPoint(mapped_from_global.x(), mapped_from_global.y() + m_collapsed_button->height());

			m_collapsed_widget->move(move_point);
			m_collapsed_widget->show();
			m_collapsed_widget->reapply_theme();
			//m_collapsed_widget->repaint();
			m_collapsed_widget->setFocus();
		}
		else m_collapsed_widget->hide();
	});

	m_control_arrow_graphic->set_name("arrow_graphic");
	m_control_arrow_graphic->set_proper_name("Arrow Graphics");

	m_control_customize_panel->set_proper_name("Customize Panels");

	m_control_text_button->set_name("text_button");
	m_control_text_button->set_proper_name("Text Buttons");

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

	connect(m_apply_button, &Button::clicked, [this] {
		if (m_preview_window)
			m_preview_window->copy_attribute_values_to(m_current_theme);

		layersApp->reapply_theme();
		layersApp->save_theme(*m_current_theme);
		layersApp->issue_update();
	});

	m_collapsed_button->hide();
	m_collapsed_button->setFixedWidth(50);
	m_collapsed_button->disable_graphic_hover_color();
	m_collapsed_button->set_stateless_attribute_value("background_disabled", false);
	m_collapsed_button->set_stateless_attribute_value("corner_radius_tl", 5);
	m_collapsed_button->set_stateless_attribute_value("corner_radius_tr", 5);
	m_collapsed_button->set_stateless_attribute_value("corner_radius_bl", 5);
	m_collapsed_button->set_stateless_attribute_value("corner_radius_br", 5);
	m_collapsed_button->set_margin(0, 10, 0, 10);
	m_collapsed_button->set_name("collapsed_button");
	m_collapsed_button->set_proper_name("Collapsed Button");
	m_collapsed_button->set_ACW_primary("border_awc", false);
	m_collapsed_button->set_ACW_primary("outline_caw", false);
	m_collapsed_button->set_ACW_primary("corner_color_caw", false);

	m_collapsed_widget->installEventFilter(this);
	m_collapsed_widget->setWindowFlags(Qt::FramelessWindowHint);
	m_collapsed_widget->setAttribute(Qt::WA_TranslucentBackground);
	m_collapsed_widget->setMouseTracking(true);
	m_collapsed_widget->set_name("collapsed_widget");
	m_collapsed_widget->set_proper_name("Collapsed Text Buttons Dropdown Widget");
	m_collapsed_widget->set_stateless_attribute_value("corner_radius_tl", 5);
	m_collapsed_widget->set_stateless_attribute_value("corner_radius_tr", 5);
	m_collapsed_widget->set_stateless_attribute_value("corner_radius_bl", 5);
	m_collapsed_widget->set_stateless_attribute_value("corner_radius_br", 5);

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

Button* CustomizeMenu::apply_button() const
{
	return m_apply_button;
}

QList<CustomizePanel*>& CustomizeMenu::customize_panels()
{
	return m_customize_panels;
}

void CustomizeMenu::init_preview_window()
{
	m_preview_window = new Window(true);
	m_preview_window->setMinimumSize(500, 400);
	m_preview_window->setMaximumSize(800, 600);
	m_preview_window->set_functionality_disabled();
	m_preview_window->titlebar()->exit_button()->set_functionality_disabled();
	m_preview_window->customize_menu()->apply_button()->set_functionality_disabled();
	m_preview_window->settings_menu()->themes_settings_panel()->theme_combobox()->set_disabled();
	
	m_preview_window->initialize_and_acquire_panels(m_customize_panels);
	populate_panel_layout();
	open_customize_panel(m_customize_panels.last());
	set_preview_widget(m_preview_window);

	// Setup Preview Window's Customize Menu's Preview Widget
	Widget* preview_window_customize_menu_preview_widget = new Widget;
	preview_window_customize_menu_preview_widget->set_name("pw_cm_preview_widget");
	preview_window_customize_menu_preview_widget->set_proper_name("Preview Widget");

	preview_window_customize_menu_preview_widget->initialize_and_acquire_panels(m_preview_window->customize_menu()->customize_panels());
	m_preview_window->customize_menu()->populate_panel_layout();
	m_preview_window->customize_menu()->open_customize_panel(m_preview_window->customize_menu()->customize_panels().last());
	m_preview_window->customize_menu()->set_preview_widget(preview_window_customize_menu_preview_widget);
}

void CustomizeMenu::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_sidebar);
	add_child_themeable_reference(m_topbar);
	m_topbar->add_child_themeable_reference(m_apply_button);
	m_topbar->add_child_themeable_reference(m_collapsed_button);
	m_topbar->add_child_themeable_reference(m_collapsed_widget);
	m_topbar->add_child_themeable_reference(m_control_arrow_graphic);
	m_topbar->add_child_themeable_reference(m_control_text_button);
	m_sidebar->add_child_themeable_reference(m_control_customize_panel);
}

void CustomizeMenu::open_customize_panel(CustomizePanel* customize_panel)
{
	if (m_panel_stack.contains(customize_panel))
	{
		if (m_panel_stack.last() != customize_panel)
		{
			m_panel_stack.last()->hide();

			m_control_customize_panel->unshare_all_attributes_with(m_panel_stack.last());

			while (m_panel_stack.last() != customize_panel)
			{
				remove_child_themeable_reference(m_text_button_stack.last());
				m_control_text_button->unshare_all_attributes_with(m_text_button_stack.last());

				for (Button* text_button : m_topbar_text_buttons)
					if (text_button == m_text_button_stack.last())
						m_topbar_text_buttons.removeOne(text_button);

				for (Button* text_button : m_collapsed_text_buttons)
					if (text_button == m_text_button_stack.last())
						m_collapsed_text_buttons.removeOne(text_button);

				m_panel_stack.removeLast();
				m_text_button_stack.takeLast()->deleteLater();
				if (!m_arrow_graphics.isEmpty())
				{
					remove_child_themeable_reference(m_arrow_graphics.last());
					m_control_arrow_graphic->unshare_all_attributes_with(m_arrow_graphics.last());
					m_arrow_graphics.takeLast()->deleteLater();
				}
			}

			m_control_customize_panel->share_all_attributes_with(customize_panel);

			customize_panel->show();

			m_text_button_stack.last()->disable_text_hover_color();

			while (calculated_topbar_content_width() < m_topbar->width() &&
				!m_collapsed_text_buttons.isEmpty())
			{
				expand_text_buttons();
			}
		}
	}
	else
	{
		if (!m_panel_stack.isEmpty())
		{
			m_panel_stack.last()->hide();

			m_control_customize_panel->unshare_all_attributes_with(m_panel_stack.last());
		}

		// Setup Button

		Button* text_button = new Button(*customize_panel->proper_name(), true);
		text_button->disable_text_hover_color();
		text_button->set_attribute_value("background_disabled", true);
		text_button->set_font_size(14);
		text_button->set_name("text_button");
		text_button->set_padding(0, text_button->top_padding(), 0, text_button->bottom_padding());
		text_button->set_text_padding(0, 4, 0, 0);

		connect(text_button, &Button::clicked, [this, customize_panel] {
			open_customize_panel(customize_panel);
			});

		if (!m_text_button_stack.isEmpty()) m_text_button_stack.last()->disable_text_hover_color(false);

		m_text_button_stack.append(text_button);
		m_topbar_text_buttons.append(text_button);

		m_control_text_button->share_all_attributes_with(text_button);

		// Setup Arrow Graphic

		if (m_text_button_stack.count() > 1)
		{
			QGraphicsOpacityEffect* arrow_opacity = new QGraphicsOpacityEffect;
			arrow_opacity->setOpacity(0.5);

			Graphic* arrow_graphic = new Graphic(":/svgs/collapse_arrow_right.svg", QSize(8, 12));
			arrow_graphic->setGraphicsEffect(arrow_opacity);
			arrow_graphic->set_name("arrow_graphic");

			m_arrow_graphics.append(arrow_graphic);

			m_control_arrow_graphic->share_all_attributes_with(arrow_graphic);

			m_topbar_layout->insertWidget(m_topbar_layout->count() - 2, arrow_graphic);
		}

		m_topbar_layout->insertWidget(m_topbar_layout->count() - 2, text_button);

		m_control_customize_panel->share_all_attributes_with(customize_panel);

		customize_panel->show();

		m_panel_stack.append(customize_panel);

		if (m_topbar->width() < topbar_content_width(true))
			collapse_text_buttons();
	}
}

void CustomizeMenu::populate_panel_layout()
{
	for (CustomizePanel* customize_panel : m_customize_panels)
	{
		m_sidebar_layout->addWidget(customize_panel);
	}

	m_sidebar_layout->addStretch(); // Can this be added in setup_layout, and use insert to add panels?
}

Window* CustomizeMenu::preview_window() const
{
	return m_preview_window;
}

int CustomizeMenu::calculated_topbar_content_width()
{
	int calculated_topbar_content_width = 0;

	if (m_collapsed_text_buttons.count() == 1)
	{
		calculated_topbar_content_width += topbar_content_width(false);
		//calculated_topbar_content_width += m_topbar_layout->spacing();
	}
	else
	{
		calculated_topbar_content_width += topbar_content_width(true);
		calculated_topbar_content_width += m_topbar_layout->spacing() * 3;
	}

	if (!m_collapsed_text_buttons.isEmpty()) calculated_topbar_content_width += m_collapsed_text_buttons.last()->width();

	return calculated_topbar_content_width;
}

void CustomizeMenu::set_preview_widget(QWidget* widget)
{
	m_preview_layout->addWidget(widget);
}

int CustomizeMenu::topbar_content_width(bool include_collapse_button)
{
	int topbar_content_width = 0;

	topbar_content_width += m_topbar_layout->contentsMargins().left() + m_topbar_layout->contentsMargins().right();

	for (Button* text_button : m_topbar_text_buttons)
		topbar_content_width += text_button->width();

	for (Graphic* arrow_graphic : m_arrow_graphics)
		topbar_content_width += arrow_graphic->width();

	topbar_content_width += m_topbar_layout->spacing() * (m_topbar_layout->count() - 2);

	topbar_content_width += m_apply_button->width();

	if (include_collapse_button && !m_collapsed_text_buttons.isEmpty()) topbar_content_width += m_collapsed_button->width();

	return topbar_content_width;
}

bool CustomizeMenu::eventFilter(QObject* object, QEvent* event)
{
	if (object == m_collapsed_widget && event->type() == QEvent::FocusOut)
	{
		m_collapsed_widget->hide();

		//update();
	}

	else if (event->type() == QEvent::Resize)
	{
		if (height() < m_sidebar->height()) m_sidebar_scroll_area->setFixedWidth(m_sidebar->width() + 17);
		else m_sidebar_scroll_area->setFixedWidth(m_sidebar->width());

		if (m_previous_size)
		{
			if (m_previous_size->width() < size().width() &&
				m_topbar->width() > topbar_content_width(true) &&
				!m_collapsed_text_buttons.isEmpty())
			{
				expand_text_buttons();
			}
			else if (m_previous_size->width() > size().width() &&
				m_topbar->width() < topbar_content_width(true))
			{
				collapse_text_buttons();
			}

			delete m_previous_size;
		}

		m_previous_size = new QSize(size());

		//if (m_topbar->width() < topbar_content_width(true))
		//	collapse_text_buttons();
		//else if (m_topbar->width() > topbar_content_width(true) && !m_collapsed_text_buttons.isEmpty())
		//	expand_text_buttons();
	}

	if (object == this)
	{
		Widget::eventFilter(object, event);
	}

	return false;
}

void CustomizeMenu::init_attribute_widgets()
{
	Widget::init_attribute_widgets();

	m_attribute_widgets["border_awc"]->set_primary(false);
	m_attribute_widgets["hover_background_caw"]->set_primary(false);
	m_attribute_widgets["outline_caw"]->set_primary(false);
	m_attribute_widgets["corner_color_caw"]->set_primary(false);
	m_attribute_widgets["corner_radii_attribute_widget"]->set_primary(false);
}

void CustomizeMenu::adjust_collapsed_widget()
{
	QMargins margins = m_collapsed_text_buttons_layout->contentsMargins();

	int collapsed_widget_width = 0;
	int collapsed_widget_height = 45 * m_collapsed_text_buttons.count();

	for (Button* text_button : m_collapsed_text_buttons)
		if (text_button->width() > collapsed_widget_width)
			collapsed_widget_width = text_button->width();

	collapsed_widget_width += margins.left() + margins.right();

	m_collapsed_widget->setFixedSize(collapsed_widget_width, collapsed_widget_height);
}

void CustomizeMenu::collapse_text_buttons()
{
	while (topbar_content_width(true) > m_topbar->width())
	{
		if (m_topbar_text_buttons.count() > 1)
		{
			if (m_collapsed_text_buttons.isEmpty())
			{
				m_collapsed_button->show();
			}
			else
			{
				remove_child_themeable_reference(m_arrow_graphics.first());
				m_control_arrow_graphic->unshare_all_attributes_with(m_arrow_graphics.first());
				m_arrow_graphics.takeFirst()->deleteLater();
			}

			m_collapsed_text_buttons.append(m_topbar_text_buttons.takeFirst());

			m_collapsed_text_buttons_layout->addWidget(m_collapsed_text_buttons.last());

			adjust_collapsed_widget();
		}
		else if (m_topbar_text_buttons.count() == 1) break;
	}
}

void CustomizeMenu::expand_text_buttons()
{
	//int calculated_topbar_content_width = 0;

	//if (m_collapsed_text_buttons.count() == 1)
	//{
	//	calculated_topbar_content_width += topbar_content_width(false);
	//	//calculated_topbar_content_width += m_topbar_layout->spacing();
	//}
	//else
	//{
	//	calculated_topbar_content_width += topbar_content_width(true);
	//	calculated_topbar_content_width += m_topbar_layout->spacing() * 3;
	//}

	//calculated_topbar_content_width += m_collapsed_text_buttons.last()->width();

	//qDebug() << "-";
	//qDebug() << "Calculated topbar content width:" << calculated_topbar_content_width;
	//qDebug() << "Topbar width:" << m_topbar->width();
	//qDebug() << "-";

	if (calculated_topbar_content_width() < m_topbar->width())
	{
		Button* text_button = m_collapsed_text_buttons.last();

		m_topbar_text_buttons.insert(0, m_collapsed_text_buttons.takeLast());

		if (m_collapsed_text_buttons.isEmpty())
		{
			m_collapsed_button->hide();

			m_topbar_layout->insertWidget(0, text_button);
		}
		else
		{
			QGraphicsOpacityEffect* arrow_opacity = new QGraphicsOpacityEffect;
			arrow_opacity->setOpacity(0.5);

			Graphic* arrow_graphic = new Graphic(":/svgs/collapse_arrow_right.svg", QSize(8, 12));
			arrow_graphic->set_stateless_attribute_value("background_disabled", false); // TODO: TEMP, remove this
			arrow_graphic->setGraphicsEffect(arrow_opacity);
			arrow_graphic->set_name("arrow_graphic");

			m_arrow_graphics.insert(0, arrow_graphic); // Was 1! Trying 0..

			m_control_arrow_graphic->share_all_attributes_with(arrow_graphic);

			m_topbar_layout->insertWidget(1, text_button);

			m_topbar_layout->insertWidget(1, arrow_graphic);
		}

		adjust_collapsed_widget();
	}
}

void CustomizeMenu::setup_layout()
{
	// Collapsed Labels Widget

	m_collapsed_text_buttons_layout->setContentsMargins(10, 0, 10, 0);
	m_collapsed_text_buttons_layout->setSpacing(0);

	m_collapsed_widget->setLayout(m_collapsed_text_buttons_layout);

	// Topbar

	m_topbar_layout->setContentsMargins(8, 0, 8, 0);
	m_topbar_layout->setSpacing(10);
	m_topbar_layout->addWidget(m_collapsed_button);
	m_topbar_layout->addStretch();
	m_topbar_layout->addWidget(m_apply_button);

	m_topbar->setLayout(m_topbar_layout);

	// Sidebar

	m_sidebar_layout->setContentsMargins(0, 0, 0, 0);
	m_sidebar_layout->setSpacing(0);

	m_sidebar->setLayout(m_sidebar_layout);

	m_sidebar_scroll_area->set_stateless_attribute_value("background_disabled", true);
	m_sidebar_scroll_area->setWidget(m_sidebar);
	m_sidebar_scroll_area->setFixedWidth(m_sidebar->width());

	// Preview Widget and Layout

	m_preview_layout->setContentsMargins(32, 32, 32, 32);
	m_preview_layout->setSpacing(0);

	m_preview_widget->set_stateless_attribute_value("background_disabled", true);
	m_preview_widget->setLayout(m_preview_layout);

	m_preview_scroll_area->set_stateless_attribute_value("background_disabled", true);
	m_preview_scroll_area->setWidget(m_preview_widget);

	// Main Vbox

	QVBoxLayout* main_vbox = new QVBoxLayout;

	main_vbox->setContentsMargins(0, 0, 0, 0);
	main_vbox->setSpacing(0);
	main_vbox->addWidget(m_topbar);
	main_vbox->addWidget(m_preview_scroll_area);

	// Main Layout

	m_main_layout->setContentsMargins(0, 0, 0, 0);
	m_main_layout->setSpacing(0);
	m_main_layout->addWidget(m_sidebar_scroll_area);
	m_main_layout->addLayout(main_vbox);
	//m_main_layout->addStretch();

	setLayout(m_main_layout);
}
