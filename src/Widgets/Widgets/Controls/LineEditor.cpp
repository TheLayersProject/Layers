#include "LineEditor.h"

#include <QEvent>

using Layers::Attribute;
using Layers::LineEditor;
using Layers::Theme;

LineEditor::LineEditor(QWidget* parent) : Widget(parent)
{
	init_attributes();

	setFixedSize(40, 40);
	set_margin(5, 5, 5, 5);

	m_line_edit->installEventFilter(this);
	m_line_edit->setStyleSheet(
		"QLineEdit { border: none; background: transparent; padding-left: " +
		QString::number(m_left_padding->as<double>() + m_margins->left()->as<double>()) + "px; padding-bottom: 1px; }");

	connect(m_line_edit, &QLineEdit::textEdited, [this] {
		if (QString(m_text->typeName()) == "QString")
			m_text->set_value(m_line_edit->text());

		else if (QString(m_text->typeName()) == "double")
			m_text->set_value(QVariant(m_line_edit->text().toDouble()));

		emit text_edited(m_line_edit->text());
		});

	connect(m_text, &AbstractAttribute::changed, [this]
		{
			update_theme_dependencies();
		});
}

LineEditor::~LineEditor()
{
	if (m_default_value)
		delete m_default_value;

	delete m_left_padding;
	delete m_text_color;
	delete m_text;
}

void LineEditor::init_attributes()
{
	m_attributes.insert({
		{ "text_color", m_text_color }
		});

	m_corner_radii->top_left()->set_value(5.0);
	m_corner_radii->top_right()->set_value(5.0);
	m_corner_radii->bottom_left()->set_value(5.0);
	m_corner_radii->bottom_right()->set_value(5.0);
	m_fill->set_value(QColor(Qt::lightGray));

	connect(m_text_color, &AbstractAttribute::changed, [this] {
		update_theme_dependencies();
		m_line_edit->update();
		});
}

void LineEditor::set_default_value(const QString& default_value)
{
	if (m_default_value)
		delete m_default_value;

	m_default_value = new QString(default_value);
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

	//if (m_text->is_multi_valued())
	//	m_text->set_value(m_text->state(), text);
	//else
	//	m_text->set_value(text);

	m_text->set_value(text);
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

Attribute* LineEditor::left_padding() const
{
	return m_left_padding;
}

Attribute* LineEditor::text_color() const
{
	return m_text_color;
}

Attribute* LineEditor::text() const
{
	return m_text;
}

void LineEditor::update_theme_dependencies()
{
	m_line_edit->setStyleSheet(
		"QLineEdit { border: none; background: transparent; color: " + m_text_color->as<QColor>().name() + "; padding-left: " +
		QString::number(m_left_padding->as<double>() + margins()->left()->as<double>()) + "px; padding-bottom: 2px; }");

	if (m_line_edit->text() != m_text->as<QString>())
		m_line_edit->setText(m_text->as<QString>());
}

void LineEditor::set_current_editting_state(const QString& state)
{
	m_text->set_state(state);

	update_theme_dependencies();
}

bool LineEditor::eventFilter(QObject* object, QEvent* event)
{
	if (object == m_line_edit)
	{
		if (event->type() == QEvent::FocusOut)
		{
			if (m_line_edit->text() == "" && m_default_value)
				m_line_edit->setText(*m_default_value);
		}
	}

	return false;
}
