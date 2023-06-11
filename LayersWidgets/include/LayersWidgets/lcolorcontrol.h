#ifndef LCOLORCONTROL_H
#define LCOLORCONTROL_H

#include "layerswidgetsexports.h"

#include "lwidget.h"

namespace Layers
{
	/*!
		A LColorControl is a LWidget that gives the user a way to access the
		LColorDialog. When the user clicks on the control, the application's
		LColorDialog is displayed.
	*/
	class LAYERS_WIDGETS_EXPORT LColorControl : public LWidget
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
		LColorControl(QWidget* parent = nullptr);

		~LColorControl();

		/*!
			Displays the application's LColorDialog to the user.
		*/
		void click();

		/*!
			Disables or enables the click functionality of the control
			depending on *cond*.
		*/
		void disable_clicking(bool cond = true);

	public slots:
		/*!
			Sets the state that is currently being edited.
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

#endif // LCOLORCONTROL_H
