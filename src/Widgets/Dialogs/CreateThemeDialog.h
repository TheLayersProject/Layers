#ifndef CREATETHEMEDIALOG_H
#define CREATETHEMEDIALOG_H

#include "ThemeComboBox.h"
#include "Dialog.h"
#include "LineEditor.h"

namespace Layers
{
	class CreateThemeDialog : public Dialog
	{
		Q_OBJECT

	public:
		CreateThemeDialog(QWidget* parent = nullptr);

		void add_theme_to_combobox(Theme* theme);

		void clear();

		void clear_theme_combobox();

		virtual Themeable* clone() override;

		QString copy_theme_id();

		QString new_theme_name();

		void set_current_start_theme_name(const QString& theme_name);

	public slots:
		virtual int	exec();

	protected:
		void init_attributes();

	private:
		void setup_layout();

		Button* m_create_button{ new Button("Create") };

		ThemeComboBox* m_start_theme_combobox{ new ThemeComboBox };

		Label* m_name_label{ new Label("Name") };
		Label* m_start_as_label{ new Label("Start as copy of") };

		LineEditor* m_theme_name_line_editor{ new LineEditor };
	};
}

#endif // CREATETHEMEDIALOG_H
