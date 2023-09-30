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

#ifndef LATTRIBUTEEDITORGROUP_H
#define LATTRIBUTEEDITORGROUP_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lattributeeditor.h"
#include "lbutton.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LAttributeEditorGroup : public LWidget
{
	Q_OBJECT

public:
	LAttributeEditorGroup(const QString& name, QWidget* parent = nullptr);

	void add_attribute_editor(LAttributeEditor* attribute_editor);

private:
	void init_layout();

	void set_collapsed(bool collapsed = true);

	LButton* m_collapse_button{
		new LButton(
			LGraphic(":/images/collapse_arrow_right.svg", QSize(8, 12)),
			LGraphic(":/images/collapse_arrow_down.svg", QSize(12, 8))) };

	bool m_collapsed{ true };

	LLabel* m_label{ new LLabel };

	QList<LAttributeEditor*> m_attribute_editors;

	QVBoxLayout* m_widgets_vbox{ new QVBoxLayout };
};
LAYERS_NAMESPACE_END

#endif // LATTRIBUTEEDITORGROUP_H
