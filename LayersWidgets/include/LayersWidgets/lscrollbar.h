#ifndef LSCROLLBAR_H
#define LSCROLLBAR_H

#include "layerswidgetsexports.h"

#include <QScrollBar>

#include <LayersCore/lthemeable.h>

namespace Layers
{
	/*!
		A LScrollBar is a QScrollBar and a LThemeable that provides a control
		that allows the user to scroll to different parts of a widget in cases
		where the widget is larger than the available area it is displayed.
	*/
	class LAYERS_WIDGETS_EXPORT LScrollBar : public QScrollBar, public LThemeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs a scroll bar.
		*/
		LScrollBar(QWidget* parent = nullptr);

		~LScrollBar();

		/*!
			Returns a pointer to the background color attribute of the scroll
			bar.
		*/
		LAttribute* background_color() const;

		/*!
			Returns a pointer to the handle color attribute of the scroll bar.
		*/
		LAttribute* handle_color() const;

		/*!
			Returns a pointer to the corner radii attributes of the scroll bar.
		*/
		LCornerRadiiAttributes* corner_radii() const;

		/*!
			Returns a pointer to the corner radii attributes of the scroll
			bar's handle.
		*/
		LCornerRadiiAttributes* handle_corner_radii() const;

	private:
		void init_attributes();

		void update_stylesheet();

		LAttribute* m_background_color{ new LAttribute("background_color", QColor(Qt::gray)) };

		LAttribute* m_handle_color{ new LAttribute("handle_color", QColor(Qt::white)) };

		LCornerRadiiAttributes* m_corner_radii{ new LCornerRadiiAttributes };

		LCornerRadiiAttributes* m_handle_corner_radii{ new LCornerRadiiAttributes("handle_corner_radii") };
	};
}

#endif // LSCROLLBAR_H
