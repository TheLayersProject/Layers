#include <Layers/lattributeeditor.h>

#include <QIntValidator>
#include <QPainterPath>

#include <Layers/lthemeitem.h>

using Layers::LAttributeEditor;
using Layers::LFillControl;
using Layers::LLineEditor;
using Layers::LLinksWidget;
using Layers::LMiniSlider;
using Layers::LThemeable;

LLinksWidget::LLinksWidget(LAttribute* attr, QWidget* parent) :
	LWidget(parent)
{
	set_name("Links Widget");

	QFont f = font();
	f.setPointSizeF(10.5);
	setFont(f);

	m_dot_svg->set_name("Dot Svg");

	m_link_arrow_svg->set_name("Link Arrow Svg");

	m_dependent_arrow_svg->set_name("Dependent Arrow Svg");
	m_dependent_arrow_2_svg->set_name("Dependent Arrow Svg");

	if (attr)
	{
		if (attr->parent())
			if (LThemeItem* parent_theme_item = dynamic_cast<LThemeItem*>(attr->parent()))
				m_parent_path = parent_theme_item->path();

		if (LAttribute* link_attr = attr->link_attribute())
		{
			while (link_attr)
			{
				QString link_path = link_attr->path();

				if (!m_parent_path.isEmpty())
					if (link_path.startsWith(m_parent_path))
						link_path.replace(m_parent_path, ".");

				m_link_paths.insert(0, link_path);

				link_attr = link_attr->link_attribute();
			}
		}

		for (LAttribute* dependent_attr : attr->dependent_attributes())
		{
			QString dependent_path = dependent_attr->path();

			if (!m_parent_path.isEmpty())
				if (dependent_path.startsWith(m_parent_path))
					dependent_path.replace(m_parent_path, ".");

			m_dependent_paths.append(dependent_path);
		}
	}

	update_height();
}

void LLinksWidget::paintEvent(QPaintEvent* event)
{
	LWidget::paintEvent(event);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	int item_number = 0;

	for (const QString& link_path : m_link_paths)
	{
		QRect item_rect(
			0, 40 * item_number++,
			width(), 40);

		paint_item_dot(&painter, item_rect, 9);
		paint_item_text(&painter, link_path, item_rect, font(), 27);

		int uplink_arrow_y = item_rect.y() + (item_rect.height() / 2) + 5;
		m_link_arrow_svg->render(&painter,
			QRectF(7, uplink_arrow_y, 12, 34));
	}

	QFont bold_text_font = font();
	bold_text_font.setBold(true);

	QRect this_text_rect = QRect(0, 40 * item_number++, width(), 40);

	paint_item_dot(&painter, this_text_rect, 9);
	paint_item_text(&painter, "This", this_text_rect, bold_text_font, 27);

	for (int i = 0; i < m_dependent_paths.size(); i++)
	{
		const QString& dependent_path = m_dependent_paths[i];

		QRect previous_item_rect(
			0, 40 * (item_number - 1),
			width(), 40);

		if (i == 0)
		{
			int downlink_arrow_y = previous_item_rect.y() + (previous_item_rect.height() / 2) + 5;
			m_dependent_arrow_svg->render(&painter,
				QRectF(7, downlink_arrow_y, 13, 37));
		}
		else
		{
			int downlink_arrow_y = previous_item_rect.y() + (previous_item_rect.height() / 2) - 7;
			m_dependent_arrow_2_svg->render(&painter,
				QRectF(12, downlink_arrow_y, 8, 48));
		}

		QRect item_rect(
			0, 40 * item_number++,
			width(), 40);

		paint_item_dot(&painter, item_rect, 19);
		paint_item_text(&painter, dependent_path, item_rect, font(), 37);
	}
}

void LLinksWidget::paint_item_dot(
	QPainter* painter,
	const QRect& item_rect,
	int x)
{
	int dot_y = item_rect.y() + (item_rect.height() / 2) - 5;

	m_dot_svg->render(painter,
		QRectF(x, dot_y, 10, 10));
}

void LLinksWidget::paint_item_text(
	QPainter* painter,
	const QString& text,
	const QRect& item_rect,
	QFont font,
	int x)
{
	const QFontMetrics& font_metrics = QFontMetrics(font);

	QPainterPath text_path;

	text_path.addText(
		QPoint(x, item_rect.center().y() + (font_metrics.height() / 2) - 2),
		font,
		text
	);

	painter->fillPath(text_path, m_text_color->as<QColor>());
}

void LLinksWidget::update_height()
{
	// 40 is item size

	int new_height = 40;

	if (m_link_paths.isEmpty());
	else
		new_height += 40 * m_link_paths.count();

	new_height += 40 * m_dependent_paths.count();

	setFixedHeight(new_height);
}

LAttributeEditor::LAttributeEditor(LAttribute* attr, QWidget* parent) :
	m_attr{ attr },
	m_links_widget{ new LLinksWidget(attr)},
	LWidget(parent)
{
	init_attributes();
	init_layout();
	setMinimumHeight(40);
	setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);

	m_fill_control->set_name("Fill Control");

	QIntValidator* int_validator = new QIntValidator(0, 30);

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
	links_tab->text_label()->set_font_size(10.5);
	links_tab->icon_label()->setFixedWidth(11);
	links_tab->close_button()->hide();
	links_tab->layout()->setContentsMargins(8, 0, 8, 0);
	links_tab->layout()->setSpacing(7);

	m_overrides_widget->set_name("Overrides Widget");
	m_overrides_widget->hide();

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
			m_line_editor->text()->set_link_attribute(attr);

			m_slider->value().set_link_attribute(m_line_editor->text());

			m_fill_control->hide();
		}

		if (attr->link_attribute())
		{
			LLabel* link_icon_label =
				new LLabel(LGraphic(":/images/chain_link.svg", QSize(8, 18)));
			link_icon_label->set_name("Icon Labels");
			link_icon_label->setAlignment(Qt::AlignCenter);
			link_icon_label->setFixedSize(20, 26);
			m_icons_layout->addWidget(link_icon_label);
		}

		if (attr->parent())
			if (LThemeItem* parent_theme_item = dynamic_cast<LThemeItem*>(attr->parent()))
				if (parent_theme_item->is_overridable())
				{
					m_features_tab_bar->add_tab(
						LGraphic(":/images/overrides_icon.svg", QSize(13, 24)),
						"Overrides");

					LTab* overrides_tab = m_features_tab_bar->tabs().last();
					overrides_tab->text_label()->set_font_size(10.5);
					overrides_tab->icon_label()->setFixedWidth(13);
					overrides_tab->close_button()->hide();
					overrides_tab->layout()->setContentsMargins(8, 0, 8, 0);
					overrides_tab->layout()->setSpacing(7);
				}

		if (attr->has_overrides())
		{
			LLabel* overrides_icon_label =
				new LLabel(LGraphic(":/images/overrides_icon.svg", QSize(10, 18)));
			overrides_icon_label->set_name("Icon Labels");
			overrides_icon_label->setAlignment(Qt::AlignCenter);
			overrides_icon_label->setFixedSize(20, 26);
			m_icons_layout->addWidget(overrides_icon_label);

			for (LAttribute* override_attr : attr->overrides())
			{
				LAttributeEditor* override_editor =
					new LAttributeEditor(override_attr);

				override_editor->set_name("Attribute Editors");
				share_theme_item_with(override_editor);

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

QList<LThemeable*> LAttributeEditor::child_themeables(Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables = LThemeable::child_themeables(options);

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
