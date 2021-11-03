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

void ComboboxItem::init_attribute_widgets()
{
	if (m_customize_panel)
	{
		AttributeWidgetContainer* border_awc = new AttributeWidgetContainer("Border", false);
		ColorAttributeWidget* background_caw = new ColorAttributeWidget("Background", m_attribute_set.attribute("background_color"), m_attribute_set.attribute("background_disabled"), true);
		ColorAttributeWidget* hover_background_caw = new ColorAttributeWidget("Hover Background", m_attribute_set.attribute("background_color_hover"), m_attribute_set.attribute("background_color_hover_disabled"), true);
		ColorAttributeWidget* outline_caw = new ColorAttributeWidget("Outline", m_attribute_set.attribute("outline_color"), m_attribute_set.attribute("outline_color_disabled"), false);
		ColorAttributeWidget* corner_color_caw = new ColorAttributeWidget("Corner Color", m_attribute_set.attribute("corner_color"), m_attribute_set.attribute("corner_color_disabled"), false);
		ColorAttributeWidget* border_caw = new ColorAttributeWidget("Color", m_attribute_set.attribute("border_color"), true);
		CornerRadiiAttributeWidget* corner_radii_attribute_widget = new CornerRadiiAttributeWidget(this, true);
		GradientAttributeWidget* border_gaw = new GradientAttributeWidget("Gradient", m_attribute_set.attribute("border_gradient_stops"), true);
		NumberAttributeWidget* border_thickness_naw = new NumberAttributeWidget("Thickness", m_attribute_set.attribute("border_thickness"), new QIntValidator(0, 30), true);
		SwitchAttributeWidget* border_color_saw = new SwitchAttributeWidget(
			"Solid", border_caw,
			"Gradient", border_gaw,
			m_attribute_set.attribute("border_gradient_disabled"), true);

		border_caw->set_centered();
		border_gaw->set_centered();

		border_thickness_naw->set_centered();
		border_thickness_naw->set_unit_label_text("px");
		border_thickness_naw->enable_silder();

		border_awc->add_attribute_widget(border_color_saw);
		border_awc->add_attribute_widget(border_thickness_naw);

		m_customize_panel->add_attribute_widget(background_caw);
		m_customize_panel->add_attribute_widget(hover_background_caw);
		m_customize_panel->add_attribute_widget(outline_caw);
		m_customize_panel->add_attribute_widget(corner_color_caw);
		m_customize_panel->add_attribute_widget(border_awc);
		m_customize_panel->add_attribute_widget(corner_radii_attribute_widget);

		// Add attribute widget references
		m_attribute_widgets["border_awc"] = border_awc;
		m_attribute_widgets["background_caw"] = background_caw;
		m_attribute_widgets["hover_background_caw"] = hover_background_caw;
		m_attribute_widgets["outline_caw"] = outline_caw;
		m_attribute_widgets["corner_color_caw"] = corner_color_caw;
		m_attribute_widgets["border_caw"] = border_caw;
		m_attribute_widgets["border_gaw"] = border_gaw;
		m_attribute_widgets["border_thickness_naw"] = border_thickness_naw;
		m_attribute_widgets["corner_radii_attribute_widget"] = corner_radii_attribute_widget;
		m_attribute_widgets["border_color_saw"] = border_color_saw;

		// TODO: Consider an implicit way to get this done
		m_customize_panel->add_child_themeable_reference(border_color_saw);
		m_customize_panel->add_child_themeable_reference(border_caw);
		m_customize_panel->add_child_themeable_reference(border_gaw);
		m_customize_panel->add_child_themeable_reference(border_thickness_naw);
	}
}

void ComboboxItem::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_item_label);
}

QString ComboboxItem::item_text()
{
	return m_item_text;
}

void ComboboxItem::issue_update()
{
	repaint();
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

bool ComboboxItem::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::Enter)
		set_attribute_value("using_background_color_hover", true);

	else if (event->type() == QEvent::Leave)
		set_attribute_value("using_background_color_hover", false);

	return false;
}
