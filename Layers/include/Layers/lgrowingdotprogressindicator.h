#ifndef LGROWINGDOTPROGRESSINDICATOR_H
#define LGROWINGDOTPROGRESSINDICATOR_H

#include <QTimer>
#include <QWidget>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
/*!
	\htmlonly
		<video style="max-width:100%;height:auto;" width="120" height="120"
		autoplay loop muted disableRemotePlayback>
			<source src="growing_dot_progress_indicator.mp4" type="video/mp4">
			Your browser does not support the video tag.
		</video>
	\endhtmlonly
	
	An LGrowingDotProgressIndicator is a QWidget and an LThemeable that conveys
	progression to the user.
*/
class LAYERS_EXPORT LGrowingDotProgressIndicator :
	public QWidget, public LThemeable
{
	Q_OBJECT

signals:
	/*!
		This signal is emitted when the progression ends.
	*/
	void timeout();

public:
	/*!
		Constructs a growing-dot progress indicator.
	*/
	LGrowingDotProgressIndicator(QWidget* parent = nullptr);

	~LGrowingDotProgressIndicator();

	/*!
		Starts the progression timer to run for *msec* milliseconds.
	*/
	void start(int msec);

protected:
	void paintEvent(QPaintEvent* event) override;

private:
	QTimer* m_progress_timer{ new QTimer };
	QTimer* m_update_timer{ new QTimer };

	QMetaObject::Connection m_progress_timer_timeout_connection;
	QMetaObject::Connection m_update_timer_timeout_connection;

	LAttribute* m_color{
		new LAttribute("Color", QColor(Qt::lightGray), this) };
};
LAYERS_NAMESPACE_END

#endif // LGROWINGDOTPROGRESSINDICATOR_H
