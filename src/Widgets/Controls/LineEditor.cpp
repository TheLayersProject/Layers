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
		QString::number(a_left_padding.as<double>() + margins.left.as<double>()) + "px; padding-bottom: 1px; }");

	connect(m_line_edit, &QLineEdit::textEdited, [this] {
  //      if (m_line_edit->text().startsWith("0")) m_line_edit->setText("0");
  //      else if (m_line_edit->hasAcceptableInput() || m_line_edit->text() == "")
  //      {
  //          if (a_text.is_stateful())
  //              a_text.set_value(a_text.state(), m_line_edit->text());
  //          else
  //              a_text.set_value(m_line_edit->text());
  //      }
  //      else m_line_edit->setText(a_text.as<QString>());

		// TODO: Simplify below after merging Attribute::set_value() overloads
		// into a single function
		// TODO: Remove
		//if (a_text.is_stateful())
		//{
		//	if (QString(a_text.typeName()) == "QString")
		//		a_text.set_value(a_text.state(), m_line_edit->text());

		//	else if (QString(a_text.typeName()) == "double")
		//		a_text.set_value(a_text.state(), QVariant(m_line_edit->text().toDouble()));
		//}
		//else
		//{
		//	if (QString(a_text.typeName()) == "QString")
		//		a_text.set_value(m_line_edit->text());

		//	else if (QString(a_text.typeName()) == "double")
		//		a_text.set_value(QVariant(m_line_edit->text().toDouble()));

		//	//a_text.set_value(m_line_edit->text());
		//}

		if (QString(a_text.typeName()) == "QString")
			a_text.set_value(m_line_edit->text());

		else if (QString(a_text.typeName()) == "double")
			a_text.set_value(QVariant(m_line_edit->text().toDouble()));

		emit text_edited(m_line_edit->text());
		});

	reconnect_text_attribute();
}

void LineEditor::reconnect_text_attribute()
{
	connect(&a_text, &Entity::value_changed, [this]
		{
			update_theme_dependencies();

			//QString new_text = a_text.as<QString>();

			//if (m_line_edit->text() != new_text) m_line_edit->setText(new_text);
		});
}

void LineEditor::init_attributes()
{
	m_entities.insert({
		{ "text_color", &a_text_color }
		});

	corner_radii.top_left.set_value(5.0);
	corner_radii.top_right.set_value(5.0);
	corner_radii.bottom_left.set_value(5.0);
	corner_radii.bottom_right.set_value(5.0);
	a_fill.set_value(QColor(Qt::lightGray));

	connect(&a_text_color, &Entity::value_changed, [this] {
		update_theme_dependencies();
		m_line_edit->update();
		});
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

	//if (a_text.is_stateful())
	//	a_text.set_value(a_text.state(), text);
	//else
	//	a_text.set_value(text);

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

void LineEditor::setFocus(Qt::FocusReason reason)
{
	m_line_edit->setFocus();
}

QString LineEditor::text()
{
	return m_line_edit->text();
}

void LineEditor::update_theme_dependencies()
{
	m_line_edit->setStyleSheet(
		"QLineEdit { border: none; background: transparent; color: " + a_text_color.as<QColor>().name() + "; padding-left: " +
		QString::number(a_left_padding.as<double>() + margins.left.as<double>()) + "px; padding-bottom: 2px; }");

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
