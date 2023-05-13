#ifndef WIDGETBUTTON_H
#define WIDGETBUTTON_H

#include "Graphic.h"
#include "Label.h"
#include "Widget.h"

namespace Layers
{
	class WidgetButton : public Widget
	{
		Q_OBJECT

	signals:
		void clicked();

	public:
		WidgetButton(const QString& label_text, QWidget* parent = nullptr);
		WidgetButton(Graphic* icon, const QString label_text, QWidget* parent = nullptr);

		Label* label() const;

		QString label_text() const;

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private:
		void init();

		void init_attributes();

		void init_layout();

		Label* m_label{ nullptr };
	};
}

#endif // WIDGETBUTTON_H
