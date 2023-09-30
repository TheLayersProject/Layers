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

#ifndef LSETTINGSMENU_H
#define LSETTINGSMENU_H

#include <QHBoxLayout>
#include <QVBoxLayout>

#include <Layers/layers_global.h>

#include <Layers/lwidget.h>

LAYERS_NAMESPACE_BEGIN

class LLabel;
class LSettingsTab;
class LThemesWidget;

class LSettingsMenu : public LWidget
{
	Q_OBJECT

public:
	LSettingsMenu(QWidget* parent = nullptr);

	void add_settings_tab(const LGraphic& icon, const QString& label_text);

	int largest_tab_index() const;

	int recommended_minimum_tab_width() const;

	LThemesWidget* themes_widget() const;

private:
	void init_layout();

	QVBoxLayout* m_sidebar_layout = new QVBoxLayout;

	QList<LSettingsTab*> m_settings_tabs;

	LWidget* m_sidebar{ new LWidget };

	LThemesWidget* m_themes_widget;
};
LAYERS_NAMESPACE_END

#endif // LSETTINGSMENU_H
