#ifndef LUPDATEDIALOG_H
#define LUPDATEDIALOG_H

#include "layers_global.h"
#include "layers_exports.h"

#include "ldialog.h"

LAYERS_NAMESPACE_BEGIN
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
LAYERS_NAMESPACE_END

#endif // LUPDATEDIALOG_H
