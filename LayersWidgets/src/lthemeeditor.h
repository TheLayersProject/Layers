#ifndef LTHEMEEDITOR_H
#define LTHEMEEDITOR_H

#include <QIntValidator>

#include <LayersCore/layers_global.h>

#include <LayersWidgets/lbutton.h>
#include <LayersWidgets/lnavigator.h>
#include <LayersWidgets/lscrollarea.h>
#include <LayersWidgets/lwidgetbuttongroup.h>

LAYERS_NAMESPACE_BEGIN
class LWidgetEditor;

class LThemeEditor : public LWidget
{
	Q_OBJECT

public:
	LThemeEditor(QWidget* parent = nullptr);

	//~LThemeEditor();

	LButton* apply_button() const;

	virtual void apply_theme(LTheme& theme) override;

	void edit_themeable(LThemeable* themeable);

	QWidget* preview_widget() const;

	void set_preview_widget(QWidget* widget);

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

private:
	void handle_sidebar_width();

	void init_layout();

	LThemeable* m_control_themeable{ new LThemeable };

	LWidgetEditor* m_control_widget_editor{ nullptr };

	LNavigator* m_navigator{ new LNavigator };

	QHBoxLayout* m_main_layout{ new QHBoxLayout };
	QVBoxLayout* m_sidebar_layout{ new QVBoxLayout };
	QHBoxLayout* m_topbar_layout{ new QHBoxLayout };
	QGridLayout* m_preview_layout{ new QGridLayout };

	LWidget* m_topbar{ new LWidget };
	LWidget* m_preview_frame = new LWidget;

	LScrollArea* m_sidebar{ new LScrollArea };
	LScrollArea* m_preview_scroll_area{ new LScrollArea };

	QWidget* m_preview_widget{ nullptr };

	QList<LThemeable*> m_open_themeables;

	LButton* m_apply_button{ new LButton("Apply") };
};
LAYERS_NAMESPACE_END

#endif // LTHEMEEDITOR_H
