#ifndef LINEEDITOR_H
#define LINEEDITOR_H

#include <QLineEdit>

#include "Widget.h"

namespace Layers
{
	class LineEditor : public Widget
	{
		Q_OBJECT

	signals:
		void text_edited(const QString& text);

	public:
		LineEditor(QWidget* parent = nullptr);

		virtual void apply_theme_attributes(QMap<QString, Attribute*>& theme_attrs) override;

		void reconnect_text_attribute();

		void set_default_value(const QString& default_value);
		void set_disabled(bool cond = true);
		void set_font_size(int size);
		void set_margin(int margin);
		void set_margin(int left, int top, int right, int bottom);

		void set_text(const QString& text);
		void set_validator(const QValidator* validator);

		void setFixedSize(int w, int h);

		void setFixedWidth(int w);

		QString text();

		Attribute a_left_padding{ Attribute("Left Padding", QVariant::fromValue(3)) };
		Attribute a_text_color{ Attribute("Text Color", QColor(Qt::black)) };
		Attribute a_text{ Attribute("Text", QString("")) };

	public slots:
		void set_current_editting_state(const QString& state);
		void update_theme_dependencies();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();

	private:
		QString* m_default_value{ nullptr };

		bool m_disabled{ false };

		QLineEdit* m_line_edit{ new QLineEdit(this) };
	};
}

#endif // LINEEDITOR_H
