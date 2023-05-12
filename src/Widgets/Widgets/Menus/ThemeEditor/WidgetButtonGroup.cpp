#include "WidgetButtonGroup.h"

using Layers::WidgetButton;
using Layers::WidgetButtonGroup;

WidgetButtonGroup::WidgetButtonGroup(
	const QString& label_text,
	QList<WidgetButton*> widget_buttons,
	QWidget* parent
) :
	m_label{ new Label(label_text) },
	m_widget_buttons{ widget_buttons },
	Widget(parent)
{
	init_attributes();
	init_layout();

	set_name("widget_button_group");
	set_proper_name("Widget Button Group");
	setMinimumHeight(40);

	m_label->set_font_size(14);
	m_label->set_name("label");
	m_label->set_proper_name("Label");
	m_label->set_padding(0, 8, 0, 0);

	m_collapse_button->set_name("collapse_button");
	m_collapse_button->set_proper_name("Collapse Button");

	connect(m_collapse_button, &Button::clicked, [this] {
		if (m_collapsed)
			set_collapsed(false);
		else
			set_collapsed();
	});
}

void WidgetButtonGroup::set_collapsed(bool collapsed)
{
	if (collapsed)
	{
		m_widget_buttons_vbox->setContentsMargins(0, 0, 0, 0);

		for (WidgetButton* widget_button : m_widget_buttons)
			widget_button->hide();

		m_collapsed = true;
	}
	else
	{
		m_widget_buttons_vbox->setContentsMargins(10, 0, 10, 10);

		for (WidgetButton* widget_button : m_widget_buttons)
			widget_button->show();

		m_collapsed = false;
	}
}

QList<WidgetButton*>& WidgetButtonGroup::widget_buttons()
{
	return m_widget_buttons;
}

void WidgetButtonGroup::init_attributes()
{
	m_fill->set_value(QColor("#1A000000"));
	m_corner_radii->top_left()->set_value(10.0);
	m_corner_radii->top_right()->set_value(10.0);
	m_corner_radii->bottom_left()->set_value(10.0);
	m_corner_radii->bottom_right()->set_value(10.0);
}

void WidgetButtonGroup::init_layout()
{
	// Top HBox

	QHBoxLayout* top_hbox = new QHBoxLayout;

	//top_hbox->addSpacing(16);
	top_hbox->addWidget(m_label);
	top_hbox->addWidget(m_collapse_button);
	top_hbox->addStretch();
	top_hbox->setContentsMargins(13, 0, 13, 0);
	top_hbox->setSpacing(0);

	// Widget Buttons VBox

	QMap<QString, WidgetButton*> organized_widget_buttons = QMap<QString, WidgetButton*>();

	for (WidgetButton* widget_button : m_widget_buttons)
		organized_widget_buttons[widget_button->label_text()] = widget_button;

	for (WidgetButton* widget_button : organized_widget_buttons)
	{
		m_widget_buttons_vbox->addWidget(widget_button);

		widget_button->hide();
	}

	m_widget_buttons_vbox->setSpacing(3);
	m_widget_buttons_vbox->setContentsMargins(0, 0, 0, 0);

	// Main Layout

	QVBoxLayout* main_layout = new QVBoxLayout;

	main_layout->addLayout(top_hbox);
	main_layout->addLayout(m_widget_buttons_vbox);
	main_layout->setContentsMargins(0, 0, 0, 0);
	main_layout->setSpacing(0);

	setLayout(main_layout);
}
