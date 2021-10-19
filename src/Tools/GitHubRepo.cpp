#include "../Layers.h"

using Layers::GitHubRepo;

GitHubRepo::GitHubRepo(const QString& repo_url)
{
	QStringList url_strings = repo_url.split("/");

	if (url_strings.size() == 2)
	{
		m_user_name = url_strings[0];
		m_repo_name = url_strings[1];
	}
}

QString GitHubRepo::toString() const
{
	return QString(m_user_name + "/" + m_repo_name);
}
