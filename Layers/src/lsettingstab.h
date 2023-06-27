#ifndef LSETTINGSTAB_H
#define LSETTINGSTAB_H

#include <QHBoxLayout>

#include <Layers/layers_global.h>

#include <Layers/lwidget.h>

LAYERS_NAMESPACE_BEGIN
class LLabel;
class LThemesWidget;

class LSettingsTab : public LWidget
{
	Q_OBJECT

signals:
	void clicked();

public:
	LSettingsTab(const LGraphic& icon, const QString& label_text, QWidget* parent = nullptr);

	int recommended_minimum_width();

	LStatePool* select_states() const;

	void set_disabled(bool cond = true);

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

	void init_attributes();

	//void resizeEvent(QResizeEvent* event);

private:
	void init_layout();

	QHBoxLayout* main_layout{ new QHBoxLayout };

	bool m_disabled{ false };

	LLabel* m_icon_label;

	LLabel* m_text_label;

	LStatePool* m_select_states{
		new LStatePool("Select", { "Selected", "Unselected" }) };
};
LAYERS_NAMESPACE_END

#endif // LSETTINGSTAB_H
