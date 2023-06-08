#ifndef SVGRENDERER_H
#define SVGRENDERER_H

#include <QSvgRenderer>

#include "Themeable.h"

namespace Layers
{
	/*!
		An SvgRenderer is a QSvgRenderer and a Themeable that is used to draw
		the contents of SVG files.
	*/
	class SvgRenderer : public QSvgRenderer, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs an SVG renderer from a file.
		*/
		SvgRenderer(const QString& file_path, QObject* parent = nullptr);

		/*!
			Constructs a copy of *svg_renderer*.
		*/
		SvgRenderer(const SvgRenderer& svg_renderer);

		~SvgRenderer();

		/*!
			Returns a pointer to the common color attribute of the renderer.
		*/
		Attribute* common_color() const;

	private:
		void init_attributes();

		void init_svg_elements_list();

		void rebuild_svg_str();

		void update();

		Attribute* m_common_color{
			new Attribute("common_color", QColor(Qt::black)) };

		QStringList m_svg_elements;

		QString m_svg_str;
	};
}

#endif // SVGRENDERER_H
