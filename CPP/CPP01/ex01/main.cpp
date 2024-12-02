#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);
void deleteZombies(Zombie* zombies);

int main()
{
	int N;
	Zombie* zombies;

	N = 5;
	zombies = zombieHorde(N, "foo2");
	for (int i = 0; i < N; i++)
	{
		zombies[i].announce();
	}
	deleteZombies(zombies);
	return 0;
}
