// 34.5 - Return Num Index Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

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

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
		Arr[i] = RandomNumber(1, 100);
}

void PrintArray(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
		cout << Arr[i] << " ";
	cout << "\n";
}

short GetNumberPositionInArray(int Number, int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		if (Number == Arr[i])
			return i;
	}
	return -1;
}

int main()
{
	srand((unsigned)time(NULL));
	int Arr[100];
	int ArrLength = ReadPositiveNumber("Enter Array length:");
	short Number;

	FillArrayWithRandomNumbers(Arr, ArrLength);

	cout << "\nArray elements:\n";
	PrintArray(Arr, ArrLength);

	Number = ReadPositiveNumber("\nEnter a Number to search for?");
	
	cout << "\nNumber you are looking for: " << Number << endl;
	short index = GetNumberPositionInArray(Number, Arr, ArrLength);

	if (index == -1)
	{
		cout << "Number not found :-(" << endl;
	}
	else
	{
		cout << "Number found at position: " << index << endl;
		cout << "Number's found order is: " << index + 1 << endl;
	}

	return 0;
}