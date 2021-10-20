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

		void init_attributes();

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

		void update_theme_dependencies();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private:
		QString* m_default_value{ nullptr };

		bool m_disabled{ false };

		QLineEdit* m_line_edit{ new QLineEdit(this) };
	};
}

#endif // LINEEDITOR_H
