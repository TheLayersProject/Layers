#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include <QScrollBar>

#include "Attribute.h"
#include "Themeable.h"

namespace Layers
{
	class ScrollBar : public QScrollBar, public Themeable
	{
		Q_OBJECT

	public:
		ScrollBar(QWidget* parent = 0);

		virtual void apply_theme_attributes(QMap<QString, Entity*>& theme_attrs) override;

		void update_theme_dependencies();

		Attribute a_background_color{ Attribute("background_color", QColor(Qt::gray)) };
		Attribute a_handle_color{ Attribute("handle_color", QColor(Qt::white)) };

		CornerRadiiAttributes corner_radii;

		CornerRadiiAttributes handle_corner_radii{ CornerRadiiAttributes("handle_corner_radii") };

	protected:
		QString build_stylesheet();

		void init_attributes();
	};
}

#endif // SCROLLBAR_H
