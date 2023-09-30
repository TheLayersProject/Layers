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

#ifndef LDOWNLOADER_H
#define LDOWNLOADER_H

#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LDownloader : public QObject
{
	Q_OBJECT

public:
	LDownloader(QObject* parent = nullptr);

	QNetworkReply* download(const QUrl& file_url);

	QNetworkReply* download(const QUrl& file_url, const QDir& directory);

private:
	QNetworkAccessManager m_network_manager;
};
LAYERS_NAMESPACE_END

#endif // LDOWNLOADER_H
