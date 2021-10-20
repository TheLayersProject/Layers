#include "../../include/build_themes.h"
#include "../../include/calculate.h"
#include "../../include/Theme.h"

#include <QGradientStops>

using Layers::Theme;

Theme Layers::build_layers_blue_theme()
{
	Theme blue_theme = Theme("Blue", false);

	QGradientStops border_gradient_stops = { { 0.0, "#4571a2" },{ 1.0, "#001122" } };
	QGradientStops default_gradient_stops = { { 0.0, Qt::black },{ 1.0, Qt::white } };

	// TEST
	//blue_theme.add_stateless_attribute("app/TilemapEditor/start_up_page", "background_color", QColor("#28405f"));

	// Window
	blue_theme.add_stateless_attribute("layers/window", "border_gradient_disabled", false);
	blue_theme.add_stateless_attribute("layers/window", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	blue_theme.add_stateless_attribute("layers/window", "border_color", QColor("#4571A2"));
	blue_theme.add_stateless_attribute("layers/window", "background_color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/window", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/window", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/window", "corner_radius_tl", 10);
	blue_theme.add_stateless_attribute("layers/window", "corner_radius_tr", 10);
	blue_theme.add_stateless_attribute("layers/window", "corner_radius_bl", 10);
	blue_theme.add_stateless_attribute("layers/window", "corner_radius_br", 10);
	blue_theme.add_stateless_attribute("layers/window", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/window", "border_thickness", 15);
	blue_theme.add_stateless_attribute("layers/window", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/window", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/window", "corner_color", QColor(Qt::black));

	// Titlebar
	blue_theme.add_stateless_attribute("layers/titlebar", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/titlebar", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/titlebar", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/titlebar", "corner_radius_tl", 6);
	blue_theme.add_stateless_attribute("layers/titlebar", "corner_radius_tr", 6);
	blue_theme.add_stateless_attribute("layers/titlebar", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/titlebar", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar", "corner_color", QColor(Qt::black));

	// Titlebar -> Window Title Label
	blue_theme.add_stateless_attribute("layers/titlebar/window_title_label", "color", QColor(Qt::lightGray));

	// Titlebar -> Settings Button
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Settings Button -> Graphic
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Settings Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic/svg", "use_common_hover_color", true);
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic/svg", "common_color", QColor("#536c9a"));
	blue_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic/svg", "common_hover_color", QColor("#6a8ac3"));

	// Titlebar -> Minimize Button
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Minimize Button -> Graphic
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Minimize Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic/svg", "use_common_hover_color", true);
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic/svg", "common_color", QColor("#536c9a"));
	blue_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic/svg", "common_hover_color", QColor("#6a8ac3"));

	// Titlebar -> Maximize Button
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Maximize Button -> Graphic
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Maximize Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic/svg", "use_common_hover_color", true);
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic/svg", "common_color", QColor("#536c9a"));
	blue_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic/svg", "common_hover_color", QColor("#6a8ac3"));

	// Titlebar -> Exit Button
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Exit Button -> Graphic
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Exit Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic/svg", "use_common_hover_color", true);
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic/svg", "common_color", QColor("#536c9a"));
	blue_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic/svg", "common_hover_color", QColor("#E33034"));

	// Titlebar -> Menu Label Layers
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "background_color", QColor("#253859"));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_radius_tl", 10);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_radius_tr", 10);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_radius_bl", 10);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_radius_br", 10);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_color", QColor(Qt::black));

	// Titlebar -> Menu Label Layers -> Back Button
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Menu Label Layers -> Back Button -> Graphic
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Menu Label Layers -> Back Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "use_common_hover_color", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "common_color", QColor("#5884d2"));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "common_hover_color", QColor("#659dff"));

	// Titlebar -> Menu Label Layers -> Icon Button
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Menu Label Layers -> Icon Button -> Graphic
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Menu Label Layers -> Icon Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic/svg", "use_common_hover_color", false);
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic/svg", "common_color", QColor("#5e96da"));

	// Titlebar -> Menu Label Layers -> Text Label
	blue_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/text_label", "color", QColor("#5e96da"));

	// Settings Menu
	blue_theme.add_stateless_attribute("layers/settings_menu", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/settings_menu", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu", "corner_color", QColor(Qt::black));

	// Settings Menu -> Sidebar
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar", "background_color", QColor("#4571a2"));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_color", QColor(Qt::black));

	// Settings Menu -> Sidebar -> App Preferences Settings Tab
	blue_theme.add_stateful_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "background_color", {
		{ "Unselected", QColor("#4571a2") },
		{ "Selected", QColor("#001122") }
		});
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_radius_tl", 5);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_radius_bl", 5);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_color", QColor("#001122"));

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Icon
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_color", QColor(Qt::black));

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Icon -> SVG
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon/svg", "use_common_hover_color", false);
	blue_theme.add_stateful_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon/svg", "common_color", {
		{ "Unselected", QColor("#001122") },
		{ "Selected", QColor("#4571a2") }
		});

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Text Label
	blue_theme.add_stateful_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/text_label", "color", {
		{ "Unselected", QColor("#001122") },
		{ "Selected", QColor("#4571a2") }
		});


	// Settings Menu -> Sidebar -> Themes Settings Tab
	blue_theme.add_stateful_attribute("layers/settings_menu/sidebar/themes_settings_tab", "background_color", {
		{ "Unselected", QColor("#4571a2") },
		{ "Selected", QColor("#001122") }
		});
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_radius_tl", 5);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_radius_bl", 5);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_color", QColor("#001122"));

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Icon
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_color", QColor(Qt::black));

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Icon -> SVG
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon/svg", "use_common_hover_color", false);
	blue_theme.add_stateful_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon/svg", "common_color", {
		{ "Unselected", QColor("#001122") },
		{ "Selected", QColor("#4571a2") }
		});

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Text Label
	blue_theme.add_stateful_attribute("layers/settings_menu/sidebar/themes_settings_tab/text_label", "color", {
		{ "Unselected", QColor("#001122") },
		{ "Selected", QColor("#4571a2") }
		});

	// Settings Menu -> App Preferences Settings Panel
	blue_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> "Theme" Label
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_label", "color", QColor("#4571a2"));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "background_color", QColor("#4571a2"));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_radius_tl", 10);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_radius_tr", 10);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_radius_bl", 10);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_radius_br", 10);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "line_edit_text_color", QColor("#001122")); // TODO: Change value?

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Current Item Label
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/current_item_label", "color", QColor("#001122"));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down -> Combobox Items
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "background_color", QColor("#274b73"));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "background_color_hover", QColor("#5d9de8"));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "background_color_hover_disabled", false);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "border_thickness", 0);
	blue_theme.add_stateful_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	blue_theme.add_stateful_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	blue_theme.add_stateful_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	blue_theme.add_stateful_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down -> Combobox Items -> Label
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item/label", "color", QColor("#001122"));

	// Settings Menu -> Themes Settings Panel -> Separators
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "background_color", QColor("#4571a2"));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> New Theme Button
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> New Theme Button -> Graphic
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> New Theme Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "use_common_hover_color", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "common_color", QColor("#43ad3f"));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "common_hover_color", QColor("#82ff7b"));

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button -> Graphic
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "use_common_hover_color", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "common_color", QColor("#c3c3c3"));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "common_hover_color", QColor("#e6e6e6"));

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button -> Graphic
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "use_common_hover_color", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "common_color", QColor("#ae3f3f"));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "common_hover_color", QColor("#e95454"));

	// Settings Menu -> Themes Settings Panel -> Theme Info Button
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Theme Info Button -> Graphic
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Theme Info Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic/svg", "use_common_hover_color", false);
	blue_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic/svg", "common_color", QColor("#4571a2"));

	// Customize Menu
	blue_theme.add_stateless_attribute("layers/customize_menu", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/customize_menu", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu", "corner_color", QColor(Qt::black));

	// Customize Menu -> Arrow Graphic
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_color", QColor(Qt::black));

	// Customize Menu -> Arrow Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic/svg", "use_common_hover_color", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic/svg", "common_color", QColor("#001122"));

	// Customize Menu -> Label Button
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_color", QColor(Qt::black));

	// Customize Menu -> Label Button -> Text Label
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button/text_label", "color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button/text_label", "color_hover", QColor("#6aaaf7"));

	// Customize Menu -> Sidebar
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar", "background_color", QColor("#4571a2"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar", "background_color", QColor("#4571a2"));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_radius_tr", 10);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_radius_br", 10);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar -> Collapsed Button
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "background_color", QColor("#6aaaf7"));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "background_color_hover", QColor("#6fc65b"));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_radius_tl", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_radius_tr", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_radius_bl", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_radius_br", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_color", QColor(Qt::black));

	// Customize Panel -> Topbar -> Collapsed Button -> Graphic
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_color", QColor(Qt::black));

	// Customize Panel -> Topbar -> Collapsed Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic/svg", "use_common_hover_color", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic/svg", "common_color", QColor("#001122"));

	// Customize Menu -> Topbar -> Collapsed Widget
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "background_color", QColor("#274b73"));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "background_color_hover", QColor("#6fc65b"));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_radius_tl", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_radius_tr", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_radius_bl", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_radius_br", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar -> Apply Button
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "background_color", QColor("#61ad50"));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "background_color_hover", QColor("#6fc65b"));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "background_color_hover_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_radius_tl", 7);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_radius_tr", 7);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_radius_bl", 7);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_radius_br", 7);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar -> Apply Button -> Text Label
	blue_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button/text_label", "color", QColor("#f8f8f8"));

	// Customize Panel
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_color", QColor(Qt::black));

	// Customize Panel -> Stateful Attributes Label
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/stateful_attributes_label", "color", QColor("#6aaaf7"));

	// Customize Panel -> Stateless Attributes Label
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/stateless_attributes_label", "color", QColor("#6aaaf7"));

	// Customize Panel -> Attributes Label
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attributes_label", "color", QColor("#6aaaf7"));

	// Customize Panel -> Elements Label
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/elements_label", "color", QColor("#6aaaf7"));

	// Customize Panel -> States Label
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/states_label", "color", QColor("#6aaaf7"));

	// Customize Panel -> State Combobox
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "background_color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_radius_tl", 10);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_radius_tr", 10);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_radius_bl", 10);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_radius_br", 10);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "line_edit_text_color", QColor("#4571a2"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_color", QColor(Qt::black));

	// Customize Panel -> State Combobox -> Current Item Label
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/current_item_label", "color", QColor("#4571a2"));

	// Customize Panel -> State Combobox -> Drop Down
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_color", QColor(Qt::black));

	// Customize Panel -> State Combobox -> Drop Down -> Combobox Item
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "background_color", QColor("#274b73"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "background_color_hover", QColor("#5d9de8"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "background_color_hover_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "border_thickness", 0);
	blue_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	blue_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	blue_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	blue_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_color", QColor(Qt::black));

	// Customize Panel -> State Combobox -> Drop Down -> Combobox Item -> Label
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item/label", "color", QColor("#001122"));

	// Customize Panel -> Show All Button
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "background_color", QColor("#61ad50"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "background_color_hover", QColor("#6fc65b"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "background_color_hover_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_radius_tl", 7);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_radius_tr", 7);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_radius_bl", 7);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_radius_br", 7);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_color", QColor(Qt::black));

	// Customize Panel -> Show All Button -> Text Label
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button/text_label", "color", QColor("#f8f8f8"));

	// Customize Panel -> Show Primary Button
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "background_color", QColor("#61ad50"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "background_color_hover", QColor("#6fc65b"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "background_color_hover_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_radius_tl", 7);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_radius_tr", 7);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_radius_bl", 7);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_radius_br", 7);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_color", QColor(Qt::black));

	// Customize Panel -> Show Primary Button -> Text Label
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button/text_label", "color", QColor("#f8f8f8"));

	// Customize Panel -> Attribute Widget
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "background_color", QColor("#3e6795"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "secondary_background_color", QColor("#4571a2"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "border_color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_radius_tl", 10);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_radius_tr", 10);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_radius_bl", 10);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_radius_br", 10);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Collapse Button
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic/svg", "use_common_hover_color", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic/svg", "common_color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic/svg", "common_hover_color", QColor("#6aaaf7"));

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic After
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic After -> SVG
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "use_common_hover_color", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "common_color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "common_hover_color", QColor("#6aaaf7"));

	// Customize Panel -> Attribute Widget -> Label
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/label", "color", QColor("#001122"));

	// Customize Panel -> Attribute Widget -> Line Editor
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "background_color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "text_color", QColor("#4571a2"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_radius_tl", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_radius_tr", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_radius_bl", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_radius_br", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Toggle
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Toggle -> Switch
	blue_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "background_color", {
		{ "Untoggled", QColor("#4571a2") },
		{ "Toggled", QColor("#6fc65b") }
		});
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "border_color", {
		{ "Untoggled", QColor("#001122") },
		{ "Toggled", QColor("#6fc65b") }
		});
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "border_thickness", 3);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_radius_tl", 4);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_radius_tr", 4);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_radius_bl", 4);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_radius_br", 4);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Toggle -> Switch -> Square
	blue_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "background_color", {
		{ "Untoggled", QColor("#001122") },
		{ "Toggled", QColor(Qt::white) }
		});
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_radius_tl", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_radius_tr", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_radius_bl", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_radius_br", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Labeled Toggle
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Switch
	blue_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "background_color", {
		{ "Untoggled", QColor("#6fc65b") },
		{ "Toggled", QColor("#6fc65b") }
		});
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "border_color", {
		{ "Untoggled", QColor("#6fc65b") },
		{ "Toggled", QColor("#6fc65b") }
		});
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "border_thickness", 3);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_radius_tl", 4);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_radius_tr", 4);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_radius_bl", 4);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_radius_br", 4);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Switch -> Square
	blue_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "background_color", {
		{ "Untoggled", QColor(Qt::white) },
		{ "Toggled", QColor(Qt::white) }
		});
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_radius_tl", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_radius_tr", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_radius_bl", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_radius_br", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Text
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/text", "color", QColor("#001122"));

	// Customize Panel -> Attribute Widget -> Slider
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Slider -> Bar
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "background_color", QColor("#34557c"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_radius_tl", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_radius_tr", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_radius_bl", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_radius_br", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Slider -> Handle
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "background_color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_radius_tl", 3);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_radius_tr", 3);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_radius_bl", 3);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_radius_br", 3);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Mini Slider
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "background_color", QColor("#6aaaf7"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "border_color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_radius_tl", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_radius_tr", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_radius_bl", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_radius_br", 5);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Mini Slider -> Bar
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "background_color", QColor("#34557c"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_radius_tl", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_radius_tr", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_radius_bl", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_radius_br", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Mini Slider -> Handle
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "background_color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_radius_tl", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_radius_tr", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_radius_bl", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_radius_br", 2);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Example Widget
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "background_color", QColor("#274b73"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "border_color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "corner_color", QColor(Qt::black));

	// Customize Panel -> Element Button
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_color", QColor(Qt::black));

	// Customize Panel -> Element Button -> Graphic
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_color", QColor(Qt::black));

	// Customize Panel -> Element Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic/svg", "use_common_hover_color", true);
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic/svg", "common_color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic/svg", "common_hover_color", QColor("#6aaaf7"));

	// Customize Panel -> Element Button -> Text Label
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/text_label", "color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/text_label", "color_hover", QColor("#6aaaf7"));

	// Gradient Selection Box
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "background_color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "border_gradient_disabled", false);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "border_gradient_disabled", false);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "border_color", QColor("#4571A2"));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "border_thickness", 10);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_radius_tl", 10);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_radius_tr", 10);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_radius_bl", 10);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_radius_br", 10);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "outline_color_disabled", false);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_color", QColor(Qt::black));

	// Gradient Selection Box -> Titlebar
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "background_color", QColor("#253859"));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_radius_tl",
		inner_radius(
			blue_theme.stateless_attribute("layers/gradient_selection_box", "corner_radius_tl")->value().value<int>(),
			blue_theme.stateless_attribute("layers/gradient_selection_box", "border_thickness")->value().value<int>()));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_radius_tr",
		inner_radius(
			blue_theme.stateless_attribute("layers/gradient_selection_box", "corner_radius_tr")->value().value<int>(),
			blue_theme.stateless_attribute("layers/gradient_selection_box", "border_thickness")->value().value<int>()));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_color", QColor(Qt::black));

	// Gradient Selection Box -> Titlebar -> Window Title Label
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/window_title_label", "color", QColor(Qt::lightGray));

	// Gradient Selection Box -> Titlebar -> Exit Button
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_color", QColor(Qt::black));

	// Gradient Selection Box -> Titlebar -> Exit Button -> Graphic
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_color", QColor(Qt::black));

	// Gradient Selection Box -> Titlebar -> Exit Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "use_common_hover_color", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "common_color", QColor("#536c9a"));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "common_hover_color", QColor("#E33034"));

	// Gradient Selection Box -> Apply Button
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "background_color", QColor("#61ad50"));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "background_color_hover", QColor("#6fc65b"));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "background_color_hover_disabled", false);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_radius_tl", 7);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_radius_tr", 7);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_radius_bl", 7);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_radius_br", 7);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_color", QColor(Qt::black));

	// Gradient Selection Box -> Apply Button -> Text Label
	blue_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button/text_label", "color", QColor("#f8f8f8"));

	// Create New Theme Dialog
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "background_color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "border_gradient_disabled", false);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "border_gradient_disabled", false);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "border_color", QColor("#4571A2"));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "border_thickness", 10);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_radius_tl", 10);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_radius_tr", 10);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_radius_bl", 10);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_radius_br", 10);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "outline_color_disabled", false);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Titlebar
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "background_color", QColor("#253859"));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_radius_tl",
		inner_radius(
			blue_theme.stateless_attribute("layers/create_new_theme_dialog", "corner_radius_tl")->value().value<int>(),
			blue_theme.stateless_attribute("layers/create_new_theme_dialog", "border_thickness")->value().value<int>()));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_radius_tr",
		inner_radius(
			blue_theme.stateless_attribute("layers/create_new_theme_dialog", "corner_radius_tr")->value().value<int>(),
			blue_theme.stateless_attribute("layers/create_new_theme_dialog", "border_thickness")->value().value<int>()));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Titlebar -> Window Title Label
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/window_title_label", "color", QColor(Qt::lightGray));

	// Create New Theme Dialog -> Titlebar -> Exit Button
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Titlebar -> Exit Button -> Graphic
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Titlebar -> Exit Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "use_common_hover_color", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "common_color", QColor("#536c9a"));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "common_hover_color", QColor("#E33034"));

	// Create New Theme Dialog -> "Name" Label
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/name_label", "color", QColor("#4571a2"));

	// Create New Theme Dialog -> Theme Name Line Edit
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "background_color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "border_color", QColor("#4571a2"));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "border_thickness", 3);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_radius_tl", 7);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_radius_tr", 7);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_radius_bl", 7);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_radius_br", 7);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "left_padding", 10);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "margin_bottom", 8);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "margin_left", 7);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "margin_right", 8);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "margin_top", 7);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "text_color", QColor("#4571a2"));

	// Create New Theme Dialog -> "Start as copy of" Label
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_as_label", "color", QColor("#4571a2"));

	// Create New Theme Dialog -> Start Theme Combobox
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "background_color", QColor("#4571a2"));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_radius_tl", 7);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_radius_tr", 7);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_radius_bl", 7);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_radius_br", 7);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "line_edit_text_color", QColor("#001122"));

	// Create New Theme Dialog -> Start Theme Combobox -> Current Item Label
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/current_item_label", "color", QColor("#001122"));

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down -> Combobox Items
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "background_color", QColor("#274b73"));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "background_color_hover", QColor("#5d9de8"));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "background_color_hover_disabled", false);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "border_thickness", 0);
	blue_theme.add_stateful_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 7 },
		{ "Top", 7 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	blue_theme.add_stateful_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 7 },
		{ "Top", 7 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	blue_theme.add_stateful_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 7 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 7 }
		});
	blue_theme.add_stateful_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 7 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 7 }
		});
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down -> Combobox Items -> Label
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item/label", "color", QColor("#001122"));

	// Create New Theme Dialog -> Create Button
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "background_color", QColor("#61ad50"));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "background_color_hover", QColor("#6fc65b"));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "background_disabled", false);
	//blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "background_color_hover_disabled", false);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_radius_tl", 7);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_radius_tr", 7);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_radius_bl", 7);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_radius_br", 7);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Create Button -> Text Label
	blue_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button/text_label", "color", QColor("#f8f8f8"));

	// Update Dialog
	blue_theme.add_stateless_attribute("layers/update_dialog", "background_color", QColor("#001122"));
	blue_theme.add_stateless_attribute("layers/update_dialog", "border_gradient_disabled", false);
	blue_theme.add_stateless_attribute("layers/update_dialog", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	blue_theme.add_stateless_attribute("layers/update_dialog", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/update_dialog", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog", "border_gradient_disabled", false);
	blue_theme.add_stateless_attribute("layers/update_dialog", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	blue_theme.add_stateless_attribute("layers/update_dialog", "border_color", QColor("#4571A2"));
	blue_theme.add_stateless_attribute("layers/update_dialog", "border_thickness", 10);
	blue_theme.add_stateless_attribute("layers/update_dialog", "corner_radius_tl", 10);
	blue_theme.add_stateless_attribute("layers/update_dialog", "corner_radius_tr", 10);
	blue_theme.add_stateless_attribute("layers/update_dialog", "corner_radius_bl", 10);
	blue_theme.add_stateless_attribute("layers/update_dialog", "corner_radius_br", 10);
	blue_theme.add_stateless_attribute("layers/update_dialog", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog", "outline_color_disabled", false);
	blue_theme.add_stateless_attribute("layers/update_dialog", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/update_dialog", "corner_color", QColor(Qt::black));

	// Update Dialog -> Titlebar
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar", "background_color", QColor("#253859"));
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar", "background_disabled", false);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_radius_tl",
		inner_radius(
			blue_theme.stateless_attribute("layers/update_dialog", "corner_radius_tl")->value().value<int>(),
			blue_theme.stateless_attribute("layers/update_dialog", "border_thickness")->value().value<int>()));
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_radius_tr",
		inner_radius(
			blue_theme.stateless_attribute("layers/update_dialog", "corner_radius_tr")->value().value<int>(),
			blue_theme.stateless_attribute("layers/update_dialog", "border_thickness")->value().value<int>()));
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_color", QColor(Qt::black));

	// Update Dialog -> Titlebar -> Window Title Label
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/window_title_label", "color", QColor(Qt::lightGray));

	// Update Dialog -> Titlebar -> Exit Button
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_color", QColor(Qt::black));

	// Update Dialog -> Titlebar -> Exit Button -> Graphic
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "background_color", QColor(Qt::white));
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "background_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "background_color_hover_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_radius_tl", 0);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_radius_tr", 0);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_radius_bl", 0);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_radius_br", 0);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_color", QColor(Qt::black));

	// Update Dialog -> Titlebar -> Exit Button -> Graphic -> SVG
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic/svg", "use_common_color", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic/svg", "use_common_hover_color", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic/svg", "common_color", QColor("#536c9a"));
	blue_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic/svg", "common_hover_color", QColor("#E33034"));

	// Update Dialog -> Message Label
	blue_theme.add_stateless_attribute("layers/update_dialog/message_label", "color", QColor("#4571a2"));

	// Update Dialog -> Remind Me Later Button
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "background_color", QColor("#4571a2"));
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "background_color_hover", QColor("#6aaaf7"));
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "background_disabled", false);
	//blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "background_color_hover_disabled", false);
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_radius_tl", 7);
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_radius_tr", 7);
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_radius_bl", 7);
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_radius_br", 7);
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_color", QColor(Qt::black));

	// Update Dialog -> Remind Me Later Button -> Text Label
	blue_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button/text_label", "color", QColor("#001122"));

	// Update Dialog -> Update Button
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "background_color", QColor("#61ad50"));
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "background_color_hover", QColor("#6fc65b"));
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "background_disabled", false);
	//blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "background_color_hover_disabled", false);
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "border_gradient_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "border_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "border_thickness", 0);
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_radius_tl", 7);
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_radius_tr", 7);
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_radius_bl", 7);
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_radius_br", 7);
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "outline_color_disabled", true);
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "outline_color", QColor(Qt::black));
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_color", QColor(Qt::black));

	// Update Dialog -> Update Button -> Text Label
	blue_theme.add_stateless_attribute("layers/update_dialog/update_button/text_label", "color", QColor("#f8f8f8"));

	return blue_theme;
}

Theme Layers::build_layers_dark_theme()
{
	Theme dark_theme("Dark", false);

	QGradientStops border_gradient_stops = { { 0.0, "#6a6a6a" },{ 1.0, "#444444" } };
	QGradientStops default_gradient_stops = { { 0.0, Qt::black },{ 1.0, Qt::white } };

	// Window
	dark_theme.add_stateless_attribute("layers/window", "border_gradient_disabled", false);
	dark_theme.add_stateless_attribute("layers/window", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	dark_theme.add_stateless_attribute("layers/window", "border_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/window", "background_color", QColor("#2e2e2e"));
	dark_theme.add_stateless_attribute("layers/window", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/window", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/window", "corner_radius_tl", 10);
	dark_theme.add_stateless_attribute("layers/window", "corner_radius_tr", 10);
	dark_theme.add_stateless_attribute("layers/window", "corner_radius_bl", 10);
	dark_theme.add_stateless_attribute("layers/window", "corner_radius_br", 10);
	dark_theme.add_stateless_attribute("layers/window", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/window", "border_thickness", 15);
	dark_theme.add_stateless_attribute("layers/window", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/window", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/window", "corner_color", QColor(Qt::black));

	// Titlebar
	dark_theme.add_stateless_attribute("layers/titlebar", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/titlebar", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/titlebar", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/titlebar", "corner_radius_tl", 6);
	dark_theme.add_stateless_attribute("layers/titlebar", "corner_radius_tr", 6);
	dark_theme.add_stateless_attribute("layers/titlebar", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/titlebar", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar", "corner_color", QColor(Qt::black));

	// Titlebar -> Label
	dark_theme.add_stateless_attribute("layers/titlebar/window_title_label", "color", QColor("#e3e3e3"));

	// Titlebar -> Settings Button
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Settings Button -> Graphic
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Settings Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic/svg", "use_common_hover_color", true);
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic/svg", "common_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic/svg", "common_hover_color", QColor("#e3e3e3"));

	// Titlebar -> Minimize Button
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Minimize Button -> Graphic
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Minimize Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic/svg", "use_common_hover_color", true);
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic/svg", "common_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic/svg", "common_hover_color", QColor("#e3e3e3"));

	// Titlebar -> Maximize Button
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Maximize Button -> Graphic
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Maximize Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic/svg", "use_common_hover_color", true);
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic/svg", "common_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic/svg", "common_hover_color", QColor("#e3e3e3"));

	// Titlebar -> Exit Button
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Exit Button -> Graphic
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Exit Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic/svg", "use_common_hover_color", true);
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic/svg", "common_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic/svg", "common_hover_color", QColor("#E33034"));

	// Titlebar -> Menu Label Layers
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "background_color", QColor("#363636"));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_radius_tl", 10);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_radius_tr", 10);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_radius_bl", 10);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_radius_br", 10);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_color", QColor(Qt::black));

	// Titlebar -> Menu Label Layers -> Back Button
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Menu Label Layers -> Back Button -> Graphic
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Menu Label Layers -> Back Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "use_common_hover_color", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "common_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "common_hover_color", QColor("#e3e3e3"));

	// Titlebar -> Menu Label Layers -> Icon Button
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Menu Label Layers -> Icon Button -> Graphic
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Menu Label Layers -> Icon Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic/svg", "use_common_hover_color", false);
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic/svg", "common_color", QColor("#e3e3e3"));

	// Titlebar -> Menu Label Layers -> Text Label
	dark_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/text_label", "color", QColor("#e3e3e3"));

	// Settings Menu
	dark_theme.add_stateless_attribute("layers/settings_menu", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/settings_menu", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu", "corner_color", QColor(Qt::black));

	// Settings Menu -> Sidebar
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar", "background_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_color", QColor(Qt::black));

	// Settings Menu -> Sidebar -> App Preferences Settings Tab
	dark_theme.add_stateful_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "background_color", {
		{ "Unselected", QColor("#6a6a6a") },
		{ "Selected", QColor("#2e2e2e") }
		});
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_radius_tl", 5);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_radius_bl", 5);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_color", QColor("#2e2e2e"));

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Icon
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_color", QColor(Qt::black));

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Icon -> SVG
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon/svg", "use_common_hover_color", false);
	dark_theme.add_stateful_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon/svg", "common_color", {
		{ "Unselected", QColor("#2e2e2e") },
		{ "Selected", QColor("#6a6a6a") }
		});

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Text Label
	dark_theme.add_stateful_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/text_label", "color", {
		{ "Unselected", QColor("#2e2e2e") },
		{ "Selected", QColor("#6a6a6a") }
		});

	// Settings Menu -> Sidebar -> Themes Settings Tab
	dark_theme.add_stateful_attribute("layers/settings_menu/sidebar/themes_settings_tab", "background_color", {
		{ "Unselected", QColor("#6a6a6a") },
		{ "Selected", QColor("#2e2e2e") }
		});
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_radius_tl", 5);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_radius_bl", 5);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_color", QColor("#2e2e2e"));

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Icon
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_color", QColor(Qt::black));

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Icon -> SVG
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon/svg", "use_common_hover_color", false);
	dark_theme.add_stateful_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon/svg", "common_color", {
		{ "Unselected", QColor("#2e2e2e") },
		{ "Selected", QColor("#6a6a6a") }
		});

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Text Label
	dark_theme.add_stateful_attribute("layers/settings_menu/sidebar/themes_settings_tab/text_label", "color", {
		{ "Unselected", QColor("#2e2e2e") },
		{ "Selected", QColor("#6a6a6a") }
		});

	// Settings Menu -> App Preferences Settings Panel
	dark_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> "Theme" Label
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_label", "color", QColor("#6a6a6a"));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "background_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_radius_tl", 10);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_radius_tr", 10);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_radius_bl", 10);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_radius_br", 10);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "line_edit_text_color", QColor("#2e2e2e"));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Current Item Label
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/current_item_label", "color", QColor("#2e2e2e"));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down -> Combobox Items
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "background_color", QColor("#959595"));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "background_color_hover", QColor("#f3f3f3"));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "background_color_hover_disabled", false);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "border_thickness", 0);
	dark_theme.add_stateful_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	dark_theme.add_stateful_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	dark_theme.add_stateful_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	dark_theme.add_stateful_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down -> Combobox Items -> Label
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item/label", "color", QColor("#2e2e2e"));

	// Settings Menu -> Themes Settings Panel -> Separators
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "background_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> New Theme Button
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> New Theme Button -> Graphic
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> New Theme Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "use_common_hover_color", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "common_color", QColor("#6fc654"));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "common_hover_color", QColor("#8cfa6a"));

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button -> Graphic
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "use_common_hover_color", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "common_color", QColor("#c3c3c3"));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "common_hover_color", QColor("#e6e6e6"));

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button -> Graphic
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "use_common_hover_color", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "common_color", QColor("#e95454"));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "common_hover_color", QColor("#ff7f7f"));

	// Settings Menu -> Themes Settings Panel -> Theme Info Button
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Theme Info Button -> Graphic
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Theme Info Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic/svg", "use_common_hover_color", false);
	dark_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic/svg", "common_color", QColor("#6a6a6a"));

	// Customize Menu
	dark_theme.add_stateless_attribute("layers/customize_menu", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/customize_menu", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu", "corner_color", QColor(Qt::black));

	// Customize Menu -> Arrow Graphic
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_color", QColor(Qt::black));

	// Customize Menu -> Arrow Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic/svg", "use_common_hover_color", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic/svg", "common_color", QColor("#2e2e2e"));

	// Customize Menu -> Label Button
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_color", QColor(Qt::black));

	// Customize Menu -> Label Button -> Text Label
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button/text_label", "color", QColor("#2e2e2e"));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button/text_label", "color_hover", QColor("#e1e1e1"));

	// Customize Menu -> Sidebar
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar", "background_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar", "background_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_radius_tr", 10);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_radius_br", 10);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar -> Collapsed Button
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "background_color", QColor("#e1e1e1"));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "background_color_hover", QColor("#6fc65b"));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_radius_tl", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_radius_tr", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_radius_bl", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_radius_br", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar -> Collapsed Button -> Graphic
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar -> Collapsed Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic/svg", "use_common_hover_color", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic/svg", "common_color", QColor("#2e2e2e"));

	// Customize Menu -> Topbar -> Collapsed Widget
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "background_color", QColor("#959595"));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "background_color_hover", QColor("#6fc65b"));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_radius_tl", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_radius_tr", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_radius_bl", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_radius_br", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar -> Apply Button
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "background_color", QColor("#61ad50"));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "background_color_hover", QColor("#6fc65b"));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "background_color_hover_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_radius_tl", 7);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_radius_tr", 7);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_radius_bl", 7);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_radius_br", 7);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar -> Apply Button -> Text Label
	dark_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button/text_label", "color", QColor("#f8f8f8"));

	// Customize Panel
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_color", QColor(Qt::black));

	// Customize Panel -> Stateful Attributes Label
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/stateful_attributes_label", "color", QColor("#e1e1e1"));

	// Customize Panel -> Stateless Attributes Label
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/stateless_attributes_label", "color", QColor("#e1e1e1"));

	// Customize Panel -> Attributes Label
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attributes_label", "color", QColor("#e1e1e1"));

	// Customize Panel -> Elements Label
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/elements_label", "color", QColor("#e1e1e1"));

	// Customize Panel -> States Label
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/states_label", "color", QColor("#e1e1e1"));

	// Customize Panel -> State Combobox
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "background_color", QColor("#2e2e2e"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_radius_tl", 10);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_radius_tr", 10);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_radius_bl", 10);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_radius_br", 10);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "line_edit_text_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_color", QColor(Qt::black));

	// Customize Panel -> State Combobox -> Current Item Label
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/current_item_label", "color", QColor("#6a6a6a"));

	// Customize Panel -> State Combobox -> Drop Down
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_color", QColor(Qt::black));

	// Customize Panel -> State Combobox -> Drop Down -> Combobox Item
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "background_color", QColor("#959595"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "background_color_hover", QColor("#f3f3f3"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "background_color_hover_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "border_thickness", 0);
	dark_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	dark_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	dark_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	dark_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_color", QColor(Qt::black));

	// Customize Panel -> State Combobox -> Drop Down -> Combobox Item -> Label
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item/label", "color", QColor("#2e2e2e"));

	// Customize Panel -> Show All Button
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "background_color", QColor("#61ad50"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "background_color_hover", QColor("#6fc65b"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "background_color_hover_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_radius_tl", 7);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_radius_tr", 7);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_radius_bl", 7);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_radius_br", 7);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_color", QColor(Qt::black));

	// Customize Panel -> Show All Button -> Text Label
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button/text_label", "color", QColor("#f8f8f8"));

	// Customize Panel -> Show Primary Button
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "background_color", QColor("#61ad50"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "background_color_hover", QColor("#6fc65b"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "background_color_hover_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_radius_tl", 7);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_radius_tr", 7);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_radius_bl", 7);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_radius_br", 7);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_color", QColor(Qt::black));

	// Customize Panel -> Show Primary Button -> Text Label
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button/text_label", "color", QColor("#f8f8f8"));

	// Customize Panel -> Attribute Widget
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "background_color", QColor("#5b5b5b"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "secondary_background_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "border_color", QColor("#2e2e2e"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_radius_tl", 10);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_radius_tr", 10);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_radius_bl", 10);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_radius_br", 10);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Collapse Button
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic/svg", "use_common_hover_color", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic/svg", "common_color", QColor("#2e2e2e"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic/svg", "common_hover_color", QColor("#e1e1e1"));

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic After
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic After -> SVG
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "use_common_hover_color", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "common_color", QColor("#2e2e2e"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "common_hover_color", QColor("#e1e1e1"));

	// Customize Panel -> Attribute Widget -> Label
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/label", "color", QColor("#2e2e2e"));

	// Customize Panel -> Attribute Widget -> Line Editor
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "background_color", QColor("#2e2e2e"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "text_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_radius_tl", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_radius_tr", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_radius_bl", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_radius_br", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Toggle
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Toggle -> Switch
	dark_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "background_color", {
		{ "Untoggled", QColor("#6a6a6a") },
		{ "Toggled", QColor("#6fc65b") }
		});
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "border_color", {
		{ "Untoggled", QColor("#2e2e2e") },
		{ "Toggled", QColor("#6fc65b") }
		});
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "border_thickness", 3);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_radius_tl", 4);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_radius_tr", 4);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_radius_bl", 4);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_radius_br", 4);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Toggle -> Switch -> Square
	dark_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "background_color", {
		{ "Untoggled", QColor("#2e2e2e") },
		{ "Toggled", QColor(Qt::white) }
		});
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_radius_tl", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_radius_tr", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_radius_bl", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_radius_br", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Labeled Toggle
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Switch
	dark_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "background_color", {
		{ "Untoggled", QColor("#6fc65b") },
		{ "Toggled", QColor("#6fc65b") }
		});
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "border_color", {
		{ "Untoggled", QColor("#6fc65b") },
		{ "Toggled", QColor("#6fc65b") }
		});
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "border_thickness", 3);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_radius_tl", 4);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_radius_tr", 4);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_radius_bl", 4);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_radius_br", 4);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Switch -> Square
	dark_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "background_color", {
		{ "Untoggled", QColor(Qt::white) },
		{ "Toggled", QColor(Qt::white) }
		});
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_radius_tl", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_radius_tr", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_radius_bl", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_radius_br", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Text
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/text", "color", QColor("#2e2e2e"));

	// Customize Panel -> Attribute Widget -> Slider
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Slider -> Bar
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "background_color", QColor("#7c7c7c"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_radius_tl", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_radius_tr", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_radius_bl", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_radius_br", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Slider -> Handle
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "background_color", QColor("#2e2e2e"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_radius_tl", 3);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_radius_tr", 3);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_radius_bl", 3);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_radius_br", 3);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Mini Slider
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "background_color", QColor("#e1e1e1"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_radius_tl", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_radius_tr", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_radius_bl", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_radius_br", 5);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Mini Slider -> Bar
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "background_color", QColor("#7c7c7c"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_radius_tl", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_radius_tr", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_radius_bl", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_radius_br", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Mini Slider -> Handle
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "background_color", QColor("#2e2e2e"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_radius_tl", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_radius_tr", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_radius_bl", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_radius_br", 2);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Example Widget
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "background_color", QColor("#989898"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "corner_color", QColor(Qt::black));

	// Customize Panel -> Element Button
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_color", QColor(Qt::black));

	// Customize Panel -> Element Button -> Graphic
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_color", QColor(Qt::black));

	// Customize Panel -> Element Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic/svg", "use_common_hover_color", true);
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic/svg", "common_color", QColor("#2e2e2e"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic/svg", "common_hover_color", QColor("#e1e1e1"));

	// Customize Panel -> Element Button -> Text Label
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/text_label", "color", QColor("#2e2e2e"));
	dark_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/text_label", "color_hover", QColor("#e1e1e1"));

	// Gradient Selection Box
	dark_theme.add_stateless_attribute("layers/gradient_selection_box", "background_color", QColor("#444444"));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box", "border_gradient_disabled", false);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box", "border_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box", "border_thickness", 10);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_radius_tl", 10);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_radius_tr", 10);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_radius_bl", 10);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_radius_br", 10);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box", "outline_color_disabled", false);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_color", QColor(Qt::black));

	// Gradient Selection Box -> Titlebar
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "background_color", QColor("#363636"));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_radius_tl",
		inner_radius(
			dark_theme.stateless_attribute("layers/gradient_selection_box", "corner_radius_tl")->value().value<int>(),
			dark_theme.stateless_attribute("layers/gradient_selection_box", "border_thickness")->value().value<int>()));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_radius_tr",
		inner_radius(
			dark_theme.stateless_attribute("layers/gradient_selection_box", "corner_radius_tr")->value().value<int>(),
			dark_theme.stateless_attribute("layers/gradient_selection_box", "border_thickness")->value().value<int>()));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_color", QColor(Qt::black));

	// Gradient Selection Box -> Titlebar -> Window Title Label
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/window_title_label", "color", QColor("#e3e3e3"));

	// Gradient Selection Box -> Titlebar -> Exit Button
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_color", QColor(Qt::black));

	// Gradient Selection Box -> Titlebar -> Exit Button -> Graphic
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_color", QColor(Qt::black));

	// Gradient Selection Box -> Titlebar -> Exit Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "use_common_hover_color", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "common_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "common_hover_color", QColor("#E33034"));

	// Gradient Selection Box -> Apply Button
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "background_color", QColor("#61ad50"));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "background_color_hover", QColor("#6fc65b"));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "background_color_hover_disabled", false);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_radius_tl", 7);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_radius_tr", 7);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_radius_bl", 7);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_radius_br", 7);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_color", QColor(Qt::black));

	// Gradient Selection Box -> Apply Button -> Text Label
	dark_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button/text_label", "color", QColor("#f8f8f8"));

	// Create New Theme Dialog
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog", "background_color", QColor("#2e2e2e"));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog", "border_gradient_disabled", false);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog", "border_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog", "border_thickness", 10);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_radius_tl", 10);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_radius_tr", 10);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_radius_bl", 10);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_radius_br", 10);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog", "outline_color_disabled", false);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Titlebar
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "background_color", QColor("#363636"));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_radius_tl",
		inner_radius(
			dark_theme.stateless_attribute("layers/create_new_theme_dialog", "corner_radius_tl")->value().value<int>(),
			dark_theme.stateless_attribute("layers/create_new_theme_dialog", "border_thickness")->value().value<int>()));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_radius_tr",
		inner_radius(
			dark_theme.stateless_attribute("layers/create_new_theme_dialog", "corner_radius_tr")->value().value<int>(),
			dark_theme.stateless_attribute("layers/create_new_theme_dialog", "border_thickness")->value().value<int>()));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Titlebar -> Window Title Label
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/window_title_label", "color", QColor("#e3e3e3"));

	// Create New Theme Dialog -> Titlebar -> Exit Button
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Titlebar -> Exit Button -> Graphic
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Titlebar -> Exit Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "use_common_hover_color", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "common_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "common_hover_color", QColor("#E33034"));

	// Create New Theme Dialog -> "Name" Label
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/name_label", "color", QColor("#6a6a6a"));

	// Create New Theme Dialog -> Theme Name Line Edit
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "background_color", QColor("#2e2e2e"));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "border_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "border_thickness", 3);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_radius_tl", 7);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_radius_tr", 7);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_radius_bl", 7);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_radius_br", 7);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "left_padding", 10);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "margin_bottom", 8);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "margin_left", 7);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "margin_right", 8);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "margin_top", 7);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "text_color", QColor("#6a6a6a"));

	// Create New Theme Dialog -> "Start as copy of" Label
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_as_label", "color", QColor("#6a6a6a"));

	// Create New Theme Dialog -> Start Theme Combobox
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "background_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_radius_tl", 7);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_radius_tr", 7);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_radius_bl", 7);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_radius_br", 7);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "line_edit_text_color", QColor("#2e2e2e"));

	// Create New Theme Dialog -> Start Theme Combobox -> Current Item Label
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/current_item_label", "color", QColor("#2e2e2e"));

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down -> Combobox Items
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "background_color", QColor("#959595"));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "background_color_hover", QColor("#f3f3f3"));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "background_color_hover_disabled", false);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "border_thickness", 0);
	dark_theme.add_stateful_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 7 },
		{ "Top", 7 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	dark_theme.add_stateful_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 7 },
		{ "Top", 7 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	dark_theme.add_stateful_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 7 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 7 }
		});
	dark_theme.add_stateful_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 7 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 7 }
		});
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down -> Combobox Items -> Label
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item/label", "color", QColor("#2e2e2e"));

	// Create New Theme Dialog -> Create Button
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "background_color", QColor("#61ad50"));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "background_color_hover", QColor("#6fc65b"));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "background_disabled", false);
	//dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "background_color_hover_disabled", false);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_radius_tl", 7);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_radius_tr", 7);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_radius_bl", 7);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_radius_br", 7);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Create Button -> Text Label
	dark_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button/text_label", "color", QColor("#f8f8f8"));

	// Update Dialog
	dark_theme.add_stateless_attribute("layers/update_dialog", "background_color", QColor("#2e2e2e"));
	dark_theme.add_stateless_attribute("layers/update_dialog", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/update_dialog", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog", "border_gradient_disabled", false);
	dark_theme.add_stateless_attribute("layers/update_dialog", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	dark_theme.add_stateless_attribute("layers/update_dialog", "border_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/update_dialog", "border_thickness", 10);
	dark_theme.add_stateless_attribute("layers/update_dialog", "corner_radius_tl", 10);
	dark_theme.add_stateless_attribute("layers/update_dialog", "corner_radius_tr", 10);
	dark_theme.add_stateless_attribute("layers/update_dialog", "corner_radius_bl", 10);
	dark_theme.add_stateless_attribute("layers/update_dialog", "corner_radius_br", 10);
	dark_theme.add_stateless_attribute("layers/update_dialog", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog", "outline_color_disabled", false);
	dark_theme.add_stateless_attribute("layers/update_dialog", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/update_dialog", "corner_color", QColor(Qt::black));

	// Update Dialog -> Titlebar
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar", "background_color", QColor("#363636"));
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar", "background_disabled", false);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_radius_tl",
		inner_radius(
			dark_theme.stateless_attribute("layers/update_dialog", "corner_radius_tl")->value().value<int>(),
			dark_theme.stateless_attribute("layers/update_dialog", "border_thickness")->value().value<int>()));
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_radius_tr",
		inner_radius(
			dark_theme.stateless_attribute("layers/update_dialog", "corner_radius_tr")->value().value<int>(),
			dark_theme.stateless_attribute("layers/update_dialog", "border_thickness")->value().value<int>()));
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_color", QColor(Qt::black));

	// Update Dialog -> Titlebar -> Window Title Label
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/window_title_label", "color", QColor("#e3e3e3"));

	// Update Dialog -> Titlebar -> Exit Button
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_color", QColor(Qt::black));

	// Update Dialog -> Titlebar -> Exit Button -> Graphic
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "background_color", QColor(Qt::white));
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "background_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "background_color_hover_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_radius_tl", 0);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_radius_tr", 0);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_radius_bl", 0);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_radius_br", 0);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_color", QColor(Qt::black));

	// Update Dialog -> Titlebar -> Exit Button -> Graphic -> SVG
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic/svg", "use_common_color", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic/svg", "use_common_hover_color", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic/svg", "common_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic/svg", "common_hover_color", QColor("#E33034"));

	// Update Dialog -> Message Label
	dark_theme.add_stateless_attribute("layers/update_dialog/message_label", "color", QColor("#6a6a6a"));

	// Update Dialog -> Remind Me Later Button
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "background_color", QColor("#6a6a6a"));
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "background_color_hover", QColor("#989898"));
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "background_disabled", false);
	//dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "background_color_hover_disabled", false);
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_radius_tl", 7);
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_radius_tr", 7);
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_radius_bl", 7);
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_radius_br", 7);
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_color", QColor(Qt::black));

	// Update Dialog -> Remind Me Later Button -> Text Label
	dark_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button/text_label", "color", QColor("#2e2e2e"));

	// Update Dialog -> Update Button
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "background_color", QColor("#61ad50"));
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "background_color_hover", QColor("#6fc65b"));
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "background_disabled", false);
	//dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "background_color_hover_disabled", false);
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "border_gradient_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "border_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "border_thickness", 0);
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_radius_tl", 7);
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_radius_tr", 7);
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_radius_bl", 7);
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_radius_br", 7);
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "outline_color_disabled", true);
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "outline_color", QColor(Qt::black));
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_color", QColor(Qt::black));

	// Update Dialog -> Update Button -> Text Label
	dark_theme.add_stateless_attribute("layers/update_dialog/update_button/text_label", "color", QColor("#f8f8f8"));

	return dark_theme;
}

Theme Layers::build_layers_light_theme()
{
	Theme light_theme("Light", false);

	QGradientStops border_gradient_stops = { { 0.0, Qt::lightGray },{ 1.0, Qt::white } };
	QGradientStops default_gradient_stops = { { 0.0, Qt::black },{ 1.0, Qt::white } };

	// Window Border
	light_theme.add_stateless_attribute("layers/window", "border_gradient_disabled", false);
	light_theme.add_stateless_attribute("layers/window", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	light_theme.add_stateless_attribute("layers/window", "border_color", QColor(Qt::lightGray));
	light_theme.add_stateless_attribute("layers/window", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/window", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/window", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/window", "corner_radius_tl", 10);
	light_theme.add_stateless_attribute("layers/window", "corner_radius_tr", 10);
	light_theme.add_stateless_attribute("layers/window", "corner_radius_bl", 10);
	light_theme.add_stateless_attribute("layers/window", "corner_radius_br", 10);
	light_theme.add_stateless_attribute("layers/window", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/window", "border_thickness", 15);
	light_theme.add_stateless_attribute("layers/window", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/window", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/window", "corner_color", QColor(Qt::black));

	// Titlebar
	light_theme.add_stateless_attribute("layers/titlebar", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/titlebar", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/titlebar", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/titlebar", "corner_radius_tl", 6);
	light_theme.add_stateless_attribute("layers/titlebar", "corner_radius_tr", 6);
	light_theme.add_stateless_attribute("layers/titlebar", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/titlebar", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/titlebar", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar", "corner_color", QColor(Qt::black));

	// Titlebar -> Window Title Label
	light_theme.add_stateless_attribute("layers/titlebar/window_title_label", "color", QColor("#2e2e2e"));

	// Titlebar -> Settings Button
	light_theme.add_stateless_attribute("layers/titlebar/settings_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/titlebar/settings_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/titlebar/settings_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/settings_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/settings_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Settings Button -> Graphic
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Settings Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic/svg", "common_color", QColor("#c5c5c5"));
	light_theme.add_stateless_attribute("layers/titlebar/settings_button/graphic/svg", "common_hover_color", QColor("#6a6a6a"));

	// Titlebar -> Minimize Button
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Minimize Button -> Graphic
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Minimize Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic/svg", "common_color", QColor("#c5c5c5"));
	light_theme.add_stateless_attribute("layers/titlebar/minimize_button/graphic/svg", "common_hover_color", QColor("#6a6a6a"));

	// Titlebar -> Maximize Button
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Maximize Button -> Graphic
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Maximize Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic/svg", "common_color", QColor("#c5c5c5"));
	light_theme.add_stateless_attribute("layers/titlebar/maximize_button/graphic/svg", "common_hover_color", QColor("#6a6a6a"));

	// Titlebar -> Exit Button
	light_theme.add_stateless_attribute("layers/titlebar/exit_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/titlebar/exit_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/titlebar/exit_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/exit_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/exit_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Exit Button -> Graphic
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Exit Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic/svg", "common_color", QColor("#c5c5c5"));
	light_theme.add_stateless_attribute("layers/titlebar/exit_button/graphic/svg", "common_hover_color", QColor("#f25557"));

	// Titlebar -> Menu Label Layers
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "background_color", QColor("#e1e1e1"));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_radius_tl", 10);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_radius_tr", 10);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_radius_bl", 10);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_radius_br", 10);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer", "corner_color", QColor(Qt::black));

	// Titlebar -> Menu Label Layers -> Back Button
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Menu Label Layers -> Back Button -> Graphic
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Menu Label Layers -> Back Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "common_color", QColor("#858585"));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/back_button/graphic/svg", "common_hover_color", QColor("#2e2e2e"));

	// Titlebar -> Menu Label Layers -> Icon Button
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button", "corner_color", QColor(Qt::black));

	// Titlebar -> Menu Label Layers -> Icon Button -> Graphic
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic", "corner_color", QColor(Qt::black));

	// Titlebar -> Menu Label Layers -> Icon Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic/svg", "use_common_hover_color", false);
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/icon_button/graphic/svg", "common_color", QColor("#2e2e2e"));

	// Titlebar -> Menu Label Layers -> Text Label
	light_theme.add_stateless_attribute("layers/titlebar/menu_label_layer/text_label", "color", QColor("#2e2e2e"));

	// Settings Menu
	light_theme.add_stateless_attribute("layers/settings_menu", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/settings_menu", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu", "corner_color", QColor(Qt::black));

	// Settings Menu -> Sidebar
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar", "background_color", QColor(Qt::lightGray));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar", "corner_color", QColor(Qt::black));

	// Settings Menu -> Sidebar -> App Preferences Settings Tab
	light_theme.add_stateful_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "background_color", {
		{ "Unselected", QColor(Qt::lightGray) },
		{ "Selected", QColor(Qt::white) }
		});
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_radius_tl", 5);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_radius_bl", 5);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab", "corner_color", QColor("#2e2e2e"));

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Icon
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_radius_tl", 5);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_radius_bl", 5);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", "corner_color", QColor(Qt::black));


	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Icon -> SVG
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon/svg", "use_common_hover_color", false);
	light_theme.add_stateful_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/icon/svg", "common_color", {
		{ "Unselected", QColor("#5d5d5d") },
		{ "Selected", QColor("#2e2e2e") }
		});

	// Settings Menu -> Sidebar -> App Preferences Settings Tab -> Text Label
	light_theme.add_stateful_attribute("layers/settings_menu/sidebar/app_preferences_settings_tab/text_label", "color", {
		{ "Unselected", QColor("#5d5d5d") },
		{ "Selected", QColor("#2e2e2e") }
		});

	// Settings Menu -> Sidebar -> Themes Settings Tab
	light_theme.add_stateful_attribute("layers/settings_menu/sidebar/themes_settings_tab", "background_color", {
		{ "Unselected", QColor(Qt::lightGray) },
		{ "Selected", QColor(Qt::white) }
		});
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_radius_tl", 5);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_radius_bl", 5);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab", "corner_color", QColor("#2e2e2e"));

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Icon
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_radius_tl", 5);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_radius_bl", 5);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon", "corner_color", QColor(Qt::black));


	// Settings Menu -> Sidebar -> Themes Settings Tab -> Icon -> SVG
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon/svg", "use_common_hover_color", false);
	light_theme.add_stateful_attribute("layers/settings_menu/sidebar/themes_settings_tab/icon/svg", "common_color", {
		{ "Unselected", QColor("#5d5d5d") },
		{ "Selected", QColor("#2e2e2e") }
		});

	// Settings Menu -> Sidebar -> Themes Settings Tab -> Text Label
	light_theme.add_stateful_attribute("layers/settings_menu/sidebar/themes_settings_tab/text_label", "color", {
		{ "Unselected", QColor("#5d5d5d") },
		{ "Selected", QColor("#2e2e2e") }
		});

	// Settings Menu -> App Preferences Settings Panel
	light_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/app_preferences_settings_panel", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> "Theme" Label
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_label", "color", QColor("#2e2e2e"));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "background_color", QColor(Qt::lightGray));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_radius_tl", 10);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_radius_tr", 10);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_radius_bl", 10);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_radius_br", 10);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "corner_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox", "line_edit_text_color", QColor("#5d5d5d"));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Current Item Label
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/current_item_label", "color", QColor("#5d5d5d"));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down -> Combobox Items
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "background_color", QColor("#d6d6d6"));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "background_color_hover", QColor("#ededed"));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "background_color_hover_disabled", false);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "border_thickness", 0);
	light_theme.add_stateful_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	light_theme.add_stateful_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	light_theme.add_stateful_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	light_theme.add_stateful_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Theme Combobox -> Drop Down -> Combobox Items -> Label
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item/label", "color", QColor("#2e2e2e"));

	// Settings Menu -> Themes Settings Panel -> Separators
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "background_color", QColor(Qt::lightGray));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/separator", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> New Theme Button
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> New Theme Button -> Graphic
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> New Theme Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "common_color", QColor("#6fc654"));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", "common_hover_color", QColor("#8cfa6a"));

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button -> Graphic
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Customize Theme Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "common_color", QColor("#c3c3c3"));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", "common_hover_color", QColor("#e6e6e6"));

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button -> Graphic
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Delete Theme Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "common_color", QColor("#e95454"));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", "common_hover_color", QColor("#ff7f7f"));

	// Settings Menu -> Themes Settings Panel -> Theme Info Button
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Theme Info Button -> Graphic
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", "corner_color", QColor(Qt::black));

	// Settings Menu -> Themes Settings Panel -> Theme Info Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic/svg", "use_common_hover_color", false);
	light_theme.add_stateless_attribute("layers/settings_menu/themes_settings_panel/theme_info_button/graphic/svg", "common_color", QColor("#6a6a6a"));

	// Customize Menu
	light_theme.add_stateless_attribute("layers/customize_menu", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/customize_menu", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/customize_menu", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu", "corner_color", QColor(Qt::black));

	// Customize Menu -> Arrow Graphic
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic", "corner_color", QColor(Qt::black));

	// Customize Menu -> Arrow Graphic -> SVG
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/arrow_graphic/svg", "common_color", QColor("#2e2e2e"));

	// Customize Menu -> Label Button
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button", "corner_color", QColor(Qt::black));

	// Customize Menu -> Label Button -> Text Label
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button/text_label", "color", QColor("#2e2e2e"));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/text_button/text_label", "color_hover", QColor(Qt::white));

	// Customize Menu -> Sidebar
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar", "background_color", QColor(Qt::lightGray));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar
	light_theme.add_stateless_attribute("layers/customize_menu/topbar", "background_color", QColor(Qt::lightGray));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_radius_tr", 10);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_radius_br", 10);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar -> Collapsed Button
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "background_color_hover", QColor("#6fc65b"));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_radius_tl", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_radius_tr", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_radius_bl", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_radius_br", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar -> Collapsed Button -> Graphic
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar -> Collapsed Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_button/graphic/svg", "common_color", QColor("#2e2e2e"));

	// Customize Menu -> Topbar -> Collapsed Widget
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "background_color", QColor("#d6d6d6"));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "background_color_hover", QColor("#6fc65b"));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_radius_tl", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_radius_tr", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_radius_bl", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_radius_br", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/collapsed_widget", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar -> Apply Button
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "background_color", QColor("#61ad50"));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "background_color_hover", QColor("#6fc65b"));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "background_color_hover_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_radius_tl", 7);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_radius_tr", 7);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_radius_bl", 7);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_radius_br", 7);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button", "corner_color", QColor(Qt::black));

	// Customize Menu -> Topbar -> Apply Button -> Text Label
	light_theme.add_stateless_attribute("layers/customize_menu/topbar/apply_button/text_label", "color", QColor("#f8f8f8"));

	// Customize Panel
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel", "corner_color", QColor(Qt::black));

	// Customize Panel -> Stateful Attributes Label
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/stateful_attributes_label", "color", QColor(Qt::white));

	// Customize Panel -> Stateless Attributes Label
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/stateless_attributes_label", "color", QColor(Qt::white));

	// Customize Panel -> Attributes Label
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attributes_label", "color", QColor(Qt::white));

	// Customize Panel -> Elements Label
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/elements_label", "color", QColor(Qt::white));

	// Customize Panel -> States Label
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/states_label", "color", QColor(Qt::white));

	// Customize Panel -> State Combobox
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_radius_tl", 10);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_radius_tr", 10);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_radius_bl", 10);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_radius_br", 10);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "line_edit_text_color", QColor(Qt::gray));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox", "corner_color", QColor(Qt::black));

	// Customize Panel -> State Combobox -> Current Item Label
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/current_item_label", "color", QColor(Qt::gray));

	// Customize Panel -> State Combobox -> Drop Down
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down", "corner_color", QColor(Qt::black));

	// Customize Panel -> State Combobox -> Drop Down -> Combobox Item
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "background_color", QColor("#d6d6d6"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "background_color_hover", QColor("#ededed"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "background_color_hover_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "border_thickness", 0);
	light_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	light_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 10 },
		{ "Top", 10 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	light_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	light_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 10 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 10 }
		});
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item", "corner_color", QColor(Qt::black));

	// Customize Panel -> State Combobox -> Drop Down -> Combobox Item -> Label
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/state_combobox/drop_down/combobox_item/label", "color", QColor("#2e2e2e"));

	// Customize Panel -> Show All Button
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "background_color", QColor("#61ad50"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "background_color_hover", QColor("#6fc65b"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "background_color_hover_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_radius_tl", 7);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_radius_tr", 7);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_radius_bl", 7);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_radius_br", 7);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button", "corner_color", QColor(Qt::black));

	// Customize Panel -> Show All Button -> Text Label
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_all_button/text_label", "color", QColor("#f8f8f8"));

	// Customize Panel -> Show Primary Button
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "background_color", QColor("#61ad50"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "background_color_hover", QColor("#6fc65b"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "background_color_hover_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_radius_tl", 7);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_radius_tr", 7);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_radius_bl", 7);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_radius_br", 7);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button", "corner_color", QColor(Qt::black));

	// Customize Panel -> Show Primary Button -> Text Label
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/show_primary_button/text_label", "color", QColor("#f8f8f8"));

	// Customize Panel -> Attribute Widget
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "background_color", QColor("#a6a6a6"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "secondary_background_color", QColor(Qt::lightGray));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "border_color", QColor("#2e2e2e"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_radius_tl", 10);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_radius_tr", 10);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_radius_bl", 10);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_radius_br", 10);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Collapse Button
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic/svg", "common_color", QColor("#2e2e2e"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic/svg", "common_hover_color", QColor(Qt::white));

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic After
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Collapse Button -> Graphic After -> SVG
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "common_color", QColor("#2e2e2e"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/collapse_button/graphic_after/svg", "common_hover_color", QColor(Qt::white));

	// Customize Panel -> Attribute Widget -> Label
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/label", "color", QColor("#2e2e2e"));

	// Customize Panel -> Attribute Widget -> Line Editor
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "background_color", QColor("#2e2e2e"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "text_color", QColor(Qt::lightGray));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_radius_tl", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_radius_tr", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_radius_bl", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_radius_br", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/line_editor", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Toggle
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Toggle -> Switch
	light_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "background_color", {
		{ "Untoggled", QColor(Qt::lightGray) },
		{ "Toggled", QColor("#6fc65b") }
		});
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "border_color", {
		{ "Untoggled", QColor("#2e2e2e") },
		{ "Toggled", QColor("#6fc65b") }
		});
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "border_thickness", 3);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_radius_tl", 4);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_radius_tr", 4);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_radius_bl", 4);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_radius_br", 4);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Toggle -> Switch -> Square
	light_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "background_color", {
		{ "Untoggled", QColor("#2e2e2e") },
		{ "Toggled", QColor(Qt::white) }
		});
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_radius_tl", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_radius_tr", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_radius_bl", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_radius_br", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/toggle/switch/square", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Labeled Toggle
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Switch
	light_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "background_color", {
		{ "Untoggled", QColor("#6fc65b") },
		{ "Toggled", QColor("#6fc65b") }
		});
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "border_color", {
		{ "Untoggled", QColor("#6fc65b") },
		{ "Toggled", QColor("#6fc65b") }
		});
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "border_thickness", 3);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_radius_tl", 4);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_radius_tr", 4);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_radius_bl", 4);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_radius_br", 4);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Switch -> Square
	light_theme.add_stateful_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "background_color", {
		{ "Untoggled", QColor(Qt::white) },
		{ "Toggled", QColor(Qt::white) }
		});
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_radius_tl", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_radius_tr", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_radius_bl", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_radius_br", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/switch/square", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Labeled Toggle -> Text
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/labeled_toggle/text", "color", QColor("#2e2e2e"));

	// Customize Panel -> Attribute Widget -> Slider
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Slider -> Bar
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "background_color", QColor("#7c7c7c"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_radius_tl", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_radius_tr", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_radius_bl", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_radius_br", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/bar", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Slider -> Handle
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "background_color", QColor("#2e2e2e"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_radius_tl", 3);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_radius_tr", 3);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_radius_bl", 3);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_radius_br", 3);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/slider/handle", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Mini Slider
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_radius_tl", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_radius_tr", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_radius_bl", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_radius_br", 5);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Mini Slider -> Bar
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "background_color", QColor("#7c7c7c"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_radius_tl", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_radius_tr", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_radius_bl", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_radius_br", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/bar", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Mini Slider -> Handle
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "background_color", QColor("#2e2e2e"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_radius_tl", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_radius_tr", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_radius_bl", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_radius_br", 2);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/mini_slider/handle", "corner_color", QColor(Qt::black));

	// Customize Panel -> Attribute Widget -> Example Widget
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "background_color", QColor("#7c7c7c"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/attribute_widget/example_widget", "corner_color", QColor(Qt::black));

	// Customize Panel -> Element Button
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button", "corner_color", QColor(Qt::black));

	// Customize Panel -> Element Button -> Graphic
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic", "corner_color", QColor(Qt::black));

	// Customize Panel -> Element Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic/svg", "common_color", QColor("#2e2e2e"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/graphic/svg", "common_hover_color", QColor(Qt::white));

	// Customize Panel -> Element Button -> Text Label
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/text_label", "color", QColor("#2e2e2e"));
	light_theme.add_stateless_attribute("layers/customize_menu/sidebar/customize_panel/element_button/text_label", "color_hover", QColor(Qt::white));

	// Gradient Selection Box
	light_theme.add_stateless_attribute("layers/gradient_selection_box", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/gradient_selection_box", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/gradient_selection_box", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box", "border_gradient_disabled", false);
	light_theme.add_stateless_attribute("layers/gradient_selection_box", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	light_theme.add_stateless_attribute("layers/gradient_selection_box", "border_color", QColor(Qt::lightGray));
	light_theme.add_stateless_attribute("layers/gradient_selection_box", "border_thickness", 10);
	light_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_radius_tl", 10);
	light_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_radius_tr", 10);
	light_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_radius_bl", 10);
	light_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_radius_br", 10);
	light_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box", "outline_color_disabled", false);
	light_theme.add_stateless_attribute("layers/gradient_selection_box", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/gradient_selection_box", "corner_color", QColor(Qt::black));

	// Gradient Selection Box -> Titlebar
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "background_color", QColor("#e1e1e1"));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_radius_tl",
		inner_radius(
			light_theme.stateless_attribute("layers/gradient_selection_box", "corner_radius_tl")->value().value<int>(),
			light_theme.stateless_attribute("layers/gradient_selection_box", "border_thickness")->value().value<int>()));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_radius_tr",
		inner_radius(
			light_theme.stateless_attribute("layers/gradient_selection_box", "corner_radius_tr")->value().value<int>(),
			light_theme.stateless_attribute("layers/gradient_selection_box", "border_thickness")->value().value<int>()));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar", "corner_color", QColor(Qt::black));

	// Gradient Selection Box -> Titlebar -> Window Title Label
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/window_title_label", "color", QColor("#2e2e2e"));

	// Gradient Selection Box -> Titlebar -> Exit Button
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button", "corner_color", QColor(Qt::black));

	// Gradient Selection Box -> Titlebar -> Exit Button -> Graphic
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic", "corner_color", QColor(Qt::black));

	// Gradient Selection Box -> Titlebar -> Exit Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "common_color", QColor("#c5c5c5"));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/titlebar/exit_button/graphic/svg", "common_hover_color", QColor("#f25557"));

	// Gradient Selection Box -> Apply Button
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "background_color", QColor("#61ad50"));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "background_color_hover", QColor("#6fc65b"));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "background_color_hover_disabled", false);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_radius_tl", 7);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_radius_tr", 7);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_radius_bl", 7);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_radius_br", 7);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button", "corner_color", QColor(Qt::black));

	// Gradient Selection Box -> Apply Button -> Text Label
	light_theme.add_stateless_attribute("layers/gradient_selection_box/apply_button/text_label", "color", QColor("#f8f8f8"));

	// Create New Theme Dialog
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog", "border_gradient_disabled", false);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog", "border_color", QColor(Qt::lightGray));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog", "border_thickness", 10);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_radius_tl", 10);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_radius_tr", 10);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_radius_bl", 10);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_radius_br", 10);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog", "outline_color_disabled", false);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Titlebar
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "background_color", QColor("#e1e1e1"));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_radius_tl",
		inner_radius(
			light_theme.stateless_attribute("layers/create_new_theme_dialog", "corner_radius_tl")->value().value<int>(),
			light_theme.stateless_attribute("layers/create_new_theme_dialog", "border_thickness")->value().value<int>()));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_radius_tr",
		inner_radius(
			light_theme.stateless_attribute("layers/create_new_theme_dialog", "corner_radius_tr")->value().value<int>(),
			light_theme.stateless_attribute("layers/create_new_theme_dialog", "border_thickness")->value().value<int>()));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Titlebar -> Window Title Label
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/window_title_label", "color", QColor("#2e2e2e"));

	// Create New Theme Dialog -> Titlebar -> Exit Button
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Titlebar -> Exit Button -> Graphic
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Titlebar -> Exit Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "common_color", QColor("#c5c5c5"));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", "common_hover_color", QColor("#f25557"));

	// Create New Theme Dialog -> "Name" Label
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/name_label", "color", QColor("#2e2e2e"));

	// Create New Theme Dialog -> Theme Name Line Edit
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "border_color", QColor(Qt::lightGray));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "border_thickness", 3);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_radius_tl", 7);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_radius_tr", 7);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_radius_bl", 7);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_radius_br", 7);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "left_padding", 10);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "margin_bottom", 8);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "margin_left", 7);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "margin_right", 8);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "margin_top", 7);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "corner_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/theme_name_line_edit", "text_color", QColor("#2e2e2e"));

	// Create New Theme Dialog -> "Start as copy of" Label
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_as_label", "color", QColor("#2e2e2e"));

	// Create New Theme Dialog -> Start Theme Combobox
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "background_color", QColor(Qt::lightGray));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_radius_tl", 7);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_radius_tr", 7);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_radius_bl", 7);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_radius_br", 7);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "corner_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox", "line_edit_text_color", QColor("#5d5d5d"));

	// Create New Theme Dialog -> Start Theme Combobox -> Current Item Label
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/current_item_label", "color", QColor("#5d5d5d"));

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down -> Combobox Items
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "background_color", QColor("#d6d6d6"));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "background_color_hover", QColor("#ededed"));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "background_color_hover_disabled", false);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "border_thickness", 0);
	light_theme.add_stateful_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_tl", {
		{ "Single", 7 },
		{ "Top", 7 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	light_theme.add_stateful_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_tr", {
		{ "Single", 7 },
		{ "Top", 7 },
		{ "Middle", 0 },
		{ "Bottom", 0 }
		});
	light_theme.add_stateful_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_bl", {
		{ "Single", 7 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 7 }
		});
	light_theme.add_stateful_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_radius_br", {
		{ "Single", 7 },
		{ "Top", 0 },
		{ "Middle", 0 },
		{ "Bottom", 7 }
		});
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Start Theme Combobox -> Drop Down -> Combobox Items -> Label
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item/label", "color", QColor("#2e2e2e"));

	// Create New Theme Dialog -> Create Button
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "background_color", QColor("#61ad50"));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "background_color_hover", QColor("#6fc65b"));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "background_disabled", false);
	//light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "background_color_hover_disabled", false);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_radius_tl", 7);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_radius_tr", 7);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_radius_bl", 7);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_radius_br", 7);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button", "corner_color", QColor(Qt::black));

	// Create New Theme Dialog -> Create Button -> Text Label
	light_theme.add_stateless_attribute("layers/create_new_theme_dialog/create_button/text_label", "color", QColor("#f8f8f8"));

	// Update Dialog
	light_theme.add_stateless_attribute("layers/update_dialog", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/update_dialog", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/update_dialog", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog", "border_gradient_disabled", false);
	light_theme.add_stateless_attribute("layers/update_dialog", "border_gradient_stops", QVariant::fromValue(border_gradient_stops));
	light_theme.add_stateless_attribute("layers/update_dialog", "border_color", QColor(Qt::lightGray));
	light_theme.add_stateless_attribute("layers/update_dialog", "border_thickness", 10);
	light_theme.add_stateless_attribute("layers/update_dialog", "corner_radius_tl", 10);
	light_theme.add_stateless_attribute("layers/update_dialog", "corner_radius_tr", 10);
	light_theme.add_stateless_attribute("layers/update_dialog", "corner_radius_bl", 10);
	light_theme.add_stateless_attribute("layers/update_dialog", "corner_radius_br", 10);
	light_theme.add_stateless_attribute("layers/update_dialog", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog", "outline_color_disabled", false);
	light_theme.add_stateless_attribute("layers/update_dialog", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/update_dialog", "corner_color", QColor(Qt::black));

	// Update Dialog -> Titlebar
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar", "background_color", QColor("#e1e1e1"));
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar", "background_disabled", false);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_radius_tl",
		inner_radius(
			light_theme.stateless_attribute("layers/update_dialog", "corner_radius_tl")->value().value<int>(),
			light_theme.stateless_attribute("layers/update_dialog", "border_thickness")->value().value<int>()));
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_radius_tr",
		inner_radius(
			light_theme.stateless_attribute("layers/update_dialog", "corner_radius_tr")->value().value<int>(),
			light_theme.stateless_attribute("layers/update_dialog", "border_thickness")->value().value<int>()));
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar", "corner_color", QColor(Qt::black));

	// Update Dialog -> Titlebar -> Window Title Label
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/window_title_label", "color", QColor("#2e2e2e"));

	// Update Dialog -> Titlebar -> Exit Button
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button", "corner_color", QColor(Qt::black));

	// Update Dialog -> Titlebar -> Exit Button -> Graphic
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "background_color", QColor(Qt::white));
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "background_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "background_color_hover_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_radius_tl", 0);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_radius_tr", 0);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_radius_bl", 0);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_radius_br", 0);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic", "corner_color", QColor(Qt::black));

	// Update Dialog -> Titlebar -> Exit Button -> Graphic -> SVG
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic/svg", "use_common_color", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic/svg", "use_common_hover_color", true);
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic/svg", "common_color", QColor("#c5c5c5"));
	light_theme.add_stateless_attribute("layers/update_dialog/titlebar/exit_button/graphic/svg", "common_hover_color", QColor("#f25557"));

	// Update Dialog -> Message Label
	light_theme.add_stateless_attribute("layers/update_dialog/message_label", "color", QColor("#2e2e2e"));

	// Update Dialog -> Remind Me Later Button
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "background_color", QColor("#c0c0c0"));
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "background_color_hover", QColor("#e4e4e4"));
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "background_disabled", false);
	//light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "background_color_hover_disabled", false);
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_radius_tl", 7);
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_radius_tr", 7);
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_radius_bl", 7);
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_radius_br", 7);
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button", "corner_color", QColor(Qt::black));

	// Update Dialog -> Remind Me Later Button -> Text Label
	light_theme.add_stateless_attribute("layers/update_dialog/remind_me_later_button/text_label", "color", QColor("#2e2e2e"));

	// Update Dialog -> Update Button
	light_theme.add_stateless_attribute("layers/update_dialog/update_button", "background_color", QColor("#61ad50"));
	light_theme.add_stateless_attribute("layers/update_dialog/update_button", "background_color_hover", QColor("#6fc65b"));
	light_theme.add_stateless_attribute("layers/update_dialog/update_button", "background_disabled", false);
	//light_theme.add_stateless_attribute("layers/update_dialog/update_button", "background_color_hover_disabled", false);
	light_theme.add_stateless_attribute("layers/update_dialog/update_button", "border_gradient_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/update_button", "border_gradient_stops", QVariant::fromValue(default_gradient_stops));
	light_theme.add_stateless_attribute("layers/update_dialog/update_button", "border_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/update_dialog/update_button", "border_thickness", 0);
	light_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_radius_tl", 7);
	light_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_radius_tr", 7);
	light_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_radius_bl", 7);
	light_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_radius_br", 7);
	light_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_color_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/update_button", "outline_color_disabled", true);
	light_theme.add_stateless_attribute("layers/update_dialog/update_button", "outline_color", QColor(Qt::black));
	light_theme.add_stateless_attribute("layers/update_dialog/update_button", "corner_color", QColor(Qt::black));

	// Update Dialog -> Update Button -> Text Label
	light_theme.add_stateless_attribute("layers/update_dialog/update_button/text_label", "color", QColor("#f8f8f8"));

	return light_theme;
}
