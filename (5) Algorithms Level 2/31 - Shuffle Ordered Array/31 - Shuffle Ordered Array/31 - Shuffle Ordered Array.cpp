// 31 - Shuffle Ordered Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cstdlib>

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

void Swap(int& A, int& B)
{
	int Temp;

	Temp = A;
	A = B;
	B = Temp;
	
}

void FillArrayWith1toN(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
		Arr[i] = i+1;
}

void PrintArray(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
		cout << Arr[i] << " ";
	cout << "\n";
}

void ShuffleArrayElements(int Arr[100], int ArrLength)
{
	for (int i = 0; i < ArrLength; i++)
	{
		Swap(Arr[RandomNumber(1, ArrLength - 1)], Arr[RandomNumber(1, ArrLength - 1)]);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int Array[100];
	int ArrLength = ReadPositiveNumber("Enter Array Length: ");

	FillArrayWith1toN(Array, ArrLength);

	cout << "\nArray elements before shuffle:\n";
	PrintArray(Array, ArrLength);

	ShuffleArrayElements(Array, ArrLength);

	cout << "\nArray elements after shuffle:\n";
	PrintArray(Array, ArrLength);


	return 0;
}