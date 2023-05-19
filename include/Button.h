#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsOpacityEffect>
#include <QHBoxLayout>

#include "Label.h"
#include "Widget.h"

namespace Layers
{
	/*!
		A Button is a Widget that provides the user with a way to interact with
		the software to perform certain actions. Users interact with buttons by
		clicking them.
	*/
	class Button : public Widget
	{
		Q_OBJECT

	signals:
		/*!
			This signal is emitted when the user clicks on the button.
		*/
		void clicked();

	public:
		/*!
			Constructs a button with a graphic and text.
		*/
		Button(Graphic* graphic, const QString& text,
			QWidget* parent = nullptr);

		/*!
			Constructs a button with a graphic.

			By default, the fill is disabled.
		*/
		Button(Graphic* graphic, QWidget* parent = nullptr);

		/*!
			Constructs a button with text.
		*/
		Button(const QString& text, QWidget* parent = nullptr);

		/*!
			Constructs a button with two graphics. The graphic that is
			displayed depends on whether the button is set to an enabled state
			or not.

			By default, the fill is disabled.
		*/
		Button(Graphic* graphic_before, Graphic* graphic_after,
			QWidget* parent = nullptr);

		~Button();

		/*!
			Disables or enables text hover coloring depending on *cond*.
		*/
		void disable_text_hover_color(bool cond = true);

		/*!
			Returns true if the button is disabled. Otherwise, returns false.
		*/
		bool disabled() const;

		/*!
			Returns a pointer to the button's graphic. If the button does not
			have a graphic, then nullptr is returned.
		*/
		Graphic* graphic() const;

		/*!
			Disables or enables the button depending on *cond*.
		*/
		void set_disabled(bool cond = true);

		/*!
			Sets the font size of the button's text.
		*/
		void set_font_size(int size);

		/*!
			Sets the button padding with a single value.
		*/
		void set_padding(int padding);

		/*!
			Sets the button padding with individual values.
		*/
		void set_padding(int left, int top, int right, int bottom);

		/*!
			Sets the padding of the button's text with individual values.
		*/
		void set_text_padding(int left, int top, int right, int bottom);

		/*!
			Toggles the visibility of the graphics.

			This function only works if the button was constructed with two
			graphics.
		*/
		void toggle_graphics();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private:
		void init();
		void init_layout();

		QHBoxLayout* main_layout{ new QHBoxLayout };

		QGraphicsOpacityEffect* m_button_opacity{ new QGraphicsOpacityEffect };

		bool m_disabled{ false };

		bool m_use_graphic_hover_color{ true };
		bool m_use_text_hover_color{ true };

		Graphic* m_graphic{ nullptr };
		Graphic* m_graphic_after{ nullptr };

		Label* m_text_label{ nullptr };
	};
}

#endif // BUTTON_H
