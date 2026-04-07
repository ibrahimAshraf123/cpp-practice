// 32 - Copy Array in Reverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void CopyArrayInReverseOrder(int ArrSource[100], int ArrDestination[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		ArrDestination[i] = ArrSource[ArrLength-1-i];
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr1[100], Arr2[100];
	int ArrLength = ReadPositiveNumber("Enter Array Length:");

	FillArrayWithRandomNumbers(Arr1, ArrLength);

	CopyArrayInReverseOrder(Arr1, Arr2, ArrLength);

	cout << "\nArray 1 elements:\n";
	PrintArray(Arr1, ArrLength);

	cout << "\nArray 2 elements:\n";
	PrintArray(Arr2, ArrLength);

	return 0;
}
