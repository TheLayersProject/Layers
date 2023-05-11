#ifndef GITHUBREPO_H
#define GITHUBREPO_H

#include <QString>

namespace Layers
{
	/*!
		A GitHubRepo object is an object that references a GitHub repository.

		A GitHub repository is referenced by the name of the user/organization
		that owns the repository, followed by the name of the repository.
	*/
	class GitHubRepo
	{
	public:
		/*!
			Constructs a GitHubRepo object from a repository URL.
		*/
		GitHubRepo(const QString& repo_url);

		/*!
			Returns a string representation of the GitHub repository.

			The string is formatted as follows:
			```
			"owner/repository"
			```
		*/
		QString to_string() const;

	private:
		QString m_repo_name{ "" };
		QString m_user_name{ "" };
	};
}

#endif // GITHUBREPO_H
