#ifndef LSCROLLBAR_H
#define LSCROLLBAR_H

#include <QScrollBar>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LScrollBar : public QScrollBar, public LThemeable
{
	Q_OBJECT

public:
	LScrollBar(QWidget* parent = nullptr);

	LAttribute* background_color() const;

	LAttribute* corner_radii_bottom_left() const;

	LAttribute* corner_radii_bottom_right() const;

	LAttribute* corner_radii_top_left() const;

	LAttribute* corner_radii_top_right() const;

	LAttribute* handle_color() const;

	LAttribute* handle_corner_radii_bottom_left() const;

	LAttribute* handle_corner_radii_bottom_right() const;

	LAttribute* handle_corner_radii_top_left() const;

	LAttribute* handle_corner_radii_top_right() const;

	virtual void update() override;

private:
	LAttribute* m_background_color
		{ new LAttribute("Background Color", QColor(Qt::gray), this) };

	LAttribute* m_corner_radii_bottom_left
		{ new LAttribute("Corner Radii.Bottom Left", 0.0, this) };

	LAttribute* m_corner_radii_bottom_right
		{ new LAttribute("Corner Radii.Bottom Right", 0.0, this) };

	LAttribute* m_corner_radii_top_left
		{ new LAttribute("Corner Radii.Top Left", 0.0, this) };

	LAttribute* m_corner_radii_top_right
		{ new LAttribute("Corner Radii.Top Right", 0.0, this) };

	LAttribute* m_handle_color
		{ new LAttribute("Handle Color", QColor(Qt::white), this) };

	LAttribute* m_handle_corner_radii_bottom_left
		{ new LAttribute("Handle Corner Radii.Bottom Left", 5.0, this) };

	LAttribute* m_handle_corner_radii_bottom_right
		{ new LAttribute("Handle Corner Radii.Bottom Right", 5.0, this) };

	LAttribute* m_handle_corner_radii_top_left
		{ new LAttribute("Handle Corner Radii.Top Left", 5.0, this) };

	LAttribute* m_handle_corner_radii_top_right
		{ new LAttribute("Handle Corner Radii.Top Right", 5.0, this) };
};
LAYERS_NAMESPACE_END

#endif // LSCROLLBAR_H
