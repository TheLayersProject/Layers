#include <Layers/lattributedata.h>

using Layers::LAttributeData;

void LAttributeData::clear()
{
	for (LAttribute* attr : ungrouped_attrs)
		delete attr;

	for (LAttributeGroup* attr_group : attr_groups)
		delete attr_group;

	ungrouped_attrs.clear();
	attr_groups.clear();
}

bool LAttributeData::is_empty() const
{
	return attr_groups.isEmpty() && ungrouped_attrs.isEmpty();
}
