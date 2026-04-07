#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main()
{
	string test = "HELLO WORLD!";

	string sub = test.substr("WORLD!");

	cout << sub;

	return 0;
}