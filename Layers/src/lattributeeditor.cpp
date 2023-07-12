#include <Layers/lattributeeditor.h>

#include <QIntValidator>

using Layers::LAttributeEditor;
using Layers::LThemeable;

LAttributeEditor::LAttributeEditor(LAttribute* attr, QWidget* parent) :
	m_attr{ attr },
	LWidget(parent)
{
	init_attributes();
	init_layout();
	setMinimumHeight(40);
	setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);

	m_fill_control->set_name("Fill Control");

	QIntValidator* int_validator = new QIntValidator(0, 30);

	control_icon_label->hide();
	control_icon_label->set_name("Icon Labels");

	m_label->set_name("Label");
	m_label->set_font_size(12);

	m_line_editor->set_name("Line Editor");
	m_line_editor->set_default_value("0");
	m_line_editor->set_font_size(13);
	m_line_editor->set_validator(int_validator);

	m_slider->set_name("Slider");
	m_slider->set_limit(int_validator->top());

	m_icons_widget->set_name("Icons Widget");
	m_icons_widget->setFixedHeight(26);

	m_collapse_button->set_name("Collapse Button");

	connect(m_collapse_button, &LButton::clicked, [this]
		{
			if (m_features_widget->isVisible())
				m_features_widget->hide();
			else
				m_features_widget->show();
		});

	m_features_widget->hide();

	m_features_tab_bar->set_name("Features Tab Bar");
	m_features_tab_bar->setFixedHeight(40);
	m_features_tab_bar->add_tab(
		LGraphic(":/images/chain_link.svg", QSize(11, 24)), "Links");
	m_features_tab_bar->set_current_index(0);

	LTab* links_tab = m_features_tab_bar->tabs().last();
	links_tab->text_label()->set_font_size(10.5);
	links_tab->icon_label()->setFixedWidth(11);
	links_tab->close_button()->hide();
	links_tab->layout()->setContentsMargins(8, 0, 8, 0);
	links_tab->layout()->setSpacing(7);

	m_links_widget->set_name("Links Widget");
	//m_links_widget->setFixedHeight(80);

	if (attr)
	{
		if (attr->name().contains("."))
			m_label->setText(attr->name().split(".").last());
		else
			m_label->setText(attr->name());

		if (
			QString(attr->typeName()) == "QColor" ||
			QString(attr->typeName()) == "QList<std::pair<double,QColor>>"
			)
		{
			m_fill_control->set_attribute(attr);

			m_line_editor->hide();
			m_slider->hide();
		}
		else if (QString(attr->typeName()) == "double")
		{
			m_line_editor->set_text(attr->as<QString>());
			m_line_editor->text()->set_uplink_attribute(attr);

			m_slider->value().set_uplink_attribute(m_line_editor->text());

			m_fill_control->hide();
		}

		QString parent_tag;

		if (attr->parent())
			if (LThemeable* parent_themeable = dynamic_cast<LThemeable*>(attr->parent()))
				parent_tag = parent_themeable->tag();

		if (attr->uplink_attribute())
		{
			LLabel* link_icon_label =
				new LLabel(LGraphic(":/images/chain_link.svg", QSize(8, 18)));
			link_icon_label->entangle_with(control_icon_label);
			link_icon_label->setAlignment(Qt::AlignCenter);
			link_icon_label->setFixedSize(20, 26);
			m_icons_layout->addWidget(link_icon_label);

			LAttribute* uplink_attr = attr->uplink_attribute();

			while (uplink_attr)
			{
				QString label_text = uplink_attr->tag();

				if (!parent_tag.isEmpty())
					if (label_text.startsWith(parent_tag))
						label_text.replace(parent_tag, "This");

				LLabel* attr_tag_label = new LLabel(label_text);
				attr_tag_label->set_font_size(10.5);
				attr_tag_label->text_color()->set_value(QColor(Qt::white));
				m_links_layout->insertWidget(0, attr_tag_label);

				uplink_attr = uplink_attr->uplink_attribute();
			}
		}

		if (attr->has_overrides())
		{
			LLabel* overrides_icon_label =
				new LLabel(LGraphic(":/images/overrides_icon.svg", QSize(10, 18)));
			overrides_icon_label->entangle_with(control_icon_label);
			overrides_icon_label->setAlignment(Qt::AlignCenter);
			overrides_icon_label->setFixedSize(20, 26);
			m_icons_layout->addWidget(overrides_icon_label);
		}

		QString label_text = attr->tag();

		if (!parent_tag.isEmpty())
			if (label_text.startsWith(parent_tag))
				label_text.replace(parent_tag, "This");

		LLabel* attr_tag_label = new LLabel(label_text);
		attr_tag_label->set_font_size(10.5);
		QFont label_font = attr_tag_label->font();
		label_font.setBold(true);
		attr_tag_label->setFont(label_font);
		attr_tag_label->text_color()->set_value(QColor(Qt::white));
		m_links_layout->addWidget(attr_tag_label);

		// Downlinks

		LAttributeList downlink_attrs = attr->downlink_attributes();

		for (LAttribute* downlink_attr : downlink_attrs)
		{
			QString downlink_attr_tag = downlink_attr->tag();

			if (!parent_tag.isEmpty())
				if (downlink_attr_tag.startsWith(parent_tag))
					downlink_attr_tag.replace(parent_tag, "This");

			LLabel* attr_tag_label = new LLabel(downlink_attr_tag);
			attr_tag_label->set_font_size(10.5);
			attr_tag_label->text_color()->set_value(QColor(Qt::white));
			m_links_layout->addWidget(attr_tag_label);
		}
	}
	else
	{
		m_fill_control->hide();
		m_line_editor->hide();
		m_slider->hide();
	}
}

QList<LThemeable*> LAttributeEditor::child_themeables(Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables = LThemeable::child_themeables(options);

	child_themeables.append(m_features_tab_bar);
	child_themeables.append(m_links_widget);

	return child_themeables;
}

void LAttributeEditor::init_attributes()
{
	m_fill->set_value(QColor("#1e2023"));
	m_corner_radii_top_left->set_value(10.0);
	m_corner_radii_top_right->set_value(10.0);
	m_corner_radii_bottom_left->set_value(10.0);
	m_corner_radii_bottom_right->set_value(10.0);

	m_label->text_color()->set_value(QColor(Qt::white));
}

void LAttributeEditor::init_layout()
{
	m_controls_layout->addWidget(m_fill_control);
	m_controls_layout->addWidget(m_line_editor);
	m_controls_layout->addWidget(m_slider);
	m_controls_layout->setContentsMargins(0, 0, 0, 0);

	m_icons_layout->setContentsMargins(0, 0, 0, 0);
	m_icons_layout->setSpacing(0);
	m_icons_widget->setLayout(m_icons_layout);

	QHBoxLayout* top_layout = new QHBoxLayout;
	top_layout->addWidget(m_label);
	top_layout->addLayout(m_controls_layout);
	top_layout->addStretch();
	top_layout->addWidget(m_icons_widget);
	top_layout->addWidget(m_collapse_button);
	top_layout->setContentsMargins(9, 0, 0, 0);

	QHBoxLayout* tab_layout = new QHBoxLayout;
	tab_layout->addWidget(m_features_tab_bar);
	tab_layout->addStretch();
	tab_layout->setContentsMargins(0, 0, 0, 0);

	m_links_layout->setContentsMargins(5, 5, 5, 5);
	m_links_widget->setLayout(m_links_layout);

	QVBoxLayout* attr_features_layout = new QVBoxLayout;
	attr_features_layout->addLayout(tab_layout);
	attr_features_layout->addWidget(m_links_widget);
	attr_features_layout->setContentsMargins(5, 5, 5, 5);
	attr_features_layout->setSpacing(0);
	m_features_widget->setLayout(attr_features_layout);

	QVBoxLayout* main_layout = new QVBoxLayout;
	main_layout->addLayout(top_layout);
	main_layout->addWidget(m_features_widget);
	main_layout->setContentsMargins(0, 0, 0, 0);
	setLayout(main_layout);
}
