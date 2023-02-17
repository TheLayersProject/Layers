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
		~LineEditor();

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

		void setFocus(Qt::FocusReason reason);

		//QString text();

		Attribute* left_padding() const;
		Attribute* text_color() const;
		Attribute* text() const;

	public slots:
		inline void setFocus() { setFocus(Qt::OtherFocusReason); }

		void set_current_editting_state(const QString& state);

		void update_theme_dependencies();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();

	private:
		Attribute* m_left_padding{ new Attribute("left_padding", QVariant::fromValue(3.0)) };
		Attribute* m_text_color{ new Attribute("text_color", QColor(Qt::black)) };
		Attribute* m_text{ new Attribute("text", QString("")) };

		QString* m_default_value{ nullptr };

		bool m_disabled{ false };

		QLineEdit* m_line_edit{ new QLineEdit(this) };
	};
}

#endif // LINEEDITOR_H
