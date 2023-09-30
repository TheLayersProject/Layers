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

#ifndef LTHEMEEDITORDIALOG_H
#define LTHEMEEDITORDIALOG_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lattributeeditor.h"
#include "lattributeeditorgroup.h"
#include "ldialog.h"
#include "lgrowingdotprogressindicator.h"
#include "lscrollarea.h"
#include "lthemeview.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeEditorDialog : public LDialog
{
	Q_OBJECT

public:
	LThemeEditorDialog(QWidget* parent = nullptr);

	virtual void apply_theme_item(LThemeItem* theme_item) override;

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

public slots:
	void edit_theme_item(LThemeItem* theme_item);

	void reset_save_timer();

private:
	void init_layout();

	void clear_attr_editors();

	void update_attr_editors_max_width();

	void update_path_label();

	QVBoxLayout* m_main_layout{ new QVBoxLayout };

	QHBoxLayout* m_hbox_layout{ new QHBoxLayout };

	QVBoxLayout* m_attr_editors_layout{ new QVBoxLayout };

	QHBoxLayout* m_status_bar_layout{ new QHBoxLayout };

	LThemeView* m_theme_view{ new LThemeView };

	LWidget* m_divider{ new LWidget };

	QString m_path_text;

	LLabel* m_path_label{ new LLabel };

	LScrollArea* m_attr_editors_scroll_area{ new LScrollArea };

	QWidget* m_attr_editors_widget{ new QWidget };

	LWidget* m_status_bar{ new LWidget };

	LLabel* m_check_label{
		new LLabel(LGraphic(":/images/check.svg", QSize(16, 13))) };

	LLabel* m_status_label{ new LLabel("Saved") };

	LGrowingDotProgressIndicator* m_save_progress_indicator{
		new LGrowingDotProgressIndicator };
};
LAYERS_NAMESPACE_END

#endif // LTHEMEEDITORDIALOG_H  
