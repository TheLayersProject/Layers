#include "Layers.h"

using Layers::Update_Dialog;

Update_Dialog::Update_Dialog(const QString& current_version_tag, const QString& latest_version_tag, QWidget* parent) :
	m_message_label{
	new Label(
		"There is an update available to download.  Would you like to update the software now?\n\n"
		"Current Version: " + current_version_tag + "\n\n"
		"Latest Version: " + latest_version_tag
	) },
	QDialog(parent)
{
	init_child_themeable_reference_list();
	init_attributes();

	setFixedSize(525, 300);
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);

	set_name("update_dialog");

	init_titlebar();

	m_remind_me_later_button->set_name("remind_me_later_button");
	m_remind_me_later_button->set_padding(8, 6, 8, 6);
	m_remind_me_later_button->set_text_padding(1, 3, 0, 0);
	m_remind_me_later_button->disable_text_hover_color();
	connect(m_remind_me_later_button, &Button::clicked, [this] { done(QDialog::Rejected); });

	m_update_button->set_name("update_button");
	m_update_button->set_padding(8, 6, 8, 6);
	m_update_button->set_text_padding(1, 3, 0, 0);
	m_update_button->disable_text_hover_color();
	connect(m_update_button, &Button::clicked, [this] { done(QDialog::Accepted); });

	m_message_label->set_name("message_label");
	m_message_label->set_font_size(15);
	m_message_label->setFixedWidth(475);
	m_message_label->setFixedHeight(200); // Consider a way to get a recommended height from the label
	m_message_label->setWordWrap(true);

	setup_layout();
}

void Update_Dialog::issue_update()
{
	update();
}

void Update_Dialog::update_theme_dependencies()
{
	int margin = m_attribute_set.attribute_value("border_thickness")->value<int>();

	m_main_layout->setContentsMargins(margin, margin, margin, margin);

	m_titlebar->set_stateless_attribute_value("corner_radius_tl", inner_radius(m_attribute_set.attribute_value("corner_radius_tl")->value<int>(), m_attribute_set.attribute_value("border_thickness")->value<int>()));
	m_titlebar->set_stateless_attribute_value("corner_radius_tr", inner_radius(m_attribute_set.attribute_value("corner_radius_tr")->value<int>(), m_attribute_set.attribute_value("border_thickness")->value<int>()));
}

void Update_Dialog::init_attributes()
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
}

void Update_Dialog::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_remind_me_later_button);
	add_child_themeable_reference(m_update_button);
	add_child_themeable_reference(m_message_label);
	add_child_themeable_reference(m_titlebar);
}

bool Update_Dialog::nativeEvent(const QByteArray& eventType, void* message, qintptr* result)
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

void Update_Dialog::paintEvent(QPaintEvent * event)
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

void Update_Dialog::init_titlebar()
{
	m_titlebar->setFixedHeight(45);
	m_titlebar->set_name("titlebar");

	Label* window_title_label = new Label("Update Available");
	window_title_label->setAttribute(Qt::WA_TransparentForMouseEvents);
	window_title_label->set_name("window_title_label");
	window_title_label->set_padding(7, 8, 0, 0);
	window_title_label->set_font_size(14);

	Button* exit_button = new Button(new Graphic_Widget(":/svgs/exit.svg", QSize(20, 20)), true);
	connect(exit_button, &Button::clicked, [this] { done(QDialog::Rejected); });
	exit_button->set_name("exit_button");

	// Add Titlebar's Child Themeable References
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

void Update_Dialog::setup_layout()
{
	// Buttons Layout
	QHBoxLayout* buttons_layout = new QHBoxLayout;

	buttons_layout->setContentsMargins(0, 0, 0, 0);
	buttons_layout->setSpacing(15);
	buttons_layout->addStretch();
	buttons_layout->addWidget(m_remind_me_later_button);
	buttons_layout->addWidget(m_update_button);

	// Inner Layout
	QVBoxLayout* inner_layout = new QVBoxLayout;

	inner_layout->setContentsMargins(15, 22, 15, 15);
	inner_layout->addWidget(m_message_label);
	inner_layout->addStretch();
	inner_layout->addLayout(buttons_layout);
	inner_layout->setAlignment(m_message_label, Qt::AlignLeft);

	// Main Layout
	int margin = m_attribute_set.attribute_value("border_thickness")->value<int>();

	m_main_layout->setContentsMargins(margin, margin, margin, margin);
	m_main_layout->setSpacing(0);
	m_main_layout->addWidget(m_titlebar);
	m_main_layout->addLayout(inner_layout);

	setLayout(m_main_layout);

	m_main_layout->activate();
}
