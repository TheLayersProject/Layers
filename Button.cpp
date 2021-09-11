#include "Layers.h"

using Layers::Graphic_Widget;
using Layers::Button;

Button::Button(Graphic_Widget* graphic, const QString& text, bool auto_touch_target_compliance, QWidget* parent) :
	m_graphic{ graphic }, m_text_label{ new Label(text) },
	m_auto_touch_target_compliance{ auto_touch_target_compliance }, Widget(parent)
{
	init();
	
	set_attribute_value("corner_radius_tl", 7);
	set_attribute_value("corner_radius_tr", 7);
	set_attribute_value("corner_radius_bl", 7);
	set_attribute_value("corner_radius_br", 7);
	set_attribute_value("background_color_hover_disabled", false);
}

Button::Button(Graphic_Widget* graphic, bool auto_touch_target_compliance, QWidget* parent) :
	m_graphic{ graphic }, m_auto_touch_target_compliance{ auto_touch_target_compliance },
	Widget(parent)
{
	init();

	set_attribute_value("background_disabled", true);

	//filter_attribute("background_color");
	//filter_attribute("background_color_hover");
	//filter_attribute("border_color");
	//filter_attribute("border_gradient_stops");
	//filter_attribute("border_thickness");
	//filter_attribute("corner_radius_tl");
	//filter_attribute("corner_radius_tr");
	//filter_attribute("corner_radius_bl");
	//filter_attribute("corner_radius_br");
	//filter_attribute("text_color");
	//filter_attribute("text_color_hover");
	//filter_attribute("border_gradient_disabled");
}

Button::Button(const QString& text, bool auto_touch_target_compliance, QWidget* parent) :
	m_text_label{ new Label(text) }, m_auto_touch_target_compliance{ auto_touch_target_compliance }, Widget(parent)
{
	init();

	set_attribute_value("corner_radius_tl", 7);
	set_attribute_value("corner_radius_tr", 7);
	set_attribute_value("corner_radius_bl", 7);
	set_attribute_value("corner_radius_br", 7);
	set_attribute_value("background_color_hover_disabled", false);
}

Button::Button(Graphic_Widget* graphic_before, Graphic_Widget* graphic_after, bool auto_touch_target_compliance, QWidget* parent) :
	m_graphic{ graphic_before }, m_graphic_after{ graphic_after }, m_auto_touch_target_compliance{ auto_touch_target_compliance },
	Widget(parent)
{
	init();

	set_attribute_value("background_disabled", true);

	filter_attribute("background_color");
	filter_attribute("background_color_hover");
	filter_attribute("border_color");
	filter_attribute("border_gradient_stops");
	filter_attribute("border_thickness");
	filter_attribute("corner_radius_tl");
	filter_attribute("corner_radius_tr");
	filter_attribute("corner_radius_bl");
	filter_attribute("corner_radius_br");
	filter_attribute("text_color");
	filter_attribute("text_color_hover");
	filter_attribute("border_gradient_disabled");
}

void Button::disable_graphic_hover_color(bool cond)
{
	if (m_graphic && m_use_graphic_hover_color) m_graphic->set_hovering(false);
	if (m_graphic_after && m_use_graphic_hover_color) m_graphic_after->set_hovering(false);

	m_use_graphic_hover_color = !cond;
}

void Button::disable_text_hover_color(bool cond)
{
	if (m_text_label && m_use_text_hover_color) m_text_label->set_hovering(false);

	m_use_text_hover_color = !cond;
}

bool Button::disabled() const
{
	return m_disabled;
}

void Button::init()
{
	init_child_themeable_reference_list();

	setup_layout();

	installEventFilter(this);

	m_button_opacity->setOpacity(1.0);
	setGraphicsEffect(m_button_opacity);

	if (m_graphic)
	{
		set_icon(new Graphic_Widget(*m_graphic));

		m_graphic->set_icon(new Graphic_Widget(*m_graphic));
		m_graphic->set_name("graphic");
		m_graphic->set_proper_name("Graphic");
	}

	if (m_text_label) m_text_label->set_name("text_label");

	if (m_graphic_after)
	{
		m_graphic_after->set_name("graphic_after");
		m_graphic_after->hide();
	}

	resize();
}

void Button::init_attributes()
{
}

void Button::init_attribute_widgets()
{
	Widget::init_attribute_widgets();

	if (m_graphic && !m_text_label)
	{
		m_attribute_widgets["border_awc"]->set_primary(false);
		m_attribute_widgets["hover_background_caw"]->set_primary(false);
		m_attribute_widgets["outline_caw"]->set_primary(false);
		m_attribute_widgets["corner_color_caw"]->set_primary(false);
		m_attribute_widgets["corner_radii_attribute_widget"]->set_primary(false);
	}
}

void Button::init_child_themeable_reference_list()
{
	if (m_graphic) add_child_themeable_reference(m_graphic);
	if (m_graphic_after) add_child_themeable_reference(m_graphic_after);
	if (m_text_label) add_child_themeable_reference(m_text_label);
}

void Button::resize()
{
	int margin_left = 0;
	int margin_top = 0;
	int margin_right = 0;
	int margin_bottom = 0;
	int graphic_width = 0;
	int text_width = 0;
	int content_height = 0;
	int content_spacing = 0;
	int border_thickness = m_attribute_set.attribute_value("border_thickness")->value<int>();

	main_layout->getContentsMargins(&margin_left, &margin_top, &margin_right, &margin_bottom);

	if (m_graphic) graphic_width = m_graphic->width();

	if (m_text_label) text_width = m_text_label->width();

	if (m_graphic && m_text_label)
	{
		if (m_graphic->height() > m_text_label->height()) content_height = m_graphic->height();
		else content_height = m_text_label->height();

		content_spacing = main_layout->spacing();
	}
	else if (m_graphic) content_height = m_graphic->height();
	else if (m_text_label) content_height = m_text_label->height();

	setFixedWidth(border_thickness + margin_left + graphic_width + content_spacing + text_width + margin_right + border_thickness);
	setFixedHeight(border_thickness + margin_top + content_height + margin_bottom + border_thickness);

	if (width() < 45)
	{
		if (m_auto_touch_target_compliance) setFixedWidth(45);
		else qDebug() << "WARNING: Button has a width (" + QString::number(width()) + ") "
			"that is not in compliance with the recommended minimum touch target size of 45px.";
	}
	if (height() < 45)
	{
		if (m_auto_touch_target_compliance) setFixedHeight(45);
		else qDebug() << "WARNING: Button has a height (" + QString::number(height()) + ") "
			"that is not in compliance with the recommended minimum touch target size of 45px.";
	}
}

void Button::set_attribute_value(const QString& attribute, QVariant value)
{
	Themeable::set_stateless_attribute_value(attribute, value);

	if (attribute == "border_thickness") resize();
	if (attribute.startsWith("#") ||
		attribute == "text_color" ||
		attribute == "text_color_hover") share_attributes();
}

void Button::set_disabled(bool cond)
{
	m_disabled = cond;

	if (m_disabled)
	{
		set_attribute_value("background_color_hover_disabled", true);
		if (m_button_opacity->opacity() != 0.25) m_button_opacity->setOpacity(0.25);
	}
	else if (!m_disabled)
	{
		set_attribute_value("background_color_hover_disabled", false);
		if (m_button_opacity->opacity() != 1.0) m_button_opacity->setOpacity(1.0);
	}
}

void Button::set_font_size(int size)
{
	m_text_label->set_font_size(size);

	resize();
}

void Button::set_padding(int padding)
{
	main_layout->setContentsMargins(padding, padding, padding, padding);

	resize();
}

void Button::set_padding(int left, int top, int right, int bottom)
{
	main_layout->setContentsMargins(left, top, right, bottom);

	resize();
}

void Button::set_text_padding(int left, int top, int right, int bottom)
{
	if (m_text_label) m_text_label->set_padding(left, top, right, bottom);
}

int Button::left_padding() const
{
	int left_padding;
	int top_padding;
	int right_padding;
	int bottom_padding;

	main_layout->getContentsMargins(&left_padding, &top_padding, &right_padding, &bottom_padding);

	return left_padding;
}

int Button::top_padding() const
{
	int left_padding;
	int top_padding;
	int right_padding;
	int bottom_padding;

	main_layout->getContentsMargins(&left_padding, &top_padding, &right_padding, &bottom_padding);

	return top_padding;
}

int Button::right_padding() const
{
	int left_padding;
	int top_padding;
	int right_padding;
	int bottom_padding;

	main_layout->getContentsMargins(&left_padding, &top_padding, &right_padding, &bottom_padding);

	return right_padding;
}

int Button::bottom_padding() const
{
	int left_padding;
	int top_padding;
	int right_padding;
	int bottom_padding;

	main_layout->getContentsMargins(&left_padding, &top_padding, &right_padding, &bottom_padding);

	return bottom_padding;
}

bool Button::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			if (!m_disabled) emit clicked();

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
	}
	else if (event->type() == QEvent::Enter)
	{
		if (!m_disabled)
		{
			if (m_graphic && m_use_graphic_hover_color) m_graphic->set_hovering(true);
			if (m_graphic_after && m_use_graphic_hover_color) m_graphic_after->set_hovering(true);
			if (m_text_label && m_use_text_hover_color) m_text_label->set_hovering(true);
		}
	}
	else if (event->type() == QEvent::Leave)
	{
		if (!m_disabled)
		{
			if (m_graphic && m_use_graphic_hover_color) m_graphic->set_hovering(false);
			if (m_graphic_after && m_use_graphic_hover_color) m_graphic_after->set_hovering(false);
			if (m_text_label && m_use_text_hover_color) m_text_label->set_hovering(false);
		}
	}

	Widget::eventFilter(object, event);

	return false;
}

void Button::setup_layout()
{
	if (m_graphic) main_layout->addWidget(m_graphic);
	if (m_graphic_after) main_layout->addWidget(m_graphic_after);
	if (m_text_label) main_layout->addWidget(m_text_label);

	setLayout(main_layout);
}
