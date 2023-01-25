#include "../../include/AttributeWidgets.h"
#include "../../include/CustomizePanel.h"
#include "../../include/Layouts.h"
#include "../../include/calculate.h"
#include "../../include/Theme.h"
#include "../../include/Widget.h"

#include <QEvent>
#include <QIntValidator>
#include <QPainterPath>

using Layers::Widget;

Widget::Widget(QWidget* parent) : QWidget(parent)
{
	init_attributes();

    installEventFilter(this);
    setFocusPolicy(Qt::ClickFocus);

    connect(&border.thickness, &AttributeType::value_changed, [this] {
        if (layout())
        {
            if (VerticalLayout* vl = dynamic_cast<VerticalLayout*>(layout()))
                vl->set_border_margin(border.thickness.as<double>());
            else if (HorizontalLayout* hl = dynamic_cast<HorizontalLayout*>(layout()))
                hl->set_border_margin(border.thickness.as<double>());
        }
        });
}

void Widget::init_attributes()
{
    ThemeableBox::init_attributes();

    for (AttributeType* attr_type : m_attributes)
        attr_type->setup_widget_update_connection(this);
}

bool Widget::eventFilter(QObject* object, QEvent* event)
{
    if (event->type() == QEvent::Enter)
    {
        m_hovering = true;
        update();
    }
    else if (event->type() == QEvent::Leave)
    {
        m_hovering = false;
        update();
    }

    return false;
}

void Widget::paintEvent(QPaintEvent* event)
{
    paint(this);
}
