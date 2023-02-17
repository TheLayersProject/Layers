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

		void update_theme_dependencies();

		Attribute* selected_text_color() const;
		Attribute* text_color() const;

	protected:
		QString build_stylesheet();

		void init_attributes();

		//void paintEvent(QPaintEvent* event);

	private:
		QList<QMenu*> m_menus{ QList<QMenu*>() };

		Attribute* m_selected_text_color{ new Attribute("selected_text_color", QColor(Qt::lightGray)) };
		Attribute* m_text_color{ new Attribute("text_color", QColor(Qt::gray)) };
	};
}

#endif // MENUBAR_H
