#ifndef LLINEEDITOR_H
#define LLINEEDITOR_H

#include <QLineEdit>

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LLineEditor : public LWidget
{
	Q_OBJECT

signals:
	void text_edited(const QString& text);

public:
	LLineEditor(QWidget* parent = nullptr);

	~LLineEditor();

	LAttribute* left_padding() const;

	void set_default_value(const QString& default_value);

	void set_font_size(int size);

	void set_font_size_f(qreal size);

	void set_text(const QString& text);

	void set_validator(const QValidator* validator);

	LAttribute* text() const;

	LAttribute* text_color() const;

	virtual void update() override;

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

private:
	void init_attributes();

	LAttribute* m_left_padding
		{ new LAttribute("left_padding", QVariant::fromValue(3.0)) };

	LAttribute* m_text_color
		{ new LAttribute("Text Color", QColor(Qt::black), this) };

	LAttribute* m_text
		{ new LAttribute("text", QString("")) };

	QString* m_default_value{ nullptr };

	QLineEdit* m_line_edit{ new QLineEdit(this) };
};
LAYERS_NAMESPACE_END

#endif // LLINEEDITOR_H
