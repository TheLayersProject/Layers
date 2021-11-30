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

		void set_attribute(Attribute* attribute);

	protected:
		bool eventFilter(QObject* object, QEvent* event);

	private:
		Attribute* m_attribute{ nullptr };
	};
}

#endif // GRADIENTCONTROL_H
