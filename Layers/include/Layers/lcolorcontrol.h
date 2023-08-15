#ifndef LCOLORCONTROL_H
#define LCOLORCONTROL_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
/*!
	![LColorControl Example](color_control.png)
	
	An LColorControl is an LWidget that displays a color to the user and
	generates an LColorDialog when clicked, giving the user an interface for
	changing the color's value.
*/
class LAYERS_EXPORT LColorControl : public LWidget
{
	Q_OBJECT

signals:
	/*!
		This signal is emitted if the associated color attribute changes.
	*/
	void color_changed();

public:
	/*!
		Constructs a color control.
	*/
	LColorControl(QWidget* parent = nullptr);

	~LColorControl();

	/*!
		Generates an LColorDialog to give the user an interface for changing
		the color value.
	*/
	void click();

	/*!
		Disables or enables the click functionality of the control depending
		on *cond*.
	*/
	void disable_clicking(bool cond = true);

protected:
	virtual bool eventFilter(QObject* object, QEvent* event) override;

private:
	void init_attributes();

	bool clicking_disabled{ false };
	bool open_on_release{ false };

	QMetaObject::Connection attribute_connection;

	QStringList m_attribute_states;
};
LAYERS_NAMESPACE_END

#endif // LCOLORCONTROL_H
