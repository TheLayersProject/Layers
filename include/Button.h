#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsOpacityEffect>
#include <QHBoxLayout>

#include "Label.h"
#include "Widget.h"

namespace Layers
{
	class Button : public Widget
	{
		Q_OBJECT

	signals:
		void clicked();

	public:
		Button(Graphic* graphic, const QString& text, bool auto_touch_target_compliance = false, QWidget* parent = nullptr);
		Button(Graphic* graphic, bool auto_touch_target_compliance = false, QWidget* parent = nullptr);
		Button(const QString& text, bool auto_touch_target_compliance = false, QWidget* parent = nullptr);
		Button(Graphic* graphic_before, Graphic* graphic_after, bool auto_touch_target_compliance = false, QWidget* parent = nullptr);
		~Button();

		void disable_graphic_hover_color(bool cond = true);
		void disable_text_hover_color(bool cond = true);

		bool disabled() const;

		Graphic* graphic() const;

		void resize();

		void set_available_width(int available_width);
		void set_disabled(bool cond = true);
		void set_font_size(int size);
		void set_padding(int padding);
		void set_padding(int left, int top, int right, int bottom);
		void set_text_padding(int left, int top, int right, int bottom);

		void toggle_graphics();

		int left_padding() const;
		int top_padding() const;
		int right_padding() const;
		int bottom_padding() const;

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init();
		void init_child_themeable_reference_list();

		void setup_layout();

	private:
		QHBoxLayout* main_layout{ new QHBoxLayout };

		QGraphicsOpacityEffect* m_button_opacity{ new QGraphicsOpacityEffect };

		bool m_auto_touch_target_compliance{ false };

		bool m_disabled{ false };

		bool m_use_graphic_hover_color{ true };
		bool m_use_text_hover_color{ true };

		int m_available_width{ 16777215 };

		Graphic* m_graphic{ nullptr };
		Graphic* m_graphic_after{ nullptr };

		Label* m_text_label{ nullptr };
	};
}

#endif // BUTTON_H
