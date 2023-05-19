#include "ComboBox.h"
#include "ComboBoxItemDelegate.h"

#include <QEvent>
#include <QListView>
#include <QPainter>

using Layers::ComboBox;
using Layers::Themeable;

ComboBox::ComboBox(QWidget* parent) : QComboBox(parent)
{
	setItemDelegate(new ComboBoxItemDelegate);

	view()->window()->installEventFilter(this);
	view()->window()->setAttribute(Qt::WA_TranslucentBackground);
	view()->window()->setWindowFlags(
		Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
	view()->setMouseTracking(true);

	init_attributes();
	update_stylesheet();
}

ComboBox::~ComboBox()
{
	delete m_border;
	delete m_corner_radius;
	delete m_fill;
	delete m_text_color;

	m_border = nullptr;
	m_corner_radius = nullptr;
	m_fill = nullptr;
	m_text_color = nullptr;
}

QList<Themeable*> ComboBox::child_themeables(Qt::FindChildOptions options)
{
	QList<Themeable*> child_themeables = Themeable::child_themeables(options);

	if (Themeable* themeable_item_delegate = dynamic_cast<Themeable*>(itemDelegate()))
	{
		child_themeables.append(themeable_item_delegate);

		if (options == Qt::FindChildrenRecursively)
		{
			QList<QObject*> delegate_child_objects = itemDelegate()->findChildren<QObject*>(options);

			for (QObject* delegate_child_object : delegate_child_objects)
				if (Themeable* child_themeable = dynamic_cast<Themeable*>(delegate_child_object))
					child_themeables.append(child_themeable);
		}
	}

	return child_themeables;
}

void ComboBox::setFixedHeight(int h)
{
	QComboBox::setFixedHeight(h);

	update_stylesheet();
}

void ComboBox::setFixedSize(int w, int h)
{
	ComboBox::setFixedSize(QSize(w, h));
}

void ComboBox::setFixedSize(const QSize& s)
{
	QComboBox::setFixedSize(s);

	update_stylesheet();
}

void ComboBox::setFixedWidth(int w)
{
	QComboBox::setFixedWidth(w);

	update_stylesheet();
}

void ComboBox::showPopup()
{
	QComboBox::showPopup();

	if (ComboBoxItemDelegate* combobox_delegate =
		dynamic_cast<ComboBoxItemDelegate*>(itemDelegate()))
	{
		combobox_delegate->set_is_above_control(
			view()->window()->y() <= mapToGlobal(this->rect().topLeft()).y());
	}
}

void ComboBox::update_stylesheet()
{
	QString stylesheet =
		"QComboBox {"
		"border: " + m_border->thickness()->as<QString>() + "px solid " + m_border->fill()->as<QColor>().name() + ";"
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
		if (view()->window()->y() <= mapToGlobal(this->rect().topLeft()).y())
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

	if (!m_fill->disabled())
		stylesheet.append(
			"QComboBox {"
			"background: " + m_fill->as<QColor>().name() + ";"
			"}");
	else
		stylesheet.append(
			"QComboBox {"
			"background: transparent;"
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

	update();
}

QPainterPath ComboBox::background_path() const
{
	QPainterPath background_path;

	int cr_tl = m_corner_radius->as<int>();
	int cr_tr = cr_tl;
	int cr_bl = cr_tl;
	int cr_br = cr_tl;

	if (view()->window()->isVisible())
	{
		if (view()->window()->y() <= mapToGlobal(this->rect().topLeft()).y())
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

bool ComboBox::eventFilter(QObject* object, QEvent* event)
{
	if (object == view()->window())
	{
		if (event->type() == QEvent::Show || event->type() == QEvent::Hide)
		{
			update_stylesheet();
		}
	}

	return false;
}

void ComboBox::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	// Draw background
	if (!m_fill->disabled())
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

void ComboBox::init_attributes()
{
	m_attributes.insert({
		{ "border", m_border },
		{ "corner_radii", m_corner_radius },
		{ "fill", m_fill },
		{ "text_color", m_text_color }
		});

	connect(m_border->fill(), &AbstractAttribute::changed, [this] { update_stylesheet(); });
	connect(m_border->thickness(), &AbstractAttribute::changed, [this] { update_stylesheet(); });
	connect(m_corner_radius, &AbstractAttribute::changed, [this] { update_stylesheet(); });
	connect(m_fill, &AbstractAttribute::changed, [this] { update_stylesheet(); });
	connect(m_text_color, &AbstractAttribute::changed, [this] { update_stylesheet(); });

	m_border->thickness()->set_value(0.0);
}
