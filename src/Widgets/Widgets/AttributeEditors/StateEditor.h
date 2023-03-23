#ifndef STATEEDITOR_H
#define STATEEDITOR_H

#include "AttributeEditor.h"
#include "ComboBox.h"
#include "Label.h"

namespace Layers
{
	class StateEditor : public AttributeEditor
	{
		Q_OBJECT

	public:
		StateEditor(QWidget* parent = nullptr);

		void add_modifier_widget(AttributeEditor* attribute_widget);

		ComboBox* state_combobox() const;

		void populate_state_combobox(const QList<QString>& states);

	private:
		void setup_layout();

		ComboBox* m_state_combobox{ new ComboBox };

		Label* m_label{ new Label("State") };

		QList<AttributeEditor*> m_child_attribute_widgets{ QList<AttributeEditor*>() };

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		QVBoxLayout* m_widgets_vbox{ new QVBoxLayout };
	};
}

#endif // STATEEDITOR_H
