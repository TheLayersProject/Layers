#ifndef LWIDGETBUTTON_H
#define LWIDGETBUTTON_H

#include "layerswidgetsexports.h"

#include "llabel.h"
#include "lwidget.h"

namespace Layers
{
	class LAYERS_WIDGETS_EXPORT LWidgetButton : public LWidget
	{
		Q_OBJECT

	signals:
		void clicked();

	public:
		LWidgetButton(const QString& label_text, QWidget* parent = nullptr);
		LWidgetButton(const LGraphic& icon, const QString label_text, QWidget* parent = nullptr);

		LLabel* label() const;

		QString label_text() const;

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private:
		void init();
		void init_attributes();
		void init_layout();

		LLabel* m_icon_label{ nullptr };

		LLabel* m_label{ nullptr };
	};
}

#endif // LWIDGETBUTTON_H