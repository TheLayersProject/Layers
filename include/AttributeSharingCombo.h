#ifndef ATTRIBUTESHARINGCOMBO_H
#define ATTRIBUTESHARINGCOMBO_H

#include <QString>

namespace Layers
{
	class StatelessAttribute;
	class StatefulAttribute;
	class Themeable;

	/*!
		Stores the themeable addresses, states, and attributes needed to establish an attribute sharing connection.

		An AttributeSharingCombo is created and stored when Themeable::share_attribute_with_themeable() is called
	*/
	class AttributeSharingCombo
	{
	public:
		AttributeSharingCombo(
			StatefulAttribute* from_stateful_attribute, QString from_state,
			StatefulAttribute* to_stateful_attribute, QString to_state);

		AttributeSharingCombo(
			StatelessAttribute* from_stateless_attribute,
			StatelessAttribute* to_stateless_attribute);

		AttributeSharingCombo(
			StatefulAttribute* from_stateful_attribute, QString from_state,
			StatelessAttribute* to_stateless_attribute);

		AttributeSharingCombo(
			StatelessAttribute* from_stateless_attribute,
			StatefulAttribute* to_stateful_attribute, QString to_state);

		StatefulAttribute* from_stateful_attribute();

		StatelessAttribute* from_stateless_attribute();

		Themeable* from_themeable() const;

		QString& from_state();

		QString& from_attribute_name();

		/*!
			Obtains the value of the to_attribute

			If the from_attribute is a QString, and the to_attribute is an int, or vice-versa, then
			this function will convert the incoming to_attribute value into the type of the from_attribute.

			@param update_shares_and_dependencies controls whether attribute shares and theme dependencies gets updated or not, true by default
		*/
		void obtain_attribute(bool update_shares_and_dependencies = true);

		/*!
			Shares the value of the from_attribute

			If the from_attribute is a QString, and the to_attribute is an int, or vice-versa, then
			this function will convert the outgoing to_attribute value into the type of the from_attribute.
		*/
		void share_attribute();

		StatefulAttribute* to_stateful_attribute();

		StatelessAttribute* to_stateless_attribute();

		Themeable* to_themeable() const;

		QString& to_state();

		QString& to_attribute_name();

	private:
		StatefulAttribute* m_from_stateful_attribute{ nullptr };
		StatefulAttribute* m_to_stateful_attribute{ nullptr };

		StatelessAttribute* m_from_stateless_attribute{ nullptr };
		StatelessAttribute* m_to_stateless_attribute{ nullptr };

		QString m_from_state{ "" };
		QString m_to_state{ "" };
	};
}

#endif // ATTRIBUTESHARINGCOMBO_H
