#ifndef THEMECOMPATIBILITYCAUTIONDIALOG_H
#define THEMECOMPATIBILITYCAUTIONDIALOG_H

#include <QTableView>

#include "Dialog.h"
#include "TableView.h"
#include "ThemeLineageModel.h"

namespace Layers
{
	class ThemeCompatibilityCautionDialog : public Dialog
	{
		Q_OBJECT

	public:
		ThemeCompatibilityCautionDialog(QWidget* parent = nullptr);

		virtual Themeable* clone() override;

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

		Label* m_message_label{ new Label };
		Label* m_table_label{ new Label };

		TableView* m_lineage_table{ new TableView };

		ThemeLineageModel m_theme_lineage_model;
	};
}

#endif // THEMECOMPATIBILITYCAUTIONDIALOG_H  
