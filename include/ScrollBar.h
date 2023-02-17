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
		~ScrollBar();

		void update_theme_dependencies();

		Attribute* background_color() const;

		Attribute* handle_color() const;

		CornerRadiiAttributes* corner_radii() const;

		CornerRadiiAttributes* handle_corner_radii() const;

	protected:
		QString build_stylesheet();

		void init_attributes();

	private:
		Attribute* m_background_color{ new Attribute("background_color", QColor(Qt::gray)) };

		Attribute* m_handle_color{ new Attribute("handle_color", QColor(Qt::white)) };

		CornerRadiiAttributes* m_corner_radii{ new CornerRadiiAttributes };

		CornerRadiiAttributes* m_handle_corner_radii{ new CornerRadiiAttributes("handle_corner_radii") };
	};
}

#endif // SCROLLBAR_H
