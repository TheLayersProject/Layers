#include "../../include/TabBar.h"

using Layers::TabBar;

TabBar::TabBar(QWidget* parent) : QTabBar(parent)
{
	init_attributes();

	setDrawBase(false);

	update_theme_dependencies();
}

void TabBar::SetCurrentTab(const QString& text)
{
	for (int i = 0; i < count(); i++)
		if (tabText(i) == text) setCurrentIndex(i);
}

bool TabBar::ContainsTab(const QString& text)
{
	for (int i = 0; i < count(); i++)
		if (tabText(i) == text) return true;

	return false;
}

//void TabBar::removeTab(int index)
//{
//	QTabBar::removeTab(index);
//}

void TabBar::removeTab(const QString& text)
{
	for (int i = 0; i < count(); i++)
	{
		QString TabText = tabText(i);

		if (TabText == text) QTabBar::removeTab(i);
	}
}

void TabBar::update_theme_dependencies()
{
	setStyleSheet(build_stylesheet());
}

QString TabBar::build_stylesheet()
{
	// "; border: 1px solid " + m_attribute_set.attribute_value("border_color")->as<QColor>().name() + 

	return
		"QTabBar { color: " + a_text_color.as<QColor>().name() + "; font: 12pt; }"
		//"QTabBar::tab { background: " + m_attribute_set.attribute_value("background_color")->as<QColor>().name() + "; }" // padding: 7px; padding-top: 2px; padding-bottom: 2px; border-bottom-color: none }"
		//"QTabBar::tab:!selected { margin-top: 2px; }"
		//"QTabBar::tab:!selected { background: " + m_attribute_set.attribute_value("background_color")->as<QColor>().name() + "; padding:10px; border-top-left-radius:5px; border-top-right-radius:5px; }"
		"QTabBar::tab:!selected { background:none; padding:10px; border-top-left-radius:5px; border-top-right-radius:5px; }"
		"QTabBar::tab:selected { background: " + a_selected_fill_color.as<QColor>().name() + "; padding:10px; border-top-left-radius:5px; border-top-right-radius:5px; }"
		//"QTabBar::tab:first:selected { margin-left: 0; }"
		//"QTabBar::tab:last { margin-right: 0; }"
		"QTabBar::tab:only-one { margin: 0; }"
		"QTabBar::close-button { image:url(./data/images/close_tab_before.png); margin-bottom:3px; }"
		"QTabBar::close-button:hover { image:url(./data/images/close_tab_after.png); margin-bottom:3px; }";
}

void TabBar::init_attributes()
{
	m_entities.insert({
		{ "text_color", &a_text_color },
		{ "selected_fill_color", &a_selected_fill_color }
		});

	connect(&a_selected_fill_color, &Entity::value_changed, [this] { update_theme_dependencies(); });
	connect(&a_text_color, &Entity::value_changed, [this] { update_theme_dependencies(); });
}
