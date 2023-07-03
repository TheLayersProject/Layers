#ifndef LSCROLLBAR_H
#define LSCROLLBAR_H

#include <QScrollBar>

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lthemeable.h>

LAYERS_NAMESPACE_BEGIN
/*!
	An LScrollBar is a QScrollBar and a LThemeable that provides a control that
	allows the user to scroll to different parts of a widget in cases where the
	widget is larger than the available area it is displayed.
*/
class LAYERS_EXPORT LScrollBar : public QScrollBar, public LThemeable
{
	Q_OBJECT

public:
	/*!
		Constructs a scroll bar.
	*/
	LScrollBar(QWidget* parent = nullptr);

	/*!
		Returns a pointer to the background color attribute of the scroll bar.
	*/
	LAttribute* background_color() const;

	/*!
		Returns a pointer to the bottom-left corner radii attribute of the
		scroll bar.
	*/
	LAttribute* corner_radii_bottom_left() const;

	/*!
		Returns a pointer to the bottom-right corner radii attribute of the
		scroll bar.
	*/
	LAttribute* corner_radii_bottom_right() const;

	/*!
		Returns a pointer to the top-left corner radii attribute of the scroll
		bar.
	*/
	LAttribute* corner_radii_top_left() const;

	/*!
		Returns a pointer to the top-right corner radii attribute of the scroll
		bar.
	*/
	LAttribute* corner_radii_top_right() const;

	/*!
		Returns a pointer to the handle color attribute of the scroll bar.
	*/
	LAttribute* handle_color() const;

	/*!
		Returns a pointer to the bottom-left corner radii attribute of the
		scroll bar's handle.
	*/
	LAttribute* handle_corner_radii_bottom_left() const;

	/*!
		Returns a pointer to the bottom-right corner radii attribute of the
		scroll bar's handle.
	*/
	LAttribute* handle_corner_radii_bottom_right() const;

	/*!
		Returns a pointer to the top-left corner radii attribute of the scroll
		bar's handle.
	*/
	LAttribute* handle_corner_radii_top_left() const;

	/*!
		Returns a pointer to the top-right corner radii attribute of the scroll
		bar's handle.
	*/
	LAttribute* handle_corner_radii_top_right() const;

	virtual void update() override;

private:
	LAttribute* m_background_color{
		new LAttribute("background_color", QColor(Qt::gray), this) };

	LAttribute* m_corner_radii_bottom_left{
		new LAttribute("corner_radii.bottom_left", 0.0, this) };

	LAttribute* m_corner_radii_bottom_right{
		new LAttribute("corner_radii.bottom_right", 0.0, this) };

	LAttribute* m_corner_radii_top_left{
		new LAttribute("corner_radii.top_left", 0.0, this) };

	LAttribute* m_corner_radii_top_right{
		new LAttribute("corner_radii.top_right", 0.0, this) };

	LAttribute* m_handle_color{
		new LAttribute("handle_color", QColor(Qt::white), this) };

	LAttribute* m_handle_corner_radii_bottom_left{
		new LAttribute("handle_corner_radii.bottom_left", 5.0, this) };

	LAttribute* m_handle_corner_radii_bottom_right{
		new LAttribute("handle_corner_radii.bottom_right", 5.0, this) };

	LAttribute* m_handle_corner_radii_top_left{
		new LAttribute("handle_corner_radii.top_left", 5.0, this) };

	LAttribute* m_handle_corner_radii_top_right{
		new LAttribute("handle_corner_radii.top_right", 5.0, this) };
};
LAYERS_NAMESPACE_END

#endif // LSCROLLBAR_H
