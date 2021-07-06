#include "Layers.h"

using Layers::Create_New_Theme_Dialog;

Create_New_Theme_Dialog::Create_New_Theme_Dialog(QWidget* parent) : QDialog(parent)
{
	init_child_themeable_reference_list();
	init_attributes();

	setFixedSize(525, 300);
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);

	set_name("create_new_theme_dialog");

	init_titlebar();

	m_create_button->set_name("create_button");
	m_create_button->set_padding(8, 6, 8, 6);
	m_create_button->set_text_padding(1, 3, 0, 0);
	m_create_button->disable_text_hover_color();
	m_create_button->set_disabled();
	connect(m_create_button, &Button::clicked, [this] { done(QDialog::Accepted); });

	m_name_label->set_name("name_label");
	m_name_label->set_font_size(15);

	m_start_as_label->set_name("start_as_label");
	m_start_as_label->set_font_size(15);

	m_theme_name_line_edit->set_name("theme_name_line_edit");
	m_theme_name_line_edit->setFixedSize(250, 50);
	m_theme_name_line_edit->set_margin(0);
	m_theme_name_line_edit->set_font_size(15);
	connect(m_theme_name_line_edit, &Line_Editor::text_edited, [this] 
	{
		bool has_char_other_than_space = false;

		for (const QChar& character : m_theme_name_line_edit->text())
		{
			if (character != " ") has_char_other_than_space = true;
		}

		if (!has_char_other_than_space)
		{
			m_create_button->set_disabled();
			return;
		}

		if (m_theme_name_line_edit->text() == "")
		{
			m_create_button->set_disabled();
			return;
		}
		
		for (const QString& theme_name : m_start_theme_combobox->items())
			if (m_theme_name_line_edit->text().toLower().simplified() == theme_name.toLower().simplified())
			{
				m_create_button->set_disabled();
				return;
			}

		if (m_create_button->disabled()) m_create_button->set_disabled(false);
	});

	m_start_theme_combobox->set_name("start_theme_combobox");
	m_start_theme_combobox->setFixedSize(250, 50);
	m_start_theme_combobox->set_font_size(15);

	setup_layout();
}

void Create_New_Theme_Dialog::issue_update()
{
	update();
}

QString Create_New_Theme_Dialog::new_theme_name()
{
	return m_theme_name_line_edit->text().simplified();
}

void Create_New_Theme_Dialog::add_theme_name_to_combobox(const QString& theme_name)
{
	m_start_theme_combobox->add_item(theme_name);
}

void Create_New_Theme_Dialog::clear()
{
	m_theme_name_line_edit->set_text("");

	m_create_button->set_disabled();
}

QString Create_New_Theme_Dialog::copy_theme_name()
{
	return m_start_theme_combobox->current_item();
}

void Create_New_Theme_Dialog::set_current_start_theme_name(const QString& theme_name)
{
	if (m_start_theme_combobox->items().contains(theme_name))
		m_start_theme_combobox->set_current_item(theme_name);
}

void Create_New_Theme_Dialog::update_theme_dependencies()
{
	m_main_layout->setMargin(attributes()["border_thickness"].value().value<int>());

	m_titlebar->set_attribute_value("Default", "corner_radius_tl", inner_radius(attributes()["corner_radius_tl"].value().value<int>(), attributes()["border_thickness"].value().value<int>()));
	m_titlebar->set_attribute_value("Default", "corner_radius_tr", inner_radius(attributes()["corner_radius_tr"].value().value<int>(), attributes()["border_thickness"].value().value<int>()));
}

void Create_New_Theme_Dialog::init_attributes()
{
	QGradientStops background_gradient_stops = { { 0.0, Qt::white },{ 1.0, Qt::black } };
	QGradientStops border_gradient_stops = { { 0.0, Qt::lightGray },{ 1.0, Qt::darkGray } };

	add_attribute("Default", "background_color", QColor(Qt::white));
	add_attribute("Default", "background_color_hover", QColor(Qt::white));
	add_attribute("Default", "background_color_hover_disabled", true);
	add_attribute("Default", "background_gradient_stops", QVariant::fromValue(background_gradient_stops));
	add_attribute("Default", "background_gradient_disabled", true);
	add_attribute("Default", "using_background_color_hover", false);
	add_attribute("Default", "background_disabled", false);
	add_attribute("Default", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	add_attribute("Default", "border_gradient_disabled", true);
	add_attribute("Default", "border_color", QColor(Qt::black));
	add_attribute("Default", "border_thickness", 10);
	add_attribute("Default", "corner_radius_tl", 10);
	add_attribute("Default", "corner_radius_tr", 10);
	add_attribute("Default", "corner_radius_bl", 10);
	add_attribute("Default", "corner_radius_br", 10);
	add_attribute("Default", "margin_left", 0);
	add_attribute("Default", "margin_top", 0);
	add_attribute("Default", "margin_right", 0);
	add_attribute("Default", "margin_bottom", 0);
	add_attribute("Default", "corner_color_disabled", true);
	add_attribute("Default", "corner_color", QColor(Qt::black));
	add_attribute("Default", "outline_color_disabled", false);
	add_attribute("Default", "outline_color", QColor(Qt::black));

	m_titlebar->set_attribute_value("Default", "corner_radius_tl", inner_radius(attributes()["corner_radius_tl"].value().value<int>(), attributes()["border_thickness"].value().value<int>()));
	m_titlebar->set_attribute_value("Default", "corner_radius_tr", inner_radius(attributes()["corner_radius_tr"].value().value<int>(), attributes()["border_thickness"].value().value<int>()));

	m_start_theme_combobox->set_attribute_value("Default", "corner_radius_tl", 7);
	m_start_theme_combobox->set_attribute_value("Default", "corner_radius_tr", 7);
	m_start_theme_combobox->set_attribute_value("Default", "corner_radius_bl", 7);
	m_start_theme_combobox->set_attribute_value("Default", "corner_radius_br", 7);

	m_theme_name_line_edit->set_attribute_value("Default", "border_thickness", 3);
	m_theme_name_line_edit->set_attribute_value("Default", "corner_radius_tl", 7);
	m_theme_name_line_edit->set_attribute_value("Default", "corner_radius_tr", 7);
	m_theme_name_line_edit->set_attribute_value("Default", "corner_radius_bl", 7);
	m_theme_name_line_edit->set_attribute_value("Default", "corner_radius_br", 7);
	m_theme_name_line_edit->set_attribute_value("Default", "left_padding", 10);
}

void Create_New_Theme_Dialog::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_create_button);
	add_child_themeable_reference(m_name_label);
	add_child_themeable_reference(m_start_as_label);
	add_child_themeable_reference(m_start_theme_combobox);
	add_child_themeable_reference(m_titlebar);
	add_child_themeable_reference(m_theme_name_line_edit);
}

bool Create_New_Theme_Dialog::nativeEvent(const QByteArray& eventType, void* message, long* result)
{
	MSG* msg = static_cast<MSG*>(message);

	if (msg->message == WM_NCHITTEST)
	{
		if (isMaximized())
		{
			return false;
		}

		*result = 0;
		const LONG borderWidth = attributes()["border_thickness"].value().value<int>() * devicePixelRatio();;
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

void Create_New_Theme_Dialog::paintEvent(QPaintEvent * event)
{
	// CREATE VARIABLES:

	bool background_disabled = m_attributes["background_disabled"].value().value<bool>();

	int border_thickness = m_attributes["border_thickness"].value().value<int>();

	int margin_left = m_attributes["margin_left"].value().value<int>();
	int margin_top = m_attributes["margin_top"].value().value<int>();
	int margin_right = m_attributes["margin_right"].value().value<int>();
	int margin_bottom = m_attributes["margin_bottom"].value().value<int>();

	int draw_width = width() - margin_left - margin_right;
	int draw_height = height() - margin_top - margin_bottom;

	int corner_radius_tl = m_attributes["corner_radius_tl"].value().value<int>();
	int corner_radius_tr = m_attributes["corner_radius_tr"].value().value<int>();
	int corner_radius_bl = m_attributes["corner_radius_bl"].value().value<int>();
	int corner_radius_br = m_attributes["corner_radius_br"].value().value<int>();

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
	if (!m_attributes["corner_color_disabled"].value().value<bool>())
	{
		painter.fillPath(corner_color_path, m_attributes["corner_color"].value().value<QColor>());
	}

	// - Draw Border
	if (border_thickness)
	{
		if (!m_attributes["border_gradient_disabled"].value().value<bool>())
		{
			QLinearGradient gradient;

			gradient.setStart(0, 0);
			gradient.setFinalStop(width(), 0);
			gradient.setStops(m_attributes["border_gradient_stops"].value().value<QGradientStops>());

			painter.fillPath(border_path, gradient);
		}
		else painter.fillPath(border_path, m_attributes["border_color"].value().value<QColor>());
	}

	// - Draw Background
	if (!background_disabled)
	{
		if (m_attributes["background_gradient_disabled"].value().value<bool>())
		{
			if (!m_attributes["background_color_hover_disabled"].value().value<bool>() && m_attributes["using_background_color_hover"].value().value<bool>())
				painter.fillPath(background_path, m_attributes["background_color_hover"].value().value<QColor>());
			else
				painter.fillPath(background_path, m_attributes["background_color"].value().value<QColor>());
		}
		else
		{
			QLinearGradient bg_gradient;

			bg_gradient.setStart(0, 0);
			bg_gradient.setFinalStop(width(), 0);
			bg_gradient.setStops(m_attributes["background_gradient_stops"].value().value<QGradientStops>());

			painter.fillPath(background_path, bg_gradient);
		}
	}

	// - Draw Outline Color
	if (!m_attributes["outline_color_disabled"].value().value<bool>())
	{
		painter.strokePath(outline_color_path, QPen(m_attributes["outline_color"].value().value<QColor>()));
	}

	painter.end();
}

void Create_New_Theme_Dialog::init_titlebar()
{
	m_titlebar->setFixedHeight(45);
	m_titlebar->set_name("titlebar");

	Label* window_title_label = new Label("Create New Theme");
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

void Create_New_Theme_Dialog::setup_layout()
{
	// Inner Layout
	QVBoxLayout* inner_layout = new QVBoxLayout;

	inner_layout->setContentsMargins(15, 22, 15, 0);
	inner_layout->addWidget(m_name_label);
	inner_layout->addWidget(m_theme_name_line_edit);
	inner_layout->addSpacing(20);
	inner_layout->addWidget(m_start_as_label);
	inner_layout->addWidget(m_start_theme_combobox);
	inner_layout->addWidget(m_create_button);
	inner_layout->addStretch();
	inner_layout->setAlignment(m_name_label, Qt::AlignLeft);
	inner_layout->setAlignment(m_theme_name_line_edit, Qt::AlignLeft);
	inner_layout->setAlignment(m_start_as_label, Qt::AlignLeft);
	inner_layout->setAlignment(m_start_theme_combobox, Qt::AlignLeft);
	inner_layout->setAlignment(m_create_button, Qt::AlignRight);

	// Main Layout
	m_main_layout->setMargin(attributes()["border_thickness"].value().value<int>());
	m_main_layout->setSpacing(0);
	m_main_layout->addWidget(m_titlebar);
	m_main_layout->addLayout(inner_layout);

	setLayout(m_main_layout);

	m_main_layout->activate();
}
