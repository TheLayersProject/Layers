#ifndef GRADIENTSELECTIONDIALOG_H
#define GRADIENTSELECTIONDIALOG_H

#include <QDialog>
#include <QTimer>

#include "Button.h"
#include "ColorControl.h"

namespace Layers
{
	class GradientSelectionDialog : public QDialog, public Themeable
	{
		Q_OBJECT

	public:
		GradientSelectionDialog(QGradientStops gradient_stops, QWidget* parent = nullptr);

		void add_gradient_stop(double stop_val, QColor color);

		QGradientStops gradient_stops() const;

		void issue_update();

		void update_gradient();
		void update_theme_dependencies();

		Attribute a_border_fill{ Attribute("Border Fill", QColor(Qt::gray)) };
		Attribute a_border_thickness{ Attribute("Border Thickness", QVariant::fromValue(0)) };
		Attribute a_corner_color{ Attribute("Corner Color", QColor(Qt::gray), true) };
		Attribute a_corner_radius_tl{ Attribute("Top-Left Corner Radius", QVariant::fromValue(0)) };
		Attribute a_corner_radius_tr{ Attribute("Top-Right Corner Radius", QVariant::fromValue(0)) };
		Attribute a_corner_radius_bl{ Attribute("Bottom-Left Corner Radius", QVariant::fromValue(0)) };
		Attribute a_corner_radius_br{ Attribute("Bottom-Right Corner Radius", QVariant::fromValue(0)) };
		Attribute a_fill{ Attribute("Fill", QColor(Qt::white)) };
		Attribute a_hover_fill{ Attribute("Hover Fill", QColor(Qt::lightGray), true) };
		Attribute a_margin_left{ Attribute("Left Margin", QVariant::fromValue(0)) };
		Attribute a_margin_top{ Attribute("Top Margin", QVariant::fromValue(0)) };
		Attribute a_margin_right{ Attribute("Right Margin", QVariant::fromValue(0)) };
		Attribute a_margin_bottom{ Attribute("Bottom Margin", QVariant::fromValue(0)) };
		Attribute a_outline_color{ Attribute("Outline Color", QColor(Qt::gray), true) };

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
