#ifndef ATTRIBUTEWIDGET_H
#define ATTRIBUTEWIDGET_H

#include "Button.h"
#include "ColorControl.h"
#include "GradientControl.h"
#include "Graphic.h"
#include "Label.h"
#include "LineEditor.h"
#include "MiniSlider.h"
#include "Slider.h"
#include "ToggleSwitch.h"

namespace Layers
{
	class AttributeWidget : public Widget
	{
		Q_OBJECT

	public:
		AttributeWidget(bool is_primary, QWidget* parent = nullptr);

		virtual void enable_secondary_background_color(bool cond = true);

		bool is_primary() const;

		void set_primary(bool is_primary = true);

	protected:
		void init_attributes();

		void paintEvent(QPaintEvent* event) override;

		StatefulAttribute* m_stateful_attribute{ nullptr };
		StatelessAttribute* m_stateless_attribute{ nullptr };

	private:
		bool m_is_primary;
	};

	class AttributeWidgetContainer : public AttributeWidget
	{
		Q_OBJECT

	public:
		AttributeWidgetContainer(const QString& label_text, bool is_primary, QWidget* parent = nullptr);

		void add_attribute_widget(AttributeWidget* attribute_widget);

		void enable_secondary_background_color(bool cond = true);

	protected:
		void init_attributes();
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		Button* m_collapse_button{ new Button(new Graphic(":/svgs/collapse_arrow_right.svg", QSize(8, 12)), new Graphic(":/svgs/collapse_arrow_down.svg", QSize(12, 8)), true) };

		bool m_collapsed{ true };

		Label* m_label;

		QList<AttributeWidget*> m_child_attribute_widgets{ QList<AttributeWidget*>() };

		QVBoxLayout* m_widgets_vbox{ new QVBoxLayout };
	};

	class CornerRadiiAttributeWidget : public AttributeWidgetContainer
	{
		Q_OBJECT

	public:
		CornerRadiiAttributeWidget(Themeable* themeable, bool is_primary, QWidget* parent = nullptr);

		MiniSlider* tl_slider() const;
		MiniSlider* tr_slider() const;
		MiniSlider* bl_slider() const;
		MiniSlider* br_slider() const;

	protected:
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		AttributeWidget* m_attribute_widget;

		MiniSlider* m_tl_slider{ new MiniSlider(30) };
		MiniSlider* m_tr_slider{ new MiniSlider(30) };
		MiniSlider* m_bl_slider{ new MiniSlider(30) };
		MiniSlider* m_br_slider{ new MiniSlider(30) };

		LineEditor* m_tl_line_editor{ new LineEditor };
		LineEditor* m_tr_line_editor{ new LineEditor };
		LineEditor* m_bl_line_editor{ new LineEditor };
		LineEditor* m_br_line_editor{ new LineEditor };

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		Widget* m_example_widget{ new Widget };
	};

	class ColorAttributeWidget : public AttributeWidget
	{
		Q_OBJECT

	public:
		ColorAttributeWidget(const QString& attribute_label_text, Attribute* attribute, bool is_primary, QWidget* parent = nullptr);
		ColorAttributeWidget(const QString& attribute_label_text, Attribute* attribute, Attribute* disabling_attribute, bool is_primary, QWidget* parent = nullptr);

		ColorControl* color_control() const;

		void set_centered(bool centered = true);

	protected:
		void init_child_themeable_reference_list();

	private:
		Attribute* m_disabling_attribute{ nullptr };

		bool m_centered{ false };

		ColorControl* m_color_control{ new ColorControl };

		Label* m_attribute_label;

		ToggleSwitch* m_disabled_attribute_toggle{ nullptr };

		Widget* m_left_stretch{ new Widget };
		Widget* m_right_stretch{ new Widget };
	};

	class GradientAttributeWidget : public AttributeWidget
	{
		Q_OBJECT

	public:
		GradientAttributeWidget(const QString& attribute_label_text, Attribute* attribute, bool is_primary, QWidget* parent = nullptr);

		void set_centered(bool centered = true);

	protected:
		void init_child_themeable_reference_list();

	private:
		bool m_centered{ false };

		GradientControl* m_gradient_control{ new GradientControl };

		Label* m_attribute_label;

		Widget* m_left_stretch{ new Widget };
		Widget* m_right_stretch{ new Widget };
	};

	class NumberAttributeWidget : public AttributeWidget
	{
		Q_OBJECT

	public:
		NumberAttributeWidget(const QString& attribute_label_text, Attribute* attribute, QIntValidator* int_validator, bool is_primary, QWidget* parent = nullptr);

		void enable_silder();

		void set_centered(bool centered = true);

		void set_unit_label_text(const QString& unit_string);

	protected:
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		bool m_centered{ false };

		Label* m_attribute_label{ nullptr };
		Label* m_unit_label{ new Label };

		LineEditor* m_line_editor{ new LineEditor };

		QIntValidator* m_int_validator{ nullptr };

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		Slider* m_slider{ nullptr };

		Widget* m_left_stretch{ new Widget };
		Widget* m_right_stretch{ new Widget };
	};

	// Control attribute currently not setup to work with stateful attributes; Not sure if needed
	class SwitchAttributeWidget : public AttributeWidget
	{
		Q_OBJECT

	public:
		SwitchAttributeWidget(
			const QString& first_label_text, AttributeWidget* first_attribute_widget,
			const QString& second_label_text, AttributeWidget* second_attribute_widget,
			StatelessAttribute* control_attribute, bool is_primary, QWidget* parent = nullptr);

		void apply_theme(Theme& theme);

		void enable_secondary_background_color(bool cond = true);

	private:
		StatelessAttribute* m_control_attribute;

		AttributeWidget* m_first_attribute_widget;
		AttributeWidget* m_second_attribute_widget;

		ToggleSwitch* m_labeled_toggle_switch;
	};
}

#endif // ATTRIBUTEWIDGET_H
