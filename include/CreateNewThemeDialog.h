#ifndef CREATENEWTHEMEDIALOG_H
#define CREATENEWTHEMEDIALOG_H

#include <QDialog>

#include "Button.h"
#include "Combobox.h"
#include "Graphic.h"
#include "LineEditor.h"

namespace Layers
{
	class CreateNewThemeDialog : public QDialog, public Themeable
	{
		Q_OBJECT

	public:
		CreateNewThemeDialog(QWidget* parent = nullptr);

		void add_theme_name_to_combobox(const QString& theme_name);

		virtual void apply_theme_attributes(QMap<QString, AttributeType*>& theme_attrs) override;

		void clear();

		QString copy_theme_name();

		QString new_theme_name();

		void set_current_start_theme_name(const QString& theme_name);

		BorderAttributes border;

		CornerRadiiAttributes corner_radii;

		MarginsAttributes margins;

		Attribute a_corner_color{ Attribute(
			"corner_color",
			QColor(Qt::gray),
			true
			) };

		Attribute a_fill{ Attribute(
			"fill",
			QColor(Qt::white)
			) };

		Attribute a_hover_fill{ Attribute(
			"hover_fill",
			QColor(Qt::lightGray),
			true
			) };

		Attribute a_outline_color{ Attribute(
			"outline_color",
			QColor(Qt::gray),
			true
			) };

	protected:
		void init_attributes();
		void init_child_themeable_reference_list();

		bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;

		void paintEvent(QPaintEvent* event) override;

	private:
		void init_titlebar();

		void setup_layout();

		bool m_hovering{ false };

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		Widget* m_titlebar{ new Widget };

		Label* m_window_title_label = new Label("Create New Theme");

		Button* m_exit_button = new Button(new Graphic(":/svgs/exit.svg", QSize(20, 20)), true);

		Button* m_create_button{ new Button("Create") };

		Combobox* m_start_theme_combobox{ new Combobox };

		Label* m_name_label{ new Label("Name") };
		Label* m_start_as_label{ new Label("Start as copy of") };

		LineEditor* m_theme_name_line_edit{ new LineEditor };

		QPainter painter;
	};
}

#endif // CREATENEWTHEMEDIALOG_H
