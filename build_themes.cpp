#include "Layers.h"

using Layers::Theme;

Theme Layers::build_blue_theme()
{
	Theme blue_theme;

	blue_theme.built_in = true;
	blue_theme.name = "Blue";

	QGradientStops border_gradient_stops = { { 0.0, "#4571a2" },{ 1.0, "#001122" } };
	QGradientStops default_gradient_stops = { { 0.0, Qt::black },{ 1.0, Qt::white } };

	// Window Border
	blue_theme.add_attribute("layers/window", "Default", "border_gradient_disabled", false);
	blue_theme.add_attribute("layers/window", "Default", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	blue_theme.add_attribute("layers/window", "Default", "border_color", QColor("#4571A2"));
	blue_theme.add_attribute("layers/window", "Default", "background_color", QColor("#001122"));
	blue_theme.add_attribute("layers/window", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/window", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/window", "Default", "corner_radius_tl", 10);
	blue_theme.add_attribute("layers/window", "Default", "corner_radius_tr", 10);
	blue_theme.add_attribute("layers/window", "Default", "corner_radius_bl", 10);
	blue_theme.add_attribute("layers/window", "Default", "corner_radius_br", 10);
	blue_theme.add_attribute("layers/window", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/window", "Default", "border_thickness", 15);
	blue_theme.add_attribute("layers/window", "Default", "outline_color_disabled", true);

	// Titlebar
	blue_theme.add_attribute("layers/titlebar", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/titlebar", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/titlebar", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/titlebar", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/titlebar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/titlebar", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/titlebar", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/titlebar", "Default", "corner_radius_tl", 6);
	blue_theme.add_attribute("layers/titlebar", "Default", "corner_radius_tr", 6);
	blue_theme.add_attribute("layers/titlebar", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/titlebar", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/titlebar", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/titlebar", "Default", "outline_color_disabled", true);

	// Titlebar -> Window Title Label
	blue_theme.add_attribute("layers/titlebar/window_title_label", "Default", "color", QColor(Qt::lightGray));

	// Titlebar -> Settings Button
	blue_theme.add_attribute("layers/titlebar/settings_button", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/titlebar/settings_button", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/titlebar/settings_button", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/titlebar/settings_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/titlebar/settings_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/titlebar/settings_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/titlebar/settings_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/titlebar/settings_button", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/titlebar/settings_button", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/titlebar/settings_button", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/titlebar/settings_button", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/titlebar/settings_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/titlebar/settings_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Settings Button -> Graphic
	blue_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Settings Button -> Graphic -> SVG
	blue_theme.add_attribute("layers/titlebar/settings_button/graphic/svg", "Default", "common_color", QColor("#536c9a"));
	blue_theme.add_attribute("layers/titlebar/settings_button/graphic/svg", "Default", "common_hover_color", QColor("#6a8ac3"));

	// Titlebar -> Minimize Button
	blue_theme.add_attribute("layers/titlebar/minimize_button", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/titlebar/minimize_button", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/titlebar/minimize_button", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/titlebar/minimize_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/titlebar/minimize_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/titlebar/minimize_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/titlebar/minimize_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/titlebar/minimize_button", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/titlebar/minimize_button", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/titlebar/minimize_button", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/titlebar/minimize_button", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/titlebar/minimize_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/titlebar/minimize_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Minimize Button -> Graphic
	blue_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Minimize Button -> Graphic -> SVG
	blue_theme.add_attribute("layers/titlebar/minimize_button/graphic/svg", "Default", "common_color", QColor("#536c9a"));
	blue_theme.add_attribute("layers/titlebar/minimize_button/graphic/svg", "Default", "common_hover_color", QColor("#6a8ac3"));

	// Titlebar -> Maximize Button
	blue_theme.add_attribute("layers/titlebar/maximize_button", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/titlebar/maximize_button", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/titlebar/maximize_button", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/titlebar/maximize_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/titlebar/maximize_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/titlebar/maximize_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/titlebar/maximize_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/titlebar/maximize_button", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/titlebar/maximize_button", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/titlebar/maximize_button", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/titlebar/maximize_button", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/titlebar/maximize_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/titlebar/maximize_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Maximize Button -> Graphic
	blue_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Maximize Button -> Graphic -> SVG
	blue_theme.add_attribute("layers/titlebar/maximize_button/graphic/svg", "Default", "common_color", QColor("#536c9a"));
	blue_theme.add_attribute("layers/titlebar/maximize_button/graphic/svg", "Default", "common_hover_color", QColor("#6a8ac3"));

	// Titlebar -> Exit Button
	blue_theme.add_attribute("layers/titlebar/exit_button", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/titlebar/exit_button", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/titlebar/exit_button", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/titlebar/exit_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/titlebar/exit_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/titlebar/exit_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/titlebar/exit_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/titlebar/exit_button", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/titlebar/exit_button", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/titlebar/exit_button", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/titlebar/exit_button", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/titlebar/exit_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/titlebar/exit_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Exit Button -> Graphic
	blue_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Exit Button -> Graphic -> SVG
	blue_theme.add_attribute("layers/titlebar/exit_button/graphic/svg", "Default", "common_color", QColor("#536c9a"));
	blue_theme.add_attribute("layers/titlebar/exit_button/graphic/svg", "Default", "common_hover_color", QColor("#E33034"));

	// Titlebar -> Menu Label Layers
	blue_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "background_color", QColor("#253859"));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "corner_radius_tl", 10);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "corner_radius_tr", 10);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "corner_radius_bl", 10);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "corner_radius_br", 10);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "outline_color_disabled", true);

	// Titlebar -> Menu Label Layers -> Back Button
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Menu Label Layers -> Back Button -> Graphic
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Menu Label Layers -> Back Button -> Graphic -> SVG
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "Default", "common_color", QColor("#5884d2"));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "Default", "common_hover_color", QColor("#659dff"));

	// Titlebar -> Menu Label Layers -> Icon Button
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Menu Label Layers -> Icon Button -> Graphic
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Menu Label Layers -> Icon Button -> Graphic -> SVG
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic/svg", "Default", "common_color", QColor("#5e96da"));

	// Titlebar -> Menu Label Layers -> Text Label
	blue_theme.add_attribute("layers/titlebar/menu_label_layer/text_label", "Default", "color", QColor("#5e96da"));

	// Settings Menu
	blue_theme.add_attribute("layers/settings_menu", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/settings_menu", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/settings_menu", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/settings_menu", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/settings_menu", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu", "Default", "outline_color_disabled", true);

	// Settings Menu -> Sidebar
	blue_theme.add_attribute("layers/settings_menu/sidebar", "Default", "background_color", QColor("#4571a2"));
	blue_theme.add_attribute("layers/settings_menu/sidebar", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/settings_menu/sidebar", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/sidebar", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/sidebar", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar", "Default", "outline_color_disabled", true);

	// Settings Menu -> Sidebar -> App Preferences Settings Tab
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "background_color", {
		{ "Unselected", QColor("#4571a2") },
		{ "Selected", QColor("#001122") }
		});
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "background_disabled", false);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_radius_tl", 5);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_radius_bl", 5);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "outline_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_color", QColor("#001122"));

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Icon
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "background_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "outline_color_disabled", true);

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Icon -> SVG
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon/svg", "common_color", {
		{ "Unselected", QColor("#001122") },
		{ "Selected", QColor("#4571a2") }
		});

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Text Label
	blue_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/text_label", "color", {
		{ "Unselected", QColor("#001122") },
		{ "Selected", QColor("#4571a2") }
		});


	// Settings Menu -> Sidebar -> Themes Settings Tab
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "background_color", {
		{ "Unselected", QColor("#4571a2") },
		{ "Selected", QColor("#001122") }
		});
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "background_disabled", false);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_radius_tl", 5);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_radius_bl", 5);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "outline_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_color", QColor("#001122"));

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Icon
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "background_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "outline_color_disabled", true);

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Icon -> SVG
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon/svg", "common_color", {
		{ "Unselected", QColor("#001122") },
		{ "Selected", QColor("#4571a2") }
		});

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Text Label
	blue_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/text_label", "color", {
		{ "Unselected", QColor("#001122") },
		{ "Selected", QColor("#4571a2") }
		});

	// Settings Menu -> Themes Settings Panel
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> "Theme" Label
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_label", "Default", "color", QColor("#4571a2"));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "background_color", QColor("#4571a2"));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "corner_radius_tl", 10);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "corner_radius_tr", 10);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "corner_radius_bl", 10);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "corner_radius_br", 10);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Current Item Label
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/current_item_label", "Default", "color", QColor("#001122"));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down -> Combobox Items
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "background_color", QColor("#274b73"));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "background_color_hover", QColor("#5d9de8"));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "background_disabled", false);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "background_color_hover_disabled", false);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down -> Combobox Items -> Label
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item/label", "Common", "color", QColor("#001122"));

	// Settings Menu -> Themes Settings Panel -> Separators
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "background_color", QColor("#4571a2"));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> New Theme Button
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> New Theme Button -> Graphic
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> New Theme Button -> Graphic -> SVG
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "Default", "common_color", QColor("#43ad3f"));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "Default", "common_hover_color", QColor("#82ff7b"));

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button -> Graphic
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button -> Graphic -> SVG
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "Default", "common_color", QColor("#c3c3c3"));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "Default", "common_hover_color", QColor("#e6e6e6"));

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button -> Graphic
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button -> Graphic -> SVG
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "Default", "common_color", QColor("#ae3f3f"));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "Default", "common_hover_color", QColor("#e95454"));

	// Settings Menu -> Themes Settings Panel -> Theme Info Button
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Theme Info Button -> Graphic
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Theme Info Button -> Graphic -> SVG
	blue_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic/svg", "Default", "common_color", QColor("#4571a2"));

	// Customize Menu
	blue_theme.add_attribute("layers/customize_menu", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/customize_menu", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/customize_menu", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_menu", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_menu", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_menu", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_menu", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_menu", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/customize_menu", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/customize_menu", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/customize_menu", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/customize_menu", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_menu", "Default", "outline_color_disabled", true);

	// Customize Menu -> Arrow Graphic
	blue_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "outline_color_disabled", true);

	// Customize Menu -> Arrow Graphic -> SVG
	blue_theme.add_attribute("layers/customize_menu/arrow_graphic/svg", "Default", "common_color", QColor("#001122"));

	// Customize Menu -> Label Button
	blue_theme.add_attribute("layers/customize_menu/label_button", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/customize_menu/label_button", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/label_button", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/label_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/label_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_menu/label_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_menu/label_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_menu/label_button", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/customize_menu/label_button", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/customize_menu/label_button", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/customize_menu/label_button", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/customize_menu/label_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/label_button", "Default", "outline_color_disabled", true);

	// Customize Menu -> Label Button -> Text Label
	blue_theme.add_attribute("layers/customize_menu/label_button/text_label", "Default", "color", QColor("#001122"));
	blue_theme.add_attribute("layers/customize_menu/label_button/text_label", "Default", "color_hover", QColor("#6aaaf7"));

	// Customize Menu -> Sidebar
	blue_theme.add_attribute("layers/customize_menu/sidebar", "Default", "background_color", QColor("#4571a2"));
	blue_theme.add_attribute("layers/customize_menu/sidebar", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/customize_menu/sidebar", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/sidebar", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/sidebar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_menu/sidebar", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_menu/sidebar", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_menu/sidebar", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/customize_menu/sidebar", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/customize_menu/sidebar", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/customize_menu/sidebar", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/customize_menu/sidebar", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/sidebar", "Default", "outline_color_disabled", true);

	// Customize Menu -> Topbar
	blue_theme.add_attribute("layers/customize_menu/topbar", "Default", "background_color", QColor("#4571a2"));
	blue_theme.add_attribute("layers/customize_menu/topbar", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/customize_menu/topbar", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/topbar", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/topbar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_menu/topbar", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_menu/topbar", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_menu/topbar", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/customize_menu/topbar", "Default", "corner_radius_tr", 10);
	blue_theme.add_attribute("layers/customize_menu/topbar", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/customize_menu/topbar", "Default", "corner_radius_br", 10);
	blue_theme.add_attribute("layers/customize_menu/topbar", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/topbar", "Default", "outline_color_disabled", true);

	// Customize Menu -> Topbar -> Apply Button
	blue_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "background_color", QColor("#61ad50"));
	blue_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "background_color_hover", QColor("#6fc65b"));
	blue_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "background_color_hover_disabled", false);
	blue_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "corner_radius_tl", 7);
	blue_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "corner_radius_tr", 7);
	blue_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "corner_radius_bl", 7);
	blue_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "corner_radius_br", 7);
	blue_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "outline_color_disabled", true);

	// Customize Menu -> Topbar -> Apply Button -> Text Label
	blue_theme.add_attribute("layers/customize_menu/topbar/apply_button/text_label", "Default", "color", QColor("#f8f8f8"));

	// Customize Panel
	blue_theme.add_attribute("layers/customize_panel", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/customize_panel", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/customize_panel", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/customize_panel", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/customize_panel", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/customize_panel", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/customize_panel", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attributes Label
	blue_theme.add_attribute("layers/customize_panel/attributes_label", "Default", "color", QColor("#6aaaf7"));

	// Customize Panel -> Elements Label
	blue_theme.add_attribute("layers/customize_panel/elements_label", "Default", "color", QColor("#6aaaf7"));

	// Customize Panel -> States Label
	blue_theme.add_attribute("layers/customize_panel/states_label", "Default", "color", QColor("#6aaaf7"));

	// Customize Panel -> State Combobox
	blue_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "background_color", QColor("#001122"));
	blue_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "corner_radius_tl", 10);
	blue_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "corner_radius_tr", 10);
	blue_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "corner_radius_bl", 10);
	blue_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "corner_radius_br", 10);
	blue_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "outline_color_disabled", true);

	// Customize Panel -> State Combobox -> Current Item Label
	blue_theme.add_attribute("layers/customize_panel/state_combobox/current_item_label", "Default", "color", QColor("#4571a2"));

	// Customize Panel -> State Combobox -> Drop Down
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "outline_color_disabled", true);

	// Customize Panel -> State Combobox -> Drop Down -> Combobox Item
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "background_color", QColor("#274b73"));
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "background_color_hover", QColor("#5d9de8"));
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "background_disabled", false);
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "background_color_hover_disabled", false);
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "outline_color_disabled", true);

	// Customize Panel -> State Combobox -> Drop Down -> Combobox Item -> Label
	blue_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item/label", "Common", "color", QColor("#001122"));

	// Customize Panel -> Show All Button
	blue_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "background_color", QColor("#61ad50"));
	blue_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "background_color_hover", QColor("#6fc65b"));
	blue_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "background_color_hover_disabled", false);
	blue_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "corner_radius_tl", 7);
	blue_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "corner_radius_tr", 7);
	blue_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "corner_radius_bl", 7);
	blue_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "corner_radius_br", 7);
	blue_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "outline_color_disabled", true);

	// Customize Panel -> Show All Button -> Text Label
	blue_theme.add_attribute("layers/customize_panel/show_all_button/text_label", "Default", "color", QColor("#f8f8f8"));

	// Customize Panel -> Show Primary Button
	blue_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "background_color", QColor("#61ad50"));
	blue_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "background_color_hover", QColor("#6fc65b"));
	blue_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "background_color_hover_disabled", false);
	blue_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "corner_radius_tl", 7);
	blue_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "corner_radius_tr", 7);
	blue_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "corner_radius_bl", 7);
	blue_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "corner_radius_br", 7);
	blue_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "outline_color_disabled", true);

	// Customize Panel -> Show Primary Button -> Text Label
	blue_theme.add_attribute("layers/customize_panel/show_primary_button/text_label", "Default", "color", QColor("#f8f8f8"));

	// Customize Panel -> Attribute Widget
	blue_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "background_color", QColor("#3e6795"));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "secondary_background_color", QColor("#4571a2"));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "border_color", QColor("#001122"));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "corner_radius_tl", 10);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "corner_radius_tr", 10);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "corner_radius_bl", 10);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "corner_radius_br", 10);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Collapse Button
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic -> SVG
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic/svg", "Default", "common_color", QColor("#001122"));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic/svg", "Default", "common_hover_color", QColor("#6aaaf7"));

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic After
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic After -> SVG
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "Default", "common_color", QColor("#001122"));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "Default", "common_hover_color", QColor("#6aaaf7"));

	// Customize Panel -> Attribute Widget -> Label
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/label", "Default", "color", QColor("#001122"));

	// Customize Panel -> Attribute Widget -> Line Editor
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "background_color", QColor("#001122"));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "text_color", QColor("#4571a2"));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "corner_radius_tl", 5);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "corner_radius_tr", 5);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "corner_radius_bl", 5);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "corner_radius_br", 5);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Toggle
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "background_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Toggle -> Switch
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "background_color", {
		{ "Untoggled", QColor("#4571a2") },
		{ "Toggled", QColor("#6fc65b") }
		});
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "background_disabled", false);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "border_color", {
		{ "Untoggled", QColor("#001122") },
		{ "Toggled", QColor("#6fc65b") }
		});
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "border_thickness", 3);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "corner_radius_tl", 4);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "corner_radius_tr", 4);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "corner_radius_bl", 4);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "corner_radius_br", 4);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Toggle -> Switch -> Square
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "background_color", {
		{ "Untoggled", QColor("#001122") },
		{ "Toggled", QColor(Qt::white) }
		});
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "background_disabled", false);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "corner_radius_tl", 2);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "corner_radius_tr", 2);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "corner_radius_bl", 2);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "corner_radius_br", 2);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Labeled Toggle
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "background_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Switch
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "background_color", {
		{ "Untoggled", QColor("#6fc65b") },
		{ "Toggled", QColor("#6fc65b") }
		});
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "background_disabled", false);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "border_color", {
		{ "Untoggled", QColor("#6fc65b") },
		{ "Toggled", QColor("#6fc65b") }
		});
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "border_thickness", 3);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "corner_radius_tl", 4);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "corner_radius_tr", 4);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "corner_radius_bl", 4);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "corner_radius_br", 4);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Switch -> Square
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "background_color", {
		{ "Untoggled", QColor(Qt::white) },
		{ "Toggled", QColor(Qt::white) }
		});
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "background_disabled", false);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "corner_radius_tl", 2);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "corner_radius_tr", 2);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "corner_radius_bl", 2);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "corner_radius_br", 2);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Text
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/text", "Common", "color", QColor("#001122"));

	// Customize Panel -> Attribute Widget -> Slider
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Slider -> Bar
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "background_color", QColor("#34557c"));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "corner_radius_tl", 2);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "corner_radius_tr", 2);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "corner_radius_bl", 2);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "corner_radius_br", 2);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Slider -> Handle
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "background_color", QColor("#001122"));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "corner_radius_tl", 3);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "corner_radius_tr", 3);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "corner_radius_bl", 3);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "corner_radius_br", 3);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "outline_color_disabled", true);

	// Customize Panel -> Element Button
	blue_theme.add_attribute("layers/customize_panel/element_button", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/customize_panel/element_button", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/element_button", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/element_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/element_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/element_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/element_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/element_button", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/customize_panel/element_button", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/customize_panel/element_button", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/customize_panel/element_button", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/customize_panel/element_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/element_button", "Default", "outline_color_disabled", true);

	// Customize Panel -> Element Button -> Graphic
	blue_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "outline_color_disabled", true);

	// Customize Panel -> Element Button -> Graphic -> SVG
	blue_theme.add_attribute("layers/customize_panel/element_button/graphic/svg", "Default", "common_color", QColor("#001122"));
	blue_theme.add_attribute("layers/customize_panel/element_button/graphic/svg", "Default", "common_hover_color", QColor("#6aaaf7"));

	// Customize Panel -> Element Button -> Text Label
	blue_theme.add_attribute("layers/customize_panel/element_button/text_label", "Default", "color", QColor("#001122"));
	blue_theme.add_attribute("layers/customize_panel/element_button/text_label", "Default", "color_hover", QColor("#6aaaf7"));

	// Gradient Selection Box
	blue_theme.add_attribute("layers/gradient_selection_box", "Default", "background_color", QColor("#001122"));
	blue_theme.add_attribute("layers/gradient_selection_box", "Default", "border_gradient_disabled", false);
	blue_theme.add_attribute("layers/gradient_selection_box", "Default", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	blue_theme.add_attribute("layers/gradient_selection_box", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/gradient_selection_box", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/gradient_selection_box", "Default", "border_gradient_disabled", false);
	blue_theme.add_attribute("layers/gradient_selection_box", "Default", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	blue_theme.add_attribute("layers/gradient_selection_box", "Default", "border_color", QColor("#4571A2"));
	blue_theme.add_attribute("layers/gradient_selection_box", "Default", "border_thickness", 10);
	blue_theme.add_attribute("layers/gradient_selection_box", "Default", "corner_radius_tl", 10);
	blue_theme.add_attribute("layers/gradient_selection_box", "Default", "corner_radius_tr", 10);
	blue_theme.add_attribute("layers/gradient_selection_box", "Default", "corner_radius_bl", 10);
	blue_theme.add_attribute("layers/gradient_selection_box", "Default", "corner_radius_br", 10);
	blue_theme.add_attribute("layers/gradient_selection_box", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/gradient_selection_box", "Default", "outline_color_disabled", false);

	// Gradient Selection Box -> Titlebar
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "background_color", QColor("#253859"));
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "corner_radius_tl",
		inner_radius(
			blue_theme["layers/gradient_selection_box"]["corner_radius_tl"].value().value<int>(),
			blue_theme["layers/gradient_selection_box"]["border_thickness"].value().value<int>()));
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "corner_radius_tr",
		inner_radius(
			blue_theme["layers/gradient_selection_box"]["corner_radius_tr"].value().value<int>(),
			blue_theme["layers/gradient_selection_box"]["border_thickness"].value().value<int>()));
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "outline_color_disabled", true);

	// Gradient Selection Box -> Titlebar -> Window Title Label
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/window_title_label", "Default", "color", QColor(Qt::lightGray));

	// Gradient Selection Box -> Titlebar -> Exit Button
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "outline_color_disabled", true);

	// Gradient Selection Box -> Titlebar -> Exit Button -> Graphic
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "outline_color_disabled", true);

	// Gradient Selection Box -> Titlebar -> Exit Button -> Graphic -> SVG
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "Default", "common_color", QColor("#536c9a"));
	blue_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "Default", "common_hover_color", QColor("#E33034"));

	// Gradient Selection Box -> Apply Button
	blue_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "background_color", QColor("#61ad50"));
	blue_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "background_color_hover", QColor("#6fc65b"));
	blue_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "background_color_hover_disabled", false);
	blue_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "corner_radius_tl", 7);
	blue_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "corner_radius_tr", 7);
	blue_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "corner_radius_bl", 7);
	blue_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "corner_radius_br", 7);
	blue_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "outline_color_disabled", true);

	// Gradient Selection Box -> Apply Button -> Text Label
	blue_theme.add_attribute("layers/gradient_selection_box/apply_button/text_label", "Default", "color", QColor("#f8f8f8"));

	// Create New Theme Dialog
	blue_theme.add_attribute("layers/create_new_theme_dialog", "Default", "background_color", QColor("#001122"));
	blue_theme.add_attribute("layers/create_new_theme_dialog", "Default", "border_gradient_disabled", false);
	blue_theme.add_attribute("layers/create_new_theme_dialog", "Default", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	blue_theme.add_attribute("layers/create_new_theme_dialog", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/create_new_theme_dialog", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog", "Default", "border_gradient_disabled", false);
	blue_theme.add_attribute("layers/create_new_theme_dialog", "Default", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	blue_theme.add_attribute("layers/create_new_theme_dialog", "Default", "border_color", QColor("#4571A2"));
	blue_theme.add_attribute("layers/create_new_theme_dialog", "Default", "border_thickness", 10);
	blue_theme.add_attribute("layers/create_new_theme_dialog", "Default", "corner_radius_tl", 10);
	blue_theme.add_attribute("layers/create_new_theme_dialog", "Default", "corner_radius_tr", 10);
	blue_theme.add_attribute("layers/create_new_theme_dialog", "Default", "corner_radius_bl", 10);
	blue_theme.add_attribute("layers/create_new_theme_dialog", "Default", "corner_radius_br", 10);
	blue_theme.add_attribute("layers/create_new_theme_dialog", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog", "Default", "outline_color_disabled", false);

	// Create New Theme Dialog -> Titlebar
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "background_color", QColor("#253859"));
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "corner_radius_tl",
		inner_radius(
			blue_theme["layers/create_new_theme_dialog"]["corner_radius_tl"].value().value<int>(),
			blue_theme["layers/create_new_theme_dialog"]["border_thickness"].value().value<int>()));
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "corner_radius_tr",
		inner_radius(
			blue_theme["layers/create_new_theme_dialog"]["corner_radius_tr"].value().value<int>(),
			blue_theme["layers/create_new_theme_dialog"]["border_thickness"].value().value<int>()));
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Titlebar -> Window Title Label
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/window_title_label", "Default", "color", QColor(Qt::lightGray));

	// Create New Theme Dialog -> Titlebar -> Exit Button
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Titlebar -> Exit Button -> Graphic
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Titlebar -> Exit Button -> Graphic -> SVG
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "Default", "common_color", QColor("#536c9a"));
	blue_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "Default", "common_hover_color", QColor("#E33034"));

	// Create New Theme Dialog -> "Name" Label
	blue_theme.add_attribute("layers/create_new_theme_dialog/name_label", "Default", "color", QColor("#4571a2"));

	// Create New Theme Dialog -> Theme Name Line Edit
	blue_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "background_color", QColor("#001122"));
	blue_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "border_color", QColor("#4571a2"));
	blue_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "border_thickness", 3);
	blue_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "corner_radius_tl", 7);
	blue_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "corner_radius_tr", 7);
	blue_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "corner_radius_bl", 7);
	blue_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "corner_radius_br", 7);
	blue_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "outline_color_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "text_color", QColor("#4571a2"));

	// Create New Theme Dialog -> "Start as copy of" Label
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_as_label", "Default", "color", QColor("#4571a2"));

	// Create New Theme Dialog -> Start Theme Combobox
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "background_color", QColor("#4571a2"));
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "background_disabled", false);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "corner_radius_tl", 7);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "corner_radius_tr", 7);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "corner_radius_bl", 7);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "corner_radius_br", 7);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Start Theme Combobox -> Current Item Label
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/current_item_label", "Default", "color", QColor("#001122"));

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "background_color", QColor(Qt::white));
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "background_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "background_color_hover_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "corner_radius_tl", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "corner_radius_tr", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "corner_radius_bl", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "corner_radius_br", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down -> Combobox Items
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "background_color", QColor("#274b73"));
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "background_color_hover", QColor("#5d9de8"));
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "background_disabled", false);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "background_color_hover_disabled", false);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "border_thickness", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 7 },
		{ "Top", 7 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 7 },
		{ "Top", 7 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 7 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 7 }
		});
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 7 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 7 }
		});
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "outline_color_disabled", true);

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down -> Combobox Items -> Label
	blue_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item/label", "Common", "color", QColor("#001122"));

	// Create New Theme Dialog -> Create Button
	blue_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "background_color", QColor("#61ad50"));
	blue_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "background_color_hover", QColor("#6fc65b"));
	blue_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "background_disabled", false);
	//blue_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "background_color_hover_disabled", false);
	blue_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "border_gradient_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "border_color", QColor(Qt::black));
	blue_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "border_thickness", 0);
	blue_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "corner_radius_tl", 7);
	blue_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "corner_radius_tr", 7);
	blue_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "corner_radius_bl", 7);
	blue_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "corner_radius_br", 7);
	blue_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "corner_color_disabled", true);
	blue_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Create Button -> Text Label
	blue_theme.add_attribute("layers/create_new_theme_dialog/create_button/text_label", "Default", "color", QColor("#f8f8f8"));

	return blue_theme;
}

Theme Layers::build_dark_theme()
{
	Theme dark_theme;

	dark_theme.built_in = true;
	dark_theme.name = "Dark";

	QGradientStops border_gradient_stops = { { 0.0, "#6a6a6a" },{ 1.0, "#444444" } };
	QGradientStops default_gradient_stops = { { 0.0, Qt::black },{ 1.0, Qt::white } };

	// Window
	dark_theme.add_attribute("layers/window", "Default", "border_gradient_disabled", false);
	dark_theme.add_attribute("layers/window", "Default", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	dark_theme.add_attribute("layers/window", "Default", "border_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/window", "Default", "background_color", QColor("#2e2e2e"));
	dark_theme.add_attribute("layers/window", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/window", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/window", "Default", "corner_radius_tl", 10);
	dark_theme.add_attribute("layers/window", "Default", "corner_radius_tr", 10);
	dark_theme.add_attribute("layers/window", "Default", "corner_radius_bl", 10);
	dark_theme.add_attribute("layers/window", "Default", "corner_radius_br", 10);
	dark_theme.add_attribute("layers/window", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/window", "Default", "border_thickness", 15);
	dark_theme.add_attribute("layers/window", "Default", "outline_color_disabled", true);

	// Titlebar
	dark_theme.add_attribute("layers/titlebar", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/titlebar", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/titlebar", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/titlebar", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/titlebar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/titlebar", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/titlebar", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/titlebar", "Default", "corner_radius_tl", 6);
	dark_theme.add_attribute("layers/titlebar", "Default", "corner_radius_tr", 6);
	dark_theme.add_attribute("layers/titlebar", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/titlebar", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/titlebar", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/titlebar", "Default", "outline_color_disabled", true);

	// Titlebar -> Label
	dark_theme.add_attribute("layers/titlebar/window_title_label", "Default", "color", QColor("#e3e3e3"));

	// Titlebar -> Settings Button
	dark_theme.add_attribute("layers/titlebar/settings_button", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/titlebar/settings_button", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/titlebar/settings_button", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/titlebar/settings_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/titlebar/settings_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/titlebar/settings_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/titlebar/settings_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/titlebar/settings_button", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/titlebar/settings_button", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/titlebar/settings_button", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/titlebar/settings_button", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/titlebar/settings_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/titlebar/settings_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Settings Button -> Graphic
	dark_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Settings Button -> Graphic -> SVG
	dark_theme.add_attribute("layers/titlebar/settings_button/graphic/svg", "Default", "common_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/titlebar/settings_button/graphic/svg", "Default", "common_hover_color", QColor("#e3e3e3"));

	// Titlebar -> Minimize Button
	dark_theme.add_attribute("layers/titlebar/minimize_button", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/titlebar/minimize_button", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/titlebar/minimize_button", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/titlebar/minimize_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/titlebar/minimize_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/titlebar/minimize_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/titlebar/minimize_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/titlebar/minimize_button", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/titlebar/minimize_button", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/titlebar/minimize_button", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/titlebar/minimize_button", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/titlebar/minimize_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/titlebar/minimize_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Minimize Button -> Graphic
	dark_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Minimize Button -> Graphic -> SVG
	dark_theme.add_attribute("layers/titlebar/minimize_button/graphic/svg", "Default", "common_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/titlebar/minimize_button/graphic/svg", "Default", "common_hover_color", QColor("#e3e3e3"));

	// Titlebar -> Maximize Button
	dark_theme.add_attribute("layers/titlebar/maximize_button", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/titlebar/maximize_button", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/titlebar/maximize_button", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/titlebar/maximize_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/titlebar/maximize_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/titlebar/maximize_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/titlebar/maximize_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/titlebar/maximize_button", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/titlebar/maximize_button", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/titlebar/maximize_button", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/titlebar/maximize_button", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/titlebar/maximize_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/titlebar/maximize_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Maximize Button -> Graphic
	dark_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Maximize Button -> Graphic -> SVG
	dark_theme.add_attribute("layers/titlebar/maximize_button/graphic/svg", "Default", "common_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/titlebar/maximize_button/graphic/svg", "Default", "common_hover_color", QColor("#e3e3e3"));

	// Titlebar -> Exit Button
	dark_theme.add_attribute("layers/titlebar/exit_button", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/titlebar/exit_button", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/titlebar/exit_button", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/titlebar/exit_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/titlebar/exit_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/titlebar/exit_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/titlebar/exit_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/titlebar/exit_button", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/titlebar/exit_button", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/titlebar/exit_button", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/titlebar/exit_button", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/titlebar/exit_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/titlebar/exit_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Exit Button -> Graphic
	dark_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Exit Button -> Graphic -> SVG
	dark_theme.add_attribute("layers/titlebar/exit_button/graphic/svg", "Default", "common_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/titlebar/exit_button/graphic/svg", "Default", "common_hover_color", QColor("#E33034"));

	// Titlebar -> Menu Label Layers
	dark_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "background_color", QColor("#363636"));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "corner_radius_tl", 10);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "corner_radius_tr", 10);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "corner_radius_bl", 10);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "corner_radius_br", 10);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "outline_color_disabled", true);

	// Titlebar -> Menu Label Layers -> Back Button
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Menu Label Layers -> Back Button -> Graphic
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Menu Label Layers -> Back Button -> Graphic -> SVG
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "Default", "common_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "Default", "common_hover_color", QColor("#e3e3e3"));

	// Titlebar -> Menu Label Layers -> Icon Button
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Menu Label Layers -> Icon Button -> Graphic
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Menu Label Layers -> Icon Button -> Graphic -> SVG
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic/svg", "Default", "common_color", QColor("#e3e3e3"));

	// Titlebar -> Menu Label Layers -> Text Label
	dark_theme.add_attribute("layers/titlebar/menu_label_layer/text_label", "Default", "color", QColor("#e3e3e3"));

	// Settings Menu
	dark_theme.add_attribute("layers/settings_menu", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/settings_menu", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/settings_menu", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/settings_menu", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/settings_menu", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu", "Default", "outline_color_disabled", true);

	// Settings Menu -> Sidebar
	dark_theme.add_attribute("layers/settings_menu/sidebar", "Default", "background_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/settings_menu/sidebar", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/settings_menu/sidebar", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/sidebar", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/sidebar", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar", "Default", "outline_color_disabled", true);

	// Settings Menu -> Sidebar -> App Preferences Settings Tab
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "background_color", {
		{ "Unselected", QColor("#6a6a6a") },
		{ "Selected", QColor("#2e2e2e") }
		});
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "background_disabled", false);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_radius_tl", 5);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_radius_bl", 5);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "outline_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_color", QColor("#2e2e2e"));

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Icon
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "background_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "outline_color_disabled", true);

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Icon -> SVG
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon/svg", "common_color", {
		{ "Unselected", QColor("#2e2e2e") },
		{ "Selected", QColor("#6a6a6a") }
		});

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Text Label
	dark_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/text_label", "color", {
		{ "Unselected", QColor("#2e2e2e") },
		{ "Selected", QColor("#6a6a6a") }
		});

	// Settings Menu -> Sidebar -> Themes Settings Tab
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "background_color", {
		{ "Unselected", QColor("#6a6a6a") },
		{ "Selected", QColor("#2e2e2e") }
		});
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "background_disabled", false);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_radius_tl", 5);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_radius_bl", 5);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "outline_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_color", QColor("#2e2e2e"));

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Icon
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "background_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "outline_color_disabled", true);

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Icon -> SVG
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon/svg", "common_color", {
		{ "Unselected", QColor("#2e2e2e") },
		{ "Selected", QColor("#6a6a6a") }
		});

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Text Label
	dark_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/text_label", "color", {
		{ "Unselected", QColor("#2e2e2e") },
		{ "Selected", QColor("#6a6a6a") }
		});

	// Settings Menu -> Themes Settings Panel
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> "Theme" Label
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_label", "Default", "color", QColor("#6a6a6a"));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "background_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "corner_radius_tl", 10);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "corner_radius_tr", 10);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "corner_radius_bl", 10);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "corner_radius_br", 10);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Current Item Label
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/current_item_label", "Default", "color", QColor("#2e2e2e"));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down -> Combobox Items
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "background_color", QColor("#959595"));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "background_color_hover", QColor("#f3f3f3"));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "background_disabled", false);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "background_color_hover_disabled", false);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down -> Combobox Items -> Label
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item/label", "Common", "color", QColor("#2e2e2e"));

	// Settings Menu -> Themes Settings Panel -> Separators
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "background_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> New Theme Button
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> New Theme Button -> Graphic
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> New Theme Button -> Graphic -> SVG
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "Default", "common_color", QColor("#6fc654"));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "Default", "common_hover_color", QColor("#8cfa6a"));

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button -> Graphic
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button -> Graphic -> SVG
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "Default", "common_color", QColor("#c3c3c3"));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "Default", "common_hover_color", QColor("#e6e6e6"));

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button -> Graphic
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button -> Graphic -> SVG
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "Default", "common_color", QColor("#e95454"));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "Default", "common_hover_color", QColor("#ff7f7f"));

	// Settings Menu -> Themes Settings Panel -> Theme Info Button
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Theme Info Button -> Graphic
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Theme Info Button -> Graphic -> SVG
	dark_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic/svg", "Default", "common_color", QColor("#6a6a6a"));

	// Customize Menu
	dark_theme.add_attribute("layers/customize_menu", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/customize_menu", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/customize_menu", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_menu", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_menu", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_menu", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_menu", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_menu", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/customize_menu", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/customize_menu", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/customize_menu", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/customize_menu", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_menu", "Default", "outline_color_disabled", true);

	// Customize Menu -> Arrow Graphic
	dark_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "outline_color_disabled", true);

	// Customize Menu -> Arrow Graphic -> SVG
	dark_theme.add_attribute("layers/customize_menu/arrow_graphic/svg", "Default", "common_color", QColor("#2e2e2e"));

	// Customize Menu -> Label Button
	dark_theme.add_attribute("layers/customize_menu/label_button", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/customize_menu/label_button", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/label_button", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/label_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/label_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_menu/label_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_menu/label_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_menu/label_button", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/customize_menu/label_button", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/customize_menu/label_button", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/customize_menu/label_button", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/customize_menu/label_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/label_button", "Default", "outline_color_disabled", true);

	// Customize Menu -> Label Button -> Text Label
	dark_theme.add_attribute("layers/customize_menu/label_button/text_label", "Default", "color", QColor("#2e2e2e"));
	dark_theme.add_attribute("layers/customize_menu/label_button/text_label", "Default", "color_hover", QColor("#e1e1e1"));

	// Customize Menu -> Sidebar
	dark_theme.add_attribute("layers/customize_menu/sidebar", "Default", "background_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/customize_menu/sidebar", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/customize_menu/sidebar", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/sidebar", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/sidebar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_menu/sidebar", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_menu/sidebar", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_menu/sidebar", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/customize_menu/sidebar", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/customize_menu/sidebar", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/customize_menu/sidebar", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/customize_menu/sidebar", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/sidebar", "Default", "outline_color_disabled", true);

	// Customize Menu -> Topbar
	dark_theme.add_attribute("layers/customize_menu/topbar", "Default", "background_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/customize_menu/topbar", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/customize_menu/topbar", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/topbar", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/topbar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_menu/topbar", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_menu/topbar", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_menu/topbar", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/customize_menu/topbar", "Default", "corner_radius_tr", 10);
	dark_theme.add_attribute("layers/customize_menu/topbar", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/customize_menu/topbar", "Default", "corner_radius_br", 10);
	dark_theme.add_attribute("layers/customize_menu/topbar", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/topbar", "Default", "outline_color_disabled", true);

	// Customize Menu -> Topbar -> Apply Button
	dark_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "background_color", QColor("#61ad50"));
	dark_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "background_color_hover", QColor("#6fc65b"));
	dark_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "background_color_hover_disabled", false);
	dark_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "corner_radius_tl", 7);
	dark_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "corner_radius_tr", 7);
	dark_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "corner_radius_bl", 7);
	dark_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "corner_radius_br", 7);
	dark_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "outline_color_disabled", true);

	// Customize Menu -> Topbar -> Apply Button -> Text Label
	dark_theme.add_attribute("layers/customize_menu/topbar/apply_button/text_label", "Default", "color", QColor("#f8f8f8"));

	// Customize Panel
	dark_theme.add_attribute("layers/customize_panel", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/customize_panel", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/customize_panel", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/customize_panel", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/customize_panel", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/customize_panel", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/customize_panel", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attributes Label
	dark_theme.add_attribute("layers/customize_panel/attributes_label", "Default", "color", QColor("#e1e1e1"));

	// Customize Panel -> Elements Label
	dark_theme.add_attribute("layers/customize_panel/elements_label", "Default", "color", QColor("#e1e1e1"));

	// Customize Panel -> States Label
	dark_theme.add_attribute("layers/customize_panel/states_label", "Default", "color", QColor("#e1e1e1"));

	// Customize Panel -> State Combobox
	dark_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "background_color", QColor("#2e2e2e"));
	dark_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "corner_radius_tl", 10);
	dark_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "corner_radius_tr", 10);
	dark_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "corner_radius_bl", 10);
	dark_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "corner_radius_br", 10);
	dark_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "outline_color_disabled", true);

	// Customize Panel -> State Combobox -> Current Item Label
	dark_theme.add_attribute("layers/customize_panel/state_combobox/current_item_label", "Default", "color", QColor("#6a6a6a"));

	// Customize Panel -> State Combobox -> Drop Down
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "outline_color_disabled", true);

	// Customize Panel -> State Combobox -> Drop Down -> Combobox Item
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "background_color", QColor("#959595"));
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "background_color_hover", QColor("#f3f3f3"));
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "background_disabled", false);
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "background_color_hover_disabled", false);
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "outline_color_disabled", true);

	// Customize Panel -> State Combobox -> Drop Down -> Combobox Item -> Label
	dark_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item/label", "Common", "color", QColor("#2e2e2e"));

	// Customize Panel -> Show All Button
	dark_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "background_color", QColor("#61ad50"));
	dark_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "background_color_hover", QColor("#6fc65b"));
	dark_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "background_color_hover_disabled", false);
	dark_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "corner_radius_tl", 7);
	dark_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "corner_radius_tr", 7);
	dark_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "corner_radius_bl", 7);
	dark_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "corner_radius_br", 7);
	dark_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "outline_color_disabled", true);

	// Customize Panel -> Show All Button -> Text Label
	dark_theme.add_attribute("layers/customize_panel/show_all_button/text_label", "Default", "color", QColor("#f8f8f8"));

	// Customize Panel -> Show Primary Button
	dark_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "background_color", QColor("#61ad50"));
	dark_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "background_color_hover", QColor("#6fc65b"));
	dark_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "background_color_hover_disabled", false);
	dark_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "corner_radius_tl", 7);
	dark_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "corner_radius_tr", 7);
	dark_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "corner_radius_bl", 7);
	dark_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "corner_radius_br", 7);
	dark_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "outline_color_disabled", true);

	// Customize Panel -> Show Primary Button -> Text Label
	dark_theme.add_attribute("layers/customize_panel/show_primary_button/text_label", "Default", "color", QColor("#f8f8f8"));

	// Customize Panel -> Attribute Widget
	dark_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "background_color", QColor("#5b5b5b"));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "secondary_background_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "border_color", QColor("#2e2e2e"));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "corner_radius_tl", 10);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "corner_radius_tr", 10);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "corner_radius_bl", 10);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "corner_radius_br", 10);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Collapse Button
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic -> SVG
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic/svg", "Default", "common_color", QColor("#2e2e2e"));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic/svg", "Default", "common_hover_color", QColor("#e1e1e1"));

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic After
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic After -> SVG
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "Default", "common_color", QColor("#2e2e2e"));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "Default", "common_hover_color", QColor("#e1e1e1"));

	// Customize Panel -> Attribute Widget -> Label
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/label", "Default", "color", QColor("#2e2e2e"));

	// Customize Panel -> Attribute Widget -> Line Editor
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "background_color", QColor("#2e2e2e"));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "text_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "corner_radius_tl", 5);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "corner_radius_tr", 5);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "corner_radius_bl", 5);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "corner_radius_br", 5);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Toggle
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "background_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Toggle -> Switch
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "background_color", {
		{ "Untoggled", QColor("#6a6a6a") },
		{ "Toggled", QColor("#6fc65b") }
		});
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "background_disabled", false);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "border_color", {
		{ "Untoggled", QColor("#2e2e2e") },
		{ "Toggled", QColor("#6fc65b") }
		});
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "border_thickness", 3);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "corner_radius_tl", 4);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "corner_radius_tr", 4);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "corner_radius_bl", 4);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "corner_radius_br", 4);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Toggle -> Switch -> Square
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "background_color", {
		{ "Untoggled", QColor("#2e2e2e") },
		{ "Toggled", QColor(Qt::white) }
		});
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "background_disabled", false);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "corner_radius_tl", 2);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "corner_radius_tr", 2);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "corner_radius_bl", 2);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "corner_radius_br", 2);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Labeled Toggle
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "background_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Switch
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "background_color", {
		{ "Untoggled", QColor("#6fc65b") },
		{ "Toggled", QColor("#6fc65b") }
		});
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "background_disabled", false);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "border_color", {
		{ "Untoggled", QColor("#6fc65b") },
		{ "Toggled", QColor("#6fc65b") }
		});
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "border_thickness", 3);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "corner_radius_tl", 4);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "corner_radius_tr", 4);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "corner_radius_bl", 4);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "corner_radius_br", 4);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Switch -> Square
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "background_color", {
		{ "Untoggled", QColor(Qt::white) },
		{ "Toggled", QColor(Qt::white) }
		});
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "background_disabled", false);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "corner_radius_tl", 2);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "corner_radius_tr", 2);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "corner_radius_bl", 2);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "corner_radius_br", 2);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Text
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/text", "Common", "color", QColor("#2e2e2e"));

	// Customize Panel -> Attribute Widget -> Slider
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Slider -> Bar
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "background_color", QColor("#7c7c7c"));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "corner_radius_tl", 2);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "corner_radius_tr", 2);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "corner_radius_bl", 2);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "corner_radius_br", 2);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Slider -> Handle
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "background_color", QColor("#2e2e2e"));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "corner_radius_tl", 3);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "corner_radius_tr", 3);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "corner_radius_bl", 3);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "corner_radius_br", 3);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "outline_color_disabled", true);

	// Customize Panel -> Element Button
	dark_theme.add_attribute("layers/customize_panel/element_button", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/customize_panel/element_button", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/element_button", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/element_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/element_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/element_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/element_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/element_button", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/customize_panel/element_button", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/customize_panel/element_button", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/customize_panel/element_button", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/customize_panel/element_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/element_button", "Default", "outline_color_disabled", true);

	// Customize Panel -> Element Button -> Graphic
	dark_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "outline_color_disabled", true);

	// Customize Panel -> Element Button -> Graphic -> SVG
	dark_theme.add_attribute("layers/customize_panel/element_button/graphic/svg", "Default", "common_color", QColor("#2e2e2e"));
	dark_theme.add_attribute("layers/customize_panel/element_button/graphic/svg", "Default", "common_hover_color", QColor("#e1e1e1"));

	// Customize Panel -> Element Button -> Text Label
	dark_theme.add_attribute("layers/customize_panel/element_button/text_label", "Default", "color", QColor("#2e2e2e"));
	dark_theme.add_attribute("layers/customize_panel/element_button/text_label", "Default", "color_hover", QColor("#e1e1e1"));

	// Gradient Selection Box
	dark_theme.add_attribute("layers/gradient_selection_box", "Default", "background_color", QColor("#444444"));
	dark_theme.add_attribute("layers/gradient_selection_box", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/gradient_selection_box", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/gradient_selection_box", "Default", "border_gradient_disabled", false);
	dark_theme.add_attribute("layers/gradient_selection_box", "Default", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	dark_theme.add_attribute("layers/gradient_selection_box", "Default", "border_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/gradient_selection_box", "Default", "border_thickness", 10);
	dark_theme.add_attribute("layers/gradient_selection_box", "Default", "corner_radius_tl", 10);
	dark_theme.add_attribute("layers/gradient_selection_box", "Default", "corner_radius_tr", 10);
	dark_theme.add_attribute("layers/gradient_selection_box", "Default", "corner_radius_bl", 10);
	dark_theme.add_attribute("layers/gradient_selection_box", "Default", "corner_radius_br", 10);
	dark_theme.add_attribute("layers/gradient_selection_box", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/gradient_selection_box", "Default", "outline_color_disabled", false);

	// Gradient Selection Box -> Titlebar
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "background_color", QColor("#363636"));
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "corner_radius_tl",
		inner_radius(
			dark_theme["layers/gradient_selection_box"]["corner_radius_tl"].value().value<int>(),
			dark_theme["layers/gradient_selection_box"]["border_thickness"].value().value<int>()));
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "corner_radius_tr",
		inner_radius(
			dark_theme["layers/gradient_selection_box"]["corner_radius_tr"].value().value<int>(),
			dark_theme["layers/gradient_selection_box"]["border_thickness"].value().value<int>()));
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "outline_color_disabled", true);

	// Gradient Selection Box -> Titlebar -> Window Title Label
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/window_title_label", "Default", "color", QColor("#e3e3e3"));

	// Gradient Selection Box -> Titlebar -> Exit Button
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "outline_color_disabled", true);

	// Gradient Selection Box -> Titlebar -> Exit Button -> Graphic
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "outline_color_disabled", true);

	// Gradient Selection Box -> Titlebar -> Exit Button -> Graphic -> SVG
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "Default", "common_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "Default", "common_hover_color", QColor("#E33034"));

	// Gradient Selection Box -> Apply Button
	dark_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "background_color", QColor("#61ad50"));
	dark_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "background_color_hover", QColor("#6fc65b"));
	dark_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "background_color_hover_disabled", false);
	dark_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "corner_radius_tl", 7);
	dark_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "corner_radius_tr", 7);
	dark_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "corner_radius_bl", 7);
	dark_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "corner_radius_br", 7);
	dark_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "outline_color_disabled", true);

	// Gradient Selection Box -> Apply Button -> Text Label
	dark_theme.add_attribute("layers/gradient_selection_box/apply_button/text_label", "Default", "color", QColor("#f8f8f8"));

	// Create New Theme Dialog
	dark_theme.add_attribute("layers/create_new_theme_dialog", "Default", "background_color", QColor("#2e2e2e"));
	dark_theme.add_attribute("layers/create_new_theme_dialog", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/create_new_theme_dialog", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog", "Default", "border_gradient_disabled", false);
	dark_theme.add_attribute("layers/create_new_theme_dialog", "Default", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	dark_theme.add_attribute("layers/create_new_theme_dialog", "Default", "border_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/create_new_theme_dialog", "Default", "border_thickness", 10);
	dark_theme.add_attribute("layers/create_new_theme_dialog", "Default", "corner_radius_tl", 10);
	dark_theme.add_attribute("layers/create_new_theme_dialog", "Default", "corner_radius_tr", 10);
	dark_theme.add_attribute("layers/create_new_theme_dialog", "Default", "corner_radius_bl", 10);
	dark_theme.add_attribute("layers/create_new_theme_dialog", "Default", "corner_radius_br", 10);
	dark_theme.add_attribute("layers/create_new_theme_dialog", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog", "Default", "outline_color_disabled", false);

	// Create New Theme Dialog -> Titlebar
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "background_color", QColor("#363636"));
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "corner_radius_tl",
		inner_radius(
			dark_theme["layers/create_new_theme_dialog"]["corner_radius_tl"].value().value<int>(),
			dark_theme["layers/create_new_theme_dialog"]["border_thickness"].value().value<int>()));
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "corner_radius_tr",
		inner_radius(
			dark_theme["layers/create_new_theme_dialog"]["corner_radius_tr"].value().value<int>(),
			dark_theme["layers/create_new_theme_dialog"]["border_thickness"].value().value<int>()));
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Titlebar -> Window Title Label
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/window_title_label", "Default", "color", QColor("#e3e3e3"));

	// Create New Theme Dialog -> Titlebar -> Exit Button
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Titlebar -> Exit Button -> Graphic
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Titlebar -> Exit Button -> Graphic -> SVG
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "Default", "common_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "Default", "common_hover_color", QColor("#E33034"));

	// Create New Theme Dialog -> "Name" Label
	dark_theme.add_attribute("layers/create_new_theme_dialog/name_label", "Default", "color", QColor("#6a6a6a"));

	// Create New Theme Dialog -> Theme Name Line Edit
	dark_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "background_color", QColor("#2e2e2e"));
	dark_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "border_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "border_thickness", 3);
	dark_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "corner_radius_tl", 7);
	dark_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "corner_radius_tr", 7);
	dark_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "corner_radius_bl", 7);
	dark_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "corner_radius_br", 7);
	dark_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "outline_color_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "text_color", QColor("#6a6a6a"));

	// Create New Theme Dialog -> "Start as copy of" Label
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_as_label", "Default", "color", QColor("#6a6a6a"));

	// Create New Theme Dialog -> Start Theme Combobox
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "background_color", QColor("#6a6a6a"));
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "background_disabled", false);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "corner_radius_tl", 7);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "corner_radius_tr", 7);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "corner_radius_bl", 7);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "corner_radius_br", 7);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Start Theme Combobox -> Current Item Label
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/current_item_label", "Default", "color", QColor("#2e2e2e"));

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "background_color", QColor(Qt::white));
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "background_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "background_color_hover_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "corner_radius_tl", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "corner_radius_tr", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "corner_radius_bl", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "corner_radius_br", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down -> Combobox Items
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "background_color", QColor("#959595"));
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "background_color_hover", QColor("#f3f3f3"));
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "background_disabled", false);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "background_color_hover_disabled", false);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "border_thickness", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 7 },
		{ "Top", 7 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 7 },
		{ "Top", 7 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 7 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 7 }
		});
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 7 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 7 }
		});
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "outline_color_disabled", true);

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down -> Combobox Items -> Label
	dark_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item/label", "Common", "color", QColor("#2e2e2e"));

	// Create New Theme Dialog -> Create Button
	dark_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "background_color", QColor("#61ad50"));
	dark_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "background_color_hover", QColor("#6fc65b"));
	dark_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "background_disabled", false);
	//dark_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "background_color_hover_disabled", false);
	dark_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "border_gradient_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "border_color", QColor(Qt::black));
	dark_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "border_thickness", 0);
	dark_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "corner_radius_tl", 7);
	dark_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "corner_radius_tr", 7);
	dark_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "corner_radius_bl", 7);
	dark_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "corner_radius_br", 7);
	dark_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "corner_color_disabled", true);
	dark_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Create Button -> Text Label
	dark_theme.add_attribute("layers/create_new_theme_dialog/create_button/text_label", "Default", "color", QColor("#f8f8f8"));

	return dark_theme;
}

Theme Layers::build_light_theme()
{
	Theme light_theme;

	light_theme.built_in = true;
	light_theme.name = "Light";

	QGradientStops border_gradient_stops = { { 0.0, Qt::lightGray },{ 1.0, Qt::white } };
	QGradientStops default_gradient_stops = { { 0.0, Qt::black },{ 1.0, Qt::white } };

	// Window Border
	light_theme.add_attribute("layers/window", "Default", "border_gradient_disabled", false);
	light_theme.add_attribute("layers/window", "Default", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	light_theme.add_attribute("layers/window", "Default", "border_color", QColor(Qt::lightGray));
	light_theme.add_attribute("layers/window", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/window", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/window", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/window", "Default", "corner_radius_tl", 10);
	light_theme.add_attribute("layers/window", "Default", "corner_radius_tr", 10);
	light_theme.add_attribute("layers/window", "Default", "corner_radius_bl", 10);
	light_theme.add_attribute("layers/window", "Default", "corner_radius_br", 10);
	light_theme.add_attribute("layers/window", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/window", "Default", "border_thickness", 15);
	light_theme.add_attribute("layers/window", "Default", "outline_color_disabled", true);

	// Titlebar
	light_theme.add_attribute("layers/titlebar", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/titlebar", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/titlebar", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/titlebar", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/titlebar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/titlebar", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/titlebar", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/titlebar", "Default", "corner_radius_tl", 6);
	light_theme.add_attribute("layers/titlebar", "Default", "corner_radius_tr", 6);
	light_theme.add_attribute("layers/titlebar", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/titlebar", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/titlebar", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/titlebar", "Default", "outline_color_disabled", true);

	// Titlebar -> Window Title Label
	light_theme.add_attribute("layers/titlebar/window_title_label", "Default", "color", QColor("#2e2e2e"));

	// Titlebar -> Settings Button
	light_theme.add_attribute("layers/titlebar/settings_button", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/titlebar/settings_button", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/titlebar/settings_button", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/titlebar/settings_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/titlebar/settings_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/titlebar/settings_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/titlebar/settings_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/titlebar/settings_button", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/titlebar/settings_button", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/titlebar/settings_button", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/titlebar/settings_button", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/titlebar/settings_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/titlebar/settings_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Settings Button -> Graphic
	light_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/titlebar/settings_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Settings Button -> Graphic -> SVG
	light_theme.add_attribute("layers/titlebar/settings_button/graphic/svg", "Default", "common_color", QColor("#c5c5c5"));
	light_theme.add_attribute("layers/titlebar/settings_button/graphic/svg", "Default", "common_hover_color", QColor("#6a6a6a"));

	// Titlebar -> Minimize Button
	light_theme.add_attribute("layers/titlebar/minimize_button", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/titlebar/minimize_button", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/titlebar/minimize_button", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/titlebar/minimize_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/titlebar/minimize_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/titlebar/minimize_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/titlebar/minimize_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/titlebar/minimize_button", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/titlebar/minimize_button", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/titlebar/minimize_button", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/titlebar/minimize_button", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/titlebar/minimize_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/titlebar/minimize_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Minimize Button -> Graphic
	light_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/titlebar/minimize_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Minimize Button -> Graphic -> SVG
	light_theme.add_attribute("layers/titlebar/minimize_button/graphic/svg", "Default", "common_color", QColor("#c5c5c5"));
	light_theme.add_attribute("layers/titlebar/minimize_button/graphic/svg", "Default", "common_hover_color", QColor("#6a6a6a"));

	// Titlebar -> Maximize Button
	light_theme.add_attribute("layers/titlebar/maximize_button", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/titlebar/maximize_button", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/titlebar/maximize_button", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/titlebar/maximize_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/titlebar/maximize_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/titlebar/maximize_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/titlebar/maximize_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/titlebar/maximize_button", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/titlebar/maximize_button", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/titlebar/maximize_button", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/titlebar/maximize_button", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/titlebar/maximize_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/titlebar/maximize_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Maximize Button -> Graphic
	light_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/titlebar/maximize_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Maximize Button -> Graphic -> SVG
	light_theme.add_attribute("layers/titlebar/maximize_button/graphic/svg", "Default", "common_color", QColor("#c5c5c5"));
	light_theme.add_attribute("layers/titlebar/maximize_button/graphic/svg", "Default", "common_hover_color", QColor("#6a6a6a"));

	// Titlebar -> Exit Button
	light_theme.add_attribute("layers/titlebar/exit_button", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/titlebar/exit_button", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/titlebar/exit_button", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/titlebar/exit_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/titlebar/exit_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/titlebar/exit_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/titlebar/exit_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/titlebar/exit_button", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/titlebar/exit_button", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/titlebar/exit_button", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/titlebar/exit_button", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/titlebar/exit_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/titlebar/exit_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Exit Button -> Graphic
	light_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/titlebar/exit_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Exit Button -> Graphic -> SVG
	light_theme.add_attribute("layers/titlebar/exit_button/graphic/svg", "Default", "common_color", QColor("#c5c5c5"));
	light_theme.add_attribute("layers/titlebar/exit_button/graphic/svg", "Default", "common_hover_color", QColor("#f25557"));

	// Titlebar -> Menu Label Layers
	light_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "background_color", QColor("#e1e1e1"));
	light_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "corner_radius_tl", 10);
	light_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "corner_radius_tr", 10);
	light_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "corner_radius_bl", 10);
	light_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "corner_radius_br", 10);
	light_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer", "Default", "outline_color_disabled", true);

	// Titlebar -> Menu Label Layers -> Back Button
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Menu Label Layers -> Back Button -> Graphic
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Menu Label Layers -> Back Button -> Graphic -> SVG
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "Default", "common_color", QColor("#858585"));
	light_theme.add_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "Default", "common_hover_color", QColor("#2e2e2e"));

	// Titlebar -> Menu Label Layers -> Icon Button
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button", "Default", "outline_color_disabled", true);

	// Titlebar -> Menu Label Layers -> Icon Button -> Graphic
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "Default", "outline_color_disabled", true);

	// Titlebar -> Menu Label Layers -> Icon Button -> Graphic -> SVG
	light_theme.add_attribute("layers/titlebar/menu_label_layer/icon_button/graphic/svg", "Default", "common_color", QColor("#2e2e2e"));

	// Titlebar -> Menu Label Layers -> Text Label
	light_theme.add_attribute("layers/titlebar/menu_label_layer/text_label", "Default", "color", QColor("#2e2e2e"));

	// Settings Menu
	light_theme.add_attribute("layers/settings_menu", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/settings_menu", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/settings_menu", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/settings_menu", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/settings_menu", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu", "Default", "outline_color_disabled", true);

	// Settings Menu -> Sidebar
	light_theme.add_attribute("layers/settings_menu/sidebar", "Default", "background_color", QColor(Qt::lightGray));
	light_theme.add_attribute("layers/settings_menu/sidebar", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/settings_menu/sidebar", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/sidebar", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/sidebar", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar", "Default", "outline_color_disabled", true);

	// Settings Menu -> Sidebar -> App Preferences Settings Tab
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "background_color", {
		{ "Unselected", QColor(Qt::lightGray) },
		{ "Selected", QColor(Qt::white) }
		});
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "background_disabled", false);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_radius_tl", 5);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_radius_bl", 5);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "outline_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "Common", "corner_color", QColor("#2e2e2e"));

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Icon
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "background_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "corner_radius_tl", 5);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "corner_radius_bl", 5);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "Common", "outline_color_disabled", true);


	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Icon -> SVG
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon/svg", "common_color", {
		{ "Unselected", QColor("#5d5d5d") },
		{ "Selected", QColor("#2e2e2e") }
		});

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Text Label
	light_theme.add_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/text_label", "color", {
		{ "Unselected", QColor("#5d5d5d") },
		{ "Selected", QColor("#2e2e2e") }
		});

	// Settings Menu -> Sidebar -> Themes Settings Tab
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "background_color", {
		{ "Unselected", QColor(Qt::lightGray) },
		{ "Selected", QColor(Qt::white) }
		});
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "background_disabled", false);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_radius_tl", 5);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_radius_bl", 5);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "outline_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab", "Common", "corner_color", QColor("#2e2e2e"));

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Icon
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "background_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "corner_radius_tl", 5);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "corner_radius_bl", 5);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "Common", "outline_color_disabled", true);


	// Settings Menu -> Sidebar -> Themes Settings Tab -> Icon -> SVG
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon/svg", "common_color", {
		{ "Unselected", QColor("#5d5d5d") },
		{ "Selected", QColor("#2e2e2e") }
		});

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Text Label
	light_theme.add_attribute("layers/settings_menu/sidebar/themes_settings_tab/text_label", "color", {
		{ "Unselected", QColor("#5d5d5d") },
		{ "Selected", QColor("#2e2e2e") }
		});

	// Settings Menu -> Themes Settings Panel
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> "Theme" Label
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_label", "Default", "color", QColor("#2e2e2e"));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "background_color", QColor(Qt::lightGray));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "corner_radius_tl", 10);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "corner_radius_tr", 10);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "corner_radius_bl", 10);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "corner_radius_br", 10);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Current Item Label
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/current_item_label", "Default", "color", QColor("#5d5d5d"));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down -> Combobox Items
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "background_color", QColor("#d6d6d6"));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "background_color_hover", QColor("#ededed"));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "background_disabled", false);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "background_color_hover_disabled", false);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "Common", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down -> Combobox Items -> Label
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item/label", "Common", "color", QColor("#2e2e2e"));

	// Settings Menu -> Themes Settings Panel -> Separators
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "background_color", QColor(Qt::lightGray));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/separator", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> New Theme Button
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> New Theme Button -> Graphic
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> New Theme Button -> Graphic -> SVG
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "Default", "common_color", QColor("#6fc654"));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "Default", "common_hover_color", QColor("#8cfa6a"));

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button -> Graphic
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button -> Graphic -> SVG
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "Default", "common_color", QColor("#c3c3c3"));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "Default", "common_hover_color", QColor("#e6e6e6"));

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button -> Graphic
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button -> Graphic -> SVG
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "Default", "common_color", QColor("#e95454"));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "Default", "common_hover_color", QColor("#ff7f7f"));

	// Settings Menu -> Themes Settings Panel -> Theme Info Button
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Theme Info Button -> Graphic
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "Default", "outline_color_disabled", true);

	// Settings Menu -> Themes Settings Panel -> Theme Info Button -> Graphic -> SVG
	light_theme.add_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic/svg", "Default", "common_color", QColor("#6a6a6a"));

	// Customize Menu
	light_theme.add_attribute("layers/customize_menu", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/customize_menu", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/customize_menu", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_menu", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_menu", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_menu", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_menu", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_menu", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/customize_menu", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/customize_menu", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/customize_menu", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/customize_menu", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_menu", "Default", "outline_color_disabled", true);

	// Customize Menu -> Arrow Graphic
	light_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_menu/arrow_graphic", "Default", "outline_color_disabled", true);

	// Customize Menu -> Arrow Graphic -> SVG
	light_theme.add_attribute("layers/customize_menu/arrow_graphic/svg", "Default", "common_color", QColor("#2e2e2e"));

	// Customize Menu -> Label Button
	light_theme.add_attribute("layers/customize_menu/label_button", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/customize_menu/label_button", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/customize_menu/label_button", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_menu/label_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_menu/label_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_menu/label_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_menu/label_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_menu/label_button", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/customize_menu/label_button", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/customize_menu/label_button", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/customize_menu/label_button", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/customize_menu/label_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_menu/label_button", "Default", "outline_color_disabled", true);

	// Customize Menu -> Label Button -> Text Label
	light_theme.add_attribute("layers/customize_menu/label_button/text_label", "Default", "color", QColor("#2e2e2e"));
	light_theme.add_attribute("layers/customize_menu/label_button/text_label", "Default", "color_hover", QColor(Qt::white));

	// Customize Menu -> Sidebar
	light_theme.add_attribute("layers/customize_menu/sidebar", "Default", "background_color", QColor(Qt::lightGray));
	light_theme.add_attribute("layers/customize_menu/sidebar", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/customize_menu/sidebar", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_menu/sidebar", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_menu/sidebar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_menu/sidebar", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_menu/sidebar", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_menu/sidebar", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/customize_menu/sidebar", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/customize_menu/sidebar", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/customize_menu/sidebar", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/customize_menu/sidebar", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_menu/sidebar", "Default", "outline_color_disabled", true);

	// Customize Menu -> Topbar
	light_theme.add_attribute("layers/customize_menu/topbar", "Default", "background_color", QColor(Qt::lightGray));
	light_theme.add_attribute("layers/customize_menu/topbar", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/customize_menu/topbar", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_menu/topbar", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_menu/topbar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_menu/topbar", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_menu/topbar", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_menu/topbar", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/customize_menu/topbar", "Default", "corner_radius_tr", 10);
	light_theme.add_attribute("layers/customize_menu/topbar", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/customize_menu/topbar", "Default", "corner_radius_br", 10);
	light_theme.add_attribute("layers/customize_menu/topbar", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_menu/topbar", "Default", "outline_color_disabled", true);

	// Customize Menu -> Topbar -> Apply Button
	light_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "background_color", QColor("#61ad50"));
	light_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "background_color_hover", QColor("#6fc65b"));
	light_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "background_color_hover_disabled", false);
	light_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "corner_radius_tl", 7);
	light_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "corner_radius_tr", 7);
	light_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "corner_radius_bl", 7);
	light_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "corner_radius_br", 7);
	light_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_menu/topbar/apply_button", "Default", "outline_color_disabled", true);

	// Customize Menu -> Topbar -> Apply Button -> Text Label
	light_theme.add_attribute("layers/customize_menu/topbar/apply_button/text_label", "Default", "color", QColor("#f8f8f8"));

	// Customize Panel
	light_theme.add_attribute("layers/customize_panel", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/customize_panel", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/customize_panel", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/customize_panel", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/customize_panel", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/customize_panel", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/customize_panel", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attributes Label
	light_theme.add_attribute("layers/customize_panel/attributes_label", "Default", "color", QColor(Qt::white));

	// Customize Panel -> Elements Label
	light_theme.add_attribute("layers/customize_panel/elements_label", "Default", "color", QColor(Qt::white));

	// Customize Panel -> States Label
	light_theme.add_attribute("layers/customize_panel/states_label", "Default", "color", QColor(Qt::white));

	// Customize Panel -> State Combobox
	light_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "corner_radius_tl", 10);
	light_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "corner_radius_tr", 10);
	light_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "corner_radius_bl", 10);
	light_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "corner_radius_br", 10);
	light_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/state_combobox", "Default", "outline_color_disabled", true);

	// Customize Panel -> State Combobox -> Current Item Label
	light_theme.add_attribute("layers/customize_panel/state_combobox/current_item_label", "Default", "color", QColor(Qt::gray));

	// Customize Panel -> State Combobox -> Drop Down
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down", "Default", "outline_color_disabled", true);

	// Customize Panel -> State Combobox -> Drop Down -> Combobox Item
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "background_color", QColor("#d6d6d6"));
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "background_color_hover", QColor("#ededed"));
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "background_disabled", false);
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "background_color_hover_disabled", false);
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item", "Common", "outline_color_disabled", true);

	// Customize Panel -> State Combobox -> Drop Down -> Combobox Item -> Label
	light_theme.add_attribute("layers/customize_panel/state_combobox/drop_down/combobox_item/label", "Common", "color", QColor("#2e2e2e"));

	// Customize Panel -> Show All Button
	light_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "background_color", QColor("#61ad50"));
	light_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "background_color_hover", QColor("#6fc65b"));
	light_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "background_color_hover_disabled", false);
	light_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "corner_radius_tl", 7);
	light_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "corner_radius_tr", 7);
	light_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "corner_radius_bl", 7);
	light_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "corner_radius_br", 7);
	light_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/show_all_button", "Default", "outline_color_disabled", true);

	// Customize Panel -> Show All Button -> Text Label
	light_theme.add_attribute("layers/customize_panel/show_all_button/text_label", "Default", "color", QColor("#f8f8f8"));

	// Customize Panel -> Show Primary Button
	light_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "background_color", QColor("#61ad50"));
	light_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "background_color_hover", QColor("#6fc65b"));
	light_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "background_color_hover_disabled", false);
	light_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "corner_radius_tl", 7);
	light_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "corner_radius_tr", 7);
	light_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "corner_radius_bl", 7);
	light_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "corner_radius_br", 7);
	light_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/show_primary_button", "Default", "outline_color_disabled", true);

	// Customize Panel -> Show Primary Button -> Text Label
	light_theme.add_attribute("layers/customize_panel/show_primary_button/text_label", "Default", "color", QColor("#f8f8f8"));

	// Customize Panel -> Attribute Widget
	light_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "background_color", QColor("#a6a6a6"));
	light_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "secondary_background_color", QColor(Qt::lightGray));
	light_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "border_color", QColor("#2e2e2e"));
	light_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "corner_radius_tl", 10);
	light_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "corner_radius_tr", 10);
	light_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "corner_radius_bl", 10);
	light_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "corner_radius_br", 10);
	light_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Collapse Button
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic -> SVG
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic/svg", "Default", "common_color", QColor("#2e2e2e"));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic/svg", "Default", "common_hover_color", QColor(Qt::white));

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic After
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic After -> SVG
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "Default", "common_color", QColor("#2e2e2e"));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "Default", "common_hover_color", QColor(Qt::white));

	// Customize Panel -> Attribute Widget -> Label
	light_theme.add_attribute("layers/customize_panel/attribute_widget/label", "Default", "color", QColor("#2e2e2e"));

	// Customize Panel -> Attribute Widget -> Line Editor
	light_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "background_color", QColor("#2e2e2e"));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "text_color", QColor(Qt::lightGray));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "corner_radius_tl", 5);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "corner_radius_tr", 5);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "corner_radius_bl", 5);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "corner_radius_br", 5);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/line_editor", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Toggle
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "background_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "corner_radius_br", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Toggle -> Switch
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "background_color", {
		{ "Untoggled", QColor(Qt::lightGray) },
		{ "Toggled", QColor("#6fc65b") }
		});
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "background_disabled", false);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "border_color", {
		{ "Untoggled", QColor("#2e2e2e") },
		{ "Toggled", QColor("#6fc65b") }
		});
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "border_thickness", 3);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "corner_radius_tl", 4);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "corner_radius_tr", 4);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "corner_radius_bl", 4);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "corner_radius_br", 4);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Toggle -> Switch -> Square
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "background_color", {
		{ "Untoggled", QColor("#2e2e2e") },
		{ "Toggled", QColor(Qt::white) }
		});
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "background_disabled", false);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "corner_radius_tl", 2);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "corner_radius_tr", 2);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "corner_radius_bl", 2);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "corner_radius_br", 2);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/toggle/switch/square", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Labeled Toggle
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "background_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "corner_radius_br", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Switch
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "background_color", {
		{ "Untoggled", QColor("#6fc65b") },
		{ "Toggled", QColor("#6fc65b") }
		});
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "background_disabled", false);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "border_color", {
		{ "Untoggled", QColor("#6fc65b") },
		{ "Toggled", QColor("#6fc65b") }
		});
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "border_thickness", 3);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "corner_radius_tl", 4);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "corner_radius_tr", 4);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "corner_radius_bl", 4);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "corner_radius_br", 4);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Switch -> Square
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "background_color", {
		{ "Untoggled", QColor(Qt::white) },
		{ "Toggled", QColor(Qt::white) }
		});
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "background_disabled", false);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "corner_radius_tl", 2);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "corner_radius_tr", 2);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "corner_radius_bl", 2);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "corner_radius_br", 2);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/switch/square", "Common", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Text
	light_theme.add_attribute("layers/customize_panel/attribute_widget/labeled_toggle/text", "Common", "color", QColor("#2e2e2e"));

	// Customize Panel -> Attribute Widget -> Slider
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Slider -> Bar
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "background_color", QColor("#7c7c7c"));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "corner_radius_tl", 2);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "corner_radius_tr", 2);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "corner_radius_bl", 2);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "corner_radius_br", 2);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/bar", "Default", "outline_color_disabled", true);

	// Customize Panel -> Attribute Widget -> Slider -> Handle
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "background_color", QColor("#2e2e2e"));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "corner_radius_tl", 3);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "corner_radius_tr", 3);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "corner_radius_bl", 3);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "corner_radius_br", 3);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/attribute_widget/slider/handle", "Default", "outline_color_disabled", true);
	
	// Customize Panel -> Element Button
	light_theme.add_attribute("layers/customize_panel/element_button", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/customize_panel/element_button", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/customize_panel/element_button", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/element_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/element_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/element_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/element_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/element_button", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/customize_panel/element_button", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/customize_panel/element_button", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/customize_panel/element_button", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/customize_panel/element_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/element_button", "Default", "outline_color_disabled", true);

	// Customize Panel -> Element Button -> Graphic
	light_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/customize_panel/element_button/graphic", "Default", "outline_color_disabled", true);

	// Customize Panel -> Element Button -> Graphic -> SVG
	light_theme.add_attribute("layers/customize_panel/element_button/graphic/svg", "Default", "common_color", QColor("#2e2e2e"));
	light_theme.add_attribute("layers/customize_panel/element_button/graphic/svg", "Default", "common_hover_color", QColor(Qt::white));

	// Customize Panel -> Element Button -> Text Label
	light_theme.add_attribute("layers/customize_panel/element_button/text_label", "Default", "color", QColor("#2e2e2e"));
	light_theme.add_attribute("layers/customize_panel/element_button/text_label", "Default", "color_hover", QColor(Qt::white));

	// Gradient Selection Box
	light_theme.add_attribute("layers/gradient_selection_box", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/gradient_selection_box", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/gradient_selection_box", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/gradient_selection_box", "Default", "border_gradient_disabled", false);
	light_theme.add_attribute("layers/gradient_selection_box", "Default", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	light_theme.add_attribute("layers/gradient_selection_box", "Default", "border_color", QColor(Qt::lightGray));
	light_theme.add_attribute("layers/gradient_selection_box", "Default", "border_thickness", 10);
	light_theme.add_attribute("layers/gradient_selection_box", "Default", "corner_radius_tl", 10);
	light_theme.add_attribute("layers/gradient_selection_box", "Default", "corner_radius_tr", 10);
	light_theme.add_attribute("layers/gradient_selection_box", "Default", "corner_radius_bl", 10);
	light_theme.add_attribute("layers/gradient_selection_box", "Default", "corner_radius_br", 10);
	light_theme.add_attribute("layers/gradient_selection_box", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/gradient_selection_box", "Default", "outline_color_disabled", false);

	// Gradient Selection Box -> Titlebar
	light_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "background_color", QColor("#e1e1e1"));
	light_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "corner_radius_tl",
		inner_radius(
			light_theme["layers/gradient_selection_box"]["corner_radius_tl"].value().value<int>(),
			light_theme["layers/gradient_selection_box"]["border_thickness"].value().value<int>()));
	light_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "corner_radius_tr",
		inner_radius(
			light_theme["layers/gradient_selection_box"]["corner_radius_tr"].value().value<int>(),
			light_theme["layers/gradient_selection_box"]["border_thickness"].value().value<int>()));
	light_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar", "Default", "outline_color_disabled", true);

	// Gradient Selection Box -> Titlebar -> Window Title Label
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/window_title_label", "Default", "color", QColor("#2e2e2e"));

	// Gradient Selection Box -> Titlebar -> Exit Button
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button", "Default", "outline_color_disabled", true);

	// Gradient Selection Box -> Titlebar -> Exit Button -> Graphic
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "Default", "outline_color_disabled", true);

	// Gradient Selection Box -> Titlebar -> Exit Button -> Graphic -> SVG
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "Default", "common_color", QColor("#c5c5c5"));
	light_theme.add_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "Default", "common_hover_color", QColor("#f25557"));

	// Gradient Selection Box -> Apply Button
	light_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "background_color", QColor("#61ad50"));
	light_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "background_color_hover", QColor("#6fc65b"));
	light_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "background_color_hover_disabled", false);
	light_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "corner_radius_tl", 7);
	light_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "corner_radius_tr", 7);
	light_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "corner_radius_bl", 7);
	light_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "corner_radius_br", 7);
	light_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/gradient_selection_box/apply_button", "Default", "outline_color_disabled", true);

	// Gradient Selection Box -> Apply Button -> Text Label
	light_theme.add_attribute("layers/gradient_selection_box/apply_button/text_label", "Default", "color", QColor("#f8f8f8"));

	// Create New Theme Dialog
	light_theme.add_attribute("layers/create_new_theme_dialog", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/create_new_theme_dialog", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/create_new_theme_dialog", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog", "Default", "border_gradient_disabled", false);
	light_theme.add_attribute("layers/create_new_theme_dialog", "Default", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	light_theme.add_attribute("layers/create_new_theme_dialog", "Default", "border_color", QColor(Qt::lightGray));
	light_theme.add_attribute("layers/create_new_theme_dialog", "Default", "border_thickness", 10);
	light_theme.add_attribute("layers/create_new_theme_dialog", "Default", "corner_radius_tl", 10);
	light_theme.add_attribute("layers/create_new_theme_dialog", "Default", "corner_radius_tr", 10);
	light_theme.add_attribute("layers/create_new_theme_dialog", "Default", "corner_radius_bl", 10);
	light_theme.add_attribute("layers/create_new_theme_dialog", "Default", "corner_radius_br", 10);
	light_theme.add_attribute("layers/create_new_theme_dialog", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog", "Default", "outline_color_disabled", false);

	// Create New Theme Dialog -> Titlebar
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "background_color", QColor("#e1e1e1"));
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "corner_radius_tl",
		inner_radius(
			light_theme["layers/create_new_theme_dialog"]["corner_radius_tl"].value().value<int>(),
			light_theme["layers/create_new_theme_dialog"]["border_thickness"].value().value<int>()));
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "corner_radius_tr",
		inner_radius(
			light_theme["layers/create_new_theme_dialog"]["corner_radius_tr"].value().value<int>(),
			light_theme["layers/create_new_theme_dialog"]["border_thickness"].value().value<int>()));
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Titlebar -> Window Title Label
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/window_title_label", "Default", "color", QColor("#2e2e2e"));

	// Create New Theme Dialog -> Titlebar -> Exit Button
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Titlebar -> Exit Button -> Graphic
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Titlebar -> Exit Button -> Graphic -> SVG
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "Default", "common_color", QColor("#c5c5c5"));
	light_theme.add_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "Default", "common_hover_color", QColor("#f25557"));

	// Create New Theme Dialog -> "Name" Label
	light_theme.add_attribute("layers/create_new_theme_dialog/name_label", "Default", "color", QColor("#2e2e2e"));

	// Create New Theme Dialog -> Theme Name Line Edit
	light_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "border_color", QColor(Qt::lightGray));
	light_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "border_thickness", 3);
	light_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "corner_radius_tl", 7);
	light_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "corner_radius_tr", 7);
	light_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "corner_radius_bl", 7);
	light_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "corner_radius_br", 7);
	light_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "outline_color_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "Default", "text_color", QColor("#2e2e2e"));

	// Create New Theme Dialog -> "Start as copy of" Label
	light_theme.add_attribute("layers/create_new_theme_dialog/start_as_label", "Default", "color", QColor("#2e2e2e"));

	// Create New Theme Dialog -> Start Theme Combobox
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "background_color", QColor(Qt::lightGray));
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "background_disabled", false);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "corner_radius_tl", 7);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "corner_radius_tr", 7);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "corner_radius_bl", 7);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "corner_radius_br", 7);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Start Theme Combobox -> Current Item Label
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/current_item_label", "Default", "color", QColor("#5d5d5d"));

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "background_color", QColor(Qt::white));
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "background_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "background_color_hover_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "corner_radius_tl", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "corner_radius_tr", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "corner_radius_bl", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "corner_radius_br", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down -> Combobox Items
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "background_color", QColor("#d6d6d6"));
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "background_color_hover", QColor("#ededed"));
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "background_disabled", false);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "background_color_hover_disabled", false);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "border_thickness", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 7 },
		{ "Top", 7 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 7 },
		{ "Top", 7 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 7 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 7 }
		});
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 7 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 7 }
		});
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "corner_color_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "Common", "outline_color_disabled", true);

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down -> Combobox Items -> Label
	light_theme.add_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item/label", "Common", "color", QColor("#2e2e2e"));

	// Create New Theme Dialog -> Create Button
	light_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "background_color", QColor("#61ad50"));
	light_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "background_color_hover", QColor("#6fc65b"));
	light_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "background_disabled", false);
	//light_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "background_color_hover_disabled", false);
	light_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "border_gradient_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "border_color", QColor(Qt::black));
	light_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "border_thickness", 0);
	light_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "corner_radius_tl", 7);
	light_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "corner_radius_tr", 7);
	light_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "corner_radius_bl", 7);
	light_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "corner_radius_br", 7);
	light_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "corner_color_disabled", true);
	light_theme.add_attribute("layers/create_new_theme_dialog/create_button", "Default", "outline_color_disabled", true);

	// Create New Theme Dialog -> Create Button -> Text Label
	light_theme.add_attribute("layers/create_new_theme_dialog/create_button/text_label", "Default", "color", QColor("#f8f8f8"));

	return light_theme;
}
