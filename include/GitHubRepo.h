#ifndef GITHUBREPO_H
#define GITHUBREPO_H

#include <QString>

namespace Layers
{
	class GitHubRepo
	{
	public:
		GitHubRepo(const QString& repo_url);

		QString toString() const;

	private:
		QString m_repo_name{ "" };
		QString m_user_name{ "" };
	};
}

#endif // GITHUBREPO_H
