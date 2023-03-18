#ifndef CUSTOMIZEMENU_H
#define CUSTOMIZEMENU_H

#include <QIntValidator>

#include "AttributeWidgets.h"
#include "Button.h"
#include "Graphic.h"
#include "Menu.h"
#include "ScrollArea.h"
#include "WidgetButtonGroup.h"

namespace Layers
{
	class CustomizePanel;
	class Window;

	class CustomizeMenu : public Menu
	{
		Q_OBJECT

	public:
		CustomizeMenu(QWidget* parent = nullptr);
		~CustomizeMenu();

		Button* apply_button() const;

		void open_customize_panel(CustomizePanel* customize_panel);

		QList<CustomizePanel*>& panels();

		QWidget* preview_widget() const;

		int calculated_topbar_content_width();

		void set_preview_widget(QWidget* widget);

		int topbar_content_width(bool include_collapse_button);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private:
		void adjust_collapsed_widget();
		void collapse_text_buttons();
		void expand_text_buttons();
		void setup_layout();

		AWGroup* m_control_aw_group{ new AWGroup(nullptr) };
		ColorAW* m_control_color_aw{ new ColorAW(nullptr) };
		CornerRadiiAW* m_control_corner_radii_aw{ new CornerRadiiAW(nullptr) };
		FillAW* m_control_fill_aw{ new FillAW(nullptr) };
		NumberAW* m_control_number_aw{ new NumberAW(nullptr, nullptr) };
		StateAW* m_control_state_aw{ new StateAW };
		WidgetButton* m_control_widget_button{ new WidgetButton(new Graphic(":/svgs/settings_animated.svg", QSize(24, 24)), QString("")) };
		WidgetButtonGroup* m_control_widget_button_group{ new WidgetButtonGroup(QString(""), QList<WidgetButton*>()) };

		Themeable* m_ccp_themeable{ new Themeable };

		QHBoxLayout* m_main_layout{ new QHBoxLayout };
		QVBoxLayout* m_collapsed_text_buttons_layout{ new QVBoxLayout };
		QVBoxLayout* m_sidebar_layout{ new QVBoxLayout };
		QHBoxLayout* m_topbar_layout{ new QHBoxLayout };
		QGridLayout* m_preview_layout{ new QGridLayout };

		Widget* m_sidebar_widget{ new Widget };
		Widget* m_topbar{ new Widget };
		Widget* m_preview_frame = new Widget;

		ScrollArea* m_sidebar{ new ScrollArea };
		ScrollArea* m_preview_scroll_area{ new ScrollArea };

		QWidget* m_preview_widget{ nullptr };

		QList<CustomizePanel*> m_panel_stack;
		QList<Button*> m_text_button_stack;
		QList<Button*> m_topbar_text_buttons;
		QList<Button*> m_collapsed_text_buttons;
		QList<Graphic*> m_arrow_graphics;

		QSize* m_previous_size{ nullptr };

		Button* m_apply_button{ new Button("Apply", true) };
		Button* m_collapse_menu_button{ new Button(new Graphic(":/svgs/ellipsis.svg", QSize(32, 8)), true) };

		Graphic* m_control_arrow_graphic{ new Graphic(":/svgs/collapse_arrow_right.svg", QSize(8, 12)) };

		CustomizePanel* m_control_customize_panel{ nullptr };

		Button* m_control_text_button{ new Button("") };

		Widget* m_collapse_menu{ new Widget };
	};
}

#endif // CUSTOMIZEMENU_H
