// 40 - CopyDistinctArrayNums.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>

using namespace std;

void FillArray(int Arr[100], int& ArrLength)
{
	ArrLength = 10;

	Arr[0] = 10;
	Arr[1] = 10;
	Arr[2] = 10;

	Arr[3] = 50;
	Arr[4] = 50;

	Arr[5] = 70;
	Arr[6] = 70;
	Arr[7] = 70;
	Arr[8] = 70;

	Arr[9] = 90;

}

void PrintArray(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << "\n";
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == Number)
			return i;
	}
	return -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
	
	return FindNumberPositionInArray(Number,arr,arrLength) != -1;
}

void AddArrayElement(int Number, int Arr[100], int& ArrLength)
{
	ArrLength++;
	Arr[ArrLength - 1] = Number;
}

void CopyArrayDistinctElement(int ArrSource[100], int ArrDestination[100], int SourceLength, int& DestinationLength)
{
	for (int i = 0; i < SourceLength; i++)
	{
		if (!IsNumberInArray(ArrSource[i], ArrDestination, DestinationLength))
		{
			AddArrayElement(ArrSource[i], ArrDestination, DestinationLength);
		}
	};
}

int main()
{
	int ArrSource[100], SourceLength = 0, ArrDestination[100], DestinationLength = 0;
	FillArray(ArrSource, SourceLength);

	cout << "\nArray 1 elements:\n";
	PrintArray(ArrSource, SourceLength);

	CopyArrayDistinctElement(ArrSource, ArrDestination, SourceLength, DestinationLength);

	cout << "\nArray 2 elements after copying distinct Numbers:\n";
	PrintArray(ArrDestination, DestinationLength);


	return 0;
}
