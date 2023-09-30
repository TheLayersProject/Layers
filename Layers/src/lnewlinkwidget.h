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

#ifndef LNEWLINKWIDGET
#define LNEWLINKWIDGET

#include <Layers/layers_global.h>

#include <Layers/lattributemapview.h>
#include <Layers/lbutton.h>
#include <Layers/llineeditor.h>
#include <Layers/lresizer.h>
#include <Layers/lsplitter.h>
#include <Layers/lthemeview.h>
#include <Layers/lwidget.h>

LAYERS_NAMESPACE_BEGIN
class LNewLinkWidget : public LWidget
{
	Q_OBJECT

signals:
	void visibility_changed(bool is_visible);

public:
	LNewLinkWidget(LAttribute* attr, QWidget* parent = nullptr);

private:
	void init_layout();

	LAttribute* m_attr;

	LAttribute* m_selected_link_attr;

	QVBoxLayout* m_main_layout{ new QVBoxLayout };

	LSplitter* m_splitter{ new LSplitter };

	LThemeView* m_theme_view{ new LThemeView };

	LAttributeMapView* m_attr_map_view{ new LAttributeMapView };

	LLineEditor* m_path_editor{ new LLineEditor };

	LButton* m_apply_link_button{
		new LButton(
			LGraphic(":/images/check.svg", QSize(16, 13)), "Apply Link") };

	LButton* m_cancel_button{
		new LButton(
			LGraphic(":/images/tab_exit.svg", QSize(16, 17)), "Cancel") };

	LResizer* m_resizer{ new LResizer(LSizeDimension::Height) };
};
LAYERS_NAMESPACE_END

#endif // LNEWLINKWIDGET
