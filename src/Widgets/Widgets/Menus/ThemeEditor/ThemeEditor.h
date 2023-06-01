#ifndef THEMEEDITOR_H
#define THEMEEDITOR_H

#include <QIntValidator>

#include "Button.h"
#include "Graphic.h"
#include "Navigator.h"
#include "ScrollArea.h"
#include "WidgetButtonGroup.h"

namespace Layers
{
	class WidgetEditor;

	class ThemeEditor : public Widget
	{
		Q_OBJECT

	public:
		ThemeEditor(QWidget* parent = nullptr);
		//~ThemeEditor();

		Button* apply_button() const;

		virtual void apply_theme(Theme& theme) override;

		void edit_themeable(Themeable* themeable);

		QWidget* preview_widget() const;

		void set_preview_widget(QWidget* widget);

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

	private:
		void handle_sidebar_width();

		void init_layout();

		Themeable* m_control_themeable{ new Themeable };

		WidgetEditor* m_control_widget_editor{ nullptr };

		Navigator* m_navigator{ new Navigator };

		QHBoxLayout* m_main_layout{ new QHBoxLayout };
		QVBoxLayout* m_sidebar_layout{ new QVBoxLayout };
		QHBoxLayout* m_topbar_layout{ new QHBoxLayout };
		QGridLayout* m_preview_layout{ new QGridLayout };

		Widget* m_topbar{ new Widget };
		Widget* m_preview_frame = new Widget;

		ScrollArea* m_sidebar{ new ScrollArea };
		ScrollArea* m_preview_scroll_area{ new ScrollArea };

		QWidget* m_preview_widget{ nullptr };

		QList<Themeable*> m_open_themeables;

		Button* m_apply_button{ new Button("Apply") };
	};
}

#endif // THEMEEDITOR_H
