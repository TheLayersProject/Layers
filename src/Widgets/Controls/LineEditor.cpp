#include "../../Layers.h"

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
            share_attributes();
        }
        else m_line_edit->setText(m_attribute_set.attribute_value("text")->value<QString>());

		emit text_edited(m_line_edit->text());
        });
}

void LineEditor::init_attributes()
{
    set_stateless_attribute_value("background_color", QColor(Qt::lightGray));
    set_stateless_attribute_value("corner_radius_tl", 5);
    set_stateless_attribute_value("corner_radius_tr", 5);
    set_stateless_attribute_value("corner_radius_bl", 5);
    set_stateless_attribute_value("corner_radius_br", 5);
    add_stateless_attribute("left_padding", 3);
    add_stateless_attribute("text_color", QColor(Qt::black));
    add_stateless_attribute("text", QString(""));
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

	share_attributes();
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
