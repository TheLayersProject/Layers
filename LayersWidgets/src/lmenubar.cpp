#include <LayersWidgets/lmenubar.h>

#include <QStyleOptionMenuItem>

using Layers::LAttribute;
using Layers::LMenuBar;

LMenuBar::LMenuBar(QWidget* parent) : QMenuBar(parent)
{
	init_attributes();

	QFont MainMenuFont = font();
	MainMenuFont.setPointSize(12);

	setFont(MainMenuFont);

    update_theme_dependencies();
}

void LMenuBar::init_attributes()
{
    m_attributes.insert({
        { "text_color", m_text_color },
        { "selected_text_color", m_selected_text_color }
        });

    connect(m_text_color, &LAbstractAttribute::changed,
		[this] { update_theme_dependencies(); });
    connect(m_selected_text_color, &LAbstractAttribute::changed,
		[this] { update_theme_dependencies(); });
}

void LMenuBar::update_theme_dependencies()
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
