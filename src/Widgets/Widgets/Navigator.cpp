#include "Navigator.h"

#include <QResizeEvent>

using Layers::Button;
using Layers::Graphic;
using Layers::Navigator;

Navigator::Navigator(QWidget* parent)
{
	installEventFilter(this);
	init_layout();
	set_name("navigator");
	set_proper_name("Navigator");

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

	m_control_arrow_graphic->setMaximumWidth(28);
	m_control_arrow_graphic->setParent(this);
	m_control_arrow_graphic->hide();
	m_control_arrow_graphic->set_name("arrow_graphic");
	m_control_arrow_graphic->set_proper_name("Arrow Graphics");

	m_control_text_button->setParent(this);
	m_control_text_button->hide();
	m_control_text_button->set_name("text_button");
	m_control_text_button->set_proper_name("Text Buttons");
}

int Navigator::calculated_width_after_expand()
{
	int calculated_width_after_expand = 0;

	if (m_collapsed_text_buttons.count() == 1)
	{
		calculated_width_after_expand += content_width(false);
	}
	else
	{
		calculated_width_after_expand += content_width(true);
		calculated_width_after_expand += m_control_arrow_graphic->width();
	}

	if (!m_collapsed_text_buttons.isEmpty())
	{
		calculated_width_after_expand +=
			m_collapsed_text_buttons.last()->width();
	}

	return calculated_width_after_expand;
}

int Navigator::content_width(bool include_collapse_button)
{
	int hierarchy_content_width =
		m_main_layout->contentsMargins().left() +
		m_main_layout->contentsMargins().right();

	if (include_collapse_button && !m_collapsed_text_buttons.isEmpty())
		hierarchy_content_width +=
		m_collapse_menu_button->width() +
		m_main_layout->spacing();

	for (Button* text_button : m_topbar_text_buttons)
		hierarchy_content_width +=
		text_button->sizeHint().width() +
		m_main_layout->spacing();

	for (Graphic* arrow_graphic : m_arrow_graphics)
		hierarchy_content_width +=
		arrow_graphic->width() +
		m_main_layout->spacing();

	hierarchy_content_width -= m_main_layout->spacing();

	return hierarchy_content_width;
}

bool Navigator::eventFilter(QObject* object, QEvent* event)
{
	if (object == m_collapse_menu && event->type() == QEvent::FocusOut)
	{
		m_collapse_menu->hide();

		//update();
	}

	else if (object == this && event->type() == QEvent::Resize)
	{
		QResizeEvent* resize_event = static_cast<QResizeEvent*>(event);

		if (resize_event->size().width() > resize_event->oldSize().width() &&
			width() > calculated_width_after_expand() &&
			!m_collapsed_text_buttons.isEmpty())
		{
			expand_text_buttons();
		}
		else if (resize_event->size().width() < resize_event->oldSize().width() &&
			width() < content_width(true))
		{
			collapse_text_buttons();
		}
	}

	return false;
}

void Navigator::collapse_text_buttons()
{
	while (width() < content_width(true))
	{
		if (m_topbar_text_buttons.count() > 1)
		{
			if (m_collapsed_text_buttons.isEmpty())
				m_collapse_menu_button->show();
			else
				m_arrow_graphics.takeFirst()->deleteLater();

			m_collapsed_text_buttons.append(m_topbar_text_buttons.takeFirst());

			m_collapse_menu_layout->addWidget(m_collapsed_text_buttons.last());
		}
		else if (m_topbar_text_buttons.count() == 1)
			break;
	}
}

void Navigator::expand_text_buttons()
{
	while (!m_collapsed_text_buttons.isEmpty() &&
			calculated_width_after_expand() < width())
	{
		Button* text_button = m_collapsed_text_buttons.last();

		m_topbar_text_buttons.insert(0, m_collapsed_text_buttons.takeLast());

		if (m_collapsed_text_buttons.isEmpty())
		{
			m_collapse_menu_button->hide();

			m_main_layout->insertWidget(0, text_button);
		}
		else
		{
			QGraphicsOpacityEffect* arrow_opacity = new QGraphicsOpacityEffect;
			arrow_opacity->setOpacity(0.5);

			Graphic* arrow_graphic = new Graphic(":/svgs/collapse_arrow_right.svg", QSize(8, 12));
			arrow_graphic->setFixedWidth(28);
			arrow_graphic->setGraphicsEffect(arrow_opacity);
			arrow_graphic->set_name("arrow_graphic");

			m_arrow_graphics.insert(0, arrow_graphic);

			m_main_layout->insertWidget(1, text_button);
			m_main_layout->insertWidget(1, arrow_graphic);
		}
	}
}

void Navigator::init_layout()
{
	// Collapse Menu Layout
	m_collapse_menu_layout->setContentsMargins(10, 0, 10, 0);
	m_collapse_menu_layout->setSpacing(0);
	m_collapse_menu->setLayout(m_collapse_menu_layout);

	// Main Layout
	m_main_layout->addWidget(m_collapse_menu_button);
	m_main_layout->addStretch();
	m_main_layout->setContentsMargins(0, 0, 0, 0);
	m_main_layout->setSpacing(0);
	setLayout(m_main_layout);
}

Graphic* Navigator::create_arrow_graphic()
{
	QGraphicsOpacityEffect* arrow_opacity = new QGraphicsOpacityEffect;
	arrow_opacity->setOpacity(0.5);

	Graphic* arrow_graphic = new Graphic(":/svgs/collapse_arrow_right.svg", QSize(8, 12));
	arrow_graphic->setFixedWidth(28);
	arrow_graphic->entangle_with(m_control_arrow_graphic);
	arrow_graphic->set_name("arrow_graphic");
	arrow_graphic->setGraphicsEffect(arrow_opacity);

	m_arrow_graphics.append(arrow_graphic);

	return arrow_graphic;
}

Button* Navigator::create_text_button(const QString& text)
{
	Button* text_button = new Button(text);
	text_button->disable_text_hover_color();
	text_button->entangle_with(m_control_text_button);
	text_button->fill()->set_disabled();
	text_button->set_font_size(14);
	text_button->set_name("text_button");
	text_button->set_padding(0);
	text_button->set_text_padding(0, 8, 0, 0);

	if (!m_text_button_stack.isEmpty())
		m_text_button_stack.last()->disable_text_hover_color(false);

	m_text_button_stack.append(text_button);
	m_topbar_text_buttons.append(text_button);

	if (m_text_button_stack.count() > 1)
		m_main_layout->insertWidget(
			m_main_layout->count() - 1,
			create_arrow_graphic());

	m_main_layout->insertWidget(
		m_main_layout->count() - 1,
		text_button);

	connect(text_button, &Button::clicked, [this, text_button] {
		while (text_button != m_text_button_stack.last())
		{
			Button* last_button = m_text_button_stack.takeLast();

			if (m_topbar_text_buttons.contains(last_button))
				m_topbar_text_buttons.removeOne(last_button);
			else if (m_collapsed_text_buttons.contains(last_button))
				m_collapsed_text_buttons.removeOne(last_button);

			last_button->deleteLater();

			if (!m_arrow_graphics.isEmpty())
				m_arrow_graphics.takeLast()->deleteLater();

			if (width() > calculated_width_after_expand() &&
				!m_collapsed_text_buttons.isEmpty())
			{
				expand_text_buttons();
			}
		}
		});

	if (width() < content_width(true))
		collapse_text_buttons();

	return text_button;
}