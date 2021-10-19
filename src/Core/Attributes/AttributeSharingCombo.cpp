#include "../../Layers.h"

using Layers::AttributeSharingCombo;
using Layers::StatefulAttribute;
using Layers::StatelessAttribute;
using Layers::Themeable;

AttributeSharingCombo::AttributeSharingCombo(
	StatefulAttribute* from_stateful_attribute, QString from_state,
	StatefulAttribute* to_stateful_attribute, QString to_state) :
	m_from_stateful_attribute{ from_stateful_attribute }, m_from_state{ from_state },
	m_to_stateful_attribute{ to_stateful_attribute }, m_to_state{ to_state }
{
}

AttributeSharingCombo::AttributeSharingCombo(
	StatelessAttribute* from_stateless_attribute,
	StatelessAttribute* to_stateless_attribute) :
	m_from_stateless_attribute{ from_stateless_attribute },
	m_to_stateless_attribute{ to_stateless_attribute }
{
}

AttributeSharingCombo::AttributeSharingCombo(
	StatefulAttribute* from_stateful_attribute, QString from_state,
	StatelessAttribute* to_stateless_attribute) :
	m_from_stateful_attribute{ from_stateful_attribute }, m_from_state{ from_state },
	m_to_stateless_attribute{ to_stateless_attribute }
{
}

AttributeSharingCombo::AttributeSharingCombo(
	StatelessAttribute* from_stateless_attribute,
	StatefulAttribute* to_stateful_attribute, QString to_state) :
	m_from_stateless_attribute{ from_stateless_attribute },
	m_to_stateful_attribute{ to_stateful_attribute }, m_to_state{ to_state }
{
}

StatefulAttribute* AttributeSharingCombo::from_stateful_attribute()
{
	return m_from_stateful_attribute;
}

StatelessAttribute* AttributeSharingCombo::from_stateless_attribute()
{
	return m_from_stateless_attribute;
}

Themeable* AttributeSharingCombo::from_themeable() const
{
	if (m_from_stateful_attribute) return m_from_stateful_attribute->parent_themeable();
	else return m_from_stateless_attribute->parent_themeable();
}

QString& AttributeSharingCombo::from_state()
{
	return m_from_state;
}

QString& AttributeSharingCombo::from_attribute_name()
{
	if (m_from_stateful_attribute) return m_from_stateful_attribute->name();
	else return m_from_stateless_attribute->name();
}

void AttributeSharingCombo::obtain_attribute(bool update_shares_and_dependencies)
{
	if (m_from_stateless_attribute)
	{
		if (m_to_stateless_attribute)
		{
			if (QString(m_from_stateless_attribute->value().typeName()) == "QString" &&
				QString(m_to_stateless_attribute->value().typeName()) == "int")
			{
				m_from_stateless_attribute->set_value(QString::number(m_to_stateless_attribute->value().value<int>()));
			}
			else if (QString(m_from_stateless_attribute->value().typeName()) == "int" &&
				QString(m_to_stateless_attribute->value().typeName()) == "QString")
			{
				m_from_stateless_attribute->set_value(m_to_stateless_attribute->value().value<QString>().toInt());
			}
			else m_from_stateless_attribute->set_value(m_to_stateless_attribute->value());
		}
		else if (m_to_stateful_attribute)
		{
			if (QString(m_from_stateless_attribute->value().typeName()) == "QString" &&
				QString(m_to_stateful_attribute->value(m_to_state)->typeName()) == "int")
			{
				m_from_stateless_attribute->set_value(QString::number(m_to_stateful_attribute->value(m_to_state)->value<int>()));
			}
			else if (QString(m_from_stateless_attribute->value().typeName()) == "int" &&
				QString(m_to_stateful_attribute->value(m_to_state)->typeName()) == "QString")
			{
				m_from_stateless_attribute->set_value(m_to_stateful_attribute->value(m_to_state)->value<QString>().toInt());
			}
			else m_from_stateless_attribute->set_value(*m_to_stateful_attribute->value(m_to_state));
		}
		else update_shares_and_dependencies = false;
	}
	else if (m_from_stateful_attribute)
	{
		if (m_to_stateless_attribute)
		{
			if (QString(m_from_stateful_attribute->value(m_from_state)->typeName()) == "QString" &&
				QString(m_to_stateless_attribute->value().typeName()) == "int")
			{
				m_from_stateful_attribute->set_value(m_from_state, QString::number(m_to_stateless_attribute->value().value<int>()));
			}
			else if (QString(m_from_stateful_attribute->value(m_from_state)->typeName()) == "int" &&
				QString(m_to_stateless_attribute->value().typeName()) == "QString")
			{
				m_from_stateful_attribute->set_value(m_from_state, m_to_stateless_attribute->value().value<QString>().toInt());
			}
			else m_from_stateful_attribute->set_value(m_from_state, m_to_stateless_attribute->value());
		}
		else if (m_to_stateful_attribute)
		{
			if (QString(m_from_stateful_attribute->value(m_from_state)->typeName()) == "QString" &&
				QString(m_to_stateful_attribute->value(m_to_state)->typeName()) == "int")
			{
				m_from_stateful_attribute->set_value(m_from_state, QString::number(m_to_stateful_attribute->value(m_to_state)->value<int>()));
			}
			else if (QString(m_from_stateful_attribute->value(m_from_state)->typeName()) == "int" &&
				QString(m_to_stateful_attribute->value(m_to_state)->typeName()) == "QString")
			{
				m_from_stateful_attribute->set_value(m_from_state, m_to_stateful_attribute->value(m_to_state)->value<QString>().toInt());
			}
			else m_from_stateful_attribute->set_value(m_from_state, *m_to_stateful_attribute->value(m_to_state));
		}
		else update_shares_and_dependencies = false;
	}
	else update_shares_and_dependencies = false;

	if (update_shares_and_dependencies)
	{
		from_themeable()->share_attributes();
		from_themeable()->update_theme_dependencies();
	}
}

void AttributeSharingCombo::share_attribute()
{
	bool successfuly_shared = true;

	if (m_from_stateless_attribute)
	{
		if (m_to_stateless_attribute)
		{
			if (QString(m_from_stateless_attribute->value().typeName()) == "QString" &&
				QString(m_to_stateless_attribute->value().typeName()) == "int")
			{
				m_to_stateless_attribute->set_value(m_from_stateless_attribute->value().value<QString>().toInt());
			}
			else if (QString(m_from_stateless_attribute->value().typeName()) == "int" &&
				QString(m_to_stateless_attribute->value().typeName()) == "QString")
			{
				m_to_stateless_attribute->set_value(QString::number(m_from_stateless_attribute->value().value<int>()));
			}
			else m_to_stateless_attribute->set_value(m_from_stateless_attribute->value());
		}
		else if (m_to_stateful_attribute)
		{
			if (QString(m_from_stateless_attribute->value().typeName()) == "QString" &&
				QString(m_to_stateful_attribute->value(m_to_state)->typeName()) == "int")
			{
				m_to_stateful_attribute->set_value(
					m_to_state,
					m_from_stateless_attribute->value().value<QString>().toInt());
			}
			else if (QString(m_from_stateless_attribute->value().typeName()) == "int" &&
				QString(m_to_stateful_attribute->value(m_to_state)->typeName()) == "QString")
			{
				m_to_stateful_attribute->set_value(
					m_to_state,
					QString::number(m_from_stateless_attribute->value().value<int>()));
			}
			else
				m_to_stateful_attribute->set_value(m_to_state, m_from_stateless_attribute->value());
		}
		else successfuly_shared = false;
	}
	else if (m_from_stateful_attribute)
	{
		if (m_to_stateless_attribute)
		{
			if (QString(m_from_stateful_attribute->value(m_from_state)->typeName()) == "QString" &&
				QString(m_to_stateless_attribute->value().typeName()) == "int")
			{
				m_to_stateless_attribute->set_value(
					m_from_stateful_attribute->value(m_from_state)->value<QString>().toInt());
			}
			else if (QString(m_from_stateful_attribute->value(m_from_state)->typeName()) == "int" &&
				QString(m_to_stateless_attribute->value().typeName()) == "QString")
			{
				m_to_stateless_attribute->set_value(
					QString::number(m_from_stateful_attribute->value(m_from_state)->value<int>()));
			}
			else m_to_stateless_attribute->set_value(*m_from_stateful_attribute->value(m_from_state));
		}
		else if (m_to_stateful_attribute)
		{
			if (QString(m_from_stateful_attribute->value(m_from_state)->typeName()) == "QString" &&
				QString(m_to_stateful_attribute->value(m_to_state)->typeName()) == "int")
			{
				m_to_stateful_attribute->set_value(
					m_to_state,
					m_from_stateful_attribute->value(m_from_state)->value<QString>().toInt());
			}
			else if (QString(m_from_stateful_attribute->value(m_from_state)->typeName()) == "int" &&
				QString(m_to_stateful_attribute->value(m_to_state)->typeName()) == "QString")
			{
				m_to_stateful_attribute->set_value(
					m_to_state,
					QString::number(m_from_stateful_attribute->value(m_from_state)->value<int>()));
			}
			else m_to_stateful_attribute->set_value(m_to_state, *m_from_stateful_attribute->value(m_from_state));
		}
		else successfuly_shared = false;
	}
	else successfuly_shared = false;

	if (successfuly_shared)
	{
		to_themeable()->share_attributes();
		to_themeable()->update_theme_dependencies();
		to_themeable()->issue_update();
	}
}

StatefulAttribute* AttributeSharingCombo::to_stateful_attribute()
{
	return m_to_stateful_attribute;
}

StatelessAttribute* AttributeSharingCombo::to_stateless_attribute()
{
	return m_to_stateless_attribute;
}

Themeable* AttributeSharingCombo::to_themeable() const
{
	if (m_to_stateful_attribute) return m_to_stateful_attribute->parent_themeable();
	else return m_to_stateless_attribute->parent_themeable();
}

QString& AttributeSharingCombo::to_state()
{
	return m_to_state;
}

QString& AttributeSharingCombo::to_attribute_name()
{
	if (m_to_stateful_attribute) return m_to_stateful_attribute->name();
	else return m_to_stateless_attribute->name();
}
