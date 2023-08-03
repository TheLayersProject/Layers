#include <Layers/lthemeable.h>

#include <QWidget>

#include <Layers/lgraphic.h>

using Layers::LAttribute;
using Layers::LGraphic;
using Layers::LStatePool;
using Layers::LThemeItem;
using Layers::LThemeable;

LThemeable::~LThemeable()
{
	if (m_name)
		delete m_name;

	if (m_icon)
		delete m_icon;
}

void LThemeable::add_state_pool(LStatePool* state_pool, bool include_children)
{
	m_state_pools.append(state_pool);

	state_pool->connect(state_pool, &LStatePool::changed, [this]
		{ update(); });

	if (include_children)
		for (LThemeable* child_themeable : child_themeables())
			child_themeable->add_state_pool(state_pool, include_children);
}

void LThemeable::apply_theme(LThemeItem* theme_item)
{
	if (!m_name)
		qDebug() << "Unable to apply theme. "
			"You must apply a name to the widget first.";
	else if (*m_name == theme_item->name())
	{
		m_current_theme_item = theme_item;

		if (!theme_item->attributes().isEmpty())
			for (LAttribute* attr : child_attributes())
				if (theme_item->attributes().contains(attr->name()))
					attr->set_theme_attribute(
						theme_item->attributes()[attr->name()]);

		if (!theme_item->child_items().isEmpty())
			for (LThemeable* child_t : child_themeables())
				if (child_t->m_name)
					if (theme_item->child_items().contains(*child_t->name()))
						child_t->apply_theme(theme_item->child_items()[*child_t->name()]);

		for (LThemeable* themeable : m_sharing_with_themeables)
			themeable->apply_theme(m_current_theme_item);
	}
}

QList<LAttribute*> LThemeable::child_attributes(Qt::FindChildOptions options)
{
	QList<LAttribute*> child_attributes;

	if (QObject* object = dynamic_cast<QObject*>(this))
	{
		child_attributes.append(
			object->findChildren<LAttribute*>(Qt::FindDirectChildrenOnly));

		if (options == Qt::FindChildrenRecursively)
		{
			for (LThemeable* child_themeable : child_themeables())
				child_attributes.append(child_themeable->child_attributes(options));
		}
	}

	return child_attributes;
}

QList<LThemeable*> LThemeable::child_themeables(Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables;

	if (QObject* object = dynamic_cast<QObject*>(this))
	{
		QList<QObject*> child_objects =
			object->findChildren<QObject*>(Qt::FindDirectChildrenOnly);

		for (QObject* child_object : child_objects)
		{
			if (LThemeable* child_themeable = dynamic_cast<LThemeable*>(child_object))
			{
				child_themeables.append(child_themeable);

				if (options == Qt::FindChildrenRecursively)
					child_themeables.append(child_themeable->child_themeables(options));
			}
		}
	}

	return child_themeables;
}

void LThemeable::clear_theme()
{
	if (m_current_theme_item)
	{
		m_current_theme_item = nullptr;

		for (LAttribute* attr : child_attributes())
			attr->clear_theme_attribute();

		for (LThemeable* child_t : child_themeables())
			child_t->clear_theme();
	}
}

LThemeItem* LThemeable::current_theme_item() const
{
	return m_current_theme_item;
}

LGraphic* LThemeable::icon() const
{
	return m_icon;
}

QString* LThemeable::name() const
{
	return m_name;
}

QString LThemeable::path()
{
	QStringList path_names;

	if (name())
		path_names.append(*name());

	LThemeable* t = parent_themeable();

	while (t)
	{
		if (t->name())
		{
			path_names.insert(0, *t->name());
			t = t->parent_themeable();
		}
		else
			t = nullptr;
	}

	return path_names.join("/");
}

LThemeable* LThemeable::parent_themeable()
{
	if (QObject* object = dynamic_cast<QObject*>(this))
		if (QObject* parent = object->parent())
			if (LThemeable* parent_themeable = dynamic_cast<LThemeable*>(parent))
				return parent_themeable;

	return nullptr;
}

void LThemeable::set_icon(const LGraphic& icon)
{
	if (m_icon)
		delete m_icon;

	m_icon = new LGraphic(icon);
}

void LThemeable::set_name(const QString& name)
{
	if (m_name)
		delete m_name;

	m_name = new QString(name);
}

void LThemeable::share_theme_item_with(LThemeable* themeable)
{
	if (themeable)
	{
		if (m_current_theme_item)
			themeable->apply_theme(m_current_theme_item);

		m_sharing_with_themeables.append(themeable);
	}
}

QList<LStatePool*> LThemeable::state_pools() const
{
	return m_state_pools;
}

QStringList LThemeable::states() const
{
	QStringList states;

	for (LStatePool* state_pool : m_state_pools)
		states.append(state_pool->state());

	return states;
}

void LThemeable::update()
{
	if (QWidget* widget = dynamic_cast<QWidget*>(this))
		widget->update();
}
