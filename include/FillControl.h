#ifndef FILLCONTROL_H
#define FILLCONTROL_H

#include "Widget.h"

namespace Layers
{
	class FillDialog;

	/*!
		A FillControl is a Widget that gives the user a way to access the
		FillDialog. When the user clicks on the control, a FillDialog is
		displayed.
	*/
	class FillControl : public Widget
	{
		Q_OBJECT

	public:
		/*!
			Constructs a fill control.
		*/
		FillControl(QWidget* parent = nullptr);

		~FillControl();

		/*!
			Sets the attribute to link with the control.
		*/
		void set_attribute(Attribute* attribute);

	public slots:
		/*!
			Sets the state that is currently being editted.
		*/
		void set_current_editting_state(const QString& state);

	protected:
		bool eventFilter(QObject* object, QEvent* event);

	private:
		void init_attributes();

		FillDialog* m_control_dialog;

		FillDialog* m_dialog;
	};
}

#endif // FILLCONTROL_H
