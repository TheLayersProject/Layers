#include "../../../include/FillControl.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPainterPath>
#include <QVBoxLayout>

using Layers::FillControl;

FillControl::FillControl(QWidget* parent) : Widget(parent)
{
	init_attributes();
	init_child_themeable_reference_list();

	installEventFilter(this);
	setFixedSize(45, 45);
	set_name("fill_control");
	set_proper_name("Fill Control");

	m_fill_type_toggle->setFixedHeight(76);
	m_fill_type_toggle->set_name("vertical_toggle_switch");
	m_fill_type_toggle->set_proper_name("Fill Type Toggle");

	connect(m_fill_type_toggle, &ToggleSwitch::toggled_event, [this] {
			if (m_fill_type_toggle->toggled())
			{
				if (m_attribute)
					m_attribute->set_value(QVariant::fromValue(QGradientStops({ { 0.0, Qt::white },{ 1.0, Qt::black } })));

				m_gradient_label_opacity->setOpacity(1.0);
				m_gradient_control->show();

				m_color_label_opacity->setOpacity(0.25);
				m_color_control->hide();
			}
			else
			{
				if (m_attribute)
					m_attribute->set_value(QColor(Qt::white));

				m_color_label_opacity->setOpacity(1.0);
				m_color_control->show();

				m_gradient_label_opacity->setOpacity(0.25);
				m_gradient_control->hide();
			}
		});

	m_color_control->setFixedHeight(38);

	m_color_label_opacity->setOpacity(1.0);

	m_color_label->set_font_size(14);
	m_color_label->setFixedHeight(38);
	m_color_label->set_resize_disabled();
	m_color_label->a_padding_top.set_value(13);
	m_color_label->setGraphicsEffect(m_color_label_opacity);
	m_color_label->set_name("color_label");
	m_color_label->set_proper_name("Color Label");

	m_gradient_control->setFixedHeight(38);

	m_gradient_label_opacity->setOpacity(1.0);

	m_gradient_label->set_font_size(14);
	m_gradient_label->setFixedHeight(38);
	m_gradient_label->set_resize_disabled();
	m_gradient_label->a_padding_top.set_value(9);
	m_gradient_label->setGraphicsEffect(m_gradient_label_opacity);
	m_gradient_label->set_name("gradient_label");
	m_gradient_label->set_proper_name("Gradient Label");

	m_dialog->installEventFilter(this);
	m_dialog->setAttribute(Qt::WA_TranslucentBackground);
	m_dialog->setFixedSize(162, 76);
	m_dialog->setMouseTracking(true);
	m_dialog->setWindowFlags(Qt::FramelessWindowHint);
	//m_dialog->set_icon(new Graphic(":/svgs/drop_down_icon.svg", QSize(21, 18)));
	m_dialog->set_name("dialog");
	m_dialog->set_proper_name("Dialog");

	setup_layout();
}

void FillControl::init_attributes()
{
	a_border_fill.set_value(QColor("#D6D6D6"));
	a_border_thickness.set_value(2);
	a_corner_radius_tl.set_value(5);
	a_corner_radius_tr.set_value(5);
	a_corner_radius_bl.set_value(5);
	a_corner_radius_br.set_value(5);
	a_margin_left.set_value(10);
	a_margin_top.set_value(10);
	a_margin_right.set_value(10);
	a_margin_bottom.set_value(10);
	a_outline_color.set_disabled(false);

	m_color_control->a_margin_top.set_value(9);
	m_color_control->a_margin_bottom.set_value(4);

	m_gradient_control->a_margin_top.set_value(4);
	m_gradient_control->a_margin_bottom.set_value(9);

	m_fill_type_toggle->a_margin_top.set_value(12);
	m_fill_type_toggle->a_margin_bottom.set_value(12);

	m_dialog->a_corner_radius_tl.set_value(4);
	m_dialog->a_corner_radius_tr.set_value(4);
	m_dialog->a_corner_radius_bl.set_value(4);
	m_dialog->a_corner_radius_br.set_value(4);
}

void FillControl::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_dialog);

	m_dialog->add_child_themeable_reference(m_fill_type_toggle);
	m_dialog->add_child_themeable_reference(m_color_label);
	m_dialog->add_child_themeable_reference(m_gradient_label);
}

void FillControl::replace_all_attributes_with(FillControl* fill_control)
{
	Widget::replace_all_attributes_with(fill_control);

	if (m_dialog) m_dialog->replace_all_attributes_with(fill_control->m_dialog);
	if (m_fill_type_toggle) m_fill_type_toggle->replace_all_attributes_with(fill_control->m_fill_type_toggle);
	if (m_color_label) m_color_label->replace_all_attributes_with(fill_control->m_color_label);
	if (m_gradient_label) m_gradient_label->replace_all_attributes_with(fill_control->m_gradient_label);
}

void FillControl::set_attribute(Attribute* attribute)
{
	m_attribute = attribute;

	m_gradient_control->set_attribute(attribute);
	m_color_control->set_attribute(attribute);

	if (QString(m_attribute->typeName()) == QString("QList<std::pair<double,QColor>>"))
	{
		m_fill_type_toggle->toggle();
	}
	else
	{
		m_gradient_label_opacity->setOpacity(0.25);
		m_gradient_control->hide();
	}

	connect(m_attribute, &Attribute::value_changed, [this]
		{
			a_fill.copy_values_from(*m_attribute);
		});
}

bool FillControl::eventFilter(QObject* object, QEvent* event)
{
	if (object == this)
	{
		if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)
		{
			QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

			if (mouse_event->button() & Qt::LeftButton)
			{
				m_dialog->move(mapToGlobal(QPoint(0, 0)));
				m_dialog->show();
				m_dialog->setFocus();
			}
		}
	}
	else if (object == m_dialog)
	{
		if (event->type() == QEvent::FocusOut)
		{
			if (m_fill_type_toggle->underMouse())
				m_dialog->setFocus();
			else
				m_dialog->hide();

			//update();
		}
	}

	return false;
}

void FillControl::setup_layout()
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

	m_dialog->setLayout(dialog_layout);
}
