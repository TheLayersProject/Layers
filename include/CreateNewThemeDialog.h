#ifndef CREATENEWTHEMEDIALOG_H
#define CREATENEWTHEMEDIALOG_H

#include "Combobox.h"
#include "Dialog.h"
#include "LineEditor.h"

namespace Layers
{
	class CreateNewThemeDialog : public Dialog
	{
		Q_OBJECT

	public:
		CreateNewThemeDialog(QWidget* parent = nullptr);

		void add_theme_name_to_combobox(const QString& theme_name);

		void clear();

		QString copy_theme_name();

		QString new_theme_name();

		void set_current_start_theme_name(const QString& theme_name);

	protected:
		void init_attributes();
		void init_child_themeable_list();

	private:
		void setup_layout();

		Button* m_create_button{ new Button("Create") };

		Combobox* m_start_theme_combobox{ new Combobox };

		Label* m_name_label{ new Label("Name") };
		Label* m_start_as_label{ new Label("Start as copy of") };

		LineEditor* m_theme_name_line_edit{ new LineEditor };
	};
}

#endif // CREATENEWTHEMEDIALOG_H
