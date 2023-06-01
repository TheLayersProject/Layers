#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QImage>
#include <QTimer>
#include <QWidget>

#include "ImageSequence.h"
#include "SvgRenderer.h"
#include "Themeable.h"

namespace Layers
{
	/*!
		A Graphic is a QWidget and a Themeable that displays a graphical
		representation to the user.
	*/
	class Graphic : public QWidget, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs a graphic from a file located at *file_path* with the
			given *size*.

			If the default invalid size if used, the size is derived from the
			file.
		*/
		Graphic(const QString& file_path, QSize size = QSize(),
			QWidget* parent = nullptr);
		
		/*!
			Constructs a graphic from a QImage.
		*/
		Graphic(const QImage& image, QWidget* parent = nullptr);
		
		/*!
			Constructs a copy of *graphic*.
		*/
		Graphic(const Graphic& graphic);

		~Graphic();

		/*!
			Returns a list of child themeables.

			This function overrides Themeable::child_themeables() to include
			a pointer to the SvgRenderer, if this graphic uses one.
		*/
		virtual QList<Themeable*> child_themeables(
			Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
		) override;

		/*!
			Returns a pointer to the SvgRenderer, if this graphic uses one.
		*/
		SvgRenderer* svg() const;

	protected:
		void paintEvent(QPaintEvent* event) override;

	private:
		QSize m_draw_size;

		int m_frame{ 0 };

		ImageSequence* m_image_sequence{ nullptr };

		QImage* m_image{ nullptr };

		QMetaObject::Connection m_repaint_connection;

		SvgRenderer* m_svg{ nullptr };

		QTimer m_timer;
	};
}

#endif // GRAPHIC_H
