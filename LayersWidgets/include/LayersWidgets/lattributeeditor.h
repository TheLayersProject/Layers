#ifndef LATTRIBUTEEDITOR_H
#define LATTRIBUTEEDITOR_H

#include "layerswidgetsexports.h"

#include "ltoggleswitch.h"

namespace Layers
{
	class LAYERS_WIDGETS_EXPORT LAttributeEditor : public LWidget
	{
		Q_OBJECT

	signals:
		void widget_disabled();

	public:
		LAttributeEditor(LAbstractAttribute* entity = nullptr, QWidget* parent = nullptr);
		~LAttributeEditor();

		LToggleSwitch* disable_toggle() const;

		bool disabled() const;

		LWidget* toggle_label_separator() const;

	public slots:
		virtual void set_current_editing_state(const QString& state);

	protected:
		void init_attributes();

		LAbstractAttribute* m_entity;

		LToggleSwitch* m_disabled_toggle{ new LToggleSwitch };

		LWidget* m_toggle_label_separator{ new LWidget };
	};
}

#endif // LATTRIBUTEEDITOR_H
