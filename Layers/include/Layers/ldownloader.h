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
