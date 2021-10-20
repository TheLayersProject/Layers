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

		void convert_attribute_to_stateful(const QString& attribute_name, QMap<QString, QVariant> state_value_map);

		QSize image_size();

		void set_hovering(bool cond = true);
		void set_icon(Graphic* icon);
		void set_pixmap(const QPixmap& pixmap);
		void set_size(QSize size);

		SVG* svg() const;

		void update_theme_dependencies();

	protected:
		void init_attribute_widgets();

	private:
		QSize m_image_size{ QSize() };
		QLabel* m_bitmap_label{ nullptr };
		SVG* m_svg_widget{ nullptr };
		ImageSequenceLabel* m_image_sequence_label{ nullptr };
	};
}

#endif // GRAPHIC_H
