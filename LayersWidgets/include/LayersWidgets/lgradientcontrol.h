#ifndef LGRADIENTCONTROL_H
#define LGRADIENTCONTROL_H

#include "layerswidgetsexports.h"

#include "lwidget.h"

namespace Layers
{
	/*!
		A LGradientControl is a LWidget that gives the user a way to access the
		LGradientDialog. When the user clicks on the control, the application's
		LGradientDialog is displayed.
	*/
	class LAYERS_WIDGETS_EXPORT LGradientControl : public LWidget
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
		LGradientControl(QWidget* parent = nullptr);

	public slots:
		/*!
			Sets the state that is currently being edited.
		*/
		void set_current_editing_state(const QString& state);

	protected:
		bool eventFilter(QObject* object, QEvent* event);

	private:
		void init_attributes();
	};
}

#endif // LGRADIENTCONTROL_H
