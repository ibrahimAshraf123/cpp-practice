// 30 - Sum of 2 Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void FillArrayWithRandomNumbers(int Array[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
		Array[i] = RandomNumber(1, 100);
}

void PrintArray(int Array[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Array[i] << " ";
	}
	cout << "\n";
}

void SumArraysElements(int Arr1[100], int Arr2[100], int ArrLength, int ArrDestination[100])
{
	for (int i = 0; i < ArrLength; i++)
	{
		ArrDestination[i] = Arr1[i] + Arr2[i];
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr1[100], Arr2[100], Arr3[100];
	int ArrLength = ReadPositiveNumber("Enter Array Length:");

	FillArrayWithRandomNumbers(Arr1, ArrLength);
	FillArrayWithRandomNumbers(Arr2, ArrLength);

	SumArraysElements(Arr1, Arr2, ArrLength, Arr3);

	cout << "\nArray 1 elements: \n";
	PrintArray(Arr1, ArrLength);
	
	cout << "\nArray 2 elements: \n";
	PrintArray(Arr2, ArrLength);
	
	cout << "\nSum of Arrays' elements: \n";
	PrintArray(Arr3, ArrLength);

	return 0;
}