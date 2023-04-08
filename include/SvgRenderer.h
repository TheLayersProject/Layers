#ifndef SVGRENDERER_H
#define SVGRENDERER_H

#include <QSvgRenderer>

#include "Themeable.h"

namespace Layers
{
	class SvgRenderer : public QSvgRenderer, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs an SVG from an SVG file.
		*/
		SvgRenderer(const QString& file_path, QObject* parent = nullptr);

		///*!
		//	Copy constructs an SVG from another SVG.
		//*/
		//SvgRenderer(const SvgRenderer& svg_w);

		/*!
			Rebuilds the SVG string from the SVG elements list.
		*/
		void rebuild_svg_str();

		//void set_hovering(bool cond = true);

		//virtual void set_state(const QString& state) override;

		/*!
			Updates things that depend on the theme.

			SVG elements are updated with the newly applied theme's attribute values. Then, the SVG string is rebuilt
			from those elements. And finally, the SVG string is passed to QSvgWidget::load() to update the SVG's
			appearance.
		*/
		void update();

		Attribute a_common_color{ Attribute("common_color", QColor(Qt::black)) };
		//Attribute a_common_hover_color{ Attribute("common_hover_color", QColor(Qt::darkGray)) };
		Attribute a_use_common_color{ Attribute("use_common_color", QVariant::fromValue(false)) };
		//Attribute a_use_common_hover_color{ Attribute("use_common_hover_color", QVariant::fromValue(false)) };

	private:
		/*!
			Initializes the attributes.

			This function is called by init_themeable().
		*/
		void init_attributes();


		//void init_size();

		void init_svg_elements_list();

		//QString element_id(const QString& element);

		//bool m_theming_blocked{ false };

		//bool m_hovering{ false };

		QString m_svg_str{  };

		QStringList m_svg_elements{  };
	};
}

#endif // SVGRENDERER_H
