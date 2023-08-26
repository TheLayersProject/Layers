#include <Layers/ldialog.h>

#include <Windows.h>
#include <windowsx.h>

#include <QApplication>
#include <QMouseEvent>
#include <QPainterPath>

#include <Layers/lcalculate.h>

using Layers::LDialog;

LDialog::LDialog(const QString& title, QWidget* parent) :
	m_title_label{ new LLabel(title) }, QDialog(parent)
{
	init_attributes();
	init_layout();
	init_titlebar();
	resize(420, 275);
	setAttribute(Qt::WA_TranslucentBackground);
	setWindowFlags(Qt::FramelessWindowHint);
	update();
}

void LDialog::set_icon(const LGraphic& icon)
{
	m_icon_label = new LLabel(icon);
	m_icon_label->setObjectName("Icon Label");
	m_icon_label->setAlignment(Qt::AlignCenter);
	m_icon_label->setMinimumWidth(40);

	m_titlebar_layout->insertWidget(0, m_icon_label);
}

void LDialog::setLayout(QLayout* layout)
{
	m_main_layout->addLayout(layout);
}

void LDialog::update()
{
	int border_thickness = m_border_thickness->as<double>();

	m_main_layout->setContentsMargins(
		border_thickness + m_margins_left->as<double>(),
		border_thickness + m_margins_top->as<double>(),
		border_thickness + m_margins_right->as<double>(),
		border_thickness + m_margins_bottom->as<double>());

	QWidget::update();
}

bool LDialog::nativeEvent(
	const QByteArray& eventType, void* message, qintptr* result)
{
	MSG* msg = static_cast<MSG*>(message);

	if (msg->message == WM_NCHITTEST)
	{
		if (isMaximized())
			return false;

		*result = 0;
		const LONG borderWidth =
			border_thickness()->as<qreal>() * devicePixelRatio();
		RECT winrect;
		GetWindowRect(reinterpret_cast<HWND>(winId()), &winrect);

		// must be short to correctly work with multiple monitors
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

		if (m_titlebar == QApplication::widgetAt(QCursor::pos()))
		{
			*result = HTCAPTION;
			return true;
		}

		if (*result != 0)
			return true;
	}

	return false;
}

void LDialog::paintEvent(QPaintEvent* event)
{
	paint(this);
}

void LDialog::init_attributes()
{
	LThemeableBox::init_attributes();

	m_border_fill->set_value(QVariant::fromValue(
		QGradientStops({
			{ 0.0, QColor("#3a3c42") },
			{ 1.0, QColor("#42454d") }
			})));
	m_border_thickness->set_value(5.0);
	m_corner_radii_top_left->set_value(12.0);
	m_corner_radii_top_right->set_value(12.0);
	m_corner_radii_bottom_left->set_value(12.0);
	m_corner_radii_bottom_right->set_value(12.0);
	m_fill->set_value(QColor("#36393f"));

	m_titlebar->corner_radii_top_left()->set_value(7);
	m_titlebar->corner_radii_top_right()->set_value(7);
	m_titlebar->fill()->set_value("#25272b");

	m_title_label->text_color()->set_value("#e3e3e3");

	m_exit_button->corner_radii_top_right()->set_value(7);
	m_exit_button->fill()->set_value("#25272b");
}

void LDialog::init_layout()
{
	// Main Layout
	m_main_layout->setSpacing(0);
	m_main_layout->addWidget(m_titlebar);
	m_main_layout->setAlignment(m_titlebar, Qt::AlignTop);
	QWidget::setLayout(m_main_layout);
	m_main_layout->activate();
}

void LDialog::init_titlebar()
{
	m_titlebar->setObjectName("Titlebar");
	m_titlebar->setFixedHeight(40);

	m_title_label->setObjectName("Title Label");
	m_title_label->set_font_size(14);
	m_title_label->setAttribute(Qt::WA_TransparentForMouseEvents);

	connect(m_exit_button, &LButton::clicked,
		[this] { done(QDialog::Rejected); });

	m_exit_button->setObjectName("Exit Button");

	// Setup Titlebar Layout
	m_titlebar_layout->setContentsMargins(5, 0, 0, 0);
	m_titlebar_layout->setSpacing(0);
	m_titlebar_layout->addWidget(m_title_label);
	m_titlebar_layout->addStretch();
	m_titlebar_layout->addWidget(m_exit_button);
	m_titlebar->setLayout(m_titlebar_layout);
}

void Layers::center(QWidget* upper_widget, QWidget* lower_widget)
{
	upper_widget->move(
		lower_widget->x() + (lower_widget->width() - upper_widget->width()) / 2,
		lower_widget->y() + (lower_widget->height() - upper_widget->height()) / 2);
}
