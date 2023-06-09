#ifndef THEMECOMBOBOX_H
#define THEMECOMBOBOX_H

#include "ComboBox.h"

namespace Layers
{
	class ThemeComboBoxItemModel;

	/*!
		A ThemeComboBox is a ComboBox that displays Theme items.

		Each item displays two pieces of theme metadata: the theme's name and
		its UUID.
	*/
	class ThemeComboBox : public ComboBox
	{
		Q_OBJECT

	public:
		/*!
			Constructs a theme combo box.
		*/
		ThemeComboBox(QWidget* parent = nullptr);

		/*!
			Adds a theme to the combo box's item model.
		*/
		void addItem(Theme* theme);

		/*!
			Clears the combo box's item model.
		*/
		void clear();

	protected:
		virtual bool eventFilter(QObject* object, QEvent* event) override;

		virtual void paintEvent(QPaintEvent* event) override;

	private:
		ThemeComboBoxItemModel* m_model;
	};
}

#endif // THEMECOMBOBOX_H
