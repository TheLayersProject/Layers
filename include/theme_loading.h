#ifndef THEME_LOADING_H
#define THEME_LOADING_H

#include <QDataStream>
#include <QFile>

#include "Theme.h"

namespace Layers
{
	Theme load_theme_1(const QString& file_name);
}

#endif // THEME_LOADING_H
