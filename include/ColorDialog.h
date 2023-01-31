#ifndef COLORDIALOG_H
#define COLORDIALOG_H

#include "ColorPlane.h"
#include "Dialog.h"
#include "LineEditor.h"
#include "Slider.h"

namespace Layers
{
	class ColorDialog : public Dialog
	{
		Q_OBJECT

	public:
		ColorDialog(QWidget* parent = nullptr);

		Attribute color{ Attribute("color", QColor()) };

		void update_color_name_line_editor();

	protected:
		void init_attributes();

	private:
		void setup_layout();

		Button* m_apply_button{ new Button("Apply") };

		LineEditor* m_color_name_line_editor{ new LineEditor };

		ColorPlane* m_color_plane{ new ColorPlane };

		Slider* m_z_slider{ new Slider(359) };
	};
}

#endif // COLORDIALOG_H
