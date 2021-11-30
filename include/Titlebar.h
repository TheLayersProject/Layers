#ifndef TITLEBAR_H
#define TITLEBAR_H

#include "MenuLabelLayer.h"

namespace Layers
{
	class Titlebar : public Widget
	{
		Q_OBJECT

	signals:
		void window_icon_updated();

	public:
		Titlebar(QWidget* parent = nullptr);

		void add_mll(MenuLabelLayer* mll);
		void remove_mlls_past(int index);

		bool is(QWidget* widget);

		void set_window_icon(const Graphic& icon_graphic);

		void set_window_title(const QString& title);

		Button* window_icon() const;
		Button* settings_button() const;
		Button* minimize_button() const;
		Button* maximize_button() const;
		Button* exit_button() const;

	protected:
		void init_child_themeable_reference_list();

		void resizeEvent(QResizeEvent* event);

		void setup_layout();

	private:
		QHBoxLayout* main_layout = new QHBoxLayout;

		Button* m_window_icon{ new Button(new Graphic(QFile(":/image_sequences/layers_logo.imgseq"), QSize(35, 35)), true) };

		Label* m_window_title_label{ new Label("Window") };

		Button* m_settings_button{ new Button(new Graphic(":/svgs/settings.svg", QSize(20, 20)), true) };
		Button* m_minimize_button{ new Button(new Graphic(":/svgs/minimize.svg", QSize(20, 20)), true) };
		Button* m_maximize_button{ new Button(new Graphic(":/svgs/maximize.svg", QSize(20, 20)), true) };
		Button* m_exit_button{ new Button(new Graphic(":/svgs/exit.svg", QSize(20, 20)), true) };

		Widget* m_buttons_container{ new Widget(this) };

		QList<MenuLabelLayer*> mll_stack;

		MenuLabelLayer* m_base_mll{ nullptr };

		MenuLabelLayer* m_control_mll{ new MenuLabelLayer(new Menu("Control Menu", new Graphic(":/svgs/icon_icon.svg", QSize(20, 20)))) };

		Widget* m_stretch_widget{ new Widget };
	};
}

#endif // TITLEBAR_H
