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

#include <Layers/ldownloader.h>

#include <QDir>
#include <QSaveFile>

using Layers::LDownloader;

LDownloader::LDownloader(QObject* parent) :
	QObject(parent)
{
}

QNetworkReply* LDownloader::download(const QUrl& file_url)
{
	QNetworkRequest request(file_url);

	QNetworkReply* reply = m_network_manager.get(request);

	connect(reply, &QNetworkReply::finished, [=] {
		reply->deleteLater();
	});

	return reply;
}

QNetworkReply* LDownloader::download(const QUrl& file_url, const QDir& directory)
{
	QNetworkRequest request(file_url);

	QNetworkReply* reply = m_network_manager.get(request);

	connect(reply, &QNetworkReply::finished, [=] {

		if (reply->error() == QNetworkReply::NoError)
		{
			QSaveFile file(directory.filePath(file_url.fileName()));

			file.open(QIODevice::WriteOnly);
			file.write(reply->readAll());
			file.commit();
		}

		reply->deleteLater();
		});

	return reply;
}
