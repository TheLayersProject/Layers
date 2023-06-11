#ifndef LGRADIENTDIALOG_H
#define LGRADIENTDIALOG_H

#include <QTimer>

#include "layerswidgetsexports.h"

#include "lbutton.h"
#include "lcolorcontrol.h"
#include "ldialog.h"

namespace Layers
{
	class LAYERS_WIDGETS_EXPORT LGradientDialog : public LDialog
	{
		Q_OBJECT

	public:
		LGradientDialog(QWidget* parent = nullptr);

		void add_gradient_stop(double stop_val, QColor color);

		virtual LThemeable* clone() override;

		QGradientStops gradient_stops() const;

		void set_gradient_stops(QGradientStops gradient_stops);

		void update_gradient();

	public slots:
		void click_control();
		void update_color_control_positions();

	protected:
		bool eventFilter(QObject* object, QEvent* event) override;

		void init_attributes();

	private:
		void init_color_controls();

		void init_layout();

		LWidget* m_gradient_widget{ new LWidget };

		QGradientStops m_gradient_stops{ {0.0, Qt::white},{1.0, Qt::black} };

		QList<LColorControl*> m_color_controls;

		LButton* m_apply_button{ new LButton("Apply") };

		LColorControl* m_selected_color_control{ nullptr };
		LColorControl* m_clicking_color_control{ nullptr };

		QPoint m_selection_start_point;

		int m_selected_control_start_x{ 0 };

		QTimer m_single_click_timer;

		bool m_moved{ false };
	};
}

#endif // LGRADIENTDIALOG_H
