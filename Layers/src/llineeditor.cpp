#include <Layers/llineeditor.h>

#include <QEvent>
#include <QResizeEvent>

using Layers::LAttribute;
using Layers::LLineEditor;

LLineEditor::LLineEditor(QWidget* parent) : LWidget(parent)
{
	init_attributes();
	installEventFilter(this);
	setFocusProxy(m_line_edit);
	update();

	m_line_edit->installEventFilter(this);

	connect(m_line_edit, &QLineEdit::textEdited, [this] {
		if (m_text->typeName() == "QString")
			m_text->set_value(m_line_edit->text());
		else if (m_text->typeName() == "double")
			m_text->set_value(QVariant(m_line_edit->text().toDouble()));

		emit text_edited(m_line_edit->text());
		});

	connect(m_text, &LAttribute::changed, [this] { update(); });
}

LLineEditor::~LLineEditor()
{
	if (m_default_value)
		delete m_default_value;

	delete m_left_padding;
	delete m_text;
}

void LLineEditor::set_default_value(const QString& default_value)
{
	if (m_default_value)
		delete m_default_value;

	m_default_value = new QString(default_value);
}

void LLineEditor::set_font_size(int size)
{
	QFont line_edit_font = m_line_edit->font();
	line_edit_font.setPointSize(size);
	m_line_edit->setFont(line_edit_font);

	update();
}

void LLineEditor::set_font_size_f(qreal size)
{
	QFont line_edit_font = m_line_edit->font();
	line_edit_font.setPointSizeF(size);
	m_line_edit->setFont(line_edit_font);

	update();
}

void LLineEditor::set_text(const QString& text)
{
	m_line_edit->setText(text);

	m_text->set_value(text);
}

void LLineEditor::set_validator(const QValidator* validator)
{
	m_line_edit->setValidator(validator);
}

LAttribute* LLineEditor::left_padding() const
{
	return m_left_padding;
}

LAttribute* LLineEditor::text_color() const
{
	return m_text_color;
}

LAttribute* LLineEditor::text() const
{
	return m_text;
}

void LLineEditor::update()
{
	m_line_edit->setStyleSheet(
		"QLineEdit {"
		"border: none;"
		"background: transparent;"
		"color: " + m_text_color->as<QColor>().name() + ";"
		"padding-left: " + QString::number(
			m_margins_left->as<double>() +
			m_left_padding->as<double>()) + "px;"
		"padding-bottom: 2px;"
		"}");

	if (m_line_edit->text() != m_text->as<QString>())
		m_line_edit->setText(m_text->as<QString>());

	m_line_edit->update();
}

bool LLineEditor::eventFilter(QObject* object, QEvent* event)
{
	if (object == m_line_edit)
	{
		if (event->type() == QEvent::FocusOut)
		{
			if (m_line_edit->text() == "" && m_default_value)
				m_line_edit->setText(*m_default_value);
		}
	}
	else if (object == this)
	{
		if (event->type() == QEvent::Resize)
		{
			QResizeEvent* resize_event = static_cast<QResizeEvent*>(event);

			m_line_edit->setFixedSize(resize_event->size());
		}
	}

	return false;
}

void LLineEditor::init_attributes()
{
	m_corner_radii_top_left->set_value(5.0);
	m_corner_radii_top_right->set_value(5.0);
	m_corner_radii_bottom_left->set_value(5.0);
	m_corner_radii_bottom_right->set_value(5.0);
	m_fill->set_value(QColor(Qt::lightGray));
}
