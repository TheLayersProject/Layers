#include "../../../include/CreateNewThemeDialog.h"

using Layers::CreateNewThemeDialog;

CreateNewThemeDialog::CreateNewThemeDialog(QWidget* parent) :
	Dialog("Create New Theme", parent)
{
	init_attributes();
	init_child_themeable_list();

	set_name("create_new_theme_dialog");

	m_create_button->set_name("create_button");
	//m_create_button->set_padding(8, 6, 8, 6);
	m_create_button->set_text_padding(1, 3, 0, 0);
	m_create_button->disable_text_hover_color();
	m_create_button->set_disabled();
	connect(m_create_button, &Button::clicked, [this] { done(QDialog::Accepted); });

	m_name_label->set_name("name_label");
	m_name_label->set_proper_name("Name Label");
	m_name_label->set_font_size(15);

	m_start_as_label->set_name("start_as_label");
	m_start_as_label->set_proper_name("Start as Label");
	m_start_as_label->set_font_size(15);

	m_theme_name_line_edit->set_name("theme_name_line_edit");
	m_theme_name_line_edit->set_proper_name("Name Line Editor");
	m_theme_name_line_edit->setFixedSize(250, 50);
	m_theme_name_line_edit->set_margin(0);
	m_theme_name_line_edit->set_font_size(15);
	connect(m_theme_name_line_edit, &LineEditor::text_edited, [this] 
	{
		bool has_char_other_than_space = false;

		for (const QChar& character : m_theme_name_line_edit->text())
		{
			if (character != ' ') has_char_other_than_space = true;
		}

		if (!has_char_other_than_space)
		{
			m_create_button->set_disabled();
			return;
		}

		if (m_theme_name_line_edit->text() == "")
		{
			m_create_button->set_disabled();
			return;
		}
		
		for (const QString& theme_name : m_start_theme_combobox->items())
			if (m_theme_name_line_edit->text().toLower().simplified() == theme_name.toLower().simplified())
			{
				m_create_button->set_disabled();
				return;
			}

		if (m_create_button->disabled()) m_create_button->set_disabled(false);
	});

	m_start_theme_combobox->set_name("start_theme_combobox");
	m_start_theme_combobox->set_proper_name("Start as Combobox");
	m_start_theme_combobox->setFixedSize(250, 50);
	m_start_theme_combobox->set_font_size(15);

	setup_layout();
}

QString CreateNewThemeDialog::new_theme_name()
{
	return m_theme_name_line_edit->text().simplified();
}

void CreateNewThemeDialog::add_theme_name_to_combobox(const QString& theme_name)
{
	m_start_theme_combobox->add_item(theme_name);
}

void CreateNewThemeDialog::clear()
{
	m_theme_name_line_edit->set_text("");

	m_create_button->set_disabled();
}

QString CreateNewThemeDialog::copy_theme_name()
{
	return m_start_theme_combobox->current_item();
}

void CreateNewThemeDialog::set_current_start_theme_name(const QString& theme_name)
{
	if (m_start_theme_combobox->items().contains(theme_name))
		m_start_theme_combobox->set_current_item(theme_name);
}

void CreateNewThemeDialog::init_attributes()
{
	m_start_theme_combobox->corner_radii.top_left.set_value(7.0);
	m_start_theme_combobox->corner_radii.top_right.set_value(7.0);
	m_start_theme_combobox->corner_radii.bottom_left.set_value(7.0);
	m_start_theme_combobox->corner_radii.bottom_right.set_value(7.0);

	m_theme_name_line_edit->border.thickness.set_value(3.0);
	m_theme_name_line_edit->corner_radii.top_left.set_value(7.0);
	m_theme_name_line_edit->corner_radii.top_right.set_value(7.0);
	m_theme_name_line_edit->corner_radii.bottom_left.set_value(7.0);
	m_theme_name_line_edit->corner_radii.bottom_right.set_value(7.0);
	m_theme_name_line_edit->a_left_padding.set_value(10.0);
}

void CreateNewThemeDialog::init_child_themeable_list()
{
	add_child_themeable_pointer(m_create_button);
	add_child_themeable_pointer(m_name_label);
	add_child_themeable_pointer(m_start_as_label);
	add_child_themeable_pointer(m_start_theme_combobox);
	add_child_themeable_pointer(m_theme_name_line_edit);
}

void CreateNewThemeDialog::setup_layout()
{
	QVBoxLayout* layout = new QVBoxLayout;

	layout->setContentsMargins(15, 22, 15, 0);
	layout->addWidget(m_name_label);
	layout->addWidget(m_theme_name_line_edit);
	layout->addSpacing(20);
	layout->addWidget(m_start_as_label);
	layout->addWidget(m_start_theme_combobox);
	layout->addWidget(m_create_button);
	layout->addStretch();
	layout->setAlignment(m_name_label, Qt::AlignLeft);
	layout->setAlignment(m_theme_name_line_edit, Qt::AlignLeft);
	layout->setAlignment(m_start_as_label, Qt::AlignLeft);
	layout->setAlignment(m_start_theme_combobox, Qt::AlignLeft);
	layout->setAlignment(m_create_button, Qt::AlignRight);

	setLayout(layout);
}
