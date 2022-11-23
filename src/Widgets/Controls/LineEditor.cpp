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
    m_line_edit->setStyleSheet(
        "QLineEdit { border: none; background: transparent; padding-left: " +
        QString::number(a_left_padding.as<int>() + a_margin_left.as<int>()) + "px; padding-bottom: 1px; }");

    connect(m_line_edit, &QLineEdit::textEdited, [this] {
        if (m_line_edit->text().startsWith("0")) m_line_edit->setText("0");
        else if (m_line_edit->hasAcceptableInput() || m_line_edit->text() == "")
        {
            if (a_text.is_stateful())
                a_text.set_value(a_text.state(), m_line_edit->text());
            else
                a_text.set_value(m_line_edit->text());
        }
        else m_line_edit->setText(a_text.as<QString>());

		emit text_edited(m_line_edit->text());
        });

    reconnect_text_attribute();
}

void LineEditor::apply_theme_attributes(QMap<QString, Attribute*>& theme_attrs)
{
    Widget::apply_theme_attributes(theme_attrs);

    a_text_color.copy_value_from(*theme_attrs["text_color"]);
}

void LineEditor::reconnect_text_attribute()
{
    connect(&a_text, &Attribute::value_changed, [this]
        {
            update_theme_dependencies();

            //QString new_text = a_text.as<QString>();

            //if (m_line_edit->text() != new_text) m_line_edit->setText(new_text);
        });
}

void LineEditor::init_attributes()
{
    m_attributes.insert({
        { "text_color", &a_text_color }
        });

    a_corner_radius_tl.set_value(5);
    a_corner_radius_tr.set_value(5);
    a_corner_radius_bl.set_value(5);
    a_corner_radius_br.set_value(5);
    a_fill.set_value(QColor(Qt::lightGray));

    connect(&a_text_color, &Attribute::value_changed, [this] {
        update_theme_dependencies();
        m_line_edit->update();
        });
}

void LineEditor::replace_all_attributes_with(LineEditor* line_editor)
{
    Widget::replace_all_attributes_with(line_editor);

    a_text_color.get_variant_from(line_editor->a_text_color);

    update_theme_dependencies();
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

    if (a_text.is_stateful())
        a_text.set_value(a_text.state(), text);
    else
        a_text.set_value(text);
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
    m_line_edit->setStyleSheet(
        "QLineEdit { border: none; background: transparent; color: " + a_text_color.as<QColor>().name() + "; padding-left: " +
        QString::number(a_left_padding.as<int>() + a_margin_left.as<int>()) + "px; padding-bottom: 2px; }");

	if (m_line_edit->text() != a_text.as<QString>())
		m_line_edit->setText(a_text.as<QString>());
}

void LineEditor::set_current_editting_state(const QString& state)
{
    a_text.set_state(state);

    update_theme_dependencies();
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
