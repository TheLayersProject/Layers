#ifndef MENULABELLAYER_H
#define MENULABELLAYER_H

#include "Button.h"
#include "Graphic.h"
#include "Label.h"
#include "Menu.h"

namespace Layers
{
	class MenuLabelLayer : public Widget
	{
		Q_OBJECT

	public:
		MenuLabelLayer(Menu* menu, QWidget* parent = nullptr);

		void replace_all_attributes_with(MenuLabelLayer* mll);

		void shrink();
		void expand();

		Button* back_button() const;
		Button* icon_button() const;

		Label* text_label() const;

	protected:
		void init_attributes();
		void init_child_themeable_reference_list();

		void setup_layout();

	private:
		QHBoxLayout* main_layout = new QHBoxLayout;

		Button* m_back_button{ new Button(new Graphic(":/svgs/back.svg", QSize(21, 18)), false) };
		Button* m_icon_button{ nullptr };

		Label* m_text_label{ nullptr };

		Widget* m_stretch_widget{ new Widget };
	};
}

#endif // MENULABELLAYER_H
