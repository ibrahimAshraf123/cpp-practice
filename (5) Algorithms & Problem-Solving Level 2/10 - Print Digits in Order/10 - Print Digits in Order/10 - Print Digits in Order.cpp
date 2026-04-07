// 10 - Print Digits in Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	int Remain = 0;
	int ReversedNum = 0;
	while (Num > 0)
	{
		Remain = Num % 10;
		Num /= 10;
		ReversedNum = ReversedNum * 10 + Remain;
	}
	return ReversedNum;
}

void PrintDigitsInOrder(int Num)
{
	int Remain;

	while (Num > 0)
	{
		Remain = Num % 10;
		Num /= 10;

		cout << Remain << endl;
	
	}
}

int main()
{
	PrintDigitsInOrder(ReverseNumber(ReadPositiveNumber("Enter a Number:")));


	return 0;
}

