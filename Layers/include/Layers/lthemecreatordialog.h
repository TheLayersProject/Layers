#ifndef LCREATETHEMEDIALOG_H
#define LCREATETHEMEDIALOG_H

#include "layers_global.h"
#include "layers_exports.h"

#include "ldialog.h"
#include "llineeditor.h"
#include "lthemecombobox.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeCreatorDialog : public LDialog
{
	Q_OBJECT

public:
	LThemeCreatorDialog(QWidget* parent = nullptr);

public slots:
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
