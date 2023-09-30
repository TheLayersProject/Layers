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

#ifndef LATTRIBUTEEDITOR_H
#define LATTRIBUTEEDITOR_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lbutton.h"
#include "lfillcontrol.h"
#include "llabel.h"
#include "llineeditor.h"
#include "lminislider.h"
#include "ltabbar.h"
#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LLinksView;
class LNewLinkWidget;

class LAYERS_EXPORT LAttributeEditor : public LWidget
{
	Q_OBJECT

public:
	LAttributeEditor(LAttribute* attr, QWidget* parent = nullptr);

	~LAttributeEditor();

	virtual QList<LThemeable*> child_themeables(
		Qt::FindChildOptions options = Qt::FindDirectChildrenOnly
	) override;

	LFillControl* fill_control() const;

	LLineEditor* line_editor() const;

	LMiniSlider* slider() const;

private:
	void init_attributes();
	void init_layout();

	void update_icon_labels();

	LAttribute* m_attr;

	QHBoxLayout* m_controls_layout{ new QHBoxLayout };
	QHBoxLayout* m_icons_layout{ new QHBoxLayout };
	QHBoxLayout* m_links_buttons_layout{ new QHBoxLayout };
	QVBoxLayout* m_links_layout{ new QVBoxLayout };
	QVBoxLayout* m_overrides_layout{ new QVBoxLayout };

	LFillControl* m_fill_control{ new LFillControl };

	LLabel* m_label{ new LLabel };

	LMiniSlider* m_slider{ new LMiniSlider };

	LLineEditor* m_line_editor{ new LLineEditor };

	LLabel* m_link_icon_label =
		new LLabel(LGraphic(":/images/chain_link.svg", QSize(8, 18)));

	LLabel* m_overrides_icon_label =
		new LLabel(LGraphic(":/images/overrides_icon.svg", QSize(10, 18)));

	LButton* m_collapse_button{
		new LButton(
			LGraphic(":/images/collapse_arrow_right.svg", QSize(8, 12)),
			LGraphic(":/images/collapse_arrow_down.svg", QSize(12, 8))) };

	LWidget* m_icons_widget{ new LWidget };

	LTabBar* m_features_tab_bar{ new LTabBar };

	QWidget* m_features_widget{ new QWidget };

	LLinksView* m_links_view;

	LNewLinkWidget* m_new_link_widget{ nullptr };

	QMetaObject::Connection m_attr_link_changed_connection;
	QMetaObject::Connection m_new_link_widget_destroyed_connection;

	LWidget* m_links_widget{ new LWidget };

	LWidget* m_overrides_widget{ new LWidget };

	LButton* m_new_link_button{
		new LButton(
			LGraphic(":/images/new_theme.svg", QSize(18, 18)), "New Link") };

	LButton* m_break_link_button{
		new LButton(
			LGraphic(":/images/tab_exit.svg", QSize(16, 17)), "Break Link") };

	LStatePool* m_status_states{
		new LStatePool("Status", { "Active", "Inactive" }) };
};
LAYERS_NAMESPACE_END

#endif // LATTRIBUTEEDITOR_H
