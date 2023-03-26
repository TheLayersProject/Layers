#include "Dialog.h"
#include "calculate.h"

#include <Windows.h>
#include <windowsx.h>

#include <QApplication>
#include <QMouseEvent>
#include <QPainterPath>

using Layers::Dialog;

Dialog::Dialog(const QString& title, QWidget* parent) :
	m_window_title_label{ new Label(title) }, QDialog(parent)
{
	init_attributes();
	init_titlebar();

	setAttribute(Qt::WA_TranslucentBackground);
	//setFixedSize(525, 300);
	setWindowFlags(Qt::FramelessWindowHint);
	//installEventFilter(this);

	set_name("dialog");

	setup_layout();
}

void Dialog::set_icon(Graphic* icon)
{
	Themeable::set_icon(icon);

	Graphic* dialog_icon = new Graphic(*icon);

	dialog_icon->setMinimumWidth(40);

	m_titlebar_layout->insertWidget(0, dialog_icon);
}

void Dialog::setLayout(QLayout* layout)
{
	m_main_layout->addLayout(layout);
}

void Dialog::update_content_margins()
{
	int border_thickness = border()->thickness()->as<double>();

	int content_margin_l = margins()->left()->as<double>() + border_thickness;
	int content_margin_t = margins()->top()->as<double>() + border_thickness;
	int content_margin_r = margins()->right()->as<double>() + border_thickness;
	int content_margin_b = margins()->bottom()->as<double>() + border_thickness;

	m_main_layout->setContentsMargins(
		content_margin_l, content_margin_t,
		content_margin_r, content_margin_b);
}

void Dialog::update_titlebar()
{
	int border_thickness = border()->thickness()->as<double>();

	m_titlebar->corner_radii()->top_left()->set_value(
		inner_radius(corner_radii()->top_left()->as<double>(), border_thickness)
	);

	m_titlebar->corner_radii()->top_right()->set_value(
		inner_radius(corner_radii()->top_right()->as<double>(), border_thickness)
	);
}

void Dialog::init_attributes()
{
	ThemeableBox::init_attributes();

	m_border->fill()->set_value(QVariant::fromValue(
		QGradientStops({
			{ 0.0, QColor("#c0c0c0") },
			{ 1.0, Qt::white }
		})));
	m_border->thickness()->set_value(10.0);
	m_corner_radii->top_left()->set_value(10.0);
	m_corner_radii->top_right()->set_value(10.0);
	m_corner_radii->bottom_left()->set_value(10.0);
	m_corner_radii->bottom_right()->set_value(10.0);

	update_content_margins();
	update_titlebar();

	connect(border()->thickness(), &AbstractAttribute::value_changed, [this] {
		update_content_margins();
		update_titlebar();
		});

	for (Attribute* margin : *m_margins)
		connect(margin, &AbstractAttribute::value_changed, this, &Dialog::update_content_margins);
}

bool Dialog::nativeEvent(const QByteArray& eventType, void* message, qintptr* result)
{
	MSG* msg = static_cast<MSG*>(message);

	if (msg->message == WM_NCHITTEST)
	{
		if (isMaximized())
		{
			return false;
		}

		*result = 0;
		const LONG borderWidth = border()->thickness()->as<double>() * devicePixelRatio();;
		RECT winrect;
		GetWindowRect(reinterpret_cast<HWND>(winId()), &winrect);

		// must be short to correctly work with multiple monitors (negative coordinates)
		short x = msg->lParam & 0x0000FFFF;
		short y = (msg->lParam & 0xFFFF0000) >> 16;

		bool resizeWidth = minimumWidth() != maximumWidth();
		bool resizeHeight = minimumHeight() != maximumHeight();

		if (resizeWidth)
		{
			//left border
			if (x >= winrect.left && x < winrect.left + borderWidth)
			{
				*result = HTLEFT;
			}
			//right border
			if (x < winrect.right && x >= winrect.right - borderWidth)
			{
				*result = HTRIGHT;
			}
		}
		if (resizeHeight)
		{
			//bottom border
			if (y < winrect.bottom && y >= winrect.bottom - borderWidth)
			{
				*result = HTBOTTOM;
			}
			//top border
			if (y >= winrect.top && y < winrect.top + borderWidth)
			{
				*result = HTTOP;
			}
		}
		if (resizeWidth && resizeHeight)
		{
			//bottom left corner
			if (x >= winrect.left && x < winrect.left + borderWidth &&
				y < winrect.bottom && y >= winrect.bottom - borderWidth)
			{
				*result = HTBOTTOMLEFT;
			}
			//bottom right corner
			if (x < winrect.right && x >= winrect.right - borderWidth &&
				y < winrect.bottom && y >= winrect.bottom - borderWidth)
			{
				*result = HTBOTTOMRIGHT;
			}
			//top left corner
			if (x >= winrect.left && x < winrect.left + borderWidth &&
				y >= winrect.top && y < winrect.top + borderWidth)
			{
				*result = HTTOPLEFT;
			}
			//top right corner
			if (x < winrect.right && x >= winrect.right - borderWidth &&
				y >= winrect.top && y < winrect.top + borderWidth)
			{
				*result = HTTOPRIGHT;
			}
		}

		if (m_titlebar == QApplication::widgetAt(QCursor::pos())) {
			*result = HTCAPTION;
			return true;
		}

		if (*result != 0) return true;
	}

	return false;
}

void Dialog::paintEvent(QPaintEvent* event)
{
	paint(this);
}

void Dialog::init_titlebar()
{
	m_titlebar->setFixedHeight(45);
	m_titlebar->set_name("titlebar");
	m_titlebar->set_proper_name("Titlebar");

	m_window_title_label->setAttribute(Qt::WA_TransparentForMouseEvents);
	m_window_title_label->set_name("window_title_label");
	m_window_title_label->set_proper_name("Label");
	m_window_title_label->set_padding(0, 8, 0, 0);
	m_window_title_label->set_font_size(14);

	connect(m_exit_button, &Button::clicked, [this] {
		if (!m_functionality_disabled)
			done(QDialog::Rejected);
	});

	m_exit_button->set_name("exit_button");
	m_exit_button->set_proper_name("Exit Button");

	// Add Titlebar's Themeable Child Element References
	//m_titlebar->add_child_themeable_pointer(m_window_title_label);
	//m_titlebar->add_child_themeable_pointer(m_exit_button);

	// Setup Layout

	m_titlebar_layout->setContentsMargins(0, 0, 0, 0);
	m_titlebar_layout->setSpacing(0);
	m_titlebar_layout->addWidget(m_window_title_label);
	m_titlebar_layout->addStretch();
	m_titlebar_layout->addWidget(m_exit_button);

	m_titlebar->setLayout(m_titlebar_layout);
}

void Dialog::setup_layout()
{
	// Main Layout
	update_content_margins();

	m_main_layout->setSpacing(0);
	m_main_layout->addWidget(m_titlebar);
	m_main_layout->setAlignment(m_titlebar, Qt::AlignTop);

	QWidget::setLayout(m_main_layout);

	m_main_layout->activate();
}