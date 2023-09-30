#ifndef LMINISLIDER_H
#define LMINISLIDER_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LMiniSlider : public LWidget
{
	Q_OBJECT

public:
	LMiniSlider(double limit = 99.0, QWidget* parent = nullptr);

	void set_limit(double limit);

	LAttribute* value();

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

private:
	double drag_increment() const;

	void init_attributes();

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
