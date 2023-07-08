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

protected:
	void init_attributes();
	void init_layout();

	QHBoxLayout* m_controls_layout{ new QHBoxLayout };
	QHBoxLayout* m_icons_layout{ new QHBoxLayout };

	QVBoxLayout* m_links_layout{ new QVBoxLayout };

	LFillControl* m_fill_control{ new LFillControl };

	LLabel* m_label{ new LLabel };

	LLineEditor* m_line_editor{ new LLineEditor };

	LMiniSlider* m_slider{ new LMiniSlider };

	LAttribute* m_attr;

	LButton* m_collapse_button{
		new LButton(
			LGraphic(":/images/collapse_arrow_right.svg", QSize(8, 12)),
			LGraphic(":/images/collapse_arrow_down.svg", QSize(12, 8))) };

	LWidget* m_icons_widget{ new LWidget };

	LLabel* control_icon_label{
		new LLabel(LGraphic(":/images/settings.svg"), m_icons_widget) };

	LTabBar* m_features_tab_bar{ new LTabBar };

	QWidget* m_features_widget{ new QWidget };

	LWidget* m_links_widget{ new LWidget };
};
LAYERS_NAMESPACE_END

#endif // LATTRIBUTEEDITOR_H
