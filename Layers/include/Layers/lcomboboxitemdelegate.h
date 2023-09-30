#ifndef LCOMBOBOXITEMDELEGATE_H
#define LCOMBOBOXITEMDELEGATE_H

#include <QPainterPath>
#include <QStyledItemDelegate>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"
#include "lstatepool.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LComboBoxItemDelegate :
	public QStyledItemDelegate, public LThemeable
{
	Q_OBJECT

public:
	LComboBoxItemDelegate(QObject* parent = nullptr);

	QPainterPath background_path(
		const QStyleOptionViewItem& option,
		const QModelIndex& index) const;

	LAttribute* corner_radius() const;

	LAttribute* fill() const;

	virtual void paint(QPainter* painter,
		const QStyleOptionViewItem& option,
		const QModelIndex& index) const override;

	void set_is_above_control(bool condition = true);

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
