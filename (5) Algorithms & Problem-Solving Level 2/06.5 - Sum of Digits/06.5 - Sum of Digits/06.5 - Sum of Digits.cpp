// 06.5 - Sum of Digits.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int SumOfDigits(int Num)
{
	int Sum = 0, Remainder = 0;

	while (Num > 0)
	{
		Remainder = Num % 10;
		Num = Num / 10;

		Sum += Remainder;
	}
	return Sum;
}

int main()
{

	cout << "Sum of digits = " << SumOfDigits(ReadPositiveNumber("Enter positive number:"));


	return 0;
}
