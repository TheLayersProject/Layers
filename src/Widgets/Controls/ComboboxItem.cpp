#include "../../../include/AttributeWidgets.h"
#include "../../../include/CustomizePanel.h"
#include "../../../include/Combobox.h"

#include <QEvent>
#include <QIntValidator>

using Layers::ComboboxItem;

ComboboxItem::ComboboxItem(const QString& item_text, QWidget* parent) :
	m_item_label{ new Label(item_text) }, m_item_text{ item_text }, Widget(parent)
{
	init_attributes();
	init_layout();

	set_name("combobox_item");

	m_item_label->set_name("label");
	m_item_label->set_proper_name("Item Label");
	m_item_label->set_padding(0, 7, 0, 0);
}

QHBoxLayout* ComboboxItem::layout() const
{
	return m_layout;
}

void ComboboxItem::init_attributes()
{
	m_corner_radii->top_left()->init_variant_map({
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
		});

	m_corner_radii->top_right()->init_variant_map({
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
		});

	m_corner_radii->bottom_left()->init_variant_map({
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
		});

	m_corner_radii->bottom_right()->init_variant_map({
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
		});

	m_hover_fill->set_disabled(false);
}

QString ComboboxItem::item_text()
{
	return m_item_text;
}

void ComboboxItem::replace_item_text(const QString& new_item_text)
{
	m_item_text = new_item_text;

	m_item_label->setText(new_item_text);
}

void ComboboxItem::set_font_size(int size)
{
	m_item_label->set_font_size(size);
}

void ComboboxItem::init_layout()
{
	m_layout->setContentsMargins(20, 0, 0, 0);
	m_layout->addWidget(m_item_label);
	m_layout->addStretch();

	setLayout(m_layout);
}
