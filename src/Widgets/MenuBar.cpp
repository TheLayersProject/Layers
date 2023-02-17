#include "../../include/MenuBar.h"

#include <QStyleOptionMenuItem>

using Layers::Attribute;
using Layers::MenuBar;

MenuBar::MenuBar(QWidget* parent) : QMenuBar(parent)
{
	init_attributes();

	QFont MainMenuFont = font();
	MainMenuFont.setPointSize(12);

	setFont(MainMenuFont);
	//setMouseTracking(true);

    //QPalette pal = palette();

    //pal.setColor(QPalette::Base, QColor(Qt::blue));
    //pal.setColor(QPalette::AlternateBase, QColor(Qt::blue));
    //pal.setColor(QPalette::Window, QColor(Qt::blue));
    //pal.setColor(QPalette::Button, QColor(Qt::blue));

    //pal.setBrush(QPalette::Base, QBrush(Qt::blue));
    //pal.setBrush(QPalette::AlternateBase, QBrush(Qt::blue));
    //pal.setBrush(QPalette::Window, QBrush(Qt::blue));
    //pal.setBrush(QPalette::Button, QBrush(Qt::blue));


    //pal.setColor(QPalette::WindowText, QColor(Qt::red));
    //pal.setColor(QPalette::Text, QColor(Qt::red));
    //pal.setColor(QPalette::ButtonText, QColor(Qt::red));

    //pal.setBrush(QPalette::WindowText, QBrush(Qt::red));
    //pal.setBrush(QPalette::Text, QBrush(Qt::red));
    //pal.setBrush(QPalette::ButtonText, QBrush(Qt::red));

    //setPalette(pal);

    update_theme_dependencies();
}

QMenu* MenuBar::addMenu(const QString& title)
{
    m_menus.append(QMenuBar::addMenu(title));

    return m_menus.last();
}

void MenuBar::init_attributes()
{
    m_entities.insert({
        { "text_color", m_text_color },
        { "selected_text_color", m_selected_text_color }
        });

    connect(m_text_color, &Entity::value_changed, [this] { update_theme_dependencies(); });
    connect(m_selected_text_color, &Entity::value_changed, [this] { update_theme_dependencies(); });
}

void MenuBar::update_theme_dependencies()
{
	setStyleSheet(build_stylesheet());

    //update();
}

Attribute* MenuBar::selected_text_color() const
{
    return m_selected_text_color;
}

Attribute* MenuBar::text_color() const
{
    return m_text_color;
}

QString MenuBar::build_stylesheet()
{
	return
		"QMenuBar {"
		"background: transparent;"
		"color: " + m_text_color->as<QColor>().name() + ";"
		"}"

		"QMenuBar::item {"
		"spacing: 3px;"
		"padding: 1px 4px;"
		"background: transparent;"
		"color: " + m_text_color->as<QColor>().name() + ";"
		"}"

		"QMenuBar::item:selected {"
		"background: transparent;"
		"color: " + m_selected_text_color->as<QColor>().name() + ";"
		"}"

		"QMenuBar::item:pressed {"
		"background: transparent;"
		"}";
}

//void MenuBar::paintEvent(QPaintEvent* event)
//{
//    //QMenuBar::paintEvent(event);
//
//    ////////qDebug() << "Start painting MenuBar";
//
//    ////////qDebug() << "Menus:";
//    ////////for (QMenu* menu : m_menus)
//    ////////{
//    ////////    qDebug() << menu->title();
//    ////////}
//
//    ////////QPainter p(this);
//    ////////QRegion emptyArea(rect());
//
//    ////////for (int i = 0; i < actions().count(); ++i)
//    ////////{
//    ////////    QAction* action = actions().at(i);
//    ////////    QRect adjustedActionRect = actionGeometry(action);
//    ////////    //if (adjustedActionRect.isEmpty() || !d->isVisible(action))
//    ////////    //    continue;
//    ////////    //if (!event->rect().intersects(adjustedActionRect))
//    ////////    //    continue;
//
//    ////////    emptyArea -= adjustedActionRect;
//
//    ////////    QStyleOptionMenuItem opt;
//    ////////    initStyleOption(&opt, action);
//    ////////    opt.rect = adjustedActionRect;
//
//    ////////    qDebug() << opt.palette;
//
//    ////////    p.setClipRect(adjustedActionRect);
//
//    ////////    style()->drawControl(QStyle::CE_MenuBarItem, &opt, &p, this);
//    ////////}
//
//    ////////qDebug() << "End painting MenuBar";
//
//    ////Q_D(QMenuBar);
//    //QPainter p(this);
//    //QRegion emptyArea(rect());
//
//    ////draw the items
//    //for (int i = 0; i < d->actions.count(); ++i) {
//    //    QAction* action = d->actions.at(i);
//    //    QRect adjustedActionRect = d->actionRect(action);
//    //    if (adjustedActionRect.isEmpty() || !d->isVisible(action))
//    //        continue;
//    //    if (!event->rect().intersects(adjustedActionRect))
//    //        continue;
//
//    //    emptyArea -= adjustedActionRect;
//    //    QStyleOptionMenuItem opt;
//    //    initStyleOption(&opt, action);
//    //    opt.rect = adjustedActionRect;
//    //    p.setClipRect(adjustedActionRect);
//    //    style()->drawControl(QStyle::CE_MenuBarItem, &opt, &p, this);
//    //}
//    ////draw border
//    //if (int fw = style()->pixelMetric(QStyle::PM_MenuBarPanelWidth, nullptr, this)) {
//    //    QRegion borderReg;
//    //    borderReg += QRect(0, 0, fw, height()); //left
//    //    borderReg += QRect(width() - fw, 0, fw, height()); //right
//    //    borderReg += QRect(0, 0, width(), fw); //top
//    //    borderReg += QRect(0, height() - fw, width(), fw); //bottom
//    //    p.setClipRegion(borderReg);
//    //    emptyArea -= borderReg;
//    //    QStyleOptionFrame frame;
//    //    frame.rect = rect();
//    //    frame.palette = palette();
//    //    frame.state = QStyle::State_None;
//    //    frame.lineWidth = style()->pixelMetric(QStyle::PM_MenuBarPanelWidth, &frame);
//    //    frame.midLineWidth = 0;
//    //    style()->drawPrimitive(QStyle::PE_PanelMenuBar, &frame, &p, this);
//    //}
//    //p.setClipRegion(emptyArea);
//    //QStyleOptionMenuItem menuOpt;
//    //menuOpt.palette = palette();
//    //menuOpt.state = QStyle::State_None;
//    //menuOpt.menuItemType = QStyleOptionMenuItem::EmptyArea;
//    //menuOpt.checkType = QStyleOptionMenuItem::NotCheckable;
//    //menuOpt.rect = rect();
//    //menuOpt.menuRect = rect();
//    //style()->drawControl(QStyle::CE_MenuBarEmptyArea, &menuOpt, &p, this);
//}
