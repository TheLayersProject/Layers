#include <Layers/limagesequence.h>

#include <QImage>
#include <QPixmap>

using Layers::LImageSequence;

LImageSequence::LImageSequence(QDir directory)
{
	QStringList image_filenames =
		directory.entryList(
			QStringList() << "*.png" << "*.PNG", QDir::Files);

	for (QString filename : image_filenames)
	{
		m_frames.append(QImage(directory.filePath(filename)));
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

QImage* LImageSequence::frame(int i)
{
	if (!m_frames.isEmpty() && i < m_frames.size())
		return &m_frames[i];

	return nullptr;
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
