#ifndef GRADIENTCONTROL_H
#define GRADIENTCONTROL_H

#include "Widget.h"

namespace Layers
{
	class GradientControl : public Widget
	{
		Q_OBJECT

	signals:
		void gradient_changed();

	public:
		GradientControl(QWidget* parent = nullptr);

		void init_attributes();

	protected:
		bool eventFilter(QObject* object, QEvent* event);
		void paintEvent(QPaintEvent* event);
	};
}

#endif // GRADIENTCONTROL_H
