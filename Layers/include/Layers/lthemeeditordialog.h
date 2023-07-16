#ifndef LTHEMEEDITORDIALOG_H
#define LTHEMEEDITORDIALOG_H

#include "layers_global.h"
#include "layers_exports.h"

#include "lattributeeditor.h"
#include "lattributeeditorgroup.h"
#include "ldialog.h"
#include "lscrollarea.h"
#include "lthemeabletreeview.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeEditorDialog : public LDialog
{
	Q_OBJECT

public:
	LThemeEditorDialog(QWidget* parent = nullptr);

	void init_root_themeable();

	bool is_root_themeable_set() const;

protected:
	bool eventFilter(QObject* object, QEvent* event) override;

public slots:
	void edit_themeable(LThemeable* themeable);

private:
	void init_layout();

	void clear_attr_editors();

	void update_attr_editors_max_width();

	void update_tag_label();

	bool m_is_root_themeable_set{ false };

	QHBoxLayout* m_main_layout{ new QHBoxLayout };

	QVBoxLayout* m_attr_editors_layout{ new QVBoxLayout };

	LThemeableTreeView* m_themeable_tree_view{ new LThemeableTreeView };

	LWidget* m_divider{ new LWidget };

	QString m_tag_text;

	LLabel* m_tag_label{ new LLabel };

	LScrollArea* m_attr_editors_scroll_area{ new LScrollArea };

	QWidget* m_attr_editors_widget{ new QWidget };

	LAttributeEditor* m_control_attr_editor{
		new LAttributeEditor(nullptr, this) };

	LAttributeEditorGroup* m_control_attr_editor_group{
		new LAttributeEditorGroup("", this) };
};
LAYERS_NAMESPACE_END

#endif // LTHEMEEDITORDIALOG_H  
