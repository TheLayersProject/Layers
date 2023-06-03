#include "UpdateDialog.h"
#include "calculate.h"

#include "Application.h"

#include <Windows.h>
#include <windowsx.h>

#include <QApplication>
#include <QPainterPath>

using Layers::UpdateDialog;
using Layers::Themeable;

UpdateDialog::UpdateDialog(
	const QString& current_version_tag,
	const QString& latest_version_tag, QWidget* parent
) :
	m_message_label{
		new Label(
			"There is an update available to download. "
			"Would you like to update the software now?\n\n"
			"Current Version: " + current_version_tag + "\n\n"
			"Latest Version: " + latest_version_tag)
	},
	Dialog("Update Available", parent)
{
	setFixedSize(525, 300);
	set_icon(new Graphic(":/svgs/update_icon.svg"));
	set_name("Update Dialog");

	m_remind_me_later_button->set_name("Remind Me Later Button");
	m_remind_me_later_button->set_padding(8, 6, 8, 6);
	m_remind_me_later_button->disable_text_hover_color();
	connect(m_remind_me_later_button, &Button::clicked,
		[this] { done(QDialog::Rejected); });

	m_update_button->set_name("Update Button");
	m_update_button->set_padding(8, 6, 8, 6);
	m_update_button->disable_text_hover_color();
	connect(m_update_button, &Button::clicked,
		[this] { done(QDialog::Accepted); });

	m_message_label->set_name("Message Label");
	m_message_label->set_font_size(15);
	m_message_label->setWordWrap(true);

	setup_layout();

	// Assign tag prefixes last!
	assign_tag_prefixes();

	// Set theme
	apply_theme(*layersApp->active_theme());
}

Themeable* UpdateDialog::clone()
{
	return new UpdateDialog("0.0.0", "0.0.0");
}

void UpdateDialog::setup_layout()
{
	// Buttons Layout
	QHBoxLayout* buttons_layout = new QHBoxLayout;

	buttons_layout->setContentsMargins(0, 0, 0, 0);
	buttons_layout->setSpacing(15);
	buttons_layout->addStretch();
	buttons_layout->addWidget(m_remind_me_later_button);
	buttons_layout->addWidget(m_update_button);

	// Layout
	QVBoxLayout* layout = new QVBoxLayout;

	layout->setContentsMargins(15, 22, 15, 15);
	layout->addWidget(m_message_label);
	layout->addStretch();
	layout->addLayout(buttons_layout);
	layout->setAlignment(m_message_label, Qt::AlignLeft);

	setLayout(layout);
}
