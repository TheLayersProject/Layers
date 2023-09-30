/*
 * Copyright (C) 2023 The Layers Project
 *
 * This file is part of Layers.
 *
 * Layers is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Layers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Layers. If not, see <https://www.gnu.org/licenses/>.
 */

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
