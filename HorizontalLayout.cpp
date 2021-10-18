#include "Layers.h"

using Layers::HorizontalLayout;

HorizontalLayout::HorizontalLayout(QWidget* parent) : QHBoxLayout(parent)
{

}

void HorizontalLayout::set_border_margin(int border_margin)
{
	m_border_margin = border_margin;

	update_margins();
}

void HorizontalLayout::setContentsMargins(int left, int top, int right, int bottom)
{
	m_margin_left = left;
	m_margin_top = top;
	m_margin_right = right;
	m_margin_bottom = bottom;

	update_margins();
}

void HorizontalLayout::update_margins()
{
	QHBoxLayout::setContentsMargins(m_margin_left + m_border_margin, m_margin_top + m_border_margin, m_margin_right + m_border_margin, m_margin_bottom + m_border_margin);
}
