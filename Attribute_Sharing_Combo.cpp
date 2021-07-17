#include "Layers.h"

using Layers::Attribute;
using Layers::Attribute_Sharing_Combo;
using Layers::Themeable;

Attribute_Sharing_Combo::Attribute_Sharing_Combo(
	Attribute& from_attribute, Attribute& to_attribute,
	QString from_state, QString to_state) :
	m_from_state{ from_state }, m_from_attribute{ from_attribute },
	m_to_state{ to_state }, m_to_attribute{ to_attribute }
{
}

Attribute& Attribute_Sharing_Combo::from_attribute()
{
	return m_from_attribute;
}

Themeable* Attribute_Sharing_Combo::from_themeable() const
{
	return m_from_attribute.parent_themeable();
}

QString& Attribute_Sharing_Combo::from_state()
{
	return m_from_state;
}

QString& Attribute_Sharing_Combo::from_attribute_name()
{
	return m_from_attribute.name();
}

void Attribute_Sharing_Combo::obtain_attribute(bool update_shares_and_dependencies)
{
	if (m_from_state == "")
	{
		if (m_to_state == "")
		{
			if (QString(m_from_attribute.value().typeName()) == "QString" &&
				QString(m_to_attribute.value().typeName()) == "int")
			{
				m_from_attribute.set_value(QString::number(m_to_attribute.value().value<int>()));
			}
			else if (QString(m_from_attribute.value().typeName()) == "int" &&
				QString(m_to_attribute.value().typeName()) == "QString")
			{
				m_from_attribute.set_value(m_to_attribute.value().value<QString>().toInt());
			}
			else m_from_attribute.set_value(m_to_attribute.value());
		}
		else
		{
			if (QString(m_from_attribute.value().typeName()) == "QString" &&
				QString(m_to_attribute.value(m_to_state).typeName()) == "int")
			{
				m_from_attribute.set_value(QString::number(m_to_attribute.value(m_to_state).value<int>()));
			}
			else if (QString(m_from_attribute.value().typeName()) == "int" &&
				QString(m_to_attribute.value(m_to_state).typeName()) == "QString")
			{
				m_from_attribute.set_value(m_to_attribute.value(m_to_state).value<QString>().toInt());
			}
			else m_from_attribute.set_value(m_to_attribute.value(m_to_state));
		}
	}
	else
	{
		if (m_to_state == "")
		{
			if (QString(m_from_attribute.value(m_from_state).typeName()) == "QString" &&
				QString(m_to_attribute.value().typeName()) == "int")
			{
				m_from_attribute.set_value(m_from_state, QString::number(m_to_attribute.value().value<int>()));
			}
			else if (QString(m_from_attribute.value(m_from_state).typeName()) == "int" &&
				QString(m_to_attribute.value().typeName()) == "QString")
			{
				m_from_attribute.set_value(m_from_state, m_to_attribute.value().value<QString>().toInt());
			}
			else m_from_attribute.set_value(m_from_state, m_to_attribute.value());
		}
		else
		{
			if (QString(m_from_attribute.value(m_from_state).typeName()) == "QString" &&
				QString(m_to_attribute.value(m_to_state).typeName()) == "int")
			{
				m_from_attribute.set_value(m_from_state, QString::number(m_to_attribute.value(m_to_state).value<int>()));
			}
			else if (QString(m_from_attribute.value(m_from_state).typeName()) == "int" &&
				QString(m_to_attribute.value(m_to_state).typeName()) == "QString")
			{
				m_from_attribute.set_value(m_from_state, m_to_attribute.value(m_to_state).value<QString>().toInt());
			}
			else m_from_attribute.set_value(m_from_state, m_to_attribute.value(m_to_state));
		}
	}

	if (update_shares_and_dependencies)
	{
		from_themeable()->share_attributes();
		from_themeable()->update_theme_dependencies();
	}
}

void Attribute_Sharing_Combo::share_attribute()
{
	if (to_themeable())
	{
		if (m_from_state == "")
		{
			if (m_to_state == "")
			{
				if (QString(m_from_attribute.value().typeName()) == "QString" &&
					QString(m_to_attribute.value().typeName()) == "int")
				{
					m_to_attribute.set_value(m_from_attribute.value().value<QString>().toInt());
				}
				else if (QString(m_from_attribute.value().typeName()) == "int" &&
					QString(m_to_attribute.value().typeName()) == "QString")
				{
					m_to_attribute.set_value(QString::number(m_from_attribute.value().value<int>()));
				}
				else m_to_attribute.set_value(m_from_attribute.value());
			}
			else
			{
				if (QString(m_from_attribute.value().typeName()) == "QString" &&
					QString(m_to_attribute.value(m_to_state).typeName()) == "int")
				{
					m_to_attribute.set_value(
						m_to_state,
						m_from_attribute.value().value<QString>().toInt());
				}
				else if (QString(m_from_attribute.value().typeName()) == "int" &&
					QString(m_to_attribute.value(m_to_state).typeName()) == "QString")
				{
					m_to_attribute.set_value(
						m_to_state,
						QString::number(m_from_attribute.value().value<int>()));
				}
				else
					m_to_attribute.set_value(
						m_to_state,
						m_from_attribute.value());
			}
		}
		else
		{
			if (m_to_state == "")
			{
				if (QString(m_from_attribute.value(m_from_state).typeName()) == "QString" &&
					QString(m_to_attribute.value().typeName()) == "int")
				{
					m_to_attribute.set_value(
						m_from_attribute.value(m_from_state).value<QString>().toInt());
				}
				else if (QString(m_from_attribute.value(m_from_state).typeName()) == "int" &&
					QString(m_to_attribute.value().typeName()) == "QString")
				{
					m_to_attribute.set_value(
						QString::number(m_from_attribute.value(m_from_state).value<int>()));
				}
				else m_to_attribute.set_value(m_from_attribute.value(m_from_state));
			}
			else
			{
				if (QString(m_from_attribute.value(m_from_state).typeName()) == "QString" &&
					QString(m_to_attribute.value(m_to_state).typeName()) == "int")
				{
					m_to_attribute.set_value(
						m_to_state,
						m_from_attribute.value(m_from_state).value<QString>().toInt());
				}
				else if (QString(m_from_attribute.value(m_from_state).typeName()) == "int" &&
					QString(m_to_attribute.value(m_to_state).typeName()) == "QString")
				{
					m_to_attribute.set_value(
						m_to_state,
						QString::number(m_from_attribute.value(m_from_state).value<int>()));
				}
				else
				{
					m_to_attribute.set_value(
						m_to_state,
						m_from_attribute.value(m_from_state));
				}
			}
		}

		to_themeable()->share_attributes();
		to_themeable()->update_theme_dependencies();
		to_themeable()->issue_update();
	}
}

Attribute& Attribute_Sharing_Combo::to_attribute()
{
	return m_to_attribute;
}

Themeable* Attribute_Sharing_Combo::to_themeable() const
{
	return m_to_attribute.parent_themeable();
}

QString& Attribute_Sharing_Combo::to_state()
{
	return m_to_state;
}

QString& Attribute_Sharing_Combo::to_attribute_name()
{
	return m_to_attribute.name();
}
