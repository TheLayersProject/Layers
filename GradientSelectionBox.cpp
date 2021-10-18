#include "Layers.h"

using Layers::GradientSelectionBox;

GradientSelectionBox::GradientSelectionBox(QGradientStops gradient_stops, QWidget* parent) : QDialog(parent)
{
	init_child_themeable_reference_list();
	init_attributes();

	setFixedSize(525, 325);
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
    installEventFilter(this);

    set_name("gradient_selection_box");
    
    m_gradient_stops = gradient_stops;

    init_titlebar();
    init_gradient_widget();

    m_apply_button->set_name("apply_button");
    m_apply_button->set_padding(8, 6, 8, 6);
    m_apply_button->set_text_padding(1, 3, 0, 0);
    m_apply_button->disable_text_hover_color();
    connect(m_apply_button, &Button::clicked, [this] { done(QDialog::Accepted); });

    assign_tag_prefixes();

    setup_layout();

    init_color_controls();

    m_single_click_timer.setSingleShot(true);

    connect(&m_single_click_timer, &QTimer::timeout, this, &GradientSelectionBox::click_control);
}

void GradientSelectionBox::add_gradient_stop(double stop_val, QColor color)
{
    ColorControl* color_control = new ColorControl(this);
    color_control->show();
    color_control->set_stateless_attribute_value("background_color", color);

    color_control->disable_clicking();

    connect(color_control, &ColorControl::color_changed, [this, color_control] {
        if (color_control->attribute_set().attribute_value("background_color")->value<QColor>() != m_gradient_stops.at(color_controls.indexOf(color_control)).second)
        {
            m_gradient_stops.replace(color_controls.indexOf(color_control), QGradientStop(m_gradient_stops.at(color_controls.indexOf(color_control)).first, color_control->attribute_set().attribute_value("background_color")->value<QColor>()));
            m_gradient_widget->set_stateless_attribute_value("background_gradient_stops", QVariant::fromValue(m_gradient_stops));
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

QGradientStops GradientSelectionBox::gradient_stops() const
{
    return m_gradient_stops;
}

void GradientSelectionBox::init_attributes()
{
	QGradientStops background_gradient_stops = { { 0.0, Qt::white },{ 1.0, Qt::black } };
	QGradientStops border_gradient_stops = { { 0.0, Qt::lightGray },{ 1.0, Qt::darkGray } };

	add_stateless_attribute("background_color", QColor(Qt::white));
	add_stateless_attribute("background_color_hover", QColor(Qt::white));
	add_stateless_attribute("background_color_hover_disabled", true);
	add_stateless_attribute("background_gradient_stops", QVariant::fromValue(background_gradient_stops));
	add_stateless_attribute("background_gradient_disabled", true);
	add_stateless_attribute("using_background_color_hover", false);
	add_stateless_attribute("background_disabled", false);
	add_stateless_attribute("border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	add_stateless_attribute("border_gradient_disabled", true);
	add_stateless_attribute("border_color", QColor(Qt::black));
	add_stateless_attribute("border_thickness", 10);
	add_stateless_attribute("corner_radius_tl", 10);
	add_stateless_attribute("corner_radius_tr", 10);
	add_stateless_attribute("corner_radius_bl", 10);
	add_stateless_attribute("corner_radius_br", 10);
	add_stateless_attribute("margin_left", 0);
	add_stateless_attribute("margin_top", 0);
	add_stateless_attribute("margin_right", 0);
	add_stateless_attribute("margin_bottom", 0);
	add_stateless_attribute("corner_color_disabled", true);
	add_stateless_attribute("corner_color", QColor(Qt::black));
	add_stateless_attribute("outline_color_disabled", false);
	add_stateless_attribute("outline_color", QColor(Qt::black));

    m_titlebar->set_stateless_attribute_value("corner_radius_tl", inner_radius(m_attribute_set.attribute_value("corner_radius_tl")->value<int>(), m_attribute_set.attribute_value("border_thickness")->value<int>()));
	m_titlebar->set_stateless_attribute_value("corner_radius_tr", inner_radius(m_attribute_set.attribute_value("corner_radius_tr")->value<int>(), m_attribute_set.attribute_value("border_thickness")->value<int>()));

    m_gradient_widget->set_stateless_attribute_value("background_gradient_disabled", false);
    m_gradient_widget->set_stateless_attribute_value("border_thickness", 1);
    m_gradient_widget->set_stateless_attribute_value("corner_radius_tl", 8);
    m_gradient_widget->set_stateless_attribute_value("corner_radius_tr", 8);
    m_gradient_widget->set_stateless_attribute_value("corner_radius_bl", 8);
    m_gradient_widget->set_stateless_attribute_value("corner_radius_br", 8);
}

void GradientSelectionBox::init_color_controls()
{
    for (int i = 0; i < m_gradient_stops.count(); i++)
    {
        QGradientStop gradient_stop = m_gradient_stops.at(i);

        ColorControl* color_control = new ColorControl(this);
        color_control->set_stateless_attribute_value("background_color", gradient_stop.second);
        if (i > 0 && i < m_gradient_stops.count() - 1) color_control->disable_clicking();

        connect(color_control, &ColorControl::color_changed, [this, color_control] {
            if (color_control->attribute_set().attribute_value("background_color")->value<QColor>() != m_gradient_stops.at(color_controls.indexOf(color_control)).second)
            {
                m_gradient_stops.replace(color_controls.indexOf(color_control), QGradientStop(m_gradient_stops.at(color_controls.indexOf(color_control)).first, color_control->attribute_set().attribute_value("background_color")->value<QColor>()));
                m_gradient_widget->set_stateless_attribute_value("background_gradient_stops", QVariant::fromValue(m_gradient_stops));
            }
            });

        color_controls.append(color_control);

        QPoint gradient_widget_pos = m_gradient_widget->pos();

        color_control->move(gradient_widget_pos.x() - (color_control->width() / 2) + m_gradient_widget->width() * gradient_stop.first,
            gradient_widget_pos.y() - (color_control->height() / 2) + (m_gradient_widget->height() / 2));
    }
}

void GradientSelectionBox::init_gradient_widget()
{
    m_gradient_widget->setFixedSize(448, 176);

    m_gradient_widget->set_stateless_attribute_value("background_gradient_stops", QVariant::fromValue(m_gradient_stops));
}

void GradientSelectionBox::init_child_themeable_reference_list()
{
    add_child_themeable_reference(m_titlebar);
    add_child_themeable_reference(m_apply_button);
}

void GradientSelectionBox::init_titlebar()
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

void GradientSelectionBox::issue_update()
{
	update();
}

void GradientSelectionBox::update_gradient()
{
    m_gradient_stops = QGradientStops();

    int range = color_controls.last()->x() - color_controls.first()->x();

    for (ColorControl* color_control : color_controls)
    {
        if (m_selected_color_control && m_selected_color_control->x() == color_control->x() && color_control != m_selected_color_control);
        else m_gradient_stops.append(QGradientStop{ double(color_control->x() - color_controls.first()->x()) / double(range), color_control->attribute_set().attribute_value("background_color")->value<QColor>() });
    }

    m_gradient_widget->set_stateless_attribute_value("background_gradient_stops", QVariant::fromValue(m_gradient_stops), true);
}

void GradientSelectionBox::update_theme_dependencies()
{
    int margin = m_attribute_set.attribute_value("border_thickness")->value<int>();

    m_main_layout->setContentsMargins(margin, margin, margin, margin);

    m_titlebar->set_stateless_attribute_value("corner_radius_tl", inner_radius(m_attribute_set.attribute_value("corner_radius_tl")->value<int>(), m_attribute_set.attribute_value("border_thickness")->value<int>()));
	m_titlebar->set_stateless_attribute_value("corner_radius_tr", inner_radius(m_attribute_set.attribute_value("corner_radius_tr")->value<int>(), m_attribute_set.attribute_value("border_thickness")->value<int>()));
}

void GradientSelectionBox::click_control()
{
    m_clicking_color_control->click();

    m_clicking_color_control = nullptr;
}

bool GradientSelectionBox::eventFilter(QObject* object, QEvent* event)
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

bool GradientSelectionBox::nativeEvent(const QByteArray& eventType, void* message, qintptr* result)
{
    MSG* msg = static_cast<MSG*>(message);

    if (msg->message == WM_NCHITTEST)
    {
        if (isMaximized())
        {
            return false;
        }

        *result = 0;
        const LONG borderWidth = m_attribute_set.attribute_value("border_thickness")->value<int>() * devicePixelRatio();;
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

void GradientSelectionBox::paintEvent(QPaintEvent* event)
{
	// CREATE VARIABLES:

	bool background_disabled = m_attribute_set.attribute_value("background_disabled")->value<bool>();

	int border_thickness = m_attribute_set.attribute_value("border_thickness")->value<int>();

	int margin_left = m_attribute_set.attribute_value("margin_left")->value<int>();
	int margin_top = m_attribute_set.attribute_value("margin_top")->value<int>();
	int margin_right = m_attribute_set.attribute_value("margin_right")->value<int>();
	int margin_bottom = m_attribute_set.attribute_value("margin_bottom")->value<int>();

	int draw_width = width() - margin_left - margin_right;
	int draw_height = height() - margin_top - margin_bottom;

	int corner_radius_tl = m_attribute_set.attribute_value("corner_radius_tl")->value<int>();
	int corner_radius_tr = m_attribute_set.attribute_value("corner_radius_tr")->value<int>();
	int corner_radius_bl = m_attribute_set.attribute_value("corner_radius_bl")->value<int>();
	int corner_radius_br = m_attribute_set.attribute_value("corner_radius_br")->value<int>();

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
	if (!m_attribute_set.attribute_value("corner_color_disabled")->value<bool>())
	{
		painter.fillPath(corner_color_path, m_attribute_set.attribute_value("corner_color")->value<QColor>());
	}

	// - Draw Border
	if (border_thickness)
	{
		if (!m_attribute_set.attribute_value("border_gradient_disabled")->value<bool>())
		{
			QLinearGradient gradient;

			gradient.setStart(0, 0);
			gradient.setFinalStop(width(), 0);
			gradient.setStops(m_attribute_set.attribute_value("border_gradient_stops")->value<QGradientStops>());

			painter.fillPath(border_path, gradient);
		}
		else painter.fillPath(border_path, m_attribute_set.attribute_value("border_color")->value<QColor>());
	}

	// - Draw Background
	if (!background_disabled)
	{
		if (m_attribute_set.attribute_value("background_gradient_disabled")->value<bool>())
		{
			if (!m_attribute_set.attribute_value("background_color_hover_disabled")->value<bool>() && m_attribute_set.attribute_value("using_background_color_hover")->value<bool>())
				painter.fillPath(background_path, m_attribute_set.attribute_value("background_color_hover")->value<QColor>());
			else
				painter.fillPath(background_path, m_attribute_set.attribute_value("background_color")->value<QColor>());
		}
		else
		{
			QLinearGradient bg_gradient;

			bg_gradient.setStart(0, 0);
			bg_gradient.setFinalStop(width(), 0);
			bg_gradient.setStops(m_attribute_set.attribute_value("background_gradient_stops")->value<QGradientStops>());

			painter.fillPath(background_path, bg_gradient);
		}
	}

	// - Draw Outline Color
	if (!m_attribute_set.attribute_value("outline_color_disabled")->value<bool>())
	{
		painter.strokePath(outline_color_path, QPen(m_attribute_set.attribute_value("outline_color")->value<QColor>()));
	}

	painter.end();
}

void GradientSelectionBox::setup_layout()
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
    int margin = m_attribute_set.attribute_value("border_thickness")->value<int>();

    m_main_layout->setContentsMargins(margin, margin, margin, margin);
    m_main_layout->setSpacing(0);
    m_main_layout->addWidget(m_titlebar);
    m_main_layout->addLayout(inner_layout);

    setLayout(m_main_layout);

    //m_main_layout->update();
    m_main_layout->activate();
}
