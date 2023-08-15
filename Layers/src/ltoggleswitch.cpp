#include <Layers/ltoggleswitch.h>

#include <QHBoxLayout>
#include <QMouseEvent>

using Layers::LToggleSwitch;

LToggleSwitch::LToggleSwitch(bool vertical, QWidget* parent) :
	m_vertical{ vertical }, LWidget(parent)
{
	add_state_pool(m_toggle_states);
	init_attributes();

	installEventFilter(this);
	setFixedSize(40, 40);
	set_name("Toggle Switch");

	m_square->set_name("Square");
	m_square->setFixedSize(10, 10);

	update_spacer_size();
	m_spacer->hide();

	init_layout();

	m_toggle_states->set_state("Untoggled");
}

void LToggleSwitch::setFixedHeight(int h)
{
	LWidget::setFixedHeight(h);

	update_spacer_size();
}

void LToggleSwitch::set_toggled(bool toggled)
{
	if ((toggled && m_toggle_states->state() != "Toggled") ||
		(!toggled && m_toggle_states->state() == "Toggled"))
	{
		toggle();
	}
}

void LToggleSwitch::toggle(bool emit_toggled_event)
{
	if (m_toggle_states->state() == "Untoggled")
	{
		m_toggle_states->set_state("Toggled");
		m_spacer->show();

		if (emit_toggled_event)
			emit toggled_event(true);
	}
	else
	{
		m_toggle_states->set_state("Untoggled");
		m_spacer->hide();

		if (emit_toggled_event)
			emit toggled_event(false);
	}

	QWidget::update();
}

bool LToggleSwitch::toggled() const
{
	return (m_toggle_states->state() == "Toggled");
}

bool LToggleSwitch::eventFilter(QObject* object, QEvent* event)
{
	// TODO: See if you want to call super's eventFilter()
	if ((event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick) && object == this)
	{
		QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

		if (mouse_event->button() & Qt::LeftButton)
		{
			toggle();
		}
	}

	return false;
}

void LToggleSwitch::init_attributes()
{
	border_fill()->set_value(QColor(Qt::black));
	border_fill()->create_override("Active", QColor("#6fc65b"));
	border_thickness()->set_value(3.0);
	corner_radii_top_left()->set_value(4.0);
	corner_radii_top_right()->set_value(4.0);
	corner_radii_bottom_left()->set_value(4.0);
	corner_radii_bottom_right()->set_value(4.0);
	m_fill->set_value(QColor(Qt::white));
	m_fill->create_override("Toggled", QColor("#6fc65b"));
	if (m_vertical)
		set_margin(10.0);
	else
	{
		m_margins_top->set_value(10.0);
		m_margins_bottom->set_value(10.0);
	}

	m_square->corner_radii_top_left()->set_value(2.0);
	m_square->corner_radii_top_right()->set_value(2.0);
	m_square->corner_radii_bottom_left()->set_value(2.0);
	m_square->corner_radii_bottom_right()->set_value(2.0);
	m_square->fill()->set_value(QColor(Qt::black));
	m_square->fill()->create_override("Toggled", QColor(Qt::white));

	//m_spacer->fill()->set_disabled();
	m_spacer->fill()->set_value(QColor(Qt::blue));
}

void LToggleSwitch::init_layout()
{
	if (m_vertical)
	{
		m_layout_v = new QVBoxLayout;

		update_layout_margins();

		m_layout_v->setSpacing(0);
		m_layout_v->addWidget(m_spacer);
		m_layout_v->addWidget(m_square);
		m_layout_v->addStretch();
		m_layout_v->setAlignment(m_spacer, Qt::AlignHCenter);
		m_layout_v->setAlignment(m_square, Qt::AlignHCenter);

		setLayout(m_layout_v);
	}
	else
	{
		m_layout_h = new QHBoxLayout;

		update_layout_margins();

		m_layout_h->setSpacing(0);
		m_layout_h->addWidget(m_spacer);
		m_layout_h->addWidget(m_square);
		m_layout_h->addStretch();
		m_layout_h->setAlignment(m_spacer, Qt::AlignVCenter);
		m_layout_h->setAlignment(m_square, Qt::AlignVCenter);

		setLayout(m_layout_h);
	}
}

void LToggleSwitch::update_layout_margins()
{
	int b_thickness = border_thickness()->as<double>();

	if (m_layout_v)
		m_layout_v->setContentsMargins(
			0, m_margins_top->as<double>() + b_thickness + a_padding_top.as<double>(),
			0, a_padding_bottom.as<double>() + b_thickness + m_margins_bottom->as<double>());
	else if (m_layout_h)
		m_layout_h->setContentsMargins(
			m_margins_left->as<double>() + b_thickness + a_padding_left.as<double>(), 0,
			a_padding_right.as<double>() + b_thickness + m_margins_right->as<double>(), 0);
}

void LToggleSwitch::update_spacer_size()
{
	int b_thickness = border_thickness()->as<double>();

	if (m_vertical)
	{
		m_spacer->setFixedSize(
			0, height() - m_margins_top->as<double>() - b_thickness - a_padding_top.as<double>() - m_square->height() - a_padding_bottom.as<double>() - b_thickness - m_margins_bottom->as<double>()
		);
	}
	else
	{
		m_spacer->setFixedSize(
			width() - m_margins_left->as<double>() - b_thickness - a_padding_left.as<double>() - m_square->width() - a_padding_right.as<double>() - b_thickness - m_margins_right->as<double>(), 0
		);
	}
}
