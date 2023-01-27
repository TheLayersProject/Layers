#include "../../../include/GradientSelectionDialog.h"

#include <QApplication>
#include <QMouseEvent>

using Layers::GradientSelectionDialog;

GradientSelectionDialog::GradientSelectionDialog(QGradientStops gradient_stops, QWidget* parent) :
    Dialog("Gradient", parent)
{
    init_attributes();
	init_child_themeable_reference_list();

	setFixedSize(525, 325);
    installEventFilter(this);

    set_name("gradient_selection_dialog");
    
    m_gradient_stops = gradient_stops;

    init_gradient_widget();

    m_apply_button->set_name("apply_button");
    m_apply_button->set_proper_name("Apply Button");
    //m_apply_button->set_padding(8, 6, 8, 6);
    m_apply_button->set_text_padding(1, 3, 0, 0);
    m_apply_button->disable_text_hover_color();
    connect(m_apply_button, &Button::clicked, [this] { done(QDialog::Accepted); });

    setup_layout();

    init_color_controls();

    m_single_click_timer.setSingleShot(true);

    connect(&m_single_click_timer, &QTimer::timeout, this, &GradientSelectionDialog::click_control);
}

void GradientSelectionDialog::add_gradient_stop(double stop_val, QColor color)
{
    ColorControl* color_control = new ColorControl(this);
    color_control->show();
    color_control->a_fill.set_value(color);

    color_control->disable_clicking();

    connect(color_control, &ColorControl::color_changed, [this, color_control] {
        if (color_control->a_fill.as<QColor>() != m_gradient_stops.at(color_controls.indexOf(color_control)).second)
        {
            m_gradient_stops.replace(
                color_controls.indexOf(color_control),
                QGradientStop(m_gradient_stops.at(color_controls.indexOf(color_control)).first, color_control->a_fill.as<QColor>()));

            m_gradient_widget->a_fill.set_value(QVariant::fromValue(m_gradient_stops));
        }
        });

    int higher_index = 0;

    for (int i = 0; i < m_gradient_stops.count(); i++)
    {
        if (m_gradient_stops.at(i).first > stop_val)
        {
            higher_index = i;
            break;
        }
    }
    color_controls.insert(higher_index, color_control);

    QPoint gradient_widget_pos = m_gradient_widget->pos();

    color_control->move(gradient_widget_pos.x() - (color_control->width() / 2) + m_gradient_widget->width() * stop_val,
        gradient_widget_pos.y() - (color_control->height() / 2) + (m_gradient_widget->height() / 2));

    update_gradient();
}

QGradientStops GradientSelectionDialog::gradient_stops() const
{
    return m_gradient_stops;
}

void GradientSelectionDialog::init_attributes()
{
    for (Entity* entity :
        QList<Entity*>({
            &border, &border.thickness, &margins,
            &margins.left, &margins.top, &margins.right, &margins.bottom }))
    {
        connect(entity, &Entity::value_changed,
            this, &GradientSelectionDialog::update_color_control_positions);
    }

    m_gradient_widget->a_fill.set_value(QVariant::fromValue(QGradientStops({ { 0.0, Qt::white },{ 1.0, Qt::black } })), false);
    m_gradient_widget->border.fill.set_value(QColor(Qt::black));
    m_gradient_widget->border.thickness.set_value(2.0);
    m_gradient_widget->corner_radii.top_left.set_value(8.0);
    m_gradient_widget->corner_radii.top_right.set_value(8.0);
    m_gradient_widget->corner_radii.bottom_left.set_value(8.0);
    m_gradient_widget->corner_radii.bottom_right.set_value(8.0);
}

void GradientSelectionDialog::init_color_controls()
{
    for (int i = 0; i < m_gradient_stops.count(); i++)
    {
        QGradientStop gradient_stop = m_gradient_stops.at(i);

        ColorControl* color_control = new ColorControl(this);
        color_control->a_fill.set_value(gradient_stop.second);
        if (i > 0 && i < m_gradient_stops.count() - 1) color_control->disable_clicking();

        connect(color_control, &ColorControl::color_changed, [this, color_control] {
            if (color_control->a_fill.as<QColor>() != m_gradient_stops.at(color_controls.indexOf(color_control)).second)
            {
                m_gradient_stops.replace(
                    color_controls.indexOf(color_control),
                    QGradientStop(m_gradient_stops.at(color_controls.indexOf(color_control)).first, color_control->a_fill.as<QColor>()));

                m_gradient_widget->a_fill.set_value(QVariant::fromValue(m_gradient_stops));
            }
            });

        color_controls.append(color_control);

        QPoint gradient_widget_pos = m_gradient_widget->pos();

        color_control->move(gradient_widget_pos.x() - (color_control->width() / 2) + m_gradient_widget->width() * gradient_stop.first,
            gradient_widget_pos.y() - (color_control->height() / 2) + (m_gradient_widget->height() / 2));
    }
}

void GradientSelectionDialog::init_gradient_widget()
{
    m_gradient_widget->setFixedSize(448, 176);

    m_gradient_widget->a_fill.set_value(QVariant::fromValue(m_gradient_stops));
}

void GradientSelectionDialog::init_child_themeable_reference_list()
{
    store_child_themeable_pointer(m_apply_button);
}

void GradientSelectionDialog::update_gradient()
{
    m_gradient_stops = QGradientStops();

    int range = color_controls.last()->x() - color_controls.first()->x();

    for (ColorControl* color_control : color_controls)
    {
        if (m_selected_color_control && m_selected_color_control->x() == color_control->x() && color_control != m_selected_color_control);
        else m_gradient_stops.append(QGradientStop{ double(color_control->x() - color_controls.first()->x()) / double(range), color_control->a_fill.as<QColor>() });
    }

    m_gradient_widget->a_fill.set_value(QVariant::fromValue(m_gradient_stops)); // , true);
}

void GradientSelectionDialog::click_control()
{
    m_clicking_color_control->click();

    m_clicking_color_control = nullptr;
}

void GradientSelectionDialog::update_color_control_positions()
{
    if (!isVisible())
        m_main_layout->activate();

    QPoint gradient_widget_pos = m_gradient_widget->pos();

    for (int i = 0; i < m_gradient_stops.count(); i++)
    {
        QGradientStop gradient_stop = m_gradient_stops.at(i);
        ColorControl* color_control = color_controls.at(i);

        color_control->move(gradient_widget_pos.x() - (color_control->width() / 2) + m_gradient_widget->width() * gradient_stop.first,
            gradient_widget_pos.y() - (color_control->height() / 2) + (m_gradient_widget->height() / 2));
    }
}

bool GradientSelectionDialog::eventFilter(QObject* object, QEvent* event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

        if (mouse_event->button() & Qt::LeftButton)
        {
            for (int i = 1; i < color_controls.count() - 1; i++)
            {
                if (color_controls.at(i)->pos().x() <= mouse_event->pos().x() &&
                    mouse_event->pos().x() < color_controls.at(i)->pos().x() + color_controls.at(i)->width() &&
                    m_gradient_widget->geometry().contains(mouse_event->pos()))
                {
                    m_selected_color_control = color_controls.at(i);
                    m_selected_color_control->raise();

                    m_selection_start_point = mouse_event->pos();

                    m_selected_control_start_x = m_selected_color_control->x();
                }
            }
        }
    }
    else if (event->type() == QEvent::MouseButtonRelease && m_selected_color_control)
    {
        QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

        if (mouse_event->button() & Qt::LeftButton)
        {
            for (ColorControl* color_control : color_controls)
            {
                if (m_selected_color_control->x() == color_control->x() && color_control != m_selected_color_control)
                {
                    if (color_controls.indexOf(color_control) == 0 || color_controls.indexOf(color_control) == color_controls.count() - 1)
                    {
                        m_selected_color_control->disable_clicking(false);
                    }

                    color_controls.swapItemsAt(color_controls.indexOf(color_control), color_controls.indexOf(m_selected_color_control));
                    color_controls.removeOne(color_control);
                    color_control->deleteLater();
                    break;
                }
            }

            if (!m_single_click_timer.isActive() && !m_moved)
            {
                m_single_click_timer.start(QApplication::doubleClickInterval() / 2);
                m_clicking_color_control = m_selected_color_control;
            }

            m_selected_color_control = nullptr;

            m_moved = false;
        }
    }
    else if (event->type() == QEvent::MouseMove && m_selected_color_control)
    {
        QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

        QPoint delta = mouse_event->pos() - m_selection_start_point;

        int lower_range = m_gradient_widget->pos().x() - (m_selected_color_control->width() / 2);
        int higher_range = m_gradient_widget->pos().x() - (color_controls.first()->width() / 2) + m_gradient_widget->width();

        if (m_selected_control_start_x + delta.x() < lower_range)
        {
            if (m_selected_color_control->x() != lower_range) m_selected_color_control->move(lower_range, m_selected_color_control->y());
        }
        else if (m_selected_control_start_x + delta.x() > higher_range)
        {
            if (m_selected_color_control->x() != higher_range) m_selected_color_control->move(higher_range, m_selected_color_control->y());
        }
        else
        {
            m_selected_color_control->move(m_selected_control_start_x + delta.x(), m_selected_color_control->y());
        }

        m_moved = true;

        update_gradient();
    }
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

        if (mouse_event->button() & Qt::LeftButton)
        {
            if (m_single_click_timer.isActive())
            {
                m_single_click_timer.stop();

                for (int i = 1; i < color_controls.count() - 1; i++)
                {
                    if (color_controls.at(i)->pos().x() <= mouse_event->pos().x() &&
                        mouse_event->pos().x() < color_controls.at(i)->pos().x() + color_controls.at(i)->width() &&
                        m_gradient_widget->geometry().contains(mouse_event->pos()))
                    {
                        color_controls.at(i)->deleteLater();
                        color_controls.removeAt(i);

                        update_gradient();

                        break;
                    }
                }
            }
            else
            {
                bool clicked_on_control = false;

                for (int i = 0; i < color_controls.count(); i++)
                {
                    if (color_controls.at(i)->pos().x() <= mouse_event->pos().x() &&
                        mouse_event->pos().x() < color_controls.at(i)->pos().x() + color_controls.at(i)->width() &&
                        m_gradient_widget->geometry().contains(mouse_event->pos()))
                    {
                        clicked_on_control = true;
                    }
                }

                if (!clicked_on_control && m_gradient_widget->geometry().contains(mouse_event->pos()))
                {
                    add_gradient_stop(double(mouse_event->pos().x() - m_gradient_widget->pos().x()) / double(m_gradient_widget->pos().x() + m_gradient_widget->width() - m_gradient_widget->pos().x()),
                        m_gradient_widget->grab().toImage().pixelColor(mouse_event->pos().x() - m_gradient_widget->pos().x(), m_gradient_widget->height() / 2));
                }
            }
        }
    }

    return false;
}

void GradientSelectionDialog::setup_layout()
{
    QVBoxLayout* layout = new QVBoxLayout;

    layout->setContentsMargins(15, 22, 15, 0);
    layout->setSpacing(12);
    layout->addWidget(m_gradient_widget);
    layout->addWidget(m_apply_button);
    layout->addStretch();
    layout->setAlignment(m_gradient_widget, Qt::AlignHCenter);
    layout->setAlignment(m_apply_button, Qt::AlignRight);

    setLayout(layout);

    // Activate layout since position information is required during initialization
    layout->activate();
}
