#ifndef LCREATETHEMEDIALOG_H
#define LCREATETHEMEDIALOG_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemecombobox.h"
#include "ldialog.h"
#include "llineeditor.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LCreateThemeDialog : public LDialog
{
	Q_OBJECT

public:
	LCreateThemeDialog(QWidget* parent = nullptr);

	void add_theme_to_combobox(LTheme* theme);

	void clear();

	void clear_theme_combobox();

	QString copy_theme_id();

	QString new_theme_name();

	void set_current_start_theme_name(const QString& theme_name);

public slots:
	virtual int	exec();

protected:
	void init_attributes();

private:
	void init_layout();

	LButton* m_create_button{ new LButton("Create") };

	LThemeComboBox* m_start_theme_combobox{ new LThemeComboBox };

	LLabel* m_name_label{ new LLabel("Name") };
	LLabel* m_start_as_label{ new LLabel("Start as copy of") };

	LLineEditor* m_theme_name_line_editor{ new LLineEditor };
};
LAYERS_NAMESPACE_END

#endif // LCREATETHEMEDIALOG_H
