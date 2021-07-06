#include "Layers.h"

using Layers::Vertical_Layout;

Vertical_Layout::Vertical_Layout(QWidget* parent) : QVBoxLayout(parent)
{

}

void Vertical_Layout::set_border_margin(int border_margin)
{
	m_border_margin = border_margin;

	update_margins();
}

void Vertical_Layout::setContentsMargins(int left, int top, int right, int bottom)
{
	m_margin_left = left;
	m_margin_top = top;
	m_margin_right = right;
	m_margin_bottom = bottom;

	update_margins();
}

void Vertical_Layout::update_margins()
{
	QVBoxLayout::setContentsMargins(m_margin_left + m_border_margin, m_margin_top + m_border_margin, m_margin_right + m_border_margin, m_margin_bottom + m_border_margin);
}
