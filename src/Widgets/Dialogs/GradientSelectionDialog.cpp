#include "../../../include/GradientSelectionDialog.h"
#include "../../../include/Graphic.h"
#include "../../../include/calculate.h"

#include <Windows.h>
#include <windowsx.h>

#include <QApplication>
#include <QMouseEvent>
#include <QPainterPath>

using Layers::GradientSelectionDialog;

GradientSelectionDialog::GradientSelectionDialog(QGradientStops gradient_stops, QWidget* parent) : QDialog(parent)
{
	init_child_themeable_reference_list();
	init_attributes();

	setFixedSize(525, 325);
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
    installEventFilter(this);

    set_name("gradient_selection_dialog");
    
    m_gradient_stops = gradient_stops;

    init_titlebar();
    init_gradient_widget();

    m_apply_button->set_name("apply_button");
    //m_apply_button->set_padding(8, 6, 8, 6);
    m_apply_button->set_text_padding(1, 3, 0, 0);
    m_apply_button->disable_text_hover_color();
    connect(m_apply_button, &Button::clicked, [this] { done(QDialog::Accepted); });

    assign_tag_prefixes();

    setup_layout();

    init_color_controls();

    m_single_click_timer.setSingleShot(true);

    connect(&m_single_click_timer, &QTimer::timeout, this, &GradientSelectionDialog::click_control);

    connect(&a_border_thickness, &Attribute::value_changed, [this] {
        int margin = a_border_thickness.value<int>();

        m_main_layout->setContentsMargins(margin, margin, margin, margin);

        //a_corner_radius_tl.set_value(inner_radius(a_corner_radius_tl.value<int>(), a_border_thickness.value<int>()));
        //a_corner_radius_tr.set_value(inner_radius(a_corner_radius_tr.value<int>(), a_border_thickness.value<int>()));

        m_titlebar->a_corner_radius_tl.set_value(inner_radius(a_corner_radius_tl.value<int>(), a_border_thickness.value<int>()));
        m_titlebar->a_corner_radius_tr.set_value(inner_radius(a_corner_radius_tr.value<int>(), a_border_thickness.value<int>()));
        });
}

void GradientSelectionDialog::add_gradient_stop(double stop_val, QColor color)
{
    ColorControl* color_control = new ColorControl(this);
    color_control->show();
    color_control->a_fill.set_value(color);

    color_control->disable_clicking();

    connect(color_control, &ColorControl::color_changed, [this, color_control] {
        if (color_control->a_fill.value<QColor>() != m_gradient_stops.at(color_controls.indexOf(color_control)).second)
        {
            m_gradient_stops.replace(
                color_controls.indexOf(color_control),
                QGradientStop(m_gradient_stops.at(color_controls.indexOf(color_control)).first, color_control->a_fill.value<QColor>()));

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

void GradientSelectionDialog::apply_theme_attributes(QMap<QString, Attribute*>& theme_attrs)
{
    a_border_fill.copy_values_from(*theme_attrs["border_fill"]);
    a_border_thickness.copy_values_from(*theme_attrs["border_thickness"]);
    a_corner_color.copy_values_from(*theme_attrs["corner_color"]);
    a_corner_radius_tl.copy_values_from(*theme_attrs["corner_radius_tl"]);
    a_corner_radius_tr.copy_values_from(*theme_attrs["corner_radius_tr"]);
    a_corner_radius_bl.copy_values_from(*theme_attrs["corner_radius_bl"]);
    a_corner_radius_br.copy_values_from(*theme_attrs["corner_radius_br"]);
    a_fill.copy_values_from(*theme_attrs["fill"]);
    a_hover_fill.copy_values_from(*theme_attrs["hover_fill"]);
    a_margin_left.copy_values_from(*theme_attrs["margin_left"]);
    a_margin_top.copy_values_from(*theme_attrs["margin_top"]);
    a_margin_right.copy_values_from(*theme_attrs["margin_right"]);
    a_margin_bottom.copy_values_from(*theme_attrs["margin_bottom"]);
    a_outline_color.copy_values_from(*theme_attrs["outline_color"]);
}

QGradientStops GradientSelectionDialog::gradient_stops() const
{
    return m_gradient_stops;
}

void GradientSelectionDialog::init_attributes()
{
    m_attributes.insert({
        { "border_fill", &a_border_fill },
        { "border_thickness", &a_border_thickness },
        { "corner_color", &a_corner_color },
        { "corner_radius_tl", &a_corner_radius_tl },
        { "corner_radius_tr", &a_corner_radius_tr },
        { "corner_radius_bl", &a_corner_radius_bl },
        { "corner_radius_br", &a_corner_radius_br },
        { "fill", &a_fill },
        { "hover_fill", &a_hover_fill },
        { "margin_left", &a_margin_left },
        { "margin_top", &a_margin_top },
        { "margin_right", &a_margin_right },
        { "margin_bottom", &a_margin_bottom },
        { "outline_color", &a_outline_color },
        });

    m_titlebar->a_corner_radius_tl.set_value(inner_radius(a_corner_radius_tl.value<int>(), a_border_thickness.value<int>()));
    m_titlebar->a_corner_radius_tr.set_value(inner_radius(a_corner_radius_tr.value<int>(), a_border_thickness.value<int>()));

    //m_gradient_widget->a_fill.set_disabled(false);
    m_gradient_widget->a_border_fill.set_value(QColor(Qt::black));
    m_gradient_widget->a_border_thickness.set_value(2);
    m_gradient_widget->a_corner_radius_tl.set_value(8);
    m_gradient_widget->a_corner_radius_tr.set_value(8);
    m_gradient_widget->a_corner_radius_bl.set_value(8);
    m_gradient_widget->a_corner_radius_br.set_value(8);
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
            if (color_control->a_fill.value<QColor>() != m_gradient_stops.at(color_controls.indexOf(color_control)).second)
            {
                m_gradient_stops.replace(
                    color_controls.indexOf(color_control),
                    QGradientStop(m_gradient_stops.at(color_controls.indexOf(color_control)).first, color_control->a_fill.value<QColor>()));

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
    add_child_themeable_reference(m_titlebar);
    add_child_themeable_reference(m_apply_button);
}

void GradientSelectionDialog::init_titlebar()
{
    m_titlebar->setFixedHeight(45);
    m_titlebar->set_name("titlebar");

    Label* window_title_label = new Label("Gradient Selection Box");
    window_title_label->setAttribute(Qt::WA_TransparentForMouseEvents);
    window_title_label->set_name("window_title_label");
    window_title_label->set_padding(7, 8, 0, 0);
    window_title_label->set_font_size(14);

    Button* exit_button = new Button(new Graphic(":/svgs/exit.svg", QSize(20, 20)), true);
    connect(exit_button, &Button::clicked, [this] { done(QDialog::Rejected); });
    exit_button->set_name("exit_button");

    // Add Titlebar's Themeable Child Element References
    m_titlebar->add_child_themeable_reference(window_title_label);
    m_titlebar->add_child_themeable_reference(exit_button);

    // Setup Layout
    QHBoxLayout* titlebar_layout = new QHBoxLayout;

    titlebar_layout->setContentsMargins(10, 0, 10, 0);
    titlebar_layout->setSpacing(0);
    titlebar_layout->addWidget(window_title_label);
    titlebar_layout->addStretch();
    titlebar_layout->addWidget(exit_button);

    m_titlebar->setLayout(titlebar_layout);
}

void GradientSelectionDialog::replace_all_attributes_with(GradientSelectionDialog* dialog)
{
    a_border_fill.get_values_from(dialog->a_border_fill);
    a_border_thickness.get_values_from(dialog->a_border_thickness);
    a_corner_color.get_values_from(dialog->a_corner_color);
    a_corner_radius_tl.get_values_from(dialog->a_corner_radius_tl);
    a_corner_radius_tr.get_values_from(dialog->a_corner_radius_tr);
    a_corner_radius_bl.get_values_from(dialog->a_corner_radius_bl);
    a_corner_radius_br.get_values_from(dialog->a_corner_radius_br);
    a_fill.get_values_from(dialog->a_fill);
    a_hover_fill.get_values_from(dialog->a_hover_fill);
    a_margin_left.get_values_from(dialog->a_margin_left);
    a_margin_top.get_values_from(dialog->a_margin_top);
    a_margin_right.get_values_from(dialog->a_margin_right);
    a_margin_bottom.get_values_from(dialog->a_margin_bottom);
    a_outline_color.get_values_from(dialog->a_outline_color);
}

void GradientSelectionDialog::update_gradient()
{
    m_gradient_stops = QGradientStops();

    int range = color_controls.last()->x() - color_controls.first()->x();

    for (ColorControl* color_control : color_controls)
    {
        if (m_selected_color_control && m_selected_color_control->x() == color_control->x() && color_control != m_selected_color_control);
        else m_gradient_stops.append(QGradientStop{ double(color_control->x() - color_controls.first()->x()) / double(range), color_control->a_fill.value<QColor>() });
    }

    m_gradient_widget->a_fill.set_value(QVariant::fromValue(m_gradient_stops)); // , true);
}

void GradientSelectionDialog::click_control()
{
    m_clicking_color_control->click();

    m_clicking_color_control = nullptr;
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

bool GradientSelectionDialog::nativeEvent(const QByteArray& eventType, void* message, qintptr* result)
{
    MSG* msg = static_cast<MSG*>(message);

    if (msg->message == WM_NCHITTEST)
    {
        if (isMaximized())
        {
            return false;
        }

        *result = 0;
        const LONG borderWidth = a_border_thickness.value<int>() * devicePixelRatio();;
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

//void GradientSelectionDialog::paintEvent(QPaintEvent* event)
//{
//	// CREATE VARIABLES:
//
//	bool background_disabled = m_attribute_set.attribute_value("background_disabled")->value<bool>();
//
//	int border_thickness = m_attribute_set.attribute_value("border_thickness")->value<int>();
//
//	int margin_left = m_attribute_set.attribute_value("margin_left")->value<int>();
//	int margin_top = m_attribute_set.attribute_value("margin_top")->value<int>();
//	int margin_right = m_attribute_set.attribute_value("margin_right")->value<int>();
//	int margin_bottom = m_attribute_set.attribute_value("margin_bottom")->value<int>();
//
//	int draw_width = width() - margin_left - margin_right;
//	int draw_height = height() - margin_top - margin_bottom;
//
//	int corner_radius_tl = m_attribute_set.attribute_value("corner_radius_tl")->value<int>();
//	int corner_radius_tr = m_attribute_set.attribute_value("corner_radius_tr")->value<int>();
//	int corner_radius_bl = m_attribute_set.attribute_value("corner_radius_bl")->value<int>();
//	int corner_radius_br = m_attribute_set.attribute_value("corner_radius_br")->value<int>();
//
//	int tl_background_radius = border_thickness ? inner_radius(corner_radius_tl, border_thickness) : corner_radius_tl;
//	int tr_background_radius = border_thickness ? inner_radius(corner_radius_tr, border_thickness) : corner_radius_tr;
//	int bl_background_radius = border_thickness ? inner_radius(corner_radius_bl, border_thickness) : corner_radius_bl;
//	int br_background_radius = border_thickness ? inner_radius(corner_radius_br, border_thickness) : corner_radius_br;
//
//	// CREATE PATHS:
//
//	// - Create Border Path
//	QPainterPath border_path;
//	border_path.moveTo(margin_left, margin_top + corner_radius_tl);
//	border_path.arcTo(QRect(margin_left, margin_top, corner_radius_tl * 2, corner_radius_tl * 2), 180, -90);
//	border_path.lineTo(margin_left + draw_width - corner_radius_tr, margin_top);
//	border_path.arcTo(QRect(margin_left + draw_width - corner_radius_tr * 2, margin_top, corner_radius_tr * 2, corner_radius_tr * 2), 90, -90);
//	border_path.lineTo(margin_left + draw_width, margin_top + draw_height - corner_radius_br);
//	border_path.arcTo(QRect(margin_left + draw_width - corner_radius_br * 2, margin_top + draw_height - corner_radius_br * 2, corner_radius_br * 2, corner_radius_br * 2), 0, -90);
//	border_path.lineTo(margin_left + corner_radius_bl, margin_top + draw_height);
//	border_path.arcTo(QRect(margin_left, margin_top + draw_height - corner_radius_bl * 2, corner_radius_bl * 2, corner_radius_bl * 2), -90, -90);
//	border_path.lineTo(margin_left, margin_top + corner_radius_tl);
//
//	// - Create Background Path
//	QPainterPath background_path;
//	background_path.moveTo(margin_left + border_thickness, margin_top + border_thickness + tl_background_radius);
//	background_path.arcTo(QRect(margin_left + border_thickness, margin_top + border_thickness, tl_background_radius * 2, tl_background_radius * 2), 180, -90);
//	background_path.lineTo(margin_left + draw_width - tr_background_radius - border_thickness, margin_top + border_thickness);
//	background_path.arcTo(QRect(margin_left + draw_width - tr_background_radius * 2 - border_thickness, margin_top + border_thickness, tr_background_radius * 2, tr_background_radius * 2), 90, -90);
//	background_path.lineTo(margin_left + draw_width - border_thickness, margin_top + draw_height - br_background_radius - border_thickness);
//	background_path.arcTo(QRect(margin_left + draw_width - br_background_radius * 2 - border_thickness, margin_top + draw_height - br_background_radius * 2 - border_thickness, br_background_radius * 2, br_background_radius * 2), 0, -90);
//	background_path.lineTo(margin_left + border_thickness + bl_background_radius, margin_top + draw_height - border_thickness);
//	background_path.arcTo(QRect(margin_left + border_thickness, margin_top + draw_height - bl_background_radius * 2 - border_thickness, bl_background_radius * 2, bl_background_radius * 2), -90, -90);
//	background_path.lineTo(margin_left + border_thickness, margin_top + border_thickness + tl_background_radius);
//
//	border_path = border_path - background_path;
//
//	// - Create Corner Path
//	QPainterPath corner_color_path;
//	corner_color_path.addRect(0, 0, width(), height());
//	corner_color_path = corner_color_path - background_path;
//	corner_color_path = corner_color_path - border_path;
//
//	// - Create Outline Path
//	QPainterPath outline_color_path;
//	outline_color_path.addRect(0, 0, width(), height());
//	outline_color_path = outline_color_path - corner_color_path;
//
//	// DRAW:
//
//	painter.begin(this);
//	painter.setRenderHint(QPainter::Antialiasing);
//
//	// - Draw Corner Color
//	if (!m_attribute_set.attribute_value("corner_color_disabled")->value<bool>())
//	{
//		painter.fillPath(corner_color_path, m_attribute_set.attribute_value("corner_color")->value<QColor>());
//	}
//
//	// - Draw Border
//	if (border_thickness)
//	{
//		if (!m_attribute_set.attribute_value("border_gradient_disabled")->value<bool>())
//		{
//			QLinearGradient gradient;
//
//			gradient.setStart(0, 0);
//			gradient.setFinalStop(width(), 0);
//			gradient.setStops(m_attribute_set.attribute_value("border_gradient_stops")->value<QGradientStops>());
//
//			painter.fillPath(border_path, gradient);
//		}
//		else painter.fillPath(border_path, m_attribute_set.attribute_value("border_color")->value<QColor>());
//	}
//
//	// - Draw Background
//	if (!background_disabled)
//	{
//		if (m_attribute_set.attribute_value("background_gradient_disabled")->value<bool>())
//		{
//			if (!m_attribute_set.attribute_value("background_color_hover_disabled")->value<bool>() && m_attribute_set.attribute_value("using_background_color_hover")->value<bool>())
//				painter.fillPath(background_path, m_attribute_set.attribute_value("background_color_hover")->value<QColor>());
//			else
//				painter.fillPath(background_path, m_attribute_set.attribute_value("background_color")->value<QColor>());
//		}
//		else
//		{
//			QLinearGradient bg_gradient;
//
//			bg_gradient.setStart(0, 0);
//			bg_gradient.setFinalStop(width(), 0);
//			bg_gradient.setStops(m_attribute_set.attribute_value("background_gradient_stops")->value<QGradientStops>());
//
//			painter.fillPath(background_path, bg_gradient);
//		}
//	}
//
//	// - Draw Outline Color
//	if (!m_attribute_set.attribute_value("outline_color_disabled")->value<bool>())
//	{
//		painter.strokePath(outline_color_path, QPen(m_attribute_set.attribute_value("outline_color")->value<QColor>()));
//	}
//
//	painter.end();
//}

void GradientSelectionDialog::paintEvent(QPaintEvent* event)
{
    // CREATE VARIABLES:

    bool fill_disabled = a_fill.disabled();

    int border_thickness = a_border_thickness.value<int>();

    int margin_left = a_margin_left.value<int>();
    int margin_top = a_margin_top.value<int>();
    int margin_right = a_margin_right.value<int>();
    int margin_bottom = a_margin_bottom.value<int>();

    int draw_width = width() - margin_left - margin_right;
    int draw_height = height() - margin_top - margin_bottom;

    int corner_radius_tl = a_corner_radius_tl.value<int>();
    int corner_radius_tr = a_corner_radius_tr.value<int>();
    int corner_radius_bl = a_corner_radius_bl.value<int>();
    int corner_radius_br = a_corner_radius_br.value<int>();

    int tl_background_radius = border_thickness ? inner_radius(corner_radius_tl, border_thickness) : corner_radius_tl;
    int tr_background_radius = border_thickness ? inner_radius(corner_radius_tr, border_thickness) : corner_radius_tr;
    int bl_background_radius = border_thickness ? inner_radius(corner_radius_bl, border_thickness) : corner_radius_bl;
    int br_background_radius = border_thickness ? inner_radius(corner_radius_br, border_thickness) : corner_radius_br;

    // CREATE PATHS:

    // - Create Border Path
    QPainterPath border_path;
    border_path.moveTo(margin_left, margin_top + corner_radius_tl);
    border_path.arcTo(QRect(margin_left, margin_top, corner_radius_tl * 2, corner_radius_tl * 2), 180, -90);
    border_path.lineTo(margin_left + draw_width - corner_radius_tr, margin_top);
    border_path.arcTo(QRect(margin_left + draw_width - corner_radius_tr * 2, margin_top, corner_radius_tr * 2, corner_radius_tr * 2), 90, -90);
    border_path.lineTo(margin_left + draw_width, margin_top + draw_height - corner_radius_br);
    border_path.arcTo(QRect(margin_left + draw_width - corner_radius_br * 2, margin_top + draw_height - corner_radius_br * 2, corner_radius_br * 2, corner_radius_br * 2), 0, -90);
    border_path.lineTo(margin_left + corner_radius_bl, margin_top + draw_height);
    border_path.arcTo(QRect(margin_left, margin_top + draw_height - corner_radius_bl * 2, corner_radius_bl * 2, corner_radius_bl * 2), -90, -90);
    border_path.lineTo(margin_left, margin_top + corner_radius_tl);

    // - Create Background Path
    QPainterPath background_path;
    background_path.moveTo(margin_left + border_thickness, margin_top + border_thickness + tl_background_radius);
    background_path.arcTo(QRect(margin_left + border_thickness, margin_top + border_thickness, tl_background_radius * 2, tl_background_radius * 2), 180, -90);
    background_path.lineTo(margin_left + draw_width - tr_background_radius - border_thickness, margin_top + border_thickness);
    background_path.arcTo(QRect(margin_left + draw_width - tr_background_radius * 2 - border_thickness, margin_top + border_thickness, tr_background_radius * 2, tr_background_radius * 2), 90, -90);
    background_path.lineTo(margin_left + draw_width - border_thickness, margin_top + draw_height - br_background_radius - border_thickness);
    background_path.arcTo(QRect(margin_left + draw_width - br_background_radius * 2 - border_thickness, margin_top + draw_height - br_background_radius * 2 - border_thickness, br_background_radius * 2, br_background_radius * 2), 0, -90);
    background_path.lineTo(margin_left + border_thickness + bl_background_radius, margin_top + draw_height - border_thickness);
    background_path.arcTo(QRect(margin_left + border_thickness, margin_top + draw_height - bl_background_radius * 2 - border_thickness, bl_background_radius * 2, bl_background_radius * 2), -90, -90);
    background_path.lineTo(margin_left + border_thickness, margin_top + border_thickness + tl_background_radius);

    border_path = border_path - background_path;

    // - Create Corner Path
    QPainterPath corner_color_path;
    corner_color_path.addRect(0, 0, width(), height());
    corner_color_path = corner_color_path - background_path;
    corner_color_path = corner_color_path - border_path;

    // - Create Outline Path
    QPainterPath outline_color_path;
    outline_color_path.addRect(0, 0, width(), height());
    outline_color_path = outline_color_path - corner_color_path;

    // DRAW:

    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // - Draw Corner Color
    if (!a_corner_color.disabled())
    {
        painter.fillPath(corner_color_path, a_corner_color.value<QColor>());
    }

    // - Draw Border
    if (border_thickness)
    {
        if (QString(a_border_fill.typeName()) == QString("QList<std::pair<double,QColor>>"))
        {
            QLinearGradient border_fill_gradient;

            border_fill_gradient.setStart(0, 0);
            border_fill_gradient.setFinalStop(width(), 0);
            border_fill_gradient.setStops(a_border_fill.value<QGradientStops>());

            painter.fillPath(border_path, border_fill_gradient);
        }
        else painter.fillPath(border_path, a_border_fill.value<QColor>());
    }

    // - Draw Background
    if (!a_fill.disabled())
    {
        if (QString(a_fill.typeName()) == QString("QList<std::pair<double,QColor>>"))
        {
            QLinearGradient fill_gradient;

            fill_gradient.setStart(0, 0);
            fill_gradient.setFinalStop(width(), 0);
            fill_gradient.setStops(a_fill.value<QGradientStops>());

            painter.fillPath(background_path, fill_gradient);
        }
        else
        {
            if (m_hovering && !a_hover_fill.disabled())
                painter.fillPath(background_path, a_hover_fill.value<QColor>());
            else
                painter.fillPath(background_path, a_fill.value<QColor>());
        }
    }

    // - Draw Outline Color
    if (!a_outline_color.disabled())
    {
        painter.strokePath(outline_color_path, QPen(a_outline_color.value<QColor>()));
    }

    painter.end();
}

void GradientSelectionDialog::setup_layout()
{
    // Inner Layout
    QVBoxLayout* inner_layout = new QVBoxLayout;

    inner_layout->setContentsMargins(15, 22, 15, 0);
    inner_layout->setSpacing(12);
    inner_layout->addWidget(m_gradient_widget);
    inner_layout->addWidget(m_apply_button);
    inner_layout->addStretch();
    inner_layout->setAlignment(m_gradient_widget, Qt::AlignHCenter);
    inner_layout->setAlignment(m_apply_button, Qt::AlignRight);

    // Main Layout
    int margin = a_border_thickness.value<int>();

    m_main_layout->setContentsMargins(margin, margin, margin, margin);
    m_main_layout->setSpacing(0);
    m_main_layout->addWidget(m_titlebar);
    m_main_layout->addLayout(inner_layout);

    setLayout(m_main_layout);

    //m_main_layout->update();
    m_main_layout->activate();
}
