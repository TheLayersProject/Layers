#ifndef LCOLORPLANE_H
#define LCOLORPLANE_H

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lcalculate.h>
#include <Layers/lcolor.h>

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
/*!
	![LColorPlane Example](color_plane.png)
	
	An LColorPlane is a QWidget that serves as a two-dimensional slider for
	selecting a color from an HSV cylinder.

	A small cursor is displayed on the plane where the selected color is
	located. Clicking/dragging the mouse cursor anywhere on the plane will
	select the color underneath it.

	## Changing Dimensions

	The plane can only represent two dimensions of an HSV cylinder at a time.
	The plane dimensions depend on the active HSV-dimension set for the Z-axis,
	referred to as the *Z-dimension*. For example, if the Z-dimension is set
	to *Saturation*, then the plane will represent the *Hue* and *Value*
	dimensions.

	| Z-Axis Dimension | Plane (Cycling Z-Axis)                                           |
	|------------------|-----------------------------------------------------------------------|
	| Hue              | \htmlonly<video style="max-width:100%;height:auto" width="180" autoplay loop muted disableremoteplayback><source src="color_plane_cycle_hue.mp4" type="video/mp4">Your browser does not support the video tag.</video>\endhtmlonly |
	| Saturation       | \htmlonly<video style="max-width:100%;height:auto" width="180" autoplay loop muted disableremoteplayback><source src="color_plane_cycle_sat.mp4" type="video/mp4">Your browser does not support the video tag.</video>\endhtmlonly |
	| Value            | \htmlonly<video style="max-width:100%;height:auto" width="180" autoplay loop muted disableremoteplayback><source src="color_plane_cycle_val.mp4" type="video/mp4">Your browser does not support the video tag.</video>\endhtmlonly |

	## Controlling the Z-Axis Value

	The Z-axis is represented with an LAttribute intended to be linked to an
	external control widget, such as an LSlider. The following is an example of
	how this can be setup:

	~~~~~~~~~~~~~{.c}
	LColorPlane* color_plane = new LColorPlane;
	LSlider* z_slider = new LSlider(MAX_H);

	z_slider->value()->set_link_attribute(color_plane->z_axis());

	connect(color_plane, &LColorPlane::z_dimension_changed,
		[this]
		{
			switch (color_plane->z_dimension())
				{
				case HSV::Hue:
					z_slider->set_limit(MAX_H);
					break;
				case HSV::Saturation:
				case HSV::Value:
					z_slider->set_limit(MAX_SV);
					break;
				}
		});
	~~~~~~~~~~~~~

	The connection in the example is established to update the slider's limit
	when the Z-axis dimension changes.
*/
class LAYERS_EXPORT LColorPlane : public QWidget
{
	Q_OBJECT

signals:
	/*!
		This signal is emitted when the Z-axis dimension is changed.
	*/
	void z_dimension_changed();

public:
	/*!
		Constructs a color plane.
	*/
	LColorPlane(QWidget* parent = nullptr);

	/*!
		Returns a pointer to the color attribute.
	*/
	LAttribute* color();

	/*!
		Sets the Z-axis dimension to *z_dimension*.
	*/
	void set_z_dimension(HSV z_dimension);

	/*!
		Sets both the minimum and maximum heights of the widget to *h*
		without changing the widths.
	*/
	void setFixedHeight(int h);

	/*!
		Sets both the minimum and maximum sizes of the widget to *s*, thereby
		preventing it from ever growing or shrinking.
	*/
	void setFixedSize(const QSize& s);

	/*!
		Sets the width of the widget to *w* and the height to *h*.
	*/
	void setFixedSize(int w, int h);

	/*!
		Sets both the minimum and maximum width of the widget to *w* without
		changing the heights.
	*/
	void setFixedWidth(int w);

	/*!
		Returns a pointer to the Z-axis attribute.
	*/
	LAttribute* z_axis();

	/*!
		Returns the active Z-axis dimension.
	*/
	HSV z_dimension() const;

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

	void paintEvent(QPaintEvent* event) override;

private slots:
	void update_cursor_position();
	void update_z_axis();

private:
	void handle_mouse_event(QPoint& mouse_pos);

	void init_attributes();

	float pos_as_ratio(int pos, int available_space);

	void update_color(float x_pos_ratio, float y_pos_ratio);

	void update_height_dependencies();
	void update_width_dependencies();

	LAttribute* m_color
		{ new LAttribute("color", QColor("#ff0000"), this) };

	LAttribute* m_z_axis
		{ new LAttribute("z_axis", QVariant::fromValue(0.0), this) };

	HSV m_z_dimension{ HSV::Hue };

	LWidget* m_cursor{ new LWidget(this) };

	int m_draw_height{ 245 };
	int m_draw_width{ 245 };

	const int margin{ 5 };

	bool m_dragging{ false };
};
LAYERS_NAMESPACE_END

#endif // LCOLORPLANE_H