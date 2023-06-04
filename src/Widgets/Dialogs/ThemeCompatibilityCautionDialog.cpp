#include "ThemeCompatibilityCautionDialog.h"

#include "Application.h"
#include "ThemeCompatibilityItemDelegate.h"

#include <QHeaderView>
#include <QSizePolicy>

using Layers::Themeable;
using Layers::ThemeCompatibilityCautionDialog;

ThemeCompatibilityCautionDialog::ThemeCompatibilityCautionDialog(QWidget* parent) :
	Dialog("Theme Compatibility Caution", parent)
{
	init_attributes();
	init_layout();

	setAttribute(Qt::WA_ShowWithoutActivating);
	setFixedWidth(520);
	setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
	setWindowFlags(windowFlags() | Qt::Tool | Qt::WindowStaysOnTopHint);
	set_icon(Graphic(":/images/caution.png"));
	set_name("Theme Compatibility Caution Dialog");

	m_message_label->set_font_size(14);
	m_message_label->set_name("Message Label");
	m_message_label->setText(
		layersApp->name() + " has not been implemented in this theme. An "
		"implementation will be inherited from the last compatible ancestor "
		"theme.");
	m_message_label->setWordWrap(true);

	m_table_label->set_font_size(14);
	m_table_label->set_name("Table Label");
	m_table_label->setText("Lineage");

	init_lineage_table();

	// Assign tag prefixes last!
	assign_tag_prefixes();

	// Set theme
	apply_theme(*layersApp->active_theme());
}

Themeable* ThemeCompatibilityCautionDialog::clone()
{
	ThemeCompatibilityCautionDialog* dialog = new ThemeCompatibilityCautionDialog;

	dialog->set_lineage_table_data({
		"Dark",
		"Second Theme"
		});

	return dialog;
}

void ThemeCompatibilityCautionDialog::set_lineage_table_data(
	const QStringList& lineage_list)
{
	QList<ThemeLineageData> lineage_table_data;

	for (const QString& theme_id : lineage_list)
	{
		ThemeLineageData lineage_data;

		if (theme_id.contains("_"))
		{
			lineage_data.name = theme_id.left(theme_id.lastIndexOf("_"));
			lineage_data.uuid =
				theme_id.right(theme_id.size() - 1 - theme_id.lastIndexOf("_"));
		}
		else
			lineage_data.name = theme_id;

		if (Theme* theme = layersApp->theme(lineage_data.name))
			lineage_data.has_app_implementation_available =
				theme->has_app_implementation();

		lineage_table_data.append(lineage_data);
	}

	m_theme_lineage_model.clear();

	for (const ThemeLineageData& lineage_data : lineage_table_data)
		m_theme_lineage_model.append(lineage_data);

	m_lineage_table->verticalHeader()->resizeSection(
		m_lineage_table->verticalHeader()->count() - 1, 40);

	m_lineage_table->update_height();
}

void ThemeCompatibilityCautionDialog::set_theme_name(const QString& theme_name)
{
	m_table_label->setText(theme_name + "'s Lineage");
}

void ThemeCompatibilityCautionDialog::init_attributes()
{
	m_border->thickness()->set_value(3.0);

	m_corner_radii->top_left()->set_value(10.0);
	m_corner_radii->top_right()->set_value(10.0);
	m_corner_radii->bottom_left()->set_value(10.0);
	m_corner_radii->bottom_right()->set_value(10.0);
}

void ThemeCompatibilityCautionDialog::init_layout()
{
	QVBoxLayout* layout = new QVBoxLayout;

	layout->addWidget(m_message_label);
	layout->addSpacing(15);
	layout->addWidget(m_table_label);
	layout->addWidget(m_lineage_table);
	layout->setAlignment(m_table_label, Qt::AlignHCenter);
	layout->setContentsMargins(12, 12, 12, 12);
	layout->setSpacing(5);

	setLayout(layout);
}

void ThemeCompatibilityCautionDialog::init_lineage_table()
{
	ThemeCompatibilityItemDelegate* item_delegate =
		new ThemeCompatibilityItemDelegate;

	m_lineage_table->setItemDelegate(item_delegate);

	m_lineage_table->set_name("Theme Lineage Table");
	m_lineage_table->setModel(&m_theme_lineage_model);

	// Set 'Theme' column to fized size:
	m_lineage_table->horizontalHeader()->resizeSection(0, 370);
}
