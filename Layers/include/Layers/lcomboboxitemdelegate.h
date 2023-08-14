#ifndef LCOMBOBOXITEMDELEGATE_H
#define LCOMBOBOXITEMDELEGATE_H

#include <QPainterPath>
#include <QStyledItemDelegate>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"
#include "lstatepool.h"

LAYERS_NAMESPACE_BEGIN
/*!
	![LComboBoxItemDelegate Example](combo_box_item_delegate.png)
	
	An LComboBoxItemDelegate is a QStyledItemDelegate and an LThemeable that
	serves as the default item delegate for LComboBox.
*/
class LAYERS_EXPORT LComboBoxItemDelegate :
	public QStyledItemDelegate, public LThemeable
{
	Q_OBJECT

public:
	/*!
		Constructs a combo box item delegate.
	*/
	LComboBoxItemDelegate(QObject* parent = nullptr);

	/*!
		Returns a QPainterPath that represents the *index* item's background.
	*/
	QPainterPath background_path(
		const QStyleOptionViewItem& option,
		const QModelIndex& index) const;

	/*!
		Returns a pointer to the delegate's corner radius attribute.
	*/
	LAttribute* corner_radius() const;

	/*!
		Returns a pointer to the delegate's fill attribute.
	*/
	LAttribute* fill() const;

	/*!
		Renders the delegate using the given *painter* and style *option* for
		the item specified by *index*.
	*/
	virtual void paint(QPainter* painter,
		const QStyleOptionViewItem& option,
		const QModelIndex& index) const override;

	/*!
		Informs the item delegate whether the items are displayed above or
		below the combo box.
	*/
	void set_is_above_control(bool condition = true);

	/*!
		Returns a pointer to the delegate's text color attribute.
	*/
	LAttribute* text_color() const;

protected:
	LAttribute* m_corner_radius
		{ new LAttribute("Corner Radius", QVariant(4.0), this) };

	LAttribute* m_fill
		{ new LAttribute("Fill", QColor("#27272e"), this)};

	LAttribute* m_text_color
		{ new LAttribute("Text Color", QColor("#e1e1e1"), this) };

private:
	void init_attributes();

	bool m_is_above_control{ false };

	LStatePool* m_select_states{
		new LStatePool("Status", { "Selected", "Unselected" }) };
};
LAYERS_NAMESPACE_END

#endif // LCOMBOBOXITEMDELEGATE_H  
