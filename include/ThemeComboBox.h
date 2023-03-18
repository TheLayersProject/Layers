#ifndef THEMECOMBOBOX_H
#define THEMECOMBOBOX_H

#include "ComboBox.h"
#include "ThemeComboBoxItemModel.h"

namespace Layers
{
	class ThemeComboBox : public ComboBox
	{
		Q_OBJECT

	public:
		ThemeComboBox(QWidget* parent = nullptr);

		void addItem(Theme* value);

		void clear();

	protected:
		virtual bool eventFilter(QObject* object, QEvent* event) override;

		virtual void paintEvent(QPaintEvent* event) override;

	private:
		ThemeComboBoxItemModel* m_model{ new ThemeComboBoxItemModel };
	};
}

#endif // THEMECOMBOBOX_H
