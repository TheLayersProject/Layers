#ifndef UPDATEDIALOG_H
#define UPDATEDIALOG_H

#include "Dialog.h"

namespace Layers
{
	class UpdateDialog : public Dialog
	{
		Q_OBJECT

	public:
		UpdateDialog(const QString& current_version_tag, const QString& latest_version_tag, QWidget* parent = nullptr);

		virtual Themeable* clone() override;

	private:
		void setup_layout();

		Button* m_remind_me_later_button{ new Button("Remind Me Later") };
		Button* m_update_button{ new Button("Update") };

		Label* m_message_label;
	};
}

#endif // UPDATEDIALOG_H