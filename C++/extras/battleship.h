#include <iostream>

namespace battleship{
	class battleField
	{
		public:
			int matrix[3][3] = 
			{
				{1,0,0},
				{0,0,0},
				{0,0,0}
			};
		
			int hits = 0;
			int ships = 1;

			int playGame()
			{
				std::string x;
				std::string y;

				std::cout << "Choose row: ";
				std::cin >> x;
				std::cout << "\n";
				
				if(x == "CLOSE")
				{
					return 1;
				}

				std::cout << "Choose column: ";
				std::cin >> y;
				std::cout << "\n";
				
				if(y == "CLOSE")
				{
					return 1;
				}

				if (std::stoi(x) >= 0 && std::stoi(y) >= 0 && std::stoi(x) < 3 && std::stoi(y) < 3)
				{
					if (matrix[std::stoi(x)][std::stoi(y)] == 1)
					{
						std::cout << "Hit!" << "\n";
						ships--;
					}

					else
					{
						std::cout << "Miss!" << "\n";
					}
				}

				else
				{
					std::cout << "Invalid co-ordinates!" << "\n";
				}

				return 0;
			}
	};

	int game()
	{
		int exit;
		battleField fieldObj;

		std::string play;
	
		std::cout << "Welcome to BattleField!" << "\n";
		std::cout << "You control the mortar!" << "\n";
		std::cout << "You choose a row and column to shoot at!" << "\n";

		std::cout << "Do you wish to continue? (Yes or no)" << "\n";
		std::cin >> play;

		if (play == "Yes" || play == "yes" || play == "YES")
		{
			while (fieldObj.ships > 0)
			{
				exit = fieldObj.playGame();

				if(exit == 1)
				{
					break;
				}
			}

			if(exit == 1)
			{
				std::cout << "Welp! See you another time!" << std::endl << std::endl;
			}
			else
			{
				std::cout << "Victory! You sunk all ships!" << "\n";
				std::cout << "Good Bye!" << std::endl << std::endl;
			}
		}
	
		else
		{
			std::cout << "Welp! See you another time!" << std::endl << std::endl;
		}

		return 0;
	}
}