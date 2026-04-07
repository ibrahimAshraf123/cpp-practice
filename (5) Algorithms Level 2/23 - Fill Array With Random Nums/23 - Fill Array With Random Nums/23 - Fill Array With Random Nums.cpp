// 23 - Fill Array With Random Nums.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
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
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

void FillArrayWithRandomNums(int Elements[100], int &ElementsToFill)
{
	cout << "Enter Amount of elements to fill:" << endl;
	cin >> ElementsToFill;

	for (int i = 0; i < ElementsToFill; i++)
	{
		Elements[i] = GetRandomNumber(1, 100);
	}
}

void PrintArrElements(int Elements[100], int ElementsToFill)
{
	cout << "Array Elements: ";

	for (int i = 0; i < ElementsToFill; i++)
	{
		cout << Elements[i] << " ";
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int Elements[100], ElementsToFill;

	FillArrayWithRandomNums(Elements, ElementsToFill);
	PrintArrElements(Elements, ElementsToFill);

	return 0;
}