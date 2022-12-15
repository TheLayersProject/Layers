#ifndef GRADIENTSELECTIONDIALOG_H
#define GRADIENTSELECTIONDIALOG_H

#include <QDialog>
#include <QTimer>

#include "Button.h"
#include "ColorControl.h"
#include "Graphic.h"

namespace Layers
{
	class GradientSelectionDialog : public QDialog, public Themeable
	{
		Q_OBJECT

	public:
		GradientSelectionDialog(QGradientStops gradient_stops, QWidget* parent = nullptr);

		void add_gradient_stop(double stop_val, QColor color);

		virtual void apply_theme_attributes(QMap<QString, AttributeType*>& theme_attrs) override;

		QGradientStops gradient_stops() const;

		void update_gradient();

		BorderAttributes border;

		CornerRadiiAttributes corner_radii;

		MarginsAttributes margins;

		Attribute a_corner_color{ Attribute(
			"corner_color",
			QColor(Qt::gray),
			true
			) };

		Attribute a_fill{ Attribute(
			"fill",
			QColor(Qt::white)
			) };

		Attribute a_hover_fill{ Attribute(
			"hover_fill",
			QColor(Qt::lightGray),
			true
			) };

		Attribute a_outline_color{ Attribute(
			"outline_color",
			QColor(Qt::gray),
			true
			) };

	public slots:
		void click_control();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();
		void init_child_themeable_reference_list();

		bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;

		void paintEvent(QPaintEvent* event) override;

	private:
		void init_color_controls();
		void init_gradient_widget();
		void init_titlebar();

		void setup_layout();

		bool m_hovering{ false };

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		Widget* m_gradient_widget{ new Widget };
		Widget* m_titlebar{ new Widget };

		Label* m_window_title_label = new Label("Gradient Selection Box");

		Button* m_exit_button = new Button(new Graphic(":/svgs/exit.svg", QSize(20, 20)), true);

		QGradientStops m_gradient_stops{ { 0.0, Qt::white },{ 1.0, Qt::black } };

		QList<ColorControl*> color_controls;

		Button* m_apply_button{ new Button("Apply") };

		ColorControl* m_selected_color_control{ nullptr };
		ColorControl* m_clicking_color_control{ nullptr };

		QPoint m_selection_start_point;

		int m_selected_control_start_x{ 0 };

		QTimer m_single_click_timer;

		bool m_moved{ false };

		QPainter painter;
	};
}

#endif // GRADIENTSELECTIONDIALOG_H
