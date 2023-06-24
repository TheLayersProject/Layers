#include <Layers/lbutton.h>

#include <QMouseEvent>

#include <Layers/lgraphic.h>

using Layers::LLabel;
using Layers::LButton;

LButton::LButton(const LGraphic& graphic, const QString& text, QWidget* parent) :
	m_graphic_label{ new LLabel(graphic) },
	m_text_label{ new LLabel(text) },
	LWidget(parent)
{
	init();
	
	m_corner_radii->top_left()->set_value(7.0);
	m_corner_radii->top_right()->set_value(7.0);
	m_corner_radii->bottom_left()->set_value(7.0);
	m_corner_radii->bottom_right()->set_value(7.0);
}

LButton::LButton(const LGraphic& graphic, QWidget* parent) :
	m_graphic_label{ new LLabel(graphic) },
	LWidget(parent)
{
	init();
}

LButton::LButton(const QString& text, QWidget* parent) :
	m_text_label{ new LLabel(text) },
	LWidget(parent)
{
	init();

	m_corner_radii->top_left()->set_value(7.0);
	m_corner_radii->top_right()->set_value(7.0);
	m_corner_radii->bottom_left()->set_value(7.0);
	m_corner_radii->bottom_right()->set_value(7.0);
}

LButton::LButton(const LGraphic& graphic, const LGraphic& graphic_after, QWidget* parent) :
	m_graphic_label{ new LLabel(graphic) },
	m_graphic_after_label{ new LLabel(graphic_after) },
	LWidget(parent)
{
	init();
}

//LButton::~LButton()
//{
//	if (m_graphic)
//		delete m_graphic;
//
//	if (m_graphic_after)
//		delete m_graphic_after;
//
//	if (m_text_label)
//		m_text_label->deleteLater();
//}

void LButton::disable_text_hover_color(bool cond)
{
	if (m_text_label && m_use_text_hover_color)
		m_text_label->text_color()->set_state("Unselected");

	m_use_text_hover_color = !cond;
}

bool LButton::disabled() const
{
	return m_disabled;
}

LLabel* LButton::graphic_label() const
{
	return m_graphic_label;
}

void LButton::set_disabled(bool cond)
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

void LButton::set_font_size(int size)
{
	if (m_text_label)
		m_text_label->set_font_size(size);
}

void LButton::set_padding(int padding)
{
	main_layout->setContentsMargins(padding, padding, padding, padding);
}

void LButton::set_padding(int left, int top, int right, int bottom)
{
	main_layout->setContentsMargins(left, top, right, bottom);
}

void LButton::toggle_graphics()
{
	if (m_graphic_after_label)
	{
		if (m_graphic_label->isVisible())
		{
			m_graphic_label->hide();
			m_graphic_after_label->show();
		}
		else
		{
			m_graphic_label->show();
			m_graphic_after_label->hide();
		}
	}
}

bool LButton::eventFilter(QObject* object, QEvent* event)
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
			if (m_graphic_label)
				m_graphic_label->graphic()->svg_renderer()->common_color()->set_state("Selected");

			if (m_graphic_after_label)
				m_graphic_after_label->graphic()->svg_renderer()->common_color()->set_state("Selected");

			if (m_text_label && m_use_text_hover_color)
				m_text_label->text_color()->set_state("Selected");
		}
	}
	else if (event->type() == QEvent::Leave)
	{
		if (!m_disabled)
		{
			if (m_graphic_label)
				m_graphic_label->graphic()->svg_renderer()->common_color()->set_state("Unselected");

			if (m_graphic_after_label)
				m_graphic_after_label->graphic()->svg_renderer()->common_color()->set_state("Unselected");

			if (m_text_label && m_use_text_hover_color)
				m_text_label->text_color()->set_state("Unselected");
		}
	}

	LWidget::eventFilter(object, event);

	return false;
}

void LButton::init()
{
	init_layout();
	setMinimumSize(40, 40);
	installEventFilter(this);

	m_button_opacity->setOpacity(1.0);
	setGraphicsEffect(m_button_opacity);

	if (m_graphic_label)
	{
		set_icon(*m_graphic_label->graphic());

		m_graphic_label->setAlignment(Qt::AlignCenter);
		m_graphic_label->set_icon(*m_graphic_label->graphic());
		m_graphic_label->set_name("Graphic");

		m_graphic_label->graphic()->svg_renderer()->common_color()->init_variant_map({
			{ "Unselected", QColor(Qt::darkGray) },
			{ "Selected", QColor(Qt::lightGray) }
			});

		m_graphic_label->graphic()->svg_renderer()->common_color()->set_state("Unselected");
	}

	if (m_graphic_after_label)
	{
		m_graphic_after_label->set_name("Graphic After");
		m_graphic_after_label->hide();

		m_graphic_after_label->graphic()->svg_renderer()->common_color()->init_variant_map({
			{ "Unselected", QColor(Qt::darkGray) },
			{ "Selected", QColor(Qt::lightGray) }
			});

		m_graphic_after_label->graphic()->svg_renderer()->common_color()->set_state("Unselected");
	}

	if (m_text_label)
	{
		m_text_label->set_name("Text Label");
		m_text_label->text_color()->set_state("Unselected");
	}
}

void LButton::init_layout()
{
	if (m_graphic_label)
		main_layout->addWidget(m_graphic_label);

	if (m_graphic_after_label)
		main_layout->addWidget(m_graphic_after_label);

	if (m_text_label)
		main_layout->addWidget(m_text_label);

	setLayout(main_layout);
}
