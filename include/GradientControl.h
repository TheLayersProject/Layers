#ifndef GRADIENTCONTROL_H
#define GRADIENTCONTROL_H

#include "Widget.h"

namespace Layers
{
	class GradientControl : public Widget
	{
		Q_OBJECT

	signals:
		void gradient_changed();

	public:
		GradientControl(QWidget* parent = nullptr);

		void init_attributes();

		void set_attribute(Attribute* attribute);

	public slots:
		void set_current_editting_state(const QString& state);

	protected:
		bool eventFilter(QObject* object, QEvent* event);
		void paintEvent(QPaintEvent* event);

	private:
		QList<QString> m_attribute_states{ QList<QString>() };

		QString m_current_editting_state{ "" };

		Attribute* m_attribute{ nullptr };
	};
}

#endif // GRADIENTCONTROL_H
