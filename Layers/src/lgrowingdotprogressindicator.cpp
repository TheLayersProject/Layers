#include <Layers/lgrowingdotprogressindicator.h>

#include <QPainter>
#include <QPainterPath>

using Layers::LGrowingDotProgressIndicator;

LGrowingDotProgressIndicator::LGrowingDotProgressIndicator(QWidget* parent) :
	QWidget(parent)
{
	setFixedSize(24, 24);

	m_progress_timer->setSingleShot(true);

	m_update_timer_timeout_connection =
		connect(m_update_timer, &QTimer::timeout, [this]
			{ QWidget::update(); });

	m_progress_timer_timeout_connection =
		connect(m_progress_timer, &QTimer::timeout, [this]
		{
			emit timeout();

			m_update_timer->stop();
		});
}

LGrowingDotProgressIndicator::~LGrowingDotProgressIndicator()
{
	disconnect(m_update_timer_timeout_connection);
	disconnect(m_progress_timer_timeout_connection);
}

void LGrowingDotProgressIndicator::start(int msec)
{
	m_progress_timer->start(msec);

	m_update_timer->start(17);
}

void LGrowingDotProgressIndicator::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	QStringList s = state_combo();

	QPoint center = rect().center() + QPoint(1, 1);

	qreal outline_outer_radius = (width() / 2);
	qreal outline_inner_radius = outline_outer_radius - 2;

	// Draw Outline Circle

	QPainterPath outline_inner_path;
	QPainterPath outline_outer_path;

	outline_inner_path.addEllipse(
		center, outline_inner_radius, outline_inner_radius);
	outline_outer_path.addEllipse(
		center, outline_outer_radius, outline_outer_radius);
	outline_outer_path = outline_outer_path - outline_inner_path;

	painter.fillPath(outline_outer_path, m_color->as<QColor>(s));

	// Draw Growing Dot

	qreal interval = m_progress_timer->interval();

	qreal time_progressed =
		interval - qreal(m_progress_timer->remainingTime());

	qreal dot_radius =
		(outline_inner_radius + 1) * (time_progressed / interval);

	QPainterPath dot_path;

	dot_path.addEllipse(center, dot_radius, dot_radius);

	painter.fillPath(dot_path, m_color->as<QColor>(s));
}
