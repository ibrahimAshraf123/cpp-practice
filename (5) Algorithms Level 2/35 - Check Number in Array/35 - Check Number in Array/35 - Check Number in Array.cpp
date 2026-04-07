// 35 - Check Number in Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

bool CheckNumberInArray(int Number, int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		if (Number == Arr[i])
			return true;
	}
	return false;
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
	bool NumberInArray = CheckNumberInArray(Number, Arr, ArrLength);

	if (NumberInArray)
	{
		cout << "Number is found :-)" << endl;
	}
	else
	{
		cout << "Number not found :-(" << endl;
	}

	return 0;
}