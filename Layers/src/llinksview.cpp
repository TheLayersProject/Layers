#include "llinksview.h"

#include <QPainter>
#include <QPainterPath>

using Layers::LLinksView;

LLinksView::LLinksView(LAttribute* attr, QWidget* parent) :
	m_attr{ attr },
	QWidget(parent)
{
	setObjectName("Links View");

	QFont f = font();
	f.setPointSizeF(10.5);
	setFont(f);

	m_dot_svg->setObjectName("Dot Svg");

	m_link_arrow_svg->setObjectName("Link Arrow Svg");

	m_dependent_arrow_svg->setObjectName("Dependent Arrow Svg");
	m_dependent_arrow_2_svg->setObjectName("Dependent Arrow Svg");

	connect(m_attr, &LAttribute::link_changed, this, &LLinksView::update_view);

	update_view();
}

void LLinksView::update_view()
{
	m_link_paths.clear();
	m_dependent_paths.clear();

	if (m_attr)
	{
		if (m_attr->parent())
			if (LThemeItem* parent_theme_item = dynamic_cast<LThemeItem*>(m_attr->parent()))
				m_parent_path = parent_theme_item->path();

		if (LAttribute* link_attr = m_attr->link_attribute())
		{
			while (link_attr)
			{
				QString link_path = link_attr->path();

				if (!m_parent_path.isEmpty())
					if (link_path.startsWith(m_parent_path))
						link_path.replace(m_parent_path, ".");

				m_link_paths.insert(0, link_path);

				link_attr = link_attr->link_attribute();
			}
		}

		for (LAttribute* dependent_attr : m_attr->dependent_attributes())
		{
			QString dependent_path = dependent_attr->path();

			if (!dependent_path.contains("/"))
				continue;

			if (!m_parent_path.isEmpty())
				if (dependent_path.startsWith(m_parent_path))
					dependent_path.replace(m_parent_path, ".");

			m_dependent_paths.append(dependent_path);
		}
	}

	update_height();
	QWidget::update();
}

void LLinksView::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	int item_number = 0;

	for (const QString& link_path : m_link_paths)
	{
		QRect item_rect(
			0, 40 * item_number++,
			width(), 40);

		paint_item_dot(&painter, item_rect, 9);
		paint_item_text(&painter, link_path, item_rect, font(), 27);

		int uplink_arrow_y = item_rect.y() + (item_rect.height() / 2) + 5;
		m_link_arrow_svg->render(&painter,
			QRectF(7, uplink_arrow_y, 12, 34));
	}

	QFont bold_text_font = font();
	bold_text_font.setBold(true);

	QRect this_text_rect = QRect(0, 40 * item_number++, width(), 40);

	paint_item_dot(&painter, this_text_rect, 9);
	paint_item_text(&painter, "This", this_text_rect, bold_text_font, 27);

	for (int i = 0; i < m_dependent_paths.size(); i++)
	{
		const QString& dependent_path = m_dependent_paths[i];

		QRect previous_item_rect(
			0, 40 * (item_number - 1),
			width(), 40);

		if (i == 0)
		{
			int downlink_arrow_y = previous_item_rect.y() + (previous_item_rect.height() / 2) + 5;
			m_dependent_arrow_svg->render(&painter,
				QRectF(7, downlink_arrow_y, 13, 37));
		}
		else
		{
			int downlink_arrow_y = previous_item_rect.y() + (previous_item_rect.height() / 2) - 7;
			m_dependent_arrow_2_svg->render(&painter,
				QRectF(12, downlink_arrow_y, 8, 48));
		}

		QRect item_rect(
			0, 40 * item_number++,
			width(), 40);

		paint_item_dot(&painter, item_rect, 19);
		paint_item_text(&painter, dependent_path, item_rect, font(), 37);
	}
}

void LLinksView::paint_item_dot(
	QPainter* painter,
	const QRect& item_rect,
	int x)
{
	int dot_y = item_rect.y() + (item_rect.height() / 2) - 5;

	m_dot_svg->render(painter,
		QRectF(x, dot_y, 10, 10));
}

void LLinksView::paint_item_text(
	QPainter* painter,
	const QString& text,
	const QRect& item_rect,
	QFont font,
	int x)
{
	const QFontMetrics& font_metrics = QFontMetrics(font);

	QPainterPath text_path;

	text_path.addText(
		QPoint(x, item_rect.center().y() + (font_metrics.height() / 2) - 2),
		font,
		text
	);

	painter->fillPath(text_path, m_text_color->as<QColor>());
}

void LLinksView::update_height()
{
	// 40 is item size

	int new_height = 40;

	if (m_link_paths.isEmpty());
	else
		new_height += 40 * m_link_paths.count();

	new_height += 40 * m_dependent_paths.count();

	setFixedHeight(new_height);
}