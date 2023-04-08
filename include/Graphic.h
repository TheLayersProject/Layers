#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QLabel>

#include "ImageSequenceLabel.h"
#include "SVG.h"
#include "Widget.h"

namespace Layers
{
	class Graphic : public Widget
	{
		Q_OBJECT

	public:
		Graphic(const ImageSequence& image_sequence, QSize size, QWidget* parent = nullptr);
		Graphic(const QString& filepath, QSize size, QWidget* parent = nullptr);
		Graphic(const QString& filepath, QWidget* parent = nullptr);
		Graphic(const QImage& image, QWidget* parent = 0);
		Graphic(const Graphic& gw);
		~Graphic();

		void set_hovering(bool cond = true);
		void set_icon(Graphic* icon);

		void set_pixmap(const QPixmap& pixmap);
		SVG* svg() const;

	private:
		void init_max_size();

		void init_layout();

		QLabel* m_bitmap_label{ nullptr };
		SVG* m_svg_widget{ nullptr };
		ImageSequenceLabel* m_image_sequence_label{ nullptr };
	};
}

#endif // GRAPHIC_H
