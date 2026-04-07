#include <iostream>
#include <vector>
#include <string>

int bubble_sort(std::vector<int> passedVector)
{
	int n = passedVector.size();
	
	for(int i = 0; i < n-1 ; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(passedVector[j] > passedVector[j + 1])
			{
				std::swap(passedVector[j], passedVector[j+1]);
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		if(i == n - 1)
		{std::cout << passedVector[i];}
		
		else{
			std::cout << passedVector[i] << ", ";
		}
	}

	return 0;
}

int main()
{
	std::string line;
	std::vector<int> vect;

	std::cout << "Welcome to the sorts program!" << std::endl;
	std::cout << "You can try out different types of sort algrorithms here. They are:" << std::endl;
	std::cout << "Bubble sort" << std::endl;
	std::cout << "Please enter your array here(without spaces): ";

	getline(std::cin, line);

	for(int i = 0; i < line.length(); i++)
	{
		if(line[i] != ',' || line[i] != ' ')
		{
			vect.push_back(line[i] - '0');
		}
	}

	bubble_sort(vect);

	return 0;
}