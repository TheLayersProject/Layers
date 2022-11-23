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

		QSize image_size();

		void replace_all_attributes_with(Graphic* graphic);

		void set_hovering(bool cond = true);
		void set_icon(Graphic* icon);
		void set_pixmap(const QPixmap& pixmap);
		void set_size(QSize size);

		SVG* svg() const;

	private:
		QSize m_image_size{ QSize() };
		QLabel* m_bitmap_label{ nullptr };
		SVG* m_svg_widget{ nullptr };
		ImageSequenceLabel* m_image_sequence_label{ nullptr };
	};
}

#endif // GRAPHIC_H
