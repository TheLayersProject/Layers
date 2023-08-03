#ifndef LTHEMEVIEW_H
#define LTHEMEVIEW_H

#include <QTreeView>

#include "layers_global.h"
#include "layers_exports.h"

#include "lscrollbar.h"
#include "lthemeable.h"
#include "lthememodel.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LThemeView is a QAbstractItemView and a LThemeable that is
	customizable.
*/
class LAYERS_EXPORT LThemeView :
	public QTreeView, public LThemeable
{
	Q_OBJECT

signals:
	void selection_changed(LThemeItem* theme_item);

public:
	/*!
		Constructs a themeable tree view.
	*/
	LThemeView(QWidget* parent = nullptr);

	~LThemeView();

	/*!
		Returns a list of child themeables.

		This function overrides LThemeable::child_themeables() to include the
		scroll bars.
	*/
	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
	) override;

	virtual void update() override;

protected:
	virtual void selectionChanged(
		const QItemSelection& selected,
		const QItemSelection& deselected) override;

private:
	LAttribute* m_fill{
		new LAttribute("Fill", QColor(Qt::white), this) };

	LAttribute* m_text_color{
		new LAttribute("Text Color", QColor(Qt::black), this) };

	LScrollBar* m_horizontal_scrollbar{ new LScrollBar };
	LScrollBar* m_vertical_scrollbar{ new LScrollBar };

	LThemeModel* m_model{ new LThemeModel };

	QMetaObject::Connection m_model_update_connection;
};
LAYERS_NAMESPACE_END

#endif // LTHEMEVIEW_H  
