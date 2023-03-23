#ifndef ATTRIBUTEEDITORGROUP_H
#define ATTRIBUTEEDITORGROUP_H

#include "AttributeEditor.h"
#include "Button.h"
#include "Graphic.h"
#include "Label.h"

namespace Layers
{
	class AttributeEditorGroup : public AttributeEditor
	{
		Q_OBJECT

	public:
		AttributeEditorGroup(AttributeGroup* attr_group, QWidget* parent = nullptr);

		void add_modifier_widget(AttributeEditor* attribute_widget);

		void set_collapsed(bool collapsed = true);

		//virtual bool disabled() const;

	public slots:
		virtual void set_current_editting_state(const QString& state) override;

	private:
		void setup_layout();

		Button* m_collapse_button{ new Button(new Graphic(":/svgs/collapse_arrow_right.svg", QSize(8, 12)), new Graphic(":/svgs/collapse_arrow_down.svg", QSize(12, 8)), true) };

		bool m_collapsed{ true };

		Label* m_label{ new Label };

		QList<AttributeEditor*> m_child_attribute_widgets{ QList<AttributeEditor*>() };

		QVBoxLayout* m_widgets_vbox{ new QVBoxLayout };
	};
}

#endif // ATTRIBUTEEDITORGROUP_H
