#include <Layers/lthemeview.h>

#include <QEvent>
#include <QPainter>

#include <Layers/lapplication.h>
#include <Layers/lthememodel.h>

using Layers::LThemeable;
using Layers::LThemeView;

LThemeView::LThemeView(QWidget* parent) :
	QTreeView(parent)
{
	set_name("Theme View");

	m_model->set_theme(activeTheme());

	m_model_update_connection =
		connect(layersApp, &LApplication::active_theme_changed, [this]
			{ m_model->set_theme(activeTheme()); });

	setHeaderHidden(true);
	setHorizontalScrollBar(m_horizontal_scrollbar);
	setModel(m_model);
	setVerticalScrollBar(m_vertical_scrollbar);

	m_horizontal_scrollbar->set_name("Horizontal ScrollBar");

	m_vertical_scrollbar->set_name("Vertical ScrollBar");
	
	update();
}

LThemeView::~LThemeView()
{
	disconnect(m_model_update_connection);
}

QList<LThemeable*> LThemeView::child_themeables(Qt::FindChildOptions options)
{
	QList<LThemeable*> child_themeables = LThemeable::child_themeables(options);

	child_themeables.append(m_horizontal_scrollbar);
	child_themeables.append(m_vertical_scrollbar);

	return child_themeables;
}

void LThemeView::update()
{
	QString style_sheet =
		"QAbstractItemView {"
		"background: " + m_fill->as<QColor>().name() + ";"
		"border: none;"
		"}"

		"QAbstractItemView::item {"
		"height: 40px;"
		"color: " + m_text_color->as<QColor>().name() + ";"
		"}";

	setStyleSheet(
		style_sheet
	);

	QWidget::update();
}

void LThemeView::selectionChanged(
	const QItemSelection& selected,
	const QItemSelection& deselected)
{
	QModelIndexList indexes = selected.indexes();

	if (!indexes.isEmpty())
		emit selection_changed(
			indexes.first().data(Qt::UserRole).value<LThemeItem*>());
}
