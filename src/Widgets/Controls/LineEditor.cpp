#include "../../../include/LineEditor.h"

#include <QEvent>

using Layers::LineEditor;
using Layers::Theme;

LineEditor::LineEditor(QWidget* parent) : Widget(parent)
{
	init_attributes();

    setFixedSize(45, 45);
    set_margin(7, 7, 8, 8);

    m_line_edit->installEventFilter(this);
    m_line_edit->setStyleSheet("QLineEdit { border: none; background: transparent; padding-left: " + QString::number(m_attribute_set.attribute_value("left_padding")->value<int>() + m_attribute_set.attribute_value("margin_left")->value<int>()) + "px; padding-bottom: 1px; }");

    connect(m_line_edit, &QLineEdit::textEdited, [this] {
        if (m_line_edit->text().startsWith("0")) m_line_edit->setText("0");
        else if (m_line_edit->hasAcceptableInput() || m_line_edit->text() == "")
        {
            set_stateless_attribute_value("text", m_line_edit->text());
        }
        else m_line_edit->setText(m_attribute_set.attribute_value("text")->value<QString>());

		emit text_edited(m_line_edit->text());
        });

    reconnect_text_attribute();
}

void LineEditor::reconnect_text_attribute()
{
    connect(m_attribute_set.stateless_attribute("text"), &Attribute::value_changed, [this]
        {
            QString new_text = m_attribute_set.attribute_value("text")->value<QString>();

            if (m_line_edit->text() != new_text) m_line_edit->setText(new_text);
        });
}

void LineEditor::init_attributes()
{
    add_stateless_attribute("left_padding", 3);
    add_stateless_attribute("text_color", QColor(Qt::black));
    add_stateless_attribute("text", QString(""));
    set_stateless_attribute_value("background_color", QColor(Qt::lightGray));
    set_stateless_attribute_value("corner_radius_tl", 5);
    set_stateless_attribute_value("corner_radius_tr", 5);
    set_stateless_attribute_value("corner_radius_bl", 5);
    set_stateless_attribute_value("corner_radius_br", 5);
}

void LineEditor::set_target_attribute(Attribute* target_attribute)
{
    m_stateful_attribute = dynamic_cast<StatefulAttribute*>(target_attribute);
    m_stateless_attribute = dynamic_cast<StatelessAttribute*>(target_attribute);

    if (m_stateless_attribute)
    {
        // When the linked stateless attribute's value changes, update the 'text' attribute
        connect(m_stateless_attribute, &Attribute::value_changed, [this]
            {
                set_stateless_attribute_value("text", m_stateless_attribute->value());
            });

        // When the 'text' attribute's value changes, update the linked stateless attribute
        connect(m_attribute_set.stateless_attribute("text"), &Attribute::value_changed, [this]
            {
                m_stateless_attribute->set_value(m_attribute_set.stateless_attribute("text")->value());
            });
    }
    else if (m_stateful_attribute)
    {
        m_attribute_states = m_stateful_attribute->states();

        m_current_editting_state = m_attribute_states.first();

        // When the linked stateful attribute's value changes, update the 'text' attribute
        connect(m_stateful_attribute, &Attribute::value_changed, [this]
            {
                set_stateless_attribute_value("text", *m_stateful_attribute->value(m_current_editting_state));
            });

        // When the 'text' attribute's value changes, update the linked stateful attribute
        connect(m_attribute_set.stateless_attribute("text"), &Attribute::value_changed, [this]
            {
                m_stateful_attribute->set_value(m_current_editting_state, m_attribute_set.stateless_attribute("text")->value());
            });
    }
}

void LineEditor::set_default_value(const QString& default_value)
{
    if (m_default_value) delete m_default_value;

    m_default_value = new QString(default_value);
}

void LineEditor::set_disabled(bool cond)
{
    m_disabled = cond;
}

void LineEditor::set_font_size(int size)
{
    QFont line_edit_font = m_line_edit->font();

    line_edit_font.setPointSize(size);

    m_line_edit->setFont(line_edit_font);

    update_theme_dependencies();
}

void LineEditor::set_margin(int margin)
{
    Widget::set_margin(margin);

    update_theme_dependencies();
}

void LineEditor::set_margin(int left, int top, int right, int bottom)
{
    Widget::set_margin(left, top, right, bottom);

    update_theme_dependencies();
}

void LineEditor::set_text(const QString& text)
{
    m_line_edit->setText(text);

    set_stateless_attribute_value("text", text);
}

void LineEditor::set_validator(const QValidator* validator)
{
    m_line_edit->setValidator(validator);
}

void LineEditor::setFixedSize(int w, int h)
{
	QWidget::setFixedSize(w, h);

	m_line_edit->setFixedSize(w, h);
}

void LineEditor::setFixedWidth(int w)
{
    QWidget::setFixedWidth(w);

    m_line_edit->setFixedWidth(w);
}

QString LineEditor::text()
{
	return m_line_edit->text();
}

void LineEditor::update_theme_dependencies()
{
    m_line_edit->setStyleSheet("QLineEdit { border: none; background: transparent; color: " + m_attribute_set.attribute_value("text_color")->value<QColor>().name() + "; padding-left: " + QString::number(m_attribute_set.attribute_value("left_padding")->value<int>() + m_attribute_set.attribute_value("margin_left")->value<int>()) + "px; padding-bottom: 2px; }");   

	if (m_line_edit->text() != m_attribute_set.attribute_value("text")->value<QString>())
		m_line_edit->setText(m_attribute_set.attribute_value("text")->value<QString>());
}

bool LineEditor::eventFilter(QObject* object, QEvent* event)
{
    if (object == m_line_edit)
    {
        if (event->type() == QEvent::FocusOut)
        {
            if (m_line_edit->text() == "" && m_default_value) m_line_edit->setText(*m_default_value);
        }
    }

    return false;
}
