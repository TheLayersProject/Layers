#ifndef LTABBAR_H
#define LTABBAR_H

#include <QHBoxLayout>

#include "layers_global.h"
#include "layers_exports.h"

#include "ltab.h"
#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LTabBar : public LWidget
{
	Q_OBJECT

signals:
	void index_changed(int old_index, int new_index);

	void tab_closed(int index);

public:
	LTabBar(QWidget* parent = nullptr);

	void add_tab(const LGraphic& icon, const QString& text);

	void add_tab(const QString& text);

	int current_index() const;

	void set_current_index(int index);

	QList<LTab*> tabs() const;

private:
	void _add_tab(LTab* tab);

	void init_layout();

	int m_current_index{ -1 };

	QList<LTab*> m_tabs;

	QHBoxLayout* m_tab_layout{ new QHBoxLayout };
};
LAYERS_NAMESPACE_END

#endif // LTABBAR_H
