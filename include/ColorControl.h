#ifndef COLORCONTROL_H
#define COLORCONTROL_H

#include "Widget.h"

namespace Layers
{
	/*!
		A ColorControl is a Widget that gives the user a way to access the
		ColorDialog. When the user clicks on the control, the application's
		ColorDialog is displayed.
	*/
	class ColorControl : public Widget
	{
		Q_OBJECT

	signals:
		/*!
			This signal is emitted if the associated color attribute changes.
		*/
		void color_changed();

	public:
		/*!
			Constructs a color control.
		*/
		ColorControl(QWidget* parent = nullptr);

		~ColorControl();

		/*!
			Displays the application's ColorDialog to the user.
		*/
		void click();

		/*!
			Disables or enables the click functionality of the control
			depending on *cond*.
		*/
		void disable_clicking(bool cond = true);

	public slots:
		/*!
			Sets the state that is currently being editted.
		*/
		void set_current_editing_state(const QString& state);

	protected:
		bool eventFilter(QObject* object, QEvent* event);

	private:
		void init_attributes();

		bool clicking_disabled{ false };
		bool open_on_release{ false };

		QMetaObject::Connection attribute_connection;

		QStringList m_attribute_states;
	};
}

#endif // COLORCONTROL_H
