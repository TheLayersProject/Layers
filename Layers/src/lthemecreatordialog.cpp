#include <Layers/lthemecreatordialog.h>

#include <Layers/lapplication.h>

using Layers::LThemeCreatorDialog;
using Layers::LThemeable;

LThemeCreatorDialog::LThemeCreatorDialog(QWidget* parent) :
	LDialog("Create Theme", parent)
{
	init_attributes();
	init_layout();

	set_icon(LGraphic(":/images/new_theme.svg", QSize(20, 20)));
	setObjectName("Theme Creator Dialog");
	setFixedSize(290, 300);
	setModal(true);

	m_name_label->setObjectName("Name Label");
	m_name_label->set_font_size(15);

	m_name_editor->setObjectName("Name Editor");
	m_name_editor->setFixedSize(250, 50);
	m_name_editor->set_margin(0);
	m_name_editor->set_font_size(15);
	connect(m_name_editor, &LLineEditor::text_edited,
		[this] 
		{
			bool has_char_other_than_space = false;

			QString text = m_name_editor->text()->as<QString>();

			for (const QChar& character : text)
			{
				if (character != ' ')
					has_char_other_than_space = true;
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

	m_parent_theme_label->setObjectName("Parent Theme Label");
	m_parent_theme_label->set_font_size(15);

	m_parent_theme_combobox->setObjectName("Parent Theme Combobox");

	for (LTheme* theme : layersApp->themes())
		if (theme->has_implementation(layersApp->app_identifier()))
		{
			if (theme == activeTheme())
				m_parent_theme_combobox->addItem(theme, true);
			else
				m_parent_theme_combobox->addItem(theme);
		}

	m_create_button->setObjectName("Create Button");
	m_create_button->set_disabled();
	m_create_button->set_font_size_f(10.5);
	m_create_button->set_padding(6);
	m_create_button->setFixedHeight(30);
	connect(m_create_button, &LButton::clicked,
		this, &LThemeCreatorDialog::create_theme);

	apply_theme_item(activeTheme()->find_item(path()));
}

int LThemeCreatorDialog::exec()
{
	m_name_editor->setFocus();

	return QDialog::exec();
}

void LThemeCreatorDialog::create_theme()
{
	LTheme* copy_theme =
		m_parent_theme_combobox->currentData().value<LTheme*>();
	LTheme* new_theme =
		new LTheme(m_name_editor->text()->as<QString>().simplified());

	QDir new_theme_dir = latest_T_version_path() + new_theme->id() + "\\";
	QDir copy_theme_dir = copy_theme->dir();

	new_theme->set_dir(new_theme_dir);

	if (!new_theme_dir.exists())
		new_theme_dir.mkdir(".");

	// Copy all files except meta.json since a new one is created below
	for (const QString& file_name : copy_theme_dir.entryList(QDir::Files))
		if (file_name != "meta.json")
		{
			QFile::copy(
				copy_theme_dir.filePath(file_name),
				new_theme_dir.filePath(file_name));

			QFile::setPermissions(
				new_theme_dir.filePath(file_name),
				QFileDevice::WriteUser);
		}

	for (const QString& theme_id : copy_theme->lineage())
		new_theme->append_to_lineage(theme_id);

	new_theme->append_to_lineage(copy_theme->id());
	new_theme->save_meta_file();

	layersApp->add_theme(new_theme);
	layersApp->apply_theme(new_theme);

	done(QDialog::Accepted);
}

void LThemeCreatorDialog::init_attributes()
{
	m_name_editor->border_thickness()->set_value(3.0);
	m_name_editor->corner_radii_top_left()->set_value(5.0);
	m_name_editor->corner_radii_top_right()->set_value(5.0);
	m_name_editor->corner_radii_bottom_left()->set_value(5.0);
	m_name_editor->corner_radii_bottom_right()->set_value(5.0);
	m_name_editor->left_padding()->set_value(10.0);
}

void LThemeCreatorDialog::init_layout()
{
	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(m_name_label);
	layout->addWidget(m_name_editor);
	layout->addSpacing(20);
	layout->addWidget(m_parent_theme_label);
	layout->addWidget(m_parent_theme_combobox);
	layout->addStretch();
	layout->addWidget(m_create_button);
	layout->setAlignment(m_create_button, Qt::AlignRight);
	layout->setContentsMargins(15, 20, 7, 7);
	setLayout(layout);
}
