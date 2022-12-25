#include "../../../include/AttributeWidgets.h"
#include "../../../include/Combobox.h"
#include "../../../include/Graphic.h"

#include <QMouseEvent>

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

    a_line_edit_text_color.get_data_from(m_current_item_label->a_text_color);

    m_drop_down->installEventFilter(this);
    m_drop_down->setWindowFlags(Qt::FramelessWindowHint);
    m_drop_down->setAttribute(Qt::WA_TranslucentBackground);
    m_drop_down->setMouseTracking(true);
    m_drop_down->set_icon(new Graphic(":/svgs/drop_down_icon.svg", QSize(21, 18)));
    m_drop_down->set_name("drop_down");
    m_drop_down->set_proper_name("Drop Down");

    m_line_edit->installEventFilter(this);
    m_line_edit->setStyleSheet("QLineEdit { border: none; background: transparent; padding-left: " + QString::number(width() * 0.09 - 2) + "px; color: " + a_line_edit_text_color.as<QColor>().name() + "; }");
    m_line_edit->hide();

    setFixedSize(250, 60);

    setup_layout();
}

void Combobox::add_item(const QString& item)
{
	for (ComboboxItem* cb_item : m_combobox_items)
		if (cb_item->item_text() == item) return;

	ComboboxItem* combobox_item = new ComboboxItem(item);

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
		for (ComboboxItem* combobox_item : m_combobox_items)
		{
			if (combobox_item == m_combobox_items.first())
				combobox_item->set_state("Top");
			else if (combobox_item == m_combobox_items.last())
				combobox_item->set_state("Bottom");
			else 
				combobox_item->set_state("Middle");
		}
	}

    combobox_item->replace_all_attributes_with(m_control_combobox_item);

    m_drop_down_layout->addWidget(combobox_item);

    m_drop_down->setFixedHeight(m_combobox_items.count() * height());

	if (m_alphabetize) alphabetize();
}

void Combobox::alphabetize()
{
	QList<QString> sorted_items = items();

	std::sort(sorted_items.begin(), sorted_items.end());

	int i = 0;
	for (ComboboxItem* cb_item : m_combobox_items)
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
    corner_radii.top_left.set_value(10.0);
    corner_radii.top_right.set_value(10.0);
    corner_radii.bottom_left.set_value(10.0);
    corner_radii.bottom_right.set_value(10.0);
    a_fill.set_value(QColor(Qt::lightGray));

    m_drop_down->corner_radii.top_left.set_value(10.0);
    m_drop_down->corner_radii.top_right.set_value(10.0);
    m_drop_down->corner_radii.bottom_left.set_value(10.0);
    m_drop_down->corner_radii.bottom_right.set_value(10.0);
    m_drop_down->a_fill.set_disabled();
}

void Combobox::init_child_themeable_reference_list()
{
	store_child_themeable_pointer(m_current_item_label);
    store_child_themeable_pointer(m_drop_down);

	m_drop_down->store_child_themeable_pointer(m_control_combobox_item);
}

void Combobox::set_current_item(const QString& item)
{
    if (m_current_combobox_item->item_text() != item)
    {
        m_current_item_label->setText(item);

		for (ComboboxItem* combobox_item : m_combobox_items)
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

    for (ComboboxItem* combobox_item : m_combobox_items)
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

	for (ComboboxItem* combobox_item : m_combobox_items)
		combobox_item->setFixedSize(s);

    m_current_item_label->move(width() * 0.09, height() / 2 - m_current_item_label->height() / 2);

    m_line_edit->setStyleSheet(
        "QLineEdit { border: none; background: transparent; padding-left: " + QString::number(width() * 0.09 - 2) + "px; color: " +
        a_line_edit_text_color.as<QColor>().name() + "; }");
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

	for (ComboboxItem* combobox_item : m_combobox_items)
		items.append(combobox_item->item_text());

	return items;
}

void Combobox::update_theme_dependencies()
{
    m_line_edit->setStyleSheet(
        "QLineEdit { border: none; background: transparent; padding-left: " + QString::number(width() * 0.09 - 2) + "px; color: " +
        a_line_edit_text_color.as<QColor>().name() + "; }");
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
                for (ComboboxItem* combobox_item : m_combobox_items)
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

void Combobox::setup_layout()
{
    m_drop_down_layout->setContentsMargins(0, 0, 0, 0);
    m_drop_down_layout->setSpacing(0);

    m_drop_down->setLayout(m_drop_down_layout);
}
