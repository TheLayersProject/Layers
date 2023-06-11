#ifndef LGRAPHIC_H
#define LGRAPHIC_H

#include <QImage>

#include "layerscoreexports.h"

#include "limagesequence.h"
#include "lsvgrenderer.h"

namespace Layers
{
	class LAYERS_CORE_EXPORT LGraphic
	{
	public:
		/*!
			Constructs a graphic from a file located at *file_path* with the
			given *size*.

			If the default invalid size if used, the size is derived from the
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
			Returns a pointer to the graphic's QImage, if this graphic uses
			one.
		*/
		QImage* image() const;

		/*!
			Returns a pointer to the graphic's LImageSequence, if this graphic
			uses one.
		*/
		LImageSequence* image_sequence() const;

		/*!
			Returns the size (width and height) of the graphic.
		*/
		QSize size() const;

		/*!
			Returns a pointer to the graphic's LSvgRenderer, if this graphic
			uses one.
		*/
		LSvgRenderer* svg_renderer() const;

	private:
		QSize m_size;

		LImageSequence* m_image_sequence{ nullptr };

		QImage* m_image{ nullptr };

		LSvgRenderer* m_svg_renderer{ nullptr };
	};
}

#endif // LGRAPHIC_H
