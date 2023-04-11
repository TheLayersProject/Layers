#include "ImageSequence.h"

#include <QImage>
#include <QPixmap>

using Layers::ImageSequence;

ImageSequence::ImageSequence(QDir dir)
{
	QStringList image_filenames =
		dir.entryList(QStringList() << "*.png" << "*.PNG", QDir::Files);

	for (QString filename : image_filenames)
	{
		m_images.append(QImage(dir.filePath(filename)));
	}

	save(QFile("layers_logo.imgseq"));
}

ImageSequence::ImageSequence(QFile file)
{
	if (file.exists())
	{
		if (!file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read file '" + file.fileName() + "'";

		QDataStream in(&file);
		in.setVersion(QDataStream::Qt_6_1);

		in >> m_images;

		file.close();
	}
}

void ImageSequence::save(QFile file)
{
	if (!file.open(QIODevice::WriteOnly))
	{
		qDebug() << "Could not create file '" + file.fileName() + "'";
		return;
	}

	QDataStream out(&file);
	out.setVersion(QDataStream::Qt_6_1);

	out << m_images;

	file.close();
}

qsizetype ImageSequence::size() const
{
	return m_images.size();
}

QList<QPixmap> ImageSequence::to_pixmaps() const
{
	QList<QPixmap> pixmaps;

	for (const QImage& image : m_images)
		pixmaps.append(QPixmap::fromImage(image));

	return pixmaps;
}

QImage& ImageSequence::operator[](int i)
{
	return m_images[i];
}
