#ifndef LCOLORCONTROL_H
#define LCOLORCONTROL_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LColorControl : public LWidget
{
	Q_OBJECT

signals:
	void color_changed();

public:
	LColorControl(QWidget* parent = nullptr);

	~LColorControl();

	void click();

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
