#include <Layers/lmenubar.h>

#include <QStyleOptionMenuItem>

using Layers::LAttribute;
using Layers::LMenuBar;

LMenuBar::LMenuBar(QWidget* parent) : QMenuBar(parent)
{
	QFont MainMenuFont = font();
	MainMenuFont.setPointSize(12);

	setFont(MainMenuFont);

    update();
}

void LMenuBar::update()
{
	setStyleSheet(build_stylesheet());
}

LAttribute* LMenuBar::selected_text_color() const
{
    return m_selected_text_color;
}

LAttribute* LMenuBar::text_color() const
{
    return m_text_color;
}

QString LMenuBar::build_stylesheet()
{
	return
		"QMenuBar {"
		"background: transparent;"
		"color: " + m_text_color->as<QColor>().name() + ";"
		"}"

		"QMenuBar::item {"
		"spacing: 3px;"
		"padding: 1px 4px;"
		"background: transparent;"
		"color: " + m_text_color->as<QColor>().name() + ";"
		"}"

		"QMenuBar::item:selected {"
		"background: transparent;"
		"color: " + m_selected_text_color->as<QColor>().name() + ";"
		"}"

		"QMenuBar::item:pressed {"
		"background: transparent;"
		"}";
}
