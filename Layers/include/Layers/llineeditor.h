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

#ifndef LLINEEDITOR_H
#define LLINEEDITOR_H

#include <QLineEdit>

#include "layers_global.h"
#include "layers_exports.h"

#include "lwidget.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LLineEditor : public LWidget
{
	Q_OBJECT

signals:
	void text_edited(const QString& text);

public:
	LLineEditor(QWidget* parent = nullptr);

	~LLineEditor();

	LAttribute* left_padding() const;

	void set_default_value(const QString& default_value);

	void set_font_size(int size);

	void set_font_size_f(qreal size);

	void set_text(const QString& text);

	void set_validator(const QValidator* validator);

	LAttribute* text() const;

	LAttribute* text_color() const;

	virtual void update() override;

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

private:
	void init_attributes();

	LAttribute* m_left_padding
		{ new LAttribute("left_padding", 3.0) };

	LAttribute* m_text_color
		{ new LAttribute("Text Color", "#000000", this) };

	LAttribute* m_text
		{ new LAttribute("text", std::string("")) };

	QString* m_default_value{ nullptr };

	QLineEdit* m_line_edit{ new QLineEdit(this) };
};
LAYERS_NAMESPACE_END

#endif // LLINEEDITOR_H
