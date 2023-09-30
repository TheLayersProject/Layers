#ifndef LTAB_H
#define LTAB_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lbutton.h"
#include "llabel.h"
#include "lstatepool.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LTab : public LWidget
{
	Q_OBJECT

signals:
	void clicked();

	void closed();

public:
	LTab(const LGraphic& icon, const QString& text, QWidget* parent = nullptr);

	LTab(const QString& text, QWidget* parent = nullptr);

	LButton* close_button() const;

	LLabel* icon_label() const;

	LStatePool* status_states() const;

	LLabel* text_label() const;

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

private:
	void init();
	void init_attributes();
	void init_layout();

	QHBoxLayout* main_layout = new QHBoxLayout;

	LButton* m_close_button
		{ new LButton(LGraphic(":/images/tab_exit.svg", QSize(16, 17))) };

	LLabel* m_icon_label{ nullptr };

	LLabel* m_text_label{ nullptr };

	LStatePool* m_status_states
		{ new LStatePool("Status", { "Active", "Inactive" })};
};
LAYERS_NAMESPACE_END

#endif // LTAB_H
