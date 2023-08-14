#ifndef LCOLORDIALOG_H
#define LCOLORDIALOG_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lcolorplane.h"
#include "lcombobox.h"
#include "ldialog.h"
#include "llineeditor.h"
#include "lradiobutton.h"
#include "lradiobuttonpool.h"
#include "lslider.h"

LAYERS_NAMESPACE_BEGIN
/*!
	![LColorDialog Example](color_dialog.png)

	An LColorDialog is an LDialog that provides an interface for changing a
	color value.

	The dialog contains an LColorPlane which displays&mdash;and makes colors
	selectable from&mdash;an HSV cylinder. Since the plane can only display two
	dimensions at a time, the dialog has an LSlider, referred to as
	the *Z-Slider*, that is linked to the plane's Z-axis attribute.

	For each dimension of HSV, the dialog contains an LRadioButton and an
	LLineEditor. The radio buttons control the plane's Z-dimension. The line
	editors control the HSV values individually via numerical text.

	There is also another line editor that displays and edits the color's name,
	referred to as the *Color Name Editor*.

	Once the desired color is selected, there is an LButton labeled 'Apply'
	which wraps up execution of the dialog when clicked.
*/
class LAYERS_EXPORT LColorDialog : public LDialog
{
	Q_OBJECT

public:
	/*!
		Constructs a color dialog.
	*/
	LColorDialog(QWidget* parent = nullptr);

	~LColorDialog();

	/*!
		Returns a pointer to the dialog's color attribute.
	*/
	LAttribute* color() const;

private slots:
	void hsv_changed();

private:
	void init_attributes();
	void init_layout();

	LButton* m_apply_button{
		new LButton(LGraphic(":/images/check.svg", QSize(16, 13)), "Apply") };

	LLabel* m_color_unit_label{ new LLabel("#")};

	LLineEditor* m_color_name_editor{ new LLineEditor };

	LColorPlane* m_color_plane{ new LColorPlane };

	LSlider* m_z_slider{ new LSlider(MAX_H) };

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
LAYERS_NAMESPACE_END

#endif // LCOLORDIALOG_H
