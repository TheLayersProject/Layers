#ifndef ATTRIBUTEWIDGET_H
#define ATTRIBUTEWIDGET_H

#include "Button.h"
#include "ColorControl.h"
#include "Combobox.h"
#include "GradientControl.h"
#include "FillControl.h"
#include "Graphic.h"
#include "Label.h"
#include "LineEditor.h"
#include "MiniSlider.h"
#include "ToggleSwitch.h"

namespace Layers
{
	class AttributeWidget : public Widget
	{
		Q_OBJECT

	public:
		AttributeWidget(QWidget* parent = nullptr);

	public slots:
		virtual void set_current_editting_state(const QString& state);

	protected:
		void init_attributes();
	};

	class StateAW : public AttributeWidget
	{
		Q_OBJECT

	public:
		StateAW(QWidget* parent = nullptr);

		void add_attribute_widget(AttributeWidget* attribute_widget);

		Combobox* state_combobox() const;

		void replace_all_attributes_with(StateAW* state_aw);

		void populate_state_combobox(const QList<QString>& states);

	protected:
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		Combobox* m_state_combobox{ new Combobox };

		Label* m_label{ new Label("State")};

		QList<AttributeWidget*> m_child_attribute_widgets{ QList<AttributeWidget*>() };

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		QVBoxLayout* m_widgets_vbox{ new QVBoxLayout };
	};

	class AWGroup : public AttributeWidget
	{
		Q_OBJECT

	public:
		AWGroup(const QString& label_text, QWidget* parent = nullptr);

		void add_attribute_widget(AttributeWidget* attribute_widget);

		void replace_all_attributes_with(AWGroup* aw_group);

	public slots:
		virtual void set_current_editting_state(const QString& state) override;

	protected:
		void init_child_themeable_reference_list();

	private:
		void setup_layout();

		Button* m_collapse_button{ new Button(new Graphic(":/svgs/collapse_arrow_right.svg", QSize(8, 12)), new Graphic(":/svgs/collapse_arrow_down.svg", QSize(12, 8)), true) };

		bool m_collapsed{ true };

		Label* m_label{ nullptr };

		QList<AttributeWidget*> m_child_attribute_widgets{ QList<AttributeWidget*>() };

		QVBoxLayout* m_widgets_vbox{ new QVBoxLayout };
	};

	class CornerRadiiAW : public AWGroup
	{
		Q_OBJECT

	public:
		CornerRadiiAW(AttributeGroup* corner_radii_ag, QWidget* parent = nullptr);

		void replace_all_attributes_with(CornerRadiiAW* corner_radii_aw);

		MiniSlider* tl_slider() const;
		MiniSlider* tr_slider() const;
		MiniSlider* bl_slider() const;
		MiniSlider* br_slider() const;

	public slots:
		void set_current_editting_state(const QString& state);

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

	class ColorAW : public AttributeWidget
	{
		Q_OBJECT

	public:
		ColorAW(Attribute* attribute, QWidget* parent = nullptr);

		ColorControl* color_control() const;

		void replace_all_attributes_with(ColorAW* color_aw);

		void set_centered(bool centered = true);

	public slots:
		void set_current_editting_state(const QString& state);

	protected:
		void init_child_themeable_reference_list();

	private:
		bool m_centered{ false };

		ColorControl* m_color_control{ new ColorControl };

		Label* m_attribute_label;

		ToggleSwitch* m_disabled_toggle{ nullptr };

		Widget* m_left_stretch{ new Widget };
		Widget* m_right_stretch{ new Widget };
	};

	class GradientAW : public AttributeWidget
	{
		Q_OBJECT

	public:
		GradientAW(const QString& attribute_label_text, Attribute* attribute, QWidget* parent = nullptr);

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

	class FillAW : public AttributeWidget
	{
		Q_OBJECT

	public:
		FillAW(Attribute* attribute, QWidget* parent = nullptr);

		FillControl* fill_control() const;

		void replace_all_attributes_with(FillAW* fill_aw);

		void set_centered(bool centered = true);

	public slots:
		virtual void set_current_editting_state(const QString& state) override;

	protected:
		void init_child_themeable_reference_list();

	private:
		bool m_centered{ false };

		FillControl* m_fill_control{ new FillControl };

		Label* m_attribute_label;

		ToggleSwitch* m_disabled_toggle{ nullptr };

		Widget* m_left_stretch{ new Widget };
		Widget* m_right_stretch{ new Widget };
	};

	class NumberAW : public AttributeWidget
	{
		Q_OBJECT

	public:
		NumberAW(Attribute* attribute, QIntValidator* int_validator, QWidget* parent = nullptr);

		void replace_all_attributes_with(NumberAW* number_aw);

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

		QVBoxLayout* m_main_layout{ new QVBoxLayout };

		MiniSlider* m_slider{ nullptr };

		Widget* m_left_stretch{ new Widget };
		Widget* m_right_stretch{ new Widget };
	};
}

#endif // ATTRIBUTEWIDGET_H
