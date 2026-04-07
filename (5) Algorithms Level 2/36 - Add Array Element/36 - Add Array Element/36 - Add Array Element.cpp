// 36 - Add Array Element.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int ReadPositiveNumber(string Message)
{
	int Num;
	do
	{
		cout << Message;
		cin >> Num;
	} while (Num < 0);
	return Num;
}

void AddNumberToArray(int Array[100], int& ArrayLength)
{
	bool AddMoreNums = 1;
	ArrayLength = 0;

	while (AddMoreNums && ArrayLength<100)
	{
		Array[ArrayLength] = ReadPositiveNumber("\nPlease enter a number: ");
		ArrayLength++;

		cout << "Do you want to add more number? [0]:No, [1]:Yes ";
		cin >> AddMoreNums;
	}
}

void PrintArray(int Array[100], int ArrayLength)
{
	cout << "\nArray length: " << ArrayLength << endl;
	cout << "\nArray elements: ";

	for (int i = 0; i < ArrayLength; i++)
		cout << "[" << Array[i] << "] ";
	cout << "\n";
}

int main()
{
	int Array[100];
	int ArrayLength;

	AddNumberToArray(Array, ArrayLength);
	PrintArray(Array, ArrayLength);

	return 0;
}
