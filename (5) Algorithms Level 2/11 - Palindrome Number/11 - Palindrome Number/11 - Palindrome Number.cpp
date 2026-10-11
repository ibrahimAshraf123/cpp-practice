// 11 - Palindrome Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

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

int ReverseNumber(int Num)
{
	int Remainder = 0, NewNum = 0;

	while (Num > 0)
	{
		Remainder = Num % 10;
		Num /= 10;
		NewNum = NewNum * 10 + Remainder;
	}
	return NewNum;
}

bool isPalindrome(int Num)
{
	cout << "Reversed: \n" << ReverseNumber(Num) << endl;

	if (Num == ReverseNumber(Num))
		return true;
	else
		return false;
}

void PrintResults(bool isPalindrome)
{
	if (isPalindrome)
		cout << "The Number is Palindrome" << endl;
	else
		cout << "The Number is NOT a Palindrome" << endl;

}

int main()
{
	//check if num is palindrome
	PrintResults(isPalindrome(ReadPositiveNumber("Enter positive number:")));

	return 0;
}
