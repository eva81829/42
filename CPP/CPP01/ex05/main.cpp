#include <iostream>
#include "Harl.hpp"

#define NUM_INPUT 1 + 1

int main(int argc, char* argv[])
{
	if (argc != NUM_INPUT)
	{
		std::cout << "Needs one parameters" << std::endl;
		return 1;
	}
	
	Harl harl;
	
	harl.complain(argv[1]);

	return 0;
}
