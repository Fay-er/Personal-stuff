#include <iostream> // io = InputOutput
using namespace std;// namespace containing libraries, basically a standard library

class wrap
{
	public:
		string hel;
};

int main()
{
	wrap wrapObj;
	string input;
	string typesOfVals[] = {"int", "float", "double", "char", "string", "bool"};
	
	wrapObj.hel = "Hello";
	
	cout << wrapObj.hel <<" World!" << "\n";
	cout << "Is there anything you would like to know about?" << "\n";
	
	cin >> input;
	
	if (input == "Yes")
	{
		cout << "There are 6 data types in C++" << "\n" << "They are:" "\n";
	
		for (string i: typesOfVals)
		{
			cout << i << "\n";
		}
		return 0;
	}
	
	else
	{
		cout << "Sorry I don't have the answer to that." << "\n";
	}
}