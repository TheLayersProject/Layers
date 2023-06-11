#ifndef LTHEMECOMBOBOX_H
#define LTHEMECOMBOBOX_H

#include "layerswidgetsexports.h"

#include "lcombobox.h"

namespace Layers
{
	class LThemeComboBoxItemModel;

	/*!
		A LThemeComboBox is a LComboBox that displays LTheme items.

		Each item displays two pieces of theme metadata: the theme's name and
		its UUID.
	*/
	class LAYERS_WIDGETS_EXPORT LThemeComboBox : public LComboBox
	{
		Q_OBJECT

	public:
		/*!
			Constructs a theme combo box.
		*/
		LThemeComboBox(QWidget* parent = nullptr);

		/*!
			Adds a theme to the combo box's item model.
		*/
		void addItem(LTheme* theme);

		/*!
			Clears the combo box's item model.
		*/
		void clear();

	protected:
		virtual bool eventFilter(QObject* object, QEvent* event) override;

		virtual void paintEvent(QPaintEvent* event) override;

	private:
		LThemeComboBoxItemModel* m_model;
	};
}

#endif // LTHEMECOMBOBOX_H
