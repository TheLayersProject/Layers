#ifndef TABBAR_H
#define TABBAR_H

#include <QTabBar>

#include "Attribute.h"
#include "Themeable.h"

namespace Layers
{
	class TabBar : public QTabBar, public Themeable
	{
		Q_OBJECT

	public:
		TabBar(QWidget* parent = 0);

		void SetCurrentTab(const QString& text);

		bool ContainsTab(const QString& text);

		void issue_update();

		//void removeTab(int index);
		void removeTab(const QString& text);

		void update_theme_dependencies();

		Attribute* a_selected_fill_color{ new Attribute("Selected Fill Color", QColor("#F0F0F0")) };
		Attribute* a_text_color{ new Attribute("Text Color", QColor(Qt::white)) };

	protected:
		QString build_stylesheet();

		void init_attributes();
	};
}

#endif // TABBAR_H
