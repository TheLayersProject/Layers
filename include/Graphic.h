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

		//void setFixedSize(QSize s);


		void set_hovering(bool cond = true);
		void set_icon(Graphic* icon);

		void set_padding(int left, int top, int right, int bottom);

		void set_pixmap(const QPixmap& pixmap);
		SVG* svg() const;

	private:
		void update_image_location();
		void update_size();

		int m_padding_bottom{ 0 };
		int m_padding_left{ 0 };
		int m_padding_right{ 0 };
		int m_padding_top{ 0 };

		QSize m_image_size{ QSize() };
		QLabel* m_bitmap_label{ nullptr };
		SVG* m_svg_widget{ nullptr };
		ImageSequenceLabel* m_image_sequence_label{ nullptr };
	};
}

#endif // GRAPHIC_H
