#ifndef UPDATEDIALOG_H
#define UPDATEDIALOG_H

#include <QDialog>

#include "Button.h"
#include "Graphic.h"

namespace Layers
{
	class UpdateDialog : public QDialog, public Themeable
	{
		Q_OBJECT

	public:
		UpdateDialog(const QString& current_version_tag, const QString& latest_version_tag, QWidget* parent = nullptr);

		virtual void apply_theme_attributes(QMap<QString, AttributeType*>& theme_attrs) override;

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

		Label* m_window_title_label = new Label("Update Available");

		Button* m_exit_button = new Button(new Graphic(":/svgs/exit.svg", QSize(20, 20)), true);

		Button* m_remind_me_later_button{ new Button("Remind Me Later") };
		Button* m_update_button{ new Button("Update") };

		Label* m_message_label;

		QPainter painter;
	};
}

#endif // UPDATEDIALOG_H
