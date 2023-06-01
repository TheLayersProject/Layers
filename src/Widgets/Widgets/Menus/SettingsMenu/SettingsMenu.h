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

		QVBoxLayout* m_sidebar_layout = new QVBoxLayout;

		QList<SettingsTab*> m_settings_tabs;

		QPoint last_pos;

		Widget* m_sidebar{ new Widget };

		ThemesWidget* m_themes_widget;
	};
}

#endif // SETTINGSMENU_H
