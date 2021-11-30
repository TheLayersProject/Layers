#include "../../../include/AttributeWidgets.h"
#include "../../../include/CustomizePanel.h"
#include "../../../include/Combobox.h"

#include <QEvent>
#include <QIntValidator>

using Layers::ComboboxItem;

ComboboxItem::ComboboxItem(const QString& item_text, QWidget* parent) :
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

void ComboboxItem::init_attributes()
{
	//Attribute::replace(a_corner_radius_tl, new Attribute(a_corner_radius_tl.name(), {
	//		{ "Single", 10 },
	//		{ "Top", 10 },
	//		{ "Middle", 0 },
	//		{ "Bottom", 0 }
	//	}));

	//Attribute::replace(a_corner_radius_tr, new Attribute(a_corner_radius_tr.name(), {
	//		{ "Single", 10 },
	//		{ "Top", 10 },
	//		{ "Middle", 0 },
	//		{ "Bottom", 0 }
	//	}));

	//Attribute::replace(a_corner_radius_bl, new Attribute(a_corner_radius_bl.name(), {
	//		{ "Single", 10 },
	//		{ "Top", 0 },
	//		{ "Middle", 0 },
	//		{ "Bottom", 10 }
	//	}));

	//Attribute::replace(a_corner_radius_br, new Attribute(a_corner_radius_br.name(), {
	//		{ "Single", 10 },
	//		{ "Top", 0 },
	//		{ "Middle", 0 },
	//		{ "Bottom", 10 }
	//	}));

	a_corner_radius_tl.set_values({
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
		});

	a_corner_radius_tr.set_values({
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
		});

	a_corner_radius_bl.set_values({
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
		});

	a_corner_radius_br.set_values({
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
		});

	//convert_attribute_to_stateful("corner_radius_tl", {
	//		{ "Single", 10 },
	//		{ "Top", 10 },
	//		{ "Middle", 0 },
	//		{ "Bottom", 0 }
	//	});
	//convert_attribute_to_stateful("corner_radius_tr", {
	//		{ "Single", 10 },
	//		{ "Top", 10 },
	//		{ "Middle", 0 },
	//		{ "Bottom", 0 }
	//	});
	//convert_attribute_to_stateful("corner_radius_bl", {
	//		{ "Single", 10 },
	//		{ "Top", 0 },
	//		{ "Middle", 0 },
	//		{ "Bottom", 10 }
	//	});
	//convert_attribute_to_stateful("corner_radius_br", {
	//		{ "Single", 10 },
	//		{ "Top", 0 },
	//		{ "Middle", 0 },
	//		{ "Bottom", 10 }
	//	});
}

//void ComboboxItem::init_attribute_widgets()
//{
//	if (m_customize_panel)
//	{
//		AWGroup* border_awc = new AWGroup("Border", false);
//		ColorAW* background_caw = new ColorAW("Background", m_attribute_set.attribute("background_color"), m_attribute_set.attribute("background_disabled"), true);
//		ColorAW* hover_background_caw = new ColorAW("Hover Background", m_attribute_set.attribute("background_color_hover"), m_attribute_set.attribute("background_color_hover_disabled"), true);
//		ColorAW* outline_caw = new ColorAW("Outline", m_attribute_set.attribute("outline_color"), m_attribute_set.attribute("outline_color_disabled"), false);
//		ColorAW* corner_color_caw = new ColorAW("Corner Color", m_attribute_set.attribute("corner_color"), m_attribute_set.attribute("corner_color_disabled"), false);
//		ColorAW* border_caw = new ColorAW("Color", m_attribute_set.attribute("border_color"), true);
//		CornerRadiiAW* corner_radii_attribute_widget = new CornerRadiiAW(this);
//		GradientAW* border_gaw = new GradientAW("Gradient", m_attribute_set.attribute("border_gradient_stops"), true);
//		NumberAW* border_thickness_naw = new NumberAW("Thickness", m_attribute_set.attribute("border_thickness"), new QIntValidator(0, 30), true);
//		AWSwitcher* border_color_saw = new AWSwitcher(
//			"Solid", border_caw,
//			"Gradient", border_gaw,
//			m_attribute_set.attribute("border_gradient_disabled"), true);
//
//		border_caw->set_centered();
//		border_gaw->set_centered();
//
//		border_thickness_naw->set_centered();
//		border_thickness_naw->set_unit_label_text("px");
//		border_thickness_naw->enable_silder();
//
//		border_awc->add_attribute_widget(border_color_saw);
//		border_awc->add_attribute_widget(border_thickness_naw);
//
//		m_customize_panel->add_attribute_widget(background_caw);
//		m_customize_panel->add_attribute_widget(hover_background_caw);
//		m_customize_panel->add_attribute_widget(outline_caw);
//		m_customize_panel->add_attribute_widget(corner_color_caw);
//		m_customize_panel->add_attribute_widget(border_awc);
//		m_customize_panel->add_attribute_widget(corner_radii_attribute_widget);
//
//		// Add attribute widget references
//		m_attribute_widgets["border_awc"] = border_awc;
//		m_attribute_widgets["background_caw"] = background_caw;
//		m_attribute_widgets["hover_background_caw"] = hover_background_caw;
//		m_attribute_widgets["outline_caw"] = outline_caw;
//		m_attribute_widgets["corner_color_caw"] = corner_color_caw;
//		m_attribute_widgets["border_caw"] = border_caw;
//		m_attribute_widgets["border_gaw"] = border_gaw;
//		m_attribute_widgets["border_thickness_naw"] = border_thickness_naw;
//		m_attribute_widgets["corner_radii_attribute_widget"] = corner_radii_attribute_widget;
//		m_attribute_widgets["border_color_saw"] = border_color_saw;
//
//		// TODO: Consider an implicit way to get this done
//		m_customize_panel->add_child_themeable_reference(border_color_saw);
//		m_customize_panel->add_child_themeable_reference(border_caw);
//		m_customize_panel->add_child_themeable_reference(border_gaw);
//		m_customize_panel->add_child_themeable_reference(border_thickness_naw);
//	}
//}

void ComboboxItem::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_item_label);
}

QString ComboboxItem::item_text()
{
	return m_item_text;
}

//void ComboboxItem::issue_update()
//{
//	repaint();
//}

void ComboboxItem::replace_all_attributes_with(ComboboxItem* cb_item)
{
	Widget::replace_all_attributes_with(cb_item);

	m_item_label->replace_all_attributes_with(cb_item->m_item_label);
}

void ComboboxItem::replace_item_text(const QString& new_item_text)
{
	m_item_text = new_item_text;

	m_item_label->setText(new_item_text);
}

void ComboboxItem::set_font_size(int size)
{
	m_item_label->set_font_size(size);

	m_item_label->move(width() * 0.09, height() / 2 - m_item_label->height() / 2);
}

void ComboboxItem::setFixedSize(const QSize& s)
{
	Widget::setFixedSize(s);

	m_item_label->move(width() * 0.09, height() / 2 - m_item_label->height() / 2);
}

void ComboboxItem::setFixedSize(int w, int h)
{
	setFixedSize(QSize(w, h));
}

//bool ComboboxItem::eventFilter(QObject* object, QEvent* event)
//{
//	if (event->type() == QEvent::Enter)
//		set_attribute_value("using_background_color_hover", true);
//
//	else if (event->type() == QEvent::Leave)
//		set_attribute_value("using_background_color_hover", false);
//
//	return false;
//}
