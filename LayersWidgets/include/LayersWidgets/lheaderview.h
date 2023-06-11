#ifndef LHEADERVIEW_H
#define LHEADERVIEW_H

#include <QHeaderView>

#include "layerswidgetsexports.h"

#include <LayersCore/lthemeable.h>

namespace Layers
{
	/*!
		A LHeaderView is a QHeaderView and a LThemeable that is customizable.
	*/
	class LAYERS_WIDGETS_EXPORT LHeaderView : public QHeaderView, public LThemeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs a header view with a specified *orientation*.
		*/
		LHeaderView(Qt::Orientation orientation, QWidget* parent = nullptr);

		// TODO: Create a destructor; free the attributes

	private:
		void init_attributes();

		void update_stylesheet();

		LBorderAttributes* m_border{ new LBorderAttributes };

		LCornerRadiiAttributes* m_corner_radii{ new LCornerRadiiAttributes };

		LAttribute* m_fill{ new LAttribute(
			"fill",
			QColor(Qt::white)
			) };

		LAttribute* m_text_color{ new LAttribute(
			"text_color",
			QColor(Qt::black)
			) };
	};
}

#endif // LHEADERVIEW_H  
