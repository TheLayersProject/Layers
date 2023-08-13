#ifndef LATTRIBUTEEDITOR_H
#define LATTRIBUTEEDITOR_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lbutton.h"
#include "lfillcontrol.h"
#include "llabel.h"
#include "llineeditor.h"
#include "lminislider.h"
#include "ltabbar.h"
#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LLinksView;
class LNewLinkWidget;

/*!
	![LAttributeEditor Example](attribute_editor.png)
	
	An LAttributeEditor is an LWidget that gives the user a set of controls and
	widgets for editing an LAttribute.

	The editor provides a label for the attribute's name and control widgets to
	modify the attribute's value (the widgets available depend on the value's
	type). There's also a collapse button (represented with the arrow icon)
	which expands the editor when clicked to reveal a tab bar and the active
	feature-widget. The feature-widgets include the *links widget* and
	the *overrides widget*, and they are only displayed when their associated
	tab is active.

	## Links Widget

	![Links Widget Example](links_widget.png)

	The links widget displays the linking information for the editor attribute
	and provides the user with mechanisms to create and break links.

	At the top, you will either see the 'New Link' button or the 'Break Link'
	button depending on if the attribute is linked or not. Underneath is
	the *links view*.

	### Links View

	![Links View Example](links_view.png)

	In the links view, **This** refers to the attribute associated with the
	editor. The editor in the example above is associated with the Main
	Window's *Fill* attribute.

	The path of the attribute that the editor attribute is *directly* linked to
	and the paths of the attributes that it is *indirectly* linked to are
	displayed above **This**. The attribute whose path is at the top is the one
	whose value represents all of the other attributes down the chain. In the
	example, the path above **This** indicates that it's directly linked to the
	App's *Primary* attribute.

	The paths of the dependent attributes are displayed under **This**. In the
	example, there are three dependent attributes.

	### Breaking Links

	Breaking a link is as simple as clicking the 'Break Link' button. The
	editor attribute will no longer be linked and utilize its own value beyond
	that point.

	After breaking the link in the example, the attribute editor would look
	like this:

	![Attribute Editor Unlinked Example](attribute_editor_unlinked.png)

	As you can see from the example above, **This** is no longer linked to
	the *App/Primary* attribute. Also, instead of the 'Break Link' button, the
	'New Link' button is visible now.

	### Creating Links

	Creating a new link starts with clicking the 'New Link' button. Doing so
	reveals the *new link widget* which contains two tree-views for navigating
	to&mdash;and selecting&mdash;the attribute you wish to link to:

	![New Link Widget Example](new_link_widget.png)

	The left-side tree-view lets the user select the widget that owns the
	attribute, and the right-side tree-view lets the user select the attribute.
	Once an attribute has been selected, click the 'Apply Link' button at the
	bottom to establish the link.

	## Overrides Widget

	![Overrides Widget Example](overrides_widget.png)

	The overrides widget contains other attribute editors associated with the
	override attributes of the original editor attribute.

	In the example above, the editor attribute is the *Fill* attribute owned by
	a radio button. By default, it has a single override attribute,
	labeled *Active*. When the radio button is in an active state, its *Fill*
	attribute uses the value stored in the *Active* override attribute instead
	of the regular value.

	The overrides widget and tab are only available if the editor attribute's
	parent is associated with at least one LStatePool.

	## Icons Widget

	![Icons Widget Example](icons_widget.png)

	The icons widget is a small widget positioned just left of the editor's
	collapse button. It displays icons that represent the active attribute
	features. It is useful for knowing what features an attribute uses
	without expanding the editor.

	The icons and their meanings are listed below:

	| Icon                                  | Meaning                                       |
	|---------------------------------------|-----------------------------------------------|
	| ![Links Icon](links_icon.svg)         | Attribute is linked to another attribute      |
	| ![Overrides Icon](overrides_icon.svg) | Attribute has at least one override attribute |

	If the icons widget is not visible, then that means the editor attribute
	does not currently use these features.
*/
class LAYERS_EXPORT LAttributeEditor : public LWidget
{
	Q_OBJECT

public:
	/*!
		Constructs an attribute editor associated with *attr*.
	*/
	LAttributeEditor(LAttribute* attr, QWidget* parent = nullptr);

	~LAttributeEditor();

	/*!
		Returns a list of child themeables.

		This function overrides LThemeable::child_themeables() to include
		additional child themeables.
	*/
	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
	) override;

	/*!
		Returns a pointer to the editor's fill control.
	*/
	LFillControl* fill_control() const;

	/*!
		Returns a pointer to the editor's line editor.
	*/
	LLineEditor* line_editor() const;

	/*!
		Returns a pointer to the editor's slider.
	*/
	LMiniSlider* slider() const;

private:
	void init_attributes();
	void init_layout();

	void update_icon_labels();

	LAttribute* m_attr;

	QHBoxLayout* m_controls_layout{ new QHBoxLayout };
	QHBoxLayout* m_icons_layout{ new QHBoxLayout };
	QHBoxLayout* m_links_buttons_layout{ new QHBoxLayout };
	QVBoxLayout* m_links_layout{ new QVBoxLayout };
	QVBoxLayout* m_overrides_layout{ new QVBoxLayout };

	LFillControl* m_fill_control{ new LFillControl };

	LLabel* m_label{ new LLabel };

	LMiniSlider* m_slider{ new LMiniSlider };

	LLineEditor* m_line_editor{ new LLineEditor };

	LLabel* m_link_icon_label =
		new LLabel(LGraphic(":/images/chain_link.svg", QSize(8, 18)));

	LLabel* m_overrides_icon_label =
		new LLabel(LGraphic(":/images/overrides_icon.svg", QSize(10, 18)));

	LButton* m_collapse_button{
		new LButton(
			LGraphic(":/images/collapse_arrow_right.svg", QSize(8, 12)),
			LGraphic(":/images/collapse_arrow_down.svg", QSize(12, 8))) };

	LWidget* m_icons_widget{ new LWidget };

	LTabBar* m_features_tab_bar{ new LTabBar };

	QWidget* m_features_widget{ new QWidget };

	LLinksView* m_links_view;

	LNewLinkWidget* m_new_link_widget{ nullptr };

	QMetaObject::Connection m_attr_link_changed_connection;
	QMetaObject::Connection m_new_link_widget_destroyed_connection;

	LWidget* m_links_widget{ new LWidget };

	LWidget* m_overrides_widget{ new LWidget };

	LButton* m_new_link_button{
		new LButton(
			LGraphic(":/images/new_theme.svg", QSize(18, 18)), "New Link") };

	LButton* m_break_link_button{
		new LButton(
			LGraphic(":/images/tab_exit.svg", QSize(16, 17)), "Break Link") };

	LStatePool* m_status_states{
		new LStatePool("Status", { "Active", "Inactive" }) };
};
LAYERS_NAMESPACE_END

#endif // LATTRIBUTEEDITOR_H
