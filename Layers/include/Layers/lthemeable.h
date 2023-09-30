#ifndef LTHEMEABLE_H
#define LTHEMEABLE_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lstatepool.h"
#include "lthemeitem.h"

LAYERS_NAMESPACE_BEGIN

class LGraphic;

class LAYERS_EXPORT LThemeable
{
public:
	void add_share_themeable(LThemeable* themeable);

	void add_state_pool(LStatePool* state_pool, bool include_children = true);

	virtual void apply_theme_item(LThemeItem* theme_item);

	QList<LAttribute*> child_attributes(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly);

	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly);

	LThemeItem* current_theme_item() const;

	QString path();

	QList<LStatePool*> state_pools() const;

	QStringList state_combo() const;

	virtual void update();

private:
	LThemeable* _parent_themeable();

	QString _name();

	LThemeItem* m_current_theme_item{ nullptr };

	QList<LThemeable*> m_share_themeables;

	QList<LStatePool*> m_state_pools;
};
LAYERS_NAMESPACE_END

#endif // LTHEMEABLE_H
