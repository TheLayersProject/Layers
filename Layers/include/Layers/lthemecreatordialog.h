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

#ifndef LCREATETHEMEDIALOG_H
#define LCREATETHEMEDIALOG_H

#include "layers_global.h"
#include "layers_exports.h"

#include "ldialog.h"
#include "llineeditor.h"
#include "lthemecombobox.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeCreatorDialog : public LDialog
{
	Q_OBJECT

public:
	LThemeCreatorDialog(QWidget* parent = nullptr);

public slots:
	virtual int	exec() override;

private slots:
	void create_theme();

private:
	void init_attributes();
	void init_layout();

	LLabel* m_name_label{ new LLabel("Name") };

	LLineEditor* m_name_editor{ new LLineEditor };

	LLabel* m_parent_theme_label{ new LLabel("Parent Theme") };

	LThemeComboBox* m_parent_theme_combobox{ new LThemeComboBox };

	LButton* m_create_button{
		new LButton(LGraphic(":/images/check.svg", QSize(16, 13)), "Create") };
};
LAYERS_NAMESPACE_END

#endif // LCREATETHEMEDIALOG_H
