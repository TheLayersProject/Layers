/*
 * Copyright (C) 2023 The Layers Project
 *
 * This file is part of Layers.
 *
 * Layers is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Layers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Layers. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef LTHEMESWIDGET_H
#define LTHEMESWIDGET_H

#include <Layers/layers_global.h>

#include <Layers/lbutton.h>
#include <Layers/lthemecombobox.h>

LAYERS_NAMESPACE_BEGIN
class LThemeEditorDialog;

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

	LWidget* m_separator_1{ new LWidget };
	LWidget* m_separator_2{ new LWidget };
	LWidget* m_spacer_1{ new LWidget };
	LWidget* m_spacer_2{ new LWidget };

	QMetaObject::Connection m_theme_buttons_handler_connection;

	LThemeEditorDialog* m_theme_editor_dialog{ nullptr };
};
LAYERS_NAMESPACE_END

#endif // LTHEMESWIDGET_H
