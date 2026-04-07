#include <iostream>
#include <fstream>
#include <string>
#include "battleship.h"
#include "files.h"

int checkAccount(std::string username, std::string password)
{
	std::string fileLine;
	std::string previousLine;

	std::ifstream fileIn("accounts.txt");

	if(!fileIn.is_open())
	{
		std::cerr << "Error opening file..." << std::endl << "ERROR 000" << std::endl << std::endl;

		return 0;
	}

	for(std::string fileLine; getline(fileIn, fileLine, ';');)
	{
		cout << fileLine << std::endl;

		if(previousLine == username && fileLine == password)
		{			
			fileIn.close();

			return 1;
		}
		previousLine = fileLine;
	};

	fileIn.close();

	return 0;
}

void createAccount(std::string username, std::string password)
{
	std::string account = username + ';' + password + ';';

	std::ofstream fileOut("accounts.txt", std::ios_base::app);

	if(!fileOut.is_open())
	{
		std::cerr << "Error opening file..." << std::endl << "ERROR 001" << std::endl << std::endl;
	}

	fileOut << account;

	fileOut.close();

	std::cout << std::endl << "Congratulations! Your account has been created!" << std::endl << std::endl;
}

int main()
{
	int wrongTries = 0;

	std::string line;
	std::string username;
	std::string password;

	std::cout << "Welcome to my program where you access many of my projects!" << std::endl;

	std::cout << "Would you like to log in or sign in?" << std::endl;

	getline(std::cin, line);

	if(line == "SIGN IN" || line == "Sign In" || line == "Sign in" || line == "sign in")
	{
		cout << "Fair." << std::endl << "Please enter your desired username: ";

		getline(cin, username);

		cout << std::endl << "Please enter your desired password: ";

		getline(cin, password);

		cout << std::endl;

		createAccount(username, password);
	}

	while(true)
	{
		std::cout << "Please enter your username here: ";
		getline(std::cin, username);
		
		std::cout << std::endl << "Please enter your password here: ";

		getline(std::cin, password);

		std::cout << std::endl;
		
		int accountConfirm = checkAccount(username, password);

		if(accountConfirm == 0)
		{
			std::cout << "Invalid credentials." << std::endl << "Please try again." << std::endl;

			wrongTries++;
			std::cout << "No of wrong tries: " << wrongTries << std::endl << std::endl << std::endl;
		}
		else
		{
			std::cout << "Account confirmed!" << std::endl;

			break;
		}

		if(wrongTries >= 3)
		{
			std::cout << "Do you want to create another account?" << std::endl;
			std::cout << "Enter here: ";

			getline(std::cin, line);

			if(line == "YES" || line == "Yes" || line == "yes")
			{
				std::cout << std::endl << "Alright!" << std::endl;
				std::cout << "Please enter your desired account name here: ";

				getline(std::cin, username);

				std::cout << std::endl << "Please enter your desired account password here: ";
				
				getline(std::cin, password);

				std::cout << std::endl << std::endl;

				createAccount(username, password);

				std::cout << "Don't forget your username/password again!" << std::endl;

				break;
			}
			else
			{
				std::cout << "Ok." << std::endl;
			}
		}
	}

	std::cout << std::endl << "Now, welcome to the menu!" << std::endl << "Enter CLOSE anywhere to exit the program." << std::endl << std::endl;
	std::cout << "What would you like to do?" << std::endl << "Here's a list of things you can do:" << std::endl << "Play Battleship." << std::endl << "Open/Write files." << std::endl << std::endl;

	while(true)
	{
		
		std::cout << "Please enter: ";

		getline(std::cin, line);

		std::cout << std::endl;

		if(line == "BATTLESHIP" || line == "Battleship" || line == "battleship")
		{
			battleship::game();
		}

		if(line == "FILES" || line == "Files" || line == "files")
		{
			files::runMain();
		}

		if(line == "CLOSE")
		{
			break;
		}
	}

	return 0;
}