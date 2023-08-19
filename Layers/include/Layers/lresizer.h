#ifndef LRESIZER_H
#define LRESIZER_H

#include "layers_global.h"
#include "layers_exports.h"

#include "llabel.h"

LAYERS_NAMESPACE_BEGIN
enum class LAYERS_EXPORT LSizeDimension { Width, Height };

/*!
	\htmlonly
		<video style="max-width:100%;height:auto;" width="448" height="376"
		autoplay loop muted disableRemotePlayback>
			<source src="resizer.mp4" type="video/mp4">
			Your browser does not support the video tag.
		</video>
	\endhtmlonly
	
	An LResizer is a QWidget and an LThemeable that gives the user a way to
	resize another widget on the screen.

	By click-dragging the resizer, the user can resize the connected widget. To
	connect a widget to the resizer, use set_widget().
*/
class LAYERS_EXPORT LResizer : public QWidget, public LThemeable
{
	Q_OBJECT

public:
	/*!
		Constructs a resizer.
	*/
	LResizer(LSizeDimension resize_dimension, QWidget* parent = nullptr);

	/*!
		Sets the *widget* that the resizer resizes.

		The *lower_limit* and *upper_limit* parameters are used to restrict the
		widget's size.
	*/
	void set_widget(QWidget* widget, int lower_limit, int upper_limit);

protected:
	virtual bool eventFilter(QObject* object, QEvent* event) override;

	virtual void paintEvent(QPaintEvent* event) override;

private:
	LSizeDimension m_resize_dimension;

	LSvgRenderer* m_icon_svg{ nullptr };

	QSize m_icon_size;

	LStatePool* m_select_states
		{ new LStatePool("Select", { "Selected", "Unselected" }) };

	QPoint m_click_pos;
	QSize m_click_size;

	QWidget* m_widget{ nullptr };

	int m_lower_limit{ 0 };
	int m_upper_limit{ 1000 };
};
LAYERS_NAMESPACE_END

#endif // LRESIZER_H
