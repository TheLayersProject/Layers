#include "lthemeswidget.h"

#include "Layers/lapplication.h"

using Layers::LButton;
using Layers::LTheme;
using Layers::LThemeComboBox;
using Layers::LThemesWidget;

LThemesWidget::LThemesWidget(QWidget* parent) : LWidget(parent)
{
	set_icon(LGraphic(":/images/panel_icon.svg", QSize(20, 20)));
	set_name("Themes Widget");

	m_theme_label->set_name("Theme Label");
	m_theme_label->set_font_size(15);

	m_theme_combobox->set_icon(LGraphic(":/images/combobox_icon.svg", QSize(21, 18)));
	m_theme_combobox->set_name("Theme Combobox");

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

	m_new_theme_button->set_name("New Theme Button");

	m_customize_theme_button->set_name("Customize Theme Button");

	m_delete_theme_button->set_name("Delete Theme Button");

	m_theme_info_button->set_name("Theme Info Button");

	m_separator_1->set_name("Separators");
	m_separator_1->setFixedSize(1, 30);

	m_separator_2->set_name("Separators");
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
