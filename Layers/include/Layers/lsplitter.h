#ifndef LSPLITTER_H
#define LSPLITTER_H

#include <QSplitter>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LSplitter : public QSplitter, public LThemeable
{
	Q_OBJECT

public:
	LSplitter(QWidget* parent = nullptr);

	LSplitter(Qt::Orientation orientation, QWidget* parent = nullptr);

private:
	void init();
};
LAYERS_NAMESPACE_END

#endif // LSPLITTER_H
