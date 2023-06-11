#ifndef LSETTINGSMENU_H
#define LSETTINGSMENU_H

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <LayersWidgets/lwidget.h>

namespace Layers
{
	class LLabel;
	class LSettingsTab;
	class LThemesWidget;

	class LSettingsMenu : public LWidget
	{
		Q_OBJECT

	public:
		LSettingsMenu(QWidget* parent = nullptr);

		void add_settings_tab(const LGraphic& icon, const QString& label_text);

		int largest_tab_index() const;

		int recommended_minimum_tab_width() const;

		LThemesWidget* themes_widget() const;

	private:
		void init_layout();

		QVBoxLayout* m_sidebar_layout = new QVBoxLayout;

		QList<LSettingsTab*> m_settings_tabs;

		LWidget* m_sidebar{ new LWidget };

		LThemesWidget* m_themes_widget;
	};
}

#endif // LSETTINGSMENU_H
