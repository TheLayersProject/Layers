#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "Widget.h"

namespace Layers
{
	class Label;
	class SettingsTab;
	class ThemesWidget;

	class SettingsMenu : public Widget
	{
		Q_OBJECT

	public:
		SettingsMenu(QWidget* parent = nullptr);

		void add_settings_tab(Graphic* icon, const QString& label_text);

		int largest_tab_index() const;

		int recommended_minimum_tab_width() const;

		ThemesWidget* themes_widget() const;

	private:
		void init_layout();

		QVBoxLayout* m_sidebar_layout = new QVBoxLayout;

		QList<SettingsTab*> m_settings_tabs;

		Widget* m_sidebar{ new Widget };

		ThemesWidget* m_themes_widget;
	};
}

#endif // SETTINGSMENU_H
