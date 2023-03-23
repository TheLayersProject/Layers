#ifndef SETTINGSTAB_H
#define SETTINGSTAB_H

#include <QHBoxLayout>

#include "Widget.h"

namespace Layers
{
	class Label;
	class ThemesWidget;

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
}

#endif // SETTINGSTAB_H
