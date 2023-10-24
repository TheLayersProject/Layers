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

#ifndef LRADIOBUTTON_H
#define LRADIOBUTTON_H

#include <QWidget>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LRadioButton : public QWidget, public LThemeable
{
	Q_OBJECT

signals:
	void clicked();

public:
	LRadioButton(QWidget* parent = nullptr);

	LStatePool* status_states() const;

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

	void paintEvent(QPaintEvent* event) override;

private:
	void init_attributes();

	LAttribute* m_active_dot_fill{
		new LAttribute("Active Dot Fill", "#000000", this) };

	LAttribute* m_border_fill{
		new LAttribute("Border.Fill", "#a0a0a4", this) };

	LAttribute* m_border_thickness{
		new LAttribute("Border.Thickness", 3.0, this) };

	LAttribute* m_fill{ new LAttribute("Fill", "#808080", this) };

	LAttribute* m_margin{ new LAttribute("Margin", 10.0, this) };

	//LStatePool* m_select_states{
	//	new LStatePool("Select", { "Selected", "Unselected" }) };

	LStatePool* m_status_states{
		new LStatePool("Status", { "Active", "Inactive" }) };
};
LAYERS_NAMESPACE_END

#endif // LRADIOBUTTON_H
