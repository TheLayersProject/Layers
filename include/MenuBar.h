#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

#include "Attribute.h"
#include "Themeable.h"

namespace Layers
{
	/*!
		A MenuBar is a QMenuBar and a Themeable that provides a menu bar that
		consists of a list of pull-down menu items.
	*/
	class MenuBar : public QMenuBar, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs a menu bar.
		*/
		MenuBar(QWidget* parent = nullptr);

		/*!
			Returns a pointer to the selected text color attribute of the menu
			bar.
		*/
		Attribute* selected_text_color() const;

		/*!
			Returns a pointer to the text color attribute of the menu bar.
		*/
		Attribute* text_color() const;

	private:
		QString build_stylesheet();

		void init_attributes();

		void update_theme_dependencies();

		Attribute* m_selected_text_color{
			new Attribute("selected_text_color", QColor(Qt::lightGray)) };

		Attribute* m_text_color{
			new Attribute("text_color", QColor(Qt::gray)) };
	};
}

#endif // MENUBAR_H
