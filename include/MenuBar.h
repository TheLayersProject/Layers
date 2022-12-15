#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

#include "Attribute.h"
#include "Themeable.h"

namespace Layers
{
	class MenuBar : public QMenuBar, public Themeable
	{
		Q_OBJECT

	public:
		MenuBar(QWidget* parent = 0);

		// TODO: Make override other overloaded versions from the parent class
		QMenu* addMenu(const QString& title);

		virtual void apply_theme_attributes(QMap<QString, AttributeType*>& theme_attrs) override;

		//void issue_update();

		void update_theme_dependencies();

		Attribute a_text_color{ Attribute("text_color", QColor(Qt::gray)) };
		Attribute a_selected_text_color{ Attribute("selected_text_color", QColor(Qt::lightGray)) };

		//Attribute a_text_color{ Attribute("Text Color", QColor(Qt::red)) };
		//Attribute a_selected_text_color{ Attribute("Selected Text Color", QColor(Qt::blue)) };

	protected:
		QString build_stylesheet();

		void init_attributes();

		//void paintEvent(QPaintEvent* event);

	private:
		QList<QMenu*> m_menus{ QList<QMenu*>() };
	};
}

#endif // MENUBAR_H
