#ifndef LTHEMECOMBOBOX_H
#define LTHEMECOMBOBOX_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lcombobox.h"
#include "lthemecompatibilitycautiondialog.h"

LAYERS_NAMESPACE_BEGIN
class LTheme;
class LThemeComboBoxItemModel;

class LAYERS_EXPORT LThemeComboBox : public LComboBox
{
	Q_OBJECT

public:
	LThemeComboBox(QWidget* parent = nullptr);

	void add_theme(LTheme* theme, bool set_as_current_index = false);

	void clear();

protected:
	virtual bool eventFilter(QObject* object, QEvent* event) override;

	virtual void paintEvent(QPaintEvent* event) override;

private:
	void init_item_delegate();

	LThemeComboBoxItemModel* m_model;

	LThemeCompatibilityCautionDialog* m_compatibility_dialog{
		new LThemeCompatibilityCautionDialog };

	int m_highlighted_index = -1;
};
LAYERS_NAMESPACE_END

#endif // LTHEMECOMBOBOX_H
