#include <Layers/lfilldialog.h>

#include <QEvent>

using Layers::LFillDialog;

LFillDialog::LFillDialog(QWidget* parent) : LWidget(parent)
{
	init_attributes();

	installEventFilter(this);
	setAttribute(Qt::WA_TranslucentBackground);
	setFixedSize(165, 85);
	setMouseTracking(true);
	setWindowFlags(Qt::FramelessWindowHint);
	set_name("Dialog");

	m_color_control->set_name("Color Control");
	m_gradient_control->set_name("Gradient Control");

	m_fill_type_toggle->setFixedHeight(85);
	m_fill_type_toggle->set_name("Fill Type Toggle");

	connect(m_fill_type_toggle, &LToggleSwitch::toggled_event, [this] {
		if (m_fill_type_toggle->toggled())
		{
			m_color_control->fill()->set_value(QVariant::fromValue(QGradientStops({ { 0.0, Qt::white },{ 1.0, Qt::black } })));

			m_gradient_label_opacity->setOpacity(1.0);
			m_gradient_control->show();

			m_color_label_opacity->setOpacity(0.25);
			m_color_control->hide();
		}
		else
		{
			m_color_control->fill()->set_value(QVariant::fromValue(QColor(Qt::white)));

			m_color_label_opacity->setOpacity(1.0);
			m_color_control->show();

			m_gradient_label_opacity->setOpacity(0.25);
			m_gradient_control->hide();
		}
		});

	m_color_label_opacity->setOpacity(1.0);

	m_color_label->set_font_size(14);
	m_color_label->setFixedHeight(40);
	m_color_label->setGraphicsEffect(m_color_label_opacity);
	m_color_label->set_name("Color Label");

	m_gradient_label_opacity->setOpacity(1.0);

	m_gradient_label->set_font_size(14);
	m_gradient_label->setFixedHeight(40);
	m_gradient_label->setGraphicsEffect(m_gradient_label_opacity);
	m_gradient_label->set_name("Gradient Label");

	init_layout();
}

void LFillDialog::set_attribute(LAttribute* attribute)
{
	m_gradient_control->fill()->set_uplink_attribute(attribute);

	m_color_control->fill()->set_uplink_attribute(attribute);

	if (QString(m_color_control->fill()->typeName()) == QString("QList<std::pair<double,QColor>>"))
	{
		m_fill_type_toggle->toggle(false);

		m_gradient_label_opacity->setOpacity(1.0);
		m_gradient_control->show();

		m_color_label_opacity->setOpacity(0.25);
		m_color_control->hide();
	}
	else if (QString(m_color_control->fill()->typeName()) == QString("QColor"))
	{
		m_color_label_opacity->setOpacity(1.0);
		m_color_control->show();

		m_gradient_label_opacity->setOpacity(0.25);
		m_gradient_control->hide();
	}
}

bool LFillDialog::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::FocusOut)
	{
		if (m_fill_type_toggle->underMouse())
			setFocus();
		else
			hide();
	}

	return false;
}

void LFillDialog::init_attributes()
{
	m_corner_radii_top_left->set_value(4.0);
	m_corner_radii_top_right->set_value(4.0);
	m_corner_radii_bottom_left->set_value(4.0);
	m_corner_radii_bottom_right->set_value(4.0);

	m_color_control->margins_top()->set_value(8.0);
	m_color_control->margins_bottom()->set_value(8.0);

	m_gradient_control->margins_top()->set_value(8.0);
	m_gradient_control->margins_bottom()->set_value(8.0);
}

void LFillDialog::init_layout()
{
	QHBoxLayout* color_control_layout = new QHBoxLayout;
	color_control_layout->setContentsMargins(0, 0, 0, 0);
	color_control_layout->setSpacing(0);
	color_control_layout->addWidget(m_color_label);
	color_control_layout->addWidget(m_color_control);
	color_control_layout->addStretch();

	QHBoxLayout* gradient_control_layout = new QHBoxLayout;
	gradient_control_layout->setContentsMargins(0, 0, 0, 0);
	gradient_control_layout->setSpacing(0);
	gradient_control_layout->addWidget(m_gradient_label);
	gradient_control_layout->addWidget(m_gradient_control);
	gradient_control_layout->addStretch();

	QVBoxLayout* control_layouts = new QVBoxLayout;
	control_layouts->setContentsMargins(0, 0, 0, 0);
	control_layouts->setSpacing(0);
	control_layouts->addLayout(color_control_layout);
	control_layouts->addLayout(gradient_control_layout);

	QHBoxLayout* dialog_layout = new QHBoxLayout;
	dialog_layout->setContentsMargins(0, 0, 0, 0);
	dialog_layout->setSpacing(0);
	dialog_layout->addWidget(m_fill_type_toggle);
	dialog_layout->addLayout(control_layouts);
	//dialog_layout->addStretch();

	setLayout(dialog_layout);
}
