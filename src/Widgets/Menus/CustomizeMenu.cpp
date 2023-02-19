#include "../../../include/Application.h"
#include "../../../include/AttributeWidgets.h"
#include "../../../include/CustomizeMenu.h"
#include "../../../include/CustomizePanel.h"
#include "../../../include/Window.h"

using Layers::Button;
using Layers::CustomizeMenu;
using Layers::CustomizePanel;
using Layers::Widget;
using Layers::Window;

CustomizeMenu::CustomizeMenu(QWidget* parent) :
	Menu("Customize", new Graphic(":/svgs/customize_theme.svg", QSize(24, 24)), parent)
{
	m_control_customize_panel = new CustomizePanel(m_ccp_themeable, false, m_sidebar);
	m_control_customize_panel->hide();
	m_control_customize_panel->set_proper_name("Customize Panels");

	m_control_aw_group->setParent(m_control_customize_panel);
	m_control_aw_group->hide();
	m_control_aw_group->set_name("aw_group");
	m_control_aw_group->set_proper_name("Attribute Widget Group");

	m_control_color_aw->setParent(m_control_customize_panel);
	m_control_color_aw->hide();
	m_control_color_aw->set_name("color_aw");
	m_control_color_aw->set_proper_name("Color Attribute Widget");

	m_control_corner_radii_aw->setParent(m_control_customize_panel);
	m_control_corner_radii_aw->hide();
	//m_control_corner_radii_aw->set_name("corner_radii_aw");
	m_control_corner_radii_aw->set_proper_name("Corner Radii Attribute Widget");

	m_control_fill_aw->setParent(m_control_customize_panel);
	m_control_fill_aw->hide();
	m_control_fill_aw->set_name("fill_aw");
	m_control_fill_aw->set_proper_name("Fill Attribute Widget");

	m_control_number_aw->setParent(m_control_customize_panel);
	m_control_number_aw->hide();
	m_control_number_aw->set_name("number_aw");
	m_control_number_aw->set_proper_name("Number Attribute Widget");

	m_control_state_aw->setParent(m_control_customize_panel);
	m_control_state_aw->hide();
	m_control_state_aw->set_name("state_aw");
	m_control_state_aw->set_proper_name("State Attribute Widget");

	m_control_widget_button->setParent(m_control_customize_panel);
	m_control_widget_button->hide();
	m_control_widget_button->set_proper_name("Widget Button");

	m_control_widget_button_group->setParent(m_control_customize_panel);
	m_control_widget_button_group->hide();
	m_control_widget_button_group->set_proper_name("Widget ButtonGroup");

	installEventFilter(this);
	setMouseTracking(true);

	//set_icon(new Graphic(":/svgs/customize_theme.svg", QSize(20, 20)));
	set_name("customize_menu");
	set_proper_name("Customize Menu");

	connect(m_collapse_menu_button, &Button::clicked, [this] {
		if (!m_collapse_menu->isVisible())
		{
			QPoint mapped_from_global = m_collapse_menu_button->mapToGlobal(QPoint(0, 0));
			QPoint move_point = QPoint(mapped_from_global.x(), mapped_from_global.y() + m_collapse_menu_button->height());

			m_collapse_menu->move(move_point);
			m_collapse_menu->show();
			m_collapse_menu->setFocus();
		}
		else m_collapse_menu->hide();
	});

	m_control_arrow_graphic->setParent(m_topbar);
	m_control_arrow_graphic->hide();
	m_control_arrow_graphic->set_name("arrow_graphic");
	m_control_arrow_graphic->set_proper_name("Arrow Graphics");

	m_control_text_button->setParent(m_topbar);
	m_control_text_button->hide();
	m_control_text_button->set_name("text_button");
	m_control_text_button->set_proper_name("Text Buttons");

	m_topbar->setFixedHeight(45);
	m_topbar->setMouseTracking(true);
	m_topbar->set_name("topbar");
	m_topbar->set_proper_name("Topbar");
	m_topbar->fill()->set_value(QColor(Qt::lightGray));
	m_topbar->corner_radii()->top_right()->set_value(10.0);
	m_topbar->corner_radii()->bottom_right()->set_value(10.0);

	m_apply_button->disable_text_hover_color();
	m_apply_button->set_margin(0, 7, 0, 7);
	m_apply_button->set_name("apply_button");
	m_apply_button->set_proper_name("Apply Button");
	m_apply_button->set_text_padding(3, 5, 0, 0);

	connect(m_apply_button, &Button::clicked, [this] {
		// TODO:
		if (m_preview_widget && !m_functionality_disabled)
		{
			if (Themeable* preview_themeable = dynamic_cast<Themeable*>(m_preview_widget))
			{
				preview_themeable->copy_attribute_values_to(
					layersApp->current_theme());

				layersApp->reapply_theme();
				layersApp->save_theme(*layersApp->current_theme());
			}
		}
	});

	m_collapse_menu_button->hide();
	m_collapse_menu_button->setFixedWidth(50);
	m_collapse_menu_button->disable_graphic_hover_color();
	m_collapse_menu_button->fill()->set_value(false);
	m_collapse_menu_button->corner_radii()->top_left()->set_value(5.0);
	m_collapse_menu_button->corner_radii()->top_right()->set_value(5.0);
	m_collapse_menu_button->corner_radii()->bottom_left()->set_value(5.0);
	m_collapse_menu_button->corner_radii()->bottom_right()->set_value(5.0);
	m_collapse_menu_button->set_margin(0, 10, 0, 10);
	m_collapse_menu_button->set_name("collapse_menu_button");
	m_collapse_menu_button->set_proper_name("Collapse Menu Button");

	m_collapse_menu->installEventFilter(this);
	m_collapse_menu->setWindowFlags(Qt::FramelessWindowHint);
	m_collapse_menu->setAttribute(Qt::WA_TranslucentBackground);
	m_collapse_menu->setMouseTracking(true);
	m_collapse_menu->set_name("collapse_menu");
	m_collapse_menu->set_proper_name("Collapse Menu");
	m_collapse_menu->corner_radii()->top_left()->set_value(5.0);
	m_collapse_menu->corner_radii()->top_right()->set_value(5.0);
	m_collapse_menu->corner_radii()->bottom_left()->set_value(5.0);
	m_collapse_menu->corner_radii()->bottom_right()->set_value(5.0);

	m_sidebar->set_name("sidebar");
	m_sidebar->set_proper_name("Sidebar");
	//m_sidebar->fill()->set_value(QColor(Qt::lightGray));

	m_sidebar_widget->installEventFilter(this);
	m_sidebar_widget->setFixedWidth(300);
	m_sidebar_widget->setMouseTracking(true);
	m_sidebar_widget->fill()->set_disabled();

	m_preview_frame->corner_color()->entangle_with(*m_sidebar->fill());

	m_preview_frame->corner_radii()->top_left()->set_value(10.0);
	m_preview_frame->corner_color()->set_disabled(false);

	m_preview_scroll_area->set_name("preview_scroll_area");
	m_preview_scroll_area->set_proper_name("Preview Scroll Area");
	//m_preview_scroll_area->fill()->set_disabled();

	setup_layout();
}

CustomizeMenu::~CustomizeMenu()
{
	delete m_ccp_themeable;
	delete m_collapse_menu;

	m_ccp_themeable = nullptr;
	m_collapse_menu = nullptr;
}

Button* CustomizeMenu::apply_button() const
{
	return m_apply_button;
}

void CustomizeMenu::open_customize_panel(CustomizePanel* customize_panel)
{
	if (m_panel_stack.contains(customize_panel))
	{
		if (m_panel_stack.last() != customize_panel)
		{
			while (m_panel_stack.last() != customize_panel)
			{
				for (Button* text_button : m_topbar_text_buttons)
					if (text_button == m_text_button_stack.last())
						m_topbar_text_buttons.removeOne(text_button);

				for (Button* text_button : m_collapsed_text_buttons)
					if (text_button == m_text_button_stack.last())
						m_collapsed_text_buttons.removeOne(text_button);

				m_panel_stack.takeLast()->deleteLater();

				m_text_button_stack.takeLast()->deleteLater();

				if (!m_arrow_graphics.isEmpty())
					m_arrow_graphics.takeLast()->deleteLater();
			}

			if (m_panel_stack.size() == 1)
			{
				m_preview_widget->deleteLater();
				m_preview_widget = nullptr;
			}

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
			m_panel_stack.last()->hide();

		customize_panel->entangle_with(m_control_customize_panel);
		customize_panel->replace_all_aw_group_attrs_with(m_control_aw_group);
		customize_panel->replace_all_color_awidgets_attrs_with(m_control_color_aw);
		customize_panel->replace_all_corner_radii_aw_attrs_with(m_control_corner_radii_aw);
		customize_panel->replace_all_fill_awidgets_attrs_with(m_control_fill_aw);
		customize_panel->replace_all_number_awidgets_attrs_with(m_control_number_aw);
		customize_panel->replace_all_state_awidgets_attrs_with(m_control_state_aw);
		customize_panel->replace_all_widget_buttons_attrs_with(m_control_widget_button);
		customize_panel->replace_all_widget_button_groups_attrs_with(m_control_widget_button_group);

		m_sidebar_layout->addWidget(customize_panel);

		// Setup Button

		Button* text_button = new Button(*customize_panel->proper_name(), true);
		text_button->disable_text_hover_color();
		text_button->fill()->set_disabled();
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

		text_button->entangle_with(m_control_text_button);

		// Setup Arrow Graphic

		if (m_text_button_stack.count() > 1)
		{
			QGraphicsOpacityEffect* arrow_opacity = new QGraphicsOpacityEffect;
			arrow_opacity->setOpacity(0.5);

			Graphic* arrow_graphic = new Graphic(":/svgs/collapse_arrow_right.svg", QSize(8, 12));
			arrow_graphic->setGraphicsEffect(arrow_opacity);
			arrow_graphic->set_name("arrow_graphic");

			m_arrow_graphics.append(arrow_graphic);

			arrow_graphic->entangle_with(m_control_arrow_graphic);

			m_topbar_layout->insertWidget(m_topbar_layout->count() - 2, arrow_graphic);
		}

		m_topbar_layout->insertWidget(m_topbar_layout->count() - 2, text_button);

		customize_panel->show();

		m_panel_stack.append(customize_panel);

		if (m_topbar->width() < topbar_content_width(true))
			collapse_text_buttons();
	}
}

QList<CustomizePanel*>& CustomizeMenu::panels()
{
	return m_panel_stack;
}

QWidget* CustomizeMenu::preview_widget() const
{
	return m_preview_widget;
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
	if (m_preview_widget)
		m_preview_widget->deleteLater();

	if (Themeable* preview_themeable = dynamic_cast<Themeable*>(widget))
		preview_themeable->set_functionality_disabled();

	m_preview_widget = widget;
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

	if (include_collapse_button && !m_collapsed_text_buttons.isEmpty()) topbar_content_width += m_collapse_menu_button->width();

	return topbar_content_width;
}

bool CustomizeMenu::eventFilter(QObject* object, QEvent* event)
{
	if (object == m_collapse_menu && event->type() == QEvent::FocusOut)
	{
		m_collapse_menu->hide();

		//update();
	}

	else if (event->type() == QEvent::Resize)
	{
		if (height() < m_sidebar->widget()->height()) m_sidebar->setFixedWidth(m_sidebar->widget()->width() + 45); // 45 is sidebar width
		else m_sidebar->setFixedWidth(m_sidebar->widget()->width());

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

void CustomizeMenu::adjust_collapsed_widget()
{
	QMargins margins = m_collapsed_text_buttons_layout->contentsMargins();

	int collapsed_widget_width = 0;
	int collapsed_widget_height = 45 * m_collapsed_text_buttons.count();

	for (Button* text_button : m_collapsed_text_buttons)
		if (text_button->width() > collapsed_widget_width)
			collapsed_widget_width = text_button->width();

	collapsed_widget_width += margins.left() + margins.right();

	m_collapse_menu->setFixedSize(collapsed_widget_width, collapsed_widget_height);
}

void CustomizeMenu::collapse_text_buttons()
{
	while (topbar_content_width(true) > m_topbar->width())
	{
		if (m_topbar_text_buttons.count() > 1)
		{
			if (m_collapsed_text_buttons.isEmpty())
				m_collapse_menu_button->show();
			else
				m_arrow_graphics.takeFirst()->deleteLater();

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
			m_collapse_menu_button->hide();

			m_topbar_layout->insertWidget(0, text_button);
		}
		else
		{
			QGraphicsOpacityEffect* arrow_opacity = new QGraphicsOpacityEffect;
			arrow_opacity->setOpacity(0.5);

			Graphic* arrow_graphic = new Graphic(":/svgs/collapse_arrow_right.svg", QSize(8, 12));
			//arrow_graphic->set_attribute_value("background_disabled", false); // TODO: TEMP, remove this
			arrow_graphic->setGraphicsEffect(arrow_opacity);
			arrow_graphic->set_name("arrow_graphic");

			m_arrow_graphics.insert(0, arrow_graphic); // Was 1! Trying 0..

			arrow_graphic->entangle_with(m_control_arrow_graphic);

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

	m_collapse_menu->setLayout(m_collapsed_text_buttons_layout);

	// Topbar

	m_topbar_layout->setContentsMargins(8, 0, 8, 0);
	m_topbar_layout->setSpacing(10);
	m_topbar_layout->addWidget(m_collapse_menu_button);
	m_topbar_layout->addStretch();
	m_topbar_layout->addWidget(m_apply_button);

	m_topbar->setLayout(m_topbar_layout);

	// Sidebar

	m_sidebar_layout->setContentsMargins(0, 0, 0, 0);
	m_sidebar_layout->setSpacing(0);

	m_sidebar_widget->setLayout(m_sidebar_layout);

	m_sidebar->setWidget(m_sidebar_widget);
	m_sidebar->setFixedWidth(m_sidebar->widget()->width());

	// Preview Widget and Layout

	m_preview_layout->setContentsMargins(32, 32, 32, 32);
	m_preview_layout->setSpacing(0);

	m_preview_frame->fill()->set_disabled();
	m_preview_frame->setLayout(m_preview_layout);

	m_preview_scroll_area->setWidget(m_preview_frame);

	// Main Vbox

	QVBoxLayout* main_vbox = new QVBoxLayout;

	main_vbox->setContentsMargins(0, 0, 0, 0);
	main_vbox->setSpacing(0);
	main_vbox->addWidget(m_topbar);
	main_vbox->addWidget(m_preview_scroll_area);

	// Main Layout

	m_main_layout->setContentsMargins(0, 0, 0, 0);
	m_main_layout->setSpacing(0);
	m_main_layout->addWidget(m_sidebar);
	m_main_layout->addLayout(main_vbox);
	//m_main_layout->addStretch();

	setLayout(m_main_layout);
}
