#ifndef LATTRIBUTEDATA_H
#define LATTRIBUTEDATA_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lattributegroup.h"

LAYERS_NAMESPACE_BEGIN

class LAttribute;

struct LAYERS_EXPORT LAttributeData
{
	LAttributeMap ungrouped_attrs;
	LAttributeGroupMap attr_groups;

	void clear();

	bool is_empty() const;
};

using LAttributeDataHash = QHash<QString, LAttributeData>;

LAYERS_NAMESPACE_END

#endif // LATTRIBUTEDATA_H
