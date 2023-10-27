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

#include <Layers/llabel.h>

#include <QPainter>

using Layers::LAttribute;
using Layers::LGraphic;
using Layers::LLabel;
using Layers::LThemeable;

LLabel::LLabel(QWidget* parent) :
	QLabel(parent)
{
	init();
}

LLabel::LLabel(const QString& text, QWidget* parent) :
	QLabel(text, parent)
{
	init();
}

LLabel::LLabel(const LGraphic& graphic, QWidget* parent) :
	m_graphic{ new LGraphic(graphic) },
	QLabel(parent)
{
	init();

	if (m_graphic->svg_renderer())
	{
		m_repaint_connection =
			connect(m_graphic->svg_renderer(), &LSvgRenderer::repaintNeeded,
				[this] { QWidget::update(); });
	}
	else if (m_graphic->image_sequence())
	{
		connect(&m_timer, &QTimer::timeout, [this]
			{ QWidget::update(); });

		m_timer.start(17);
	}

	setMinimumSize(m_graphic->size());
}

LLabel::~LLabel()
{
	disconnect(m_repaint_connection);

	//delete m_fill;

	if (!m_text_color->parent())
		delete m_text_color;
}

QList<LThemeable*> LLabel::child_themeables(Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables;

	if (m_graphic && m_graphic->svg_renderer())
		child_themeables.append(m_graphic->svg_renderer());

	return child_themeables;
}

LAttribute* LLabel::fill() const
{
	return m_fill;
}

LGraphic* LLabel::graphic() const
{
	return m_graphic;
}

LAttribute* LLabel::text_color() const
{
	return m_text_color;
}

void LLabel::set_font_size(int size)
{
	QFont f = font();

	f.setPointSize(size);

	setFont(f);
}

void LLabel::set_font_size_f(qreal size)
{
	QFont f = font();

	f.setPointSizeF(size);

	setFont(f);
}

QSize LLabel::sizeHint() const
{
	if (m_graphic)
		return m_graphic->size();
	else
		return QLabel::sizeHint();
}

void LLabel::paintEvent(QPaintEvent* event)
{
	if (m_graphic)
	{
		QPainter painter = QPainter(this);

		QSize graphic_size = m_graphic->size();

		int x = 0;
		int y = 0;

		Qt::Alignment a = alignment();

		if (a & Qt::AlignHCenter)
			x = (width() / 2) - (graphic_size.width() / 2);
		else if (a & Qt::AlignRight)
			x = width() - graphic_size.width();

		if (a & Qt::AlignVCenter)
			y = (height() / 2) - (graphic_size.height() / 2);
		else if (a & Qt::AlignBottom)
			y = height() - graphic_size.height();

		if (m_graphic->svg_renderer())
		{
			m_graphic->svg_renderer()->render(&painter,
				QRectF(QPoint(x, y), graphic_size));
		}
		else if (m_graphic->image())
		{
			painter.drawImage(x, y, *m_graphic->image());
		}
		else if (LImageSequence* imgseq = m_graphic->image_sequence())
		{
			if (QImage* next_frame = imgseq->frame(m_frame++))
				painter.drawImage(x, y, *next_frame);
				
			if (m_frame == imgseq->size())
				m_frame = 0;
		}
	}
	else
		QLabel::paintEvent(event);
}

void LLabel::update()
{
	std::vector<std::string> s = state_combo();

	QString style_sheet = "QLabel {";

	// TEMP:
	//style_sheet += "background: " + m_fill->as<QColor>(s).name() + ";";
	style_sheet += "background: transparent;";

	if (!m_graphic)
		style_sheet += "color: " +
			QString::fromStdString(m_text_color->as<std::string>(s)) + ";";

	style_sheet += "}";

	setStyleSheet(style_sheet);

	QWidget::update();
}

void LLabel::init()
{
	init_attributes();
	update();
}

void LLabel::init_attributes()
{
	if (!m_graphic)
		m_text_color->set_parent(this);
}
