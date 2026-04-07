// 17 - Guess 3-Letter Password.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

string ReadPassword(string Message)
{
	string Pass;
	cout << Message << endl;
	cin >> Pass;

	return Pass;
}

void GuessPassword(string Password)
{
	string Guess = "";
	int trial = 0;

	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				trial++;

				Guess = Guess + char(i);
				Guess = Guess + char(j);
				Guess = Guess + char(k);

				cout << "Trail [" << trial << "] : " << Guess << endl;

				if (Guess == Password)
				{
					cout << "Password = " << Guess << endl;
					cout << "Found after " << trial << " trial(s)" << endl;
					return;
				}
				Guess = "";
			}
		}
	}
}

int main()
{
	GuessPassword(ReadPassword("Enter 3-Letter Password:"));

	return 0;
}
