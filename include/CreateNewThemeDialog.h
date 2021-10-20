#ifndef CREATENEWTHEMEDIALOG_H
#define CREATENEWTHEMEDIALOG_H

#include <QDialog>

#include "Button.h"
#include "Combobox.h"
#include "LineEditor.h"

namespace Layers
{
	class CreateNewThemeDialog : public QDialog, public Themeable
	{
		Q_OBJECT

	public:
		CreateNewThemeDialog(QWidget* parent = nullptr);

		void add_theme_name_to_combobox(const QString& theme_name);

		void clear();

		QString copy_theme_name();

		void issue_update();

		QString new_theme_name();

		void set_current_start_theme_name(const QString& theme_name);

		void update_theme_dependencies();

	protected:
		void init_attributes();
		void init_child_themeable_reference_list();

		bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;

		void paintEvent(QPaintEvent* event) override;

	private:
		void init_titlebar();

		void setup_layout();

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		Widget* m_titlebar{ new Widget };

		Button* m_create_button{ new Button("Create") };

		Combobox* m_start_theme_combobox{ new Combobox };

		Label* m_name_label{ new Label("Name") };
		Label* m_start_as_label{ new Label("Start as copy of") };

		LineEditor* m_theme_name_line_edit{ new LineEditor };

		QPainter painter;
	};
}

#endif // CREATENEWTHEMEDIALOG_H
