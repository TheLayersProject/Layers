#ifndef LFILLDIALOG_H
#define LFILLDIALOG_H

#include <QGraphicsOpacityEffect>

#include "layerswidgetsexports.h"

#include "lcolorcontrol.h"
#include "lgradientcontrol.h"
#include "llabel.h"
#include "ltoggleswitch.h"

namespace Layers
{
	class LAYERS_WIDGETS_EXPORT LFillDialog : public LWidget
	{
		Q_OBJECT

	public:
		LFillDialog(QWidget* parent = nullptr);

		void set_attribute(LAttribute* attribute);

	//public slots:
		void set_current_editing_state(const QString& state);

	protected:
		bool eventFilter(QObject* object, QEvent* event);

		void init_attributes();

	private:
		void init_layout();

		LColorControl* m_color_control{ new LColorControl };

		LLabel* m_color_label{ new LLabel("Color") };

		QGraphicsOpacityEffect* m_color_label_opacity{ new QGraphicsOpacityEffect };

		LToggleSwitch* m_fill_type_toggle{ new LToggleSwitch(true) };

		LGradientControl* m_gradient_control{ new LGradientControl };

		LLabel* m_gradient_label{ new LLabel("Gradient") };

		QGraphicsOpacityEffect* m_gradient_label_opacity{ new QGraphicsOpacityEffect };
	};
}

#endif // LFILLDIALOG_H
