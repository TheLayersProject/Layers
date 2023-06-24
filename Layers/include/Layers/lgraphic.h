#ifndef LGRAPHIC_H
#define LGRAPHIC_H

#include <QImage>

#include "layers_global.h"
#include "layers_exports.h"

#include "limagesequence.h"
#include "lsvgrenderer.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LGraphic stores data pertaining to graphical imagery.

	The data is represented with either a QImage, an LImageSequence, or an
	LSvgRenderer.
*/
class LAYERS_EXPORT LGraphic
{
public:
	/*!
		Constructs a graphic from a file located at *file_path* with the
		given *size*.

		If the default invalid size if used, the size is derived from the file.
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
		Returns a pointer to the graphic's QImage, if this graphic uses
		one.
	*/
	QImage* image() const;

	/*!
		Returns a pointer to the graphic's LImageSequence, if this graphic uses
		one.
	*/
	LImageSequence* image_sequence() const;

	/*!
		Returns the size (width and height) of the graphic.
	*/
	QSize size() const;

	/*!
		Returns a pointer to the graphic's LSvgRenderer, if this graphic uses
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
