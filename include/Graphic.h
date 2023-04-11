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
		~Graphic();

		virtual QList<Themeable*> child_themeables(
			Qt::FindChildOptions options = Qt::FindDirectChildrenOnly) override;

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

#endif // GRAPHIC2_H
