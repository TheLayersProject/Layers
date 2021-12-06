#include "../../include/build_themes.h"
#include "../../include/calculate.h"
#include "../../include/Theme.h"

#include <QGradientStops>

using Layers::Theme;

Theme Layers::build_layers_blue_theme()
{
	Theme blue_theme = Theme("Blue", false);

	blue_theme.add_attributes("layers/window", {
		{ "border_fill", new Attribute("Border Fill", QVariant::fromValue(QGradientStops({ { 0.0, "#4571a2" },{ 1.0, "#001122" } }))) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(15)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#001122")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/titlebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/titlebar/window_title_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor(Qt::lightGray)) }
		});

	blue_theme.add_attributes("layers/titlebar/settings_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/titlebar/settings_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/titlebar/settings_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#536c9a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6a8ac3")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/titlebar/minimize_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/titlebar/minimize_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/titlebar/minimize_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#536c9a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6a8ac3")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/titlebar/maximize_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/titlebar/maximize_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/titlebar/maximize_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#536c9a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6a8ac3")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/titlebar/exit_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/titlebar/exit_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/titlebar/exit_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#536c9a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#E33034")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/titlebar/menu_label_layer", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#253859")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/titlebar/menu_label_layer/back_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/titlebar/menu_label_layer/back_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/titlebar/menu_label_layer/back_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#5884d2")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#659dff")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/titlebar/menu_label_layer/icon_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/titlebar/menu_label_layer/icon_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/titlebar/menu_label_layer/icon_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#5e96da")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#5e96da")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/titlebar/menu_label_layer/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#5e96da")) }
		});

	blue_theme.add_attributes("layers/settings_menu", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/sidebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#4571a2")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/sidebar/app_preferences_settings_tab", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", {
			{ "Unselected", QColor("#4571a2") },
			{ "Selected", QColor("#001122") }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/sidebar/app_preferences_settings_tab/icon/svg", {
		{ "common_color", new Attribute("Common Color", {
			{ "Unselected", QColor("#001122") },
			{ "Selected", QColor("#4571a2") }
			}) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6a8ac3")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/settings_menu/sidebar/app_preferences_settings_tab/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", {
			{ "Unselected", QColor("#001122") },
			{ "Selected", QColor("#4571a2") }
			}) }
		});

	blue_theme.add_attributes("layers/settings_menu/sidebar/themes_settings_tab", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", {
			{ "Unselected", QColor("#4571a2") },
			{ "Selected", QColor("#001122") }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/sidebar/themes_settings_tab/icon", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/sidebar/themes_settings_tab/icon/svg", {
		{ "common_color", new Attribute("Common Color", {
			{ "Unselected", QColor("#001122") },
			{ "Selected", QColor("#4571a2") }
			}) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6a8ac3")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/settings_menu/sidebar/themes_settings_tab/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", {
			{ "Unselected", QColor("#001122") },
			{ "Selected", QColor("#4571a2") }
			}) }
		});

	blue_theme.add_attributes("layers/settings_menu/app_preferences_settings_panel", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#4571a2")) }
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_combobox", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#4571a2")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_combobox/current_item_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#001122")) }
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", {
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
			}) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", {
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
			}) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", {
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
			}) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", {
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
			}) },
		{ "fill", new Attribute("Fill", QColor("#274b73")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#5d9de8")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#001122")) }
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/separator", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#4571a2")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/new_theme_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#43ad3f")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#82ff7b")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/customize_theme_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#c3c3c3")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#e6e6e6")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/delete_theme_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#ae3f3f")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#e95454")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_info_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_info_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#4571a2")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#4571a2")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(false)) }
		});

	blue_theme.add_attributes("layers/customize_menu", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/topbar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#4571a2")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/topbar/apply_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(7)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(7)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/topbar/apply_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#6aaaf7"), true) }
		});

	blue_theme.add_attributes("layers/customize_menu/topbar/arrow_graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/topbar/arrow_graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#001122")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#001122")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(false)) }
		});

	blue_theme.add_attributes("layers/customize_menu/topbar/collapse_menu", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#274b73")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/topbar/collapse_menu_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#6aaaf7")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(10)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(10)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/topbar/collapse_menu_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/topbar/collapse_menu_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#001122")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#001122")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(false)) }
		});

	blue_theme.add_attributes("layers/customize_menu/topbar/text_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/topbar/text_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#001122")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#6aaaf7")) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#4571a2")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/attributes_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#6aaaf7")) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/widgets_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#6aaaf7")) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/color_aw", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#1A000000")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/color_aw/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#001122")) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/color_aw/toggle_switch", {
		{ "border_fill", new Attribute("Border Fill", {
			{ "Untoggled", QColor("#001122") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(3)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(4)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor("#4571a2") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(12)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(12)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/color_aw/toggle_switch/square", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor("#001122") },
			{ "Toggled", QColor(Qt::white) }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#1A000000")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#001122")) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/toggle_switch", {
		{ "border_fill", new Attribute("Border Fill", {
			{ "Untoggled", QColor("#001122") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(3)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(4)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor("#4571a2") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(12)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(12)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/toggle_switch/square", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor("#001122") },
			{ "Toggled", QColor(Qt::white) }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control", {
		{ "border_fill", new Attribute("Border Fill", QColor("#D6D6D6")) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(2)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor(Qt::black)) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(10)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(10)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(10)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(10)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control/dialog", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(4)) },
		{ "fill", new Attribute("Fill", QColor("#243d59")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control/dialog/vertical_toggle_switch", {
		{ "border_fill", new Attribute("Border Fill", {
			{ "Untoggled", QColor("#6fc65b") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(3)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(4)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor("#6fc65b") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(12)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(12)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(12)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(12)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control/dialog/vertical_toggle_switch/square", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor(Qt::white) },
			{ "Toggled", QColor(Qt::white) }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control/dialog/color_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#5a93d3")) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control/dialog/gradient_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#5a93d3")) }
		});
	
	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#1A000000")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/collapse_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/collapse_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/collapse_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#001122")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6aaaf7")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/collapse_button/graphic_after", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/collapse_button/graphic_after/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#001122")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6aaaf7")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#001122")) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#1A000000")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/collapse_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/collapse_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/collapse_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#001122")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6aaaf7")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/collapse_button/graphic_after", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/collapse_button/graphic_after/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#001122")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6aaaf7")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#001122")) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/mini_slider", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#6aaaf7")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/mini_slider/bar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", QColor("#34557c")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(5)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(5)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/mini_slider/handle", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", QColor("#001122")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/line_editor", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#001122")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(7)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(7)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(8)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(8)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		{ "text_color", new Attribute("Text Color", QColor("#4571a2")) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/example_widget", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#274b73")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#1A000000")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#001122")) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw/mini_slider", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#6aaaf7")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(5)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(5)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw/mini_slider/bar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", QColor("#34557c")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(5)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(5)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw/mini_slider/handle", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", QColor("#001122")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw/line_editor", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#001122")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(7)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(7)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(8)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(8)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		{ "text_color", new Attribute("Text Color", QColor("#4571a2")) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/show_all_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(7)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(7)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/show_all_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#6aaaf7"), true) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/show_primary_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(7)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(7)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/show_primary_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#f8f8f8"), true) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/widget_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/widget_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/widget_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#001122")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6aaaf7")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/widget_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#001122")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#6aaaf7")) }
		});
		
	blue_theme.add_attributes("layers/create_new_theme_dialog", {
		{ "border_fill", new Attribute("Border Fill", QVariant::fromValue(QGradientStops({ { 0.0, "#4571a2" },{ 1.0, "#001122" } }))) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(10)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#001122")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black)) },
		});
		
	blue_theme.add_attributes("layers/create_new_theme_dialog/titlebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#253859")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/create_new_theme_dialog/titlebar/exit_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/create_new_theme_dialog/titlebar/exit_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#536c9a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#E33034")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/create_new_theme_dialog/titlebar/window_title_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor(Qt::lightGray)) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::lightGray), true) }
		});

	blue_theme.add_attributes("layers/create_new_theme_dialog/name_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#4571a2")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#4571a2"), true) }
		});

	blue_theme.add_attributes("layers/create_new_theme_dialog/start_as_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#4571a2")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#4571a2"), true) }
		});

	blue_theme.add_attributes("layers/create_new_theme_dialog/start_theme_combobox", {
	{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
	{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
	{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
	{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
	{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
	{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
	{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
	{ "fill", new Attribute("Fill", QColor("#4571a2")) },
	{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
	{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
	{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
	{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
	{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
	{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/create_new_theme_dialog/start_theme_combobox/current_item_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#001122")) }
		});

	blue_theme.add_attributes("layers/create_new_theme_dialog/start_theme_combobox/drop_down", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", {
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
			}) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", {
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
			}) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", {
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
			}) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", {
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
			}) },
		{ "fill", new Attribute("Fill", QColor("#274b73")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#5d9de8")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#001122")) }
		});

	blue_theme.add_attributes("layers/create_new_theme_dialog/theme_name_line_edit", {
	{ "border_fill", new Attribute("Border Fill", QColor("#4571a2")) },
	{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(3)) },
	{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
	{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
	{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
	{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
	{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
	{ "fill", new Attribute("Fill", QColor("#001122"), true) },
	{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) }, 
	{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
	{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
	{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
	{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
	{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
	{ "text_color", new Attribute("Text Color", QColor("#4571a2")) }
	});

	blue_theme.add_attributes("layers/create_new_theme_dialog/create_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(4)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(6)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(4)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(6)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/create_new_theme_dialog/create_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#f8f8f8"), true) }
		});

	blue_theme.add_attributes("layers/gradient_selection_dialog", {
		{ "border_fill", new Attribute("Border Fill", QVariant::fromValue(QGradientStops({ { 0.0, "#4571a2" },{ 1.0, "#001122" } }))) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(10)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#001122")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black)) },
		});

	blue_theme.add_attributes("layers/gradient_selection_dialog/titlebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#253859")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/gradient_selection_dialog/titlebar/exit_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/gradient_selection_dialog/titlebar/exit_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/gradient_selection_dialog/titlebar/exit_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#536c9a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#E33034")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/gradient_selection_dialog/titlebar/window_title_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor(Qt::lightGray)) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::lightGray), true) }
		});

	blue_theme.add_attributes("layers/gradient_selection_dialog/apply_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(4)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(6)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(4)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(6)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/gradient_selection_dialog/apply_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#f8f8f8"), true) }
		});

	blue_theme.add_attributes("layers/update_dialog", {
		{ "border_fill", new Attribute("Border Fill", QVariant::fromValue(QGradientStops({ { 0.0, "#4571a2" },{ 1.0, "#001122" } }))) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(10)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#001122")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black)) },
		});

	blue_theme.add_attributes("layers/update_dialog/titlebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#253859")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/update_dialog/titlebar/exit_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/update_dialog/titlebar/exit_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/update_dialog/titlebar/exit_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#536c9a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#E33034")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	blue_theme.add_attributes("layers/update_dialog/titlebar/window_title_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor(Qt::lightGray)) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::lightGray), true) }
		});

	blue_theme.add_attributes("layers/update_dialog/message_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#4571a2")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#4571a2"), true) }
		});

	blue_theme.add_attributes("layers/update_dialog/remind_me_later_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#4571a2")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6aaaf7")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/update_dialog/remind_me_later_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#001122")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#001122"), true) }
		});

	blue_theme.add_attributes("layers/update_dialog/update_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	blue_theme.add_attributes("layers/update_dialog/update_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#f8f8f8"), true) }
		});

	return blue_theme;
}

Theme Layers::build_layers_dark_theme()
{
	Theme dark_theme = Theme("Dark", false);

	dark_theme.add_attributes("layers/window", {
		{ "border_fill", new Attribute("Border Fill", QVariant::fromValue(QGradientStops({ { 0.0, "#6a6a6a" },{ 1.0, "#444444" } }))) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(15)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#2e2e2e")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/titlebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/titlebar/window_title_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#e3e3e3")) }
		});

	dark_theme.add_attributes("layers/titlebar/settings_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/titlebar/settings_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/titlebar/settings_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#6a6a6a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#e3e3e3")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/titlebar/minimize_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/titlebar/minimize_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/titlebar/minimize_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#6a6a6a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#e3e3e3")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/titlebar/maximize_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/titlebar/maximize_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/titlebar/maximize_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#6a6a6a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#e3e3e3")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/titlebar/exit_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/titlebar/exit_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/titlebar/exit_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#6a6a6a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#E33034")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/titlebar/menu_label_layer", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#363636")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/titlebar/menu_label_layer/back_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/titlebar/menu_label_layer/back_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/titlebar/menu_label_layer/back_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#6a6a6a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#e3e3e3")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/titlebar/menu_label_layer/icon_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/titlebar/menu_label_layer/icon_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/titlebar/menu_label_layer/icon_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#e3e3e3")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#e3e3e3")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/titlebar/menu_label_layer/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#e3e3e3")) }
		});

	dark_theme.add_attributes("layers/settings_menu", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/sidebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#6a6a6a")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/sidebar/app_preferences_settings_tab", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", {
			{ "Unselected", QColor("#6a6a6a") },
			{ "Selected", QColor("#2e2e2e") }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/sidebar/app_preferences_settings_tab/icon/svg", {
		{ "common_color", new Attribute("Common Color", {
			{ "Unselected", QColor("#2e2e2e") },
			{ "Selected", QColor("#6a6a6a") }
			}) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6a8ac3")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/settings_menu/sidebar/app_preferences_settings_tab/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", {
			{ "Unselected", QColor("#2e2e2e") },
			{ "Selected", QColor("#6a6a6a") }
			}) }
		});

	dark_theme.add_attributes("layers/settings_menu/sidebar/themes_settings_tab", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", {
			{ "Unselected", QColor("#6a6a6a") },
			{ "Selected", QColor("#2e2e2e") }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/sidebar/themes_settings_tab/icon", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/sidebar/themes_settings_tab/icon/svg", {
		{ "common_color", new Attribute("Common Color", {
			{ "Unselected", QColor("#2e2e2e") },
			{ "Selected", QColor("#6a6a6a") }
			}) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6a8ac3")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/settings_menu/sidebar/themes_settings_tab/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", {
			{ "Unselected", QColor("#2e2e2e") },
			{ "Selected", QColor("#6a6a6a") }
			}) }
		});

	dark_theme.add_attributes("layers/settings_menu/app_preferences_settings_panel", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#6a6a6a")) }
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_combobox", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#6a6a6a")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_combobox/current_item_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", {
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
			}) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", {
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
			}) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", {
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
			}) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", {
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
			}) },
		{ "fill", new Attribute("Fill", QColor("#959595")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#f3f3f3")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/separator", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#6a6a6a")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/new_theme_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#6fc654")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#8cfa6a")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/customize_theme_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#c3c3c3")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#e6e6e6")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/delete_theme_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#e95454")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#ff7f7f")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_info_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_info_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#6a6a6a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6a6a6a")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(false)) }
		});

	dark_theme.add_attributes("layers/customize_menu", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/topbar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#6a6a6a")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/topbar/apply_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(7)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(7)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/topbar/apply_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#6aaaf7"), true) }
		});

	dark_theme.add_attributes("layers/customize_menu/topbar/arrow_graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/topbar/arrow_graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#2e2e2e")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#2e2e2e")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(false)) }
		});

	dark_theme.add_attributes("layers/customize_menu/topbar/collapse_menu", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#959595")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/topbar/collapse_menu_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#e1e1e1")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(10)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(10)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/topbar/collapse_menu_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/topbar/collapse_menu_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#2e2e2e")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#2e2e2e")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(false)) }
		});

	dark_theme.add_attributes("layers/customize_menu/topbar/text_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/topbar/text_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#e1e1e1")) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#6a6a6a")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/attributes_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#e1e1e1")) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/widgets_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#e1e1e1")) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/color_aw", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#1A000000")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/color_aw/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/color_aw/toggle_switch", {
		{ "border_fill", new Attribute("Border Fill", {
			{ "Untoggled", QColor("#2e2e2e") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(3)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(4)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor("#6a6a6a") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(12)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(12)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/color_aw/toggle_switch/square", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor("#2e2e2e") },
			{ "Toggled", QColor(Qt::white) }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#1A000000")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/toggle_switch", {
		{ "border_fill", new Attribute("Border Fill", {
			{ "Untoggled", QColor("#2e2e2e") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(3)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(4)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor("#6a6a6a") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(12)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(12)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/toggle_switch/square", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor("#2e2e2e") },
			{ "Toggled", QColor(Qt::white) }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control", {
		{ "border_fill", new Attribute("Border Fill", QColor("#D6D6D6")) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(2)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor(Qt::black)) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(10)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(10)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(10)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(10)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control/dialog", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(4)) },
		{ "fill", new Attribute("Fill", QColor("#404040")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control/dialog/vertical_toggle_switch", {
		{ "border_fill", new Attribute("Border Fill", {
			{ "Untoggled", QColor("#6fc65b") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(3)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(4)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor("#6fc65b") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(12)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(12)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(12)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(12)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control/dialog/vertical_toggle_switch/square", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor(Qt::white) },
			{ "Toggled", QColor(Qt::white) }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control/dialog/color_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#e1e1e1")) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control/dialog/gradient_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#e1e1e1")) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#1A000000")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/collapse_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/collapse_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/collapse_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#2e2e2e")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#e1e1e1")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/collapse_button/graphic_after", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/collapse_button/graphic_after/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#2e2e2e")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#e1e1e1")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#1A000000")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/collapse_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/collapse_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/collapse_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#2e2e2e")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#e1e1e1")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/collapse_button/graphic_after", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/collapse_button/graphic_after/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#2e2e2e")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#e1e1e1")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/mini_slider", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#e1e1e1")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/mini_slider/bar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", QColor("#7c7c7c")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(5)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(5)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/mini_slider/handle", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", QColor("#2e2e2e")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/line_editor", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#2e2e2e")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(7)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(7)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(8)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(8)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		{ "text_color", new Attribute("Text Color", QColor("#6a6a6a")) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/example_widget", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#989898")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#1A000000")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw/mini_slider", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#e1e1e1")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(5)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(5)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw/mini_slider/bar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", QColor("#7c7c7c")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(5)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(5)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw/mini_slider/handle", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", QColor("#2e2e2e")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw/line_editor", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#2e2e2e")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(7)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(7)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(8)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(8)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		{ "text_color", new Attribute("Text Color", QColor("#6a6a6a")) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/show_all_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(7)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(7)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/show_all_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#6aaaf7"), true) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/show_primary_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(7)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(7)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/show_primary_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#f8f8f8"), true) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/widget_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/widget_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/widget_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#2e2e2e")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#e1e1e1")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/widget_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#e1e1e1")) }
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog", {
		{ "border_fill", new Attribute("Border Fill", QVariant::fromValue(QGradientStops({ { 0.0, "#6a6a6a" },{ 1.0, "#444444" } }))) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(10)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#2e2e2e")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black)) },
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog/titlebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#363636")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog/titlebar/exit_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog/titlebar/exit_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#6a6a6a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#E33034")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog/titlebar/window_title_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor(Qt::lightGray)) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#e3e3e3"), true) }
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog/name_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#6a6a6a")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#6a6a6a"), true) }
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog/start_as_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#6a6a6a")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#6a6a6a"), true) }
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog/start_theme_combobox", {
	{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
	{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
	{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
	{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
	{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
	{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
	{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
	{ "fill", new Attribute("Fill", QColor("#6a6a6a")) },
	{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
	{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
	{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
	{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
	{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
	{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog/start_theme_combobox/current_item_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog/start_theme_combobox/drop_down", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", {
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
			}) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", {
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
			}) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", {
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
			}) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", {
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
			}) },
		{ "fill", new Attribute("Fill", QColor("#959595")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#f3f3f3")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog/theme_name_line_edit", {
		{ "border_fill", new Attribute("Border Fill", QColor("#6a6a6a")) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(3)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#2e2e2e"), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		{ "text_color", new Attribute("Text Color", QColor("#6a6a6a")) }
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog/create_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(4)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(6)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(4)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(6)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/create_new_theme_dialog/create_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#f8f8f8"), true) }
		});

	dark_theme.add_attributes("layers/gradient_selection_dialog", {
		{ "border_fill", new Attribute("Border Fill", QVariant::fromValue(QGradientStops({ { 0.0, "#6a6a6a" },{ 1.0, "#444444" } }))) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(10)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#2e2e2e")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black)) },
		});

	dark_theme.add_attributes("layers/gradient_selection_dialog/titlebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#363636")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/gradient_selection_dialog/titlebar/exit_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/gradient_selection_dialog/titlebar/exit_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/gradient_selection_dialog/titlebar/exit_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#6a6a6a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#E33034")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/gradient_selection_dialog/titlebar/window_title_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor(Qt::lightGray)) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#e3e3e3"), true) }
		});

	dark_theme.add_attributes("layers/gradient_selection_dialog/apply_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(4)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(6)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(4)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(6)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/gradient_selection_dialog/apply_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#f8f8f8"), true) }
		});

	dark_theme.add_attributes("layers/update_dialog", {
		{ "border_fill", new Attribute("Border Fill", QVariant::fromValue(QGradientStops({ { 0.0, "#6a6a6a" },{ 1.0, "#444444" } }))) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(10)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#2e2e2e")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black)) },
		});

	dark_theme.add_attributes("layers/update_dialog/titlebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#363636")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/update_dialog/titlebar/exit_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/update_dialog/titlebar/exit_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/update_dialog/titlebar/exit_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#6a6a6a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#E33034")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	dark_theme.add_attributes("layers/update_dialog/titlebar/window_title_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor(Qt::lightGray)) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#e3e3e3"), true) }
		});

	dark_theme.add_attributes("layers/update_dialog/message_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor(Qt::lightGray)) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#e3e3e3"), true) }
		});

	dark_theme.add_attributes("layers/update_dialog/remind_me_later_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#6a6a6a")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#989898")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/update_dialog/remind_me_later_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#2e2e2e"), true) }
		});

	dark_theme.add_attributes("layers/update_dialog/update_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	dark_theme.add_attributes("layers/update_dialog/update_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#f8f8f8"), true) }
		});

	return dark_theme;
}

Theme Layers::build_layers_light_theme()
{
	Theme light_theme = Theme("Light", false);

	light_theme.add_attributes("layers/window", {
		{ "border_fill", new Attribute("Border Fill", QVariant::fromValue(QGradientStops({ { 0.0, Qt::lightGray },{ 1.0, Qt::white } }))) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(15)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white)) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/titlebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/titlebar/window_title_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	light_theme.add_attributes("layers/titlebar/settings_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/titlebar/settings_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/titlebar/settings_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#c5c5c5")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6a6a6a")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/titlebar/minimize_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/titlebar/minimize_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/titlebar/minimize_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#c5c5c5")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6a6a6a")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/titlebar/maximize_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/titlebar/maximize_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/titlebar/maximize_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#c5c5c5")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6a6a6a")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/titlebar/exit_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/titlebar/exit_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/titlebar/exit_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#c5c5c5")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#E33034")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/titlebar/menu_label_layer", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#e1e1e1")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/titlebar/menu_label_layer/back_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/titlebar/menu_label_layer/back_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/titlebar/menu_label_layer/back_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#858585")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#2e2e2e")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/titlebar/menu_label_layer/icon_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/titlebar/menu_label_layer/icon_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/titlebar/menu_label_layer/icon_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#2e2e2e")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#2e2e2e")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/titlebar/menu_label_layer/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	light_theme.add_attributes("layers/settings_menu", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/sidebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::lightGray)) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/sidebar/app_preferences_settings_tab", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", {
			{ "Unselected", QColor(Qt::lightGray) },
			{ "Selected", QColor(Qt::white) }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/sidebar/app_preferences_settings_tab/icon", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/sidebar/app_preferences_settings_tab/icon/svg", {
		{ "common_color", new Attribute("Common Color", {
			{ "Unselected", QColor("#5d5d5d") },
			{ "Selected", QColor("#2e2e2e") }
			}) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6a8ac3")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/settings_menu/sidebar/app_preferences_settings_tab/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", {
			{ "Unselected", QColor("#5d5d5d") },
			{ "Selected", QColor("#2e2e2e") }
			}) }
		});

	light_theme.add_attributes("layers/settings_menu/sidebar/themes_settings_tab", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", {
			{ "Unselected", QColor(Qt::lightGray) },
			{ "Selected", QColor(Qt::white) }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/sidebar/themes_settings_tab/icon", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/sidebar/themes_settings_tab/icon/svg", {
		{ "common_color", new Attribute("Common Color", {
			{ "Unselected", QColor("#5d5d5d") },
			{ "Selected", QColor("#2e2e2e") }
			}) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6a8ac3")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/settings_menu/sidebar/themes_settings_tab/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", {
			{ "Unselected", QColor("#5d5d5d") },
			{ "Selected", QColor("#2e2e2e") }
			}) }
		});

	light_theme.add_attributes("layers/settings_menu/app_preferences_settings_panel", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_combobox", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor(Qt::lightGray)) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_combobox/current_item_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#5d5d5d")) }
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", {
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
			}) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", {
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
			}) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", {
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
			}) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", {
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
			}) },
		{ "fill", new Attribute("Fill", QColor("#d6d6d6")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#ededed")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_combobox/drop_down/combobox_item/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/separator", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::lightGray)) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/new_theme_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/new_theme_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/new_theme_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#6fc654")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#8cfa6a")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/customize_theme_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/customize_theme_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#c3c3c3")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#e6e6e6")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/delete_theme_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/delete_theme_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#e95454")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#ff7f7f")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_info_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_info_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/settings_menu/themes_settings_panel/theme_info_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#6a6a6a")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#6a6a6a")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(false)) }
		});

	light_theme.add_attributes("layers/customize_menu", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/topbar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor(Qt::lightGray)) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/topbar/apply_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(7)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(7)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/topbar/apply_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#6aaaf7"), true) }
		});

	light_theme.add_attributes("layers/customize_menu/topbar/arrow_graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/topbar/arrow_graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#2e2e2e")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#2e2e2e")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(false)) }
		});

	light_theme.add_attributes("layers/customize_menu/topbar/collapse_menu", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("d6d6d6")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/topbar/collapse_menu_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white)) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(10)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(10)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/topbar/collapse_menu_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/topbar/collapse_menu_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#2e2e2e")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#2e2e2e")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(false)) }
		});

	light_theme.add_attributes("layers/customize_menu/topbar/text_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/topbar/text_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::white)) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor(Qt::lightGray)) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/attributes_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor(Qt::white)) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/widgets_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor(Qt::white)) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/color_aw", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#1A000000")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/color_aw/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/color_aw/toggle_switch", {
		{ "border_fill", new Attribute("Border Fill", {
			{ "Untoggled", QColor("#2e2e2e") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(3)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(4)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor(Qt::lightGray) },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(12)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(12)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/color_aw/toggle_switch/square", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor("#2e2e2e") },
			{ "Toggled", QColor(Qt::white) }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#1A000000")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/toggle_switch", {
		{ "border_fill", new Attribute("Border Fill", {
			{ "Untoggled", QColor("#2e2e2e") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(3)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(4)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor(Qt::lightGray) },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(12)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(12)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/toggle_switch/square", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor("#2e2e2e") },
			{ "Toggled", QColor(Qt::white) }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control", {
		{ "border_fill", new Attribute("Border Fill", QColor("#D6D6D6")) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(2)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor(Qt::black)) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(10)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(10)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(10)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(10)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control/dialog", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(4)) },
		{ "fill", new Attribute("Fill", QColor("#c9c9c9")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control/dialog/vertical_toggle_switch", {
		{ "border_fill", new Attribute("Border Fill", {
			{ "Untoggled", QColor("#6fc65b") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(3)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(4)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(4)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor("#6fc65b") },
			{ "Toggled", QColor("#6fc65b") }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(12)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(12)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(12)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(12)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control/dialog/vertical_toggle_switch/square", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", {
			{ "Untoggled", QColor(Qt::white) },
			{ "Toggled", QColor(Qt::white) }
			}) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control/dialog/color_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor(Qt::white)) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/fill_aw/fill_control/dialog/gradient_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor(Qt::white)) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#1A000000")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/collapse_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/collapse_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/collapse_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#2e2e2e")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor(Qt::white)) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/collapse_button/graphic_after", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/collapse_button/graphic_after/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#2e2e2e")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor(Qt::white)) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/aw_group/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#1A000000")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/collapse_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/collapse_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/collapse_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#2e2e2e")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor(Qt::white)) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/collapse_button/graphic_after", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/collapse_button/graphic_after/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#2e2e2e")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor(Qt::white)) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/mini_slider", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white)) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/mini_slider/bar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", QColor("#7c7c7c")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(5)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(5)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/mini_slider/handle", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", QColor("#2e2e2e")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/line_editor", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#2e2e2e")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(7)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(7)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(8)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(8)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		{ "text_color", new Attribute("Text Color", QColor(Qt::lightGray)) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/corner_radii_aw/example_widget", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#7c7c7c")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor("#1A000000")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw/mini_slider", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white)) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(5)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(5)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw/mini_slider/bar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", QColor("#7c7c7c")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(5)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(5)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw/mini_slider/handle", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(2)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(2)) },
		{ "fill", new Attribute("Fill", QColor("#2e2e2e")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/number_aw/line_editor", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#2e2e2e")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(7)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(7)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(8)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(8)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		{ "text_color", new Attribute("Text Color", QColor(Qt::lightGray)) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/show_all_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(7)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(7)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/show_all_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#6aaaf7"), true) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/show_primary_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(7)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(7)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/show_primary_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#f8f8f8"), true) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/widget_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/widget_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/widget_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#2e2e2e")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor(Qt::white)) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/customize_menu/sidebar/customize_panel/widget_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::white)) }
		});

	light_theme.add_attributes("layers/create_new_theme_dialog", {
		{ "border_fill", new Attribute("Border Fill", QVariant::fromValue(QGradientStops({ { 0.0, Qt::lightGray },{ 1.0, Qt::white } }))) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(10)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white)) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black)) },
		});

	light_theme.add_attributes("layers/create_new_theme_dialog/titlebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#e1e1e1")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/create_new_theme_dialog/titlebar/exit_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true)},
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/create_new_theme_dialog/titlebar/exit_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/create_new_theme_dialog/titlebar/exit_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#c5c5c5")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#f25557")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/create_new_theme_dialog/titlebar/window_title_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#2e2e2e"), true) }
		});

	light_theme.add_attributes("layers/create_new_theme_dialog/name_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#2e2e2e"), true) }
		});

	light_theme.add_attributes("layers/create_new_theme_dialog/start_as_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#2e2e2e"), true) }
		});

	light_theme.add_attributes("layers/create_new_theme_dialog/start_theme_combobox", {
	{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
	{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
	{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
	{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
	{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
	{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
	{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
	{ "fill", new Attribute("Fill", QColor(Qt::lightGray)) },
	{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
	{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
	{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
	{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
	{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
	{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/create_new_theme_dialog/start_theme_combobox/current_item_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#5d5d5d")) }
		});

	light_theme.add_attributes("layers/create_new_theme_dialog/start_theme_combobox/drop_down", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", {
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
			}) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", {
			{ "Single", 10 },
			{ "Top", 10 },
			{ "Middle", 0 },
			{ "Bottom", 0 }
			}) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", {
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
			}) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", {
			{ "Single", 10 },
			{ "Top", 0 },
			{ "Middle", 0 },
			{ "Bottom", 10 }
			}) },
		{ "fill", new Attribute("Fill", QColor("#d6d6d6")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#ededed")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/create_new_theme_dialog/start_theme_combobox/drop_down/combobox_item/label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor(Qt::black)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	light_theme.add_attributes("layers/create_new_theme_dialog/theme_name_line_edit", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::lightGray)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(3)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) }
		});

	light_theme.add_attributes("layers/create_new_theme_dialog/create_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(4)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(6)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(4)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(6)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/create_new_theme_dialog/create_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#f8f8f8"), true) }
		});

	light_theme.add_attributes("layers/gradient_selection_dialog", {
		{ "border_fill", new Attribute("Border Fill", QVariant::fromValue(QGradientStops({ { 0.0, Qt::lightGray },{ 1.0, Qt::white } }))) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(10)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white)) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black)) },
		});

	light_theme.add_attributes("layers/gradient_selection_dialog/titlebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#e1e1e1")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/gradient_selection_dialog/titlebar/exit_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true)},
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/gradient_selection_dialog/titlebar/exit_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/gradient_selection_dialog/titlebar/exit_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#c5c5c5")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#f25557")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/gradient_selection_dialog/titlebar/window_title_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#2e2e2e"), true) }
		});

	light_theme.add_attributes("layers/gradient_selection_dialog/apply_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(4)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(6)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(4)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(6)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/gradient_selection_dialog/apply_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#f8f8f8"), true) }
		});

	light_theme.add_attributes("layers/update_dialog", {
		{ "border_fill", new Attribute("Border Fill", QVariant::fromValue(QGradientStops({ { 0.0, Qt::lightGray },{ 1.0, Qt::white } }))) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(10)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(10)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(10)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white)) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black)) },
		});

	light_theme.add_attributes("layers/update_dialog/titlebar", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(6)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor("#e1e1e1")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/update_dialog/titlebar/exit_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true)},
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/update_dialog/titlebar/exit_button/graphic", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) },
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "hover_fill", new Attribute("Hover Fill", QColor(Qt::white), true) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/update_dialog/titlebar/exit_button/graphic/svg", {
		{ "common_color", new Attribute("Common Color", QColor("#c5c5c5")) },
		{ "common_hover_color", new Attribute("Common Hover Color", QColor("#f25557")) },
		{ "use_common_color", new Attribute("Use Common Color", QVariant::fromValue(true)) },
		{ "use_common_hover_color", new Attribute("Use Common Hover Color", QVariant::fromValue(true)) }
		});

	light_theme.add_attributes("layers/update_dialog/titlebar/window_title_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#2e2e2e"), true) }
		});

	light_theme.add_attributes("layers/update_dialog/message_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#2e2e2e"), true) }
		});

	light_theme.add_attributes("layers/update_dialog/remind_me_later_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#c0c0c0")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#e4e4e4")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/update_dialog/remind_me_later_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#2e2e2e")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#2e2e2e"), true) }
		});

	light_theme.add_attributes("layers/update_dialog/update_button", {
		{ "border_fill", new Attribute("Border Fill", QColor(Qt::black)) },
		{ "border_thickness", new Attribute("Border Thickness", QVariant::fromValue(0)) },
		{ "corner_color", new Attribute("Corner Color", QColor(Qt::black), true) },
		{ "corner_radius_tl", new Attribute("Top-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_tr", new Attribute("Top-Right Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_bl", new Attribute("Bottom-Left Corner Radius", QVariant::fromValue(5)) },
		{ "corner_radius_br", new Attribute("Bottom-Right Corner Radius", QVariant::fromValue(5)) },
		{ "fill", new Attribute("Fill", QColor("#61ad50")) },
		{ "hover_fill", new Attribute("Hover Fill", QColor("#6fc65b")) },
		{ "margin_left", new Attribute("Left Margin", QVariant::fromValue(0)) },
		{ "margin_top", new Attribute("Top Margin", QVariant::fromValue(0)) },
		{ "margin_right", new Attribute("Right Margin", QVariant::fromValue(0)) },
		{ "margin_bottom", new Attribute("Bottom Margin", QVariant::fromValue(0)) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::black), true) },
		});

	light_theme.add_attributes("layers/update_dialog/update_button/text_label", {
		{ "fill", new Attribute("Fill", QColor(Qt::white), true) },
		{ "outline_color", new Attribute("Outline Color", QColor(Qt::gray), true) },
		{ "text_color", new Attribute("Text Color", QColor("#f8f8f8")) },
		{ "text_hover_color", new Attribute("Text Hover Color", QColor("#f8f8f8"), true) }
		});

	return light_theme;
}
