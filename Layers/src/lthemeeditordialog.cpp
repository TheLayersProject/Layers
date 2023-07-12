#include <Layers/lthemeeditordialog.h>

#include <Layers/lapplication.h>

using Layers::LThemeable;
//using Layers::LThemeableTreeView2;
using Layers::LThemeEditorDialog;

LThemeEditorDialog::LThemeEditorDialog(QWidget* parent) :
	LDialog("Theme Editor", parent)
{
	init_layout();
	m_attr_editors_widget->installEventFilter(this);
	setFixedSize(800, 600);
	set_icon(LGraphic(":/images/customize_theme.svg", QSize(24, 24)));
	set_name("Theme Editor Dialog");

	m_tag_label->setFixedHeight(40);
	//m_topbar->setMouseTracking(true);
	//m_topbar->set_name("Topbar");

	m_control_attr_editor->set_name("Attribute Editors");
	m_control_attr_editor->hide();

	m_control_attr_editor_group->set_name("Group Editors");
	m_control_attr_editor_group->hide();

	m_themeable_tree_view->setFixedWidth(298);

	connect(
		m_themeable_tree_view, SIGNAL(selection_changed(LThemeable*)),
		this, SLOT(edit_themeable(LThemeable*)));

	m_divider->setFixedWidth(4);

	m_attr_editors_widget->setSizePolicy(
		QSizePolicy::Minimum, QSizePolicy::Minimum);

	m_attr_editors_scroll_area->setHorizontalScrollBarPolicy(
		Qt::ScrollBarAlwaysOff);
	m_attr_editors_scroll_area->setWidget(m_attr_editors_widget);

	assign_tag_prefixes();
}

void LThemeEditorDialog::init_root_themeable()
{
	m_themeable_tree_view->set_root_themeable(layersApp);

	m_is_root_themeable_set = true;
}

bool LThemeEditorDialog::is_root_themeable_set() const
{
	return m_is_root_themeable_set;
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

void LThemeEditorDialog::edit_themeable(LThemeable* themeable)
{
	clear_attr_editors();

	QMap<QString, QWidget*> organized_widgets;
	QMap<QString, LAttributeEditorGroup*> attr_editor_groups;

	for (const QString& group_name : themeable->attribute_group_names())
	{
		LAttributeEditorGroup* attr_editor_group =
			new LAttributeEditorGroup(group_name);

		attr_editor_group->entangle_with(m_control_attr_editor_group);
		attr_editor_groups[group_name] = attr_editor_group;
		organized_widgets[group_name] = attr_editor_group;
	}

	for (LAttribute* attr : themeable->child_attributes())
	{
		LAttributeEditor* attr_editor = new LAttributeEditor(attr);
		attr_editor->entangle_with(m_control_attr_editor);

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

	m_tag_label->setText(themeable->tag());
}

void LThemeEditorDialog::init_layout()
{
	QVBoxLayout* right_vbox = new QVBoxLayout;
	right_vbox->addWidget(m_tag_label);
	right_vbox->addWidget(m_attr_editors_scroll_area);

	m_attr_editors_layout->addStretch();
	m_attr_editors_widget->setLayout(m_attr_editors_layout);

	m_main_layout->addWidget(m_themeable_tree_view);
	m_main_layout->addWidget(m_divider);
	m_main_layout->addLayout(right_vbox);
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
