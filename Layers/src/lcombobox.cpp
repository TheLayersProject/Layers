#include <Layers/lcombobox.h>

#include <QEvent>
#include <QListView>
#include <QPainter>

#include <Layers/lcomboboxitemdelegate.h>

using Layers::LAttribute;
using Layers::LComboBox;
using Layers::LThemeable;

LComboBox::LComboBox(QWidget* parent) : QComboBox(parent)
{
	setItemDelegate(new LComboBoxItemDelegate);

	view()->window()->installEventFilter(this);
	view()->window()->setAttribute(Qt::WA_TranslucentBackground);
	view()->window()->setWindowFlags(
		Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
	view()->setMouseTracking(true);

	update();
}

LAttribute* LComboBox::border_fill() const
{
	return m_border_fill;
}

LAttribute* LComboBox::border_thickness() const
{
	return m_border_thickness;
}

QList<LThemeable*> LComboBox::child_themeables(Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables =
		LThemeable::child_themeables(options);

	if (LThemeable* themeable_item_delegate =
		dynamic_cast<LThemeable*>(itemDelegate()))
	{
		child_themeables.append(themeable_item_delegate);

		if (options == Qt::FindChildrenRecursively)
		{
			QList<QObject*> delegate_child_objects =
				itemDelegate()->findChildren<QObject*>(options);

			for (QObject* delegate_child_object : delegate_child_objects)
				if (LThemeable* child_themeable =
					dynamic_cast<LThemeable*>(delegate_child_object))
				{
					child_themeables.append(child_themeable);
				}
		}
	}

	return child_themeables;
}

LAttribute* LComboBox::corner_radius() const
{
	return m_corner_radius;
}

LAttribute* LComboBox::fill() const
{
	return m_fill;
}

bool LComboBox::is_view_positioned_above() const
{
	return view()->window()->y() <= mapToGlobal(this->rect().topLeft()).y();
}

void LComboBox::setFixedHeight(int h)
{
	QComboBox::setFixedHeight(h);

	update();
}

void LComboBox::setFixedSize(int w, int h)
{
	LComboBox::setFixedSize(QSize(w, h));
}

void LComboBox::setFixedSize(const QSize& s)
{
	QComboBox::setFixedSize(s);

	update();
}

void LComboBox::setFixedWidth(int w)
{
	QComboBox::setFixedWidth(w);

	update();
}

void LComboBox::showPopup()
{
	QComboBox::showPopup();

	if (LComboBoxItemDelegate* combobox_delegate =
		dynamic_cast<LComboBoxItemDelegate*>(itemDelegate()))
	{
		combobox_delegate->set_is_above_control(is_view_positioned_above());
	}
}

LAttribute* LComboBox::text_color() const
{
	return m_text_color;
}

void LComboBox::update()
{
	QString stylesheet =
		"QComboBox {"
		"border: " + m_border_thickness->as<QString>() + "px "
		"	solid " + m_border_fill->as<QColor>().name() + ";"
		"color: " + m_text_color->as<QColor>().name() + ";"
		"}"
		
		"QComboBox::drop-down { "
		"width: 0px; "
		"}";

	QString corner_radius = m_corner_radius->as<QString>();

	if (!view()->window()->isVisible())
		stylesheet.append(
			"QComboBox {"
			"border-top-left-radius: " + corner_radius + "px;"
			"border-top-right-radius: " + corner_radius + "px;"
			"border-bottom-left-radius: " + corner_radius + "px;"
			"border-bottom-right-radius: " + corner_radius + "px;"
			"}");
	else
	{
		if (is_view_positioned_above())
			stylesheet.append(
				"QComboBox {"
				"border-top-left-radius: 0px;"
				"border-top-right-radius: 0px;"
				"border-bottom-left-radius: " + corner_radius + "px;"
				"border-bottom-right-radius: " + corner_radius + "px;"
				"}");
		else
			stylesheet.append(
				"QComboBox {"
				"border-top-left-radius: " + corner_radius + "px;"
				"border-top-right-radius: " + corner_radius + "px;"
				"border-bottom-left-radius: 0px;"
				"border-bottom-right-radius: 0px;"
				"}");
	}

	stylesheet.append(
		"QComboBox {"
		"background: " + m_fill->as<QColor>().name() + ";"
		"}");

	setStyleSheet(stylesheet);

	view()->setStyleSheet(
		"QAbstractItemView {"
		"background: transparent;"
		"border: none;"
		"}"

		"QAbstractItemView::item {"
		"height: " + QString::number(height()) + "px;"
		"}"
	);

	QWidget::update();
}

QPainterPath LComboBox::background_path() const
{
	QPainterPath background_path;

	int cr_tl = m_corner_radius->as<int>();
	int cr_tr = cr_tl;
	int cr_bl = cr_tl;
	int cr_br = cr_tl;

	if (view()->window()->isVisible())
	{
		if (is_view_positioned_above())
		{
			cr_tl = 0;
			cr_tr = 0;
		}
		else
		{
			cr_bl = 0;
			cr_br = 0;
		}
	}

	int doubled_cr_tl = cr_tl * 2;
	int doubled_cr_tr = cr_tr * 2;
	int doubled_cr_bl = cr_bl * 2;
	int doubled_cr_br = cr_br * 2;

	// Move to start point
	background_path.moveTo(0, cr_tl);

	// Arc Top-Left
	background_path.arcTo(
		QRect(
			0, 0,
			doubled_cr_tl, doubled_cr_tl
		),
		180, -90);

	// Line Top
	background_path.lineTo(width() - cr_tr, 0);

	// Arc Top-Right
	background_path.arcTo(
		QRect(
			width() - doubled_cr_tr, 0,
			doubled_cr_tr, doubled_cr_tr
		),
		90, -90);

	// Line Right
	background_path.lineTo(width(), height() - cr_br);

	// Arc Bottom-Right
	background_path.arcTo(
		QRect(
			width() - doubled_cr_br, height() - doubled_cr_br,
			doubled_cr_br, doubled_cr_br
		),
		0, -90);

	// Line Bottom
	background_path.lineTo(cr_bl, height());

	// Arc Bottom-Left
	background_path.arcTo(
		QRect(
			0, height() - doubled_cr_bl,
			doubled_cr_bl, doubled_cr_bl
		),
		-90, -90);

	// Line Left
	background_path.lineTo(0, cr_tl);

	return background_path;
}

bool LComboBox::eventFilter(QObject* object, QEvent* event)
{
	if (object == view()->window())
		if (event->type() == QEvent::Show || event->type() == QEvent::Hide)
			update();

	return false;
}

void LComboBox::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	// Draw background
	painter.fillPath(background_path(), m_fill->as<QColor>());

	QFont item_font = font();

	const QFontMetrics& item_font_metrics = QFontMetrics(item_font);

	QPainterPath item_text_path;

	QString item_text = currentData(Qt::DisplayRole).toString();

	item_text_path.addText(
		QPoint(10, rect().center().y() + (item_font_metrics.height() / 2) - 2),
		item_font,
		item_text
	);

	painter.fillPath(item_text_path, m_text_color->as<QColor>());
}
