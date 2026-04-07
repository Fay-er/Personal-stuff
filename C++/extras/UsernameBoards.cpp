#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::string;

void insertUser(string line)
{
	std::ofstream fileOut("usernames.txt", std::ios_base::app);

	if(!fileOut.is_open())
	{
		std::cerr << "Error inserting username into the file." << std::endl;
	}

	fileOut << line << std::endl;
	fileOut.close();
}

void getUserBoards()
{
	string fileLine;

	std::ifstream fileIn("usernames.txt");

	if(!fileIn.is_open())
	{
		std::cerr << "Error while reading username file." << std::endl;
	}

	while(getline(fileIn, fileLine))
	{
		cout << fileLine << std::endl;
	}

	fileIn.close();
}

int main()
{
	string line;

	cout << std::endl;
	cout << "Please enter your username: ";
	getline(cin, line);
	cout << std::endl;

	cout << "Welcome!" << std::endl;
	cout << "This is a username boards program." << std::endl;
	cout << "Your username will be inserted into it now." << :: std::endl;

	insertUser(line);

	cout << "The username boards:" << std::endl << std::endl;

	getUserBoards();

	return 0;
}