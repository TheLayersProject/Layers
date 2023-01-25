#ifndef GRADIENTSELECTIONDIALOG_H
#define GRADIENTSELECTIONDIALOG_H

#include <QTimer>

#include "Button.h"
#include "ColorControl.h"
#include "Dialog.h"
#include "Graphic.h"

namespace Layers
{
	class GradientSelectionDialog : public Dialog
	{
		Q_OBJECT

	public:
		GradientSelectionDialog(QGradientStops gradient_stops, QWidget* parent = nullptr);

		void add_gradient_stop(double stop_val, QColor color);

		QGradientStops gradient_stops() const;

		void update_gradient();

	public slots:
		void click_control();
		void update_color_control_positions();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();
		void init_child_themeable_reference_list();

	private:
		void init_color_controls();
		void init_gradient_widget();

		void setup_layout();

		Widget* m_gradient_widget{ new Widget };

		QGradientStops m_gradient_stops{ { 0.0, Qt::white },{ 1.0, Qt::black } };

		QList<ColorControl*> color_controls;

		Button* m_apply_button{ new Button("Apply") };

		ColorControl* m_selected_color_control{ nullptr };
		ColorControl* m_clicking_color_control{ nullptr };

		QPoint m_selection_start_point;

		int m_selected_control_start_x{ 0 };

		QTimer m_single_click_timer;

		bool m_moved{ false };
	};
}

#endif // GRADIENTSELECTIONDIALOG_H
