#ifndef LWIDGETBUTTONGROUP_H
#define LWIDGETBUTTONGROUP_H

#include <QVBoxLayout>

#include "layers_global.h"
#include "layers_exports.h"

#include "lbutton.h"
#include "lwidgetbutton.h"

LAYERS_NAMESPACE_BEGIN
class LWidgetButtonGroup : public LWidget
{
	Q_OBJECT

public:
	LWidgetButtonGroup(
		const QString& label_text,
		QList<LWidgetButton*> widget_buttons,
		QWidget* parent = nullptr);

	void set_collapsed(bool collapsed = true);

	QList<LWidgetButton*>& widget_buttons();

private:
	void init_attributes();

	void init_layout();

	LButton* m_collapse_button{
		new LButton(
			LGraphic(":/images/collapse_arrow_right.svg", QSize(8, 12)),
			LGraphic(":/images/collapse_arrow_down.svg", QSize(12, 8))) };

	bool m_collapsed{ true };

	LLabel* m_label{ nullptr };

	QList<LWidgetButton*> m_widget_buttons{ QList<LWidgetButton*>() };

	QVBoxLayout* m_widget_buttons_vbox{ new QVBoxLayout };
};
LAYERS_NAMESPACE_END

#endif // LWIDGETBUTTONGROUP_H
