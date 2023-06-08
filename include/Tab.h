#ifndef TAB_H
#define TAB_H

#include "Button.h"
#include "Graphic.h"
#include "Label.h"

namespace Layers
{
	/*!
		A Tab is a Widget that labels another widget and can be clicked by the
		user to switch between different widgets.
	*/
	class Tab : public Widget
	{
		Q_OBJECT

	signals:
		/*!
			This signal is emitted when the tab is clicked.
		*/
		void clicked();

		/*!
			This signal is emitted when the tab is closed.
		*/
		void closed();

	public:
		/*!
			Constructs a tab labeled with an *icon* and *text*.
		*/
		Tab(const Graphic& icon, const QString& text, QWidget* parent = nullptr);

		/*!
			Constructs a tab labeled with *text*.
		*/
		Tab(const QString& text, QWidget* parent = nullptr);

		/*!
			Returns a pointer to the tab's close button.
		*/
		Button* close_button() const;

		/*!
			Returns a pointer to the tab's text label.
		*/
		Label* text_label() const;

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private:
		void init();
		void init_attributes();
		void init_layout();

		QHBoxLayout* main_layout = new QHBoxLayout;

		Button* m_close_button{
			new Button(Graphic(":/images/tab_exit.svg", QSize(16, 17))) };

		Label* m_icon_label{ nullptr };

		Label* m_text_label{ nullptr };
	};
}

#endif // TAB_H
