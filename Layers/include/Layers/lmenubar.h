#ifndef LMENUBAR_H
#define LMENUBAR_H

#include <QMenuBar>

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lthemeable.h>

LAYERS_NAMESPACE_BEGIN
/*!
	An LMenuBar is a QMenuBar and a LThemeable that provides a menu bar that
	consists of a list of pull-down menu items.
*/
class LAYERS_EXPORT LMenuBar : public QMenuBar, public LThemeable
{
	Q_OBJECT

public:
	/*!
		Constructs a menu bar.
	*/
	LMenuBar(QWidget* parent = nullptr);

	/*!
		Returns a pointer to the selected text color attribute of the menu bar.
	*/
	LAttribute* selected_text_color() const;

	/*!
		Returns a pointer to the text color attribute of the menu bar.
	*/
	LAttribute* text_color() const;

	virtual void update() override;

private:
	QString build_stylesheet();

	LAttribute* m_selected_text_color{
		new LAttribute("selected_text_color", QColor(Qt::lightGray), this) };

	LAttribute* m_text_color{
		new LAttribute("Text Color", QColor(Qt::gray), this) };
};
LAYERS_NAMESPACE_END

#endif // LMENUBAR_H
