#include "../../../include/Label.h"
#include "../../../include/ToggleSwitch.h"

#include <QHBoxLayout>
#include <QMouseEvent>

using Layers::ToggleSwitch;

ToggleSwitch::ToggleSwitch(bool vertical, QWidget* parent) :
	m_vertical{ vertical }, Widget(parent)
{
	init_child_themeable_reference_list();
	init_attributes();

	installEventFilter(this);
	setFixedSize(45, 45);
	set_name("toggle_switch");

	m_square->set_name("square");
	m_square->set_proper_name("Square");
	m_square->setFixedSize(11, 11);

	update_spacer_size();
	m_spacer->hide();

	setup_layout();
}

void ToggleSwitch::setFixedHeight(int h)
{
	Widget::setFixedHeight(h);

	update_spacer_size();
}

void ToggleSwitch::set_toggled(bool toggled)
{
	if ((toggled && state() != "Toggled") || (!toggled && state() == "Toggled"))
	{
		toggle();
	}
}

void ToggleSwitch::toggle(bool emit_toggled_event)
{
	if (state() == "Untoggled")
	{
		set_state("Toggled");

		m_spacer->show();
	}
	else
	{
		set_state("Untoggled");

		m_spacer->hide();
	}

	if (emit_toggled_event) emit toggled_event();

	update();
}

bool ToggleSwitch::toggled() const
{
	if (state() == "Toggled") return true;
	else return false;
}

void ToggleSwitch::update_layout_margins()
{
	int b_thickness = border.thickness.as<double>();

	if (m_layout_v)
		m_layout_v->setContentsMargins(
			0, margins.top.as<double>() + b_thickness + a_padding_top.as<double>(),
			0, a_padding_bottom.as<double>() + b_thickness + margins.bottom.as<double>());
	else if (m_layout_h)
		m_layout_h->setContentsMargins(
			margins.left.as<double>() + b_thickness + a_padding_left.as<double>(), 0,
			a_padding_right.as<double>() + b_thickness + margins.right.as<double>(), 0);
}

void ToggleSwitch::update_spacer_size()
{
	int b_thickness = border.thickness.as<double>();

	if (m_vertical)
	{
		m_spacer->setFixedSize(
			0, height() - margins.top.as<double>() - b_thickness - a_padding_top.as<double>() - m_square->height() - a_padding_bottom.as<double>() - b_thickness - margins.bottom.as<double>()
		);
	}
	else
	{
		m_spacer->setFixedSize(
			width() - margins.left.as<double>() - b_thickness - a_padding_left.as<double>() - m_square->width() - a_padding_right.as<double>() - b_thickness - margins.right.as<double>(), 0
		);
	}
}

bool ToggleSwitch::eventFilter(QObject* object, QEvent* event)
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

void ToggleSwitch::init_attributes()
{
	border.fill.init_variant_map({
		{ "Untoggled", QColor(Qt::black) },
		{ "Toggled", QColor("#6fc65b") }
		});
	border.thickness.set_value(3.0);
	corner_radii.top_left.set_value(4.0);
	corner_radii.top_right.set_value(4.0);
	corner_radii.bottom_left.set_value(4.0);
	corner_radii.bottom_right.set_value(4.0);
	a_fill.init_variant_map({
		{ "Untoggled", QColor(Qt::white) },
		{ "Toggled", QColor("#6fc65b") }
		});
	if (m_vertical)
	{
		margins.top.set_value(12.0);
		margins.left.set_value(12.0);
		margins.right.set_value(12.0);
	}
	else
	{
		margins.top.set_value(12.0);
		margins.bottom.set_value(12.0);
	}

	m_square->corner_radii.top_left.set_value(2.0);
	m_square->corner_radii.top_right.set_value(2.0);
	m_square->corner_radii.bottom_left.set_value(2.0);
	m_square->corner_radii.bottom_right.set_value(2.0);
	m_square->a_fill.init_variant_map({
		{ "Untoggled", QColor(Qt::black) },
		{ "Toggled", QColor(Qt::white) }
		});

	//m_spacer->a_fill.set_disabled();
	m_spacer->a_fill.set_value(QColor(Qt::blue));

	// Set initial state
	set_state("Untoggled");;

	//connect(&a_margin_left, &Entity::value_changed, [this] {
	//	update_layout_margins(); update_spacer_size();
	//	});

	//connect(&a_margin_top, &Entity::value_changed, [this] {
	//	update_layout_margins(); update_spacer_size();
	//	});

	//connect(&a_margin_right, &Entity::value_changed, [this] {
	//	update_layout_margins(); update_spacer_size();
	//	});

	//connect(&a_margin_bottom, &Entity::value_changed, [this] {
	//	update_layout_margins(); update_spacer_size();
	//	});

	//connect(&a_padding_left, &Entity::value_changed, [this] {
	//	update_layout_margins(); update_spacer_size();
	//	});

	//connect(&a_padding_top, &Entity::value_changed, [this] {
	//	update_layout_margins(); update_spacer_size();
	//	});

	//connect(&a_padding_right, &Entity::value_changed, [this] {
	//	update_layout_margins(); update_spacer_size();
	//	});

	//connect(&a_padding_bottom, &Entity::value_changed, [this] {
	//	update_layout_margins(); update_spacer_size();
	//	});
}

void ToggleSwitch::init_child_themeable_reference_list()
{
	store_child_themeable_pointer(m_square);
}

void ToggleSwitch::setup_layout()
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