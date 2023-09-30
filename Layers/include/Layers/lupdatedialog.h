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

#ifndef LUPDATEDIALOG_H
#define LUPDATEDIALOG_H

#include "layers_global.h"
#include "layers_exports.h"

#include "ldialog.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LUpdateDialog : public LDialog
{
	Q_OBJECT

public:
	LUpdateDialog(const QString& version, const QString& latest_version,
		QWidget* parent = nullptr);

private:
	void init_layout();

	LButton* m_remind_me_later_button{ new LButton("Remind Me Later") };
	LButton* m_update_button{ new LButton("Update") };

	LLabel* m_message_label;
};
LAYERS_NAMESPACE_END

#endif // LUPDATEDIALOG_H
