#include "Button.h"

#include "Graphic.h"

#include <QMouseEvent>

using Layers::Graphic;
using Layers::Button;

Button::Button(Graphic* graphic, const QString& text, QWidget* parent) :
	m_graphic{ graphic },
	m_text_label{ new Label(text) },
	Widget(parent)
{
	init();
	
	m_corner_radii->top_left()->set_value(7.0);
	m_corner_radii->top_right()->set_value(7.0);
	m_corner_radii->bottom_left()->set_value(7.0);
	m_corner_radii->bottom_right()->set_value(7.0);
	// TODO:
	//m_hover_fill->set_disabled(false);
}

Button::Button(Graphic* graphic, QWidget* parent) :
	m_graphic{ graphic },
	Widget(parent)
{
	init();

	m_fill->set_disabled();
}

Button::Button(const QString& text, QWidget* parent) :
	m_text_label{ new Label(text) },
	Widget(parent)
{
	init();

	m_corner_radii->top_left()->set_value(7.0);
	m_corner_radii->top_right()->set_value(7.0);
	m_corner_radii->bottom_left()->set_value(7.0);
	m_corner_radii->bottom_right()->set_value(7.0);
	// TODO:
	//m_hover_fill->set_disabled(false);
}

Button::Button(Graphic* graphic_before, Graphic* graphic_after, QWidget* parent) :
	m_graphic{ graphic_before },
	m_graphic_after{ graphic_after },
	Widget(parent)
{
	init();

	m_fill->set_disabled();
}

Button::~Button()
{
	if (m_graphic)
		m_graphic->deleteLater();

	if (m_graphic_after)
		m_graphic_after->deleteLater();

	if (m_text_label)
		m_text_label->deleteLater();
}

void Button::disable_text_hover_color(bool cond)
{
	if (m_text_label && m_use_text_hover_color)
		m_text_label->set_hovering(false);

	m_use_text_hover_color = !cond;
}

bool Button::disabled() const
{
	return m_disabled;
}

Graphic* Button::graphic() const
{
	return m_graphic;
}

void Button::set_disabled(bool cond)
{
	m_disabled = cond;

	if (m_disabled)
	{
		if (m_button_opacity->opacity() != 0.25)
			m_button_opacity->setOpacity(0.25);
	}
	else if (!m_disabled)
	{
		if (m_button_opacity->opacity() != 1.0)
			m_button_opacity->setOpacity(1.0);
	}
}

void Button::set_font_size(int size)
{
	if (m_text_label)
		m_text_label->set_font_size(size);
}

void Button::set_padding(int padding)
{
	main_layout->setContentsMargins(padding, padding, padding, padding);
}

void Button::set_padding(int left, int top, int right, int bottom)
{
	main_layout->setContentsMargins(left, top, right, bottom);
}

void Button::set_text_padding(int left, int top, int right, int bottom)
{
	if (m_text_label)
		m_text_label->set_padding(left, top, right, bottom);
}

void Button::toggle_graphics()
{
	if (m_graphic_after)
	{
		if (m_graphic->isVisible())
		{
			m_graphic->hide();
			m_graphic_after->show();
		}
		else
		{
			m_graphic->show();
			m_graphic_after->hide();
		}
	}
}

bool Button::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			if (!m_disabled)
				emit clicked();

			toggle_graphics();
		}
	}
	else if (event->type() == QEvent::Enter)
	{
		if (!m_disabled)
		{
			if (m_graphic)
				m_graphic->svg()->common_color()->set_state("Selected");

			if (m_graphic_after)
				m_graphic_after->svg()->common_color()->set_state("Selected");

			if (m_text_label && m_use_text_hover_color)
				m_text_label->set_hovering(true);
		}
	}
	else if (event->type() == QEvent::Leave)
	{
		if (!m_disabled)
		{
			if (m_graphic)
				m_graphic->svg()->common_color()->set_state("Unselected");

			if (m_graphic_after)
				m_graphic_after->svg()->common_color()->set_state("Unselected");

			if (m_text_label && m_use_text_hover_color)
				m_text_label->set_hovering(false);
		}
	}

	Widget::eventFilter(object, event);

	return false;
}

void Button::init()
{
	init_layout();
	setMinimumSize(40, 40);
	installEventFilter(this);

	m_button_opacity->setOpacity(1.0);
	setGraphicsEffect(m_button_opacity);

	if (m_graphic)
	{
		set_icon(new Graphic(*m_graphic));

		m_graphic->set_icon(new Graphic(*m_graphic));
		m_graphic->set_name("graphic");
		m_graphic->set_proper_name("Graphic");

		m_graphic->svg()->common_color()->init_variant_map({
			{ "Unselected", QColor(Qt::darkGray) },
			{ "Selected", QColor(Qt::lightGray) }
			});

		m_graphic->svg()->common_color()->set_state("Unselected");
	}

	if (m_graphic_after)
	{
		m_graphic_after->set_name("graphic_after");
		//m_graphic_after->set_proper_name("Graphic After");
		m_graphic_after->hide();

		m_graphic_after->svg()->common_color()->init_variant_map({
			{ "Unselected", QColor(Qt::darkGray) },
			{ "Selected", QColor(Qt::lightGray) }
			});

		m_graphic_after->svg()->common_color()->set_state("Unselected");
	}

	if (m_text_label)
	{
		m_text_label->set_name("text_label");
		m_text_label->set_proper_name("Text Label");
		m_text_label->setWordWrap(true);
	}
}

void Button::init_layout()
{
	if (m_graphic)
		main_layout->addWidget(m_graphic);

	if (m_graphic_after)
		main_layout->addWidget(m_graphic_after);

	if (m_text_label)
		main_layout->addWidget(m_text_label);

	setLayout(main_layout);
}
