#include "main.hpp"

// static void creatContact(PhoneBook* phonebook)
// {
// 	Contact contact0("0","0","0","0","0");
// 	Contact contact1("1111111111111111","1","1","1","1");
// 	Contact contact2("2","2","2","2","2");
// 	Contact contact3("3","3","3","3","3");
// 	Contact contact4("4","4","4","4","4");
// 	Contact contact5("5","5","5","5","5");
// 	Contact contact6("6","6","6","6","6");
// 	Contact contact7("7","7","7","7","7");

// 	phonebook->addContact(contact0);
// 	phonebook->addContact(contact1);
// 	phonebook->addContact(contact2);
// 	phonebook->addContact(contact3);
// 	phonebook->addContact(contact4);
// 	phonebook->addContact(contact5);
// 	phonebook->addContact(contact6);
// 	phonebook->addContact(contact7);
// }

int main()
{
	PhoneBook phonebook;
	std::string option;

	while (!std::cin.fail())
	{
		std::cout << "Please input("
			      << ADD << "/" << SEARCH << "/" << EXIT << "):";

		std::getline(std::cin, option);
		if (option == ADD)
		{
			addPhoneBook(&phonebook);
		} 
		else if (option == SEARCH)
		{
			searchPhoneBook(&phonebook);
		}
		else if (option == EXIT)
		{
			break;
		}
	}
	return 0;
}
