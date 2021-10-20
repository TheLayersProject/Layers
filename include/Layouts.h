#ifndef LAYOUTS_H
#define LAYOUTS_H

#include <QHBoxLayout>
#include <QVBoxLayout>

namespace Layers
{
	class HorizontalLayout : public QHBoxLayout
	{
	public:
		HorizontalLayout(QWidget* parent = nullptr);

		void set_border_margin(int border_margin);
		void setContentsMargins(int left, int top, int right, int bottom);

		void update_margins();

	protected:
		int m_margin_left{ 0 };
		int m_margin_top{ 0 };
		int m_margin_right{ 0 };
		int m_margin_bottom{ 0 };
		int m_border_margin{ 0 };
	};

	class VerticalLayout : public QVBoxLayout
	{
	public:
		VerticalLayout(QWidget* parent = nullptr);

		void set_border_margin(int border_margin);
		void setContentsMargins(int left, int top, int right, int bottom);

		void update_margins();

	protected:
		int m_margin_left{ 0 };
		int m_margin_top{ 0 };
		int m_margin_right{ 0 };
		int m_margin_bottom{ 0 };
		int m_border_margin{ 0 };
	};
}

#endif // LAYOUTS_H
