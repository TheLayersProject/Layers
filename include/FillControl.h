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

		void init_attributes();

		void set_attribute(Attribute* attribute);

	protected:
		bool eventFilter(QObject* object, QEvent* event);

	private:
		void setup_layout();

		Attribute* m_attribute{ nullptr };

		ColorControl* m_color_control{ new ColorControl };

		Label* m_color_label{ new Label("Color") };

		QGraphicsOpacityEffect* m_color_label_opacity{ new QGraphicsOpacityEffect };

		QString m_current_editting_state{ "" };

		Widget* m_dialog{ new Widget };

		ToggleSwitch* m_fill_type_toggle{ new ToggleSwitch(true)};

		GradientControl* m_gradient_control{ new GradientControl };

		Label* m_gradient_label{ new Label("Gradient") };

		QGraphicsOpacityEffect* m_gradient_label_opacity{ new QGraphicsOpacityEffect };
	};
}

#endif // FILLCONTROL_H
