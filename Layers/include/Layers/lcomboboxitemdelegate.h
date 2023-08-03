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
	An LComboBoxItemDelegate is a QStyledItemDelegate and a LThemeable that
	serves as a basic item delegate for LComboBox.
*/
class LAYERS_EXPORT LComboBoxItemDelegate : public QStyledItemDelegate, public LThemeable
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
		new LAttribute("Corner Radius", QVariant(10.0), this) };

	LAttribute* m_fill{
		new LAttribute("Fill", QColor(Qt::gray), this) };

	LAttribute* m_text_color{
		new LAttribute("Text Color", QColor(Qt::black), this) };

private:
	void init_attributes();

	bool m_is_above_control{ false };

	LStatePool* m_select_states{
		new LStatePool("Status", { "Selected", "Unselected" }) };
};
LAYERS_NAMESPACE_END

#endif // LCOMBOBOXITEMDELEGATE_H  
