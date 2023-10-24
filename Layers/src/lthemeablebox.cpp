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

#include <Layers/lthemeablebox.h>

#include <QEvent>
#include <QPainterPath>
#include <QWidget>

#include <Layers/lalgorithms.h>

using Layers::LAttribute;
using Layers::LThemeableBox;

LAttribute* LThemeableBox::border_fill() const
{
	return m_border_fill;
}

LAttribute* LThemeableBox::border_thickness() const
{
	return m_border_thickness;
}

QPainterPath LThemeableBox::box_path(
	const QRect& box_rect, const LCornerRadii& corner_radii)
{
	QPainterPath path;

	int corner_diameter_tl = corner_radii.top_left * 2;
	int corner_diameter_tr = corner_radii.top_right * 2;
	int corner_diameter_bl = corner_radii.bottom_left * 2;
	int corner_diameter_br = corner_radii.bottom_right * 2;

	/* Move to starting point */
	path.moveTo(box_rect.topLeft() + QPoint(0, corner_radii.top_left));

	/* Arc TL */
	path.arcTo(
		QRect(box_rect.topLeft(),
			lsize(corner_diameter_tl)),
		180, -90);

	/* Line Top */
	path.lineTo(
		box_rect.right() - corner_radii.top_right,
		box_rect.top());

	/* Arc TR */
	path.arcTo(
		QRect(box_rect.topRight() - QPoint(corner_diameter_tr, 0),
			lsize(corner_diameter_tr)),
		90, -90);

	/* Line Right */
	path.lineTo(
		box_rect.right(),
		box_rect.bottom() - corner_radii.bottom_right);

	/* Arc BR */
	path.arcTo(
		QRect(box_rect.bottomRight() - lpoint(corner_diameter_br),
			lsize(corner_diameter_br)),
		0, -90);

	/* Line Bottom */
	path.lineTo(box_rect.bottomLeft() + QPoint(corner_radii.bottom_left, 0));

	/* Arc BL */
	path.arcTo(
		QRect(box_rect.bottomLeft() - QPoint(0, corner_diameter_bl),
			lsize(corner_diameter_bl)),
		-90, -90);

	/* Line Left */
	path.lineTo(box_rect.topLeft() + QPoint(0, corner_radii.top_left));

	return path;
}

LAttribute* LThemeableBox::corner_radii_bottom_left() const
{
	return m_corner_radii_bottom_left;
}

LAttribute* LThemeableBox::corner_radii_bottom_right() const
{
	return m_corner_radii_bottom_right;
}

LAttribute* LThemeableBox::corner_radii_top_left() const
{
	return m_corner_radii_top_left;
}

LAttribute* LThemeableBox::corner_radii_top_right() const
{
	return m_corner_radii_top_right;
}

LAttribute* LThemeableBox::fill() const
{
	return m_fill;
}

LAttribute* LThemeableBox::margins_bottom() const
{
	return m_margins_bottom;
}

LAttribute* LThemeableBox::margins_left() const
{
	return m_margins_left;
}

LAttribute* LThemeableBox::margins_right() const
{
	return m_margins_right;
}

LAttribute* LThemeableBox::margins_top() const
{
	return m_margins_top;
}

void LThemeableBox::set_margin(double margin)
{
	set_margin(margin, margin, margin, margin);
}

void LThemeableBox::set_margin(
	double left, double top, double right, double bottom)
{
	m_margins_left->set_value(left);
	m_margins_top->set_value(top);
	m_margins_right->set_value(right);
	m_margins_bottom->set_value(bottom);
}

void LThemeableBox::init_attributes()
{
	if (QObject* object = dynamic_cast<QObject*>(this))
	{
		m_border_fill->setParent(object);
		m_border_thickness->setParent(object);
		m_corner_radii_bottom_left->setParent(object);
		m_corner_radii_bottom_right->setParent(object);
		m_corner_radii_top_left->setParent(object);
		m_corner_radii_top_right->setParent(object);
		m_fill->setParent(object);
		m_margins_bottom->setParent(object);
		m_margins_left->setParent(object);
		m_margins_right->setParent(object);
		m_margins_top->setParent(object);
	}
}

void LThemeableBox::paint(QWidget* widget)
{
	QPainter painter(widget);
	painter.setRenderHint(QPainter::Antialiasing);

	QStringList s = state_combo();

	int border_thickness = (widget->isMaximized()) ?
		0 : m_border_thickness->as<double>(s);

	int margin_left = m_margins_left->as<double>(s);
	int margin_top = m_margins_top->as<double>(s);
	int margin_right = m_margins_right->as<double>(s);
	int margin_bottom = m_margins_bottom->as<double>(s);

	QSize draw_size = QSize(
		widget->width() - margin_left - margin_right,
		widget->height() - margin_top - margin_bottom);

	LCornerRadii border_cr;
	LCornerRadii fill_cr;

	border_cr.top_left = (widget->isMaximized()) ?
		0 : m_corner_radii_top_left->as<double>(s);

	border_cr.top_right = (widget->isMaximized()) ?
		0 : m_corner_radii_top_right->as<double>(s);

	border_cr.bottom_left = (widget->isMaximized()) ?
		0 : m_corner_radii_bottom_left->as<double>(s);

	border_cr.bottom_right = (widget->isMaximized()) ?
		0 : m_corner_radii_bottom_right->as<double>(s);

	fill_cr.top_left = (border_thickness) ?
		inner_radius(border_cr.top_left, border_thickness) :
		border_cr.top_left;

	fill_cr.top_right = (border_thickness) ?
		inner_radius(border_cr.top_right, border_thickness) :
		border_cr.top_right;

	fill_cr.bottom_left = (border_thickness) ?
		inner_radius(border_cr.bottom_left, border_thickness) :
		border_cr.bottom_left;

	fill_cr.bottom_right = (border_thickness) ?
		inner_radius(border_cr.bottom_right, border_thickness) :
		border_cr.bottom_right;

	QRect border_rect = QRect(
		QPoint(margin_left, margin_top),
		draw_size + lsize(1));

	QRect fill_rect = QRect(
		border_rect.topLeft() + lpoint(border_thickness),
		draw_size + lsize(1) - lsize(border_thickness * 2));

	QPainterPath fill_path = box_path(fill_rect, fill_cr);
	QPainterPath border_path = box_path(border_rect, border_cr) - fill_path;

	/* Draw Border */
	if (border_thickness)
	{
		if (auto stops = m_border_fill->as_if<std::vector<std::string>>(s))
		{
			QLinearGradient border_fill_grad;

			border_fill_grad.setStart(border_rect.left(), 0);
			border_fill_grad.setFinalStop(border_rect.right() + 1, 0);
			border_fill_grad.setStops(to_QGradientStops(*stops));

			painter.fillPath(border_path, border_fill_grad);
		}
		else
			painter.fillPath(border_path,
				QColor(QString::fromStdString(
					m_border_fill->as<std::string>(s))));
	}

	/* Draw Fill */
	if (auto stops = m_fill->as_if<std::vector<std::string>>(s))
	{
		QLinearGradient fill_grad;

		fill_grad.setStart(fill_rect.left(), 0);
		fill_grad.setFinalStop(fill_rect.right() + 1, 0);
		fill_grad.setStops(to_QGradientStops(*stops));

		painter.fillPath(fill_path, fill_grad);
	}
	else
		painter.fillPath(fill_path,
			QColor(QString::fromStdString(m_fill->as<std::string>(s))));
}
