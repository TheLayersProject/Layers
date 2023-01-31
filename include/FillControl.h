#ifndef FILLCONTROL_H
#define FILLCONTROL_H

#include "FillDialog.h"

namespace Layers
{
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
		FillDialog* m_control_dialog{ new FillDialog(this) };

		FillDialog* m_dialog{ new FillDialog };
	};
}

#endif // FILLCONTROL_H
