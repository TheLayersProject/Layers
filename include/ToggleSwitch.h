#ifndef TOGGLESWITCH_H
#define TOGGLESWITCH_H

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "Widget.h"

namespace Layers
{
	class Label;

	class ToggleSwitch : public Widget
	{
		Q_OBJECT

	signals:
		void toggled_event();

	public:
		ToggleSwitch(bool vertical = false, QWidget* parent = nullptr);

		void replace_all_attributes_with(ToggleSwitch* fill_aw);

		void setFixedHeight(int h);

		void set_toggled(bool toggled);

		void toggle(bool emit_toggled_event = true);

		bool toggled() const;

		void update_layout_margins();

		void update_spacer_size();

		Attribute a_padding_left{ Attribute("Left Padding", QVariant::fromValue(2))};
		Attribute a_padding_top{ Attribute("Top Padding", QVariant::fromValue(2)) };
		Attribute a_padding_right{ Attribute("Right Padding", QVariant::fromValue(2)) };
		Attribute a_padding_bottom{ Attribute("Bottom Padding", QVariant::fromValue(2)) };

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();

		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		QHBoxLayout* m_layout_h{ nullptr };

		QVBoxLayout* m_layout_v{ nullptr };

		Widget* m_spacer{ new Widget };
		Widget* m_square{ new Widget };

		bool m_vertical{ false };
	};
}

#endif // TOGGLESWITCH_H
