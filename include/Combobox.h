#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QComboBox>
#include <QPainterPath>

#include "Themeable.h"

namespace Layers
{
	class ComboBox : public QComboBox, public Themeable
	{
		Q_OBJECT

	public:
		ComboBox(QWidget* parent = nullptr);
		~ComboBox();

		virtual QList<Themeable*> child_themeables(
			Qt::FindChildOptions options = Qt::FindDirectChildrenOnly) override;

		void setFixedSize(int w, int h);
		void setFixedSize(QSize size);

		virtual void showPopup() override;

		void update_stylesheet();

	protected:
		QPainterPath background_path() const;

		virtual bool eventFilter(QObject* object, QEvent* event) override;

		virtual void paintEvent(QPaintEvent* event) override;

		BorderAttributes* m_border{ new BorderAttributes };

		Attribute* m_corner_radius{ new Attribute(
			"corner_radius",
			Variant(10.0)
			) };

		Attribute* m_fill{ new Attribute(
			"fill",
			QColor(Qt::white)
			) };

		Attribute* m_text_color{ new Attribute(
			"text_color",
			QColor(Qt::black)
			) };

	private:
		void init_attributes();
	};
}

#endif // COMBOBOX_H
