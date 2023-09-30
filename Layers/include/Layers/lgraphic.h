#ifndef LGRAPHIC_H
#define LGRAPHIC_H

#include <QImage>

#include "layers_global.h"
#include "layers_exports.h"

#include "limagesequence.h"
#include "lsvgrenderer.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LGraphic
{
public:
	LGraphic(const QString& file_path, QSize size = QSize());

	LGraphic(const QImage& image);

	LGraphic(const LGraphic& graphic);

	~LGraphic();

	QImage* image() const;

	LImageSequence* image_sequence() const;

	QSize size() const;

	LSvgRenderer* svg_renderer() const;

private:
	QSize m_size;

	LImageSequence* m_image_sequence{ nullptr };

	QImage* m_image{ nullptr };

	LSvgRenderer* m_svg_renderer{ nullptr };
};
LAYERS_NAMESPACE_END

#endif // LGRAPHIC_H
