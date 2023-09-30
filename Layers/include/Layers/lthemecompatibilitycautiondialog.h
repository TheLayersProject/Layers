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

#ifndef LTHEMECOMPATIBILITYCAUTIONDIALOG_H
#define LTHEMECOMPATIBILITYCAUTIONDIALOG_H

#include <QTableView>

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lthemelineagemodel.h>

#include "ldialog.h"
#include "ltableview.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeCompatibilityCautionDialog : public LDialog
{
	Q_OBJECT

public:
	LThemeCompatibilityCautionDialog(QWidget* parent = nullptr);

	void set_lineage_table_data(const QStringList& lineage_list);

	void set_theme_name(const QString& theme_name);

private:
	void init_attributes();

	void init_layout();

	void init_lineage_table();

	LLabel* m_message_label{ new LLabel };
	LLabel* m_table_label{ new LLabel };

	LTableView* m_lineage_table{ new LTableView };

	LThemeLineageModel m_theme_lineage_model;
};
LAYERS_NAMESPACE_END

#endif // LTHEMECOMPATIBILITYCAUTIONDIALOG_H  
