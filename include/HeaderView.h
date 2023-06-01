#ifndef HEADERVIEW_H
#define HEADERVIEW_H

#include <QHeaderView>

#include "Themeable.h"

namespace Layers
{
	/*!
		A HeaderView is a QHeaderView and a Themeable that is customizable.
	*/
	class HeaderView : public QHeaderView, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs a header view with a specified *orientation*.
		*/
		HeaderView(Qt::Orientation orientation, QWidget* parent = nullptr);
		// TODO: Create a destructor; free the attributes

	private:
		void init_attributes();

		void update_stylesheet();

		BorderAttributes* m_border{ new BorderAttributes };

		CornerRadiiAttributes* m_corner_radii{ new CornerRadiiAttributes };

		Attribute* m_fill{ new Attribute(
			"fill",
			QColor(Qt::white)
			) };

		Attribute* m_text_color{ new Attribute(
			"text_color",
			QColor(Qt::black)
			) };
	};
}

#endif // HEADERVIEW_H  
