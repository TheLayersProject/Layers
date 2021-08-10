#include "Layers.h"

using Layers::Combobox_Item;

Combobox_Item::Combobox_Item(const QString& item_text, QWidget* parent) :
	m_item_label{ new Label(item_text) }, m_item_text{ item_text }, Widget(parent)
{
	init_child_themeable_reference_list();
	init_attributes();

	installEventFilter(this);

	setMouseTracking(true);
	set_name("combobox_item");

	m_item_label->setParent(this);
	m_item_label->set_name("label");
	m_item_label->set_proper_name("Item Label");
	m_item_label->set_padding(0, 7, 0, 0);
}

void Combobox_Item::init_attributes()
{
	convert_attribute_to_stateful("corner_radius_tl", {
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
		});
	convert_attribute_to_stateful("corner_radius_tr", {
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
		});
	convert_attribute_to_stateful("corner_radius_bl", {
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
		});
	convert_attribute_to_stateful("corner_radius_br", {
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
		});
}

void Combobox_Item::init_attribute_widgets()
{
	if (m_customize_panel)
	{
		Attribute_Widget_Container* border_awc = new Attribute_Widget_Container("Border", false);
		Attribute_Widget_Container* corner_radii_awc = new Attribute_Widget_Container("Corner Radii", true);
		Color_Attribute_Widget* background_caw = new Color_Attribute_Widget("Background", m_attribute_set.attribute("background_color"), m_attribute_set.attribute("background_disabled"), true);
		Color_Attribute_Widget* hover_background_caw = new Color_Attribute_Widget("Hover Background", m_attribute_set.attribute("background_color_hover"), m_attribute_set.attribute("background_color_hover_disabled"), true);
		Color_Attribute_Widget* outline_caw = new Color_Attribute_Widget("Outline", m_attribute_set.attribute("outline_color"), m_attribute_set.attribute("outline_color_disabled"), false);
		Color_Attribute_Widget* corner_color_caw = new Color_Attribute_Widget("Corner Color", m_attribute_set.attribute("corner_color"), m_attribute_set.attribute("corner_color_disabled"), false);
		Color_Attribute_Widget* border_caw = new Color_Attribute_Widget("Color", m_attribute_set.attribute("border_color"), true);
		Gradient_Attribute_Widget* border_gaw = new Gradient_Attribute_Widget("Gradient", m_attribute_set.attribute("border_gradient_stops"), true);
		Number_Attribute_Widget* border_thickness_naw = new Number_Attribute_Widget("Thickness", m_attribute_set.attribute("border_thickness"), new QIntValidator(0, 30), true);
		Number_Attribute_Widget* corner_radius_tl_naw = new Number_Attribute_Widget("Top-Left", m_attribute_set.attribute("corner_radius_tl"), new QIntValidator(0, 30), true);
		Number_Attribute_Widget* corner_radius_tr_naw = new Number_Attribute_Widget("Top-Right", m_attribute_set.attribute("corner_radius_tr"), new QIntValidator(0, 30), true);
		Number_Attribute_Widget* corner_radius_bl_naw = new Number_Attribute_Widget("Bottom-Left", m_attribute_set.attribute("corner_radius_bl"), new QIntValidator(0, 30), true);
		Number_Attribute_Widget* corner_radius_br_naw = new Number_Attribute_Widget("Bottom-Right", m_attribute_set.attribute("corner_radius_br"), new QIntValidator(0, 30), true);
		Switch_Attribute_Widget* border_color_saw = new Switch_Attribute_Widget(
			"Solid", border_caw,
			"Gradient", border_gaw,
			m_attribute_set.stateless_attribute("border_gradient_disabled"), true);

		border_caw->set_centered();
		border_gaw->set_centered();

		border_thickness_naw->set_centered();
		border_thickness_naw->set_unit_label_text("px");
		border_thickness_naw->enable_silder();

		border_awc->add_attribute_widget(border_color_saw);
		border_awc->add_attribute_widget(border_thickness_naw);

		corner_radius_tl_naw->set_centered();
		corner_radius_tl_naw->enable_silder();

		corner_radius_tr_naw->set_centered();
		corner_radius_tr_naw->enable_silder();

		corner_radius_bl_naw->set_centered();
		corner_radius_bl_naw->enable_silder();

		corner_radius_br_naw->set_centered();
		corner_radius_br_naw->enable_silder();

		corner_radii_awc->add_attribute_widget(corner_radius_tl_naw);
		corner_radii_awc->add_attribute_widget(corner_radius_tr_naw);
		corner_radii_awc->add_attribute_widget(corner_radius_bl_naw);
		corner_radii_awc->add_attribute_widget(corner_radius_br_naw);

		m_customize_panel->add_attribute_widget(background_caw);
		m_customize_panel->add_attribute_widget(hover_background_caw);
		m_customize_panel->add_attribute_widget(outline_caw);
		m_customize_panel->add_attribute_widget(corner_color_caw);
		m_customize_panel->add_attribute_widget(border_awc);
		m_customize_panel->add_attribute_widget(corner_radii_awc);

		// Add attribute widget references
		m_attribute_widgets["border_awc"] = border_awc;
		m_attribute_widgets["corner_radii_awc"] = corner_radii_awc;
		m_attribute_widgets["background_caw"] = background_caw;
		m_attribute_widgets["hover_background_caw"] = hover_background_caw;
		m_attribute_widgets["outline_caw"] = outline_caw;
		m_attribute_widgets["corner_color_caw"] = corner_color_caw;
		m_attribute_widgets["border_caw"] = border_caw;
		m_attribute_widgets["border_gaw"] = border_gaw;
		m_attribute_widgets["border_thickness_naw"] = border_thickness_naw;
		m_attribute_widgets["corner_radius_tl_naw"] = corner_radius_tl_naw;
		m_attribute_widgets["corner_radius_tr_naw"] = corner_radius_tr_naw;
		m_attribute_widgets["corner_radius_bl_naw"] = corner_radius_bl_naw;
		m_attribute_widgets["corner_radius_br_naw"] = corner_radius_br_naw;
		m_attribute_widgets["border_color_saw"] = border_color_saw;

		// TODO: Consider an implicit way to get this done
		m_customize_panel->add_child_themeable_reference(border_color_saw);
		m_customize_panel->add_child_themeable_reference(border_caw);
		m_customize_panel->add_child_themeable_reference(border_gaw);
		m_customize_panel->add_child_themeable_reference(border_thickness_naw);
		m_customize_panel->add_child_themeable_reference(corner_radius_tl_naw);
		m_customize_panel->add_child_themeable_reference(corner_radius_tr_naw);
		m_customize_panel->add_child_themeable_reference(corner_radius_bl_naw);
		m_customize_panel->add_child_themeable_reference(corner_radius_br_naw);
	}
}

void Combobox_Item::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_item_label);
}

QString Combobox_Item::item_text()
{
	return m_item_text;
}

void Combobox_Item::replace_item_text(const QString& new_item_text)
{
	m_item_text = new_item_text;

	m_item_label->setText(new_item_text);
}

void Combobox_Item::set_font_size(int size)
{
	m_item_label->set_font_size(size);

	m_item_label->move(width() * 0.09, height() / 2 - m_item_label->height() / 2);
}

void Combobox_Item::setFixedSize(const QSize& s)
{
	Widget::setFixedSize(s);

	m_item_label->move(width() * 0.09, height() / 2 - m_item_label->height() / 2);
}

void Combobox_Item::setFixedSize(int w, int h)
{
	setFixedSize(QSize(w, h));
}

bool Combobox_Item::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::Enter)
		set_stateless_attribute_value("using_background_color_hover", true, true);

	else if (event->type() == QEvent::Leave)
		set_stateless_attribute_value("using_background_color_hover", false, true);

	return false;
}
