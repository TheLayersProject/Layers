#ifndef NEWGRAPHIC_H
#define NEWGRAPHIC_H

#include <QImage>

#include "ImageSequence.h"
#include "SvgRenderer.h"

namespace Layers
{
	/*!
		A Graphic is a QWidget and a Themeable that displays a graphical
		representation to the user.
	*/
	class NewGraphic
	{
	public:
		/*!
			Constructs a graphic from a file located at *file_path* with the
			given *size*.

			If the default invalid size if used, the size is derived from the
			file.
		*/
		NewGraphic(const QString& file_path, QSize size = QSize(),
			QWidget* parent = nullptr);

		/*!
			Constructs a graphic from a QImage.
		*/
		NewGraphic(const QImage& image, QWidget* parent = nullptr);

		/*!
			Constructs a copy of *graphic*.
		*/
		NewGraphic(const NewGraphic& graphic);

		~NewGraphic();

		/*!
			Returns a pointer to the graphic's QImage, if this graphic uses
			one.
		*/
		QImage* image() const;

		/*!
			Returns a pointer to the graphic's ImageSequence, if this graphic
			uses one.
		*/
		ImageSequence* image_sequence() const;

		/*!
			Returns the size (width and height) of the graphic.
		*/
		QSize size() const;

		/*!
			Returns a pointer to the graphic's SvgRenderer, if this graphic
			uses one.
		*/
		SvgRenderer* svg_renderer() const;

	private:
		QSize m_size;

		ImageSequence* m_image_sequence{ nullptr };

		QImage* m_image{ nullptr };

		//QMetaObject::Connection m_repaint_connection;

		SvgRenderer* m_svg_renderer{ nullptr };
	};
}

#endif // NEWGRAPHIC_H
