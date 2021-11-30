#ifndef SETTINGSPANELS_H
#define SETTINGSPANELS_H

#include "Button.h"
#include "Combobox.h"
#include "Graphic.h"

namespace Layers
{
	class AppPreferencesSettingsPanel : public Widget
	{
		Q_OBJECT

	public:
		AppPreferencesSettingsPanel(QWidget* parent = nullptr);
	};

	class ThemesSettingsPanel : public Widget
	{
		Q_OBJECT

	public:
		ThemesSettingsPanel(QWidget* parent = nullptr);

		void apply_theme(Theme& theme);

		Button* customize_theme_button() const;

		Button* new_theme_button() const;

		Combobox* theme_combobox() const;

		void show_custom_theme_buttons(bool cond = true);

	protected:
		void init_attributes();
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		Label* m_theme_label{ new Label("Theme") };

		Combobox* m_theme_combobox{ new Combobox };

		Button* m_new_theme_button{ new Button(new Graphic(":/svgs/new_theme.svg", QSize(20, 20)), true) };
		Button* m_customize_theme_button{ new Button(new Graphic(":/svgs/customize_theme.svg", QSize(20, 20)), true) };
		Button* m_delete_theme_button{ new Button(new Graphic(":/svgs/delete_theme.svg", QSize(17, 20)), true) };
		Button* m_theme_info_button{ new Button(new Graphic(":/svgs/info_theme.svg", QSize(20, 20)), true) };

		Widget* m_control_separator{ new Widget };
		Widget* m_separator_1{ new Widget };
		Widget* m_separator_2{ new Widget };
		Widget* m_spacer_1{ new Widget };
		Widget* m_spacer_2{ new Widget };
	};
}

#endif // SETTINGSPANELS_H
