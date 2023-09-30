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

#ifndef LTAB_H
#define LTAB_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lbutton.h"
#include "llabel.h"
#include "lstatepool.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LTab : public LWidget
{
	Q_OBJECT

signals:
	void clicked();

	void closed();

public:
	LTab(const LGraphic& icon, const QString& text, QWidget* parent = nullptr);

	LTab(const QString& text, QWidget* parent = nullptr);

	LButton* close_button() const;

	LLabel* icon_label() const;

	LStatePool* status_states() const;

	LLabel* text_label() const;

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

private:
	void init();
	void init_attributes();
	void init_layout();

	QHBoxLayout* main_layout = new QHBoxLayout;

	LButton* m_close_button
		{ new LButton(LGraphic(":/images/tab_exit.svg", QSize(16, 17))) };

	LLabel* m_icon_label{ nullptr };

	LLabel* m_text_label{ nullptr };

	LStatePool* m_status_states
		{ new LStatePool("Status", { "Active", "Inactive" })};
};
LAYERS_NAMESPACE_END

#endif // LTAB_H
