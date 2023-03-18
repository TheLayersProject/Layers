#ifndef SETTINGSPANELS_H
#define SETTINGSPANELS_H

#include "Button.h"
#include "ThemeComboBox.h"
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
		~ThemesSettingsPanel();

		void handle_custom_theme_buttons_visibility();

		Button* customize_theme_button() const;

		Button* new_theme_button() const;

		ThemeComboBox* theme_combobox() const;

		void show_custom_theme_buttons(bool cond = true);

	protected:
		void init_attributes();

	private:
		void setup_layout();

		Label* m_theme_label{ new Label("Theme") };

		ThemeComboBox* m_theme_combobox{ new ThemeComboBox };

		Button* m_new_theme_button{ new Button(new Graphic(":/svgs/new_theme.svg", QSize(20, 20)), true) };
		Button* m_customize_theme_button{ new Button(new Graphic(":/svgs/customize_theme.svg", QSize(20, 20)), true) };
		Button* m_delete_theme_button{ new Button(new Graphic(":/svgs/delete_theme.svg", QSize(17, 20)), true) };
		Button* m_theme_info_button{ new Button(new Graphic(":/svgs/info_theme.svg", QSize(20, 20)), true) };

		Widget* m_control_separator{ new Widget(this) };
		Widget* m_separator_1{ new Widget };
		Widget* m_separator_2{ new Widget };
		Widget* m_spacer_1{ new Widget };
		Widget* m_spacer_2{ new Widget };

		QList<QMetaObject::Connection> m_connections{ QList<QMetaObject::Connection>() };
	};
}

#endif // SETTINGSPANELS_H
