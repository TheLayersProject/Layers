#include <Layers/lthemeeditordialog.h>

#include <Layers/lapplication.h>

using Layers::LThemeable;
using Layers::LThemeEditorDialog;

LThemeEditorDialog::LThemeEditorDialog(QWidget* parent) :
	LDialog("Theme Editor", parent)
{
	init_layout();
	m_attr_editors_widget->installEventFilter(this);
	resize(800, 600);
	set_icon(LGraphic(":/images/customize_theme.svg", QSize(24, 24)));
	set_name("Theme Editor Dialog");;

	m_path_label->set_name("Path Label");
	m_path_label->setFixedHeight(40);

	m_theme_view->set_name("Theme View");
	m_theme_view->setFixedWidth(298);

	connect(
		m_theme_view, SIGNAL(selection_changed(LThemeItem*)),
		this, SLOT(edit_theme_item(LThemeItem*)));

	m_divider->set_name("Divider");
	m_divider->setFixedWidth(4);

	m_attr_editors_widget->setSizePolicy(
		QSizePolicy::Minimum, QSizePolicy::Minimum);

	m_attr_editors_scroll_area->set_name("Attribute Editors Scroll Area");
	m_attr_editors_scroll_area->setHorizontalScrollBarPolicy(
		Qt::ScrollBarAlwaysOff);
	m_attr_editors_scroll_area->setWidget(m_attr_editors_widget);

	connect(m_save_progress_indicator, &LGrowingDotProgressIndicator::timeout,
		[this]
	{
		activeTheme()->save();

		m_save_progress_indicator->hide();

		m_check_label->show();
		m_status_label->show();
	});

	m_status_bar->setFixedHeight(40);
	m_status_bar->set_name("Status Bar");

	m_check_label->set_name("Check Label");
	m_check_label->hide();

	m_status_label->set_name("Status Label");
	m_status_label->hide();

	m_save_progress_indicator->set_name("Save Progress Indicator");
	m_save_progress_indicator->hide();
}

void LThemeEditorDialog::apply_theme(LThemeItem* theme_item)
{
	clear_attr_editors();
	m_check_label->hide();
	m_status_label->hide();
	m_path_text = "";
	update_path_label();

	LThemeable::apply_theme(theme_item);
}

bool LThemeEditorDialog::eventFilter(QObject* object, QEvent* event)
{
	if (event->type() == QEvent::Resize)
	{
		update_attr_editors_max_width();
		return true;
	}

	return LDialog::eventFilter(object, event);
}

void LThemeEditorDialog::edit_theme_item(LThemeItem* theme_item)
{
	clear_attr_editors();

	QMap<QString, QWidget*> organized_widgets;
	QMap<QString, LAttributeEditorGroup*> attr_editor_groups;

	for (const QString& group_name : theme_item->attribute_group_names())
	{
		LAttributeEditorGroup* attr_editor_group =
			new LAttributeEditorGroup(group_name);
		attr_editor_group->set_name("Attribute Editor Groups");

		if (m_current_theme_item)
			attr_editor_group->apply_theme(
				m_current_theme_item->find_item({ "Attribute Editor Groups" }));

		attr_editor_groups[group_name] = attr_editor_group;
		organized_widgets[group_name] = attr_editor_group;
	}

	for (LAttribute* attr : theme_item->attributes())
	{
		LAttributeEditor* attr_editor = new LAttributeEditor(attr);
		attr_editor->set_name("Attribute Editors");

		if (m_current_theme_item)
			attr_editor->apply_theme(
				m_current_theme_item->find_item({ "Attribute Editors" }));

		connect(attr_editor->fill_control()->fill(), &LAttribute::changed,
			this, &LThemeEditorDialog::reset_save_timer);

		connect(&attr_editor->slider()->value(), &LAttribute::changed,
			this, &LThemeEditorDialog::reset_save_timer);

		if (attr->name().contains("."))
		{
			QString group_name = attr->name().split(".").first();

			attr_editor_groups[group_name]->add_attribute_editor(attr_editor);
		}
		else
			organized_widgets[attr->name()] = attr_editor;
	}

	for (QWidget* widget : organized_widgets)
	{
		widget->setMaximumWidth(m_attr_editors_scroll_area->width());

		m_attr_editors_layout->insertWidget(
			m_attr_editors_layout->count() - 1, widget);
	}

	update_attr_editors_max_width();

	m_path_text = theme_item->path();
	update_path_label();
}

void LThemeEditorDialog::reset_save_timer()
{
	m_check_label->hide();
	m_status_label->hide();

	m_save_progress_indicator->show();

	m_save_progress_indicator->start(3000);
}

void LThemeEditorDialog::init_layout()
{
	QHBoxLayout* path_label_layout = new QHBoxLayout;
	path_label_layout->addWidget(m_path_label);
	path_label_layout->setSpacing(0);
	path_label_layout->setContentsMargins(8, 0, 8, 0);

	QVBoxLayout* right_vbox = new QVBoxLayout;
	right_vbox->addLayout(path_label_layout);
	right_vbox->addWidget(m_attr_editors_scroll_area);

	m_attr_editors_layout->addStretch();
	m_attr_editors_widget->setLayout(m_attr_editors_layout);

	m_hbox_layout->addWidget(m_theme_view);
	m_hbox_layout->addWidget(m_divider);
	m_hbox_layout->addLayout(right_vbox);
	m_hbox_layout->setContentsMargins(0, 0, 0, 0);
	m_hbox_layout->setSpacing(0);

	m_status_bar_layout->addWidget(m_save_progress_indicator);
	m_status_bar_layout->addWidget(m_check_label);
	m_status_bar_layout->addWidget(m_status_label);
	m_status_bar_layout->addStretch();
	m_status_bar_layout->setContentsMargins(8, 0, 8, 0);
	m_status_bar_layout->setSpacing(8);
	m_status_bar->setLayout(m_status_bar_layout);

	m_main_layout->addLayout(m_hbox_layout);
	m_main_layout->addWidget(m_status_bar);
	m_main_layout->setContentsMargins(0, 0, 0, 0);
	m_main_layout->setSpacing(0);

	setLayout(m_main_layout);
	m_main_layout->activate();
}

void LThemeEditorDialog::clear_attr_editors()
{
	for (QObject* child_object : m_attr_editors_widget->children())
		if (QWidget* child_widget = dynamic_cast<QWidget*>(child_object))
			child_widget->deleteLater();
}

void LThemeEditorDialog::update_attr_editors_max_width()
{
	QMargins margins = m_attr_editors_layout->contentsMargins();

	int scroll_bar_width =
		(m_attr_editors_scroll_area->height() < m_attr_editors_widget->height()) ?
		m_attr_editors_scroll_area->verticalScrollBar()->width() : 0;

	for (QObject* child_object : m_attr_editors_widget->children())
		if (QWidget* child_widget = dynamic_cast<QWidget*>(child_object))
			child_widget->setMaximumWidth(
				m_attr_editors_scroll_area->width() -
				(margins.left() + margins.right() + scroll_bar_width)
			);
}

void LThemeEditorDialog::update_path_label()
{
	QFontMetrics font_metrics = QFontMetrics(m_path_label->font());

	m_path_label->setText(
		font_metrics.elidedText(
			m_path_text, Qt::ElideLeft, m_path_label->width()));
}
