// 38 - CopyArrayOddNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>

using namespace std;

int ReadNumber(string Message)
{
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int Arr[100], int &ArrLength)
{
	cout << "\nPlease enter Array Length:\n";
	cin >> ArrLength;

	for (int i = 0; i < ArrLength; i++)
	{
		Arr[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << "\n";
}

void AddArrayElement(int Number, int Arr[100], int &ArrLength)
{
	ArrLength++;
	Arr[ArrLength - 1] = Number;
}

bool NumberIsOdd(int Num)
{
	if (!(Num % 2 == 0))
		return true;
	else
		return false;
}

void CopyArrayOddNumber(int Arr1[100], int Arr2[100], int Arr1Length, int &Arr2Length)
{
	for (int i = 0; i < Arr1Length; i++)
	{
		if (NumberIsOdd(Arr1[i]))
		{
			AddArrayElement(Arr1[i], Arr2, Arr2Length);
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr1[100], Arr1Length = 0;

	FillArrayWithRandomNumbers(Arr1, Arr1Length);

	int Arr2[100], Arr2Length = 0;
	CopyArrayOddNumber(Arr1, Arr2, Arr1Length, Arr2Length);

	cout << "\nArray 1 elements:\n";
	PrintArray(Arr1, Arr1Length);

	cout << "\nArray 2 elements after copying Odd Numbers:\n";
	PrintArray(Arr2, Arr2Length);


	return 0;
}
