#ifndef LGITHUBREPO_H
#define LGITHUBREPO_H

#include <QString>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN
/*!
	A LGitHubRepo object is an object that references a GitHub repository.

	A GitHub repository is referenced by the name of the user/organization that
	owns the repository, followed by the name of the repository.
*/
class LAYERS_EXPORT LGitHubRepo
{
public:
	/*!
		Constructs a LGitHubRepo object from a repository URL.
	*/
	LGitHubRepo(const QString& repo_url);

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
LAYERS_NAMESPACE_END

#endif // LGITHUBREPO_H
