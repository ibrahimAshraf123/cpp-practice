// Home Work 39 (#50 ATM PIN 3 Times).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void readPIN(int &PIN) {
	
	cout << "Enter PIN: \n";
	cin >> PIN;
}

int main()
{

	int PIN;
	int i = 0;
	int balance = 7500;

	while (i < 3) {
		readPIN(PIN);
		
		if (PIN == 1234) {
			cout << "balance = " << balance << endl;
			break;
		}
		else {
			cout << "WRONG PIN\n";
			i++;
		}
	}

	if (i == 3) {
		cout << "Card is locked\n";
	}
	

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
