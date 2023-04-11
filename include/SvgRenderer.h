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
		~SvgRenderer();

		Attribute* common_color() const;

		/*!
			Rebuilds the SVG string from the SVG elements list.
		*/
		void rebuild_svg_str();

		void update();

	private:
		/*!
			Initializes the attributes.

			This function is called by init_themeable().
		*/
		void init_attributes();

		void init_svg_elements_list();

		Attribute* m_common_color{ new Attribute("common_color", QColor(Qt::black)) };

		QStringList m_svg_elements;

		QString m_svg_str;
	};
}

#endif // SVGRENDERER_H
