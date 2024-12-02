#include <iostream>

void printUpperStr(char *str)
{
	char letter;
	for (int j = 0; str[j]; j++) // if str[j] exist (str[j] != '\0') then keep looping
	{
		letter = toupper(str[j]);
		std::cout << letter;
	}
}

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			printUpperStr(argv[i]);
		}
		std::cout << "\n";
	}
	return 0;
}
