#include <Layers/lmainwindow.h>

#include <Windows.h>
#include <windowsx.h>

#include <QIcon>
#include <QPainterPath>

#include <Layers/lapplication.h>
#include <Layers/lcalculate.h>
#include <Layers/lthemecreatordialog.h>

#include "lmainwindowtitlebar.h"
#include "lsettingsmenu.h"
#include "lthemeswidget.h"

using Layers::LSettingsMenu;
using Layers::LThemeable;
using Layers::LMainWindowTitlebar;
using Layers::LMainWindow;

LMainWindow::LMainWindow(QWidget* parent) :
	m_titlebar{ new LMainWindowTitlebar },
	LWidget(parent)
{
	init_attributes();
	init_layout();
	init_titlebar_connections();
	resize(1000, 700);
	setObjectName("Main Window");
	setAttribute(Qt::WA_TranslucentBackground);
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

	connect(m_titlebar->menu_tab_bar(), &LTabBar::index_changed,
		[this](int prev_index, int new_index)
		{
			if (QWidget* prev_widget = (prev_index != -1) ?
				m_central_widgets[prev_index] : nullptr)
			{
				prev_widget->hide();
			}

			if (QWidget* new_widget = (new_index != -1) ?
				m_central_widgets[new_index] : nullptr)
			{
				new_widget->show();
			}
		});

	connect(m_titlebar->menu_tab_bar(), &LTabBar::tab_closed,
		[this](int i)
		{
			m_central_widgets.takeAt(i)->deleteLater();

			if (m_central_widgets.isEmpty())
				qApp->quit();
		});

	m_separator->setObjectName("Separator");
	m_separator->setFixedHeight(3);
}

void LMainWindow::open_central_widget(QWidget* central_widget)
{
	m_titlebar->menu_tab_bar()->add_tab(central_widget->objectName());

	_open_central_widget(central_widget);
}

void LMainWindow::open_central_widget(
	QWidget* central_widget, const LGraphic& tab_icon_graphic)
{
	m_titlebar->menu_tab_bar()->add_tab(
		tab_icon_graphic, central_widget->objectName());

	_open_central_widget(central_widget);
}

void LMainWindow::update()
{
	if (isMaximized())
		m_main_layout->setContentsMargins(0, 0, 0, 0);
	else
	{
		int border_thickness = m_border_thickness->as<double>();

		m_main_layout->setContentsMargins(
			border_thickness + m_margins_left->as<double>(),
			border_thickness + m_margins_top->as<double>(),
			border_thickness + m_margins_right->as<double>(),
			border_thickness + m_margins_bottom->as<double>());
	}

	QWidget::update();
}

bool LMainWindow::nativeEvent(
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

void LMainWindow::new_theme_clicked()
{
	LThemeCreatorDialog dialog;

	center(&dialog, this);

	dialog.exec();
}

void LMainWindow::init_attributes()
{
	m_fill->set_link_attribute(layersApp->primary());

	m_border_thickness->set_value(15.0);
	m_border_fill->set_value(
		QVariant::fromValue(
			QGradientStops({ { 0.0, Qt::lightGray },{ 1.0, Qt::darkGray } })));
	m_corner_radii_top_left->set_value(10.0);
	m_corner_radii_top_right->set_value(10.0);
	m_corner_radii_bottom_left->set_value(10.0);
	m_corner_radii_bottom_right->set_value(10.0);

	m_separator->fill()->set_value(QColor("#25272b"));
}

void LMainWindow::init_layout()
{
	int margin = border_thickness()->as<double>();

	m_main_layout->setContentsMargins(margin, margin, margin, margin);
	m_main_layout->setSpacing(0);
	m_main_layout->addWidget(m_titlebar);
	m_main_layout->addWidget(m_separator);

	setLayout(m_main_layout);
}

void LMainWindow::init_titlebar_connections()
{
	connect(m_titlebar->settings_button(), &LButton::clicked,
		[this]
		{
			LSettingsMenu* settings_menu = new LSettingsMenu;

			connect(settings_menu->themes_widget()->new_theme_button(),
				&LButton::clicked,
				this, &LMainWindow::new_theme_clicked);

			open_central_widget(settings_menu,
				LGraphic(":/images/settings_animated.svg", QSize(24, 24)));
		});

	connect(m_titlebar->minimize_button(), &LButton::clicked,
		[this]
		{
			showMinimized();
		});

	connect(m_titlebar->maximize_button(), &LButton::clicked,
		[this]
		{
			if (isMaximized())
				showNormal();
			else
				showMaximized();

			update();
		});

	connect(m_titlebar->exit_button(), &LButton::clicked,
		[this] { qApp->quit(); });
}

void LMainWindow::_open_central_widget(QWidget* central_widget)
{
	if (LThemeable* central_themeable =
		dynamic_cast<LThemeable*>(central_widget))
	{
		if (current_theme_item())
			central_themeable->apply_theme_item(
				current_theme_item()->find_item(central_widget->objectName()));
	}

	m_central_widgets.append(central_widget);
	m_main_layout->addWidget(central_widget);

	set_active_central_widget(central_widget);
}

void LMainWindow::set_active_central_widget(QWidget* central_widget)
{
	if (m_central_widgets.contains(central_widget))
		m_titlebar->menu_tab_bar()->set_current_index(
			m_central_widgets.indexOf(central_widget));
}
