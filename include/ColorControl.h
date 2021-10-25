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

		void set_attribute(Attribute* attribute);

	public slots:
		void set_current_editting_state(const QString& state);

	protected:
		bool eventFilter(QObject* object, QEvent* event);
		void paintEvent(QPaintEvent* event);

	private:
		bool clicking_disabled{ false };
		bool open_on_release{ false };

		StatefulAttribute* m_stateful_attribute{ nullptr };

		StatelessAttribute* m_stateless_attribute{ nullptr };

		QString m_current_editting_state{ "" };

		QList<QString> m_attribute_states{ QList<QString>() };
	};
}

#endif // COLORCONTROL_H
