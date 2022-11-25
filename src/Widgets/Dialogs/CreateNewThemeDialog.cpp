#include "../../../include/CreateNewThemeDialog.h"
#include "../../../include/calculate.h"

#include <Windows.h>
#include <windowsx.h>

#include <QApplication>
#include <QPainterPath>

using Layers::CreateNewThemeDialog;

CreateNewThemeDialog::CreateNewThemeDialog(QWidget* parent) : QDialog(parent)
{
	init_child_themeable_reference_list();
	init_attributes();

	setFixedSize(525, 300);
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);

	set_name("create_new_theme_dialog");

	init_titlebar();

	m_create_button->set_name("create_button");
	//m_create_button->set_padding(8, 6, 8, 6);
	m_create_button->set_text_padding(1, 3, 0, 0);
	m_create_button->disable_text_hover_color();
	m_create_button->set_disabled();
	connect(m_create_button, &Button::clicked, [this] { done(QDialog::Accepted); });

	m_name_label->set_name("name_label");
	m_name_label->set_proper_name("Name Label");
	m_name_label->set_font_size(15);

	m_start_as_label->set_name("start_as_label");
	m_start_as_label->set_proper_name("Start as Label");
	m_start_as_label->set_font_size(15);

	m_theme_name_line_edit->set_name("theme_name_line_edit");
	m_theme_name_line_edit->set_proper_name("Name Line Editor");
	m_theme_name_line_edit->setFixedSize(250, 50);
	m_theme_name_line_edit->set_margin(0);
	m_theme_name_line_edit->set_font_size(15);
	connect(m_theme_name_line_edit, &LineEditor::text_edited, [this] 
	{
		bool has_char_other_than_space = false;

		for (const QChar& character : m_theme_name_line_edit->text())
		{
			if (character != ' ') has_char_other_than_space = true;
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
	m_start_theme_combobox->set_proper_name("Start as Combobox");
	m_start_theme_combobox->setFixedSize(250, 50);
	m_start_theme_combobox->set_font_size(15);

	connect(&a_border_thickness, &Attribute::value_changed, [this] {
		int margin = a_border_thickness.as<double>();

		m_main_layout->setContentsMargins(margin, margin, margin, margin);

		//a_corner_radius_tl.set_value(inner_radius(a_corner_radius_tl.as<double>(), a_border_thickness.as<double>()));
		//a_corner_radius_tr.set_value(inner_radius(a_corner_radius_tr.as<double>(), a_border_thickness.as<double>()));

		m_titlebar->a_corner_radius_tl.set_value(inner_radius(a_corner_radius_tl.as<double>(), a_border_thickness.as<double>()));
		m_titlebar->a_corner_radius_tr.set_value(inner_radius(a_corner_radius_tr.as<double>(), a_border_thickness.as<double>()));
		});

	setup_layout();
}

QString CreateNewThemeDialog::new_theme_name()
{
	return m_theme_name_line_edit->text().simplified();
}

void CreateNewThemeDialog::add_theme_name_to_combobox(const QString& theme_name)
{
	m_start_theme_combobox->add_item(theme_name);
}

void CreateNewThemeDialog::apply_theme_attributes(QMap<QString, Attribute*>& theme_attrs)
{
	a_border_fill.copy_value_from(*theme_attrs["border_fill"]);
	a_border_thickness.copy_value_from(*theme_attrs["border_thickness"]);
	a_corner_color.copy_value_from(*theme_attrs["corner_color"]);
	a_corner_radius_tl.copy_value_from(*theme_attrs["corner_radius_tl"]);
	a_corner_radius_tr.copy_value_from(*theme_attrs["corner_radius_tr"]);
	a_corner_radius_bl.copy_value_from(*theme_attrs["corner_radius_bl"]);
	a_corner_radius_br.copy_value_from(*theme_attrs["corner_radius_br"]);
	a_fill.copy_value_from(*theme_attrs["fill"]);
	a_hover_fill.copy_value_from(*theme_attrs["hover_fill"]);
	a_margin_left.copy_value_from(*theme_attrs["margin_left"]);
	a_margin_top.copy_value_from(*theme_attrs["margin_top"]);
	a_margin_right.copy_value_from(*theme_attrs["margin_right"]);
	a_margin_bottom.copy_value_from(*theme_attrs["margin_bottom"]);
	a_outline_color.copy_value_from(*theme_attrs["outline_color"]);
}

void CreateNewThemeDialog::clear()
{
	m_theme_name_line_edit->set_text("");

	m_create_button->set_disabled();
}

QString CreateNewThemeDialog::copy_theme_name()
{
	return m_start_theme_combobox->current_item();
}

void CreateNewThemeDialog::set_current_start_theme_name(const QString& theme_name)
{
	if (m_start_theme_combobox->items().contains(theme_name))
		m_start_theme_combobox->set_current_item(theme_name);
}

void CreateNewThemeDialog::init_attributes()
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

	m_attribute_layout.append(&a_fill);
	m_attribute_layout.append(&a_hover_fill);
	m_attribute_layout.append(&ag_border);
	m_attribute_layout.append(&ag_corner_radii);
	m_attribute_layout.append(&ag_margins);
	m_attribute_layout.append(&a_corner_color);
	m_attribute_layout.append(&a_outline_color);

	m_titlebar->a_corner_radius_tl.set_value(inner_radius(a_corner_radius_tl.as<double>(), a_border_thickness.as<double>()));
	m_titlebar->a_corner_radius_tr.set_value(inner_radius(a_corner_radius_tr.as<double>(), a_border_thickness.as<double>()));

	m_start_theme_combobox->a_corner_radius_tl.set_value(7.0);
	m_start_theme_combobox->a_corner_radius_tr.set_value(7.0);
	m_start_theme_combobox->a_corner_radius_bl.set_value(7.0);
	m_start_theme_combobox->a_corner_radius_br.set_value(7.0);

	m_theme_name_line_edit->a_border_thickness.set_value(3.0);
	m_theme_name_line_edit->a_corner_radius_tl.set_value(7.0);
	m_theme_name_line_edit->a_corner_radius_tr.set_value(7.0);
	m_theme_name_line_edit->a_corner_radius_bl.set_value(7.0);
	m_theme_name_line_edit->a_corner_radius_br.set_value(7.0);
	m_theme_name_line_edit->a_left_padding.set_value(10.0);
}

void CreateNewThemeDialog::init_child_themeable_reference_list()
{
	store_child_themeable_pointer(m_create_button);
	store_child_themeable_pointer(m_name_label);
	store_child_themeable_pointer(m_start_as_label);
	store_child_themeable_pointer(m_start_theme_combobox);
	store_child_themeable_pointer(m_titlebar);
	store_child_themeable_pointer(m_theme_name_line_edit);
}

bool CreateNewThemeDialog::nativeEvent(const QByteArray& eventType, void* message, qintptr* result)
{
	MSG* msg = static_cast<MSG*>(message);

	if (msg->message == WM_NCHITTEST)
	{
		if (isMaximized())
		{
			return false;
		}

		*result = 0;
		const LONG borderWidth = a_border_thickness.as<double>() * devicePixelRatio();;
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

void CreateNewThemeDialog::paintEvent(QPaintEvent* event)
{
	// CREATE VARIABLES:

	bool fill_disabled = a_fill.disabled();

	int border_thickness = a_border_thickness.as<double>();

	int margin_left = a_margin_left.as<double>();
	int margin_top = a_margin_top.as<double>();
	int margin_right = a_margin_right.as<double>();
	int margin_bottom = a_margin_bottom.as<double>();

	int draw_width = width() - margin_left - margin_right;
	int draw_height = height() - margin_top - margin_bottom;

	int corner_radius_tl = a_corner_radius_tl.as<double>();
	int corner_radius_tr = a_corner_radius_tr.as<double>();
	int corner_radius_bl = a_corner_radius_bl.as<double>();
	int corner_radius_br = a_corner_radius_br.as<double>();

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
		painter.fillPath(corner_color_path, a_corner_color.as<QColor>());
	}

	// - Draw Border
	if (border_thickness)
	{
		if (QString(a_border_fill.typeName()) == QString("QList<std::pair<double,QColor>>"))
		{
			QLinearGradient border_fill_gradient;

			border_fill_gradient.setStart(0, 0);
			border_fill_gradient.setFinalStop(width(), 0);
			border_fill_gradient.setStops(a_border_fill.as<QGradientStops>());

			painter.fillPath(border_path, border_fill_gradient);
		}
		else painter.fillPath(border_path, a_border_fill.as<QColor>());
	}

	// - Draw Background
	if (!a_fill.disabled())
	{
		if (QString(a_fill.typeName()) == QString("QList<std::pair<double,QColor>>"))
		{
			QLinearGradient fill_gradient;

			fill_gradient.setStart(0, 0);
			fill_gradient.setFinalStop(width(), 0);
			fill_gradient.setStops(a_fill.as<QGradientStops>());

			painter.fillPath(background_path, fill_gradient);
		}
		else
		{
			if (m_hovering && !a_hover_fill.disabled())
				painter.fillPath(background_path, a_hover_fill.as<QColor>());
			else
				painter.fillPath(background_path, a_fill.as<QColor>());
		}
	}

	// - Draw Outline Color
	if (!a_outline_color.disabled())
	{
		painter.strokePath(outline_color_path, QPen(a_outline_color.as<QColor>()));
	}

	painter.end();
}

void CreateNewThemeDialog::init_titlebar()
{
	m_titlebar->setFixedHeight(45);
	m_titlebar->set_name("titlebar");
	m_titlebar->set_proper_name("Titlebar");

	m_window_title_label->setAttribute(Qt::WA_TransparentForMouseEvents);
	m_window_title_label->set_name("window_title_label");
	m_window_title_label->set_proper_name("Window Title Label");
	m_window_title_label->set_padding(7, 8, 0, 0);
	m_window_title_label->set_font_size(14);

	connect(m_exit_button, &Button::clicked, [this] { done(QDialog::Rejected); });
	m_exit_button->set_name("exit_button");
	m_exit_button->set_proper_name("Exit Button");

	// Add Titlebar's Child Themeable References
	m_titlebar->store_child_themeable_pointer(m_window_title_label);
	m_titlebar->store_child_themeable_pointer(m_exit_button);

	// Setup Layout
	QHBoxLayout* titlebar_layout = new QHBoxLayout;

	titlebar_layout->setContentsMargins(10, 0, 10, 0);
	titlebar_layout->setSpacing(0);
	titlebar_layout->addWidget(m_window_title_label);
	titlebar_layout->addStretch();
	titlebar_layout->addWidget(m_exit_button);

	m_titlebar->setLayout(titlebar_layout);
}

void CreateNewThemeDialog::setup_layout()
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
	int margin = a_border_thickness.as<double>();

	m_main_layout->setContentsMargins(margin, margin, margin, margin);
	m_main_layout->setSpacing(0);
	m_main_layout->addWidget(m_titlebar);
	m_main_layout->addLayout(inner_layout);

	setLayout(m_main_layout);

	m_main_layout->activate();
}
