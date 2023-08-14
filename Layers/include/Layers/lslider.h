#ifndef LSLIDER_H
#define LSLIDER_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LSlider is a LWidget that provides a mechanism for a user to control a
	numerical value within a set range.
*/
class LAYERS_EXPORT LSlider : public LWidget
{
	Q_OBJECT

public:
	/*!
		Constructs a slider delimited by a ratio (0:1).
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

	LAttribute* m_value{
		new LAttribute("value", QVariant::fromValue(0.0), this) };

	LWidget* m_bar{ new LWidget };
	LWidget* m_handle{ new LWidget(this) };

	int m_limit{ 99 };
	double m_value_on_click{ 0.0 };

	bool m_dragging_handle{ false };

	bool m_is_ratio_slider;

	QPoint m_mouse_click_position{ QPoint() };
};
LAYERS_NAMESPACE_END

#endif // LSLIDER_H
