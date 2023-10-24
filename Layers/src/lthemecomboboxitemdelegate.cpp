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

#include <Layers/lthemecomboboxitemdelegate.h>

#include <QMouseEvent>
#include <QPainter>

#include <Layers/lapplication.h>

using Layers::LThemeComboBoxItemDelegate;

bool LThemeComboBoxItemDelegate::editorEvent(
	QEvent* event,
	QAbstractItemModel* model,
	const QStyleOptionViewItem& option,
	const QModelIndex& index)
{
	if (event->type() == QMouseEvent::MouseMove)
		emit mouse_moved(QCursor::pos());

	return false;
}

void LThemeComboBoxItemDelegate::paint(
	QPainter* painter,
	const QStyleOptionViewItem& option,
	const QModelIndex& index) const
{
	LTheme* theme = index.data(Qt::UserRole).value<LTheme*>();

	QColor fill_color = (option.state & QStyle::State_HasFocus) ?
		QColor(QString::fromStdString(
			m_fill->as<std::string>({ "Selected" }))) :
		QColor(QString::fromStdString(
			m_fill->as<std::string>({ "Unselected" })));

	QFont secondary_font(option.font.family(), 8);

	const QFontMetrics& item_font_metrics = option.fontMetrics;
	const QFontMetrics& secondary_font_metrics = QFontMetrics(secondary_font);

	QPainterPath item_text_path;
	QPainterPath secondary_text_path;

	QString item_text = QString::fromStdString(theme->name());
	QString secondary_text;

	if (!theme->publisher().empty())
		secondary_text = QString::fromStdString(theme->publisher());
	else if (!theme->uuid().empty())
		secondary_text = QString::fromStdString(theme->uuid());

	painter->setRenderHint(QPainter::Antialiasing);

	// Draw background
	painter->fillPath(background_path(option, index), fill_color);

	if (!secondary_text.isEmpty())
	{
		// Draw item text and uuid text

		item_text_path.addText(
			QPoint(10, option.rect.center().y() + (item_font_metrics.height() / 2) - 12),
			option.font,
			item_text
		);

		secondary_text_path.addText(
			QPoint(10, option.rect.center().y() + (secondary_font_metrics.height() / 2) + 8),
			secondary_font,
			secondary_text
		);
	}
	else
	{
		// Draw item text only

		item_text_path.addText(
			QPoint(10, option.rect.center().y() + (item_font_metrics.height() / 2) - 2),
			option.font,
			item_text
		);
	}

	QColor text_color =
		QColor(QString::fromStdString(m_text_color->as<std::string>()));

	painter->fillPath(item_text_path, text_color);
	painter->fillPath(secondary_text_path, text_color);

	if (!theme->has_implementation(layersApp->app_display_id().toStdString()))
	{
		QPoint caution_image_location = QPoint(
			option.rect.right() - m_caution_image.width() - 10,
			option.rect.center().y() - (m_caution_image.height() / 2));

		painter->drawImage(caution_image_location, m_caution_image);
	}
}
