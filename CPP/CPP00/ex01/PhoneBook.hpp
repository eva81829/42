#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "main.hpp"

# define START_IDX_CONTACT 0
# define MAX_NUM_CONTACT 8

class PhoneBook
{
	private:
		int			numContact;
		Contact 	contacts[MAX_NUM_CONTACT];

	public:
		PhoneBook();
		void		addContact(Contact contact);
		Contact*	getContact(int idx);
		int 		getNumContact();
};

#endif // PHONEBOOK_HPP