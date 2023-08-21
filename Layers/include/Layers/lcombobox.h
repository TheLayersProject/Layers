#ifndef LCOMBOBOX_H
#define LCOMBOBOX_H

#include <QComboBox>
#include <QPainterPath>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
/*!
	![LComboBox Example](combo_box.png)
	
	An LComboBox is a QComboBox and an LThemeable that provides the user with a
	way to select an option from a list.

	LComboBoxItemDelegate was created to serve as the default item delegate for
	%LComboBox.
*/
class LAYERS_EXPORT LComboBox : public QComboBox, public LThemeable
{
	Q_OBJECT

public:
	/*!
		Constructs a combo box.
	*/
	LComboBox(QWidget* parent = nullptr);

	/*!
		Returns a pointer to the combo box's border fill attribute.
	*/
	LAttribute* border_fill() const;

	/*!
		Returns a pointer to the combo box's border thickness attribute.
	*/
	LAttribute* border_thickness() const;

	/*!
		Returns a list of child themeables.

		This function overrides LThemeable::child_themeables() to include the
		item delegate of the combo box and any children it might have.
	*/
	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
	) override;

	/*!
		Returns a pointer to the combo box's corner radius attribute.
	*/
	LAttribute* corner_radius() const;

	/*!
		Returns a pointer to the combo box's fill attribute.
	*/
	LAttribute* fill() const;

	/*!
		Sets both the minimum and maximum heights of the widget to *h* without
		changing the widths.
	*/
	void setFixedHeight(int h);

	/*!
		Sets both the minimum and maximum sizes of the widget to *s*, thereby
		preventing it from ever growing or shrinking.
	*/
	void setFixedSize(const QSize& s);

	/*!
		Sets the width of the widget to *w* and the height to *h*.
	*/
	void setFixedSize(int w, int h);

	/*!
		Sets both the minimum and maximum width of the widget to *w* without
		changing the heights.
	*/
	void setFixedWidth(int w);

	/*!
		Displays the list of items in the combobox.

		This function overrides QComboBox::showPopup() to inform the item
		delegate about whether the popup is being displayed above or below the
		combo box, if the item delegate is a LComboBoxItemDelegate.
	*/
	virtual void showPopup() override;

	/*!
		Returns a pointer to the combo box's text color attribute.
	*/
	LAttribute* text_color() const;

	/*!
		Updates the combo box.

		This function overrides LThemeable::update() to update the combo box's
		style_sheet.
	*/
	virtual void update() override;

protected:
	/*!
		Returns a QPainterPath that represents the background.
	*/
	QPainterPath background_path() const;

	virtual bool eventFilter(QObject* object, QEvent* event) override;

	bool is_view_positioned_above() const;

	virtual void paintEvent(QPaintEvent* event) override;

	LAttribute* m_border_fill
		{ new LAttribute("Border.Fill", QColor(Qt::gray), this) };

	LAttribute* m_border_thickness
		{ new LAttribute("Border.Thickness", 0.0, this) };

	LAttribute* m_corner_radius
		{ new LAttribute("Corner Radius", 4.0, this) };

	LAttribute* m_fill
		{ new LAttribute("Fill", QColor("#31323b"), this)};

	LAttribute* m_text_color
		{ new LAttribute("Text Color", QColor("#e1e1e1"), this) };
};
LAYERS_NAMESPACE_END

#endif // LCOMBOBOX_H
