#include "Layers.h"

using Layers::Button;
using Layers::Label;
using Layers::Menu;
using Layers::MenuLabelLayer;

MenuLabelLayer::MenuLabelLayer(Menu* menu, QWidget* parent) :
	m_icon_button{ new Button(new Graphic(*menu->icon), false) },
	m_text_label{ new Label(menu->name) },
	Widget(parent)
{
	init_attributes();
	init_child_themeable_reference_list();

	set_name("menu_label_layer");
	set_icon(new Graphic(":/svgs/mll_icon.svg", QSize(20, 6)));

	m_back_button->set_name("back_button");
	m_back_button->set_proper_name("Back Button");
	m_back_button->set_attribute_value("#arrow", QColor("#6d6d6d"));
	m_back_button->set_attribute_value("#arrow_hover", QColor("#2b2b2b"));
	m_back_button->set_padding(11, 13, 6, 14);

	m_icon_button->set_name("icon_button");
	m_icon_button->set_proper_name("Menu Icon");
	m_icon_button->set_padding(6, 11, 11, 11);
	m_icon_button->disable_graphic_hover_color();

	m_text_label->setAttribute(Qt::WA_TransparentForMouseEvents);
	m_text_label->set_name("text_label");
	m_text_label->set_proper_name("Text Label");
	m_text_label->set_font_size(16);
	m_text_label->set_padding(0, 8, 0, 0);

	m_stretch_widget->setAttribute(Qt::WA_TransparentForMouseEvents);

	setup_layout();
}

void MenuLabelLayer::init_attributes()
{
	set_stateless_attribute_value("background_color", QColor("#e6e6e6"));
	set_stateless_attribute_value("corner_radius_tl", 10);
	set_stateless_attribute_value("corner_radius_tr", 10);
	set_stateless_attribute_value("corner_radius_bl", 10);
	set_stateless_attribute_value("corner_radius_br", 10);

	m_stretch_widget->set_stateless_attribute_value("background_disabled", true);
}

void MenuLabelLayer::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_back_button);
	add_child_themeable_reference(m_icon_button);
	add_child_themeable_reference(m_text_label);
}

void MenuLabelLayer::shrink()
{
	m_back_button->hide();
	m_text_label->hide();

	m_icon_button->set_padding(21, 11, 21, 11);

	m_stretch_widget->hide();

	setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}

void MenuLabelLayer::expand()
{
	m_back_button->show();
	m_text_label->show();

	m_icon_button->set_padding(6, 11, 11, 11);

	m_stretch_widget->show();

	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

Button* MenuLabelLayer::back_button() const
{
	return m_back_button;
}

Button* MenuLabelLayer::icon_button() const
{
	return m_icon_button;
}

Label* MenuLabelLayer::text_label() const
{
	return m_text_label;
}

void MenuLabelLayer::init_attribute_widgets()
{
	Widget::init_attribute_widgets();

	m_attribute_widgets["border_awc"]->set_primary(false);
	m_attribute_widgets["hover_background_caw"]->set_primary(false);
	m_attribute_widgets["outline_caw"]->set_primary(false);
	m_attribute_widgets["corner_color_caw"]->set_primary(false);
}

void MenuLabelLayer::setup_layout()
{
	main_layout->setContentsMargins(0, 0, 0, 0);
	main_layout->setSpacing(0);
	main_layout->addWidget(m_back_button);
	main_layout->addWidget(m_icon_button);
	main_layout->addWidget(m_text_label);
	main_layout->addWidget(m_stretch_widget);

	setLayout(main_layout);
}
