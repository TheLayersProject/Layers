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

		//void set_attribute(Attribute* attribute);

	public slots:
		void set_current_editting_state(const QString& state);

	protected:
		bool eventFilter(QObject* object, QEvent* event);

		void init_attributes();

	//private:
		//Attribute* m_attribute{ nullptr };
	};
}

#endif // GRADIENTCONTROL_H
