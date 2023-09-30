#ifndef LGITHUBREPO_H
#define LGITHUBREPO_H

#include <QString>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LGitHubRepo
{
public:
	LGitHubRepo(const QString& repo_url);

	QString to_string() const;

private:
	QString m_repo_name{ "" };
	QString m_user_name{ "" };
};
LAYERS_NAMESPACE_END

#endif // LGITHUBREPO_H
