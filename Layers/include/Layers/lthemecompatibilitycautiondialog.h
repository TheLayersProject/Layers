#ifndef LTHEMECOMPATIBILITYCAUTIONDIALOG_H
#define LTHEMECOMPATIBILITYCAUTIONDIALOG_H

#include <QTableView>

#include "layers_global.h"
#include "layers_exports.h"

#include <Layers/lthemelineagemodel.h>

#include "ldialog.h"
#include "ltableview.h"

LAYERS_NAMESPACE_BEGIN
class LAYERS_EXPORT LThemeCompatibilityCautionDialog : public LDialog
{
	Q_OBJECT

public:
	LThemeCompatibilityCautionDialog(QWidget* parent = nullptr);

	virtual LThemeable* clone() override;

	void set_lineage_table_data(const QStringList& lineage_list);

	void set_theme_name(const QString& theme_name);

protected:
	/*!
		Overrides the QWidget::eventFilter() to handle widget hover coloring
	*/
	//bool eventFilter(QObject* object, QEvent* event) override;

	void init_attributes();

private:
	void init_layout();

	void init_lineage_table();

	LLabel* m_message_label{ new LLabel };
	LLabel* m_table_label{ new LLabel };

	LTableView* m_lineage_table{ new LTableView };

	LThemeLineageModel m_theme_lineage_model;
};
LAYERS_NAMESPACE_END

#endif // LTHEMECOMPATIBILITYCAUTIONDIALOG_H  
