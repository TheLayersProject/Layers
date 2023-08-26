#include <Layers/lcombobox.h>

#include <QEvent>
#include <QListView>
#include <QPainter>

#include <Layers/lcomboboxitemdelegate.h>
#include <Layers/lthemeablebox.h>

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
	QString style_sheet =
		"QComboBox::drop-down { "
		"width: 0px; "
		"}";

	setStyleSheet(style_sheet);

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

bool LComboBox::eventFilter(QObject* object, QEvent* event)
{
	if (object == view()->window())
		if (event->type() == QEvent::Show || event->type() == QEvent::Hide)
			update();

	return false;
}

void LComboBox::paint_box(QPainter* painter)
{
	if (!painter)
		return;

	QStringList s = state_combo();

	int border_thickness = m_border_thickness->as<double>(s);

	LCornerRadii border_cr;
	LCornerRadii fill_cr;

	border_cr.top_left = m_corner_radius->as<double>(s);
	border_cr.top_right = border_cr.top_left;
	border_cr.bottom_left = border_cr.top_left;
	border_cr.bottom_right = border_cr.top_left;

	if (view()->window()->isVisible())
		if (is_view_positioned_above())
		{
			border_cr.top_left = 0;
			border_cr.top_right = 0;
		}
		else
		{
			border_cr.bottom_left = 0;
			border_cr.bottom_right = 0;
		}

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
		QPoint(0, 0),
		size() + lsize(1));

	QRect fill_rect = QRect(
		lpoint(border_thickness),
		size() + lsize(1) - lsize(border_thickness * 2));

	QPainterPath fill_path =
		LThemeableBox::box_path(fill_rect, fill_cr);
	QPainterPath border_path =
		LThemeableBox::box_path(border_rect, border_cr) - fill_path;

	/* Draw Border */
	if (border_thickness)
	{
		if (m_border_fill->typeName(s) == "QList<std::pair<double,QColor>>")
		{
			QLinearGradient border_fill_grad;

			border_fill_grad.setStart(border_rect.left(), 0);
			border_fill_grad.setFinalStop(border_rect.right() + 1, 0);
			border_fill_grad.setStops(m_border_fill->as<QGradientStops>(s));

			painter->fillPath(border_path, border_fill_grad);
		}
		else
			painter->fillPath(border_path, m_border_fill->as<QColor>(s));
	}

	/* Draw Fill */
	if (m_fill->typeName(s) == "QList<std::pair<double,QColor>>")
	{
		QLinearGradient fill_gradient;

		fill_gradient.setStart(fill_rect.left(), 0);
		fill_gradient.setFinalStop(fill_rect.right() + 1, 0);
		fill_gradient.setStops(m_fill->as<QGradientStops>(s));

		painter->fillPath(fill_path, fill_gradient);
	}
	else
		painter->fillPath(fill_path, m_fill->as<QColor>(s));
}

void LComboBox::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	paint_box(&painter);

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
