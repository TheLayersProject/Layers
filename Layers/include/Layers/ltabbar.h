#ifndef LTABBAR_H
#define LTABBAR_H

#include <QHBoxLayout>

#include "layers_global.h"
#include "layers_exports.h"

#include "ltab.h"
#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LTabBar is a LWidget that lets the user switch between different widgets
	that are represented by a set of tabs.
*/
class LAYERS_EXPORT LTabBar : public LWidget
{
	Q_OBJECT

signals:
	/*!
		This signal is emitted when the current index changes.
	*/
	void index_changed(int old_index, int new_index);

	/*!
		This signal is emitted when a tab is closed.
	*/
	void tab_closed(int index);

public:
	/*!
		Constructs a tab bar.
	*/
	LTabBar(QWidget* parent = nullptr);

	/*!
		Creates a tab labeled with an *icon* and *text*.
	*/
	void add_tab(const LGraphic& icon, const QString& text);

	/*!
		Creates a tab labeled with *text*.
	*/
	void add_tab(const QString& text);

	/*!
		Returns the current index of the tab bar.
	*/
	int current_index() const;

	/*!
		Sets the current index of the tab bar.
	*/
	void set_current_index(int index);

	/*!
		Returns a list of pointers to the tabs of the tab bar.
	*/
	QList<LTab*> tabs() const;

protected:
	void init_layout();

	void _add_tab(LTab* tab);

	int m_current_index{ -1 };

	QList<LTab*> m_tabs;

	QHBoxLayout* m_tab_layout{ new QHBoxLayout };
};
LAYERS_NAMESPACE_END

#endif // LTABBAR_H
