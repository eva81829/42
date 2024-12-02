#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.hpp"

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact();
		Contact(std::string firstName, std::string lastName, std::string nickName, 
			std::string phoneNumber, std::string darkestSecret);

		void 		setFirstName(std::string firstName);
		void 		setLastName(std::string lastName);
		void 		setNickName(std::string nickName);
		void 		setPhoneNumber(std::string phoneNumber);
		void 		setDarkestSecret(std::string darkestSecret);
	
		std::string getFirstName();
		std::string getLastName();
		std::string getNickName();
		std::string getPhoneNumber();
		std::string getDarkestSecret();
};

#endif // CONTACT_HPP