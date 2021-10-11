#include "Layers.h"

#include <algorithm>

using Layers::Combobox;

Combobox::Combobox(QWidget* parent) : Widget(parent)
{
    connect(m_line_edit, &QLineEdit::returnPressed, this, &Combobox::line_edit_return_pressed);

    init_attributes();
	init_child_themeable_reference_list();

    installEventFilter(this);

	m_control_combobox_item->set_proper_name("Combobox Items");

    m_current_item_label->set_font_size(15);
    m_current_item_label->set_proper_name("Current Item Label");
    m_current_item_label->set_padding(0, 7, 0, 0);
    m_current_item_label->set_name("current_item_label");
    m_current_item_label->share_attribute_with_themeable(
		m_current_item_label->attribute_set().stateless_attribute("color"),
		m_attribute_set.stateless_attribute("line_edit_text_color"));

    m_drop_down->installEventFilter(this);
    m_drop_down->setWindowFlags(Qt::FramelessWindowHint);
    m_drop_down->setAttribute(Qt::WA_TranslucentBackground);
    m_drop_down->setMouseTracking(true);
    m_drop_down->set_icon(new Graphic(":/svgs/drop_down_icon.svg", QSize(21, 18)));
    m_drop_down->set_name("drop_down");
    m_drop_down->set_proper_name("Drop Down");

    m_line_edit->installEventFilter(this);
    m_line_edit->setStyleSheet("QLineEdit { border: none; background: transparent; padding-left: " + QString::number(width() * 0.09 - 2) + "px; color: " + m_attribute_set.attribute_value("line_edit_text_color")->value<QColor>().name() + "; }");
    m_line_edit->hide();

    setFixedSize(250, 60);

    setup_layout();
}

void Combobox::add_item(const QString& item)
{
	for (Combobox_Item* cb_item : m_combobox_items)
		if (cb_item->item_text() == item) return;

	Combobox_Item* combobox_item = new Combobox_Item(item);

	combobox_item->set_font_size(m_current_item_label->font().pointSize());
	combobox_item->setFixedSize(size());

	m_combobox_items.append(combobox_item);

    if (m_combobox_items.count() == 1)
    {
		combobox_item->set_state("Single");

        m_current_item_label->setText(item);

        m_current_combobox_item = combobox_item;
    }
	else
	{
		for (Combobox_Item* combobox_item : m_combobox_items)
		{
			if (combobox_item == m_combobox_items.first())
				combobox_item->set_state("Top");
			else if (combobox_item == m_combobox_items.last())
				combobox_item->set_state("Bottom");
			else 
				combobox_item->set_state("Middle");
		}
	}

	m_control_combobox_item->share_all_attributes_with(combobox_item);

    m_drop_down_layout->addWidget(combobox_item);

    m_drop_down->setFixedHeight(m_combobox_items.count() * height());

	if (m_alphabetize) alphabetize();
}

void Combobox::alphabetize()
{
	QList<QString> sorted_items = items();

	std::sort(sorted_items.begin(), sorted_items.end());

	int i = 0;
	for (Combobox_Item* cb_item : m_combobox_items)
	{
		cb_item->replace_item_text(sorted_items[i]);
		i++;
	}
}

void Combobox::edit_current_item()
{
    QFont line_edit_font = m_line_edit->font();

    line_edit_font.setPointSize(m_current_item_label->font().pointSize());

    m_line_edit->setFont(line_edit_font);

    m_current_item_label->hide();

    m_line_edit->setText(m_current_combobox_item->item_text());
    m_line_edit->show();
    m_line_edit->selectAll();
    m_line_edit->setFocus();
}

void Combobox::enable_alphabetization(bool cond)
{
	m_alphabetize = true;

	alphabetize();
}

void Combobox::init_attributes()
{
    set_stateless_attribute_value("corner_radius_tl", 10);
    set_stateless_attribute_value("corner_radius_tr", 10);
    set_stateless_attribute_value("corner_radius_bl", 10);
    set_stateless_attribute_value("corner_radius_br", 10);
    set_stateless_attribute_value("background_color", QColor(Qt::lightGray));
    add_stateless_attribute("line_edit_text_color", QColor(Qt::black));

    m_drop_down->set_stateless_attribute_value("corner_radius_tl", 10);
    m_drop_down->set_stateless_attribute_value("corner_radius_tr", 10);
    m_drop_down->set_stateless_attribute_value("corner_radius_bl", 10);
    m_drop_down->set_stateless_attribute_value("corner_radius_br", 10);
    m_drop_down->set_stateless_attribute_value("background_disabled", true);
}

void Combobox::init_child_themeable_reference_list()
{
	add_child_themeable_reference(m_current_item_label);
    add_child_themeable_reference(m_drop_down);

	m_drop_down->add_child_themeable_reference(m_control_combobox_item);
}

void Combobox::set_current_item(const QString& item)
{
    if (m_current_combobox_item->item_text() != item)
    {
        m_current_item_label->setText(item);

		for (Combobox_Item* combobox_item : m_combobox_items)
			if (combobox_item->item_text() == item)
				m_current_combobox_item = combobox_item;

        if (!m_disabled) emit current_item_changed(item);
    }
}

void Combobox::set_disabled(bool cond)
{
    m_disabled = cond;
}

void Combobox::set_font_size(int size)
{
    m_current_item_label->set_font_size(size);

    for (Combobox_Item* combobox_item : m_combobox_items)
		combobox_item->set_font_size(size);
}

void Combobox::set_item_renaming_disabled(bool disable)
{
    m_item_renaming_disabled = disable;
}

void Combobox::set_padding(int left, int top, int right, int bottom)
{
    m_current_item_label->set_padding(left, top, right, bottom);
}

void Combobox::setFixedSize(const QSize& s)
{
    Widget::setFixedSize(s);

    m_line_edit->setFixedSize(s);

    m_drop_down->setFixedWidth(s.width());

	for (Combobox_Item* combobox_item : m_combobox_items)
		combobox_item->setFixedSize(s);

    m_current_item_label->move(width() * 0.09, height() / 2 - m_current_item_label->height() / 2);

    m_line_edit->setStyleSheet("QLineEdit { border: none; background: transparent; padding-left: " + QString::number(width() * 0.09 - 2) + "px; color: " + m_attribute_set.attribute_value("line_edit_text_color")->value<QColor>().name() + "; }");
}

void Combobox::setFixedSize(int w, int h)
{
    setFixedSize(QSize(w, h));
}

QString Combobox::current_item() const
{
    return m_current_combobox_item->item_text();
}

QList<QString> Combobox::items()
{
	QList<QString> items;

	for (Combobox_Item* combobox_item : m_combobox_items)
		items.append(combobox_item->item_text());

	return items;
}

void Combobox::update_theme_dependencies()
{
    m_line_edit->setStyleSheet("QLineEdit { border: none; background: transparent; padding-left: " + QString::number(width() * 0.09 - 2) + "px; color: " + m_attribute_set.attribute_value("line_edit_text_color")->value<QColor>().name() + "; }");
}

void Combobox::line_edit_return_pressed()
{
    if (current_item() != m_line_edit->text())
    {
        QString old_item_text = current_item();

		m_current_combobox_item->replace_item_text(m_line_edit->text());

        emit item_replaced(old_item_text, m_line_edit->text());

        m_current_item_label->setText(current_item());
    }

    m_line_edit->hide();

    m_current_item_label->show();
}

bool Combobox::eventFilter(QObject* object, QEvent* event)
{
    if (object == this)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

            if (mouse_event->button() & Qt::LeftButton)
            {
                QPoint mapped_from_global = mapToGlobal(QPoint(0, 0));
                QPoint move_point = QPoint(mapped_from_global.x(), mapped_from_global.y() - (m_combobox_items.indexOf(m_current_combobox_item) * height()));

                m_drop_down->move(move_point);
                m_drop_down->show();
                m_drop_down->setFocus();
            }
        }
    }
    else if (object == m_drop_down)
    {
        if (event->type() == QEvent::FocusOut)
        {
            m_drop_down->hide();

            update();
        }
        else if (event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

            if (mouse_event->button() & Qt::LeftButton)
            {
                for (Combobox_Item* combobox_item : m_combobox_items)
                {
                    if (combobox_item->geometry().contains(mouse_event->pos()))
                    {
                        set_current_item(combobox_item->item_text());
                    }
                }

                m_drop_down->hide();
            }
        }
    }
    else if (object == m_line_edit)
    {
        if (event->type() == QEvent::FocusOut)
        {
            line_edit_return_pressed();
        }
    }
    if (!m_disabled && !m_item_renaming_disabled)
    {
        if (event->type() == QEvent::MouseButtonDblClick)
        {
            QMouseEvent* mouse_event = static_cast<QMouseEvent*>(event);

            if (mouse_event->button() & Qt::LeftButton)
            {
                m_drop_down->hide();

                update();

                edit_current_item();
            }
        }
    }

    return false;
}

void Combobox::init_attribute_widgets()
{
	Widget::init_attribute_widgets();

	m_attribute_widgets["border_awc"]->set_primary(false);
	m_attribute_widgets["hover_background_caw"]->set_primary(false);
	m_attribute_widgets["outline_caw"]->set_primary(false);
	m_attribute_widgets["corner_color_caw"]->set_primary(false);

	m_drop_down->attribute_widgets()["border_awc"]->set_primary(false);
	m_drop_down->attribute_widgets()["hover_background_caw"]->set_primary(false);
	m_drop_down->attribute_widgets()["outline_caw"]->set_primary(false);
	m_drop_down->attribute_widgets()["corner_color_caw"]->set_primary(false);
	m_drop_down->attribute_widgets()["corner_radii_attribute_widget"]->set_primary(false);
}

void Combobox::setup_layout()
{
    m_drop_down_layout->setContentsMargins(0, 0, 0, 0);
    m_drop_down_layout->setSpacing(0);

    m_drop_down->setLayout(m_drop_down_layout);
}
