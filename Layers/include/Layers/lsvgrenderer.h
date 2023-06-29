#ifndef LSVGRENDERER_H
#define LSVGRENDERER_H

#include <QColor>
#include <QSvgRenderer>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LSvgRenderer is a QSvgRenderer and a LThemeable that is used to draw the
	contents of SVG files.
*/
class LAYERS_EXPORT LSvgRenderer : public QSvgRenderer, public LThemeable
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
		new LAttribute("common_color", QColor(Qt::black), this) };

	QStringList m_svg_elements;

	QString m_svg_str;
};
LAYERS_NAMESPACE_END

#endif // LSVGRENDERER_H
