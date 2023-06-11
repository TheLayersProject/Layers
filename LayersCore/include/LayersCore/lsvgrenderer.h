#ifndef LSVGRENDERER_H
#define LSVGRENDERER_H

#include <QSvgRenderer>

#include "layerscoreexports.h"

#include "lthemeable.h"

namespace Layers
{
	/*!
		An LSvgRenderer is a QSvgRenderer and a LThemeable that is used to draw
		the contents of SVG files.
	*/
	class LAYERS_CORE_EXPORT LSvgRenderer : public QSvgRenderer, public LThemeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs an SVG renderer from a file.
		*/
		LSvgRenderer(const QString& file_path, QObject* parent = nullptr);

		/*!
			Constructs a copy of *svg_renderer*.
		*/
		LSvgRenderer(const LSvgRenderer& svg_renderer);

		~LSvgRenderer();

		/*!
			Returns a pointer to the common color attribute of the renderer.
		*/
		LAttribute* common_color() const;

	private:
		void init_attributes();

		void init_svg_elements_list();

		void rebuild_svg_str();

		void update();

		LAttribute* m_common_color{
			new LAttribute("common_color", QColor(Qt::black)) };

		QStringList m_svg_elements;

		QString m_svg_str;
	};
}

#endif // LSVGRENDERER_H