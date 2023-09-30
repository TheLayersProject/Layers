/*
 * Copyright (C) 2023 The Layers Project
 *
 * This file is part of Layers.
 *
 * Layers is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Layers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Layers. If not, see <https://www.gnu.org/licenses/>.
 */

#include <Layers/lcolordialog.h>

#include <QRegularExpressionValidator>

#include <Layers/lcalculate.h>
#include <Layers/lapplication.h>

using Layers::LAttribute;
using Layers::LColorDialog;
using Layers::LThemeable;

LColorDialog::LColorDialog(QWidget* parent) :
	LDialog("Color", parent)
{
	init_attributes();
	init_layout();
	set_icon(LGraphic(":/images/color_icon.png"));
	setObjectName("Color Dialog");
	setFixedSize(315, 400);

	m_apply_button->setObjectName("Apply Button");
	m_apply_button->set_font_size_f(10.5);
	m_apply_button->set_padding(6);
	m_apply_button->setFixedHeight(30);

	connect(m_apply_button, &LButton::clicked,
		[this] { done(QDialog::Accepted); });

	m_color_unit_label->setObjectName("Color Unit Label");

	m_color_name_editor->setObjectName("Color Name Editor");
	m_color_name_editor->setFixedSize(100, 40);
	//QRegularExpression rx("^#[0-9a-f]{3}([0-9a-f]{3})?$")
	//m_color_name_line_editor->set_validator(
	//	new QRegularExpressionValidator(rx));

	connect(m_color_name_editor, &LLineEditor::text_edited,
		[this]
		{
			qsizetype text_size =
				m_color_name_editor->text()->as<QString>().size();

			if (text_size == 6) // || text_size == 8)
				m_color->set_value(
					QColor("#" + m_color_name_editor->text()->as<QString>()));
		});

	m_radio_button_hue->setObjectName("Hue Radio Button");
	connect(m_radio_button_hue, &LRadioButton::clicked, [this]
		{ m_color_plane->set_z_dimension(HSV::Hue); });

	m_radio_button_sat->setObjectName("Saturation Radio Button");
	connect(m_radio_button_sat, &LRadioButton::clicked, [this]
		{ m_color_plane->set_z_dimension(HSV::Saturation); });

	m_radio_button_val->setObjectName("Value Radio Button");
	connect(m_radio_button_val, &LRadioButton::clicked, [this]
		{ m_color_plane->set_z_dimension(HSV::Value); });

	m_label_hue->setObjectName("Hue Label");

	m_label_hue_unit->setObjectName("Hue Unit Label");

	m_label_sat->setObjectName("Saturation Label");

	m_label_sat_unit->setObjectName("Saturation Unit Label");

	m_label_val->setObjectName("Value Label");

	m_label_val_unit->setObjectName("Value Unit Label");

	m_line_editor_hue->setObjectName("Hue Line Editor");
	m_line_editor_hue->setFixedSize(55, 40);

	m_line_editor_sat->setObjectName("Saturation Line Editor");
	m_line_editor_sat->setFixedSize(55, 40);

	m_line_editor_val->setObjectName("Value Line Editor");
	m_line_editor_val->setFixedSize(55, 40);

	connect(m_line_editor_hue, &LLineEditor::text_edited,
		this, &LColorDialog::hsv_changed);

	connect(m_line_editor_sat, &LLineEditor::text_edited,
		this, &LColorDialog::hsv_changed);

	connect(m_line_editor_val, &LLineEditor::text_edited,
		this, &LColorDialog::hsv_changed);

	m_color_plane->setFixedSize(160, 160);

	connect(m_color_plane, &LColorPlane::z_dimension_changed,
		[this]
		{
			switch (m_color_plane->z_dimension())
				{
				case HSV::Hue:
					m_z_slider->set_limit(MAX_H);
					break;
				case HSV::Saturation:
				case HSV::Value:
					m_z_slider->set_limit(MAX_SV);
					break;
				}
		});

	m_z_slider->setObjectName("Z-Slider");
}

LColorDialog::~LColorDialog()
{
	delete m_color;
}

LAttribute* LColorDialog::color() const
{
	return m_color;
}

void LColorDialog::hsv_changed()
{
	float hue_f = m_line_editor_hue->text()->as<float>() / float(MAX_H);
	float sat_f = m_line_editor_sat->text()->as<float>() / 100.f;
	float val_f = m_line_editor_val->text()->as<float>() / 100.f;

	QColor new_color;
	new_color.setHsvF(hue_f, sat_f, val_f);

	m_color->set_value(new_color);
}

void LColorDialog::init_attributes()
{
	m_color->set_link_attribute(m_color_plane->color());

	connect(m_color, &LAttribute::changed, [this]
		{
			QColor color = m_color->as<QColor>();

			m_color_name_editor->set_text(
				color.name().remove("#"));

			m_line_editor_hue->set_text(
				QString::number(color.hue()));

			m_line_editor_sat->set_text(
				QString::number(int(round(color.saturationF() * 100.f))));

			m_line_editor_val->set_text(
				QString::number(int(round(color.valueF() * 100.f))));
		});

	m_z_slider->value()->set_link_attribute(m_color_plane->z_axis());
}

void LColorDialog::init_layout()
{
	// Color Name Layout
	QHBoxLayout* color_name_layout = new QHBoxLayout;
	color_name_layout->setContentsMargins(0, 0, 0, 0);
	color_name_layout->setSpacing(0);
	color_name_layout->addWidget(m_color_unit_label);
	color_name_layout->addWidget(m_color_name_editor);

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
	main_layout->setAlignment(m_apply_button, Qt::AlignRight);
	setLayout(main_layout);

	main_layout->activate();
}
