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

		virtual void apply_theme_attributes(QMap<QString, Entity*>& theme_attrs) override;

		void SetCurrentTab(const QString& text);

		bool ContainsTab(const QString& text);

		//void removeTab(int index);
		void removeTab(const QString& text);

		void update_theme_dependencies();

		Attribute a_selected_fill_color{ Attribute("selected_fill_color", QColor(Qt::gray)) };
		Attribute a_text_color{ Attribute("text_color", QColor(Qt::white)) };

	protected:
		QString build_stylesheet();

		void init_attributes();
	};
}

#endif // TABBAR_H
