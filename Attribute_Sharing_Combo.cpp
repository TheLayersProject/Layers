#include "Layers.h"

using Layers::Attribute_Sharing_Combo;
using Layers::Stateful_Attribute;
using Layers::Stateless_Attribute;
using Layers::Themeable;

Attribute_Sharing_Combo::Attribute_Sharing_Combo(
	Stateful_Attribute* from_stateful_attribute, QString from_state,
	Stateful_Attribute* to_stateful_attribute, QString to_state) :
	m_from_stateful_attribute{ from_stateful_attribute }, m_from_state{ from_state },
	m_to_stateful_attribute{ to_stateful_attribute }, m_to_state{ to_state }
{
}

Attribute_Sharing_Combo::Attribute_Sharing_Combo(
	Stateless_Attribute* from_stateless_attribute,
	Stateless_Attribute* to_stateless_attribute) :
	m_from_stateless_attribute{ from_stateless_attribute },
	m_to_stateless_attribute{ to_stateless_attribute }
{
}

Attribute_Sharing_Combo::Attribute_Sharing_Combo(
	Stateful_Attribute* from_stateful_attribute, QString from_state,
	Stateless_Attribute* to_stateless_attribute) :
	m_from_stateful_attribute{ from_stateful_attribute }, m_from_state{ from_state },
	m_to_stateless_attribute{ to_stateless_attribute }
{
}

Attribute_Sharing_Combo::Attribute_Sharing_Combo(
	Stateless_Attribute* from_stateless_attribute,
	Stateful_Attribute* to_stateful_attribute, QString to_state) :
	m_from_stateless_attribute{ from_stateless_attribute },
	m_to_stateful_attribute{ to_stateful_attribute }, m_to_state{ to_state }
{
}

Stateful_Attribute* Attribute_Sharing_Combo::from_stateful_attribute()
{
	return m_from_stateful_attribute;
}

Stateless_Attribute* Attribute_Sharing_Combo::from_stateless_attribute()
{
	return m_from_stateless_attribute;
}

Themeable* Attribute_Sharing_Combo::from_themeable() const
{
	if (m_from_stateful_attribute) return m_from_stateful_attribute->parent_themeable();
	else return m_from_stateless_attribute->parent_themeable();
}

QString& Attribute_Sharing_Combo::from_state()
{
	return m_from_state;
}

QString& Attribute_Sharing_Combo::from_attribute_name()
{
	if (m_from_stateful_attribute) return m_from_stateful_attribute->name();
	else return m_from_stateless_attribute->name();
}

void Attribute_Sharing_Combo::obtain_attribute(bool update_shares_and_dependencies)
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

void Attribute_Sharing_Combo::share_attribute()
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

Stateful_Attribute* Attribute_Sharing_Combo::to_stateful_attribute()
{
	return m_to_stateful_attribute;
}

Stateless_Attribute* Attribute_Sharing_Combo::to_stateless_attribute()
{
	return m_to_stateless_attribute;
}

Themeable* Attribute_Sharing_Combo::to_themeable() const
{
	if (m_to_stateful_attribute) return m_to_stateful_attribute->parent_themeable();
	else return m_to_stateless_attribute->parent_themeable();
}

QString& Attribute_Sharing_Combo::to_state()
{
	return m_to_state;
}

QString& Attribute_Sharing_Combo::to_attribute_name()
{
	if (m_to_stateful_attribute) return m_to_stateful_attribute->name();
	else return m_to_stateless_attribute->name();
}
