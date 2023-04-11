#include "ThemeComboBoxItemDelegate.h"

#include "Application.h"
#include "Layers.h"

#include "Widgets/Dialogs/ThemeCompatibilityCautionDialog.h"

#include <QMouseEvent>
#include <QPainter>

using Layers::ThemeComboBoxItemDelegate;

bool ThemeComboBoxItemDelegate::editorEvent(
	QEvent* event,
	QAbstractItemModel* model,
	const QStyleOptionViewItem& option,
	const QModelIndex& index)
{
	if (event->type() == QMouseEvent::MouseMove)
	{
		ThemeCompatibilityCautionDialog* dialog =
			layersApp->theme_compatibility_caution_dialog();

		if (!index.data(Layers::AppImplementationAvailable).toBool())
		{
			dialog->move(QCursor::pos() + QPoint(20, 20));

			if (!dialog->isVisible())
			{
				Theme* theme = layersApp->theme(index.data(Qt::UserRole).toString());

				dialog->set_lineage_table_data(theme->lineage());
				dialog->set_theme_name(theme->name());

				dialog->show();
				dialog->raise();
			}
		}
		else
		{
			dialog->hide();
		}
	}

	return false;
}

void ThemeComboBoxItemDelegate::paint(
	QPainter* painter,
	const QStyleOptionViewItem& option,
	const QModelIndex& index) const
{
	QColor fill_color = (option.state & QStyle::State_HasFocus) ?
		m_fill->as<QColor>("Selected") : m_fill->as<QColor>("Unselected");

	QFont uuid_font(option.font.family(), 8);

	const QFontMetrics& item_font_metrics = option.fontMetrics;
	const QFontMetrics& uuid_font_metrics = QFontMetrics(uuid_font);

	QPainterPath item_text_path;
	QPainterPath uuid_text_path;

	QString item_text = index.data().toString();
	QString uuid_text = index.data(Layers::UuidIfExists).toString();

	painter->setRenderHint(QPainter::Antialiasing);

	// Draw background
	if (!m_fill->disabled())
		painter->fillPath(background_path(option, index), fill_color);

	if (!uuid_text.isEmpty())
	{
		// Draw item text and uuid text

		item_text_path.addText(
			QPoint(10, option.rect.center().y() + (item_font_metrics.height() / 2) - 12),
			option.font,
			item_text
		);

		uuid_text_path.addText(
			QPoint(10, option.rect.center().y() + (uuid_font_metrics.height() / 2) + 8),
			uuid_font,
			uuid_text
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

	painter->fillPath(item_text_path, m_text_color->as<QColor>());
	painter->fillPath(uuid_text_path, m_text_color->as<QColor>());

	if (!index.data(Layers::AppImplementationAvailable).toBool())
	{
		QPoint caution_image_location = QPoint(
			option.rect.right() - m_caution_image.width() - 10,
			option.rect.center().y() - (m_caution_image.height() / 2));

		painter->drawImage(caution_image_location, m_caution_image);
	}
}
