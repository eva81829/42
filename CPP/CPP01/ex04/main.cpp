#include <iostream>
#include <fstream>

#define NUM_INPUT 3 + 1
#define IDX_FILE 1
#define IDX_S1 2
#define IDX_S2 3

std::string replaceString(std::string line, std::string s1, std::string s2)
{
	std::string newLine;
	int i = 0;
	while(line[i])
	{
		std::string subLine;
		subLine = line.substr(i, s1.length());
		if (s1.length() > 0 && subLine == s1)
		{
			newLine += s2;
			i += s1.length();
			continue;
		}
		newLine += line[i];
		i++;
	}
	return newLine;
}

void replaceLine(std::ifstream* inFile, std::ofstream* outFile, std::string s1, std::string s2)
{
	std::string line;
	while(std::getline(*inFile, line))
	{
		*outFile << replaceString(line, s1, s2);
		//If inFile is not at the end of the file
		if(!inFile->eof())
		{
			*outFile << std::endl; //This line ends with '\n'
		}
	}
}

bool replaceFile(std::string fileName, std::string s1, std::string s2)
{
	std::ifstream inFile(fileName);
    if (!inFile.is_open()) // Check if the file opened successfully
	{
        std::cerr << "Failed to open the file." << std::endl;
        return false;
    }

    std::ofstream outFile(fileName + ".replace");
    if (!outFile.is_open()) // Check if the file opened successfully
	{
        std::cerr << "Error opening file for writing!" << std::endl;
        return false;
    }

	replaceLine(&inFile, &outFile, s1, s2);

	inFile.close();
	outFile.close();
	return true;
}

int main(int argc, char* argv[])
{
	if (argc != NUM_INPUT)
	{
		std::cout << "Needs three parameters" << std::endl;
		return 1;
	}

	std::string fileName = argv[IDX_FILE];
	std::string s1 = argv[IDX_S1];
	std::string s2 = argv[IDX_S2];
	if(!replaceFile(fileName, s1, s2))
	{
		return 1;
	}
	return 0;
}
