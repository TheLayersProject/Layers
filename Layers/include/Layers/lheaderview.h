#ifndef LHEADERVIEW_H
#define LHEADERVIEW_H

#include <QHeaderView>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LHeaderView : public QHeaderView, public LThemeable
{
	Q_OBJECT

public:
	LHeaderView(Qt::Orientation orientation, QWidget* parent = nullptr);

	virtual void update() override;

private:
	LAttribute* m_border_fill{
		new LAttribute("Border.Fill", QColor(Qt::gray), this) };

	LAttribute* m_border_thickness{
		new LAttribute("Border.Thickness", 0.0, this) };

	LAttribute* m_corner_radii_bottom_left{
		new LAttribute("Corner Radii.Bottom Left", 0.0, this) };

	LAttribute* m_corner_radii_bottom_right{
		new LAttribute("Corner Radii.Bottom Right", 0.0, this) };

	LAttribute* m_corner_radii_top_left{
		new LAttribute("Corner Radii.Top Left", 2.0, this) };

	LAttribute* m_corner_radii_top_right{
		new LAttribute("Corner Radii.Top Right", 2.0, this) };

	LAttribute* m_fill{
		new LAttribute("Fill", QColor("#808080"), this) };

	LAttribute* m_text_color{
		new LAttribute("Text Color", QColor(Qt::black), this) };
};
LAYERS_NAMESPACE_END

#endif // LHEADERVIEW_H  
