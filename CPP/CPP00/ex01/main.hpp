#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"    //Contact.hpp should include before PhoneBook.hpp
# include "PhoneBook.hpp"  //otherwise PhoneBook can't reconize Contact(in PhoneBook.hpp)

# define ADD "ADD"
# define SEARCH "SEARCH"
# define EXIT "EXIT"

# define LEN_COL 10

# define FIRST_NAME "first name"
# define LAST_NAME "last name"
# define NICK_NAME "nick name"
# define PHONE_NUMBER "phone number"
# define DARKEST_SECRET "darkest secret"

typedef struct sContact {
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
}	tContact;

// search.cpp
void searchPhoneBook(PhoneBook* phonebook);

// add.cpp
void addPhoneBook(PhoneBook* phonebook);

#endif // MAIN_HPP