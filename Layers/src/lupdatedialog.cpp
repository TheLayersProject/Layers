#include <Layers/lupdatedialog.h>

using Layers::LUpdateDialog;
using Layers::LThemeable;

LUpdateDialog::LUpdateDialog(
	const QString& version, const QString& latest_version,
	QWidget* parent
) :
	m_message_label{
		new LLabel(
			"There is an update available to download. "
			"Would you like to update the software now?\n\n"
			"Current Version: " + version + "\n\n"
			"Latest Version: " + latest_version)
	},
	LDialog("Update Available", parent)
{
	setFixedSize(525, 300);
	set_icon(LGraphic(":/images/update_icon.svg"));
	set_name("Update Dialog");

	m_remind_me_later_button->set_name("Remind Me Later Button");
	m_remind_me_later_button->set_padding(8, 6, 8, 6);
	connect(m_remind_me_later_button, &LButton::clicked,
		[this] { done(QDialog::Rejected); });

	m_update_button->set_name("Update Button");
	m_update_button->set_padding(8, 6, 8, 6);
	connect(m_update_button, &LButton::clicked,
		[this] { done(QDialog::Accepted); });

	m_message_label->set_name("Message Label");
	m_message_label->set_font_size(15);
	m_message_label->setWordWrap(true);

	init_layout();
}

void LUpdateDialog::init_layout()
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
