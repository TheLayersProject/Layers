#include "lnewlinkwidget.h"

using Layers::LNewLinkWidget;

LNewLinkWidget::LNewLinkWidget(LAttribute* attr, QWidget* parent) :
	m_attr{ attr },
	LWidget(parent)
{
	init_layout();
	setObjectName("New Link Widget");
	setFixedHeight(357);

	connect(m_theme_view, &LThemeView::selected_theme_item_changed,
		[this](LThemeItem* theme_item)
		{
			QStringList filter_paths = { m_attr->path() };
			for (LAttribute* dependent_attr : m_attr->dependent_attributes(true))
				filter_paths.append(dependent_attr->path());

			m_attr_map_view->set_attributes(
				theme_item->attributes(m_attr->typeName()), filter_paths);

			m_selected_link_attr = nullptr;

			m_path_editor->set_text(theme_item->path() + "/");
			m_apply_link_button->set_disabled();
		});

	connect(m_attr_map_view, &LAttributeMapView::selection_changed,
		[this](LAttribute* attr)
		{
			m_selected_link_attr = attr;

			m_path_editor->set_text(attr->path());
			m_apply_link_button->set_disabled(false);
		});

	m_splitter->addWidget(m_theme_view);
	m_splitter->addWidget(m_attr_map_view);

	m_path_editor->setObjectName("Path Editor");
	m_path_editor->set_font_size_f(10.5);
	m_path_editor->setFixedHeight(30);
	m_path_editor->setSizePolicy(
		QSizePolicy::Minimum, QSizePolicy::Fixed);

	connect(m_path_editor, &LLineEditor::text_edited,
		[this](const QString& text)
		{
			m_apply_link_button->set_disabled();
		});

	m_apply_link_button->setObjectName("Apply Link Button");
	m_apply_link_button->set_font_size_f(10.5);
	m_apply_link_button->set_padding(6);
	m_apply_link_button->setFixedHeight(30);
	m_apply_link_button->setSizePolicy(
		QSizePolicy::Maximum, QSizePolicy::Fixed);
	m_apply_link_button->set_disabled();

	connect(m_apply_link_button, &LButton::clicked,
		[this]
		{
			m_attr->set_link_path(m_path_editor->text()->as<QString>());
			m_attr->set_link_attribute(m_selected_link_attr);

			deleteLater();
		});

	m_cancel_button->setObjectName("Cancel Button");
	m_cancel_button->set_font_size_f(10.5);
	m_cancel_button->set_padding(6);
	m_cancel_button->setFixedHeight(30);
	m_cancel_button->setSizePolicy(
		QSizePolicy::Maximum, QSizePolicy::Fixed);

	connect(m_cancel_button, &LButton::clicked,
		[this] { deleteLater(); });

	m_resizer->set_widget(this, 180, 1000);
}

void LNewLinkWidget::init_layout()
{
	QHBoxLayout* m_controls_layout = new QHBoxLayout;
	m_controls_layout->addWidget(m_path_editor);
	m_controls_layout->addWidget(m_apply_link_button);
	m_controls_layout->addWidget(m_cancel_button);
	m_controls_layout->setContentsMargins(0, 5, 0, 5);
	m_controls_layout->setSpacing(5);

	m_main_layout->addWidget(m_splitter);
	m_main_layout->addLayout(m_controls_layout);
	m_main_layout->addWidget(m_resizer);
	m_main_layout->setContentsMargins(5, 5, 5, 0);
	m_main_layout->setSpacing(0);

	setLayout(m_main_layout);
}
