#ifndef SVG_H
#define SVG_H

#include <QSvgWidget>

#include "Themeable.h"

namespace Layers
{
	/*!
		The SVG class provides representation for SVG files in Layers.

		An SVG loads an SVG file into a string. To make the SVG appear on the screen, the string is passed to
		QSvgWidget::load(). The load function can be called indefinitely. Therefore, changes can be made to the SVG string
		and loaded again, allowing for theme application.

		Manipulating the SVG string itself would be punishing. To make this easier, a list of SVG elements is built from
		the string with build_svg_elements_list().

		The SVG's constructors wait to call Themeable::init_themeable() until after the SVG elements list has been built.
		This is because the SVG::init_attributes() function, which is called virtually by Themeable::init_themeable(),
		depends on the elements list.

		When a theme is applied to the SVG, the attributes are updated to values provided in the applied theme, but
		the SVG string needs to be updated with the new attribute values and passed along to QSvgWidget::load() before the
		appearance of the SVG updates. This class implements update_theme_dependencies() to ensure that this all
		happens after theme application.
	*/
	class SVG : public QSvgWidget, public Themeable
	{
		Q_OBJECT

	public:
		/*!
			Constructs an SVG from an SVG file.
		*/
		SVG(QString file_path, QWidget* parent = nullptr);

		/*!
			Copy constructs an SVG from another SVG.
		*/
		SVG(const SVG& svg_w);

		virtual void apply_theme_attributes(QMap<QString, Attribute*>& theme_attrs) override;

		/*!
			Rebuilds the SVG string from the SVG elements list.
		*/
		void rebuild_svg_str();

		void replace_all_attributes_with(SVG* svg);

		void set_hovering(bool cond = true);

		virtual void set_state(const QString& state) override;

		/*!
			Updates things that depend on the theme.

			SVG elements are updated with the newly applied theme's attribute values. Then, the SVG string is rebuilt
			from those elements. And finally, the SVG string is passed to QSvgWidget::load() to update the SVG's
			appearance.
		*/
		void update();

		Attribute a_common_color{ Attribute("Common Color", QColor(Qt::black)) };
		Attribute a_common_hover_color{ Attribute("Common Hover Color", QColor(Qt::darkGray)) };
		Attribute a_use_common_color{ Attribute("Use Common Color", QVariant::fromValue(false)) };
		Attribute a_use_common_hover_color{ Attribute("Use Common Hover Color", QVariant::fromValue(false)) };

	protected:
		/*!
			Initializes the attributes.

			This function is called by init_themeable().
		*/
		void init_attributes();

		void init_attribute_widgets();

		/*!
			Calls the QSvgWidget's update() function.
		*/
		//void issue_update();

	private:
		void init_size();

		void build_svg_elements_list();

		QString element_id(const QString& element);

		bool m_hovering{ false };

		QString m_svg_str{  };

		QStringList m_svg_elements{  };
	};
}

#endif // SVG_H
