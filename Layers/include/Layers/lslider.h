#ifndef LSLIDER_H
#define LSLIDER_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
/*!
	![LSlider Example](slider.png)
	
	An LSlider is an LWidget that provides a mechanism for changing a
	numerically-valued LAttribute within a limited range.

	If you need a slider that can fit into smaller spaces, consider using an
	LMiniSlider.

	By click-dragging on the slider handle, a user can change the attribute
	linked to it.

	The following demonstrates how to link the slider's *value* attribute
	with another attribute:

	~~~~~~~~~~~~~{.c}
	LWidget* widget = new LWidget;
	LSlider* slider = new LSlider(30.0);

	slider->value()->set_link_attribute(widget->border_thickness());
	~~~~~~~~~~~~~

	In the example, after the call to LAttribute::set_link_attribute(),
	the *widget*'s border thickness will change when the slider is interacted
	with.
*/
class LAYERS_EXPORT LSlider : public LWidget
{
	Q_OBJECT

public:
	/*!
		Constructs a decimal slider whose value is equal-to or between 0 and 1.
	*/
	LSlider(QWidget* parent = nullptr);

	/*!
		Constructs a slider with a fixed *limit*.
	*/
	LSlider(int limit, QWidget* parent = nullptr);

	/*!
		Sets the upper limit of the slider.
	*/
	void set_limit(int limit);

	/*!
		Returns a reference to the value attribute of the slider.
	*/
	LAttribute* value();

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

private:
	void init();

	void init_attributes();

	void init_layout();

	void update_handle_pos();

	LAttribute* m_value
		{ new LAttribute("value", QVariant::fromValue(0.0), this) };

	LWidget* m_bar{ new LWidget };
	LWidget* m_handle{ new LWidget(this) };

	int m_limit{ 99 };
	double m_value_on_click{ 0.0 };

	bool m_dragging_handle{ false };

	bool m_is_decimal_slider;

	QPoint m_mouse_click_position{ QPoint() };
};
LAYERS_NAMESPACE_END

#endif // LSLIDER_H
