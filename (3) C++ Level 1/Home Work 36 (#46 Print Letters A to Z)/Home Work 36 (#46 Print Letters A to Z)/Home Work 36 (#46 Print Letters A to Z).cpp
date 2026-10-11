// Home Work 36 (#46 Print Letters A to Z).cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

#include <iostream>

void printAlphabets() {
	int i = 65;
	for (i; i <= 90; i++) {
		cout << char(i) << endl;
	}
}


int main()
{

	printAlphabets();

	return 0;
}
