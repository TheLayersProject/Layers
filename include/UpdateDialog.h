#ifndef UPDATEDIALOG_H
#define UPDATEDIALOG_H

#include <QDialog>

#include "Button.h"

namespace Layers
{
	class UpdateDialog : public QDialog, public Themeable
	{
		Q_OBJECT

	public:
		UpdateDialog(const QString& current_version_tag, const QString& latest_version_tag, QWidget* parent = nullptr);

		void issue_update();

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

		Button* m_remind_me_later_button{ new Button("Remind Me Later") };
		Button* m_update_button{ new Button("Update") };

		Label* m_message_label;

		QPainter painter;
	};
}

#endif // UPDATEDIALOG_H
