#include "Version.h"

using Layers::Version;

Version::Version(int major, int minor, int patch, QString suffix) :
	m_major{ major },
	m_minor{ minor },
	m_patch{ patch },
	m_suffix{ suffix }
{}

Version::Version(QString version_string)
{
	for (const QString& suffix : m_acceptable_suffixes)
	{
		if (version_string.endsWith(suffix))
		{
			m_suffix = suffix;

			version_string.chop(suffix.size());

			break;
		}
	}

	if (version_string.endsWith("-") || version_string.endsWith("_"))
	{
		m_separator_charactor = version_string.last(1);

		version_string.chop(1);
	}

	QStringList version_strings = version_string.split(".");

	bool success = false;

	if (!version_strings.isEmpty())
	{
		m_major = version_strings[0].toInt(&success);

		if (success && version_strings.size() > 1)
		{
			m_minor = version_strings[1].toInt(&success);

			if (success && version_strings.size() > 2)
			{
				m_patch = version_strings[2].toInt();
			}
		}
	}
}

Version::Version() {}

QString Version::to_string()
{
	return
		QString::number(m_major) + "." +
		QString::number(m_minor) + "." +
		QString::number(m_patch) + m_separator_charactor + m_suffix;
}
