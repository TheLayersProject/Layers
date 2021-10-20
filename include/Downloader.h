#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Layers
{
	class Downloader : public QObject
	{
		Q_OBJECT

	public:
		Downloader(QObject* parent = 0);

		QNetworkReply* download(const QUrl& file_url, const QDir& directory);

		QNetworkReply* download(const QUrl& file_url);

	private:
		QNetworkAccessManager m_network_manager;
	};
}

#endif // DOWNLOADER_H
