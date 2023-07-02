#ifndef LHEADERVIEW_H
#define LHEADERVIEW_H

#include <QHeaderView>

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lthemeable.h>

LAYERS_NAMESPACE_BEGIN
/*!
	An LHeaderView is a QHeaderView and a LThemeable that is customizable.
*/
class LAYERS_EXPORT LHeaderView : public QHeaderView, public LThemeable
{
	Q_OBJECT

public:
	/*!
		Constructs a header view with a specified *orientation*.
	*/
	LHeaderView(Qt::Orientation orientation, QWidget* parent = nullptr);

	// TODO: Create a destructor; free the attributes

	virtual void update() override;

private:
	LAttribute* m_border_fill{
		new LAttribute("border.fill", QColor(Qt::gray), this) };

	LAttribute* m_border_thickness{
		new LAttribute("border.thickness", 0.0, this) };

	LAttribute* m_corner_radii_bottom_left{
		new LAttribute("corner_radii.bottom_left", 0.0, this) };

	LAttribute* m_corner_radii_bottom_right{
		new LAttribute("corner_radii.bottom_right", 0.0, this) };

	LAttribute* m_corner_radii_top_left{
		new LAttribute("corner_radii.top_left", 2.0, this) };

	LAttribute* m_corner_radii_top_right{
		new LAttribute("corner_radii.top_right", 2.0, this) };

	LAttribute* m_fill{
		new LAttribute("fill", QColor("#808080"), this) };

	LAttribute* m_text_color{
		new LAttribute("text_color", QColor(Qt::black), this) };
};
LAYERS_NAMESPACE_END

#endif // LHEADERVIEW_H  
