#include "ColorDialog.h"

#include "Application.h"
#include "calculate.h"

#include <QRegularExpressionValidator>

using Layers::Attribute;
using Layers::ColorDialog;
using Layers::Themeable;

ColorDialog::ColorDialog(QWidget* parent) :
	Dialog("Color", parent)
{
	init_attributes();

	setFixedSize(315, 465);

	set_icon(Graphic(":/images/color_icon.png"));
	set_name("Color Dialog");

	m_apply_button->set_name("Apply Button");
	m_apply_button->disable_text_hover_color();
	connect(m_apply_button, &Button::clicked, [this] { done(QDialog::Accepted); });

	m_color_unit_label->set_name("Color Unit Label");

	m_line_editor_color_name->set_name("Color Name Line Editor");
	m_line_editor_color_name->setFixedWidth(100);
	//QRegularExpression rx("^#[0-9a-f]{3}([0-9a-f]{3})?$")
	//m_color_name_line_editor->set_validator(new QRegularExpressionValidator(rx));

	connect(m_line_editor_color_name, &LineEditor::text_edited, [this] {
		qsizetype text_size = m_line_editor_color_name->text()->as<QString>().size();

		if (text_size == 6) // || text_size == 8)
			m_color->set_value(QColor("#" + m_line_editor_color_name->text()->as<QString>()));
		});

	m_radio_button_hue->set_name("Hue Radio Button");
	connect(m_radio_button_hue, &RadioButton::clicked, [this]
		{ m_color_plane->set_active_hsv(HSV::Hue); });

	m_radio_button_sat->set_name("Saturation Radio Button");
	connect(m_radio_button_sat, &RadioButton::clicked, [this]
		{ m_color_plane->set_active_hsv(HSV::Saturation); });

	m_radio_button_val->set_name("Value Radio Button");
	connect(m_radio_button_val, &RadioButton::clicked, [this]
		{ m_color_plane->set_active_hsv(HSV::Value); });

	m_label_hue->set_name("Hue Label");

	m_label_hue_unit->set_name("Hue Unit Label");

	m_label_sat->set_name("Saturation Label");

	m_label_sat_unit->set_name("Saturation Unit Label");

	m_label_val->set_name("Value Label");

	m_label_val_unit->set_name("Value Unit Label");

	m_line_editor_hue->set_name("Hue Line Editor");
	m_line_editor_hue->setFixedWidth(55);

	m_line_editor_sat->set_name("Saturation Line Editor");
	m_line_editor_sat->setFixedWidth(55);

	m_line_editor_val->set_name("Value Line Editor");
	m_line_editor_val->setFixedWidth(55);

	connect(m_line_editor_hue, &LineEditor::text_edited,
		this, &ColorDialog::hsv_changed);

	connect(m_line_editor_sat, &LineEditor::text_edited,
		this, &ColorDialog::hsv_changed);

	connect(m_line_editor_val, &LineEditor::text_edited,
		this, &ColorDialog::hsv_changed);

	m_color_plane->setFixedSize(160, 160);

	connect(m_color_plane, &ColorPlane::active_mode_changed, [this]
		{
			switch (m_color_plane->active_hsv())
				{
				case HSV::Hue:
					m_z_slider->set_limit(359);
					break;
				case HSV::Saturation:
				case HSV::Value:
					m_z_slider->set_limit(255);
					break;
				}
		});

	setup_layout();

	// Assign tag prefixes last!
	assign_tag_prefixes();

	// Set theme
	apply_theme(*layersApp->active_theme());
}

ColorDialog::~ColorDialog()
{
	delete m_color;
}

Themeable* ColorDialog::clone()
{
	return new ColorDialog;
}

Attribute* ColorDialog::color() const
{
	return m_color;
}

void ColorDialog::init_attributes()
{
	m_color->entangle_with(m_color_plane->color());

	connect(m_color, &Attribute::changed, [this]
		{
			QColor color = m_color->as<QColor>();

			m_line_editor_color_name->set_text(
				color.name().remove("#"));

			m_line_editor_hue->set_text(
				QString::number(color.hue()));

			m_line_editor_sat->set_text(
				QString::number(int(round(color.saturationF() * 100.f))));

			m_line_editor_val->set_text(
				QString::number(int(round(color.valueF() * 100.f))));
		});

	m_z_slider->value().entangle_with(m_color_plane->z_value());
}

void ColorDialog::hsv_changed()
{
	float hue_f = m_line_editor_hue->text()->as<float>() / float(MAX_H);
	float sat_f = m_line_editor_sat->text()->as<float>() / 100.f;
	float val_f = m_line_editor_val->text()->as<float>() / 100.f;

	QColor new_color;
	new_color.setHsvF(hue_f, sat_f, val_f);

	m_color->set_value(new_color);
}

void ColorDialog::setup_layout()
{
	// Color Name Layout
	QHBoxLayout* color_name_layout = new QHBoxLayout;
	color_name_layout->setContentsMargins(0, 0, 0, 0);
	color_name_layout->setSpacing(0);
	color_name_layout->addWidget(m_color_unit_label);
	color_name_layout->addWidget(m_line_editor_color_name);

	// Left Layout
	QVBoxLayout* left_layout = new QVBoxLayout;
	left_layout->setContentsMargins(0, 0, 0, 0);
	left_layout->setSpacing(12);
	left_layout->addWidget(m_color_plane);
	left_layout->addLayout(color_name_layout);

	// Hue Layout
	QHBoxLayout* hue_layout = new QHBoxLayout;
	hue_layout->setContentsMargins(0, 0, 0, 0);
	hue_layout->setSpacing(0);
	hue_layout->addWidget(m_radio_button_hue);
	hue_layout->addWidget(m_label_hue);
	hue_layout->addWidget(m_line_editor_hue);
	hue_layout->addWidget(m_label_hue_unit);

	// Sat Layout
	QHBoxLayout* sat_layout = new QHBoxLayout;
	sat_layout->setContentsMargins(0, 0, 0, 0);
	sat_layout->setSpacing(0);
	sat_layout->addWidget(m_radio_button_sat);
	sat_layout->addWidget(m_label_sat);
	sat_layout->addWidget(m_line_editor_sat);
	sat_layout->addWidget(m_label_sat_unit);

	// Val Layout
	QHBoxLayout* val_layout = new QHBoxLayout;
	val_layout->setContentsMargins(0, 0, 0, 0);
	val_layout->setSpacing(0);
	val_layout->addWidget(m_radio_button_val);
	val_layout->addWidget(m_label_val);
	val_layout->addWidget(m_line_editor_val);
	val_layout->addWidget(m_label_val_unit);

	// Right Layout
	QVBoxLayout* right_layout = new QVBoxLayout;
	right_layout->setContentsMargins(0, 0, 0, 0);
	right_layout->setSpacing(0);
	right_layout->addLayout(hue_layout);
	right_layout->addLayout(sat_layout);
	right_layout->addLayout(val_layout);

	// Top Layout
	QHBoxLayout* top_layout = new QHBoxLayout;
	top_layout->setContentsMargins(0, 0, 0, 0);
	top_layout->setSpacing(12);
	top_layout->addLayout(left_layout);
	top_layout->addLayout(right_layout);

	// Main Layout
	QVBoxLayout* main_layout = new QVBoxLayout;
	main_layout->setContentsMargins(7, 7, 7, 7);
	main_layout->setSpacing(12);
	main_layout->addLayout(top_layout);
	main_layout->addWidget(m_z_slider);
	main_layout->addStretch();
	main_layout->addWidget(m_apply_button);
	//main_layout->setAlignment(m_color_plane, Qt::AlignLeft);
	main_layout->setAlignment(m_apply_button, Qt::AlignRight);
	setLayout(main_layout);

	main_layout->activate();
}
