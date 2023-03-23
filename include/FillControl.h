#ifndef FILLCONTROL_H
#define FILLCONTROL_H

#include "Widget.h"

namespace Layers
{
	class FillDialog;

	class FillControl : public Widget
	{
		Q_OBJECT

	public:
		FillControl(QWidget* parent = nullptr);
		~FillControl();

		void set_attribute(Attribute* attribute);

	public slots:
		void set_current_editting_state(const QString& state);

	protected:
		bool eventFilter(QObject* object, QEvent* event);

		void init_attributes();

	private:
		FillDialog* m_control_dialog;

		FillDialog* m_dialog;
	};
}

#endif // FILLCONTROL_H
