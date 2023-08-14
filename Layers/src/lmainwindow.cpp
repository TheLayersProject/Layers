#include <Layers/lmainwindow.h>

#include <Windows.h>
#include <windowsx.h>

#include <QIcon>
#include <QPainterPath>

#include <Layers/lapplication.h>
#include <Layers/lcalculate.h>
#include <Layers/lthemecreatordialog.h>
#include <Layers/lthemeeditordialog.h>

#include "lmainwindowtitlebar.h"
#include "lsettingsmenu.h"
#include "lthemeswidget.h"

using Layers::LSettingsMenu;
using Layers::LThemeable;
using Layers::LMainWindowTitlebar;
using Layers::LMainWindow;

LMainWindow::LMainWindow(QWidget* parent) :
	m_settings_menu{ new LSettingsMenu },
	m_titlebar{ new LMainWindowTitlebar },
	LWidget(parent)
{
	init_attributes();
	init_layout();
	init_themes_widget_connections();
	init_titlebar_connections();
	resize(1200, 800);
	set_name("Main Window");
	setAttribute(Qt::WA_TranslucentBackground);
	setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
	
	m_settings_menu->hide();

	connect(m_titlebar->menu_tab_bar(), SIGNAL(index_changed(int, int)),
		this, SLOT(open_widget_changed(int, int)));

	connect(m_titlebar->menu_tab_bar(), SIGNAL(tab_closed(int)),
		this, SLOT(close_widget(int)));

	m_separator->set_icon(LGraphic(":/images/separator_h_icon.svg"));
	m_separator->set_name("Separator");
	m_separator->setFixedHeight(3);

	m_theme_editor_dialog->apply_theme(
		activeTheme()->find_item("App/Theme Editor Dialog"));
}

void LMainWindow::set_central_widget(LWidget* central_widget)
{
	m_central_widget = central_widget;

	m_main_layout->addWidget(m_central_widget);

	if (m_central_widget->icon())
	{
		set_icon(LGraphic(*m_central_widget->icon()));

		open_widget(m_central_widget, *m_central_widget->name(),
			m_central_widget->icon());
	}
	else
		open_widget(m_central_widget, *m_central_widget->name());

	LTab* app_menu_tab = m_titlebar->menu_tab_bar()->tabs().last();
	app_menu_tab->close_button()->hide();
	app_menu_tab->layout()->setContentsMargins(2, 0, 12, 0);
}

void LMainWindow::center_dialog(QDialog* dialog)
{
	dialog->move(
		x() + (width() - dialog->width()) / 2,
		y() + (height() - dialog->height()) / 2);
}

void LMainWindow::close_widget(int index)
{
	m_opened_widgets.removeAt(index);
}

void LMainWindow::open_widget(
	LWidget* widget, const QString& name, LGraphic* icon)
{
	LTabBar* tab_bar = m_titlebar->menu_tab_bar();

	if (!m_opened_widgets.contains(widget))
	{
		m_opened_widgets.append(widget);

		if (icon)
			tab_bar->add_tab(*icon, name);
		else
			tab_bar->add_tab(name);
	}

	tab_bar->set_current_index(m_opened_widgets.indexOf(widget));
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

	center_dialog(&dialog);

	dialog.exec();
}

void LMainWindow::open_widget_changed(int old_index, int new_index)
{
	if (QWidget* old_widget = (old_index != -1) ?
		m_opened_widgets[old_index] : nullptr)
	{
		old_widget->hide();
	}

	m_opened_widgets[new_index]->show();
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
	m_main_layout->addWidget(m_settings_menu);

	setLayout(m_main_layout);
}

void LMainWindow::init_themes_widget_connections()
{
	LThemesWidget* themes_widget = m_settings_menu->themes_widget();

	connect(themes_widget->customize_theme_button(), &LButton::clicked, [this]
	{
		m_theme_editor_dialog->show();
		m_theme_editor_dialog->raise();
	});

	connect(themes_widget->new_theme_button(), &LButton::clicked,
		this, &LMainWindow::new_theme_clicked);
}

void LMainWindow::init_titlebar_connections()
{
	connect(m_titlebar->settings_button(), &LButton::clicked, [this]
	{
		open_widget(m_settings_menu,
		*m_settings_menu->name(), m_settings_menu->icon());
	});

	connect(m_titlebar->minimize_button(), &LButton::clicked, [this]
	{
		showMinimized();
	});

	connect(m_titlebar->maximize_button(), &LButton::clicked, [this]
	{
		if (isMaximized())
			showNormal();
		else
			showMaximized();

		update();
	});

	connect(m_titlebar->exit_button(), &LButton::clicked, [this]
		{ qApp->quit(); });
}
