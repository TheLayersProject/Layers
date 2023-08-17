#ifndef LGRADIENTEDITOR
#define LGRADIENTEDITOR

#include "layers_global.h"
#include "layers_exports.h"

#include "lbutton.h"
#include "lcolorcontrol.h"
#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LGradientEditorItem;

/*!
	![LGradientEditor Example](gradient_editor.png)

	An LGradientEditor is an LWidget that provides the user with a way to edit
	colors of a gradient.

	The editor is filled with the gradient being edited so that the user can
	see the result as they make changes.

	LColorControl widgets are spread out along the top of the editor,
	representing the individual colors that make up the gradient. The
	X-position of each control is proportional to the color's stop value. To
	change a color, the user can click on the corresponding control to launch
	an LColorDialog for editing the color.

	The X-position of each control, except the two on either end of the editor,
	can be moved by click-dragging. This is how a color's stop value can be
	changed. If there is already a control at the new X-position when the
	drag-control is released, then the control is deleted, and its color is
	removed from the gradient

	Between each color control, there is an LButton with a *plus* icon which
	adds a color to the gradient. If two controls are visibly too close to each
	other, the button in-between them is hidden.
*/
class LAYERS_EXPORT LGradientEditor : public LWidget
{
	Q_OBJECT

public:
	/*!
		Constructs a gradient editor initialized with *gradient_stops*.
	*/
	LGradientEditor(QGradientStops gradient_stops, QWidget* parent = nullptr);

	~LGradientEditor();

	/*!
		Returns the stops of the gradient being edited.
	*/
	QGradientStops gradient_stops() const;

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

private:
	LGradientEditorItem* create_item(const QGradientStop& stop);

	void init_attributes(const QGradientStops& gradient_stops);
	void init_items(const QGradientStops& gradient_stops);
	void init_add_stop_buttons();

	void update_gradient();
	void update_indexes();
	void update_positions();

	QList<LGradientEditorItem*> m_items;
	QList<LButton*> m_add_stop_buttons;

	LGradientEditorItem* m_drag_item{ nullptr };
	LGradientEditorItem* m_replace_item{ nullptr };

	int m_drag_ctrl_initial_x{ 0 };
	QPoint m_click_pos;
};
LAYERS_NAMESPACE_END

#endif // LGRADIENTEDITOR
