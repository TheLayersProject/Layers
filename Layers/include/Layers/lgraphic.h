#ifndef LGRAPHIC_H
#define LGRAPHIC_H

#include <QImage>

#include "layers_global.h"
#include "layers_exports.h"

#include "limagesequence.h"
#include "lsvgrenderer.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LGraphic stores an image object whose type depends on the image data
	that represents it.

	The stored image object is either a QImage, an LImageSequence, or an
	LSvgRenderer.
*/
class LAYERS_EXPORT LGraphic
{
public:
	/*!
		Constructs a graphic of *size* from a loaded file located
		at *file_path*.

		If the default, invalid size is used, the size is derived from the
		file.
	*/
	LGraphic(const QString& file_path, QSize size = QSize(),
		QWidget* parent = nullptr);

	/*!
		Constructs a graphic from a QImage.
	*/
	LGraphic(const QImage& image, QWidget* parent = nullptr);

	/*!
		Constructs a copy of *graphic*.
	*/
	LGraphic(const LGraphic& graphic);

	~LGraphic();

	/*!
		Returns a pointer to the graphic's QImage, if this graphic stores
		one.
	*/
	QImage* image() const;

	/*!
		Returns a pointer to the graphic's LImageSequence, if this graphic
		stores one.
	*/
	LImageSequence* image_sequence() const;

	/*!
		Returns the size (width and height) of the graphic.
	*/
	QSize size() const;

	/*!
		Returns a pointer to the graphic's LSvgRenderer, if this graphic stores
		one.
	*/
	LSvgRenderer* svg_renderer() const;

private:
	QSize m_size;

	LImageSequence* m_image_sequence{ nullptr };

	QImage* m_image{ nullptr };

	LSvgRenderer* m_svg_renderer{ nullptr };
};
LAYERS_NAMESPACE_END

#endif // LGRAPHIC_H
