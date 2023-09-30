#ifndef LSVGRENDERER_H
#define LSVGRENDERER_H

#include <QColor>
#include <QSvgRenderer>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LSvgRenderer : public QSvgRenderer, public LThemeable
{
	Q_OBJECT

public:
	LSvgRenderer(const QString& file_path, QObject* parent = nullptr);

	LSvgRenderer(const LSvgRenderer& svg_renderer);

	~LSvgRenderer();

	LAttribute* color() const;

private:
	void init_svg_elements_list();

	void rebuild_svg_str();

	void update();

	LAttribute* m_color
		{ new LAttribute("Color", QColor(Qt::black), this) };

	QStringList m_svg_elements;

	QString m_svg_str;
};
LAYERS_NAMESPACE_END

#endif // LSVGRENDERER_H
