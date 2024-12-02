#include "main.hpp"

PhoneBook::PhoneBook()
{
	this->numContact = 0;
}

void PhoneBook::addContact(Contact contact)
{
	int idxContact;

	idxContact = this->numContact % MAX_NUM_CONTACT;
	this->contacts[idxContact].setFirstName(contact.getFirstName());
	this->contacts[idxContact].setLastName(contact.getLastName());
	this->contacts[idxContact].setNickName(contact.getNickName());
	this->contacts[idxContact].setPhoneNumber(contact.getPhoneNumber());
	this->contacts[idxContact].setDarkestSecret(contact.getDarkestSecret());			
	this->numContact++;
}

Contact* PhoneBook::getContact(int idx)
{
	if (idx < this->numContact)
	{
		return &(this->contacts[idx]);
	}
	else
	{
		return NULL;
	}
}

int PhoneBook::getNumContact()
{
	return this->numContact;
}