#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <QIntValidator>

#include "Button.h"

namespace Layers
{
	/*!
		A Navigator is a QWidget and a Themeable that provides the user with a
		set of text-buttons that represent items of a hierarchy. The buttons
		can be clicked to navigate between the hierarchy of items.
	*/
	class Navigator : public QWidget, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs a navigator.
		*/
		Navigator(QWidget* parent = nullptr);

		//~Navigator();

		/*!
			Creates a new text-button for the navigator labeled with *text*.
			
			The button is returned so that the caller can connect it with other
			functionality.
		*/
		Button* create_text_button(const QString& text);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private:
		int calculated_width_after_expand();

		void collapse_text_buttons();

		int content_width(bool include_collapse_button);

		Label* create_arrow_label();

		void expand_text_buttons();

		void init_layout();

		QList<Label*> m_arrow_labels;

		Widget* m_collapse_menu{ new Widget };

		Button* m_collapse_menu_button{
			new Button(Graphic(":/images/ellipsis.svg", QSize(32, 8))) };

		QVBoxLayout* m_collapse_menu_layout{ new QVBoxLayout };

		QList<Button*> m_collapsed_text_buttons;

		Label* m_control_arrow_label{
			new Label(Graphic(":/images/collapse_arrow_right.svg", QSize(8, 12))) };

		Button* m_control_text_button{ new Button("") };

		QHBoxLayout* m_main_layout{ new QHBoxLayout };

		QList<Button*> m_text_button_stack;

		QList<Button*> m_topbar_text_buttons;
	};
}

#endif // NAVIGATOR_H
