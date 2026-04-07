// 14 - Inverted Letter Pattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void PrintInvertedLetterPattern(int Num)
{
	cout << endl;
	for (int i = Num; i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << char(i + 64);
		}
		cout << endl;
	}
}

int main()
{
	PrintInvertedLetterPattern(ReadPositiveNumber("Enter a positive number:"));


	return 0;
}
