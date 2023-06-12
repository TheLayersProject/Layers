#ifndef LTHEMESWIDGET_H
#define LTHEMESWIDGET_H

#include <LayersCore/layers_global.h>

#include <LayersWidgets/lbutton.h>
#include <LayersWidgets/lthemecombobox.h>

LAYERS_NAMESPACE_BEGIN
class LThemesWidget : public LWidget
{
	Q_OBJECT

public:
	LThemesWidget(QWidget* parent = nullptr);
	~LThemesWidget();

	void handle_theme_buttons_visibility();

	LButton* customize_theme_button() const;

	LButton* new_theme_button() const;

	LThemeComboBox* theme_combobox() const;

	void show_custom_theme_buttons(bool cond = true);

protected:
	void init_attributes();

private:
	void init_layout();

	LLabel* m_theme_label{ new LLabel("Theme") };

	LThemeComboBox* m_theme_combobox{ new LThemeComboBox };

	LButton* m_new_theme_button{
		new LButton(LGraphic(":/images/new_theme.svg", QSize(20, 20))) };
		
	LButton* m_customize_theme_button{
		new LButton(LGraphic(":/images/customize_theme.svg", QSize(20, 20))) };
		
	LButton* m_delete_theme_button{
		new LButton(LGraphic(":/images/delete_theme.svg", QSize(17, 20))) };
		
	LButton* m_theme_info_button{
		new LButton(LGraphic(":/images/info_theme.svg", QSize(20, 20))) };

	LWidget* m_control_separator{ new LWidget(this) };
	LWidget* m_separator_1{ new LWidget };
	LWidget* m_separator_2{ new LWidget };
	LWidget* m_spacer_1{ new LWidget };
	LWidget* m_spacer_2{ new LWidget };

	QMetaObject::Connection m_theme_buttons_handler_connection;
};
LAYERS_NAMESPACE_END

#endif // LTHEMESWIDGET_H
