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

#ifndef LSETTINGSTAB_H
#define LSETTINGSTAB_H

#include <QHBoxLayout>

#include <Layers/layers_global.h>

#include <Layers/lwidget.h>

LAYERS_NAMESPACE_BEGIN
class LLabel;
class LThemesWidget;

class LSettingsTab : public LWidget
{
	Q_OBJECT

signals:
	void clicked();

public:
	LSettingsTab(const LGraphic& icon, const QString& label_text, QWidget* parent = nullptr);

	int recommended_minimum_width();

	LStatePool* select_states() const;

	void set_disabled(bool cond = true);

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

	void init_attributes();

	//void resizeEvent(QResizeEvent* event);

private:
	void init_layout();

	QHBoxLayout* main_layout{ new QHBoxLayout };

	bool m_disabled{ false };

	LLabel* m_icon_label;

	LLabel* m_text_label;

	LStatePool* m_select_states{
		new LStatePool("Select", { "Selected", "Unselected" }) };
};
LAYERS_NAMESPACE_END

#endif // LSETTINGSTAB_H
