#ifndef COLORDIALOG_H
#define COLORDIALOG_H

#include "ColorPlane.h"
#include "ComboBox.h"
#include "Dialog.h"
#include "LineEditor.h"
#include "RadioButton.h"
#include "RadioButtonPool.h"
#include "Slider.h"

namespace Layers
{
	class ColorDialog : public Dialog
	{
		Q_OBJECT

	public:
		ColorDialog(QWidget* parent = nullptr);
		~ColorDialog();

		virtual Themeable* clone() override;

		Attribute* color() const;

	protected:
		void init_attributes();

	private slots:
		void hsv_changed();

	private:
		void setup_layout();

		Button* m_apply_button{ new Button("Apply") };

		Label* m_color_unit_label{ new Label("#")};

		LineEditor* m_line_editor_color_name{ new LineEditor };

		ColorPlane* m_color_plane{ new ColorPlane };

		Slider* m_z_slider{ new Slider(359) };

		Attribute* m_color{ new Attribute("color", QColor()) };

		RadioButton* m_radio_button_hue{ new RadioButton };
		RadioButton* m_radio_button_sat{ new RadioButton };
		RadioButton* m_radio_button_val{ new RadioButton };

		RadioButtonPool m_hsv_radio_button_pool{
			RadioButtonPool({
				m_radio_button_hue,
				m_radio_button_sat,
				m_radio_button_val
				}) };

		Label* m_label_hue{ new Label("H:") };
		Label* m_label_hue_unit{ new Label("°") };
		Label* m_label_sat{ new Label("S:") };
		Label* m_label_sat_unit{ new Label("%") };
		Label* m_label_val{ new Label("V:") };
		Label* m_label_val_unit{ new Label("%") };

		LineEditor* m_line_editor_hue{ new LineEditor };
		LineEditor* m_line_editor_sat{ new LineEditor };
		LineEditor* m_line_editor_val{ new LineEditor };
	};
}

#endif // COLORDIALOG_H
