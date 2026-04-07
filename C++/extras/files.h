#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::string;

namespace files
{
	void openFile(string line = "my_file")
	{
		string fileLine;

		std::ifstream fileOpened(line);

		if (!fileOpened.is_open())
		{
			std::cerr << "Error opening file." << std::endl << "Error 001" << std::endl;
		}
	
		cout << "File contents:" << std::endl;

		while (getline(fileOpened, fileLine))
		{
			cout << "	" << fileLine << std::endl;
		}

		cout << std::endl;
	};

	void writeFile(string line = "my_file")
	{
		string userLine;

		std::ofstream openedFile(line, std::ios_base::app);

		if(!openedFile.is_open())
		{
			std::cerr << "Error opening file." << std::endl << "Error 002" << std::endl;
		};

		cout << "Content to add to file:" << std::endl;
		cout << "	";

		while(getline(cin, userLine))
		{
			cout << "	";

			if(userLine == "change")
			{
				break;
			}
		
			openedFile << userLine << std::endl;
		};

		openedFile.close();

		cout << std::endl << "Going back to file choosing menu..." << std::endl << std::endl;
	};

	int runMain()
	{
		int userState = 0;
		string line;

		cout << "Welcome to my file opener/writer software!" << std::endl << std::endl;
		cout << "Please enter '1' if you wish to open a file." << std::endl;
		cout << "Please enter '2' if you wish to write to a file" << std::endl;
		cout << "Now, to exit the software, enter 'CLOSE'." << std::endl;

		cout << "Please enter what you wish to do: ";
		getline(cin, line);

		cout << std::endl;

		if(line == "1" || line == "2")
		{
			while(true)
			{
				if (line == "1")
				{
					userState = 1;
					cout << std::endl << "File opener:" << std::endl;

			
					cout << "To go back to the menu, enter 'menu'." << std::endl << std::endl;

					while (true)
					{
						cout << "Enter file name/command here: ";
						getline(cin, line);

						cout << std::endl;

						if(line == "menu" || line == "CLOSE")
						{
							cout << "Going back to the main menu..." << std::endl << std::endl;

							break;
						}

						openFile(line);
					};
				};

				if(line == "2")
				{
					userState = 2;
					cout << std::endl << "File writer:" << std::endl;

					cout << "To go back to the menu, enter 'menu'." << std::endl;
					cout << "Enter 'change' to change file." << std::endl;

					while(true)
					{
						cout << "Enter file name/command here: ";
						getline(cin, line);

						if(line == "menu" || line == "CLOSE")
						{
							cout << std::endl << "Going back to the main menu..." << std::endl << std::endl << std::endl;

							break;
						};

						cout << std::endl << std::endl;

						writeFile(line);
					};
				};

				if(line == "CLOSE")
				{
					break;
				}

				if(line == "menu")
				{
					if(userState == 0)
					{
						cout << "You're already at the menu..." << std::endl;
					}
					else
					{
						cout << "You're back at the menu." << std::endl;

						userState = 0;
					};
				}

				cout << "Enter: ";
				getline(cin, line);
			};
		}
		return 0;
	}
}