#ifndef LGROWINGDOTPROGRESSINDICATOR_H
#define LGROWINGDOTPROGRESSINDICATOR_H

#include <QTimer>
#include <QWidget>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LGrowingDotProgressIndicator :
	public QWidget, public LThemeable
{
	Q_OBJECT

signals:
	void timeout();

public:
	LGrowingDotProgressIndicator(QWidget* parent = nullptr);

	~LGrowingDotProgressIndicator();

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
