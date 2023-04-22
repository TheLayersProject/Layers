#include "ThemeEditor.h"

#include "Application.h"
#include "WidgetEditor.h"

#include <QResizeEvent>

using Layers::Button;
using Layers::Graphic;
using Layers::ThemeEditor;
using Layers::Widget;
using Layers::WidgetEditor;

ThemeEditor::ThemeEditor(QWidget* parent) :
	Menu("Theme Editor", new Graphic(":/svgs/customize_theme.svg", QSize(24, 24)), parent)
{
	installEventFilter(this);
	setMouseTracking(true);

	set_name("theme_editor");
	set_proper_name("Theme Editor");

	m_topbar->setFixedHeight(45);
	m_topbar->setMouseTracking(true);
	m_topbar->set_name("topbar");
	m_topbar->set_proper_name("Topbar");
	m_topbar->fill()->set_value(QColor(Qt::lightGray));
	m_topbar->corner_radii()->top_right()->set_value(10.0);
	m_topbar->corner_radii()->bottom_right()->set_value(10.0);

	m_apply_button->disable_text_hover_color();
	m_apply_button->set_margin(0, 7, 0, 7);
	m_apply_button->set_name("apply_button");
	m_apply_button->set_proper_name("Apply Button");
	m_apply_button->set_text_padding(3, 5, 0, 0);

	connect(m_apply_button, &Button::clicked, [this] {
		// TODO:
		if (m_preview_widget && !m_functionality_disabled)
		{
			if (Themeable* preview_themeable = dynamic_cast<Themeable*>(m_preview_widget))
			{
				preview_themeable->copy_attribute_values_to(
					layersApp->current_theme());

				layersApp->reapply_theme();
				layersApp->save_theme(*layersApp->current_theme());
			}
		}
	});

	m_sidebar->set_name("sidebar");
	m_sidebar->set_proper_name("Sidebar");
	//m_sidebar->fill()->set_value(QColor(Qt::lightGray));

	m_preview_frame->corner_color()->entangle_with(*m_sidebar->fill());

	m_preview_frame->corner_radii()->top_left()->set_value(10.0);
	m_preview_frame->corner_color()->set_disabled(false);

	m_preview_scroll_area->set_name("preview_scroll_area");
	m_preview_scroll_area->set_proper_name("Preview Scroll Area");
	//m_preview_scroll_area->fill()->set_disabled();

	init_layout();
}

//ThemeEditor::~ThemeEditor()
//{
//	delete m_collapse_menu;
//
//	m_collapse_menu = nullptr;
//}

Button* ThemeEditor::apply_button() const
{
	return m_apply_button;
}

void ThemeEditor::apply_theme(Theme& theme)
{
	Themeable::apply_theme(theme);

	//for (WidgetEditor* widget_editor : m_panel_stack)
	//	widget_editor->apply_theme(theme);

	if (m_preview_widget)
	{
		if (Themeable* themeable_preview_widget =
			dynamic_cast<Themeable*>(m_preview_widget))
		{
			themeable_preview_widget->apply_theme(theme);
		}
	}
}

void ThemeEditor::edit_themeable(Themeable* themeable)
{
	if (m_open_themeables.count() == 1 && themeable != layersApp)
	{
		themeable = themeable->clone();

		if (QWidget* cloned_widget = dynamic_cast<QWidget*>(themeable))
			set_preview_widget(cloned_widget);
	}
	
	WidgetEditor* widget_editor = new WidgetEditor(themeable);

	if (m_sidebar->widget())
		m_sidebar->takeWidget()->deleteLater();

	m_sidebar->setWidget(widget_editor);
	m_sidebar->setFixedWidth(widget_editor->width());

	QStringList widget_editor_prefixes = m_sidebar->tag_prefixes();
	widget_editor_prefixes.append(*m_sidebar->name());
	widget_editor->assign_tag_prefixes(widget_editor_prefixes);
	widget_editor->apply_theme(*layersApp->current_theme());

	if (!m_open_themeables.contains(themeable))
	{
		m_open_themeables.append(themeable);

		Button* text_button = m_navigator->create_text_button(*themeable->proper_name());

		connect(text_button, &Button::clicked, [this, themeable] {
			while (themeable != m_open_themeables.last())
				m_open_themeables.takeLast();

			edit_themeable(themeable);
			});

		//if (m_topbar->width() < topbar_content_width(true))
		//	collapse_text_buttons();
	}

	if (m_open_themeables.size() == 1 && m_preview_widget)
	{
		m_preview_widget->deleteLater();
		m_preview_widget = nullptr;
	}
}

QWidget* ThemeEditor::preview_widget() const
{
	return m_preview_widget;
}

void ThemeEditor::set_preview_widget(QWidget* widget)
{
	if (m_preview_widget)
		m_preview_widget->deleteLater();

	if (Themeable* preview_themeable = dynamic_cast<Themeable*>(widget))
		preview_themeable->set_functionality_disabled();

	m_preview_widget = widget;
	m_preview_layout->addWidget(widget);
}

bool ThemeEditor::eventFilter(QObject* object, QEvent* event)
{
	if (object == this && event->type() == QEvent::Resize)
	{
		if (m_sidebar->widget())
		{
			if (height() < m_sidebar->widget()->height())
				m_sidebar->setFixedWidth(m_sidebar->widget()->width() + 45); // 45 is scrollbar width
			else
				m_sidebar->setFixedWidth(m_sidebar->widget()->width());
		}
	}

	return false;
}

void ThemeEditor::init_layout()
{
	// Topbar
	m_topbar_layout->setContentsMargins(8, 0, 8, 0);
	m_topbar_layout->setSpacing(10);
	m_topbar_layout->addWidget(m_navigator);
	m_topbar_layout->addWidget(m_apply_button);
	m_topbar->setLayout(m_topbar_layout);

	// Preview Widget and Layout

	m_preview_layout->setContentsMargins(32, 32, 32, 32);
	m_preview_layout->setSpacing(0);

	m_preview_frame->fill()->set_disabled();
	m_preview_frame->setLayout(m_preview_layout);

	m_preview_scroll_area->setWidget(m_preview_frame);

	// Right Vbox
	QVBoxLayout* right_vbox = new QVBoxLayout;
	right_vbox->setContentsMargins(0, 0, 0, 0);
	right_vbox->setSpacing(0);
	right_vbox->addWidget(m_topbar);
	right_vbox->addWidget(m_preview_scroll_area);

	// Main Layout
	m_main_layout->setContentsMargins(0, 0, 0, 0);
	m_main_layout->setSpacing(0);
	m_main_layout->addWidget(m_sidebar);
	m_main_layout->addLayout(right_vbox);
	setLayout(m_main_layout);
}
