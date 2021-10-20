#ifndef COLORCONTROL_H
#define COLORCONTROL_H

#include "Widget.h"

namespace Layers
{
	class ColorControl : public Widget
	{
		Q_OBJECT

	signals:
		void color_changed();

	public:
		ColorControl(QWidget* parent = nullptr);

		void click();

		void disable_clicking(bool cond = true);

		void init_attributes();

	protected:
		bool eventFilter(QObject* object, QEvent* event);
		void paintEvent(QPaintEvent* event);

	private:
		bool clicking_disabled{ false };
		bool open_on_release{ false };
	};
}

#endif // COLORCONTROL_H
