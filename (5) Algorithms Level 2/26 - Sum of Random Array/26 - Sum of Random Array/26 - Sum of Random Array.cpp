// 26 - Sum of Random Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int GetRandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNums(int Array[100], int& ArraySize)
{
	cout << "\nEnter Array Size:\n";
	cin >> ArraySize;

	for (int i = 0; i < ArraySize; i++)
	{
		Array[i] = GetRandomNumber(1, 100);
	}
}

void PrintArray(int Array[100], int ArraySize)
{

	for (int i = 0; i < ArraySize; i++)
	{
		cout << Array[i] << " ";
	}
	cout << "\n";
}

int SumArrayElements(int Array[100], int ArraySize)
{
	int Sum = 0;

	for (int i = 0; i < ArraySize; i++)
	{
		Sum += Array[i];
	}
	return Sum;
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[100];
	int ArraySize;

	FillArrayWithRandomNums(Array, ArraySize);

	cout << "\nArray Elements: ";
	PrintArray(Array, ArraySize);

	cout << "\nSum of all numbers is: ";
	cout << SumArrayElements(Array, ArraySize) << endl;

	return 0;
}
