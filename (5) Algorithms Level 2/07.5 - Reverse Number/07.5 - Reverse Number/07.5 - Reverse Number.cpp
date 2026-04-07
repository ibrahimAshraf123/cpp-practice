// 07.5 - Reverse Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int ReverseNumber(int Num)
{
	int Remainder = 0;
	int NewNum = 0;
	while (Num > 0)
	{
		Remainder = Num % 10;
		Num /= 10;
		NewNum = NewNum * 10  + Remainder;
	}
	return NewNum;
}

int main()
{

	cout << ReverseNumber(ReadPositiveNumber("enter number:"));

	return 0;
}
