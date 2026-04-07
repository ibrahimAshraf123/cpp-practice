// 25 - Min Of Random Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

using namespace std;

int ReadPositiveNum(string Message)
{
	int Num;

	do
	{
		cout << Message << endl;
		cin >> Num;
	} while (Num < 0);
	return Num;
}

int RandomNum(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNums(int Array[100], int& ArraySize)
{
	cout << "\nEnter Array Size:\n";
	cin >> ArraySize;

	for (int i = 0; i < ArraySize; i++)
	{
		Array[i] = RandomNum(1,100);
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

int GetMinimumNumber(int Array[100], int ArraySize)
{
	int Min = 100;

	for (int i = 0; i < ArraySize; i++)
	{
		if (Array[i] < Min)
			Min = Array[i];
	}

	return Min;
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[100];
	int ArraySize;

	FillArrayWithRandomNums(Array, ArraySize);

	cout << "\nArray Elements: ";
	PrintArray(Array, ArraySize);

	cout << "\nMin Number is: ";
	cout << GetMinimumNumber(Array, ArraySize) << endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
