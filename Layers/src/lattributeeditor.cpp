/*
 * Copyright (C) 2023 The Layers Project
 *
 * This file is part of Layers.
 *
 * Layers is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Layers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Layers. If not, see <https://www.gnu.org/licenses/>.
 */

#include <Layers/lattributeeditor.h>

#include <QIntValidator>
#include <QPainterPath>

#include <Layers/lalgorithms.h>
#include <Layers/lthemeitem.h>

#include "lnewlinkwidget.h"
#include "llinksview.h"

using Layers::LAttributeEditor;
using Layers::LFillControl;
using Layers::LLineEditor;
using Layers::LLinksView;
using Layers::LMiniSlider;
using Layers::LNewLinkWidget;
using Layers::LThemeable;

LAttributeEditor::LAttributeEditor(LAttribute* attr, QWidget* parent) :
	m_attr{ attr },
	m_links_view{ new LLinksView(attr) },
	LWidget(parent)
{
	init_attributes();
	init_layout();
	setMinimumHeight(40);
	setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);

	m_fill_control->setObjectName("Fill Control");

	QIntValidator* int_validator = new QIntValidator(0, 30);

	m_label->setObjectName("Label");
	m_label->set_font_size(12);

	m_line_editor->setObjectName("Line Editor");
	m_line_editor->set_default_value("0");
	m_line_editor->set_font_size(13);
	m_line_editor->set_validator(int_validator);
	m_line_editor->setFixedSize(40, 40);

	m_slider->setObjectName("Slider");
	m_slider->set_limit(int_validator->top());

	m_icons_widget->setObjectName("Icons Widget");
	m_icons_widget->setFixedHeight(26);

	m_link_icon_label->setObjectName("Icon Labels");
	m_link_icon_label->setAlignment(Qt::AlignCenter);
	m_link_icon_label->setFixedSize(20, 26);

	m_overrides_icon_label->setObjectName("Icon Labels");
	m_overrides_icon_label->setAlignment(Qt::AlignCenter);
	m_overrides_icon_label->setFixedSize(20, 26);

	update_icon_labels();

	m_attr_link_changed_connection = m_attr->on_link_change(
		[this] {
			update_icon_labels();

			if (m_attr->link_attribute())
			{
				m_break_link_button->show();
				m_new_link_button->hide();
			}
			else
			{
				m_break_link_button->hide();
				m_new_link_button->show();
			}
		}
	);

	m_collapse_button->setObjectName("Collapse Button");

	connect(m_collapse_button, &LButton::clicked, [this]
		{
			if (m_features_widget->isVisible())
				m_features_widget->hide();
			else
				m_features_widget->show();
		});

	m_features_widget->hide();

	m_features_tab_bar->setObjectName("Features Tab Bar");
	m_features_tab_bar->setFixedHeight(40);
	m_features_tab_bar->add_tab(
		LGraphic(":/images/chain_link.svg", QSize(11, 24)), "Links");
	m_features_tab_bar->set_current_index(0);

	connect(m_features_tab_bar, &LTabBar::index_changed, [this]
	{
		switch (m_features_tab_bar->current_index())
		{
		case 0:
			m_links_widget->show();
			m_overrides_widget->hide();
			break;
		case 1:
			m_links_widget->hide();
			m_overrides_widget->show();
			break;
		}
	});

	LTab* links_tab = m_features_tab_bar->tabs().last();
	links_tab->text_label()->set_font_size_f(10.5);
	links_tab->icon_label()->setFixedWidth(11);
	links_tab->close_button()->hide();
	links_tab->layout()->setContentsMargins(8, 0, 8, 0);
	links_tab->layout()->setSpacing(7);

	m_links_widget->setObjectName("Links Widget");

	m_status_states->set_state("Inactive");

	m_new_link_button->setObjectName("New Link Button");
	m_new_link_button->set_font_size_f(10.5);
	m_new_link_button->set_padding(6);
	m_new_link_button->setFixedHeight(30);
	m_new_link_button->add_state_pool(m_status_states);

	connect(m_new_link_button, &LButton::clicked,
		[this]
		{
			if (m_status_states->state() == "Inactive")
			{
				m_status_states->set_state("Active");

				m_new_link_widget = new LNewLinkWidget(m_attr);
				m_new_link_widget->apply_theme_item(
					current_theme_item()->find_item(
						"Links Widget/New Link Widget"));

				m_links_layout->insertWidget(1, m_new_link_widget);

				m_new_link_widget_destroyed_connection =
					connect(m_new_link_widget, &LNewLinkWidget::destroyed,
						[this] { m_status_states->set_state("Inactive"); });
			}
			else
			{
				m_new_link_widget->deleteLater();
			}
		});

	m_break_link_button->setObjectName("Break Link Button");
	m_break_link_button->set_font_size_f(10.5);
	m_break_link_button->set_padding(6);
	m_break_link_button->setFixedHeight(30);

	connect(m_break_link_button, &LButton::clicked, [this]
	{
		m_attr->break_link();
		m_break_link_button->hide();
		m_new_link_button->show();
	});

	m_overrides_widget->setObjectName("Overrides Widget");
	m_overrides_widget->hide();

	if (attr)
	{
		std::string attr_name = attr->object_name();

		if (std::find(attr_name.begin(), attr_name.end(),
			'.') != attr_name.end())
		{
			m_label->setText(QString::fromStdString(
				split<std::vector<std::string>>(
				attr_name, '.').back()));
		}
		else
			m_label->setText(QString::fromStdString(attr->object_name()));

		if (attr->type_index() == 3 || attr->type_index() == 4)
		{
			m_fill_control->set_attribute(attr);

			m_line_editor->hide();
			m_slider->hide();
		}
		else if (attr->type_index() == 1)
		{
			m_line_editor->set_text(QString::number(attr->as<double>()));
			m_line_editor->text()->set_link_attribute(attr);

			m_slider->value()->set_link_attribute(m_line_editor->text());

			m_fill_control->hide();
		}

		if (attr->link_attribute())
			m_new_link_button->hide();
		else
			m_break_link_button->hide();

		if (attr->parent())
			if (LThemeItem* parent_theme_item = dynamic_cast<LThemeItem*>(attr->parent()))
				if (parent_theme_item->is_overridable())
				{
					m_features_tab_bar->add_tab(
						LGraphic(":/images/overrides_icon.svg", QSize(13, 24)),
						"Overrides");

					LTab* overrides_tab = m_features_tab_bar->tabs().last();
					overrides_tab->text_label()->set_font_size_f(10.5);
					overrides_tab->icon_label()->setFixedWidth(13);
					overrides_tab->close_button()->hide();
					overrides_tab->layout()->setContentsMargins(8, 0, 8, 0);
					overrides_tab->layout()->setSpacing(7);
				}

		if (attr->has_overrides())
		{
			for (const auto& [key, override_attr] : attr->overrides())
			{
				LAttributeEditor* override_editor =
					new LAttributeEditor(override_attr);

				override_editor->setObjectName("Attribute Editors");
				add_share_themeable(override_editor);

				m_overrides_layout->addWidget(override_editor);
			}
		}
	}
	else
	{
		m_fill_control->hide();
		m_line_editor->hide();
		m_slider->hide();
	}
}

LAttributeEditor::~LAttributeEditor()
{
	m_attr->disconnect_link_change(m_attr_link_changed_connection);

	disconnect(m_new_link_widget_destroyed_connection);
}

QList<LThemeable*> LAttributeEditor::child_themeables(
	Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables =
		LThemeable::child_themeables(options);

	child_themeables.append(m_features_tab_bar);
	child_themeables.append(m_links_widget);
	child_themeables.append(m_overrides_widget);

	return child_themeables;
}

LFillControl* LAttributeEditor::fill_control() const
{
	return m_fill_control;
}

LLineEditor* LAttributeEditor::line_editor() const
{
	return m_line_editor;
}

LMiniSlider* LAttributeEditor::slider() const
{
	return m_slider;
}

void LAttributeEditor::update_icon_labels()
{
	if (m_attr->link_attribute())
		m_link_icon_label->show();
	else
		m_link_icon_label->hide();

	if (m_attr->has_overrides())
		m_overrides_icon_label->show();
	else
		m_overrides_icon_label->hide();
}

void LAttributeEditor::init_attributes()
{
	m_fill->set_value("#1e2023");
	m_corner_radii_top_left->set_value(10.0);
	m_corner_radii_top_right->set_value(10.0);
	m_corner_radii_bottom_left->set_value(10.0);
	m_corner_radii_bottom_right->set_value(10.0);

	m_label->text_color()->set_value("#ffffff");
}

void LAttributeEditor::init_layout()
{
	m_controls_layout->addWidget(m_fill_control);
	m_controls_layout->addWidget(m_line_editor);
	m_controls_layout->addWidget(m_slider);
	m_controls_layout->setContentsMargins(0, 0, 0, 0);

	m_icons_layout->addWidget(m_link_icon_label);
	m_icons_layout->addWidget(m_overrides_icon_label);
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

	m_links_buttons_layout->addWidget(m_new_link_button);
	m_links_buttons_layout->addWidget(m_break_link_button);
	m_links_buttons_layout->addStretch();
	m_links_buttons_layout->setSpacing(5);
	m_links_buttons_layout->setContentsMargins(0, 0, 0, 0);

	m_links_layout->addLayout(m_links_buttons_layout);
	//m_links_layout->addWidget(m_new_link_widget);
	m_links_layout->addWidget(m_links_view);
	m_links_layout->setSpacing(0);
	m_links_layout->setContentsMargins(5, 5, 5, 5);
	m_links_widget->setLayout(m_links_layout);

	m_overrides_layout->setSpacing(3);
	m_overrides_layout->setContentsMargins(5, 5, 5, 5);
	m_overrides_widget->setLayout(m_overrides_layout);

	QVBoxLayout* attr_features_layout = new QVBoxLayout;
	attr_features_layout->addLayout(tab_layout);
	attr_features_layout->addWidget(m_links_widget);
	attr_features_layout->addWidget(m_overrides_widget);
	attr_features_layout->setContentsMargins(5, 5, 5, 5);
	attr_features_layout->setSpacing(0);
	m_features_widget->setLayout(attr_features_layout);

	QVBoxLayout* main_layout = new QVBoxLayout;
	main_layout->addLayout(top_layout);
	main_layout->addWidget(m_features_widget);
	main_layout->setContentsMargins(0, 0, 0, 0);
	setLayout(main_layout);
}
