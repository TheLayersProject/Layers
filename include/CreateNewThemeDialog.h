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

		Attribute a_border_fill{ Attribute("Border Fill", QColor(Qt::gray)) };
		Attribute a_border_thickness{ Attribute("Border Thickness", QVariant::fromValue(0)) };
		Attribute a_corner_color{ Attribute("Corner Color", QColor(Qt::gray), true) };
		Attribute a_corner_radius_tl{ Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) };
		Attribute a_corner_radius_tr{ Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) };
		Attribute a_corner_radius_bl{ Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) };
		Attribute a_corner_radius_br{ Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) };
		Attribute a_fill{ Attribute("Fill", QColor(Qt::white)) };
		Attribute a_hover_fill{ Attribute("Hover Fill", QColor(Qt::lightGray), true) };
		Attribute a_margin_left{ Attribute("Left Margin", QVariant::fromValue(0)) };
		Attribute a_margin_top{ Attribute("Top Margin", QVariant::fromValue(0)) };
		Attribute a_margin_right{ Attribute("Right Margin", QVariant::fromValue(0)) };
		Attribute a_margin_bottom{ Attribute("Bottom Margin", QVariant::fromValue(0)) };
		Attribute a_outline_color{ Attribute("Outline Color", QColor(Qt::gray), true) };

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

		Button* m_create_button{ new Button("Create") };

		Combobox* m_start_theme_combobox{ new Combobox };

		Label* m_name_label{ new Label("Name") };
		Label* m_start_as_label{ new Label("Start as copy of") };

		LineEditor* m_theme_name_line_edit{ new LineEditor };

		QPainter painter;
	};
}

#endif // CREATENEWTHEMEDIALOG_H
