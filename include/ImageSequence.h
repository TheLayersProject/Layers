#ifndef IMAGESEQUENCE_H
#define IMAGESEQUENCE_H

#include <QDir>

namespace Layers
{
	class ImageSequence
	{
	public:
		ImageSequence(QDir dir);

		ImageSequence(QFile file);

		void save(QFile file);

		QList<QPixmap> to_pixmaps() const;

	private:
		QList<QImage> m_images{ QList<QImage>() };
	};
}

#endif // IMAGESEQUENCE_H
