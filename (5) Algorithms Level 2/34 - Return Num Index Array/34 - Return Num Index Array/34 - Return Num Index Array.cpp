// 34 - Return Num Index Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void FillArrayWithRandomNumbers(int Array[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		Array[i] = RandomNumber(1,100);
	}
}

void PrintArray(int Array[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		cout << Array[i] << " ";
	}
	cout << "\n";
}

void GetNumberIndex(int Array[100], int ArrLength, int &Number)
{
	Number = ReadPositiveNumber("\nEnter Number to search for:");
	cout << "Number you are Looking for is: " << Number << endl;

	for (int i = 0; i < ArrLength; i++)
	{
		if (Number == Array[i])
		{
			cout << "The Number found at position: " << i << endl;
			cout << "The Number's found order is: " << i+1 << endl;
		}
		else if(Number != Array[i] && i == ArrLength-1)
		{
			cout << "The Number is not found :-(" << endl;
			break;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[100];
	int ArrLength = ReadPositiveNumber("Enter Array Length:");
	int Number;

	FillArrayWithRandomNumbers(Array, ArrLength);

	cout << "\nArray elements:\n";
	PrintArray(Array, ArrLength);

	GetNumberIndex(Array, ArrLength, Number);
	

	return 0;
}