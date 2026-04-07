// 41 - Is Palindrome Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void FillArray(int arr[100], int& arrLength)
{
	arrLength = 7;

	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 50;
	arr[4] = 30;
	arr[5] = 20;
	arr[6] = 10;
}

void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void SwapNumbers(int& x, int &y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;
}

void ReverseArrayElements(int arr[100], int arrLength)
{
	for (int i = 0; i < (arrLength/2); i++)
	{
		SwapNumbers(arr[i], arr[(arrLength - i) - 1]);
	}
}

bool IsArrayPalindrome(int arr[100], int arrLength)
{
	
	for (int i = 0; i < (arrLength / 2); i++)
	{
		if (arr[i] != arr[(arrLength - i) - 1])
			return false;	
	}
	return true;
}

int main()
{
	int arr[100], arrLength = 0;

	FillArray(arr, arrLength);

	cout << "\nArray Elements:\n";
	PrintArray(arr, arrLength);
   
	ReverseArrayElements(arr, arrLength);

	cout << "\nArray Elements in reverse:\n";
	PrintArray(arr, arrLength);

	if (IsArrayPalindrome(arr, arrLength))
		cout << "\nArray is palindrome\n";
	else
		cout << "\nArray is not palindrome\n";

	return 0;
}
