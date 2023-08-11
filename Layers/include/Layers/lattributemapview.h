#ifndef LATTRIBUTEMAPVIEW_H
#define LATTRIBUTEMAPVIEW_H

#include <QTreeView>

#include "layers_global.h"
#include "layers_exports.h"

#include "lscrollbar.h"
#include "lthemeable.h"
#include "lattributemapmodel.h"

LAYERS_NAMESPACE_BEGIN
/*!
	An LAttributeMapView is a QTreeView and a LThemeable.
*/
class LAYERS_EXPORT LAttributeMapView :
	public QTreeView, public LThemeable
{
	Q_OBJECT

signals:
	void selection_changed(LAttribute* attr);

public:
	/*!
		Constructs an attribute map view.
	*/
	LAttributeMapView(QWidget* parent = nullptr);

	//~LAttributeMapView();

	/*!
		Returns a list of child themeables.

		This function overrides LThemeable::child_themeables() to include the
		scroll bars.
	*/
	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
	) override;

	void set_attributes(
		LAttributeMap attributes, const QStringList& filter_paths);

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

	LAttributeMapModel* m_model{ new LAttributeMapModel };

	//QMetaObject::Connection m_model_update_connection;
};
LAYERS_NAMESPACE_END

#endif // LATTRIBUTEMAPVIEW_H  
