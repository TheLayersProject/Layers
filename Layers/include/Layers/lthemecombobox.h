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

#ifndef LTHEMECOMBOBOX_H
#define LTHEMECOMBOBOX_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lcombobox.h"
#include "lthemecompatibilitycautiondialog.h"

LAYERS_NAMESPACE_BEGIN
class LTheme;
class LThemeComboBoxItemModel;

class LAYERS_EXPORT LThemeComboBox : public LComboBox
{
	Q_OBJECT

public:
	LThemeComboBox(QWidget* parent = nullptr);

	void add_theme(LTheme* theme, bool set_as_current_index = false);

	void clear();

protected:
	virtual bool eventFilter(QObject* object, QEvent* event) override;

	virtual void paintEvent(QPaintEvent* event) override;

private:
	void init_item_delegate();

	LThemeComboBoxItemModel* m_model;

	LThemeCompatibilityCautionDialog* m_compatibility_dialog{
		new LThemeCompatibilityCautionDialog };

	int m_highlighted_index = -1;
};
LAYERS_NAMESPACE_END

#endif // LTHEMECOMBOBOX_H
