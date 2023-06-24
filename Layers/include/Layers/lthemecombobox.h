#ifndef LTHEMECOMBOBOX_H
#define LTHEMECOMBOBOX_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lcombobox.h"

LAYERS_NAMESPACE_BEGIN
class LThemeComboBoxItemModel;

/*!
	An LThemeComboBox is a LComboBox that displays LTheme items.

	Each item displays two pieces of theme metadata: the theme's name and
	its UUID.
*/
class LAYERS_EXPORT LThemeComboBox : public LComboBox
{
	Q_OBJECT

public:
	/*!
		Constructs a theme combo box.
	*/
	LThemeComboBox(QWidget* parent = nullptr);

	/*!
		Adds a theme to the combo box's item model.
	*/
	void addItem(LTheme* theme);

	/*!
		Clears the combo box's item model.
	*/
	void clear();

protected:
	virtual bool eventFilter(QObject* object, QEvent* event) override;

	virtual void paintEvent(QPaintEvent* event) override;

private:
	LThemeComboBoxItemModel* m_model;
};
LAYERS_NAMESPACE_END

#endif // LTHEMECOMBOBOX_H
