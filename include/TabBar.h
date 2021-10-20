#ifndef TABBAR_H
#define TABBAR_H

#include <QTabBar>

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

	protected:
		QString build_stylesheet();

		void init_attributes();
	};
}

#endif // TABBAR_H
