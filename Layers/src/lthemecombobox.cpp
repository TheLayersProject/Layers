#include <Layers/lthemecombobox.h>

#include <QAbstractItemView>
#include <QEvent>
#include <QMouseEvent>

#include <Layers/lapplication.h>
#include <Layers/lthemecomboboxitemdelegate.h>
#include <Layers/lthemecomboboxitemmodel.h>

using Layers::LThemeComboBox;

LThemeComboBox::LThemeComboBox(QWidget* parent) :
	m_model{ new LThemeComboBoxItemModel }, LComboBox(parent)
{
	init_item_delegate();
	setFixedSize(250, 60);
	setModel(m_model);

	m_compatibility_dialog->apply_theme(
		activeTheme()->find_item("App/Theme Compatibility Caution Dialog"));

	connect(this, &QComboBox::highlighted, [this](int index)
	{
		m_highlighted_index = index;

		LTheme* theme = itemData(index).value<LTheme*>();

		if (!theme->has_app_implementation(layersApp->app_identifier()))
		{
			m_compatibility_dialog->set_lineage_table_data(theme->lineage());
			m_compatibility_dialog->set_theme_name(theme->name());

			if (!m_compatibility_dialog->isVisible())
			{
				m_compatibility_dialog->show();
				m_compatibility_dialog->raise();
			}
		}
		else
		{
			m_compatibility_dialog->hide();
		}
	});
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
		if (event->type() == QEvent::Leave && m_compatibility_dialog)
			m_compatibility_dialog->hide();

	return false;
}

void LThemeComboBox::paintEvent(QPaintEvent* event)
{
	LTheme* current_theme = currentData().value<LTheme*>();

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	// Draw background
	painter.fillPath(background_path(), m_fill->as<QColor>());

	QFont item_font = font();
	QFont uuid_font(item_font.family(), 8);

	const QFontMetrics& item_font_metrics = QFontMetrics(item_font);
	const QFontMetrics& uuid_font_metrics = QFontMetrics(uuid_font);

	QPainterPath item_text_path;
	QPainterPath uuid_text_path;

	QString item_text = current_theme->name();
	QString uuid_text;

	if (QUuid* uuid = current_theme->uuid())
		uuid_text = uuid->toString(QUuid::WithoutBraces);

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

void LThemeComboBox::init_item_delegate()
{
	LThemeComboBoxItemDelegate* item_delegate = new LThemeComboBoxItemDelegate;

	connect(item_delegate, &LThemeComboBoxItemDelegate::mouse_moved,
		[this](QPoint mouse_cursor)
	{
		if (m_highlighted_index > -1)
		{
			LTheme* theme = itemData(m_highlighted_index).value<LTheme*>();

			if (!theme->has_app_implementation(layersApp->app_identifier()))
				if (!m_compatibility_dialog->isVisible())
				{
					m_compatibility_dialog->show();
					m_compatibility_dialog->raise();
				}
		}

		m_compatibility_dialog->move(QCursor::pos() + QPoint(20, 20));
	});

	setItemDelegate(item_delegate);
}
