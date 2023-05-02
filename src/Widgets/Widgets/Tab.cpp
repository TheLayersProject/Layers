#include "Tab.h"

#include <QEvent>
#include <QMouseEvent>

using Layers::Button;
using Layers::Label;
using Layers::Menu;
using Layers::Tab;

Tab::Tab(QWidget* parent) :
	m_tab_icon{ new Graphic(":/svgs/mll_icon.svg", QSize(20, 6)) },
	m_text_label{ new Label("") },
	Widget(parent)
{
	set_icon(new Graphic(":/svgs/mll_icon.svg", QSize(20, 6)));
	set_name("tabs");
	set_proper_name("Tabs");

	init_attributes();

	m_exit_button->set_name("exit_button");
	m_exit_button->set_proper_name("Exit Button");

	m_tab_icon->set_name("icon");
	m_tab_icon->set_proper_name("Icon");

	m_text_label->set_name("text_label");
	m_text_label->set_proper_name("Text Label");

	setup_layout();
}

Tab::Tab(Menu* menu, QWidget* parent) :
	m_text_label{ new Label(menu->menu_name()) },
	m_menu{ menu },
	Widget(parent)
{
	m_tab_icon = new Graphic(*menu->icon());
	m_tab_icon->set_name("icon");
	m_tab_icon->setMinimumWidth(42);
	//m_tab_icon->set_padding(11, 0, 11, 0);

	init_attributes();
	installEventFilter(this);

	m_exit_button->set_name("exit_button");

	connect(m_exit_button, &Button::clicked, [this] {
		emit exit_pressed();
		});

	m_text_label->setAttribute(Qt::WA_TransparentForMouseEvents);
	m_text_label->set_name("text_label");
	m_text_label->set_font_size(16);
	m_text_label->set_padding(0, 8, 0, 0);

	setup_layout();

	m_fill->set_state("Inactive");
}

Menu* Tab::menu() const
{
	return m_menu;
}

bool Tab::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::MouseButtonPress && !m_exit_button->underMouse())
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			emit clicked();
		}
	}
	//else if (event->type() == QEvent::Enter)
	//{
	//}
	//else if (event->type() == QEvent::Leave)
	//{
	//}

	Widget::eventFilter(object, event);

	return false;
}

void Tab::init_attributes()
{
	//fill()->set_value(QColor("#e6e6e6"));

	m_fill->init_variant_map({
		{ "Inactive", QColor("#36393f") },
		{ "Active", QColor("#25272b") }
		});

	corner_radii()->top_left()->set_value(5.0);
	corner_radii()->top_right()->set_value(5.0);

	m_text_label->text_color()->set_value(QColor("#e3e3e3"));

	if (m_tab_icon->svg())
	{
		//m_tab_icon->svg()->a_use_common_color.set_value(QVariant::fromValue(true));
		m_tab_icon->svg()->common_color()->set_value(QColor("#e3e3e3"));
	}

	//m_exit_button->graphic()->svg()->a_use_common_color.set_value(QVariant::fromValue(true));
	//m_exit_button->graphic()->svg()->a_use_common_hover_color.set_value(QVariant::fromValue(true));
	m_exit_button->graphic()->svg()->common_color()->set_value(QColor("#5f5f5f"));
	//m_exit_button->graphic()->svg()->a_common_hover_color.set_value(QColor("#e95454"));
}

Button* Tab::exit_button() const
{
	return m_exit_button;
}

Label* Tab::text_label() const
{
	return m_text_label;
}

void Tab::setup_layout()
{
	main_layout->setContentsMargins(2, 0, 4, 0);
	main_layout->setSpacing(0);
	main_layout->addWidget(m_tab_icon);
	main_layout->addWidget(m_text_label);
	main_layout->addWidget(m_exit_button);

	setLayout(main_layout);
}
