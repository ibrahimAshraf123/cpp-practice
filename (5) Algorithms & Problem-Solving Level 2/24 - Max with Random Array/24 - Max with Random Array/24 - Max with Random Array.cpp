// 24 - Max with Random Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

using namespace std;

int GetRandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void FillArrayWithRandomNums(int Array[100], int &ArraySize)
{
	cout << "Enter Elements Amount:\n";
	cin >> ArraySize;

	for (int i = 0; i < ArraySize; i++)
	{
		Array[i] = GetRandomNumber(1, 100);
	}

}

void PrintArrayElements(int Array[100], int ArraySize)
{
	
	for (int i = 0; i < ArraySize; i++)
	{
		cout << Array[i] << " ";
	}

	cout << "\n";
}

int GetMaxNum(int Array[100], int ArraySize)
{
	int MaxNum = 0;
	for (int i = 0; i < ArraySize; i++)
	{
		if (Array[i] > MaxNum)
			MaxNum = Array[i];
	}
	return MaxNum;
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[100], ArraySize;

	FillArrayWithRandomNums(Array, ArraySize);

	cout << "Array Elements: ";
	PrintArrayElements(Array, ArraySize);

	cout << "Max Number is: ";
	cout << GetMaxNum(Array, ArraySize) << endl;
	return 0;
}
