#include "main.hpp"

static bool checkInput(std::string input)
{
	int idx;

	try
	{
		idx = std::stoi(input);  // Convert string to int
		if (!(idx >= START_IDX_CONTACT && idx <= MAX_NUM_CONTACT - 1))
		{
			std::cout << "[Error]Out of range" << std::endl;
			return false;
		}
	}
	catch (...)
	{
		std::cout << "[Error]Input not number" << std::endl;
		return false;
	}
	return true;
}

static bool printContact(std::string input, PhoneBook* phonebook)
{
	int			idx;
	Contact*	contact;
	
	if (checkInput(input))
	{
		idx = std::stoi(input);  // Convert string to int
		contact = phonebook->getContact(idx);
		if(!contact)
		{
			std::cout << "[Error]Contact not found" << std::endl;
			return false;
		}

		std::cout << FIRST_NAME << ": " << contact->getFirstName() << std::endl
				  << LAST_NAME << ": " << contact->getLastName() << std::endl
				  << NICK_NAME << ": " << contact->getNickName() << std::endl
				  << PHONE_NUMBER << ": " << contact->getPhoneNumber() << std::endl
				  << DARKEST_SECRET << ": " << contact->getDarkestSecret() << std::endl;
		return true;
	}
	return false;
}

static std::string truncTxt(std::string str)
{
	if (str.length() > LEN_COL)
	{
		return str.substr(0, LEN_COL - 1) + ".";
	}
	return str;
}

static void displayContacts(PhoneBook* phonebook)
{
	Contact*	contact;

	std::cout << "     index|first name| last name| nick name" << std::endl;
	for (int i = 0; i < MAX_NUM_CONTACT; i++)
	{
		contact = phonebook->getContact(i);
		if (contact)
		{
			std::cout << std::setw(LEN_COL) << i << "|"
					  << std::setw(LEN_COL) << truncTxt(contact->getFirstName()) << "|"
					  << std::setw(LEN_COL) << truncTxt(contact->getLastName()) << "|"
					  << std::setw(LEN_COL) << truncTxt(contact->getNickName()) << std::endl;
		}
		else
		{
			std::cout << std::setw(LEN_COL) << i << "|"
					  << std::setw(LEN_COL) << "-" << "|"
					  << std::setw(LEN_COL) << "-" << "|"
					  << std::setw(LEN_COL) << "-" << std::endl;
		}
	}
}

void searchPhoneBook(PhoneBook* phonebook)
{
	std::string input;

	if (phonebook->getNumContact() == 0)
	{
		std::cout << "No contact!" << std::endl;
		return;
	}
	while (true)
	{
		displayContacts(phonebook);
		std::cout << "Please input the 'index' of the contact:";
		std::getline(std::cin, input);

		if (std::cin.fail())
			return;
		if (printContact(input, phonebook))
			return;
	}
}
