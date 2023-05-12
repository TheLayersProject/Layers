#include "WidgetButton.h"

#include <QHBoxLayout>
#include <QMouseEvent>

using Layers::WidgetButton;

WidgetButton::WidgetButton(const QString& label_text, QWidget* parent) :
	m_label{ new Label(label_text) },
	Widget(parent)
{
	init();
}

WidgetButton::WidgetButton(Graphic* icon, const QString label_text, QWidget* parent) :
	m_label{ new Label(label_text) },
	Widget(parent)
{
	m_icon = icon;

	init();
}

QString WidgetButton::label_text() const
{
	return m_label->text();
}

bool WidgetButton::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			emit clicked();
		}
	}
	else if (event->type() == QEvent::Enter)
	{
		if (m_icon && m_icon->svg())
			m_icon->svg()->common_color()->set_state("Selected");
		m_label->set_hovering(true);
	}
	else if (event->type() == QEvent::Leave)
	{
		if (m_icon && m_icon->svg())
			m_icon->svg()->common_color()->set_state("Unselected");
		m_label->set_hovering(false);
	}

	Widget::eventFilter(object, event);

	return false;
}

void WidgetButton::init()
{
	init_attributes();
	init_layout();
	installEventFilter(this);

	set_name("widget_button");
	set_proper_name("Widget Button");
	setMinimumHeight(40);

	if (m_icon)
	{
		m_icon->set_name("icon");
		m_icon->setMinimumWidth(40);
	}

	m_label->setMaximumWidth(252); // TODO: Verify this width
	m_label->set_font_size(14);
	m_label->set_name("label");
	m_label->set_proper_name("Label");
	m_label->set_padding(0, 8, 0, 0);
	//m_label->setFixedHeight(40);
}

void WidgetButton::init_attributes()
{
	m_fill->set_value(QColor("#1A000000"));
	m_corner_radii->top_left()->set_value(10.0);
	m_corner_radii->top_right()->set_value(10.0);
	m_corner_radii->bottom_left()->set_value(10.0);
	m_corner_radii->bottom_right()->set_value(10.0);

	if (m_icon && m_icon->svg())
	{
		m_icon->svg()->common_color()->init_variant_map({
			{ "Unselected", QColor(Qt::darkGray) },
			{ "Selected", QColor(Qt::lightGray) }
			});

		m_icon->svg()->common_color()->set_state("Unselected");
	}
}

void WidgetButton::init_layout()
{
	QHBoxLayout* main_layout = new QHBoxLayout;

	if (m_icon)
	{
		main_layout->addWidget(m_icon);
		main_layout->setContentsMargins(0, 0, 0, 0);
	}
	else
		main_layout->setContentsMargins(40, 0, 0, 0);

	main_layout->addWidget(m_label);
	main_layout->addStretch();
	main_layout->setSpacing(0);

	setLayout(main_layout);
}
