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
	class Graphic : public QWidget, public Themeable
	{
		Q_OBJECT

	public:
		Graphic(const QString& file_path, QSize size = QSize(), QWidget* parent = nullptr);
		Graphic(const Graphic& g);

		Attribute* common_color() const;

	protected:
		void paintEvent(QPaintEvent* event) override;

	private:
		void init_attributes();

		Attribute* m_common_color{ new Attribute("common_color", QColor(Qt::black)) };

		int m_frame{ 0 };

		ImageSequence* m_image_sequence{ nullptr };

		QImage* m_image{ nullptr };

		SvgRenderer* m_svg{ nullptr };

		QTimer m_timer;
	};
}

#endif // GRAPHIC_H
