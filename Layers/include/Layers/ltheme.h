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

#ifndef LTHEME_H
#define LTHEME_H

#include <QDataStream>
#include <QDir>
#include <QJsonDocument>
#include <QString>
#include <QUuid>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeitem.h"

LAYERS_NAMESPACE_BEGIN

class LAttribute;

struct LAYERS_EXPORT LThemeLineageData
{
	QString name;
	QString uuid;
	bool has_app_implementation_available = false;
};

class LAYERS_EXPORT LTheme
{
public:
	LTheme();

	LTheme(QDir dir);

	LTheme(const QString& name, bool editable = true);

	LTheme(const QString& name, QUuid uuid, bool editable);

	~LTheme();

	void append_to_lineage(const QString& theme_id);

	void clear();

	QDir dir() const;

	QString display_id() const;

	bool editable() const;

	LThemeItem* find_item(const QString& path);

	LThemeItem* find_item(const QStringList& name_list);

	bool has_implementation(const QString& app_display_id) const;

	QStringList lineage() const;

	void load(const QString& app_id);

	QString name() const;

	QString publisher() const;

	LThemeItem* root_item() const;

	void save();

	void save_meta_file();

	void set_dir(QDir dir);

	void set_name(const QString& new_name);

	QUuid uuid() const;

private:
	void load_file(QFile& document_file);

	void load_dir(const QDir& dir);

	LThemeItem* init_item(const QString& name,
		QJsonObject item_object, const QString& file_name,
		LThemeItem* parent = nullptr);

	void resolve_links(LThemeItem* item);

	void resolve_parents();

	LThemeItem* m_root_item{ nullptr };

	QMap<QString, LThemeItem*> m_unparented_theme_items;

	QMap<QString, QList<LThemeItem*>> m_file_items;

	QDir m_dir;

	bool m_editable{ true };

	QStringList m_lineage;

	QString m_name;

	QString m_publisher;

	QUuid m_uuid;
};
LAYERS_NAMESPACE_END

#endif // LTHEME_H
