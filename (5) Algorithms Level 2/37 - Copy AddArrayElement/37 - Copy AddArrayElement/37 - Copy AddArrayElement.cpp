// 37 - Copy AddArrayElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

using namespace std;

int ReadNumber()
{
	int Num;
	cout << "\nPlease enter number: ";
	cin >> Num;
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

void AddArrayElement(int Number, int Arr[100], int& ArrLength)
{
	ArrLength++;
	Arr[ArrLength - 1] = Number;
}

void CopyUsingAddArrayElement(int ArrSrc[100], int ArrDest[100], int ArrSrcLength, int &ArrDestLength)
{
	ArrDestLength = 0;

	do
	{
		AddArrayElement(ArrSrc[ArrDestLength], ArrDest, ArrDestLength);
	} while (ArrSrcLength > ArrDestLength);
}

int main()
{
	srand((unsigned)time(NULL));
	
	int Arr1[100], Arr2[100];
	int Arr1Length = 0, Arr2Length = 0;

	Arr1Length = ReadNumber();

	FillArrayWithRandomNumbers(Arr1, Arr1Length);

	cout << "\nArray 1 elements: ";
	PrintArray(Arr1, Arr1Length);

	CopyUsingAddArrayElement(Arr1, Arr2, Arr1Length, Arr2Length);

	cout << "\nArray 2 elements: ";
	PrintArray(Arr2, Arr2Length);

	return 0;
}

