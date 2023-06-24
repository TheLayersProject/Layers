#include <Layers/limagesequence.h>

#include <QImage>
#include <QPixmap>

using Layers::LImageSequence;

LImageSequence::LImageSequence(QDir dir)
{
	QStringList image_filenames =
		dir.entryList(QStringList() << "*.png" << "*.PNG", QDir::Files);

	for (QString filename : image_filenames)
	{
		m_frames.append(QImage(dir.filePath(filename)));
	}
}

LImageSequence::LImageSequence(QFile file)
{
	if (file.exists())
	{
		if (!file.open(QIODevice::ReadOnly))
			qDebug() << "Could not read file '" + file.fileName() + "'";

		QDataStream in(&file);

		in >> m_frames;

		file.close();
	}
}

void LImageSequence::save(QFile file)
{
	if (!file.open(QIODevice::WriteOnly))
	{
		qDebug() << "Could not create file '" + file.fileName() + "'";
		return;
	}

	QDataStream out(&file);

	out << m_frames;

	file.close();
}

qsizetype LImageSequence::size() const
{
	return m_frames.size();
}

QImage& LImageSequence::operator[](int i)
{
	return m_frames[i];
}
