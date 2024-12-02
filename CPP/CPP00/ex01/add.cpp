#include "main.hpp"

static bool checkPhoneNumber(std::string input)
{
	try
	{
		std::stoi(input);  // Convert string to int
		return true;
	}
	catch(...)
	{
		std::cout << "[Error]Input not number" << std::endl;
	}
	return false;
}

static bool checkEmpty(std::string input)
{
	for (int i = 0; input[i]; i++)
	{
		if (input[i] != ' ')
		{
			return true;
		}
	}
	std::cout << "[Error]Empty field" << std::endl;
	return false;
}

static bool getField(std::string column, std::string* field)
{
	std::string input;
	while(true)
	{
		std::cout << "Please input the '" << column << "' of the contact:";
		std::getline(std::cin, input);
		if (std::cin.fail())
			return false;
		if (!checkEmpty(input))
			continue;

		if (column != PHONE_NUMBER)
		{
			*field = input;
			return true;
		}
		else if (column == PHONE_NUMBER && checkPhoneNumber(input))
		{
			*field = input;
			return true;
		}
	}
}

void addPhoneBook(PhoneBook* phonebook)
{
	tContact	tmpContact;
	Contact		contact;

	if (!getField(FIRST_NAME, &tmpContact.firstName))
		return;
	if (!getField(LAST_NAME, &tmpContact.lastName))
		return;
	if (!getField(NICK_NAME, &tmpContact.nickName))
		return;
	if (!getField(PHONE_NUMBER, &tmpContact.phoneNumber))
		return;
	if (!getField(DARKEST_SECRET, &tmpContact.darkestSecret))
		return;

	contact.setFirstName(tmpContact.firstName);
	contact.setLastName(tmpContact.lastName);
	contact.setNickName(tmpContact.nickName);
	contact.setPhoneNumber(tmpContact.phoneNumber);
	contact.setDarkestSecret(tmpContact.darkestSecret);

	phonebook->addContact(contact);
	std::cout << "Contact add!" << std::endl;
}
