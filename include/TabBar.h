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

		//void removeTab(int index);
		void removeTab(const QString& text);

		void update_theme_dependencies();

		Attribute* selected_fill_color() const;
		Attribute* text_color() const;

	protected:
		QString build_stylesheet();

		void init_attributes();

	private:
		Attribute* m_selected_fill_color{ new Attribute("selected_fill_color", QColor(Qt::gray)) };
		Attribute* m_text_color{ new Attribute("text_color", QColor(Qt::white)) };
	};
}

#endif // TABBAR_H
