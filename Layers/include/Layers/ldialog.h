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

#ifndef LDIALOG_H
#define LDIALOG_H

#include <QDialog>

#include "layers_global.h"
#include "layers_exports.h"

#include "lbutton.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LDialog : public QDialog, public LThemeableBox
{
	Q_OBJECT

public:
	LDialog(const QString& title = "Dialog", QWidget* parent = nullptr);

	void set_icon(const LGraphic& icon);

	void setLayout(QLayout* layout);

	virtual void update() override;

protected:
	virtual bool nativeEvent(
		const QByteArray& eventType, void* message, qintptr* result) override;

	virtual void paintEvent(QPaintEvent* event) override;

	QVBoxLayout* m_main_layout{ new QVBoxLayout };

private:
	void init_attributes();
	void init_layout();
	void init_titlebar();

	bool m_hovering{ false };

	QHBoxLayout* m_titlebar_layout = new QHBoxLayout;

	LWidget* m_titlebar{ new LWidget };

	LLabel* m_icon_label{ nullptr };

	LLabel* m_title_label{ nullptr };

	LButton* m_exit_button = new LButton(
		LGraphic(":/images/exit.svg", QSize(20, 20)));
};

/*!
	Moves *upper_widget* to the center of *lower_widget*.
*/
LAYERS_EXPORT void center(QWidget* upper_widget, QWidget* lower_widget);

LAYERS_NAMESPACE_END

#endif // LDIALOG_H
