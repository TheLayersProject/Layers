#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include <QScrollBar>

#include "Attribute.h"
#include "Themeable.h"

namespace Layers
{
	/*!
		A ScrollBar is a QScrollBar and a Themeable that provides a control
		that allows the user to scroll to different parts of a widget in cases
		where the widget is larger than the available area it is displayed.
	*/
	class ScrollBar : public QScrollBar, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs a scroll bar.
		*/
		ScrollBar(QWidget* parent = nullptr);

		~ScrollBar();

		/*!
			Returns a pointer to the background color attribute of the scroll
			bar.
		*/
		Attribute* background_color() const;

		/*!
			Returns a pointer to the handle color attribute of the scroll bar.
		*/
		Attribute* handle_color() const;

		/*!
			Returns a pointer to the corner radii attributes of the scroll bar.
		*/
		CornerRadiiAttributes* corner_radii() const;

		/*!
			Returns a pointer to the corner radii attributes of the scroll
			bar's handle.
		*/
		CornerRadiiAttributes* handle_corner_radii() const;

	private:
		void init_attributes();

		void update_stylesheet();

		Attribute* m_background_color{ new Attribute("background_color", QColor(Qt::gray)) };

		Attribute* m_handle_color{ new Attribute("handle_color", QColor(Qt::white)) };

		CornerRadiiAttributes* m_corner_radii{ new CornerRadiiAttributes };

		CornerRadiiAttributes* m_handle_corner_radii{ new CornerRadiiAttributes("handle_corner_radii") };
	};
}

#endif // SCROLLBAR_H
