// 22.5 - Count Repeated Elements.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void ReadArrayElements(int Array[100], int &ArraySize)
{
	cout << "\nEnter number of elements:\n";
	cin >> ArraySize;

	cout << "\nEnter array elements:\n";

	for (int i = 0; i < ArraySize; i++)
	{
		cout << "Element [" << i + 1 << "]: ";
		cin >> Array[i];
	}
	cout << endl;
}

void PrintArray(int Array[100], int ArraySize)
{
	for (int i = 0; i < ArraySize; i++)
		cout << Array[i] << " ";
	cout << "\n";
}

int GetNumFrequncy(int Array[100], int ArraySize, int CheckNum)
{
	int Frequency = 0;

	for (int i = 0; i < ArraySize; i++)
	{
		if (Array[i] == CheckNum)
			Frequency++;
	}
	return Frequency;
}


int main()
{
	int Array[100];
	int ArraySize;
	int CheckNum;

	ReadArrayElements(Array, ArraySize);
	CheckNum = ReadPositiveNumber("Enter Number you want to check:");

	cout << "\nOriginal array: ";
	PrintArray(Array, ArraySize);

	cout << "\nNumber " << CheckNum;
	cout << " is repeated ";
	cout << GetNumFrequncy(Array, ArraySize, CheckNum)<< " time(s)\n";
	

	return 0;
}
