#ifndef LCOLORDIALOG_H
#define LCOLORDIALOG_H

#include "layerswidgetsexports.h"

#include "lcolorplane.h"
#include "lcombobox.h"
#include "ldialog.h"
#include "llineeditor.h"
#include "lradiobutton.h"
#include "lradiobuttonpool.h"
#include "lslider.h"

namespace Layers
{
	class LAYERS_WIDGETS_EXPORT LColorDialog : public LDialog
	{
		Q_OBJECT

	public:
		LColorDialog(QWidget* parent = nullptr);
		~LColorDialog();

		virtual LThemeable* clone() override;

		LAttribute* color() const;

	protected:
		void init_attributes();

	private slots:
		void hsv_changed();

	private:
		void init_layout();

		LButton* m_apply_button{ new LButton("Apply") };

		LLabel* m_color_unit_label{ new LLabel("#")};

		LLineEditor* m_line_editor_color_name{ new LLineEditor };

		LColorPlane* m_color_plane{ new LColorPlane };

		LSlider* m_z_slider{ new LSlider(359) };

		LAttribute* m_color{ new LAttribute("color", QColor()) };

		LRadioButton* m_radio_button_hue{ new LRadioButton };
		LRadioButton* m_radio_button_sat{ new LRadioButton };
		LRadioButton* m_radio_button_val{ new LRadioButton };

		LRadioButtonPool m_hsv_radio_button_pool{
			LRadioButtonPool({
				m_radio_button_hue,
				m_radio_button_sat,
				m_radio_button_val
				}) };

		LLabel* m_label_hue{ new LLabel("H:") };
		LLabel* m_label_hue_unit{ new LLabel("°") };
		LLabel* m_label_sat{ new LLabel("S:") };
		LLabel* m_label_sat_unit{ new LLabel("%") };
		LLabel* m_label_val{ new LLabel("V:") };
		LLabel* m_label_val_unit{ new LLabel("%") };

		LLineEditor* m_line_editor_hue{ new LLineEditor };
		LLineEditor* m_line_editor_sat{ new LLineEditor };
		LLineEditor* m_line_editor_val{ new LLineEditor };
	};
}

#endif // LCOLORDIALOG_H
