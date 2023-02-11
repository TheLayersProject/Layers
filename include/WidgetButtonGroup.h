#ifndef WIDGETBUTTONGROUP_H
#define WIDGETBUTTONGROUP_H

#include <QVBoxLayout>

#include "Button.h"
#include "Graphic.h"
#include "WidgetButton.h"

namespace Layers
{
	class WidgetButtonGroup : public Widget
	{
		Q_OBJECT

	//signals:
	//	void clicked();

	public:
		WidgetButtonGroup(
			const QString& label_text,
			QList<WidgetButton*> widget_buttons,
			QWidget* parent = nullptr);

		void set_collapsed(bool collapsed = true);

		QList<WidgetButton*>& widget_buttons();

	private:
		void init_attributes();

		void init_layout();

		Button* m_collapse_button{ new Button(new Graphic(":/svgs/collapse_arrow_right.svg", QSize(8, 12)), new Graphic(":/svgs/collapse_arrow_down.svg", QSize(12, 8)), true) };

		bool m_collapsed{ true };

		Label* m_label{ nullptr };

		QList<WidgetButton*> m_widget_buttons{ QList<WidgetButton*>() };

		QVBoxLayout* m_widget_buttons_vbox{ new QVBoxLayout };
	};
}

#endif // WIDGETBUTTONGROUP_H
