#include "ThemeComboBox.h"

#include "Application.h"
#include "Layers.h"
#include "ThemeComboBoxItemDelegate.h"
#include "ThemeComboBoxItemModel.h"

#include "Widgets/Dialogs/ThemeCompatibilityCautionDialog.h"

#include <QAbstractItemView>
#include <QEvent>

using Layers::ThemeComboBox;

ThemeComboBox::ThemeComboBox(QWidget* parent) :
	m_model{ new ThemeComboBoxItemModel }, ComboBox(parent)
{
	setFixedSize(250, 60);
	setItemDelegate(new ThemeComboBoxItemDelegate);
	setModel(m_model);
}

void ThemeComboBox::clear()
{
	m_model->clear();
}

void ThemeComboBox::addItem(Theme* theme)
{
	m_model->append(theme);
}

bool ThemeComboBox::eventFilter(QObject* object, QEvent* event)
{
	ComboBox::eventFilter(object, event);

	if (object == view()->window())
	{
		if (event->type() == QEvent::Leave)
		{
			ThemeCompatibilityCautionDialog* dialog =
				layersApp->theme_compatibility_caution_dialog();

			if (dialog->isVisible())
				dialog->hide();
		}
	}

	return false;
}

void ThemeComboBox::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	// Draw background
	if (!m_fill->disabled())
		painter.fillPath(background_path(), m_fill->as<QColor>());

	QFont item_font = font();
	QFont uuid_font(item_font.family(), 8);

	const QFontMetrics& item_font_metrics = QFontMetrics(item_font);
	const QFontMetrics& uuid_font_metrics = QFontMetrics(uuid_font);

	QPainterPath item_text_path;
	QPainterPath uuid_text_path;

	QString item_text = currentData(Qt::DisplayRole).toString();
	QString uuid_text = currentData(Layers::UuidIfExists).toString();

	if (!uuid_text.isEmpty())
	{
		// Draw item text and uuid text

		item_text_path.addText(
			QPoint(10, rect().center().y() + (item_font_metrics.height() / 2) - 12),
			item_font,
			item_text
		);

		uuid_text_path.addText(
			QPoint(10, rect().center().y() + (uuid_font_metrics.height() / 2) + 8),
			uuid_font,
			uuid_text
		);
	}
	else
	{
		// Draw item text only

		item_text_path.addText(
			QPoint(10, rect().center().y() + (item_font_metrics.height() / 2) - 2),
			item_font,
			item_text
		);
	}

	painter.fillPath(item_text_path, m_text_color->as<QColor>());
	painter.fillPath(uuid_text_path, m_text_color->as<QColor>());
}
