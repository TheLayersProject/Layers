#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <QHBoxLayout>

#include "Layouts.h"
#include "Menu.h"
#include "SettingsPanels.h"

namespace Layers
{
	class Label;

	class SettingsTab : public Widget
	{
		Q_OBJECT

	signals:
		void clicked();
		void under_minimum_width();
		void over_minimum_width();

	public:
		SettingsTab(Graphic* icon, const QString& label_text, QWidget* parent = nullptr);

		void expand();
		void shrink();

		int recommended_minimum_width();

		void set_disabled(bool cond = true);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();

		void resizeEvent(QResizeEvent* event);

	private:
		void setup_layout();

		QHBoxLayout* main_layout{ new QHBoxLayout };

		bool m_disabled{ false };

		Label* m_text_label;

		Graphic* m_tab_icon;

		Widget* m_spacer{ new Widget };
		Widget* m_stretch_widget{ new Widget };
		Widget* m_stretch_widget2{ new Widget };
	};

	class SettingsSidebar : public Widget
	{
		Q_OBJECT

	public:
		SettingsSidebar(QWidget* parent = nullptr);
	};

	class SettingsMenu : public Menu
	{
		Q_OBJECT

	public:
		SettingsMenu(QWidget* parent = nullptr);

		void add_settings_tab(Graphic* icon, const QString& label_text);

		int largest_tab_index() const;

		int recommended_minimum_tab_width() const;

		ThemesSettingsPanel* themes_settings_panel() const;

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private slots:
		void shrink_tabs();
		void expand_tabs();

	private:
		void setup_layout();

		bool m_dragging_sidebar{ false };
		bool m_frozen{ false };
		bool m_hovering_over_divider{ false };
		bool m_shrunk{ false };

		VerticalLayout* m_sidebar_layout = new VerticalLayout;

		QList<SettingsTab*> m_settings_tabs;

		QPoint last_pos;

		SettingsSidebar* m_sidebar{ new SettingsSidebar };

		AppPreferencesSettingsPanel* m_app_preferences_settings_panel{ new AppPreferencesSettingsPanel };

		ThemesSettingsPanel* m_themes_settings_panel{ new ThemesSettingsPanel };
	};
}

#endif // SETTINGSMENU_H
