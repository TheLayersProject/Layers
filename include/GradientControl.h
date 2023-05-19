#ifndef GRADIENTCONTROL_H
#define GRADIENTCONTROL_H

#include "Widget.h"

namespace Layers
{
	/*!
		A GradientControl is a Widget that gives the user a way to access the
		GradientDialog. When the user clicks on the control, the application's
		GradientDialog is displayed.
	*/
	class GradientControl : public Widget
	{
		Q_OBJECT

	signals:
		/*!
			This signal is emitted if the associated gradient attribute
			changes.
		*/
		void gradient_changed();

	public:
		/*!
			Constructs a gradient control.
		*/
		GradientControl(QWidget* parent = nullptr);

	public slots:
		/*!
			Sets the state that is currently being editted.
		*/
		void set_current_editting_state(const QString& state);

	protected:
		bool eventFilter(QObject* object, QEvent* event);

	private:
		void init_attributes();
	};
}

#endif // GRADIENTCONTROL_H
