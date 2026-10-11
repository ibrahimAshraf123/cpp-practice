// 05.5 - Print Digits in Reverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Num;
	do
	{
		cout << Message << endl;
		cin >> Num;
	} while (Num < 0);

	return Num;
}

void ReverseNumber(int Num)
{
	int Remainder = 0;

	while (Num > 0)
	{
		Remainder = Num % 10;
		Num /= 10;
		cout << Remainder << endl;
	}
}

int main()
{

	ReverseNumber(ReadPositiveNumber("enter number:"));

	return 0;
}
