#ifndef LUPDATEDIALOG_H
#define LUPDATEDIALOG_H

#include "layerswidgetsexports.h"

#include "ldialog.h"

namespace Layers
{
	class LUpdateDialog : public LDialog
	{
		Q_OBJECT

	public:
		LUpdateDialog(const QString& current_version_tag, const QString& latest_version_tag, QWidget* parent = nullptr);

		virtual LThemeable* clone() override;

	private:
		void init_layout();

		LButton* m_remind_me_later_button{ new LButton("Remind Me Later") };
		LButton* m_update_button{ new LButton("Update") };

		LLabel* m_message_label;
	};
}

#endif // LUPDATEDIALOG_H
