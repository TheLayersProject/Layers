#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "Button.h"
#include "Graphic.h"

namespace Layers
{
	/*!
		A Dialog is a QDialog and a ThemeableBox that is used for short-term
		tasks or brief communications with the user.
	*/
	class Dialog : public QDialog, public ThemeableBox
	{
		Q_OBJECT

	public:
		/*!
			Constructs a dialog labeled with *title*.
		*/
		Dialog(const QString& title = "Dialog", QWidget* parent = nullptr);

		/*!
			Sets the dialog's icon.
		*/
		void set_icon(const Graphic& icon);

		/*!
			Sets the layout of the dialog.
		*/
		void setLayout(QLayout* layout);

	protected:
		bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;

		void paintEvent(QPaintEvent* event) override;

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

	private slots:
		void update_content_margins();
		void update_titlebar();

	private:
		void init_attributes();
		void init_layout();
		void init_titlebar();

		bool m_hovering{ false };

		QHBoxLayout* m_titlebar_layout = new QHBoxLayout;

		Widget* m_titlebar{ new Widget };

		Label* m_icon_label{ nullptr };

		Label* m_title_label{ nullptr };

		Button* m_exit_button = new Button(
			Graphic(":/svgs/exit.svg", QSize(20, 20)));
	};
}

#endif // DIALOG_H
