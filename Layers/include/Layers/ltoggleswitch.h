#ifndef LTOGGLESWITCH_H
#define LTOGGLESWITCH_H

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "layers_global.h"
#include "layers_exports.h"

#include "lstatepool.h"
#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN

class LLabel;

class LAYERS_EXPORT LToggleSwitch : public LWidget
{
	Q_OBJECT

signals:
	void toggled_event(bool toggled);

public:
	LToggleSwitch(bool vertical = false, QWidget* parent = nullptr);

	void set_toggled(bool toggled);

	void setFixedHeight(int h);

	void toggle(bool emit_toggled_event = true);

	bool toggled() const;

	LAttribute a_padding_left{ LAttribute("Left Padding", QVariant::fromValue(2.0)) };
	LAttribute a_padding_top{ LAttribute("Top Padding", QVariant::fromValue(2.0)) };
	LAttribute a_padding_right{ LAttribute("Right Padding", QVariant::fromValue(2.0)) };
	LAttribute a_padding_bottom{ LAttribute("Bottom Padding", QVariant::fromValue(2.0)) };

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

private:
	void init_attributes();

	void init_layout();

	void update_layout_margins();

	void update_spacer_size();

	QHBoxLayout* m_layout_h{ nullptr };

	QVBoxLayout* m_layout_v{ nullptr };

	LWidget* m_spacer{ new LWidget };
	LWidget* m_square{ new LWidget };

	bool m_vertical{ false };

	LStatePool* m_toggle_states{ new LStatePool("Toggle", { "Toggled", "Untoggled" })};
};
LAYERS_NAMESPACE_END

#endif // LTOGGLESWITCH_H
