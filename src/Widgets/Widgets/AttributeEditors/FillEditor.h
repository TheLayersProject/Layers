#ifndef FILLEDITOR_H
#define FILLEDITOR_H

#include "AttributeEditor.h"
#include "FillControl.h"
#include "Label.h"

namespace Layers
{
	class FillEditor : public AttributeEditor
	{
		Q_OBJECT

	public:
		FillEditor(Attribute* attribute, QWidget* parent = nullptr);

		FillControl* fill_control() const;

	public slots:
		virtual void set_current_editing_state(const QString& state) override;

	private:
		FillControl* m_fill_control{ new FillControl };

		Label* m_attribute_label{ new Label };
	};
}

#endif // FILLEDITOR_H
