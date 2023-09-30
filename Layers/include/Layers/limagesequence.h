#ifndef LIMAGESEQUENCE_H
#define LIMAGESEQUENCE_H

#include <QDir>

#include "layers_global.h"
#include "layers_exports.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LImageSequence
{
public:
	LImageSequence(QDir directory);

	LImageSequence(QFile file);

	QImage* frame(int i);

	void save(QFile file);

	qsizetype size() const;

private:
	QList<QImage> m_frames;
};
LAYERS_NAMESPACE_END

#endif // LIMAGESEQUENCE_H
