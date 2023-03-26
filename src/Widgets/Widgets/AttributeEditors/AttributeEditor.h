#ifndef ATTRIBUTEEDITOR_H
#define ATTRIBUTEEDITOR_H

//#include "Graphic.h"
//#include "Label.h"
#include "ToggleSwitch.h"

namespace Layers
{
	class AttributeEditor : public Widget
	{
		Q_OBJECT

	signals:
		void widget_disabled();

	public:
		AttributeEditor(AbstractAttribute* entity = nullptr, QWidget* parent = nullptr);
		~AttributeEditor();

		ToggleSwitch* disable_toggle() const;

		bool disabled() const;

		Widget* toggle_label_separator() const;

	public slots:
		virtual void set_current_editting_state(const QString& state);

	protected:
		void init_attributes();

		AbstractAttribute* m_entity;

		ToggleSwitch* m_disabled_toggle{ new ToggleSwitch };

		Widget* m_toggle_label_separator{ new Widget };
	};
}

#endif // ATTRIBUTEEDITOR_H
