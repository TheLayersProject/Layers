#ifndef LTAB_H
#define LTAB_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lbutton.h"
#include "llabel.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LTab is a LWidget that labels another widget and can be clicked by the
	user to switch between different widgets.
*/
class LAYERS_EXPORT LTab : public LWidget
{
	Q_OBJECT

signals:
	/*!
		This signal is emitted when the tab is clicked.
	*/
	void clicked();

	/*!
		This signal is emitted when the tab is closed.
	*/
	void closed();

public:
	/*!
		Constructs a tab labeled with an *icon* and *text*.
	*/
	LTab(const LGraphic& icon, const QString& text, QWidget* parent = nullptr);

	/*!
		Constructs a tab labeled with *text*.
	*/
	LTab(const QString& text, QWidget* parent = nullptr);

	/*!
		Returns a pointer to the tab's close button.
	*/
	LButton* close_button() const;

	/*!
		Returns a pointer to the tab's text label.
	*/
	LLabel* text_label() const;

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

private:
	void init();
	void init_attributes();
	void init_layout();

	QHBoxLayout* main_layout = new QHBoxLayout;

	LButton* m_close_button{
		new LButton(LGraphic(":/images/tab_exit.svg", QSize(16, 17))) };

	LLabel* m_icon_label{ nullptr };

	LLabel* m_text_label{ nullptr };
};
LAYERS_NAMESPACE_END

#endif // LTAB_H
