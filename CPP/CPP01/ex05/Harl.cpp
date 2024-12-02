# include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!"
			  << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month."
			  << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

const std::string Harl::levels[] = {DEBUG, INFO, WARNING, ERROR};

// Constructor definition initializing memberFunctions pointer array
// memberFunctions pointer array store pointers to member functions
Harl::Harl()
{
    memberFunctions[0] = &Harl::debug;
    memberFunctions[1] = &Harl::info;
    memberFunctions[2] = &Harl::warning;
    memberFunctions[3] = &Harl::error;	
}

void Harl::complain(std::string level)
{
	for(int i = 0; i < NUM_LEVELS; i++)
	{
		if(level == levels[i])
		{
			// Dereferencing the pointer to member function in order to call the member function
			(this->*memberFunctions[i])();
		}
	}
}
