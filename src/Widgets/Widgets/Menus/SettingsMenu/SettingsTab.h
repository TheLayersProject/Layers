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
		SettingsTab(const Graphic& icon, const QString& label_text, QWidget* parent = nullptr);

		int recommended_minimum_width();

		void set_disabled(bool cond = true);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();

		void resizeEvent(QResizeEvent* event);

	private:
		void init_layout();

		QHBoxLayout* main_layout{ new QHBoxLayout };

		bool m_disabled{ false };

		Label* m_icon_label;

		Label* m_text_label;
	};
}

#endif // SETTINGSTAB_H
