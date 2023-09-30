#ifndef LDIALOG_H
#define LDIALOG_H

#include <QDialog>

#include "layers_global.h"
#include "layers_exports.h"

#include "lbutton.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LDialog : public QDialog, public LThemeableBox
{
	Q_OBJECT

public:
	LDialog(const QString& title = "Dialog", QWidget* parent = nullptr);

	void set_icon(const LGraphic& icon);

	void setLayout(QLayout* layout);

	virtual void update() override;

protected:
	virtual bool nativeEvent(
		const QByteArray& eventType, void* message, qintptr* result) override;

	virtual void paintEvent(QPaintEvent* event) override;

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

/*!
	Moves *upper_widget* to the center of *lower_widget*.
*/
LAYERS_EXPORT void center(QWidget* upper_widget, QWidget* lower_widget);

LAYERS_NAMESPACE_END

#endif // LDIALOG_H
