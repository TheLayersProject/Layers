#ifndef LATTRIBUTEEDITOR_H
#define LATTRIBUTEEDITOR_H

#include "layers_global.h"
#include "layers_exports.h"

#include "ltoggleswitch.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LAttributeEditor : public LWidget
{
	Q_OBJECT

public:
	LAttributeEditor(LAttribute* attr = nullptr, QWidget* parent = nullptr);
	//~LAttributeEditor();

protected:
	void init_attributes();

	LAttribute* m_attr;
};
LAYERS_NAMESPACE_END

#endif // LATTRIBUTEEDITOR_H
