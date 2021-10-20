#ifndef VERSION_H
#define VERSION_H

#include <QList>
#include <QString>

namespace Layers
{
	class Version
	{
	public:
		Version(int major, int minor = 0, int patch = 0, QString phase = "");

		Version(QString version_string);

		Version();

		QString toString();

	private:
		const QList<QString> m_acceptable_phases{ QList<QString>({
			"alpha", "a", "beta", "b", "release-candidate", "rc" }) };

		int m_major{ 0 };
		int m_minor{ 0 };
		int m_patch{ 0 };

		QString m_phase{ "" };

		QString m_separator_charactor{ "" };
	};
}

#endif // VERSION_H
