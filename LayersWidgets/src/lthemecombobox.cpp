#include <LayersWidgets/lthemecombobox.h>

#include <QAbstractItemView>
#include <QEvent>

#include <LayersWidgets/lapplication.h>
#include <LayersWidgets/lenums.h>
#include <LayersWidgets/lthemecomboboxitemdelegate.h>
#include <LayersWidgets/lthemecomboboxitemmodel.h>
#include <LayersWidgets/lthemecompatibilitycautiondialog.h>

using Layers::LThemeComboBox;

LThemeComboBox::LThemeComboBox(QWidget* parent) :
	m_model{ new LThemeComboBoxItemModel }, LComboBox(parent)
{
	setFixedSize(250, 60);
	setItemDelegate(new LThemeComboBoxItemDelegate);
	setModel(m_model);
}

void LThemeComboBox::clear()
{
	m_model->clear();
}

void LThemeComboBox::addItem(LTheme* theme)
{
	m_model->append(theme);
}

bool LThemeComboBox::eventFilter(QObject* object, QEvent* event)
{
	LComboBox::eventFilter(object, event);

	if (object == view()->window())
	{
		if (event->type() == QEvent::Leave)
		{
			LThemeCompatibilityCautionDialog* dialog =
				layersApp->theme_compatibility_caution_dialog();

			if (dialog->isVisible())
				dialog->hide();
		}
	}

	return false;
}

void LThemeComboBox::paintEvent(QPaintEvent* event)
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
