#ifndef MENU_H
#define MENU_H

#include "Widget.h"

namespace Layers
{
	class Menu : public Widget
	{
		Q_OBJECT

	public:
		Menu(const QString& menu_name, Graphic* menu_icon, QWidget* parent = nullptr);

		QString name;
	};
}

#endif // MENU_H
