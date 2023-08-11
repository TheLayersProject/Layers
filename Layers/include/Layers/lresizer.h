#ifndef LRESIZER_H
#define LRESIZER_H

#include "layers_global.h"
#include "layers_exports.h"

#include "llabel.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LResizer : public QWidget, public LThemeable
{
	Q_OBJECT

public:
	LResizer(Qt::Orientation orientation, QWidget* parent = nullptr);

	void set_widget(QWidget* widget, int lower_limit, int upper_limit);

protected:
	virtual bool eventFilter(QObject* object, QEvent* event) override;

	virtual void paintEvent(QPaintEvent* event) override;

private:
	Qt::Orientation m_orientation;

	LSvgRenderer* m_icon_svg{ nullptr };

	QSize m_icon_size;

	LStatePool* m_select_states{
		new LStatePool("Select", { "Selected", "Unselected" }) };

	QPoint m_click_pos;
	QSize m_click_size;

	QWidget* m_widget{ nullptr };

	int m_lower_limit{ 0 };
	int m_upper_limit{ 1000 };
};
LAYERS_NAMESPACE_END

#endif // LRESIZER_H
