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

#ifndef LMAINWINDOW_H
#define LMAINWINDOW_H

#include <QVBoxLayout>

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class Menu;
class LSettingsMenu;
class LMainWindowTitlebar;

class LAYERS_EXPORT LMainWindow : public LWidget
{
	Q_OBJECT

public:
	LMainWindow(QWidget* parent = nullptr);

	void open_central_widget(QWidget* central_widget);

	void open_central_widget(
		QWidget* central_widget, const LGraphic& tab_icon_graphic);

	virtual void update() override;

protected:
	virtual bool nativeEvent(
		const QByteArray& eventType, void* message, qintptr* result) override;

private slots:
	void new_theme_clicked();

private:
	void init_attributes();
	void init_layout();
	void init_titlebar_connections();

	void _open_central_widget(QWidget* central_widget);

	void set_active_central_widget(QWidget* central_widget);

	QVBoxLayout* m_main_layout{ new QVBoxLayout };

	LMainWindowTitlebar* m_titlebar;

	LWidget* m_separator{ new LWidget };

	QList<QWidget*> m_central_widgets;
};
LAYERS_NAMESPACE_END

#endif // LMAINWINDOW_H
