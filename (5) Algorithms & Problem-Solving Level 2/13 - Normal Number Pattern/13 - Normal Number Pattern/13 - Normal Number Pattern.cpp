// 13 - Normal Number Pattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Num = 0;
	do
	{
		cout << Message << endl;
		cin >> Num;
	} while (Num < 0);
	return Num;

}

void PrintPattern(int Num)
{
	cout << endl;
	for (int i = 1; i <= Num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}
		cout << endl;
	}
}

int main()
{
	PrintPattern(ReadPositiveNumber("Enter a positive number:"));


	return 0;
}
