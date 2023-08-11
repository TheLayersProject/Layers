#ifndef LLINKSVIEW
#define LLINKSVIEW

#include <QWidget>

#include <Layers/layers_global.h>

#include <Layers/lsvgrenderer.h>
#include <Layers/lthemeable.h>

LAYERS_NAMESPACE_BEGIN
class LLinksView : public QWidget, public LThemeable
{
	Q_OBJECT

public:
	LLinksView(LAttribute* attr, QWidget* parent = nullptr);

	void update_view();

protected:
	virtual void paintEvent(QPaintEvent* event) override;

private:
	void paint_item_dot(
		QPainter* painter,
		const QRect& item_rect,
		int x);

	void paint_item_text(
		QPainter* painter,
		const QString& text,
		const QRect& item_rect,
		QFont font,
		int x);

	void update_height();

	LAttribute* m_attr;

	LAttribute* m_text_color{
		new LAttribute("Text Color", QColor(Qt::black), this) };

	QString m_parent_path;

	QStringList m_link_paths;
	QStringList m_dependent_paths;

	LSvgRenderer* m_dot_svg{ new LSvgRenderer(":/images/dot.svg", this) };

	LSvgRenderer* m_link_arrow_svg{
		new LSvgRenderer(":/images/link_arrow.svg", this) };

	LSvgRenderer* m_dependent_arrow_svg{
		new LSvgRenderer(":/images/dependent_arrow.svg", this) };

	LSvgRenderer* m_dependent_arrow_2_svg{
		new LSvgRenderer(":/images/dependent_arrow_2.svg", this) };
};
LAYERS_NAMESPACE_END

#endif // LLINKSVIEW
