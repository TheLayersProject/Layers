#ifndef LCOMBOBOX_H
#define LCOMBOBOX_H

#include <QComboBox>
#include <QPainterPath>

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lthemeable.h>

LAYERS_NAMESPACE_BEGIN
/*!
	An LComboBox is a QComboBox and a LThemeable that provides the user with a
	way to select an option from a list of options.
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
		Returns a list of child themeables.

		This function overrides LThemeable::child_themeables() to include the
		item delegate of the combo box and any children it might have.
	*/
	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
	) override;

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
		combo box, if the item delegate is a LComboBoxItemDelegate type.
	*/
	virtual void showPopup() override;

	virtual void update() override;

protected:
	/*!
		Returns a QPainterPath that represents the combo box's background.
	*/
	QPainterPath background_path() const;

	virtual bool eventFilter(QObject* object, QEvent* event) override;

	virtual void paintEvent(QPaintEvent* event) override;

	LAttribute* m_border_fill{
		new LAttribute("Border.Fill", QColor(Qt::gray), this) };

	LAttribute* m_border_thickness{
		new LAttribute("Border.Thickness", 0.0, this) };

	LAttribute* m_corner_radius{
		new LAttribute("Corner Radius", 10.0, this) };

	LAttribute* m_fill{
		new LAttribute("Fill", QColor(Qt::white), this) };

	LAttribute* m_text_color{
		new LAttribute("Text Color", QColor(Qt::black), this) };
};
LAYERS_NAMESPACE_END

#endif // LCOMBOBOX_H
