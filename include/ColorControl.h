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
		~ColorControl();

		void click();

		void disable_clicking(bool cond = true);

		void init_attributes();

		//void set_attribute(Attribute* attribute);

		//Attribute a_corner_radii{ Attribute("Corner Radii", QVariant::fromValue(5)) };
		//Attribute a_inner_border_color{ Attribute("Inner Border Color", QColor("#2c2c2c")) };
		//Attribute a_outer_border_color{ Attribute("Outer Border Color", QColor("#d6d6d6")) };

	public slots:
		void set_current_editting_state(const QString& state);

	protected:
		bool eventFilter(QObject* object, QEvent* event);
		//void paintEvent(QPaintEvent* event);

	private:
		bool clicking_disabled{ false };
		bool open_on_release{ false };

		QMetaObject::Connection attribute_connection;

		QList<QString> m_attribute_states{ QList<QString>() };
	};
}

#endif // COLORCONTROL_H
