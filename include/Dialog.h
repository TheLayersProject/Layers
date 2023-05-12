#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "Button.h"
#include "Graphic.h"

namespace Layers
{
	class Dialog : public QDialog, public ThemeableBox
	{
		Q_OBJECT

	public:
		Dialog(const QString& title = "Dialog", QWidget* parent = nullptr);

		void set_icon(Graphic* icon);

		void setLayout(QLayout* layout);

	public slots:
		void update_content_margins();
		void update_titlebar();

	protected:
		void init_attributes();

		bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;

		void paintEvent(QPaintEvent* event) override;

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

	private:
		void init_titlebar();

		void setup_layout();

		bool m_hovering{ false };

		QHBoxLayout* m_titlebar_layout = new QHBoxLayout;

		Widget* m_titlebar{ new Widget };

		Label* m_title_label;

		Button* m_exit_button = new Button(
			new Graphic(":/svgs/exit.svg", QSize(20, 20)));
	};
}

#endif // DIALOG_H
