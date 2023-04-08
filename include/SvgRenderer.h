#ifndef SVGRENDERER_H
#define SVGRENDERER_H

#include <QSvgRenderer>

#include "Themeable.h"

namespace Layers
{
	class SvgRenderer : public QSvgRenderer, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs an SVG from an SVG file.
		*/
		SvgRenderer(const QString& file_path, QObject* parent = nullptr);
		SvgRenderer(const SvgRenderer& sr);

		Attribute* common_color() const;

		/*!
			Rebuilds the SVG string from the SVG elements list.
		*/
		void rebuild_svg_str();

		/*!
			Updates things that depend on the theme.

			SVG elements are updated with the newly applied theme's attribute values. Then, the SVG string is rebuilt
			from those elements. And finally, the SVG string is passed to QSvgWidget::load() to update the SVG's
			appearance.
		*/
		void update();

		//Attribute a_use_common_color{ Attribute("use_common_color", QVariant::fromValue(false)) };

	private:
		/*!
			Initializes the attributes.

			This function is called by init_themeable().
		*/
		void init_attributes();

		void init_svg_elements_list();

		Attribute* m_common_color{ new Attribute("common_color", QColor(Qt::black)) };

		QString m_svg_str{  };

		QStringList m_svg_elements{  };
	};
}

#endif // SVGRENDERER_H
