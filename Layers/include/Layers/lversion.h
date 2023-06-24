#ifndef LVERSION_H
#define LVERSION_H

#include <QList>
#include <QString>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LVersion object is an object that represents a version tag.
		
	%Version tags make it easy to compare software iterations and determine if
	updates are available.
*/
class LAYERS_EXPORT LVersion
{
public:
	/*!
		Constructs a version object from major, minor, and patch integers.

		An optional *suffix* may be included.
	*/
	LVersion(int major, int minor = 0, int patch = 0, QString suffix = "");

	/*!
		Constructs a version object from a string.
	*/
	LVersion(QString version_string);

	/*!
		Constructs a null version object.
			
		The resulting version tag will be '0.0.0'.
	*/
	LVersion();

	/*!
		Returns a string representation of the version.
	*/
	QString to_string();

private:
	QList<QString> m_acceptable_suffixes{ QList<QString>({
		"alpha", "a", "beta", "b", "release-candidate", "rc" }) };

	int m_major{ 0 };
	int m_minor{ 0 };
	int m_patch{ 0 };

	QString m_suffix{ "" };

	QString m_separator_character{ "" };
};
LAYERS_NAMESPACE_END

#endif // LVERSION_H
