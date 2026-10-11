#include <iostream>
#include <iomanip> //library stores std::setw
using namespace std;

int main()
{

	cout << "---------|--------------------------------|---------|" << endl;
	cout << "  Code   |             Name               |  Mark   |" << endl;
	cout << "---------|--------------------------------|---------|" << endl;

	cout << setw(9) << "C101" << "|" << setw(32) << "introduction to programming 1" << "|" << setw(9) << "95" << "|" << endl;
	cout << setw(9) << "C102" << "|" << setw(32) << "Computer Hardware" << "|" << setw(9) << "88" << "|" << endl;
	cout << setw(9) << "C103456" << "|" << setw(32) << "Network" << "|" << setw(9) << "75" << "|" << endl;
	cout << "---------|--------------------------------|---------|" << endl;

	return 0;
}