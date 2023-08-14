#ifndef LCREATETHEMEDIALOG_H
#define LCREATETHEMEDIALOG_H

#include "layers_global.h"
#include "layers_exports.h"

#include "ldialog.h"
#include "llineeditor.h"
#include "lthemecombobox.h"

LAYERS_NAMESPACE_BEGIN
/*!
	![LThemeCreatorDialog Example](theme_creator_dialog.png)

	An LThemeCreatorDialog is an LDialog that provides an interface for creating
	a new LTheme.

	The dialog contains an LLineEditor for the user to enter the new theme's
	name. It also contains an LThemeComboBox for the user to select the parent
	theme that the new theme will inherit from. The parent theme will become
	part of the new theme's lineage.

	There is an LButton labeled 'Create' that creates the new theme when
	clicked. The new theme is also set as the active theme.
*/
class LAYERS_EXPORT LThemeCreatorDialog : public LDialog
{
	Q_OBJECT

public:
	/*!
		Constructs a theme creator dialog.
	*/
	LThemeCreatorDialog(QWidget* parent = nullptr);

public slots:
	/*!
		Shows the dialog as a
		[modal dialog](https://doc.qt.io/qt-6/qdialog.html#modal-dialogs),
		blocking until the user closes it. The function returns a
		[DialogCode](https://doc.qt.io/qt-6/qdialog.html#DialogCode-enum)
		result.

		This function overrides QDialog::exec() to give the *Name Editor*
		focus before QDialog::exec() is processed.
	*/
	virtual int	exec() override;

private slots:
	void create_theme();

private:
	void init_attributes();
	void init_layout();

	LLabel* m_name_label{ new LLabel("Name") };

	LLineEditor* m_name_editor{ new LLineEditor };

	LLabel* m_parent_theme_label{ new LLabel("Parent Theme") };

	LThemeComboBox* m_parent_theme_combobox{ new LThemeComboBox };

	LButton* m_create_button{
		new LButton(LGraphic(":/images/check.svg", QSize(16, 13)), "Create") };
};
LAYERS_NAMESPACE_END

#endif // LCREATETHEMEDIALOG_H
