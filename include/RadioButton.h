#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include "Themeable.h"

#include <QWidget>

namespace Layers
{
	class RadioButton : public QWidget, public Themeable
	{
		Q_OBJECT

	signals:
		void clicked();

	public:
		RadioButton(QWidget* parent = nullptr);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void paintEvent(QPaintEvent* event) override;

	private:
		void init_attributes();

		Attribute* m_active_dot_fill{ new Attribute("active_dot_fill", QColor(Qt::black)) };

		BorderAttributes* m_border{ new BorderAttributes };

		Attribute* m_fill{ new Attribute("fill", {
			{ "Active", QColor(Qt::lightGray) },
			{ "Inactive", QColor(Qt::darkGray) }
			}) };

		Attribute* m_margin{ new Attribute("margin", Variant(10)) };
	};
}

#endif // RADIOBUTTON_H
