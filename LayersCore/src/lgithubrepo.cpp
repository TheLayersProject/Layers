#include <LayersCore/lgithubrepo.h>

#include <QList>

using Layers::LGitHubRepo;

LGitHubRepo::LGitHubRepo(const QString& repo_url)
{
	QStringList url_strings = repo_url.split("/");

	if (url_strings.size() >= 2)
	{
		m_user_name = url_strings[url_strings.size() - 2];
		m_repo_name = url_strings[url_strings.size() - 1];
	}
}

QString LGitHubRepo::to_string() const
{
	return QString(m_user_name + "/" + m_repo_name);
}
