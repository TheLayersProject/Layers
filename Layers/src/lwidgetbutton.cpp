#include <Layers/lwidgetbutton.h>

#include <QHBoxLayout>
#include <QMouseEvent>

using Layers::LLabel;
using Layers::LWidgetButton;

LWidgetButton::LWidgetButton(const QString& label_text, QWidget* parent) :
	m_label{ new LLabel(label_text) },
	LWidget(parent)
{
	init();
}

LWidgetButton::LWidgetButton(const LGraphic& icon, const QString label_text, QWidget* parent) :
	m_icon_label{ new LLabel(icon) },
	m_label{ new LLabel(label_text) },
	LWidget(parent)
{
	set_icon(icon);

	init();
}

LLabel* LWidgetButton::label() const
{
	return m_label;
}

QString LWidgetButton::label_text() const
{
	return m_label->text();
}

bool LWidgetButton::eventFilter(QObject* object, QEvent* event)
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
		m_select_states->set_state("Selected");
	}
	else if (event->type() == QEvent::Leave)
	{
		m_select_states->set_state("Unselected");
	}

	LWidget::eventFilter(object, event);

	return false;
}

void LWidgetButton::init()
{
	init_attributes();
	init_layout();
	installEventFilter(this);
	add_state_pool(m_select_states);

	m_select_states->set_state("Unselected");

	set_name("Widget Button");
	setMinimumHeight(40);

	if (m_icon_label)
	{
		m_icon_label->set_name("Icon Label");
		m_icon_label->setMinimumWidth(40);
		m_icon_label->setAlignment(Qt::AlignCenter);
	}

	m_label->setWordWrap(true);
	m_label->set_font_size(14);
	m_label->set_name("Label");
}

void LWidgetButton::init_attributes()
{
	m_fill->set_value(QColor("#1A000000"));
	m_corner_radii->top_left()->set_value(10.0);
	m_corner_radii->top_right()->set_value(10.0);
	m_corner_radii->bottom_left()->set_value(10.0);
	m_corner_radii->bottom_right()->set_value(10.0);

	if (m_icon_label && m_icon_label->graphic()->svg_renderer())
	{
		m_icon_label->graphic()->svg_renderer()->common_color()->set_value(
			QColor(Qt::darkGray));
		m_icon_label->graphic()->svg_renderer()->common_color()->add_override(
			"Selected", QColor(Qt::lightGray));
	}

	m_label->text_color()->set_value(QColor(Qt::darkGray));
	m_label->text_color()->add_override("Selected", QColor(Qt::lightGray));
}

void LWidgetButton::init_layout()
{
	QHBoxLayout* main_layout = new QHBoxLayout;

	if (m_icon_label)
	{
		main_layout->addWidget(m_icon_label);
		main_layout->setContentsMargins(0, 0, 0, 0);
	}
	else
		main_layout->setContentsMargins(40, 0, 0, 0);

	main_layout->addWidget(m_label);
	main_layout->addStretch();
	main_layout->setSpacing(0);

	setLayout(main_layout);
}
