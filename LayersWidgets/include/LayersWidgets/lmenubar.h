#ifndef LMENUBAR_H
#define LMENUBAR_H

#include <QMenuBar>

#include "layerswidgetsexports.h"

#include <LayersCore/lthemeable.h>

namespace Layers
{
	/*!
		A LMenuBar is a QMenuBar and a LThemeable that provides a menu bar that
		consists of a list of pull-down menu items.
	*/
	class LAYERS_WIDGETS_EXPORT LMenuBar : public QMenuBar, public LThemeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs a menu bar.
		*/
		LMenuBar(QWidget* parent = nullptr);

		/*!
			Returns a pointer to the selected text color attribute of the menu
			bar.
		*/
		LAttribute* selected_text_color() const;

		/*!
			Returns a pointer to the text color attribute of the menu bar.
		*/
		LAttribute* text_color() const;

	private:
		QString build_stylesheet();

		void init_attributes();

		void update_theme_dependencies();

		LAttribute* m_selected_text_color{
			new LAttribute("selected_text_color", QColor(Qt::lightGray)) };

		LAttribute* m_text_color{
			new LAttribute("text_color", QColor(Qt::gray)) };
	};
}

#endif // LMENUBAR_H
