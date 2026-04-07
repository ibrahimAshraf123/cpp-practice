// 27 - Average of Random Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void FillArrayWithRandNums(int Array[100], int& ArrayLength)
{
	cout << "\nEnter Array Length:\n";
	cin >> ArrayLength;

	for (int i = 0; i < ArrayLength; i++)
	{
		Array[i] = RandomNumber(1, 100);
	}
}

void PrintArray(int Array[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Array[i] << " ";
	}
	cout << "\n";
}

int SumOfArrayNumbers(int Array[100], int ArrayLength)
{
	int Sum = 0;
	for (int i = 0; i < ArrayLength; i++)
	{
		Sum += Array[i];
	}
	return Sum;
}

float AvgOfArrayNumbers(int Array[100], int ArrayLength)
{
	return (float) SumOfArrayNumbers(Array, ArrayLength) / ArrayLength;
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[100], ArrayLength;

	FillArrayWithRandNums(Array, ArrayLength);

	cout << "\nArray elements: ";
	PrintArray(Array, ArrayLength);

	cout << "\nAverage of all numbers is: ";
	cout << AvgOfArrayNumbers(Array, ArrayLength) << endl;

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
