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

#ifndef LTOGGLESWITCH_H
#define LTOGGLESWITCH_H

#include <QHBoxLayout>
#include <QVBoxLayout>

#include "layers_global.h"
#include "layers_exports.h"

#include "lstatepool.h"
#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN

class LLabel;

class LAYERS_EXPORT LToggleSwitch : public LWidget
{
	Q_OBJECT

signals:
	void toggled_event(bool toggled);

public:
	LToggleSwitch(bool vertical = false, QWidget* parent = nullptr);

	void set_toggled(bool toggled);

	void setFixedHeight(int h);

	void toggle(bool emit_toggled_event = true);

	bool toggled() const;

	LAttribute a_padding_left{ LAttribute("Left Padding", 2.0) };
	LAttribute a_padding_top{ LAttribute("Top Padding", 2.0) };
	LAttribute a_padding_right{ LAttribute("Right Padding", 2.0) };
	LAttribute a_padding_bottom{ LAttribute("Bottom Padding", 2.0) };

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

private:
	void init_attributes();

	void init_layout();

	void update_layout_margins();

	void update_spacer_size();

	QHBoxLayout* m_layout_h{ nullptr };

	QVBoxLayout* m_layout_v{ nullptr };

	LWidget* m_spacer{ new LWidget };
	LWidget* m_square{ new LWidget };

	bool m_vertical{ false };

	LStatePool* m_toggle_states{ new LStatePool("Toggle", { "Toggled", "Untoggled" })};
};
LAYERS_NAMESPACE_END

#endif // LTOGGLESWITCH_H
