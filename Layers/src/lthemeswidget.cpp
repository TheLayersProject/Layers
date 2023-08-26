#include "lthemeswidget.h"

#include <Layers/lapplication.h>
#include <Layers/lthemeeditordialog.h>

using Layers::LButton;
using Layers::LTheme;
using Layers::LThemeComboBox;
using Layers::LThemesWidget;

LThemesWidget::LThemesWidget(QWidget* parent) : LWidget(parent)
{
	setObjectName("Themes Widget");

	m_theme_label->setObjectName("Theme Label");
	m_theme_label->set_font_size(15);

	m_theme_combobox->setObjectName("Theme Combobox");

	for (LTheme* theme : layersApp->themes())
		m_theme_combobox->addItem(theme);

	for (int i = 0; i < m_theme_combobox->count(); i++)
		if (m_theme_combobox->itemData(i).value<LTheme*>() == activeTheme())
		{
			m_theme_combobox->setCurrentIndex(i);
			break;
		}

	connect(layersApp, &LApplication::theme_added,
		[this](LTheme* theme)
		{
			m_theme_combobox->addItem(theme, true);
		});

	connect(m_theme_combobox, &LThemeComboBox::currentIndexChanged, [this]
	{
		layersApp->apply_theme(
			m_theme_combobox->currentData().value<LTheme*>());
	});

	m_theme_buttons_handler_connection =
		connect(layersApp, &LApplication::active_theme_changed, [this]
			{
				handle_theme_buttons_visibility();
			});

	if (!activeTheme()->editable())
		show_custom_theme_buttons(false);

	m_new_theme_button->setObjectName("New Theme Button");

	m_customize_theme_button->setObjectName("Customize Theme Button");

	connect(m_customize_theme_button, &LButton::clicked,
		[this]
		{
			if (!m_theme_editor_dialog)
			{
				m_theme_editor_dialog = new LThemeEditorDialog;

				center(m_theme_editor_dialog, window());

				m_theme_editor_dialog->apply_theme_item(
					activeTheme()->find_item(
						m_theme_editor_dialog->path()));

				connect(m_theme_editor_dialog, &QDialog::finished,
					[this]
					{
						m_theme_editor_dialog->deleteLater();
						m_theme_editor_dialog = nullptr;
					});
			}

			m_theme_editor_dialog->show();
			m_theme_editor_dialog->raise();
		});

	m_delete_theme_button->setObjectName("Delete Theme Button");

	m_theme_info_button->setObjectName("Theme Info Button");

	m_separator_1->setObjectName("Separators");
	m_separator_1->setFixedSize(1, 30);

	m_separator_2->setObjectName("Separators");
	m_separator_2->setFixedSize(1, 30);

	m_spacer_1->setFixedWidth(12);
	m_spacer_1->fill()->set_link_attribute(this->fill());

	m_spacer_2->setFixedWidth(12);
	m_spacer_2->fill()->set_link_attribute(this->fill());

	init_layout();
}

LThemesWidget::~LThemesWidget()
{
	QObject::disconnect(m_theme_buttons_handler_connection);
}

void LThemesWidget::handle_theme_buttons_visibility()
{
	if (activeTheme()->editable())
		show_custom_theme_buttons();
	else
		show_custom_theme_buttons(false);
}

LButton* LThemesWidget::customize_theme_button() const
{
	return m_customize_theme_button;
}

LButton* LThemesWidget::new_theme_button() const
{
	return m_new_theme_button;
}

LThemeComboBox* LThemesWidget::theme_combobox() const
{
	return m_theme_combobox;
}

void LThemesWidget::show_custom_theme_buttons(bool cond)
{
	if (cond)
	{
		m_customize_theme_button->show();
		m_delete_theme_button->show();
		m_separator_2->show();
		m_spacer_1->show();
		m_spacer_2->show();
	}
	else
	{
		m_customize_theme_button->hide();
		m_delete_theme_button->hide();
		m_separator_2->hide();
		m_spacer_1->hide();
		m_spacer_2->hide();
	}
}

void LThemesWidget::init_layout()
{
	QHBoxLayout* theme_buttons_hbox = new QHBoxLayout;

	theme_buttons_hbox->setContentsMargins(0, 5, 0, 0);
	theme_buttons_hbox->setSpacing(0);
	theme_buttons_hbox->addWidget(m_new_theme_button);
	theme_buttons_hbox->addSpacing(12);
	theme_buttons_hbox->addWidget(m_separator_1);
	theme_buttons_hbox->addSpacing(12);
	theme_buttons_hbox->addWidget(m_customize_theme_button);
	theme_buttons_hbox->addWidget(m_delete_theme_button);
	theme_buttons_hbox->addWidget(m_spacer_1);
	theme_buttons_hbox->addWidget(m_separator_2);
	theme_buttons_hbox->addWidget(m_spacer_2);
	theme_buttons_hbox->addWidget(m_theme_info_button);
	theme_buttons_hbox->addStretch();

	QVBoxLayout* main_layout = new QVBoxLayout;

	main_layout->setContentsMargins(32, 32, 0, 0);
	main_layout->addWidget(m_theme_label);
	main_layout->addWidget(m_theme_combobox);
	main_layout->addLayout(theme_buttons_hbox);
	main_layout->addStretch();

	setLayout(main_layout);

	main_layout->activate();
}
