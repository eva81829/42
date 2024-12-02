#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	randomChump("Foo0");

	Zombie* zombie;

	zombie = newZombie("Foo");
	zombie->announce();
	delete zombie;
	
	return 0;
}
