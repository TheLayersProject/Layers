#ifndef IMAGESEQUENCELABEL_H
#define IMAGESEQUENCELABEL_H

#include <QLabel>
#include <QTimer>

#include "ImageSequence.h"

namespace Layers
{
	class ImageSequenceLabel : public QLabel
	{
		Q_OBJECT

	public:
		ImageSequenceLabel(ImageSequence image_sequence, QSize size, QWidget* parent = nullptr);
		ImageSequenceLabel(const ImageSequenceLabel& isl);

	public slots:
		void time_out();

	private:
		int m_frame_number{ 0 };

		QTimer m_timer;

		QList<QPixmap> m_pixmaps{ QList<QPixmap>() };
	};
}

#endif // IMAGESEQUENCELABEL_H
