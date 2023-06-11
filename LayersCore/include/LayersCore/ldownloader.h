#ifndef LDOWNLOADER_H
#define LDOWNLOADER_H

#include <QFile>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "layerscoreexports.h"

namespace Layers
{
	/*!
		A LDownloader is a QObject that provides a mechanism for downloading
		files from the Internet.
	*/
	class LAYERS_CORE_EXPORT LDownloader : public QObject
	{
		Q_OBJECT

	public:
		/*!
			Constructs a downloader object.
		*/
		LDownloader(QObject* parent = 0);

		/*!
			Downloads the file located at *file_url*. Returns a pointer to a
			QNetworkReply response.
		*/
		QNetworkReply* download(const QUrl& file_url);

		/*!
			Downloads the file located at *file_url* to the specfied *directory*
			on the system. Returns a pointer to a QNetworkReply response.
		*/
		QNetworkReply* download(const QUrl& file_url, const QDir& directory);

	private:
		QNetworkAccessManager m_network_manager;
	};
}

#endif // LDOWNLOADER_H
