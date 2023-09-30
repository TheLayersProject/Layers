#ifndef LMENUBAR_H
#define LMENUBAR_H

#include <QMenuBar>

#include "layers_global.h"
#include "layers_exports.h"

#include "lthemeable.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LMenuBar : public QMenuBar, public LThemeable
{
	Q_OBJECT

public:
	LMenuBar(QWidget* parent = nullptr);

	LAttribute* selected_text_color() const;

	LAttribute* text_color() const;

	virtual void update() override;

private:
	QString build_stylesheet();

	LAttribute* m_selected_text_color
		{ new LAttribute("selected_text_color", QColor(Qt::lightGray), this) };

	LAttribute* m_text_color
		{ new LAttribute("Text Color", QColor(Qt::gray), this) };
};
LAYERS_NAMESPACE_END

#endif // LMENUBAR_H
