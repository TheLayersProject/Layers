#include "Layers.h"

using Layers::Horizontal_Layout;

Horizontal_Layout::Horizontal_Layout(QWidget* parent) : QHBoxLayout(parent)
{

}

void Horizontal_Layout::set_border_margin(int border_margin)
{
	m_border_margin = border_margin;

	update_margins();
}

void Horizontal_Layout::setContentsMargins(int left, int top, int right, int bottom)
{
	m_margin_left = left;
	m_margin_top = top;
	m_margin_right = right;
	m_margin_bottom = bottom;

	update_margins();
}

void Horizontal_Layout::update_margins()
{
	QHBoxLayout::setContentsMargins(m_margin_left + m_border_margin, m_margin_top + m_border_margin, m_margin_right + m_border_margin, m_margin_bottom + m_border_margin);
}
