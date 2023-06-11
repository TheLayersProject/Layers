#ifndef LNAVIGATOR_H
#define LNAVIGATOR_H

#include <QIntValidator>

#include "layerswidgetsexports.h"

#include "lbutton.h"

namespace Layers
{
	/*!
		A LNavigator is a QWidget and a LThemeable that provides the user with a
		set of text-buttons that represent items of a hierarchy. The buttons
		can be clicked to navigate between the hierarchy of items.
	*/
	class LAYERS_WIDGETS_EXPORT LNavigator : public QWidget, public LThemeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs a navigator.
		*/
		LNavigator(QWidget* parent = nullptr);

		//~LNavigator();

		/*!
			Creates a new text-button for the navigator labeled with *text*.
			
			The button is returned so that the caller can connect it with other
			functionality.
		*/
		LButton* create_text_button(const QString& text);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private:
		int calculated_width_after_expand();

		void collapse_text_buttons();

		int content_width(bool include_collapse_button);

		LLabel* create_arrow_label();

		void expand_text_buttons();

		void init_layout();

		QList<LLabel*> m_arrow_labels;

		LWidget* m_collapse_menu{ new LWidget };

		LButton* m_collapse_menu_button{
			new LButton(LGraphic(":/images/ellipsis.svg", QSize(32, 8))) };

		QVBoxLayout* m_collapse_menu_layout{ new QVBoxLayout };

		QList<LButton*> m_collapsed_text_buttons;

		LLabel* m_control_arrow_label{
			new LLabel(LGraphic(":/images/collapse_arrow_right.svg", QSize(8, 12))) };

		LButton* m_control_text_button{ new LButton("") };

		QHBoxLayout* m_main_layout{ new QHBoxLayout };

		QList<LButton*> m_text_button_stack;

		QList<LButton*> m_topbar_text_buttons;
	};
}

#endif // LNAVIGATOR_H
