#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "ThemeableBox.h"

namespace Layers
{
	class Widget : public QWidget, public ThemeableBox
	{
		Q_OBJECT

	public:
		Widget(QWidget* parent = nullptr);

	protected:
		virtual void paintEvent(QPaintEvent* event) override;
	};
}

#endif // WIDGET_H  
