#ifndef TOGGLESWITCH_H
#define TOGGLESWITCH_H

#include <QGraphicsOpacityEffect>

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
		ToggleSwitch(QWidget* parent = nullptr);
		ToggleSwitch(const QString& first_label_text, const QString& second_label_text, QWidget* parent = nullptr);

		void set_toggled(bool toggled);

		void toggle();

		bool toggled() const;

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();

		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		Label* m_first_label{ nullptr };
		Label* m_second_label{ nullptr };

		QGraphicsOpacityEffect* m_first_label_opacity{ new QGraphicsOpacityEffect };
		QGraphicsOpacityEffect* m_second_label_opacity{ new QGraphicsOpacityEffect };

		Widget* m_spacer{ new Widget };
		Widget* m_square{ new Widget };
		Widget* m_switch{ new Widget };
	};
}

#endif // TOGGLESWITCH_H
