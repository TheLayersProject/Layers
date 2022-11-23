#ifndef FILLCONTROL_H
#define FILLCONTROL_H

#include <QGraphicsOpacityEffect>

#include "ColorControl.h"
#include "GradientControl.h"
#include "Label.h"
#include "ToggleSwitch.h"

namespace Layers
{
	class FillControl : public Widget
	{
		Q_OBJECT

	public:
		FillControl(QWidget* parent = nullptr);
		~FillControl();

		void init_child_themeable_reference_list();

		void set_attribute(Attribute* attribute);

	public slots:
		void set_current_editting_state(const QString& state);

	protected:
		bool eventFilter(QObject* object, QEvent* event);

		void init_attributes();

	private:
		void setup_layout();

		ColorControl* m_color_control{ new ColorControl };

		Label* m_color_label{ new Label("Color") };

		QGraphicsOpacityEffect* m_color_label_opacity{ new QGraphicsOpacityEffect };

		Widget* m_dialog{ new Widget };

		ToggleSwitch* m_fill_type_toggle{ new ToggleSwitch(true)};

		GradientControl* m_gradient_control{ new GradientControl };

		Label* m_gradient_label{ new Label("Gradient") };

		QGraphicsOpacityEffect* m_gradient_label_opacity{ new QGraphicsOpacityEffect };
	};
}

#endif // FILLCONTROL_H
