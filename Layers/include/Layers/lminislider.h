#ifndef LMINISLIDER_H
#define LMINISLIDER_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
/*!
	![LMiniSlider Example](mini_slider.png)
	
	An LMiniSlider is an LWidget that provides a mechanism for changing a
	numerically-valued LAttribute within a limited range. Mini sliders are
	intended to fit into smaller spaces. If a larger slider is needed, see
	LSlider.

	By click-dragging on the slider, a user can change the attribute linked to
	it.

	The following demonstrates how to link the slider's *value* attribute
	with another attribute:

	~~~~~~~~~~~~~{.c}
	LWidget* widget = new LWidget;
	LMiniSlider* slider = new LMiniSlider(30.0);

	slider->value()->set_link_attribute(widget->border_thickness());
	~~~~~~~~~~~~~

	In the example, after the call to LAttribute::set_link_attribute(),
	the *widget*'s border thickness will change when the slider is interacted
	with.
*/
class LAYERS_EXPORT LMiniSlider : public LWidget
{
	Q_OBJECT

public:
	/*!
		Constructs a mini-slider with a fixed *limit*.
	*/
	LMiniSlider(double limit = 99.0, QWidget* parent = nullptr);

	/*!
		Sets the upper limit of the slider.
	*/
	void set_limit(double limit);

	/*!
		Returns a reference to the value attribute of the slider.
	*/
	LAttribute* value();

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

	void init_attributes();

private:
	double drag_increment() const;

	void init_layout();

	void update_handle_pos();

	LAttribute* m_value
		{ new LAttribute("value", QVariant::fromValue(0.0), this) };

	LWidget* m_bar{ new LWidget };
	LWidget* m_handle{ new LWidget(this) };

	double m_limit;

	int m_mouse_move_scale{ 5 };
	int m_value_on_click{ 0 };

	bool m_dragging_handle{ false };

	QPoint m_mouse_click_position;
};
LAYERS_NAMESPACE_END

#endif // LMINISLIDER_H
