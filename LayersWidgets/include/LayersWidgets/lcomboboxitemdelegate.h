#ifndef LCOMBOBOXITEMDELEGATE_H
#define LCOMBOBOXITEMDELEGATE_H

#include <QPainterPath>
#include <QStyledItemDelegate>

#include <LayersCore/layers_global.h>
#include "layerswidgets_exports.h"

#include <LayersCore/lthemeable.h>

LAYERS_NAMESPACE_BEGIN
/*!
	An LComboBoxItemDelegate is a QStyledItemDelegate and a LThemeable that
	serves as a basic item delegate for LComboBox.
*/
class LAYERS_WIDGETS_EXPORT LComboBoxItemDelegate : public QStyledItemDelegate, public LThemeable
{
	Q_OBJECT

public:
	/*!
		Constructs a combo box item delegate.
	*/
	LComboBoxItemDelegate(QObject* parent = nullptr);

	// TODO: Create a destructor; free the attributes

	/*!
		Returns a QPainterPath that represents the item's background.
	*/
	QPainterPath background_path(
		const QStyleOptionViewItem& option,
		const QModelIndex& index) const;

	/*!
		Renders the delegate using the given *painter* and style *option* for
		the item specified by *index*.
	*/
	virtual void paint(QPainter* painter,
		const QStyleOptionViewItem& option,
		const QModelIndex& index) const override;

	/*!
		Informs the item delegate that the combo box popup widget is displayed
		above or below the combo box.
	*/
	void set_is_above_control(bool condition = true);

protected:
	LAttribute* m_corner_radius{
		new LAttribute("corner_radius", LVariant(10.0)) };

	LAttribute* m_fill{
		new LAttribute("fill", LVariantMap({
			{ "Selected", QColor(Qt::green) },
			{ "Unselected", QColor(Qt::white) }
		})) };

	LAttribute* m_text_color{
		new LAttribute("text_color", QColor(Qt::black)) };

private:
	void init_attributes();

	bool m_is_above_control{ false };
};
LAYERS_NAMESPACE_END

#endif // LCOMBOBOXITEMDELEGATE_H  
