#ifndef MENULABELLAYER_H
#define MENULABELLAYER_H

#include "Button.h"
#include "Graphic.h"
#include "Label.h"

namespace Layers
{
	class Tab : public Widget
	{
		Q_OBJECT

	signals:
		void clicked();
		void closed();

	public:
		Tab(const Graphic& icon, const QString& text, QWidget* parent = nullptr);
		Tab(const QString& text, QWidget* parent = nullptr);

		Button* close_button() const;

		Label* text_label() const;

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private:
		void init();
		void init_attributes();
		void init_layout();

		QHBoxLayout* main_layout = new QHBoxLayout;

		Button* m_close_button{
			new Button(Graphic(":/images/tab_exit.svg", QSize(16, 17))) };

		Label* m_icon_label{ nullptr };

		Label* m_text_label{ nullptr };
	};
}

#endif // MENULABELLAYER_H
