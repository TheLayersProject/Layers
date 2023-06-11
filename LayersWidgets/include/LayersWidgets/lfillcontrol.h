#ifndef LFILLCONTROL_H
#define LFILLCONTROL_H

#include "layerswidgetsexports.h"

#include "lwidget.h"

namespace Layers
{
	class LFillDialog;

	/*!
		A LFillControl is a LWidget that gives the user a way to access the
		LFillDialog. When the user clicks on the control, a LFillDialog is
		displayed.
	*/
	class LAYERS_WIDGETS_EXPORT LFillControl : public LWidget
	{
		Q_OBJECT

	public:
		/*!
			Constructs a fill control.
		*/
		LFillControl(QWidget* parent = nullptr);

		~LFillControl();

		/*!
			Sets the attribute to link with the control.
		*/
		void set_attribute(LAttribute* attribute);

	public slots:
		/*!
			Sets the state that is currently being edited.
		*/
		void set_current_editing_state(const QString& state);

	protected:
		bool eventFilter(QObject* object, QEvent* event);

	private:
		void init_attributes();

		LFillDialog* m_control_dialog;

		LFillDialog* m_dialog;
	};
}

#endif // LFILLCONTROL_H
