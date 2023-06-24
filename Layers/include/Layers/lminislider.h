#ifndef LMINISLIDER_H
#define LMINISLIDER_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LMiniSlider is a LWidget that provides a mechanism for a user to control
	a numerical value within a set range.
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
	LAttribute& value();

public slots:
	void set_current_editing_state(const QString& state);

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

	void init_attributes();

private:
	void init_layout();

	void update_handle_pos();

	LAttribute a_value{ LAttribute("value", QVariant::fromValue(0.0)) };

	LWidget* m_bar{ new LWidget };
	LWidget* m_handle{ new LWidget(this) };

	double m_limit;

	int m_mouse_move_scale{ 5 };
	int m_value_on_click{ 0 };

	bool m_dragging_handle{ false };

	QPoint m_mouse_click_position{ QPoint() };
};
LAYERS_NAMESPACE_END

#endif // LMINISLIDER_H
