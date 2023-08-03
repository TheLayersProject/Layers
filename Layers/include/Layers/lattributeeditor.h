#ifndef LATTRIBUTEEDITOR_H
#define LATTRIBUTEEDITOR_H

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "layers_global.h"
#include "layers_exports.h"

#include "lbutton.h"
#include "lfillcontrol.h"
#include "llabel.h"
#include "llineeditor.h"
#include "lminislider.h"
#include "ltabbar.h"
#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LLinksWidget : public LWidget
{
	Q_OBJECT

public:
	LLinksWidget(LAttribute* attr, QWidget* parent = nullptr);

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

class LAYERS_EXPORT LAttributeEditor : public LWidget
{
	Q_OBJECT

public:
	LAttributeEditor(LAttribute* attr, QWidget* parent = nullptr);

	/*!
		Returns a list of child themeables.

		This function overrides LThemeable::child_themeables() to include
		additional child themeables.
	*/
	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
	) override;

	LFillControl* fill_control() const;

	LLineEditor* line_editor() const;

	LMiniSlider* slider() const;

private:
	void init_attributes();
	void init_layout();

	QHBoxLayout* m_controls_layout{ new QHBoxLayout };
	QHBoxLayout* m_icons_layout{ new QHBoxLayout };
	QVBoxLayout* m_overrides_layout{ new QVBoxLayout };

	LFillControl* m_fill_control{ new LFillControl };

	LLabel* m_label{ new LLabel };

	LMiniSlider* m_slider{ new LMiniSlider };

	LLineEditor* m_line_editor{ new LLineEditor };

	LAttribute* m_attr;

	LButton* m_collapse_button{
		new LButton(
			LGraphic(":/images/collapse_arrow_right.svg", QSize(8, 12)),
			LGraphic(":/images/collapse_arrow_down.svg", QSize(12, 8))) };

	LWidget* m_icons_widget{ new LWidget };

	LTabBar* m_features_tab_bar{ new LTabBar };

	QWidget* m_features_widget{ new QWidget };

	LLinksWidget* m_links_widget;

	LWidget* m_overrides_widget{ new LWidget };
};
LAYERS_NAMESPACE_END

#endif // LATTRIBUTEEDITOR_H
