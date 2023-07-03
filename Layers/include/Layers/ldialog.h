#ifndef LDIALOG_H
#define LDIALOG_H

#include <QDialog>

#include "layers_global.h"
#include "layers_exports.h"

#include "lbutton.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LDialog is a QDialog and a LThemeableBox that is used for short-term
	tasks or brief communications with the user.
*/
class LAYERS_EXPORT LDialog : public QDialog, public LThemeableBox
{
	Q_OBJECT

public:
	/*!
		Constructs a dialog labeled with *title*.
	*/
	LDialog(const QString& title = "Dialog", QWidget* parent = nullptr);

	/*!
		Sets the dialog's icon.
	*/
	void set_icon(const LGraphic& icon);

	/*!
		Sets the layout of the dialog.
	*/
	void setLayout(QLayout* layout);

	virtual void update() override;

protected:
	bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;

	void paintEvent(QPaintEvent* event) override;

	QVBoxLayout* m_main_layout{ new QVBoxLayout };

private:
	void init_attributes();
	void init_layout();
	void init_titlebar();

	bool m_hovering{ false };

	QHBoxLayout* m_titlebar_layout = new QHBoxLayout;

	LWidget* m_titlebar{ new LWidget };

	LLabel* m_icon_label{ nullptr };

	LLabel* m_title_label{ nullptr };

	LButton* m_exit_button = new LButton(
		LGraphic(":/images/exit.svg", QSize(20, 20)));
};
LAYERS_NAMESPACE_END

#endif // LDIALOG_H
