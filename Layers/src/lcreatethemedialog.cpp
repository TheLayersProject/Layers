#include <Layers/lcreatethemedialog.h>

#include <Layers/lapplication.h>

using Layers::LCreateThemeDialog;
using Layers::LThemeable;

LCreateThemeDialog::LCreateThemeDialog(QWidget* parent) :
	LDialog("Create Theme", parent)
{
	init_attributes();

	set_icon(LGraphic(":/images/new_theme.svg", QSize(20, 20)));
	set_name("Create Theme Dialog");
	setFixedSize(525, 300);
	setModal(true);

	m_create_button->set_name("Create Button");
	m_create_button->set_disabled();
	connect(m_create_button, &LButton::clicked, [this] { done(QDialog::Accepted); });

	m_name_label->set_name("Name Label");
	m_name_label->set_font_size(15);

	m_start_as_label->set_name("Start As Label");
	m_start_as_label->set_font_size(15);

	m_theme_name_line_editor->set_name("Theme Name Line Editor");
	m_theme_name_line_editor->setFixedSize(250, 50);
	m_theme_name_line_editor->set_margin(0);
	m_theme_name_line_editor->set_font_size(15);
	connect(m_theme_name_line_editor, &LLineEditor::text_edited, [this] 
	{
		bool has_char_other_than_space = false;

		QString text = m_theme_name_line_editor->text()->as<QString>();

		for (const QChar& character : text)
		{
			if (character != ' ') has_char_other_than_space = true;
		}

		if (!has_char_other_than_space)
		{
			m_create_button->set_disabled();
			return;
		}

		if (text == "")
		{
			m_create_button->set_disabled();
			return;
		}

		if (m_create_button->disabled())
			m_create_button->set_disabled(false);
	});

	m_start_theme_combobox->set_name("Start Theme Combobox");

	init_layout();

	assign_tag_prefixes();
}

QString LCreateThemeDialog::new_theme_name()
{
	return m_theme_name_line_editor->text()->as<QString>().simplified();
}

void LCreateThemeDialog::add_theme_to_combobox(LTheme* theme)
{
	m_start_theme_combobox->addItem(theme);
}

void LCreateThemeDialog::clear()
{
	m_theme_name_line_editor->set_text("");

	m_create_button->set_disabled();
}

void LCreateThemeDialog::clear_theme_combobox()
{
	m_start_theme_combobox->clear();
}

QString LCreateThemeDialog::copy_theme_id()
{
	return m_start_theme_combobox->currentData().toString();
	//return m_start_theme_combobox->currentData(Qt::DisplayRole).toString();
}

void LCreateThemeDialog::set_current_start_theme_name(const QString& theme_id)
{
	//if (m_start_theme_combobox->count().contains(theme_name))
	//	m_start_theme_combobox->set_current_item(theme_name);

	for (int i = 0; i < m_start_theme_combobox->count(); i++)
		if (m_start_theme_combobox->itemData(i) == theme_id)
			m_start_theme_combobox->setCurrentIndex(i);
}

int LCreateThemeDialog::exec()
{
	m_theme_name_line_editor->setFocus();

	return QDialog::exec();
}

void LCreateThemeDialog::init_attributes()
{
	//m_start_theme_combobox->corner_radii_top_left()->set_value(7.0);
	//m_start_theme_combobox->corner_radii_top_right()->set_value(7.0);
	//m_start_theme_combobox->corner_radii_bottom_left()->set_value(7.0);
	//m_start_theme_combobox->corner_radii_bottom_right()->set_value(7.0);

	m_theme_name_line_editor->border_thickness()->set_value(3.0);
	m_theme_name_line_editor->corner_radii_top_left()->set_value(7.0);
	m_theme_name_line_editor->corner_radii_top_right()->set_value(7.0);
	m_theme_name_line_editor->corner_radii_bottom_left()->set_value(7.0);
	m_theme_name_line_editor->corner_radii_bottom_right()->set_value(7.0);
	m_theme_name_line_editor->left_padding()->set_value(10.0);
}

void LCreateThemeDialog::init_layout()
{
	QVBoxLayout* layout = new QVBoxLayout;

	layout->setContentsMargins(15, 22, 15, 0);
	layout->addWidget(m_name_label);
	layout->addWidget(m_theme_name_line_editor);
	layout->addSpacing(20);
	layout->addWidget(m_start_as_label);
	layout->addWidget(m_start_theme_combobox);
	layout->addWidget(m_create_button);
	layout->addStretch();
	layout->setAlignment(m_name_label, Qt::AlignLeft);
	layout->setAlignment(m_theme_name_line_editor, Qt::AlignLeft);
	layout->setAlignment(m_start_as_label, Qt::AlignLeft);
	layout->setAlignment(m_start_theme_combobox, Qt::AlignLeft);
	layout->setAlignment(m_create_button, Qt::AlignRight);

	setLayout(layout);
}
